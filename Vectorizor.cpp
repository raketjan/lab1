#include "Vector.h"

int main() {
  Vector<int> vec1(3), vec2(5);
  Vector<const char *> vecs(3);
  vecs[0]="hej";
  std::cout << "vecs[0] " << vecs[0] << std::endl;
  
  vec1[1] = 17;

  vec2[0] = 3; 
  vec2[4] = 5;

  std::cout << "vec1 ska vara 0 17 0 " << std::endl;
  std::cout << "vec2 ska vara 3 0 0 0 5" << std::endl;
  std::cout << "vec1: " << vec1[0] << " " << vec1[1] << " " << vec1[2] << std::endl;
  std::cout << "vec2: " << vec2[0] << " " << vec2[1] << " " << vec2[2] << " " <<  vec2[3] << " " << vec2[4]<< std::endl;  
  std::cout << "vec1=vec2" << std::endl; 
  vec1=vec2;
  std::cout << "vec1 ska vara 3 0 0 0 5" << std::endl;
  std::cout << "vec1: " << vec1[0] << " " << vec1[1] << " " << vec1[2] << " " << vec1[3] << " " << vec1[4] << std::endl;

  vec2[2] = 8;
  std::cout << "vec2 ska vara 3 0 8 0 5" << std::endl;
  std::cout << "vec2: " << vec2[0] << " " << vec2[1] << " " << vec2[2] << " " <<  vec2[3] << " " << vec2[4]<< std::endl;


  

  Vector<int> vec3(vec1);
  vec3[0]=333;
  std::cout << vec1[0] << vec3[0] << " " << vec1[2] << vec3[2] << std::endl;
  return 0;
}
