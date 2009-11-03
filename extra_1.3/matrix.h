#ifndef _MAT_
#define _MAT__
#include <iostream>
#include <cstddef>
#include <stdlib.h>
#include "vector.h"

class Matrix{
  friend std::ostream & operator<<(std::ostream &,const Matrix &); 
  friend std::istream & operator>>(const Matrix &,std::istream &);
  size_t cols;
  size_t rows;
  size_t matrix_size;
  Vector< Vector <int>  * > matrix;
 public:
  Matrix();
  
  Matrix(int, int);
  ~Matrix();  
  /* Quadratic matrix*/
  /*
  explicit Matrix(size_t)  Matrix(size_t,size_t);
  Matrix & operator=(const Matrix &);


  */
  Vector <int> & operator[](const size_t);
  const Vector <int> & operator[](const size_t) const;
  size_t size() const;
  
  /* Copy constructor */
  //Matrix(const Matrix &);
};
  std::istream & operator>>(const Matrix &,std::istream &);
  std::ostream & operator<<(std::ostream &,const Matrix &);
#endif //_MAT_
