#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}

int *preencheVetor(int intervalo){
    int *vet = (int*) calloc (10, sizeof(int));
    for(int i = 0; i < 10; i++){
        vet[i] = rand() % intervalo;
    }
    imprimeVetor(vet,10);
    return vet;
}

int main(){
    int intervalo=50;
    int *vet = preencheVetor(intervalo);
    return 0;
}