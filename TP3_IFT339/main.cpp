#include <algorithm>
#include <iostream>
#include "list.h"

int main() {
    std::cout << "Testing list<int> operations:" << std::endl;

    list<int> list1;

    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);
    std::cout << "\nApres push_back:" << std::endl;
    list1.afficher();

    // Test push_front: adding an element at the beginning.
    list1.push_front(5);
    std::cout << "\nApres push_front(5):" << std::endl;
    list1.afficher();

    typename list<int>::iterator it = list1.begin();
    ++it;
    list1.insert(it, 7);
    std::cout << "\nApres inserer au deuxieme en regular iterator (7):" << std::endl;
    list1.afficher();
    --it;
    list1.erase(it);
    std::cout << "\nApres delete au deuxieme en regular iterator" << std::endl;
    list1.afficher();

    typename list<int>::reverse_iterator r_it = list1.rbegin();
    ++r_it;
    list1.insert(r_it, 9);
    std::cout << "\nApres inserer a l'avant dernier en reverse iterator (9):" << std::endl;
    list1.afficher();
    --r_it;
    list1.erase(r_it);
    std::cout << "\nApres delete a l'avant dernier en reverse iterator (9):" << std::endl;
    list1.afficher();

    list<int> list2 = list1;
    list2.afficher();

    list2.resize(2);
    list2.afficher();

    list2.resize(4, 7);
    list2.afficher();

    list1.reverse();


    typename list<int>::iterator it2 = list2.begin();
    ++it2;
    list2.splice(it2, list1);
    list2.afficher();

    list2.resize(4);
    list2.afficher();
    list2.reverse();
    list2.afficher();

    list2.sort(list2.begin(), list2.end());
    list2.afficher();


    return 0;
}
