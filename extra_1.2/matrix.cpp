#include "matrix.h"

Matrix::Matrix():cols(0), rows(0), matrix_size(0), matrix(){
  
}

Matrix::Matrix(int r,int c) : cols(c), rows(r), matrix_size(r*c), matrix(r) {
  if(r == 0 ||
     c == 0){
    throw std::out_of_range("bad matrix");
  }

  for(int rr = 0; rr < r; ++rr){
    matrix[rr] = new Vector<int>(c);
  }
}

Matrix::~Matrix(){
  for(size_t i = 0; i < rows; ++i){
    delete matrix[i];
  }
}

Matrix::Matrix(const Matrix & m):cols(m.cols),rows(m.rows),matrix_size(m.matrix_size),matrix(m.rows){
  for(size_t i = 0; i < rows; ++i){
    matrix[i] = new Vector<int>(m[i]);
  }  
}

Matrix & Matrix::operator=(const Matrix & m){
  // problem with x*y matrix
  // delete all that are not used anymore
  
  //Vector<Vector<int> * > * tmp = new Vector<Vector<int> * >(m.rows);
  Matrix * tmp = new Matrix(m);
  
  for(size_t i = 0; i < rows; ++i){  
    delete matrix[i];
  }
  /*
    for(size_t i = 0; i < m.rows; ++i){
    (*tmp)[i] = new Vector<int>(m[i]);
    }
  */
  //matrix = *tmp;
  matrix = tmp->matrix;
  cols=m.cols;
  rows=m.rows;
  matrix_size=m.matrix_size;  
  return *this;
}

Matrix Matrix::T() const{
  Matrix nm(cols,rows); 
  for(size_t i = 0; i < cols; ++i){
    for(size_t j = 0; j < rows; ++j){
      nm[i][j] = (*this)[j][i];
    }
  }
  return nm;
}

void Matrix::id(){
  // Check square matrix
  for(size_t i = 0; i < rows; ++i){
    for(size_t j = 0; j < cols; ++j){
      if(i!=j){
	(*this)[i][j] = 0;
      }else{
	(*this)[i][j] = 1;
      }}}}

size_t Matrix::size() const{
  return matrix_size;
}

Vector <int> & Matrix::operator[](const size_t row) {
  if(row > rows-1 ||
     row < 0){
    throw std::out_of_range("out_of_range []");
  }
  return *(matrix[row]);
}

const Vector <int> & Matrix::operator[](const size_t row) const {
  if(row > rows-1 ||
     row < 0){
    throw std::out_of_range("out_of_range []");
  }
  return *(matrix[row]);
}

Matrix Matrix::operator+(const Matrix & m) const{
  if(m.rows!=rows ||
     m.cols!=cols){
    throw std::out_of_range("dimension not agree");
  }
  
  Matrix tmp_m(*this);
  for (size_t i = 0; i < rows; ++i)  {
    for (size_t j = 0;j < cols; ++j) {
      tmp_m[i][j] += m[i][j];
    }
  }
  return tmp_m;
}

Matrix Matrix::operator-(const Matrix & m) const{
  if(m.rows!=rows ||
     m.cols!=cols){
    throw std::out_of_range("dim not agree");
  }
  return *this + (m*(-1));
}

Matrix Matrix::operator*(const Matrix & m) const{
  if(cols != m.rows){
    throw std::out_of_range("dmi not agree");
  }
  Matrix nm(rows,m.cols);
  // den nya matrisen blir m.rowsXcols stor 
  
  for (size_t i = 0; i < rows; ++i){
    for (size_t j = 0; j < m.cols; ++j){
      int t = 0;
      for (size_t k = 0; k < cols; ++k){
	t+=(*this)[i][k] * m[k][j];
      }
      nm[i][j] = t;
    }
  }
  return nm;
}

Matrix Matrix::operator*(int x) const{
  Matrix tmp_m(*this);
  for (size_t i = 0; i < rows; ++i)  {
    for (size_t j = 0;j < cols; ++j) {
      tmp_m[i][j] *= x;
    }
  }
  return tmp_m;
}


std::ostream & operator<<(std::ostream & os ,const Matrix & m) {
  os << "[ ";
  for (size_t i = 0; i < m.rows; ++i) {
    if (i != 0) os << "; ";
    for (size_t j = 0; j < m.cols; ++j) {
      os << m[i][j] << " ";
    }
    if (i != m.rows-1) os  << std::endl;
  }
  
  os << "]";
  return os;
}

std::istream & operator>>(std::istream & is ,Matrix & m){
    // [ 2 3 4 ; 3 4 6 ]
  
  Vector<int> * v = new Vector<int>;
  // lägg in chars i en Vector
  // sen gör om 
  /*
    while(is.get(c)){
    if(c == ']' || c == ';'){
    m.matrix.push_back(v);
    }
    if(c == ']') break;
    if(c == ';'){
    v = new Vector<int>;
    }
    
    if(c != ' ' && c!= ';' && c!='[' && c!= ']'){
      v->push_back(atoi(&c));
      }    
      }
  */
  
  m.cols = v->size();
  m.rows = m.matrix.size();
  
  return is;
}
