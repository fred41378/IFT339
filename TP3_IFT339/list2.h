/**
* \ file list2.h
* \ author Aida Ouangraoua (Fev 2025)
* \ brief Ce fichier contient les fonctions
* \ du type list à coder
*/

#ifndef list2_h
#define list2_h

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::insert(cellule* C,const TYPE& X){
  cellule* tmp = new cellule(X);
  tmp->SUIV = C;
  tmp->PREC = C->PREC;
  tmp->PREC->SUIV = tmp;
  tmp->SUIV->PREC = tmp;
  SIZE++;
  return C;
}

template <typename TYPE>
typename list<TYPE>::cellule* list<TYPE>::erase(cellule* C) {

  cellule* next = C->SUIV;

  C->PREC->SUIV = C->SUIV;
  C->SUIV->PREC = C->PREC;

  delete C;
  SIZE--;

  return next;
}


template <typename TYPE>
class list<TYPE>::reverse_iterator {
  friend class list<TYPE>;
private:
  cellule* POINTEUR;
public:
  reverse_iterator(cellule* C = nullptr) : POINTEUR(C) {}
  TYPE& operator*() const { return POINTEUR->CONTENU; }
  TYPE* operator->() const { return &(POINTEUR->CONTENU); }
  reverse_iterator& operator++() {POINTEUR = POINTEUR->PREC;return *this;}
  reverse_iterator operator++(int) {reverse_iterator temp(*this);POINTEUR = POINTEUR->PREC;return temp;}
  reverse_iterator& operator--() {POINTEUR = POINTEUR->SUIV;return *this; }
  reverse_iterator operator--(int) {reverse_iterator temp(*this);POINTEUR = POINTEUR->SUIV;return temp;  }
  bool operator==(const reverse_iterator& IT) const {return POINTEUR == IT.POINTEUR;}
  bool operator!=(const reverse_iterator& IT) const {return POINTEUR != IT.POINTEUR;}
};


template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rbegin(){
  return reverse_iterator(DEBUT->PREC->PREC);
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::rend(){
  return reverse_iterator(DEBUT);
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::insert(reverse_iterator i, const TYPE& x) {
  return reverse_iterator(insert(i.POINTEUR, x));
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::erase(reverse_iterator i) {
  return reverse_iterator(erase(i.POINTEUR));
}



template <typename TYPE>
void list<TYPE>::operator=(list<TYPE>& L){
  if (&L == this)
    return;
  clear();
  for (iterator it = L.begin(); it != L.end(); ++it) {
    push_back(*it);
  }
}

template <typename TYPE>
void list<TYPE>::resize(size_t N, const TYPE& X) {
  if (size() == N) return;
  if (N > size()) {
    size_t nbDeFoi = N - size();
    for (size_t i = 0; i < nbDeFoi; ++i) {
      push_back(X);
    }
  }
  else if (N < size()) {
    size_t nbDeFoi = size() - N;
    for (size_t i = 0; i < nbDeFoi; ++i) {
      pop_back();
    }
  }
  SIZE = N;
}

template <typename TYPE>
void list<TYPE>::splice(iterator i,list& L){
  if (&L == this || L.empty()) {
    return;
  }
  cellule* position = i.POINTEUR;
  cellule* avant = position->PREC;

  cellule* first = L.DEBUT->SUIV;
  cellule* last = L.DEBUT->PREC->PREC;

  avant->SUIV = first;
  first->PREC = avant;

  last->SUIV = position;
  position->PREC = last;

  SIZE += L.SIZE;
  // Now, reset L to an empty state.
  cellule* tail = L.DEBUT->PREC;   // the tail dummy node remains unchanged

  // Set the source list L's pointers to match an empty list.
  L.DEBUT->SUIV = tail;
  L.DEBUT->PREC = tail;   // make sure both point to the tail dummy
  tail->PREC = L.DEBUT;   // reestablish the backward link

  L.SIZE = 0;
}

template <typename TYPE>
void list<TYPE>::reverse(){
  if (size() < 2) return;
  cellule* current = DEBUT->SUIV->SUIV;

  while (current != DEBUT->PREC) {
    cellule* next = current->SUIV;

    current->PREC->SUIV = current->SUIV;
    current->SUIV->PREC = current->PREC;

    current->SUIV = DEBUT->SUIV;
    DEBUT->SUIV->PREC = current;
    DEBUT->SUIV = current;
    current->PREC = DEBUT;

    current = next;
  }
}

template <typename TYPE>
void list<TYPE>::sort(iterator DEB, iterator FIN) {
  if(DEB == FIN) return;

  bool swapped;
  do {
    swapped = false;
    iterator it = DEB;
    iterator next_it = it;
    ++next_it;
    while(next_it != FIN) {
      if(*it > *next_it) {
        std::swap(*it, *next_it);
        swapped = true;
      }
      ++it;
      ++next_it;
    }
  } while(swapped);
}

#endif
