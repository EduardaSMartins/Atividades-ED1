#include <stdio.h>

void imprimeVetor(int vet[], int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ",vet[i]);
    }
    printf("\n");
}

int *incrementa(int *vet, int tam){
    for(int i = 0; i < tam; i++){
        vet[i]++;
    }
    return vet;
}

int main(){
    int tam=10;
    int vet[] = {5,10,15,20,25,30,35,40,45,50};
    int *vetor = incrementa(&vet,tam);
    imprimeVetor(vetor,tam);
    return 0;
}