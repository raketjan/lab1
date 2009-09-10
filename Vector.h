#ifndef __BAJS__
#define __BAJS__

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <stdexcept>
template <class T>
class Vector{
  size_t size;
  T * v1;
  
 public:
  explicit Vector(size_t); 
  // Kopieringskonstruktor
  Vector(const Vector<T> &);
  
  // Överlagrad = operator
  Vector<T> & operator=(Vector<T> &);
  
  // Överlagrad [] operator
  T & operator[](size_t i);
  const T & operator[](size_t i) const;  
};
#include "Vector.cpp"
#endif // __BAJS__
