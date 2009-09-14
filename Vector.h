#ifndef __BAJS__
#define __BAJS__

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <stdexcept>
template <class T>
class Vector{
  size_t vector_size;
  size_t array_size;
  /*const size_t DEFAULT_SIZE(8);
    const size_t ENLARGE_FACTOR(2);*/
  T * array;
  
 public:
  Vector();
  explicit Vector(size_t); 
  explicit Vector(size_t, T);
  // Kopieringskonstruktor
  Vector(const Vector<T> &);
  
  // Överlagrad = operator
  Vector<T> & operator=(Vector<T> &);
  
  // Överlagrad [] operator
  T & operator[](size_t);
  
  /* Behövs för tex std::cout */
  const T & operator[](size_t) const;  

  const int size(void) const;
  const int get_array_size(void) const;
  /*
  void setSize(size_t);
  */
  void enlargeArray(void);
  void push_back(T);
};

#include "Vector.cpp"

#endif // __BAJS__
