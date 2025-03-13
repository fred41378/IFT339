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
  if (C == DEBUT)
    push_front(X);
  else {
    cellule* tmp = new cellule(X);
    tmp->SUIV = C;
    tmp->PREC = C->PREC;
    tmp->PREC->SUIV = tmp;
    tmp->SUIV->PREC = tmp;
    SIZE++;
  }
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
  // Reverse the directions:
  reverse_iterator& operator++() {
    POINTEUR = POINTEUR->PREC;
    return *this;
  }
  reverse_iterator operator++(int) {
    reverse_iterator temp(*this);
    POINTEUR = POINTEUR->PREC;
    return temp;
  }
  reverse_iterator& operator--() {
    POINTEUR = POINTEUR->SUIV;
    return *this;
  }
  reverse_iterator operator--(int) {
    reverse_iterator temp(*this);
    POINTEUR = POINTEUR->SUIV;
    return temp;
  }
  bool operator==(const reverse_iterator& IT) const {
    return POINTEUR == IT.POINTEUR;
  }
  bool operator!=(const reverse_iterator& IT) const {
    return POINTEUR != IT.POINTEUR;
  }
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
  iterator base_iterator(i.POINTEUR);
  ++base_iterator;
  iterator inserted_iterator = insert(base_iterator, x);
  return reverse_iterator(inserted_iterator.POINTEUR);
}

template <typename TYPE>
typename list<TYPE>::reverse_iterator list<TYPE>::erase(reverse_iterator i) {
  iterator it(i.POINTEUR);

  iterator next_it = erase(it);
  return reverse_iterator(next_it.POINTEUR->PREC);
}



template <typename TYPE>
void list<TYPE>::operator=(list<TYPE>& L){
  clear();
  for (iterator it = L.begin(); it != L.end(); ++it) {
    push_back(*it);
  }
}

template <typename TYPE>
void list<TYPE>::resize(size_t N, const TYPE& X) {
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

  cellule* L_tail = L.DEBUT->PREC;
  L.DEBUT->SUIV = L_tail;
  L.DEBUT->PREC = L_tail;
  L_tail->PREC = L.DEBUT;
  L.SIZE = 0;
}

template <typename TYPE>
void list<TYPE>::reverse(){
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
  iterator it = DEB;
  ++it;

  while (it != FIN) {
    TYPE value = *it;
    iterator next_it = it;
    ++next_it;
    iterator pos = DEB;
    while (pos != it && *pos <= value) {
      ++pos;
    }

    if (pos != it) {
      erase(it);
      insert(pos, value);
    }

    it = next_it;
  }
}




#endif
