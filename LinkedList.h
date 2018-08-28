#include "Node.h"
template <class T>
class LinkedList{
public:
  LinkedList();
  ~LinkedList();
  T get(int pos);
  T set(T data, int pos);

  void addFirst(T data);
  void addLast(T data);
  void deleteFirst();
  void deleteLast();
  void del(int pos);
  int  deleteAll();
  bool add(T data, int pos);
  bool change(int pos1,int pos2);
  int getSize();
  void print();

  bool isEmpty();
private:
  Node<T> *head;
  int size;
  void deleteHelper();
};

template <class T>
LinkedList<T>::LinkedList(){
  head = NULL;
  size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
  deleteHelper();
}

template <class T>
bool LinkedList<T>::isEmpty(){
  return (head == NULL);
  //return (head == NULL);
}

template <class T>
void LinkedList<T>::addFirst(T data){
  head = new Node<T>(data, head);
  size++;
}


template <class T>
void LinkedList<T>::addLast(T data){
  if(this->isEmpty()){
    addFirst(data);
  }
  else{
    Node<T> *curr = head;
    while (curr->getNext() != NULL) {
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data));
    size++;
  }

}

template <class T>
void LinkedList<T>::deleteFirst(){
  if(!this->isEmpty()){
    Node<T> *curr = head;
    head = head->getNext();
    delete curr;
    size--;
  }
}
template <class T>
void LinkedList<T>::deleteLast(){
  if(size <= 1){
    deleteFirst();
  }else{
    Node<T> *curr = head;
    while(curr->getNext()->getNext() != NULL){
      curr = curr->getNext();
    }
    delete curr->getNext();
    curr->setNext(NULL);
    size--;
  }

}
template <class T>
int LinkedList<T>::getSize(){
  return size;
}
template <class T>
void LinkedList<T>::deleteHelper(){
  Node<T> *curr = head;
  while (!this->isEmpty()) {
    head = head->getNext();
    delete curr;
    curr = head;
  }
}
template <class T>
void LinkedList<T>::del(int pos){
  if(pos == 0){
    deleteFirst();
  }else if(pos == size-1){
    deleteLast();
  }else{
    Node<T> *curr = head;
    for(int i = 1; i < pos; i++){
      curr = curr->getNext();
    }
    Node<T> *temp = curr->getNext();
    curr->setNext(temp->getNext());
    delete temp;
  }
}
template <class T>
int LinkedList<T>::deleteAll(){
  int cant = size;
  deleteHelper();
  size = 0;
  return cant;
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
  if(pos > size){
    return false;
  }
  if( pos == 0){
    addFirst(data);
  }else if(pos == size){
    addLast(data);
  }else{
    Node<T> *curr = head;
    for(int i = 1; i < pos; i++){
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data, curr->getNext()));
    size++;
  }
  return true;
}

template <class T>
T LinkedList<T>::get(int pos){
    Node<T> *curr = head;
    for (size_t i = 0; i <= pos; i++) {
      curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos){
  if(!isEmpty()){
    Node<T> *curr = head;
    for(int i = 1; i < pos; i++){
      curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
  }
}

template <class T>
bool LinkedList<T>::change(int pos1,int pos2){
  /*
    if(pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size)
    return false
  */
    if(pos1 == pos2){
      return true;
    }
    int posMen = (pos1 < pos2 ? pos1 : pos2);
    int posMay = (pos1 > pos2 ? pos1 : pos2);

    Node<T> *curr1 = head;
    for (size_t i = 0; i < pos1; i++) {
      curr1 = curr1->getNext();
    }
    Node<T> *curr2 = curr1;
    for (size_t j = posMen; j < posMay; j++) {
      curr2 = curr2->getNext();
    }
    T dataAux = curr1->getData();
    curr1->setData(curr2->getData());
    curr2->setData(dataAux);
    return true;
}

template <class T>
void LinkedList<T>::print(){
  Node<T> *curr = head;
  while (curr != NULL) {
    std::cout <<curr->getData()<< '\n';
    curr = curr->getNext();
  }

}
