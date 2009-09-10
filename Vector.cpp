/*
 * En härlig vektorklass av Jan Nordberg och Feliz Rios
 * Slit den med hälsan...  
*/

template <class T>
Vector<T>::Vector(size_t s) : size(s), v1(new T[s])  {
  for (int i = 0; i<s; ++i) {
    v1[i] = 0;
  }
}

/* copy constructor */ 
template <class T>
Vector<T>::Vector(const Vector<T> & ref):size(ref.size),v1(new T[ref.size]){
  for(int i=0;i<ref.size;++i){
    v1[i]=ref[i];
  }
}

/* = */
template <class T>
Vector<T> & Vector<T>::operator=(Vector<T> & v2) {
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
    v1 = new T[v2.size];
    size = v2.size;
    for (int i = 0; i < v2.size; ++i) {
      v1[i] = v2[i];
    }
    return *this;
  }
}

template <class T>
T & Vector<T>::operator[](size_t index) {
  if (index < 0 || index >= size) throw std::out_of_range("out_of_range");
  else return *(v1 + index);
}

template <class T>
const T & Vector<T>::operator[](size_t index) const {
  if (index < 0 || index >= size) throw std::out_of_range("out_of_range");
  else return *(v1 + index);
}
