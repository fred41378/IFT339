/**
* \ file set2.h
* \ author Aida Ouangraoua (Mars. 2025)
* \ brief Ce fichier contient les fonctions 
* \ du type map à coder
*/


#ifndef map2_h
#define map2_h


/////////////////////////////////////////////////
// map
// fonctions publiques
/////////////////////////////////////////////////

template <typename Tclef, typename Tvaleur>
typename map<Tclef,Tvaleur>::iterator map<Tclef,Tvaleur>::lower_bound(const Tclef& c) const {
  noeud* n = APRES->GAUCHE;
  noeud* lower = APRES;

  while (n != nullptr) {
    if (!(n->CONTENU->first >= c)) {
      lower = n;
      n = n->GAUCHE;
    } else {
      n = n->DROITE;
    }
  }

  return iterator(lower);
}


template <typename Tclef, typename Tvaleur>
typename map<Tclef,Tvaleur>::iterator map<Tclef,Tvaleur>::insert(iterator j, const Tclef& c) {
  if (j == end()) {
    return insert(c).first;
  }
  noeud* indice_noeud = j.POINTEUR;
  if (indice_noeud->CONTENU->first == c) {
    return j;
  }
  if (c < indice_noeud->CONTENU->first) {
    iterator prec = j;
    --prec;
    if (prec == end() || prec->first < c) {
      iterator it;
      if (insert(c, indice_noeud, it)) {
        return it;
      }
    }
  } else {
    iterator suiv = j;
    ++suiv;
    if (suiv == end() || suiv->first > c) {
      iterator it;
      if (insert(c, indice_noeud, it)) {
        return it;
      }
    }
  }
  return insert(c).first;
}

template <typename Tclef, typename Tvaleur>
  size_t map<Tclef,Tvaleur>::erase(const Tclef& c){
  if(empty()) return 0;

  noeud* racine = APRES->GAUCHE;
  noeud* a_remplacer = nullptr;
  bool suppression = erase(c, racine, a_remplacer);

  if(suppression) {
    APRES->GAUCHE = racine;
    if(a_remplacer) {
      while(racine->PARENT != APRES)
        racine = racine->PARENT;
      APRES->GAUCHE = racine;
    }
    return 1;
  }
  return 0;
}

template <typename Tclef, typename Tvaleur>
  typename map<Tclef,Tvaleur>::iterator map<Tclef,Tvaleur>::erase(iterator i){
  if (i == end()) return end();

  iterator it = i;
  ++it;

  Tclef c = i->first;
  erase(c);

  return it;
}


///////////////////////////////////////////////////
// fonctions privees pour la gestion de l'equilibre
///////////////////////////////////////////////////


template <typename Tclef, typename Tvaleur>
void map<Tclef,Tvaleur>::rotation_gauche_droite(noeud*& p){
  noeud* c = p->GAUCHE;
  noeud* c_droite = c->DROITE;

  c->DROITE = p;
  c->PARENT = p->PARENT;
  p->PARENT = c;

  p->GAUCHE = c_droite;
  if (c_droite != nullptr) {
    c_droite->PARENT = p;
  }

  p=c;

  p->INDICE=0;
  p->DROITE->INDICE=0;
}

template <typename Tclef, typename Tvaleur>
void map<Tclef,Tvaleur>::rotation_droite_gauche(noeud*& p){
  noeud* c = p->DROITE;
  noeud* c_gauche = c->GAUCHE;

  c->GAUCHE = p;
  c->PARENT = p->PARENT;
  p->PARENT = c;

  p->DROITE = c_gauche;
  if (c_gauche != nullptr) {
    c_gauche->PARENT = p;
  }

  p=c;

  p->INDICE=0;
  p->GAUCHE->INDICE=0;
}


#endif /* map2_h */
