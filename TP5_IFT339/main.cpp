#include <iostream>
#include <map>

#include "map.h"

// int main() {
//     std::string lignesSeparation = "\n====================================";
//
//
//     std::cout << lignesSeparation;
//     std::cout << "\nTEST INSERT PAR CLEF";
//     std::cout << lignesSeparation << std::endl;
//
//     map<int,std::string> map_insert_clef;
//     std::cout << "Avant insert :" << std::endl;
//     map_insert_clef.afficher();
//     map_insert_clef.insert(10);
//     map_insert_clef.insert(20);
//     map_insert_clef.insert(30);
//     std::cout << "Apres insert, mais sans contenu : " << std::endl;
//     map_insert_clef.afficher();
//     map_insert_clef[10] = "Dix";
//     map_insert_clef[20] = "Vingt";
//     map_insert_clef[30] = "Trente";
//     std::cout << "Apres insert, avec contenu : " << std::endl;
//     map_insert_clef.afficher();
//
//
//     std::cout << lignesSeparation;
//     std::cout << "\nTEST INSERT PAR ITERRATEUR";
//     std::cout << lignesSeparation << std::endl;
//
//     map<int,std::string> map_insert_iterator;
//     std::cout << "Avant insert :" << std::endl;
//     map_insert_iterator.afficher();
//     map_insert_iterator.insert(10);
//     map_insert_iterator.insert(20);
//     map_insert_iterator.insert(30);
//     map_insert_iterator[10] = "Dix";
//     map_insert_iterator[20] = "Vingt";
//     map_insert_iterator[30] = "Trente";
//     std::cout << "Apres insert regulier :" << std::endl;
//     map_insert_iterator.afficher();
//     auto indice1 = map_insert_iterator.find(20);
//     map_insert_iterator.insert(indice1, 15);
//     map_insert_iterator[15] = "Quinze";
//     std::cout << "Apres insert avec iterator (15) : " << std::endl;
//     map_insert_iterator.afficher();
//
//
//     std::cout << lignesSeparation;
//     std::cout << "\nTEST ERASE PAR CLEF";
//     std::cout << lignesSeparation << std::endl;
//
//     map<int,std::string> map_erase_clef;
//     map_erase_clef.insert(10);
//     map_erase_clef[10] = "Dix";
//     map_erase_clef.insert(20);
//     map_erase_clef[20] = "Vingt";
//     map_erase_clef.insert(30);
//     map_erase_clef[30] = "Trente";
//     map_erase_clef.insert(40);
//     map_erase_clef[40] = "Quarante";
//     std::cout << "Avant erase :" << std::endl;
//     map_erase_clef.afficher();
//     map_erase_clef.erase(20);
//     map_erase_clef.afficher();
//
//
//     std::cout << lignesSeparation;
//     std::cout << "\nTEST GROS ECHAN";
//     std::cout << lignesSeparation << std::endl;
//
//     map<int,std::string> map_bigass;
//     for (int i = 0; i < 16; ++i) {
//         map_bigass.insert(i);
//         map_bigass[i] = std::to_string(i);
//     }
//     map_bigass.afficher();
//     map_bigass.verifier_hauteurs();
//
//     return 0;
// }
int main() {
    map<int, std::string> m;
    std::cout << "Arbre initial vide :" << std::endl;
    m.afficher();

    // Insertion de valeurs en ordre croissant
    std::cout << "\nInsertion de 1 :" << std::endl;
    auto r1 = m.insert(1);
    m.afficher();
    m.verifier_hauteurs(); // Vérifier si l'arbre est équilibré

    std::cout << "\nInsertion de 2 :" << std::endl;
    auto r2 = m.insert(2);
    m.afficher();
    m.verifier_hauteurs();

    std::cout << "\nInsertion de 3 :" << std::endl;
    auto r3 = m.insert(3);
    m.afficher();
    m.verifier_hauteurs();

    std::cout << "\nInsertion de 5 :" << std::endl;
    auto r4 = m.insert(5);
    m.afficher();
    m.verifier_hauteurs();

    m.insert(6);
    m.insert(9);
    m.insert(16);
    m.insert(12);
    m.insert(0);
    m.afficher();


    // Test de lower_bound avec affichage des résultats
    std::cout << "\nRecherche avec lower_bound :" << std::endl;

    auto it = m.lower_bound(4);
    std::cout << "lower_bound(4) -> ";
    if (it == m.end())
        std::cout << "end()" << std::endl;
    else
        std::cout << it->first << std::endl;

    it = m.lower_bound(3);
    std::cout << "lower_bound(3) -> ";
    if (it == m.end())
        std::cout << "end()" << std::endl;
    else
        std::cout << it->first << std::endl;

    // Test avec une valeur qui n'est pas dans l'arbre
    it = m.lower_bound(1000);
    std::cout << "lower_bound(1000) -> ";
    if (it == m.end())
        std::cout << "end()" << std::endl;
    else
        std::cout << it->first << std::endl;


    m.erase(5);
    m.afficher();
    m.erase(12);
    m.erase(9);
    m.erase(2);
    m.afficher();

    std::cout << "Erase 9 :" << std::endl;
    auto i = m.find(9);
    m.erase(i);
    m.afficher();
    std::cout << "Erase 6 :" << std::endl;
    i = m.find(6);
    m.erase(i);

    m.afficher();


    i = m.find(3);
    m.insert(i, 12);
    m.insert(i, 4);
    m.insert(i, 14);
    m.afficher();

    // end = 3
    map<int, std::string>::iterator ite = m.begin();
    m.erase(i);
    m.afficher();

    return 0;
}