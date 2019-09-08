#include <stdio.h>
#include <stdlib.h>

int *vetorCloneA(int vetor[], int tam){
    int *vet = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vet[i] = rand() % 50;
    }
    return vet;
}

void imprimir(int *end, int tam){
    for(int i = 0; i < tam; i++){
        printf("v[%d] = %d\n", i,end[i]);
    }
}

int main(){
    int tam=10;
    int vet[tam];
    int *end = vetorCloneA(vet, tam);
    imprimir(end, tam);
    return 0;
}
/*Escreva uma função que crie um vetor preenchido com valores aleatórios.*/