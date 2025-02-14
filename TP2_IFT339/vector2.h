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
  DEBUT = new TYPE[D];
  FIN_DIM = DEBUT;
  FIN_CAP = DEBUT + D;
}

template <typename TYPE>
void vector<TYPE>::reserve(size_t nCAP)
{
  size_t currentCapacity = FIN_CAP - DEBUT;
  if (currentCapacity >= nCAP) {
    return;
  }
  TYPE* temp = new TYPE[nCAP]();

  size_t currentSize = FIN_DIM - DEBUT;
  for (size_t i = 0; i < currentSize; ++i) {
    temp[i] = DEBUT[i];
  }

  delete[] DEBUT;

  DEBUT = temp;
  FIN_DIM = temp + currentSize;
  FIN_CAP = temp + nCAP;
}

template <typename TYPE>
TYPE& vector<TYPE>::back()
{
  if (empty()) {
    throw std::out_of_range("Vector is empty");
  }
  return DEBUT[size()-1];
}

template <typename TYPE>
const TYPE& vector<TYPE>::back()const
{
  if (empty()) {
    throw std::out_of_range("Vector is empty");
  }
  return DEBUT[size()-1];
}

template <typename TYPE>
TYPE& vector<TYPE>::front()
{
  if (empty()) {
    throw std::out_of_range("Vector is empty");
  }
  return DEBUT[0];
}

template <typename TYPE>
const TYPE& vector<TYPE>::front()const
{
  if (empty()) {
    throw std::out_of_range("Vector is empty");
  }
  return DEBUT[0];
}

template <typename TYPE>
TYPE& vector<TYPE>::operator[](size_t i)
{
  if (empty()) {
    throw std::out_of_range("Vector is empty");
  }
  if(i >= size()){
    throw std::out_of_range("Vector index out of range.");
    }
  return DEBUT[i];
}

template <typename TYPE>
const TYPE& vector<TYPE>::operator[](size_t i)const
{
  if (empty()) {
    throw std::out_of_range("Vector is empty");
  }
  if(i >= size()){
    throw std::out_of_range("Vector index out of range.");
  }
  return DEBUT[i];
}


#endif
