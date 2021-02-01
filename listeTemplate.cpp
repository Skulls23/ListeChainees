/**
 * \name   listeTemplate.cpp
 * \author Florian Boireau
 * \date   octobre 2020
 */

#include "listeTemplate.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

template <typename T>
class Element {
public:
    /*!
     * \brief Constructeur
     * \param parametre T qui sera contenu dans valeur
     */
    Element(const T& s);

private:
    T valeur;


    Element<T>* precedent;
    Element<T>* suivant;

    friend class Liste<T>;
    friend class Iterateur<T>;
};

/*!
 * \brief Constructeur d'un element de T
 * \param T qui sera contenu dans valeur
 */
template <typename T>
Element<T>::Element(const T& s) {
    valeur = s;
    precedent = suivant = (Element<T>*)nullptr;
}

/*!
 * \brief Constructeur d'iterateur qui pourra parcourir la liste d'element
 */
template <typename T>
Iterateur<T>::Iterateur() { position = dernier = (Element<T>*)nullptr; }

/*!
 * \brief Incrementation prefixe de la position
 * \return Un nouvel Iterateur de T
 */
template <typename T>
Iterateur<T> Iterateur<T>::operator++()
{
    if(position != NULL)
    {
        if (this->position->suivant != (Element<T> *) nullptr)
            position = position->suivant;
    }else
        position = (Element<T> *) nullptr;

    return *this;
}

/*!
 * \brief Incrementation suffixe de la position
 * \return Un nouvel Iterateur de T
 */
template <typename T>
Iterateur<T> Iterateur<T>::operator++(int)
{
    Iterateur<T> it;
    it.position = this->position;
    it.dernier = this->dernier;

    if(position != NULL)
    {
        if (this->position->suivant != (Element<T> *) nullptr)
            position = position->suivant;
    }else
    {
        position = (Element<T> *) nullptr;
    }

    return it;
}

/*!
 * \brief Decrementation prefixe de la position
 * \return Un nouvel Iterateur de T
 */
template <typename T>
Iterateur<T> Iterateur<T>::operator--()
{
    if(position != NULL)
    {
        if (this->position->precedent != (Element<T> *) nullptr)
            position = position->precedent;
    }else position = dernier;

    return *this;
}

/*!
 * \brief Decrementation suffixe de la position
 * \return Un nouvel Iterateur de T
 */
template <typename T>
Iterateur<T> Iterateur<T>::operator--(int)
{
    Iterateur<T> it;
    it.position = this->position;
    it.dernier = this->dernier;

    if(position != NULL)
    {
        if (this->position->precedent != (Element<T> *) nullptr)
            position = position->precedent;
    }else position = dernier;

    return it;
}

/*!
 * \brief retourne la position de l'iterateur
 * \return un type T
 */
template <typename T>
T Iterateur<T>::operator*()
{
    if (position == (Element<T>*)nullptr)
        return T{}; //On ne peux pas renvoyer un nullptr de double ou char, la, on renvoie un new T()
    return position->valeur;
}

/*!
 * \brief Test booleen d'egalite
 * \param Un Iterateur de T
 * \return Un bool
 */
template <typename T>
bool Iterateur<T>::operator==(const Iterateur<T> & iter)
{
    //si les deux sont vide
    if(position == (Element<T>*)nullptr && iter.position == (Element<T>*)nullptr)
        return true;
    else if(position == (Element<T>*)nullptr || iter.position == (Element<T>*)nullptr)//si l'un des deux est vide
        return false;
    return position == iter.position;
}

/*!
 * \brief Test booleen d'inegalite
 * \param Un Iterateur de T
 * \return Un bool
 */
template <typename T>
bool Iterateur<T>::operator!=(const Iterateur<T> & iter)
{
    //si les deux sont vide
    if(position == (Element<T>*)nullptr && iter.position == (Element<T>*)nullptr)
        return false;
    else if(position == (Element<T>*)nullptr || iter.position == (Element<T>*)nullptr)//si l'un des deux est vide
        return true;
    return position != iter.position;
}


/*!
 * \brief Affichage de la liste position par position
 */
template <typename T>
void Iterateur<T>::afficher()
{
    if(this->position != (Element<T>*)nullptr)
    {
        Element<T> *positionDeBase = this->position;

        //on se replace au debut a chaque fois pour tout afficher
        while (this->position->precedent != (Element<T> *) nullptr)
            (*this)--;

        while (position != (Element<T> *) nullptr) {
            cout << *(*this) << endl;
            position = position->suivant;
        }
        cout << "\n";
        this->position = positionDeBase;
    }else { cout << "Position invalide (ou liste vide), affichage de la liste impossible" << endl; }
}


/////////////////////////////////////////////////   LISTE   /////////////////////////////////////////////////

/*!
 * \brief Constructeur de Liste
 */
template <typename T>
Liste<T>::Liste() {
    premier = dernier = (Element<T>*)nullptr;
}

/*!
 * \brief Constructeur de Liste par recopie
 * \param Une Liste de T
 */
template <typename T>
Liste<T>::Liste(Liste<T> & l)
{
    this->premier = l.premier;
    this->dernier = l.dernier;
}

/*!
 * \brief Destructeur de Liste
 */
template <typename T>
Liste<T>::~Liste()
{
    for (Iterateur<T> it = this->debut(); it != this->fin();)
    {

        Element<T> *e = new Element<T>(it.position->valeur);
        e->suivant = it.position->suivant;
        e->precedent = it.position->precedent;
        free(it.position);
        it.position = e->suivant;
        free(e);
    }


    this->premier = (Element<T>*)nullptr;
    this->dernier = (Element<T>*)nullptr;
}

/*!
 * \brief Constructeur de Liste par operateur d'affectation
 * \param Liste de T
 * \return Une Liste de T
 */
template <typename T>
Liste<T> & Liste<T>::operator=(Liste<T> & l)
{
    for (Iterateur<T> it = l.debut(); it != l.fin(); it++)
        this->ajouter(it.position->valeur);

    return *this;
}

/*!
 * \brief Construit un Iterateur a la premiere position de la liste
 * \return Iterateur de T
 */
template <typename T>
Iterateur<T> Liste<T>::debut() const {
    Iterateur<T> it;
    it.position = this->premier;
    it.dernier = this->dernier;
    return it;
}

/*!
 * \brief Construit un Iterateur a la position nullptr
 * \return Iterateur de T
 */
template <typename T>
Iterateur<T> Liste<T>::fin() const {
    Iterateur<T> it;
    it.position = (Element<T>*)nullptr;
    it.dernier = dernier;
    return it;
}

/*!
 * \brief ajoute un T a la fin de la liste
 * \param T
 */
template <typename T>
void Liste<T>::ajouter(const T& s)
{
    Element<T> *e = new Element<T>(s);

    if (premier == (Element<T>*)nullptr) { premier = dernier = e; }
    else
    {
        e->precedent = dernier;
        dernier->suivant = e;
        dernier = e;
    }
}

/*!
 * \brief ajoute un T a la position
 * \param Un Iterateur de T, un T
 */
template <typename T>
void Liste<T>::inserer(Iterateur<T>& pos, const T& s)
{
    Element<T> *e = new Element<T>(s);

    /*On a 2 cas ou la position est (Element<T>*)nullptr, quand on fait liste.fin()
        * mais aussi quand on a une liste vide, dans ce cas on ajoute s
        */
    if (pos.position == (Element<T>*)nullptr)
    {
        this->ajouter(s);
        pos.position = premier;
        pos.dernier  = dernier;
    }
    else
    {
        e->suivant = pos.position;

        if (pos.position->precedent == (Element<T>*)nullptr)
        {
            pos.position->precedent = e;
            premier = e;
        }
        else
        {
            e->precedent = pos.position->precedent;

            e->suivant->precedent = e;
            e->precedent->suivant = e;
        }
    }
}

/*!
 * \brief Supprime le T que pointe la position
 * \param Un Iterateur de T
 */
template <typename T>
void Liste<T>::supprimer(Iterateur<T>& pos)
{
    if (pos.position != (Element<T>*)nullptr)
    {
        if (pos.position->precedent == (Element<T>*)nullptr && pos.position->suivant != (Element<T>*)nullptr)
        {
            pos++;
            pos.position->precedent = (Element<T>*)nullptr;
            delete pos.position->precedent;
            premier = pos.position;
        }
        else if (pos.position->suivant == (Element<T>*)nullptr && pos.position->precedent != (Element<T>*)nullptr)
        {
            pos--;
            pos.position->suivant = (Element<T>*)nullptr;
            delete pos.position->suivant;
            dernier = pos.position;
        }
        else if (pos.position->suivant == (Element<T>*)nullptr && pos.position->precedent == (Element<T>*)nullptr)
        {
            pos.position = pos.dernier = premier = dernier = (Element<T>*)nullptr;
            delete pos.position, premier, dernier;
        }
        else
        {
            pos.position->suivant->precedent = pos.position->precedent;
            pos.position->precedent->suivant = pos.position->suivant;
            pos.position = pos.position->suivant;
        }
    }
}

