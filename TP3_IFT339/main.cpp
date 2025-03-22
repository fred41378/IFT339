#include <iostream>
#include "list.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {


    list<int> l1;

    list<int> l2(10); // Utilise le constructeur avec N éléments (10 éléments de type int initialisés à 0)

    list<int>::iterator it;

    std::cout << "-------------------------TEST L1--------------------------" << std::endl;
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(0);
    l1.push_front(-1);

    l1.pop_front();
    l1.pop_back();

    l1.resize(10, 5);

    l1.afficher();

    l1.reverse();
    l1.afficher();


    std::cout << "-------------------------TEST L2--------------------------" << std::endl;
    l2.afficher();

    l2 = l1;
    it = l2.begin();
    l2.afficher();

    l2.splice(it, l1);

    l2.afficher();

    l2.reverse();
    l2.afficher();

    l2.sort(l2.begin(), l2.end());
    l2.afficher();


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

    it = list1.begin();
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


    std::cout << "\noperator = :" << std::endl;
    list<int> list2;
    list2.push_back(10);
    list2.push_back(20);
    list2.push_back(30);
    list2 = list1;
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
    std::cout << "\n reverse :" << std::endl;
    list2.reverse();
    list2.afficher();

    list2.sort(list2.begin(), list2.end());
    list2.afficher();

    list<int> list3;
    list3 = list2;
    list3.afficher();

    list3.push_back(2);
    list3.push_back(14);
    list3.push_back(3);
    list3.push_back(4);
    list3.push_back(1);
    list3.afficher();

    list3.sort(list3.begin(), list3.end());
    list3.afficher();

    return 0;
}
