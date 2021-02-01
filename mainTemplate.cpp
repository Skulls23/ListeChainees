/**
 * \name   mainTemplate.cpp
 * \author Florian Boireau
 * \date   octobre 2020
 * Ce fichier represente tout les tests de mes methodes, on voit ici,
 * l'utilisation de chacune des methodes. On voit les cas les plus courant d'utilisation,
 * mais aussi les utilisations aux bornes ou dans une liste vide afin d'eviter toute erreur possible
 */

#include <string>
#include <iostream>
#include "listeTemplate.cpp"


using namespace std;
int main()
{
    /*************************/
    /*    CREATION SIMPLE    */
    /*************************/



    cout << "creation d'une liste de string" << endl;
    Liste<string> liste;

    liste.ajouter("1");
    liste.ajouter("2");
    liste.ajouter("3");
    liste.ajouter("4");

    Iterateur<string> it = liste.debut();
    it.afficher();



    /*********************/
    /*    DEPLACEMENT    */
    /*********************/



    cout << "\tDEPLACEMENT\n" << endl;

    cout << "Emplacement : " << *it << endl;
    cout << "Emplacement apres incrementation prefixe : " << *(++it) << endl; //S'incremente avant l'affichage
    cout << "Emplacement apres incrementation suffixe : " << *(it++) << endl; //S'incremente apres l'affichage
    cout << "Emplacement : " << *it << "\n" << endl;                          //Montre que l'incrementation suffixe fonctionne
    cout << "Emplacement apres decrementation prefixe : " << *(--it) << endl; //Se decremente avant l'affichage
    cout << "Emplacement apres decrementation suffixe : " << *(it--) << endl; //Se decremente apres l'affichage
    cout << "Emplacement : " << *it << "\n" << endl;                          //Montre que la decrementation suffixe fonctionne

    it++; it++; it++;
    cout << "Emplacement a la limite max : " << *it << endl;
    cout << "Emplacement apres sortie de la limite max: " << *(++it) << endl;

    it--; it--; it--;
    cout << "Emplacement a la limite min : " << *it << endl;
    cout << "Emplacement apres sortie de la limite min: " << *(--it) << endl;
    cout << "\n" << endl;

    Iterateur<string> it2 = liste.fin();
    cout << "Emplacement : " << *(--it2) << "\n" << endl;
    cout << "Emplacement post-incrementation: " << *(++it2) << "\n" << endl;
    cout << "Emplacement post-decrementation: " << *(--it2) << "\n" << endl;



    /*********************/
    /*     INSERTION     */
    /*********************/



    cout << "\tINSERTION\n" << endl;

    Liste<int> liste2;
    //liste2.ajouter(1);
    cout << "Creation d'une liste d'1 element" << endl;

    Iterateur<int> it3 = liste2.debut();
    cout << "Emplacement : " << *it3 << endl;
    liste2.supprimer(it3);
    it3.afficher();

    liste2.inserer(it3, 1);
    cout << "Emplacement apres insertion : " << *it3 << endl; //Dans une liste vide
    it3.afficher();
    liste2.inserer(it3, 2);
    cout << "Emplacement apres insertion : " << *it3 << endl; //Dans une liste de 1 element
    liste2.inserer(it3, 3);
    cout << "Emplacement apres insertion : " << *it3 << endl; //Dans une liste de plusieurs elements
    it3.afficher();
    cout << "\n" << endl;



    /*********************/
    /*    SUPPRESSION    */
    /*********************/



    cout << "\tSUPPRESSION\n" << endl;

    cout << "Emplacement : " << *it3 << endl;
    it3.afficher();

    liste2.supprimer(it3);
    cout << "Emplacement apres 1 suppression : " << *it3 << endl;
    it3.afficher();

    liste2.supprimer(it3);
    cout << "Emplacement apres 2 suppressions : " << *it3 << endl;
    it3.afficher();

    liste2.supprimer(it3);
    cout << "Emplacement apres 3 suppressions : " << *it3 << endl;
    it3.afficher();

    cout << "Emplacement : " << *(++it3) << endl;
    cout << "Emplacement : " << *(--it3) << endl;
    cout << "\n" << endl;



    /************************************/
    /*    CONSTRUCTEUR ET TESTS BOOL    */
    /************************************/



    cout << "\tCONSTRUCTEUR ET TESTS BOOL\n" << endl;

    Liste<double> liste3;
    liste3.ajouter(1.1);
    liste3.ajouter(2.22);
    liste3.ajouter(3.333);

    Iterateur<double> it4 = liste3.debut();
    cout << "Liste3 de base" << endl;
    it4.afficher();

    Liste<double> liste4 = liste3;
    Liste<double> liste5(liste3);

    Iterateur<double> it5=(liste4.debut());
    cout << "Liste4 via =" << endl;
    it5.afficher();

    Iterateur<double> it6 = liste5.debut();
    cout << "Liste5 via recopie" << endl;
    it6.afficher();

    Iterateur<double> it7 = liste5.debut();

    //test pour savoir les autres constructeurs pointent les meme cases memoires
    liste3.supprimer(it4);
    it4.afficher();
    it5.afficher();
    it6.afficher();


    bool bEqual = it6==it7;
    cout << "it6 == it7 : " << boolalpha << bEqual << endl;

    bEqual = it6!=(it7++);
    cout << "it6 != it7 : " << boolalpha << bEqual << endl;

    cout << "apres deplacement de it7" << endl;

    bEqual = it6==it7;
    cout << "it6 == it7 : " << boolalpha << bEqual << endl;

    bEqual = it6!=it7;
    cout << "it6 != it7 : " << boolalpha << bEqual << endl;

    cout << "construction de it8 et it9, deux iterateurs vide" << endl;

    Iterateur<double> it8;
    Iterateur<double> it9;

    bEqual = it8==it9;
    cout << "it8 == it9 : " << boolalpha << bEqual << endl;

    cout << "construction de la Liste6 de void * pour tester la stabilite du template" << endl;
    Liste<void *> liste6;
    liste6.ajouter((void *)'4');
    Iterateur<void *> it10 = liste6.debut();
    cout << "Liste6 : " << endl;
    it10.afficher();


    /***********************/
    /*    FIN DES TESTS    */
    /***********************/
}