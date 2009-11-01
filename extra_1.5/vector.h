#ifndef __BAJS__
#define __BAJS__

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <stdexcept>
#include "math.h"

template <class T>
class Vector{
  /* Ordinary Vector */
  size_t vector_size;
  size_t array_size;

  // static const size_t DEFAULT_SIZE(8);
  // static const size_t ENLARGE_FACTOR = 2;
  T * array;
 public:

  Vector(void);
  explicit Vector(size_t);
  Vector(size_t, T);
  Vector(const Vector<T> &);
  Vector<T> & operator=(const Vector<T> &);  
  T & operator[](const size_t);
  const T & operator[](const size_t) const;
  const int size(void) const;
  const int get_array_size(void) const;
  void push_back(T);
  void insert(size_t,T);
  void erase(size_t);
  void clear(void);
  void sort(bool);
  ~Vector();

};

/* Vector<bool> */
template <>
class Vector<bool>{
  size_t vector_size;
  size_t int_array_size;
  size_t bool_array_size;
  static const double BYTE_SIZE = 8;
  unsigned int * array;  
  friend class reference;
 
 public:

  // Auxiliary type conversin to bool
  // This class represents a signle bit in a Vector<bool>
  // The reference keeps track of the position of a single bit in a Vector<bool>
  class reference{
  public:
    friend class Vector;
    int int_index;
    int bit_index;
    bool ref_b;
    unsigned int * array_p;
    //automatic type converts into bool
    //returns the bit value as bool
    operator bool() const;
    //bool operator() const;
    //assignment
    reference & operator= (const bool);
    reference & operator= (const reference&);
    // bit complement
    //void flip();
  };
  bool operator[](const size_t) const; 
  reference operator[](const size_t);
  reference at(size_t);
  reference front();
  reference back();
  
  Vector(void);  
  explicit Vector(size_t);
  Vector(size_t, bool);
  Vector(const Vector<bool> &);
  Vector<bool> & operator=(const Vector<bool> &);  
  int to_int() const;
  const int size(void) const;
  const int get_array_size(void) const;
  void push_back(bool);
  void clear(void);
  void sort(bool);
  ~Vector();
  
};
Vector<bool> to_vec(int);

#include "vector.cpp"
#include "vector_bool.cpp"
#endif //__BAJS__
