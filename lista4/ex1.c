#include <stdio.h>

void imprimeVetor(int *v, int tam){
    printf("[");
    for(int i = 0; i < tam; i++){
        printf("%d", v[i]);
        if(i < tam-1){
            printf(",");
        }else{
            printf("]\n");
        }
    }
}

int main(){
    int vet[] = {10,20,30};
    int tam = 3;
    imprimeVetor(vet, tam);
    return 0;
}

/*Escreva uma função para imprimir um vetor. A impressão deve ter o seguinte formato:   */