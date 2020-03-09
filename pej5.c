#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

  int padre=getpid();
  int i,k;
  pid_t hijos[3]={};
  for(i=0;i<3;i++){
    hijos[i]=fork();
    if(hijos[i]==0){
      hijos[0]=fork();
      if(i==1&&hijos[0]==0){
        for(k=0;k<2;k++){
          hijos[k]=fork();
          if(hijos[k]==0){break;}
        }
        break;
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
