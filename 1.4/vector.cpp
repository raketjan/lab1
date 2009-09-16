/* En härlig vektorklass av Jan Nordberg och Feliz Rios
   Slit den med hälsan...  */

#include "vector.h"

Vector::~Vector(){
  delete [] v1;
}

Vector::Vector(size_t s) : vector_size(s), v1(new unsigned int[s])  {
  for (int i = 0; i<s; ++i) {
    v1[i] = 0;
  }
}

Vector::Vector(const Vector & ref):vector_size(ref.vector_size),v1(new unsigned int[ref.vector_size]){
  for(int i=0;i<ref.vector_size;++i){
    v1[i]=ref[i];
  }
}

Vector & Vector::operator=(const Vector & v2) {
  // ta hand om selfassignment (a = a)
  if (&v2 == this) return *this;

  // fall 1 lika stora
  if (vector_size == v2.vector_size) {  
    for (int i = 0; i < v2.vector_size; ++i) {
      v1[i] = v2[i];
  }
    return *this;
  } else {
    
    //olika stora, skaffa nytt utrymme
    delete [] v1;
    v1 = new unsigned int[v2.vector_size];
    vector_size = v2.vector_size;
    for (int i = 0; i < v2.vector_size; ++i) {
      v1[i] = v2[i];
    }
    return *this;
  }
}

unsigned  int & Vector::operator[](size_t index) {
  if (index < 0 || index >= vector_size) throw std::out_of_range("out_of_range");
  else return v1[index];
}

const unsigned  int & Vector::operator[](size_t index) const {
  if (index < 0 || index >= vector_size) throw std::out_of_range("out_of_range");
  else return v1[index];
}

const size_t Vector::size() const{
  return vector_size;
}
