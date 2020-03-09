/*
           nieto
         /
      hijo -- nieto
      /
    /
padre---hijo
  \
   \    nieto
    \   /
      hijo---nieto
      \
        nieto
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

  int i,k,j;
  pid_t childs[3];
  int padre=getpid();

  for(i=0;i<3;i++){
    childs[i]=fork();
    if(childs[i]==0){
      if(i==0){
        for(k=0;k<2;k++){
          childs[k]=fork();
          if(childs[k]==0){break;}
        }
    }else if(i==2){
      for(j=0;j<3;j++){
        childs[j]=fork();
        if(childs[j]==0){break;}
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
