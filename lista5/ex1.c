#include <stdio.h>
#include <stdlib.h>

int *cloneA(int vet[], int tam){
    int *vetor = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetor[i] = vet[i];
    }
    return vetor;
}

void cloneB(int *v, int tam, int *end){
    int *vetorzito = (int*) calloc (tam, sizeof(int));
    
}

int main(){
    int v[5] = {2,4,6,8,10};
    int *copia1, *copia2;
    copia1 = cloneA(v, 5);
    printf("Endereço: [%u]\n", copia1);
    cloneB(v, 5, &copia2);
    return 0;
}

/*Escreva uma função que crie um clone de um determinado vetor. Desenvolva duas versões desta
função:
a) usando a estratégia convencional
b) usando a estratégia do scanf.*/