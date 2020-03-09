#include<stdio.h>

void funtion();

int main(){
  int i=0;
  funtion(); //2
  funtion(); //3
  funtion(); //3
  printf("va i final: %d",i);
  return 0;
}

void funtion(){
  static int i=1;
  printf("va i: %d ",i);
  i=i+1;
  printf("prueba %d ",i);
}
