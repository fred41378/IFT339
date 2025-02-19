/**
* \ file polygone.cpp
* \ author Aida Ouangraoua
* \ brief Ce fichier contient l'implementation
* des operations du type Polygone
*/

#include "polygone.h"

Polygone::Polygone() : Polygone(0){
}

Polygone::Polygone(int nb) : nb_sommets(nb){
}

void Polygone::translater(Point vector){
    for (int i = 0; i < nb_sommets; i++) {
        sommets[i].translater(vector);
    }
}

void Polygone::tournerOrigine(float angle_degres){
    for (int i = 0; i < nb_sommets; i++) {
        sommets[i].tournerOrigine(angle_degres);
    }
}

void Polygone::tourner(Point p, float angle_degres){
    for (int i = 0; i < nb_sommets; i++) {
        sommets[i].tourner(p,angle_degres);
    }
}

float Polygone::calculerCirconference(){
  float  circonference = 0.0;

  for (int i = 0; i < nb_sommets; i++) {
      circonference += sommets[i].calculerDistance(sommets[(i + 1) %  nb_sommets]);
  }
  return circonference;
}

void Polygone::afficher(void){
  cout << "Sommets ";
  for(int i = 0; i < nb_sommets; i++){
    cout << " ";
    sommets[i].afficher();
  }
  cout << endl;

}
