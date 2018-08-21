#include <iostream>
/*
  Sudoku.cpp
  Este programa se crea una matriz de 9x9 posiciones y la inicializa con una serie
  de numeros para completar el Sudoku.Se realizan validaciones para saber si
  esta correctamente llenada la matriz, checando filas, columnas y cuadrados
  de 3x3.

   Author: JulioGutierrez
    12 de agosto de 2018, 9:00 PM
   version 1.0
*/

using namespace std;


int const iMAXROWS = 9;
int const iMAXCOLUMNS = 9;


bool findNumber(int iNum, int iArr[9]){
  bool auxKey = false;
  for (size_t k = 0; k < 9 && auxKey == false; k++) {
    if(iArr[k] == iNum){
      auxKey = true;
      iArr[k] = 0;
    }
  }
  return auxKey;
}

void SudokuCheck(bool k1,bool k2, bool k3){
  if(k1 && k2 && k3){
    std::cout << "YES"<<endl;
  }else{
    std::cout << "NO"<<endl;
  }
}

void fillArray(int iArr[iMAXROWS]){
  for (size_t i = 1; i < 10; i++) {
    iArr[i-1] = i;
  }
}

int main(int argc, char const *argv[]) {
  int iArr[9] = {1,2,3,4,5,6,7,8,9};
  int iSquareSide = 0,iSquareSide2 = 0;
  int iSum = 0,iMult = 1;
  bool key1 = true,key2 = true,key3 = true;

  int iMat[iMAXROWS][iMAXCOLUMNS];
  for (size_t i = 0; i < 9; i++) {
    for (size_t u = 0; u < 9; u++) {
      cin>>iMat[i][u];
    }
  }
  for (size_t i = 0; i < iMAXROWS && key1 == true; i++) {
    for (size_t j = 0; j < iMAXCOLUMNS; j++) {
      if(!findNumber(iMat[i][j],iArr)){
        key1 = false;
      }
    }
    fillArray(iArr);
  }

  for (size_t i = 0; i < iMAXROWS && key2 == true; i++) {
    for (size_t j = 0; j < iMAXCOLUMNS; j++) {
      if(!findNumber(iMat[j][i],iArr)){
        key2 = false;
      }
    }
    fillArray(iArr);
  }

  do {
    for (size_t h = iSquareSide; h < iSquareSide+3 && key3 == true; h++) {
      for (size_t g = iSquareSide2; g < iSquareSide2+3; g++) {
        if(!findNumber(iMat[h][g],iArr)){
          key3 = false;
        }
      }
      fillArray(iArr);
    }
    iSquareSide += 3;
    if(iSquareSide == 9){
      iSquareSide = 0;
      iSquareSide2 += 3;
    }
  } while(iSquareSide2 != 9);
  SudokuCheck(key1,key2,key3);
  return 0;
}                                                  
