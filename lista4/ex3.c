#include <stdio.h>
#include <stdlib.h>

int *criaVetor(int tam, int valor){
    int *v = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        v[i] = valor;
    }
    return v;
}

void preencheVetor(int *v, int tam){
    int valor=10;
    for(int i = 0; i < tam; i++){
        v[i] = valor;
        valor+=10;
    }
}

int devolveIndice(int *v, int tam){
    int valor=-10000, indice=0;
    for(int i = 0; i < tam; i++){
        if(v[i] > valor){
            valor = v[i];
            indice = i;
        }
    }
    return indice;
}

int main(){
    int tam=5;
    int *vet;
    vet = criaVetor(tam, 0);
    preencheVetor(vet, tam);
    printf("Índice do maior valor do vetor: %d\n", devolveIndice(vet,tam));
    return 0;
}

/*Escreva uma função que devolva o índice do maior elemento de um vetor.*/