#include "set.h"

int main() {

    string lignesSeparation = "\n====================================";



    cout << lignesSeparation;
    cout << "\nTEST INSERT PAR VALEUR";
    cout << lignesSeparation << std::endl;
    set<int> setInsertValeur;
    setInsertValeur.afficher();
    setInsertValeur.insert(1);
    setInsertValeur.afficher();
    setInsertValeur.insert(2);
    setInsertValeur.afficher();
    setInsertValeur.insert(3);
    setInsertValeur.afficher();
    setInsertValeur.insert(4);
    setInsertValeur.afficher();

    cout << lignesSeparation;
    cout << "\nTEST INSERT PAR ITERATOR";
    cout << lignesSeparation << std::endl;
    set<int> setInsertIterator;
    setInsertIterator.insert(1);
    setInsertIterator.insert(2);
    setInsertIterator.insert(4);
    setInsertIterator.afficher();
    cout << "Insert 3";
    set<int>::iterator it_1 = setInsertIterator.find(2);
    setInsertIterator.insert(it_1, 3);
    setInsertValeur.afficher();


    cout << lignesSeparation;
    cout << "\nTEST ERASE PAR VALEUR";
    cout << lignesSeparation << std::endl;
    set<int> setEraseValeur;
    setEraseValeur.insert(1);
    setEraseValeur.insert(2);
    setEraseValeur.insert(3);
    setEraseValeur.insert(4);
    setEraseValeur.afficher();
    cout << "Erase 3";
    setEraseValeur.erase(3);
    setEraseValeur.afficher();

    cout << lignesSeparation;
    cout << "\nTEST ERASE PAR ITERATOR";
    cout << lignesSeparation << std::endl;
    set<int> setEraseIterator;
    setEraseIterator.insert(1);
    setEraseIterator.insert(2);
    setEraseIterator.insert(3);
    setEraseIterator.insert(4);
    setEraseIterator.afficher();
    set<int>::iterator it_2 = setInsertIterator.find(3);
    cout << "Erase 3";
    setInsertIterator.erase(it_2);
    setInsertIterator.afficher();

    cout << lignesSeparation;
    cout << "\nTEST CONSTRUCTEUR PAR COPIE";
    cout << lignesSeparation << std::endl;
    set<int> setDonneur;
    set<int> setReceveur;
    setDonneur.insert(1);
    setDonneur.insert(2);
    setDonneur.insert(3);
    setDonneur.insert(4);
    cout << "Set donneur :";
    setDonneur.afficher();
    cout << "Set receveur :";
    setReceveur.insert(54);
    setReceveur.insert (32);
    setReceveur.insert(212);
    setReceveur.afficher();
    cout << "Apres copie," << endl;
    cout << "Set receveur :";
    setReceveur = setDonneur;
    setReceveur.afficher();

    cout << lignesSeparation;
    cout << "\nTEST CLEAR";
    cout << lignesSeparation << std::endl;
    cout << "Avant clear :";
    setReceveur.afficher();
    setReceveur.clear();
    cout << "Apres clear :";
    setReceveur.afficher();
    return 0;
}