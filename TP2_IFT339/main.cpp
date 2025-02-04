#include "vector.h"
#include "deque.h"
#include <iostream>

int main()
{
    int testSize = 5;
    string lignesSeparation = "\n====================================";

#pragma region vecteurs
    std::cout << "Tests des fonctions de vector2" << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DU CONSTRUCTEUR";
    std::cout << lignesSeparation << std::endl;
    std::cout << "\nCreation d'un vecteur de taille: " << testSize << std::endl;
    vector<int> vector0(testSize);
    vector0.afficher();

    vector0.clear();
    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DU CONSTRUCTEUR";
    std::cout << "\n======================" << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DE PUSH BACK";
    std::cout << lignesSeparation << std::endl;
    vector<int> vector1(testSize);

    std::cout << "\nEtat initial du vecteur 1:" << std::endl;
    vector1.afficher();

    std::cout << "\nAjout d'elements:" << std::endl;
    for (int i = 0; i < testSize; ++i) {
        vector1.push_back(i + 1);
        std::cout << "\nApres push_back(" << i + 1 << "):";
        vector1.afficher();
        std::cout << lignesSeparation << std::endl;
    }

    std::cout << "\nAjout d'elements, mais le vecteur est deja full:" << std::endl;
    vector1.push_back(testSize + 1);
    std::cout << "\nApres push_back(" << testSize + 1 << "):";
    vector1.afficher();

    vector1.clear();
    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DE PUSH BACK";
    std::cout << lignesSeparation << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DE RESERVE";
    std::cout << lignesSeparation << std::endl;

    vector<int> vector2(testSize);

    std::cout << "\nEtat initial du vecteur 2:" << std::endl;
    vector2.afficher();

    std::cout << "\nAppel a reserve(" << testSize + 1 << "):";
    vector2.reserve(testSize + 1);
    vector2.afficher();

    std::cout << "\nAppel a reserve(" << testSize - 1 << "):";
    vector2.reserve(testSize - 1);
    vector2.afficher();

    vector2.clear();
    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DE RESERVE";
    std::cout << lignesSeparation << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DE RESIZE";
    std::cout << lignesSeparation << std::endl;

    vector<int> vector3(testSize);

    std::cout << "\nEtat initial du vecteur 3:" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector3.push_back(i + 1);
    }

    vector3.afficher();

    std::cout << "\nAppel a resize(" << testSize + 3 << "):";
    vector3.resize(testSize + 3);
    vector3.afficher();

    std::cout << "\nAppel a resize(" << testSize - 1 << "):";
    vector3.resize(testSize - 1);
    vector3.afficher();

    vector3.clear();
    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DE RESIZE";
    std::cout << lignesSeparation << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DE BACK";
    std::cout << lignesSeparation << std::endl;

    vector<int> vector4(testSize);

    std::cout << "\nEtat initial du vecteur 4 (pas un const):" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector4.push_back(i + 1);
    }
    vector4.afficher();

    std::cout << "\nObtention du dernier element avec back: " << vector4.back() << std::endl;

    std::cout << "\nModification du dernier element avec back (60): \n";
    vector4.back() = 60;
    vector4.afficher();


    const vector<int>& vector5 = vector4;

    std::cout << lignesSeparation << std::endl;
    std::cout << "\nEtat initial du vecteur 5 (un const et une copie du vecteur 4):" << std::endl;
    vector5.afficher();

    std::cout << "\nObtention du dernier element avec back: " << vector5.back();
    vector5.afficher();

    vector4.clear();

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DE BACK";
    std::cout << "\n======================" << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DE FRONT";
    std::cout << lignesSeparation << std::endl;

    vector<int> vector6(testSize);

    std::cout << "\nEtat initial du vecteur 6 (pas un const):" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector6.push_back(i + 1);
    }
    vector6.afficher();

    std::cout << "\nObtention du premier element avec front: " << vector6.front() << std::endl;

    std::cout << "\nModification du premier element avec front (60): \n";
    vector6.front() = 60;
    vector6.afficher();


    const vector<int>& vector7 = vector6;

    std::cout << lignesSeparation << std::endl;
    std::cout << "\nEtat initial du vecteur 7 (un const et une copie du vecteur 6):" << std::endl;
    vector7.afficher();

    std::cout << "\nObtention du premier element avec front: " << vector7.front() << std::endl;

    vector6.clear();

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DE FRONT";
    std::cout << lignesSeparation << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) DEBUT TEST DE OPERATOR[]";
    std::cout << lignesSeparation << std::endl;

    vector<int> vector8(testSize);

    std::cout << "\nEtat initial du vecteur 8 (pas un const):" << std::endl;

    for (int i = 0; i < testSize; ++i) {
        vector8.push_back(i + 1);
    }
    vector8.afficher();

    std::cout << "\nObtention de l'element a l'index 2 avec operator[]: " << vector8.operator[](2) << std::endl;
    std::cout << "\nObtention de l'element a l'index 0 avec operator[]: " << vector8.operator[](0) << std::endl;
    std::cout << "\nObtention de l'element a l'index " << testSize << " avec operator[]: " << vector8.operator[](testSize-1) << std::endl;

    std::cout << "\nModification de l'element a l'index 4 avec operator[] (60): \n";

    vector8.operator[](4)  = 60;
    vector8.afficher();


    const vector<int>& vector9 = vector8;

    std::cout << lignesSeparation << std::endl;
    std::cout << "\nEtat initial du vecteur 9 (un const et une copie du vecteur 8):" << std::endl;
    vector9.afficher();

    std::cout << "\nObtention de l'element a l'index 3 avec operator[]: " << vector9.operator[](3) << std::endl;
    std::cout << "\nObtention de l'element a l'index 0 avec operator[]: " << vector9.operator[](0) << std::endl;
    std::cout << "\nObtention de l'element a l'index " << testSize << " avec operator[]: " << vector9.operator[](testSize-1) << std::endl;

    vector8.clear();

    std::cout << lignesSeparation;
    std::cout << "\n(vecteurs) FIN TEST DE OPERATOR[]";
    std::cout << lignesSeparation << std::endl;

#pragma endregion vecteurs

#pragma region deques
    std::cout << "Tests des fonctions de deque2" << std::endl;

    std::cout << lignesSeparation;
    std::cout << "\n(deques) DEBUT TEST DU CONSTRUCTEUR";
    std::cout << lignesSeparation << std::endl;

    std::cout << "\nCreation d'un deque de taille: " << testSize << std::endl;
    deque<int> deque0(testSize);
    deque0.afficher();

    std::cout << "\nCreation d'un deque qui est une cope de deque 0: " << testSize << std::endl;
    const deque<int>& deque1 = deque0;
    deque1.afficher();

    deque0.clear();
    std::cout << lignesSeparation;
    std::cout << "\n(deques) FIN TEST DU CONSTRUCTEUR";
    std::cout << lignesSeparation << std::endl;

#pragma endregion deques
    return 0;
}