#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main(){

pid_t i=fork();
if(i!=0){
  pid_t j=fork();
  if(j!=0){
    pid_t k;
    for(int u=0;u<3;u++){
      k=fork();
      if(k==0){
        printf("ultimo de los hijos creado %d \n",(int)getpid());
        printf("el padre de este proceso es %d\n",(int)getppid());
        break;
      }
    }
  }else{
    printf("estas en el nivel 2 %d\n",(int)getpid());
    wait(NULL);
  }
}else{
  printf("estas en el nivel 1 %d\n",(int)getpid());
  wait(NULL);
}
  return 0;
}
