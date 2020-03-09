#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *agrv[]){
  FILE * archivo;
  int n;
  printf("ingrese numero: ");
  scanf("%d",&n);
  archivo=fopen("triangulos.txt","a");
  for(int i=1;i<=n;i++){
    int mitad=(1+(n+n-1))/2;
    for(int j=1;j<=(n+n-1);j++){
      if(i==1){
        if(j==mitad){
          fprintf(archivo,"*");
        }else{
          fprintf(archivo," ");
        }
      }else if(i!=n){
        if(j==mitad-i){
          fprintf(archivo,"*");
        }else if(j==mitad+i){
          fprintf(archivo,"*");
        }else{
          fprintf(archivo," ");
        }
      }else{
        fprintf(archivo,"*");
      }
    }
    fprintf(archivo,"\n");
  }
  return 0;
}
