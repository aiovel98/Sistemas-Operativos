#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(void){
  printf("ID de proceso: %ld\n", (long)getpid());
  printf("ID dde proceso padre: %ld\n",(long)getppid());
}
