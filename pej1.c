#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(int argc, char *argv[]){
  int id;
  int i;
  pid_t padre = getpid();
  pid_t hijos[3];
  /*for(int i=0;i<3;i++){
    pid_t id = fork();
    if(id!=0){
      if(hijos[2]==0){
        hijos[2]=fork();
      }
    }else{
      break;
    }
  }*/
  for(int i=0;i<3;i++){
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
  if(padre==getpid()){

          char b[500];
          sprintf(b,"pstree -lp %d",getpid());
          system(b);
          wait(NULL);
      }else{
          sleep(1);
      }

  return 0;
}
