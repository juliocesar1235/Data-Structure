template <class T>
class Lista{
  public:
    Lista();
    Lista(const Lista &list1);
    int getCant();
    T getDato(int pos);
    bool add(T data);
    int search(T data);
    void sort(bool order);
    void print();
    friend bool operator==(Lista list1, Lista list2){
      if(list1.getCant() == list2.getCant()){
        for(int i = 0; i < list2.getCant(); i++){
          if(list1.getDato(i) != list2.getDato(i)){
            return false;
          }
        }
        return true;
      }else{
        return false;
      }
    }
      void operator=(Lista list2){
       this->iCant = list2->getCant();
       for (size_t j = 0; j < this->iCant; j++) {
         this->arrDatos[j] = list2->getDato(j);
       }
      }
  private:
    T arrDatos[10];
    int iCant;
    void BubbleSort(T arrDatos[], int iCant, bool order);
    int BusquedaBinaria(T arrDatos[],T data);
};

template <class T>
Lista<T>::Lista(){
  iCant = 0;
}

template <class T>
Lista<T>::Lista(const Lista &list1){
  iCant = list1.iCant;
  for (size_t i = 0; i < iCant; i++) {
    arrDatos[i] = list1.arrDatos[i];
  }
}

template <class T>
int Lista<T>::getCant(){
  return iCant;
}

template <class T>
T Lista<T>::getDato(int pos){
  if(pos >= 0 && pos < iCant){
    return arrDatos[pos];
  }
}

template <class T>
bool Lista<T>::add(T data){
  if(iCant <= 10){
    arrDatos[iCant] = data;
    iCant++;
    return true;
  }else{
    return false;
  }
}

template <class T>
int Lista<T>::BusquedaBinaria(T arrDatos[],T data){
  int central, bajo, alto, n;
  T valorCentral;
  bajo = 0;
  n = this->iCant;
  alto = n-1;
  while (bajo <= alto) {
    central = (bajo+alto)/2;
    valorCentral = arrDatos[central];
    if(data == valorCentral){
      return central;
    }else if(data < valorCentral){
      alto = central - 1;
    }else{
      bajo = central + 1;
    }
  }
  return -1;
}

template <class T>
int Lista<T>::search(T data){
  sort(true);
  return BusquedaBinaria(arrDatos,data);
}

template <class T>
void Lista<T>::BubbleSort(T arrDatos[], int iCant, bool order){
  bool interruptor = true;
  T temp;
  if(order){
    for(int pasada = 0; pasada < iCant-1 && interruptor; pasada++){
      interruptor = false;
      for (size_t j = 0; j < iCant-1-pasada; j++) {
        if(arrDatos[j+1] < arrDatos[j]){
          temp = arrDatos[j];
          arrDatos[j] = arrDatos[j+1];
          arrDatos[j+1] = temp;
          interruptor = true;
        }
      }
    }
  }else{
    for(int pasada = 0; pasada < iCant-1 && interruptor; pasada++){
      interruptor = false;
      for (size_t j = 0; j < iCant-1-pasada; j++) {
        if(arrDatos[j+1] > arrDatos[j]){
          temp = arrDatos[j];
          arrDatos[j] = arrDatos[j+1];
          arrDatos[j+1] = temp;
          interruptor = true;
        }
      }
    }
  }
}

template <class T>
void Lista<T>::sort(bool order){
  BubbleSort(arrDatos,iCant,order);
}

template <class T>
void Lista<T>::print(){
  for (size_t i = 0; i < this->iCant; i++) {
    std::cout << i <<"-"<<this->arrDatos[i]<<'\n';
  }
}
