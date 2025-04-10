#include <iostream>
#include <map>

#include "map.h"

int main() {
    std::string lignesSeparation = "\n====================================";


    std::cout << lignesSeparation;
    std::cout << "\nTEST INSERT PAR CLEF";
    std::cout << lignesSeparation << std::endl;

    map<int,std::string> map_insert_clef;
    std::cout << "Avant insert :" << std::endl;
    map_insert_clef.afficher();
    map_insert_clef.insert(10);
    map_insert_clef.insert(20);
    map_insert_clef.insert(30);
    std::cout << "Apres insert, mais sans contenu : " << std::endl;
    map_insert_clef.afficher();
    map_insert_clef[10] = "Dix";
    map_insert_clef[20] = "Vingt";
    map_insert_clef[30] = "Trente";
    std::cout << "Apres insert, avec contenu : " << std::endl;
    map_insert_clef.afficher();


    std::cout << lignesSeparation;
    std::cout << "\nTEST INSERT PAR ITERRATEUR";
    std::cout << lignesSeparation << std::endl;

    map<int,std::string> map_insert_iterator;
    std::cout << "Avant insert :" << std::endl;
    map_insert_iterator.afficher();
    map_insert_iterator.insert(10);
    map_insert_iterator.insert(20);
    map_insert_iterator.insert(30);
    map_insert_iterator[10] = "Dix";
    map_insert_iterator[20] = "Vingt";
    map_insert_iterator[30] = "Trente";
    std::cout << "Apres insert regulier :" << std::endl;
    map_insert_iterator.afficher();
    auto indice1 = map_insert_iterator.find(20);
    map_insert_iterator.insert(indice1, 15);
    map_insert_iterator[15] = "Quinze";
    std::cout << "Apres insert avec iterator (15) : " << std::endl;
    map_insert_iterator.afficher();


    std::cout << lignesSeparation;
    std::cout << "\nTEST ERASE PAR CLEF";
    std::cout << lignesSeparation << std::endl;

    map<int,std::string> map_erase_clef;
    map_erase_clef.insert(10);
    map_erase_clef[10] = "Dix";
    map_erase_clef.insert(20);
    map_erase_clef[20] = "Vingt";
    map_erase_clef.insert(30);
    map_erase_clef[30] = "Trente";
    map_erase_clef.insert(40);
    map_erase_clef[40] = "Quarante";
    std::cout << "Avant erase :" << std::endl;
    map_erase_clef.afficher();
    map_erase_clef.erase(20);
    map_erase_clef.afficher();


    std::cout << lignesSeparation;
    std::cout << "\nTEST GROS ECHAN";
    std::cout << lignesSeparation << std::endl;

    map<int,std::string> map_bigass;
    for (int i = 0; i < 16; ++i) {
        map_bigass.insert(i);
        map_bigass[i] = std::to_string(i);
    }
    map_bigass.afficher();
    map_bigass.verifier_hauteurs();


    return 0;
}
