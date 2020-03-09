#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    FILE * archivo;
    char linea[34];
    archivo=fopen("archivo.txt","r");
    if(archivo==NULL){
      printf("eror al abrir el archivo");
    }else{
      while(fgets(linea,34,archivo)!=NULL){
        printf("%s",linea);
      }
    }
      fclose(archivo);
      //rewind(archivo);
      //printf("\n");
      //while(feof(archivo)==0){
      //  char caracter=fgetc(archivo);
      //  printf("%c",caracter);
      //}

  return  0;
}
