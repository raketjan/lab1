#include <iostream>

class A {
public:
  A()
  {std::cout << " Default konstruktör !" << std::endl; }
  A(const A & ref)
  {std::cout << " Copy constructor !" << std::endl; }
  ~A()
  {std::cout << " Destructor !" << std::endl; }
  A(char * s)
  {std::cout << " tar en sträng !" << s << std::endl; }
  A & operator=(const A & s)
  {std::cout << " överlagrad = !" << std::endl;
    return *this;}
};

void no_ref(A a) {}
void with_ref(const A &a) {}

int main()
{
  A a("my name is a");
    A b = a;                 // vad är  skillnaden
    A c(a);                  // mellan dessa
    A d;                     // tre tekniker
    
  d = a;
 
  A *aa = new A[5];
  delete [] aa ;               // Vad kommer att hända ?
  
  no_ref(a);               // Bildas temporära objekt ?
  with_ref(a);             // Bildas temporära objekt ?
  
  return 0;
}
