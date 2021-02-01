/**
 * \name   listeTemplate.h
 * \author Florian Boireau
 * \date   octobre 2020
 */

#pragma once

#ifndef LISTE_H

#define LISTE_H


template <typename T>
class Element;

template <typename T>
class Iterateur;

template <typename T>
class Liste {
public:
    // constructeur
    Liste();
    Liste(Liste<T> & l);
    ~Liste();
    Liste<T> & operator=(Liste<T> & l);

    // ajouter s a la fin de la liste
    void ajouter(const T& s);

    // ajouter s avant la position pos
    void inserer(Iterateur<T>& pos, const T& s);

    // supprimer l'element a la position pos
    void supprimer(Iterateur<T>& pos);

    // la premiere position
    Iterateur<T> debut() const;

    // la fin de la liste (apres la derniere position)
    Iterateur<T> fin() const;

private:
    // pointeurs vers le premier et le dernier element
    Element<T>* premier;
    Element<T>* dernier;
};

template <typename T>
class Iterateur {
public:
    // constructeur
    Iterateur();

    Iterateur<T>   operator++();    //prefixe ++it     Position suivante
    Iterateur<T>   operator++(int); //suffixe it++
    Iterateur<T>   operator--();    //                 Position precedente
    Iterateur<T>   operator--(int);
    T              operator*();     //equivalent a get
    bool           operator==(const Iterateur<T>& iter);
    bool           operator!=(const Iterateur<T>& iter);

    void afficher();


private:
    // pointeur vers l'element courant
    Element<T>* position;

    // pointeur vers le dernier element de la liste
    Element<T>* dernier;

    friend class Liste<T>;
};

#endif
