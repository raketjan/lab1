#ifndef __BAJS__
#define __BAJS__

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <stdexcept>
template <class T>
class Vector{
  size_t size;
  int next_empty;
  T * v1;
  
 public:
  Vector();
  explicit Vector(size_t); 
  explicit Vector(size_t, T);
  // Kopieringskonstruktor
  Vector(const Vector<T> &);
  
  // Överlagrad = operator
  Vector<T> & operator=(Vector<T> & v2);
  
  // Överlagrad [] operator
  T & operator[](size_t);
  
  /* Behövs för tex std::cout */
  const T & operator[](size_t) const;  

  const int getSize() const;
  
  void setSize(size_t);
  
  void push_back(T);
};

#include "Vector.cpp"

#endif // __BAJS__
