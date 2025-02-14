/**
* \ file deque2.h
* \ author Aida Ouangraoua (Jan. 2023)
* \ brief Ce fichier contient les fonctions 
* \ du type deque à coder
*/

#ifndef deque2_h
#define deque2_h

template <typename TYPE>
deque<TYPE>::deque(size_t D)
{
  if (D == 0) {
    DEBUT_CAP = FIN_CAP = nullptr;
    FRONT = BACK = nullptr;
  } else {
    DEBUT_CAP = new TYPE[D];
    FIN_CAP = DEBUT_CAP + D;
    FRONT = BACK = nullptr;
  }
}

template <typename TYPE>
deque<TYPE>::deque(const deque& source) :deque()
{
  size_t n = source.size();
  if(n == 0) {
    DEBUT_CAP = FIN_CAP = nullptr;
    FRONT = BACK = nullptr;
  } else {
    DEBUT_CAP = new TYPE[n];
    FIN_CAP = DEBUT_CAP + n;
    for(size_t i = 0; i < n; i++){
      DEBUT_CAP[i] = source[i];
    }
    FRONT = DEBUT_CAP;
    BACK = DEBUT_CAP + n - 1;
  }

}

template <typename TYPE>
void deque<TYPE>::swap(deque& v)
{
  std::swap(DEBUT_CAP, v.DEBUT_CAP);
  std::swap(FIN_CAP, v.FIN_CAP);
  std::swap(BACK, v.BACK);
  std::swap(FRONT, v.FRONT);
}

template <typename TYPE>
void deque<TYPE>::operator=(const deque& source)
{
  deque temp(source);
  swap(temp);
}
  
template <typename TYPE>
void deque<TYPE>::reserve(size_t nCAP)
{
  size_t oldCap = (FIN_CAP ? (FIN_CAP - DEBUT_CAP) : 0);
  if(nCAP <= oldCap) {
    return;
  }
  TYPE* temp = new TYPE[nCAP];

  size_t currentSize = size();
  for (size_t i = 0; i < currentSize; i++){
    temp[i] = DEBUT_CAP[i];
  }
  delete[] DEBUT_CAP;

  DEBUT_CAP = temp;
  FIN_CAP = temp + nCAP;

  if(currentSize > 0){
    FRONT = DEBUT_CAP;
    BACK = DEBUT_CAP + currentSize - 1;
  } else {
    FRONT = BACK = nullptr;
  }
}

template <typename TYPE>
void deque<TYPE>::clear()
{
  delete[] DEBUT_CAP;
  DEBUT_CAP = FIN_CAP = nullptr;
  FRONT = BACK = nullptr;
}

template <typename TYPE>
void deque<TYPE>::push_front(const TYPE& x)
{
  size_t dim = size();
  size_t cap = FIN_CAP - DEBUT_CAP;

  if (cap == 0) {
    reserve(1);
    cap =1;
  }
  else if (cap == dim) {
    reserve(cap*2);
    cap = FIN_CAP - DEBUT_CAP;
  }
  if (empty()) {
    FRONT = BACK = DEBUT_CAP;

  }else {
    if (FRONT == DEBUT_CAP) {
      FRONT = FIN_CAP - 1;
    }
    else {
      FRONT = FRONT - 1;
    }
  }

  *FRONT = x;
}

template <typename TYPE>
void deque<TYPE>::push_back(const TYPE& x)
{
  size_t dim = size();
  size_t cap = FIN_CAP - DEBUT_CAP;

  if (cap == 0) {
    reserve(1);
    cap = 1;
  }
  else if (cap == dim) {
    reserve(cap*2);
    cap = FIN_CAP - DEBUT_CAP;
  }
  if (empty()) {
    FRONT = BACK = DEBUT_CAP;

  }else {
    if (BACK == FIN_CAP - 1) {
      BACK = DEBUT_CAP;
    }
    else {
      BACK = BACK + 1;
    }
  }

  *BACK = x;
}

template <typename TYPE>
size_t deque<TYPE>::size()const
{
  if (FRONT == nullptr)
    return 0;

  if (FRONT <= BACK)
    return BACK - FRONT + 1;
  else
    return FIN_CAP - FRONT + (BACK - DEBUT_CAP + 1);
}

template <typename TYPE>
bool deque<TYPE>::empty()const
{
  return FRONT == nullptr;
}

template <typename TYPE>
TYPE& deque<TYPE>::operator[](size_t i)
{
  size_t cap = FIN_CAP - DEBUT_CAP;
  size_t index = ( (FRONT - DEBUT_CAP) + i ) % cap;
  return DEBUT_CAP[index];
}

template <typename TYPE>
const TYPE& deque<TYPE>::operator[](size_t i) const
{
  size_t cap = FIN_CAP - DEBUT_CAP;
  size_t index = ( (FRONT - DEBUT_CAP) + i ) % cap;
  return DEBUT_CAP[index];
}

template <typename TYPE>
TYPE& deque<TYPE>::at(size_t i)
{
  assert(i < size());
  return (*this)[i];
}

template <typename TYPE>
const TYPE& deque<TYPE>::at(size_t i) const
{
  assert(i < size());
  return (*this)[i];
}

#endif
