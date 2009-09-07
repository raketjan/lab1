#include <iostream>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[]) {
  std::string s = "world";
  int nr = 1;
  std::cout << "Hello" ;
  if (argc > 1 && std::atoi(argv[1])) {
      nr = std::atoi(argv[1]);
      if (argc > 2) s = argv[2];
  } else if (argc > 1) s = argv[1];
  
      while (nr > 0) {
	std::cout << " " << s; 
	--nr;
      }  
      std::cout << "!" << std::endl;
      return 0; 
}
