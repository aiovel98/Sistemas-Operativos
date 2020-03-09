#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int main(){

  int padre=getpid();
  for(int i=0;i<3;i++){
    int pid=fork();
    if(pid==0){
      if(i==0){
        for(int k=0;k<2;k++){
          int pid=fork();
          if(pid!=0){
            break;
          }
        }
      }
      if(i==1){
        int pid=fork();
        if(pid==0) break;
      }
      if(i==2){
        for(int k=0;k<2;k++){
          int pid=fork();
          if(pid!=0){
            break;
          }
        }

      }
      break;
    }
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
