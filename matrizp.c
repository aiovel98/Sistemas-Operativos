#include<stdio.h>
#include<stdlib.h>

void prueba(int **m );

int main(){

int ** matriz;
matriz=(int **)calloc(3,sizeof(int*));
for(int i=0;i<3;i++) matriz[i]=(int*)calloc(3,sizeof(int));
for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		matriz[i][j]=2;
	}
}
prueba(matriz);

return 0;
}

void prueba(int **m ){

     for(int i=0;i<3;i++){
	for(int j=0;j<3;j++){
		printf("%d",m[i][j]);
	}
	printf("\n");
     }

}
