#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdio.h>

int totalNumeros(char *); //Devuelve el total de numeros del archivo
void llenarVector(char *); //Llena el vector con los numeros del archivo
void llenarArchivo(char *, int); //Llena el archivo llamado "out.txt"
void error(char *); //Funcion del error
int leerTotal(); //Devuelve el total calculado por los 2 procesos hijos
int *vector; //Vector que contendrá los numeros
int cantidadNumeros; 
int main(){
    pid_t root = getpid();
    remove("out.txt");
    cantidadNumeros = totalNumeros("input.txt");
    int i, sw=cantidadNumeros/2; //Aquí divido la carga entre los 2 hijos
    llenarVector("input.txt");
    for(i=0; i<2; i++){ //Creo los hijos
        if(!fork()){
            break;
        }
    }
    if(root!=getpid()){ //Si son los hijos
        if (i==0){ //Primer hijo
            int numero = 0;
            for (int k = 0; k < sw; k++){ //Se ocupará de la primera mitad
                numero = numero + (int)vector[k];
            }
            llenarArchivo("out.txt", numero);
        }else{ //Segundo hijo
            int numero2 = 0;
            for (int k = sw; k < cantidadNumeros; k++){ //Se ocupará de la segunda mitad
                numero2 = numero2 + (int)vector[k];
            }
            llenarArchivo("out.txt", numero2); //Guardará el resultado de la suma en el archivo "out.txt"
        }
    }else{ //Si es el padre
        for (int k = 0; k < 2; k++){ //Espera a que acaben los hijos para proceder a mostrar el total
            wait(NULL);
        }
        
        printf("\nLa sumatoria total es:%d\n",leerTotal()); //Muestra el total
    }

    return EXIT_SUCCESS;
}

int totalNumeros(char *filename){
    int c, numero;
    FILE *infile;
    infile = fopen(filename, "r");
    if(! infile ){ 
        error("Error fopen\n");
    }
    fscanf(infile, "%d", &c);
    fclose(infile);
    return c;
}

void llenarVector(char *filename){
    int i, numero, c;
    FILE *infile;
    infile = fopen(filename, "r");
    if(! infile ){ 
        error("Error fopen\n");
    }
    fscanf(infile, "%d", &c);
    vector = malloc(sizeof(int));
    printf("El vector con el contenido del archivo es:\n");
    for(i=0;i<c; i++){
        fscanf(infile, "%d", &numero);
        vector[i] = numero;
        printf("%d\n", vector[i]);
    }
    fclose(infile);
}

void llenarArchivo(char *filename, int n){
    FILE *archivo;
    archivo = fopen(filename, "a");
    fprintf(archivo, "%d\n", n);
    fclose(archivo);
}

int leerTotal(){
    FILE *infile;
    int sumap1=0,sumap2=0,total=0;
    infile = fopen("out.txt","r");
    if(!infile){
        error("Error padre archivo resultados");
    }
    fscanf(infile,"%d", &sumap1);
    fscanf(infile,"%d", &sumap2);
    total = sumap1 + sumap2;
    return total;

}

void error(char *msg){ 
    perror(msg); 
    exit(-1); 
}
        