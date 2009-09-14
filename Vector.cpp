/*
 * En härlig vektorklass av Jan Nordberg och Feliz Rios
 * Slit den med hälsan...  
*/

/* Default */
template <class T>
Vector<T>::Vector():vector_size(0),array_size(8),array(new T[8]){
}

template <class T>
Vector<T>::Vector(size_t s,T ival) : vector_size(s),array_size(s*2), array(new T[s*2]) {
  for (int i = 0; i<s; ++i) {
    array[i] = T(ival);
  }
}

template <class T>
Vector<T>::Vector(size_t s) : vector_size(s),array_size(s*2), array(new T[s]) {
  for (int i = 0; i<s; ++i) {
    array[i] = T();
  }
}

/* copy constructor */ 
template <class T>
Vector<T>::Vector(const Vector<T> & ref):vector_size(ref.vector_size),array_size(ref.array_size),array(new T[ref.array_size]){
  for(int i=0;i<ref.vector_size;++i){
    array[i]=ref[i];
  }
}

/* = */
template <class T>
Vector<T> & Vector<T>::operator=(Vector<T> & v2) {
  // ta hand om selfassignment (a = a)
  if (&v2 == this) return *this;

  // fall 1 lika stora
  if (vector_size == v2.vector_size) {
    for (int i = 0; i < v2.vector_size; ++i) {
      array[i] = v2[i];
      std::cout << v2[i] << " ";
    }
    std::cout << std::endl;
    return *this;
  } else {
    
    //olika stora, skaffa nytt utrymme
    delete [] array;
    array = new T[v2.vector_size*2];
    vector_size = v2.vector_size;
    array_size=vector_size*2;
    for (int i = 0; i < v2.vector_size; ++i) {
      array[i] = v2[i];
    }
    return *this;
  }
}

template <class T>
T & Vector<T>::operator[](size_t index) {
  if (index < 0 || index >= vector_size) throw std::out_of_range("out_of_range");
  else return *(array + index);
}

template <class T>
const T & Vector<T>::operator[](size_t index) const {
  if (index < 0 || index >= vector_size) throw std::out_of_range("out_of_range");
  else return *(array + index);
}

template <class T>
const int Vector<T>::size(void) const{
  return vector_size;
}

template <class T>
const int Vector<T>::get_array_size(void) const{
  return array_size;
}

template <class T>
void Vector<T>::enlargeArray(void){
  
  T *tmp_vec = new T[array_size*2];
  
  for(int i=0; i<vector_size; ++i){
    tmp_vec[i]=array[i];
  }
  delete [] array;
  array=tmp_vec;
  array_size*=2;
}

template <class T>
void Vector<T>::push_back(T element){
  if(vector_size>=array_size){
    enlargeArray();
  }
  
  array[vector_size]=element;
  vector_size++;
    
}

template <class T>
void Vector<T>::insert(size_t index,T element){
  T * tmp_array;
  if(vector_size>=array_size){ 
    tmp_array = new T[array_size*2];
    array_size*=2;
  }else{
    tmp_array = new T[array_size];
  }
  

  for(int i=0;i<index;++i){
    tmp_array[i]=array[i]; 
  }
  
  tmp_array[index]=element;
  for(int i=index;i<vector_size;++i){
    tmp_array[i+1]=array[i]; 
  }

  delete [] array;
  array = tmp_array;
  vector_size++;
}

template <class T>
void Vector<T>::erase(size_t index){
  if(index<0 || index>=vector_size){
    return;
  }
  for(int i = index+1;i<vector_size-1;i++){
    array[i]=array[i+1];
  }
  // Not needed
  array[vector_size]=T();
  vector_size--;
}

template <class T>
void Vector<T>::clear(void){
  vector_size=0;
}

template <class T>
void Vector<T>::sort(bool ascending = true){
  std::sort(array, array+vector_size);
  T * tmp;
  if(!ascending){    
    tmp = new T[array_size];
    for(int i = 0;i<vector_size; i++){
      tmp[vector_size-i-1]=array[i];
    }
    delete [] array;
    array=tmp;
  }
}

