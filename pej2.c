
/*         hijo     nieto ---bisnieto ---trinieto
          /       /
    padre-------hijo
         \        \
          hijo      nieto
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
  int padre=getpid();
  int i,j,k;
  for(i=0;i<3;i++){
    if(fork()==0){
      if(i==1){
        for(j=0;j<2;j++){
          if(fork()==0){
            if(j==1){
              for(k=0;k<2;k++){
                if(fork()!=0){
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
