#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include "vector.h"

class Matrix{
  size_t cols;
  size_t rows;
  /*  Vector<Vector <int> > matrix;
  Vector<int> * vector_array;
  int * array;*/
 public:
  Matrix();
  ~Matrix();  
  /* Quadratic matrix*/
  /*
  explicit Matrix(size_t);
  Matrix(size_t,size_t);
  Matrix & operator=(const Matrix &);
  std::ostream & operator<<(std::ostream &,const Matrix &);
  std::istream & operator>>(const Matrix &,std::istream &);
  Vector <int> & operator[](const size_t) const;
  const Vector <int> & operator[](const size_t) const;
  const size_t size() const;
  */
  /* Copy constructor */
  //Matrix(const Matrix &);
};
#endif //__MATRIX__
