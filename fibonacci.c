#include<stdio.h>
#include<stdlib.h>


int main(){
  int anterior;
  int Aanterior;
  int actual;
  for(int i=0;i<8;i++){
    if(i==0){
      anterior=0;
      Aanterior=0;
      actual=0;
      printf("%d",actual);
    }else if(i==1){
      Aanterior=0;
      anterior=0;
      actual=1;
      printf("%d",actual);
      Aanterior=anterior;
      anterior=actual;
    }else{
      actual=anterior+Aanterior;
      printf("%d",actual);
      Aanterior=anterior;
      anterior=actual;

    }
  }
  return 0;
}
