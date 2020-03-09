#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

int *vector;
int vector2[5]={0,1,2,8,4};
int *p=&vector2[0];
int n=5;
vector=(int*)calloc(n,sizeof(int));
*(vector)=1;
*(vector+1)=2;
*(vector+2)=3;
*(vector+3)=4;
*(vector+4)=*(vector+3)+1;
for(int i=0;i<n;i++){
  printf("va el vector en la posicion %d %d",i,*(vector+i));
  printf("\n");
}

for(int i=0;i<5;i++){
  printf("va el vector2 %d %d",i,*(p+i));
  printf("\n");
}

return 0;
}
