/**
* \ file vector.h
* \ author Aida Ouangraoua (Jan. 2023)
* \ brief Ce fichier contient les fonctions du type vector à coder
*/

#ifndef _vector2_h
#define _vector2_h

template <typename TYPE>
vector<TYPE>::vector(size_t D)
{
  if (D == 0) {
    DEBUT = FIN_DIM = FIN_CAP = nullptr;
  } else {
    DEBUT = new TYPE[D];
    FIN_DIM = DEBUT;
    FIN_CAP = DEBUT + D;
  }
}

template <typename TYPE>
void vector<TYPE>::reserve(size_t nCAP)
{
  size_t currentCapacity = FIN_CAP - DEBUT;
  if (currentCapacity >= nCAP) {
    return;
  }
  TYPE* tmp = new TYPE[nCAP]();

  size_t currentSize = FIN_DIM - DEBUT;
  for (size_t i = 0; i < currentSize; ++i) {
    tmp[i] = DEBUT[i];
  }

  delete[] DEBUT;

  DEBUT = tmp;
  FIN_DIM = tmp + currentSize;
  FIN_CAP = tmp + nCAP;
}

template <typename TYPE>
TYPE& vector<TYPE>::back()
{
  return DEBUT[size()-1];
}

template <typename TYPE>
const TYPE& vector<TYPE>::back()const
{
  return DEBUT[size()-1];
}

template <typename TYPE>
TYPE& vector<TYPE>::front()
{
  return DEBUT[0];
}

template <typename TYPE>
const TYPE& vector<TYPE>::front()const
{
  return DEBUT[0];
}

template <typename TYPE>
TYPE& vector<TYPE>::operator[](size_t i)
{
  return DEBUT[i];
}

template <typename TYPE>
const TYPE& vector<TYPE>::operator[](size_t i)const
{
  return DEBUT[i];
}


#endif
