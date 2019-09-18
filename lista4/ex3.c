#include <stdio.h>

int indice(int *vet, int tam){
    int maior=-1000;
    int maiorIndice;
    for(int i = 0; i < tam; i++){
        if(vet[i] >= maior){
            maiorIndice = i;
            maior = vet[i];
        }
    }
    return maiorIndice;
}

int main(){
    int tam=5;
    int vet[]={10,20,100,40,50};
    int indiceMaior = (vet,tam);
    printf("Índice do maior valor do vetor: %d\n", indiceMaior);
    return 0;
}