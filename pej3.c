#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(int argc, char *argv[]){

  int padre=getpid();
  int i,j,k;

  for(i=0;i<3;i++){
    if(fork()==0){
      if(i==0){
        for(j=0;j<2;j++){
          if(fork()!=0){
            break;
          }
        }
      }
      if(i==1){
        if(fork()==0){
          break;
        }
      }
      if(i==2){
        for(k=0;k<2;k++){
          if(fork()!=0){
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
