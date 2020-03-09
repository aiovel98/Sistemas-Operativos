#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<string.h>
void leer1(FILE *archivo, char *vector);

void leer2(FILE *archivo, char *vector);

void leer3(FILE *archivo, char *vector);

void leer4(FILE *archivo, char*vector);

void escribir1(FILE *archivo);

void escribir2(FILE *archivo);

void escribir3(FILE *archivo);

void escribir4(FILE *archivo);

int main(){
  char vector[100];
  FILE *archivo;
  archivo=fopen("archivo2.txt","r");
  //archivo=fopen("archivo3.txt","w");
  //escribir4(archivo);
  leer1(archivo,vector);
  fclose(archivo);
  return 0;
}

void escribir1(FILE *archivo){
  fputc('a',archivo);
}

void escribir2(FILE *archivo){
  fputs("hola de nuevo",archivo);
}

void escribir3(FILE *archivo){
  fwrite("cadena de prueba\n",sizeof(char),sizeof("cadena de prueba\n"),archivo);
}

void escribir4(FILE *archivo){
  fprintf(archivo,"otra cadena");
}

void leer4(FILE *archivo, char*vector){
  while(feof(archivo)==0){
    if(fgets(vector,100,archivo)!=NULL){
      printf("%s\n",vector);
    }
  }
}

void leer3(FILE *archivo, char*vector){
  while(feof(archivo)==0){
    fread(vector,sizeof(char),50,archivo);
    printf("%s\n",vector);
  }
}

void leer2(FILE *archivo, char *vector){
   while(feof(archivo)==0){
     fscanf(archivo,"%s",vector);
     printf("%s\n",vector);
   }
 }

void leer1(FILE *archivo, char *vector){
   int i=0;
   while(feof(archivo)==0){
     vector[i]=fgetc(archivo);
     i++;
   }
    i=0;
   while(i<strlen(vector)){
     if(vector[i]>=65 && vector[i]<=122){printf("%c",vector[i]);}
     i++;
   }
 }
