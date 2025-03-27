/**
* \ file set2.h
* \ author Aida Ouangraoua (Mars 2025)
* \ brief Ce fichier contient les fonctions 
* \ du type set à coder
*/

#ifndef set2_h
#define set2_h

/////////////////////////////////////////////////
// set
// fonctions privees
/////////////////////////////////////////////////

template <typename TYPE>
typename set<TYPE>::cellule* set<TYPE>::erase(typename set<TYPE>::cellule* C) {
  if (!C || C == DEBUT || C == DEBUT->PREC[0]) {
    return C;
  }

  cellule* suivant = C->SUIV[0];

  for (size_t i = 0; i < C->HAUTEUR; ++i) {
    cellule* prev = C->PREC[i];
    cellule* next = C->SUIV[i];
    prev->SUIV[i] = next;
    next->PREC[i] = prev;
  }

  --SIZE;
  delete C;
  return suivant;
}

/////////////////////////////////////////////////
// set
// fonctions publiques
/////////////////////////////////////////////////

template <typename TYPE>
set<TYPE>::set(const set<TYPE>& source) : set() {
  DEBUT->HAUTEUR = source.DEBUT->HAUTEUR;
  DEBUT->PREC[0]->HAUTEUR = source.DEBUT->PREC[0]->HAUTEUR;

  delete[] DEBUT->SUIV;
  delete[] DEBUT->PREC[0]->PREC;

  DEBUT->SUIV = new cellule*[DEBUT->HAUTEUR];
  DEBUT->PREC[0]->PREC = new cellule*[DEBUT->PREC[0]->HAUTEUR];

  std::vector<cellule*> new_cells(DEBUT->HAUTEUR, DEBUT);
  cellule* current_source = source.DEBUT->SUIV[0];

  while (current_source && current_source != source.DEBUT->PREC[0]) {
    cellule* current_cell = new cellule(current_source->CONTENU, current_source->HAUTEUR);
    for (size_t i = 0; i < current_cell->HAUTEUR; ++i) {
      current_cell->PREC[i] = new_cells[i];
      new_cells[i]->SUIV[i] = current_cell;
      new_cells[i] = current_cell;
    }
    current_source = current_source->SUIV[0];
    ++SIZE;
  }

  for (size_t i = 0; i < DEBUT->HAUTEUR; ++i) {
    new_cells[i]->SUIV[i] = DEBUT->PREC[0];
    DEBUT->PREC[0]->PREC[i] = new_cells[i];
  }
}

template <typename TYPE>
set<TYPE>::~set()
{
  clear();
  delete DEBUT;
}

template <typename TYPE>
void set<TYPE>::clear()
{
  cellule* current = DEBUT->SUIV[0];
  while (current != nullptr && current != DEBUT->PREC[0]) {
    cellule* next = current->SUIV[0];
    erase(current);
    current = next;
  }
  SIZE = 0;
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::find(const TYPE& X)
{
  iterator it = lower_bound(X);
  if (it != end() && *it == X) {
    return it;
  }
  return end();
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::lower_bound(const TYPE& X)
{
  cellule* current = DEBUT;
  size_t k = DEBUT->HAUTEUR;
  for (size_t i = k; i-- > 0;) {
    size_t index = i;
    while (current->SUIV[index] != DEBUT->PREC[0] && current->SUIV[index]->CONTENU < X) {
      current = current->SUIV[index];
    }
  }
  current = current->SUIV[0];
  return iterator(current);
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::upper_bound(const TYPE& X)
{
  cellule* current = DEBUT;
  size_t k = DEBUT->SUIV[0]->HAUTEUR;
  for (size_t i = k; i-- > 0;) {
    size_t index = i;
    while (current->SUIV[index] != DEBUT->PREC[0] && current->SUIV[index]->CONTENU <= X) {
      current = current->SUIV[index];
    }
  }
  current = current->SUIV[0];
  return iterator(current);
}

template <typename TYPE>
std::pair<typename set<TYPE>::iterator, bool> set<TYPE>::insert(const TYPE& X) {
  cellule* current = DEBUT;

  for (size_t i = DEBUT->HAUTEUR; i-- > 0;) {
    while (current->SUIV[i] != nullptr && current->SUIV[i] != DEBUT->PREC[0] && current->SUIV[i]->CONTENU < X) {
      current = current->SUIV[i];
    }
  }

  cellule* candidat = current->SUIV[0];
  if (candidat != nullptr && candidat != DEBUT->PREC[0] && candidat->CONTENU == X) {
    return {iterator(candidat), false};
  }

  cellule* nCell = insert(current->SUIV[0], X);
  return {iterator(nCell), true};
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::insert(iterator it, const TYPE& X) {
  if (it == end()) {
    cellule* ap = DEBUT->PREC[0];
    cellule* new_node = insert(ap, X);
    return iterator(new_node);
  }

  cellule* cell = it.POINTEUR;

  if (cell->CONTENU <= X) {
    cellule* next_node = cell->SUIV[0];
    if (next_node == DEBUT->PREC[0] || next_node->CONTENU >= X) {
      if (next_node != DEBUT->PREC[0] && next_node->CONTENU == X) {
        return iterator(next_node);
      }
      cellule* new_node = insert(next_node, X);
      return iterator(new_node);
    }
  }

  if (cell->CONTENU > X) {
    cellule* prev_node = cell->PREC[0];
    if (prev_node != DEBUT && prev_node->CONTENU <= X) {
      if (prev_node->CONTENU == X) {
        return iterator(prev_node);
      }
      cellule* new_node = insert(cell, X);
      return iterator(new_node);
    }
  }
  return insert(X).first;
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::erase(const TYPE& VAL)
{
  iterator it = find(VAL);
  if (it != end()) {
    cellule* current = it.POINTEUR;
    erase(current);
    return iterator(current->SUIV[0]);
  }
  return end();
}

template <typename TYPE>
typename set<TYPE>::iterator set<TYPE>::erase(iterator it)
{
  if (it != end()) {
    cellule* current = it.POINTEUR;
    erase(current);
    return iterator(current->SUIV[0]);
  }
  return end();
}

#endif
