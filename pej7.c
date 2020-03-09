#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
  int padre=getpid();
  int nivel=0;
  for(int i=0;i<4;i++){
    if(!fork()){
      nivel++;
      if(i==0){
        for(int j=0;j<3;j++){
          if(!fork()){
            nivel++;
            break;
          }
        }
      }
      else if(i==1){
        for(int k=0;k<3;k++){
          if(!fork()){
            nivel++;
            break;
          }
        }
      }
      else if(i==2){
        if(!fork()){
          nivel++;
          break;
        }
      }
      else if(i==3){
        for(int u=0;u<3;u++){
          if(!fork()){
            nivel++;
            if(u==0){
              fork();
              nivel++;
              break;
            }
            else if(u==1){
              for(int p=0;p<2;p++){
                if(!fork()){
                  nivel++;
                  break;
                }
              }
            }
            else if(u==2){
              for(int y=0;y<3;y++){
                if(fork()){
                  nivel++;
                  break;
                }
              }
            }
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
