#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(){
    pid_t padre = getpid();
    for (int i = 0; i < 4; i++){
        if (!fork()){
            if (i==2){
                for (int k = 0; k < 2; k++)
                {
                    if (!fork())
                    {
                        if (k==1)
                        {
                            for (int j = 0; j < 2; j++)
                            {
                                if (!fork())
                                {
                                    break;
                                }
                                
                            }
                            
                        }
                        break;
                        
                    }
                    
                }
                
            }

            if (i==3){
                fork();
                break;
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