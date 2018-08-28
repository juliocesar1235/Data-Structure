#include <iostream>
using namespace std;
#include "LinkedList.h"

int main(int argc, char const *argv[]) {
  LinkedList<string> miLista;

  miLista.addLast("KEVIN");
  miLista.addFirst("LLEGA");
  miLista.add("TARDE",1);
  miLista.addLast("SIEMPRE");
  /*for (size_t i = 0; i < miLista.getSize(); i++) {
    std::cout << miLista.get(i) << '\n';
  }
  std::cout<< '\n';*/
  miLista.print();
//miLista.deleteFirst();
  //miLista.print();
  //miLista.deleteLast();
  //miLista.print();
  //miLista.del(2);
  //miLista.deleteAll();
  //miLista.print();
  //miLista.addFirst("HOLA");
  //miLista.print();
  std::cout << miLista.set("TEMPRANO",1) << '\n';
  miLista.print();
  miLista.change(1,2);
  miLista.print();

  LinkedList<int> *tuLista = new LinkedList<int>();
  tuLista->addFirst(100);
  tuLista->addFirst(40);
  tuLista->addLast(30);
  tuLista->print();
  delete tuLista;
  return 0;
}
