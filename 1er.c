#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main (int argc, char *argv[]) {
int num;
pid_t pid;
int padre=getpid();
for (num= 0; num< 3; num++) {
pid= fork();
printf ("Soy el proceso de PID %d y mi padre tiene %d de PID.\n",
getpid(), getppid());
if (pid!= 0) {break;}
srandom(getpid());
sleep (random() %3);
}
if (pid!= 0){printf ("Fin del proceso de PID %d.\n", wait (NULL));}

return 0;
}
