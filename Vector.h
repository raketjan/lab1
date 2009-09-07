#include <iostream>
#include <cstddef>   // för size_t



class Vector {
  size_t size;
 unsigned int * v1;

public:
  explicit Vector(size_t s);

  // Kopieringskonstruktor
  Vector(const Vector & ref);

  // Överlagrad = operator
  Vector & operator=( Vector & v2);

  // Överlagrad [] operator
  unsigned int & operator[](size_t i);
  const unsigned int & operator[](size_t i) const;  
}; 
