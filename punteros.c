#include<stdio.h>

int main(){
int i=5;

int *p=&i;

printf(" va *p : %d",*p); // valor al que apunta p
printf(" va &p : %p",&p); // direccion de memoria a la que apunta p

  return 0;
}
