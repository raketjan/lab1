#include <iostream>
#include <cstddef>   // för size_t


class Vector {
public:
  explicit Vector(size_t s);

  // Kopieringskonstruktor
  Vector(const Vector & ref);

  // Överlagrad = operator
  Vector & operator=(const Vector & v2);  


private:
  int * v;
  size_t size;
}; 
