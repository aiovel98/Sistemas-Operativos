#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>


int main(void){

  int id;
  int i;
  pid_t padre=getpid();
  for(i=0;i<3;i++){
    id=fork();
    if(id==0){
      printf("eres el hijo %d\n",getpid());
      printf("tu papa es %d\n ",getppid());
      break;
    }else{
      printf("eres el padre tu id es: %d\n",getpid());
      wait(NULL);
    }
  }
  printf("prueba");
}
