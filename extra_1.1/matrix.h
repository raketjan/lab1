#ifndef _MAT_
#define _MAT__
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include <iterator>
#include "vector.h"
#include <sstream>
class Matrix{
  friend std::ostream & operator<<(std::ostream &,const Matrix &); 
  friend std::istream & operator>>(const Matrix &,std::istream &);
 public:
  size_t cols;
  size_t rows; 
  size_t matrix_size;
  Vector< Vector <int>  * > matrix;
  Matrix();
  Matrix(const Matrix &);
  Matrix(int, int);
  ~Matrix();
  Matrix & operator=(const Matrix & m);
  Matrix operator+(const Matrix &)  const;
  Matrix operator-(const Matrix &) const;
  Matrix operator*(const Matrix &) const;
  Matrix operator*(int) const;
  /* Quadratic matrix*/
  /*
  explicit Matrix(size_t)  Matrix(size_t,size_t);
  */
  Vector <int> & operator[](const size_t);
  const Vector <int> & operator[](const size_t) const;
  size_t size() const;
  void id();
  Matrix T() const;
};
  std::istream & operator>>(const Matrix &,std::istream &);
  std::ostream & operator<<(std::ostream &,const Matrix &);
#endif //_MAT_
