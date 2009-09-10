/* En härlig vektorklass av Jan Nordberg och Feliz Rios
   Slit den med hälsan...  */

#include "Vector.h"
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

Vector & Vector::operator=(Vector & v2) {
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




int main() {
  Vector vec1(3), vec2(5);

  std::cout << "Gör en vector med 3 element !" << std::endl;
  vec1[1] = 17;
  vec2[0] = 3; 
  vec2[4] = 5;
  std::cout << vec1[0] << " " << vec1[1] << " " << vec1[2] << std::endl;
  vec2 = vec1;
  vec2[2] = 17272;
  std::cout << vec2[0] << " " << vec2[1] << " " << vec2[2] << " ";//  vec2[3] << " " << vec2[4]<< std::endl;

  std::cout << vec1[0] << " " << vec1[1] << " " << vec1[2] << std::endl;

  Vector vec3(vec1);
  vec3[0]=333;
  std::cout << vec1[0] << vec3[0] << " " << vec1[2] << vec3[2] << std::endl;
  
}; 
