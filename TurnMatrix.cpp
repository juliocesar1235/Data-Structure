#include <iostream>


using namespace std;

int const iMAXROWS = 4;
int const iMAXCOLUMNS = 4;

void printMatrix(int iNew[iMAXROWS][iMAXCOLUMNS]){
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      cout<<iNew[i][j];
      if(j == 3){
        std::cout <<'\n';
      }else{
        cout<<" ";
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int iSpins = 0;
  int iResiduo = 0;
  int iCounter = 0;
  int iMat[iMAXROWS][iMAXCOLUMNS];
  int iNew[iMAXROWS][iMAXCOLUMNS];
  cin>>iSpins;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      cin>>iMat[i][j];
    }
  }
  if(iSpins >= 0){
    iResiduo = iSpins%4;
  }else if (iSpins > -4){
    iResiduo = iSpins+4;
  }else{
    iResiduo = ((iSpins+4)*-1)%4;
  }
    iCounter = iResiduo;

    if(iResiduo != 0 && iResiduo !=4){
      do {
        for (size_t i = 0; i < 4; i++) {
          for (size_t j = 0; j < 4; j++) {
            iNew[j][3-i] = iMat[i][j];
          }
        }
        for (size_t k = 0; k < 4; k++) {
          for (size_t h = 0; h < 4; h++) {
            iMat[k][h] = iNew[k][h];
          }
        }
        iCounter--;
      } while(iCounter > 0);
    }else{
      for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < 4; j++) {
          iNew[i][j] = iMat[i][j];
        }
      }
    }

    printMatrix(iNew);
  return 0;
}
