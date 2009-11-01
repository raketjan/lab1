Vector<bool>::Vector(void):
  vector_size(0),
  int_array_size(1),
  bool_array_size(sizeof(int)*BYTE_SIZE),
  array(new unsigned int[1])
{
}

Vector<bool>::Vector(size_t s,bool ival):
  vector_size(s),
  int_array_size(ceil(s/(BYTE_SIZE*sizeof(int)))),
  bool_array_size(ceil(s/(BYTE_SIZE*sizeof(int)))*(BYTE_SIZE*sizeof(int)))
{
  
  int a = ceil(s/(BYTE_SIZE*sizeof(int)));
  // kan bli fel om man gör en 0 stor
  array = new unsigned int[a];
  
  for (size_t i = 0; i<int_array_size; ++i) {
    array[i] = 0;
    if(ival){      
      array[i] = ~array[i];
    }
  }  
}


Vector<bool>::Vector(size_t s):
  vector_size(s),
  int_array_size(ceil(s/(BYTE_SIZE*sizeof(int)))),
  bool_array_size(ceil(s/(BYTE_SIZE*sizeof(int)))*(BYTE_SIZE*sizeof(int)))
{
  /* Should be in init list */
  int a = ceil(s/(BYTE_SIZE*sizeof(int)));
  array = new unsigned int[a];
  for (size_t i = 0; i<int_array_size; ++i){
    array[i] = 0;
  }
}

Vector<bool>::~Vector(){
  delete [] array;
}


/* copy constructor */ 

Vector<bool>::Vector(const Vector<bool> & ref):
  vector_size(ref.vector_size),
  int_array_size(ref.int_array_size),
  bool_array_size(ref.bool_array_size),
  array(new unsigned int[ref.int_array_size]){
  
  for(size_t i=0;i<ref.int_array_size;++i){
    array[i]=ref.array[i];
  }
}

/* = */

// Vector<bool> & Vector<bool>::operator=(const Vector<bool> & v2){
//   // ta hand om selfassignment (a = a)
//   if (&v2 == this) return *this;

//   // fall 1 lika stora
//   if (vector_size == v2.vector_size) {
//     for (size_t i = 0; i < v2.vector_size; ++i) {
//       array[i] = v2[i];
//     }
//     return *this;
//   } else {    
//     //olika stora, skaffa nytt utrymme
//     delete [] array;
//     array = new T[v2.vector_size*2];
//     vector_size = v2.vector_size;
//     array_size=vector_size*2;
//     for (size_t i = 0; i < v2.vector_size; ++i) {
//       array[i] = v2[i];
//     }
//     return *this;
//   }
// }


Vector<bool>::reference Vector<bool>::operator[](size_t index) {
  if (index < 0 || index >= vector_size) {
    throw std::out_of_range("out_of_range");
  }else{
    std::cout << "SETTER" << std::endl;   
    //reference * r = new reference();
    reference r;
    r.array_p = array;
    r.int_index = floor((vector_size-1)/(BYTE_SIZE*sizeof(int)));
    r.bit_index = index - r.int_index * BYTE_SIZE*sizeof(int);
    return r;
  }
}

bool Vector<bool>::operator[](size_t index)const{
  if (index < 0 || index >= vector_size){
    throw std::out_of_range("out_of_range");
  }else{
    std::cout << "GETTER " << std::endl;
    int int_index = floor((vector_size-1)/(BYTE_SIZE*sizeof(int)));
    int bit_index = index - int_index * BYTE_SIZE*sizeof(int);
    std::cout << "index " << index << std::endl;
    std::cout << "vector_size " << vector_size << std::endl;
    std::cout << "int_index: " << int_index << std::endl;
    std::cout << "bit_index: " << bit_index << std::endl;
    return ((array[int_index]>>bit_index)&1)&&true;
    
  }
}


Vector<bool>::reference Vector<bool>::front(){
  reference r;
  r.int_index = 0;
  r.bit_index = 0;
  return r;
}

Vector<bool>::reference Vector<bool>::back(){
  reference r;
  return r;
}

/**************** reference *********************/

 
Vector<bool>::reference & Vector<bool>::reference::operator=(const bool b){
  std::cout << "Set to bool " << std::endl;
  std::cout << "int_index: " << int_index << std::endl;
  std::cout << "bit_index: " << bit_index << std::endl;
  int x=1;
  if(b==true){    
    std::cout << "set true " << std::endl;
    x=x<<bit_index;
    array_p[int_index]=array_p[int_index]|x;
  }else{
    std::cout << "set false " << std::endl;
    x=x<<bit_index;
    x=~x;
    array_p[int_index]=array_p[int_index]&x;
  }
  return *this;
}

Vector<bool>::reference & Vector<bool>::reference::operator=(const reference & r){
  std::cout << "Set to reference " << std::endl;
  array_p=r.array_p;
  int_index=r.int_index;
  bit_index=r.bit_index;
  return *this;
}

Vector<bool>::reference::operator bool() const{
  std::cout << "int_index: " << int_index << std::endl;
  std::cout << "bit_index: " << bit_index << std::endl;
  std::cout << "array_p[bit_index]: " << array_p[int_index] << std::endl;
  std::cout << "ret2: " << (((array_p[int_index]>>bit_index)&1) && true) << std::endl;
  return (((array_p[int_index]>>bit_index)&1) && true);
    
}
/*************************************************/

int Vector<bool>::to_int() const{
  int x = 0;
  std::cout << "vector_size: " << vector_size << std::endl;
  if(vector_size > BYTE_SIZE*sizeof(int)){
    return ~x;
  }
  for(size_t i=0;i<vector_size;++i){

    x += (*this)[i]*pow(2,i);
  }
  std::cout << "to_int(): " << x << std::endl;
  return x;
}
const int Vector<bool>::size(void) const{
  return vector_size;
}

Vector<bool> to_vec(int n){
  //kolla hur många bitar
  //Vector<bool> v(8*sizeof(int));
  Vector<bool> v;
  for(size_t i = 0; i < 8*sizeof(int);++i){
    n=n>>i;
    v.push_back((n&1)==1);
  }
  return v;
}

const int Vector<bool>::get_array_size(void) const{
  return int_array_size;
}


void Vector<bool>::push_back(bool element){    

  if(vector_size>=bool_array_size){
    std::cout << "vector_size >= array_size " << std::endl;
    unsigned int * tmp_array; 
    tmp_array = new unsigned int[sizeof(array)*2];
    int_array_size*=2;
    bool_array_size*=2;
    for(size_t i=0;i<int_array_size;++i){
      tmp_array[i]=array[i];
    }
   
    delete [] array;
    array = tmp_array;
  }

  std::cout << " array[vector_size] = element; " << std::endl;
  /********** shift **********/
  //feeeel
  int index = vector_size;
  int int_index = floor((vector_size)/(BYTE_SIZE*sizeof(int))); 
  int bit_index = index - int_index * BYTE_SIZE*sizeof(int);
  
  std::cout << "vector_size " << vector_size << std::endl;
  std::cout << "int_array_size " << int_array_size << std::endl;
  std::cout << "bool_array_size " << bool_array_size << std::endl;
  std::cout << "int_index " << int_index << std::endl;
  std::cout << "bit_index " << bit_index << std::endl;
  int x=1;
  if(element==true){    
    std::cout << "set true " << std::endl;
    x=x<<bit_index;
    array[int_index]=array[int_index]|x;
  }else{
    std::cout << "set false " << std::endl;
    x=x<<bit_index;
    x=~x;
    array[int_index]=array[int_index]&x;
  }
  
  /***************************/
    //array[vector_size] = element;

  ++vector_size;
  return;
}

void Vector<bool>::clear(void){  
  delete [] array;
  array = new unsigned int[1];
  int_array_size=1;
  bool_array_size=BYTE_SIZE*sizeof(int);
  vector_size=0;
}


// void Vector<bool>::sort(bool ascending = true){
//   bool temp;
//   if(ascending){
//     for(size_t j=1;j<vector_size;++j){
//       for(size_t k=0;k<j;k++){
// 	if(array[j] < array[k]){
// 	  temp = array[k];
// 	  array[k] = array[j];
// 	  array[j] = temp;
// 	}
//       }
//     }  
//   }else if(!ascending){
//     for(size_t j=1;j<vector_size;++j){
//       for(size_t k=0;k<j;k++){
// 	if(array[k] < array[j]){
// 	  temp = array[k];
// 	  array[k] = array[j];
// 	  array[j] = temp;
// 	}
//       }
//     }
//   } 
// }
  

