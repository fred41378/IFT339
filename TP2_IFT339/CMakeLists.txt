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