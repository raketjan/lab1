/* En härlig vektorklass av Jan Nordberg och Feliz Rios
   Slit den med hälsan...  */

#include "vector.h"
#include <stdexcept>


Vector::Vector(size_t s) : size(s), v1(new unsigned int[s])  {
  for (int i = 0; i<s; ++i) {
    v1[i] = 0;
  }
}

Vector::Vector(const Vector & ref):size(ref.size),v1(new unsigned int[ref.size]){
  for(int i=0;i<ref.size;++i){
    v1[i]=ref[i];
  }
}

Vector & Vector::operator=(const Vector & v2) {
  // ta hand om selfassignment (a = a)
  if (&v2 == this) return *this;

  // fall 1 lika stora
  if (size == v2.size) {  
  for (int i = 0; i < v2.size; ++i) {
    v1[i] = v2[i];
    std::cout << v2[i] << " ";
  }
  std::cout << std::endl;
return *this;
  } else {

    //olika stora, skaffa nytt utrymme
    delete [] v1;
    v1 = new unsigned int[v2.size];
    size = v2.size;
    for (int i = 0; i < v2.size; ++i) {
      v1[i] = v2[i];
  }
    return *this;
}
}


  unsigned  int & Vector::operator[](size_t index) {
  if (index < 0 || index >= size) throw std::out_of_range("out_of_range");
  else return *(v1 + index);
}
 const unsigned  int & Vector::operator[](size_t index) const {
  if (index < 0 || index >= size) throw std::out_of_range("out_of_range");
  else return *(v1 + index);
 }
