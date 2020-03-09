#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

  int padre=getpid();

  for(int i=0;i<3;i++){
    fork();
  }
  if(padre==getpid()){
        char b[500];
        sprintf(b,"pstree -lp %d",getpid());
        system(b);
    }else{
        sleep(1);
    }
  return 0;
}
