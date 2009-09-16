#include <iostream>
#include <cstddef>   // för size_t
#include <stdexcept>

class Vector {
  size_t size;
  unsigned int * v1;

public:
  explicit Vector(size_t);

  // Kopieringskonstruktor
  Vector(const Vector &);

  // Överlagrad = operator
  Vector & operator=(const Vector &);

  // Överlagrad [] operator
  unsigned int & operator[](size_t);
  const unsigned int & operator[](size_t i) const;  
};

