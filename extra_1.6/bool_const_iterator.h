// iterator example
#include <iostream>
#include <iterator>
using namespace std;


template <class T>
struct iterator_traits {
  //typedef typename T::iterator_category     iterator_category;
  typedef bool            value_type;
  //typedef typename T::difference_type       difference_type;
  // typedef typename T::pointer               pointer;
  //typedef typename T::reference             reference;
};


