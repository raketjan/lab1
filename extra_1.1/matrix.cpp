#include "matrix.h"

Matrix::Matrix(){
  
}


Matrix::Matrix(int r,int c) : cols(c), rows(r), matrix_size(r*c), matrix(r) {
  for(int rr = 0; rr < r; ++rr){
    matrix[rr] = new Vector<int>(c);
  }
}

Matrix::~Matrix(){
  for(int i = 0; i < rows; ++i){
    delete matrix[i];
  }
}

Matrix::Matrix(const Matrix & m):matrix(m.rows),cols(m.cols),rows(m.rows),matrix_size(m.matrix_size){
  for(int i = 0; i < rows; ++i){
    matrix[i] = new Vector<int>(m[i]);
  }  
}

Matrix & Matrix::operator=(const Matrix & m){
  // problem with x*y matrix
  // delete all that are not used anymore
  Matrix tmp(m);
  for(int i = 0; i < rows; ++i){
    delete matrix[i];
  }
  matrix = tmp.matrix;
  // lägg till med insert kanske
  cols=m.cols;
  rows=m.rows;
  matrix_size=m.matrix_size;
  return *this;
}

Matrix Matrix::T() const{
  Matrix nm(cols,rows); 
  for(int i = 0; i < cols; ++i){
    for(int j = 0; j < rows; ++j){
      nm[i][j] = (*this)[j][i];
    }
  }  
  return nm;
}

void Matrix::id(){
  // Check square matrix
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      if(i!=j){
	(*this)[i][j] = 0;
      }else{
	(*this)[i][j] = 1;
      }
    }
  }
}

size_t Matrix::size() const{
  return matrix_size;
}

Vector <int> & Matrix::operator[](const size_t row) {
  return *(matrix[row]);
}

const Vector <int> & Matrix::operator[](const size_t row) const {
  return *(matrix[row]);
}

Matrix Matrix::operator+(const Matrix & m) const{
  /*
  if(m.rows!=rows) return false;
  if(m.cols!=cols) return false;
  */
  Matrix tmp_m(*this);
  for (int i = 0; i < rows; ++i)  {
    for (int j = 0;j < cols; ++j) {
      tmp_m[i][j] += m[i][j];
    }
  }
  return tmp_m;
}

Matrix Matrix::operator-(const Matrix & m) const{
  /*if(m.rows!=rows) return false;
  if(m.cols!=cols) return false;
  */
  return *this + (m*(-1));
}

Matrix Matrix::operator*(const Matrix & m) const{
  Matrix nm(rows,m.cols);
  // den nya matrisen blir m.rowsXcols stor 
  
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < m.cols; ++j){
      int t = 0;
      for (int k = 0; k < cols; ++k){
	t+=(*this)[i][k] * m[k][j];
      }
      nm[i][j] = t;
    }
  }
  return nm;
}

Matrix Matrix::operator*(int x) const{
  Matrix tmp_m(*this);
  for (int i = 0; i < rows; ++i)  {
    for (int j = 0;j < cols; ++j) {
      tmp_m[i][j] *= x;
    }
  }
  return tmp_m;
}


std::ostream & operator<<(std::ostream & os ,const Matrix & m) {
  os << "[ ";
  for (int i = 0; i < m.rows; ++i) {
    if (i != 0) os << "; ";
    for (int j = 0; j < m.cols; ++j) {
      os << m[i][j] << " ";
    }
    if (i != m.rows-1) os  << std::endl;
  }
  
  os << "]";
  return os;
}

std::istream & operator>>(std::istream & is ,Matrix & m) {
  //std::istream copy(is);
  //while (is){
    
    // hitta antal kolumner
    // hitta antal rader
  //}
  
  //m[i][j]=
  return is;
}

