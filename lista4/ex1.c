#include <stdio.h>
#include <stdlib.h>

int *cloneA(int vetor[], int tam){
    int *vet = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vet[i] = vetor[i];
    }
    return vetor;
}

void cloneB(int *v, int tam){
    int *vetorzito = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vetorzito[i] = v[i];
    }
}

int main(){
    int v[5] = {2,4,6,8,10};
    int *copia1, *copia2;
    copia1 = cloneA(v, 5);
    printf("Endereço clone A: [%ls]\n", copia1);
    cloneB(v, 5);
    return 0;
}

/*Escreva uma função que crie um clone de um determinado vetor. Desenvolva duas versões desta
função:
a) usando a estratégia convencional
b) usando a estratégia do scanf.*/