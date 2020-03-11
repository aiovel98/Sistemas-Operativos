#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t padre = getpid();
    int N;
    printf("Escriba el numero:");
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        if (!fork()){
            for(int k=0; k<i+1; k++){
                if(!fork()){
                    break;
                }
            }
        break;
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
    

    return EXIT_SUCCESS;

}
