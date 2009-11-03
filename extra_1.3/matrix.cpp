#include "matrix.h"

Matrix::Matrix(){
  
}


Matrix::Matrix(int r,int c) : cols(c), rows(r), matrix_size(r*c), matrix(r) {
   for(int rr = 0; rr < r; ++rr){
    matrix[rr] = new Vector<int>(c);
  }
 
}

Matrix::~Matrix(){

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

