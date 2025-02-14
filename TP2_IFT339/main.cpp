#include "vector.h"
#include "deque.h"
#include <iostream>

int main()
{
    int testSize = 5;
    string lignesSeparation = "\n====================================";

#pragma region vecteurs
    cout << "Tests des fonctions de vector2" << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DU CONSTRUCTEUR";
    cout << lignesSeparation << std::endl;
    cout << "\nCreation d'un vecteur de taille: " << testSize << std::endl;
    vector<int> vector0(testSize);
    vector0.afficher();

    vector0.clear();
    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DU CONSTRUCTEUR";
    cout << "\n======================" << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DE PUSH BACK";
    cout << lignesSeparation << std::endl;
    vector<int> vector1(testSize);

    cout << "\nEtat initial du vecteur 1:" << std::endl;
    vector1.afficher();

    cout << "\nAjout d'elements:" << std::endl;
    for (int i = 0; i < testSize; ++i) {
        vector1.push_back(i + 1);
        cout << "\nApres push_back(" << i + 1 << "):";
        vector1.afficher();
        cout << lignesSeparation << std::endl;
    }

    cout << "\nAjout d'elements, mais le vecteur est deja full:" << std::endl;
    vector1.push_back(testSize + 1);
    cout << "\nApres push_back(" << testSize + 1 << "):";
    vector1.afficher();

    vector1.clear();
    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DE PUSH BACK";
    cout << lignesSeparation << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DE RESERVE";
    cout << lignesSeparation << std::endl;

    vector<int> vector2(testSize);

    cout << "\nEtat initial du vecteur 2:" << std::endl;
    vector2.afficher();

    cout << "\nAppel a reserve(" << testSize + 1 << "):";
    vector2.reserve(testSize + 1);
    vector2.afficher();

    cout << "\nAppel a reserve(" << testSize - 1 << "):";
    vector2.reserve(testSize - 1);
    vector2.afficher();

    vector2.clear();
    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DE RESERVE";
    cout << lignesSeparation << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DE RESIZE";
    cout << lignesSeparation << std::endl;

    vector<int> vector3(testSize);

    cout << "\nEtat initial du vecteur 3:" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector3.push_back(i + 1);
    }

    vector3.afficher();

    cout << "\nAppel a resize(" << testSize + 3 << "):";
    vector3.resize(testSize + 3);
    vector3.afficher();

    cout << "\nAppel a resize(" << testSize - 1 << "):";
    vector3.resize(testSize - 1);
    vector3.afficher();

    vector3.clear();
    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DE RESIZE";
    cout << lignesSeparation << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DE BACK";
    cout << lignesSeparation << std::endl;

    vector<int> vector4(testSize);

    cout << "\nEtat initial du vecteur 4 (pas un const):" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector4.push_back(i + 1);
    }
    vector4.afficher();

    cout << "\nObtention du dernier element avec back: " << vector4.back() << std::endl;

    cout << "\nModification du dernier element avec back (60): \n";
    vector4.back() = 60;
    vector4.afficher();


    const vector<int>& vector5 = vector4;

    cout << lignesSeparation << std::endl;
    cout << "\nEtat initial du vecteur 5 (un const et une copie du vecteur 4):" << std::endl;
    vector5.afficher();

    cout << "\nObtention du dernier element avec back: " << vector5.back();
    vector5.afficher();

    vector4.clear();

    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DE BACK";
    cout << "\n======================" << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DE FRONT";
    cout << lignesSeparation << std::endl;

    vector<int> vector6(testSize);

    cout << "\nEtat initial du vecteur 6 (pas un const):" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector6.push_back(i + 1);
    }
    vector6.afficher();

    cout << "\nObtention du premier element avec front: " << vector6.front() << std::endl;

    cout << "\nModification du premier element avec front (60): \n";
    vector6.front() = 60;
    vector6.afficher();


    const vector<int>& vector7 = vector6;

    cout << lignesSeparation << std::endl;
    cout << "\nEtat initial du vecteur 7 (un const et une copie du vecteur 6):" << std::endl;
    vector7.afficher();

    cout << "\nObtention du premier element avec front: " << vector7.front() << std::endl;

    vector6.clear();

    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DE FRONT";
    cout << lignesSeparation << std::endl;

    cout << lignesSeparation;
    cout << "\n(vecteurs) DEBUT TEST DE OPERATOR[]";
    cout << lignesSeparation << std::endl;

    vector<int> vector8(testSize);

    cout << "\nEtat initial du vecteur 8 (pas un const):" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector8.push_back(i + 1);
    }
    vector8.afficher();

    cout << "\nObtention de l'element a l'index 2 avec operator[]: " << vector8.operator[](2) << std::endl;
    cout << "\nObtention de l'element a l'index 0 avec operator[]: " << vector8.operator[](0) << std::endl;
    cout << "\nObtention de l'element a l'index " << testSize << " avec operator[]: " << vector8.operator[](testSize-1) << std::endl;

    cout << "\nModification de l'element a l'index 4 avec operator[] (60): \n";

    vector8.operator[](4)  = 60;
    vector8.afficher();


    const vector<int>& vector9 = vector8;

    cout << lignesSeparation << std::endl;
    cout << "\nEtat initial du vecteur 9 (un const et une copie du vecteur 8):" << std::endl;
    vector9.afficher();

    cout << "\nObtention de l'element a l'index 3 avec operator[]: " << vector9.operator[](3) << std::endl;
    cout << "\nObtention de l'element a l'index 0 avec operator[]: " << vector9.operator[](0) << std::endl;
    cout << "\nObtention de l'element a l'index " << testSize << " avec operator[]: " << vector9.operator[](testSize-1) << std::endl;

    vector8.clear();

    cout << lignesSeparation;
    cout << "\n(vecteurs) FIN TEST DE OPERATOR[]";
    cout << lignesSeparation << std::endl;

#pragma endregion vecteurs

#pragma region deques
    cout << "Tests des fonctions de deque2" << endl;

    cout << lignesSeparation;
    cout << "\n(deques) DEBUT TEST DU CONSTRUCTEUR";
    cout << lignesSeparation << endl;
    cout << "\nCreation d'un deque de taille: " << testSize << endl;
    deque<int> deque0(testSize);
    deque0.afficher();

    cout << "\nCreation d'un deque par copie de deque0:" << endl;
    deque<int> deque1(deque0);
    deque1.afficher();

    deque0.clear();
    cout << lignesSeparation;
    cout << "\n(deques) FIN TEST DU CONSTRUCTEUR";
    cout << lignesSeparation << endl;

    cout << lignesSeparation;
    cout << "\n(deques) DEBUT TEST DE PUSH_BACK";
    cout << lignesSeparation << endl;
    deque<int> deque2(testSize);
    cout << "\nEtat initial du deque2:" << endl;
    deque2.afficher();

    cout << "\nAjout d'elements via push_back:" << endl;
    for (int i = 0; i < testSize; ++i) {
        deque2.push_back(i + 1);
        cout << "\nApres push_back(" << i + 1 << "):";
        deque2.afficher();
        cout << lignesSeparation << endl;
    }

    cout << "\nAjout d'elements via push_front:" << endl;
    for (int i = 0; i < testSize; ++i) {
        int value = (i + 1) * 10;
        deque2.push_front(value);
        cout << "\nApres push_front(" << value << "):";
        deque2.afficher();
        cout << lignesSeparation << endl;
    }

    cout << "\nTest de pop_front:" << endl;
    deque2.pop_front();
    cout << "\nApres pop_front:" << endl;
    deque2.afficher();

    cout << "\nTest de pop_back:" << endl;
    deque2.pop_back();
    cout << "\nApres pop_back:" << endl;
    deque2.afficher();

    cout << "\nTest de operator[]:" << endl;
    cout << "Element a l'index 0: " << deque2[0] << endl;
    cout << "Element a l'index 2: " << deque2[2] << endl;

    cout << "\nTest de at():" << endl;
    assert(deque2.size() > 1);
    cout << "Element a l'index 1: " << deque2.at(1) << endl;

    cout << "\nTest de front():" << endl;
    cout << "Premier element: " << deque2.front() << endl;
    cout << "\nTest de back():" << endl;
    cout << "Dernier element: " << deque2.back() << endl;

    cout << "\nTest de swap:" << endl;
    deque<int> deque3(testSize);
    for (int i = 0; i < testSize; ++i) {
        deque3.push_back((i + 1) * 100);
    }
    cout << "\nEtat initial du deque3:" << endl;
    deque3.afficher();
    cout << "\nSwap de deque2 et deque3:" << endl;
    deque2.swap(deque3);
    cout << "\nEtat du deque2 apres swap:" << endl;
    deque2.afficher();
    cout << "\nEtat du deque3 apres swap:" << endl;
    deque3.afficher();

    cout << "\nTest de reserve:" << endl;
    cout << "\nAvant reserve, deque3:" << endl;
    deque3.afficher();
    cout << "\nAppel reserve(" << testSize + 3 << "):" << endl;
    deque3.reserve(testSize + 3);
    deque3.afficher();

    cout << "\nTest de resize:" << endl;
    cout << "\nAvant resize, deque3:" << endl;
    deque3.afficher();
    cout << "\nAppel resize(" << testSize + 2 << "):" << endl;
    deque3.resize(testSize + 2);
    deque3.afficher();
    cout << "\nAppel resize(" << testSize - 1 << "):" << endl;
    deque3.resize(testSize - 1);
    deque3.afficher();

    cout << "\nTest de clear:" << endl;
    deque2.clear();
    deque3.clear();
    cout << "\nApres clear, deque2:" << endl;
    deque2.afficher();
    cout << "\nApres clear, deque3:" << endl;
    deque3.afficher();

    cout << lignesSeparation;
    cout << "\n(deques) FIN TEST DES FONCTIONS DEQUE";
    cout << lignesSeparation << endl;
#pragma endregion deques

    return 0;
}