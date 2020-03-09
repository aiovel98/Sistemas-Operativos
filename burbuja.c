#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(){
  int *vector;
  vector=(int*)calloc(6,sizeof(int));
  *(vector)=50;
  *(vector+1)=10;
  *(vector+2)=36;
  *(vector+3)=82;
  *(vector+4)=5;
  *(vector+5)=40;
  for(int i=0;i<5;i++){
    for(int j=i+1;j<6;j++){
      if(*(vector+i)>*(vector+j)){
        int aux=*(vector+j);
        *(vector+j)=*(vector+i);
        *(vector+i)=aux;
      }
    }
  }

  for(int i=0;i<6;i++){
    printf("[%d]",*(vector+i));
    printf("\n");
  }
  return 0;
}
