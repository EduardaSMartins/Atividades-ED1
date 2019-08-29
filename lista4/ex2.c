#include <stdio.h>
#include <stdlib.h>

//Função com estratégia convencional
int *criaVetor(int tam, int valor){
    int *v = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        v[i] = valor;
    }
    return v;
}

void criarVetor(int tam, int valor, int *vet){
    vet = (int*) calloc (tam, sizeof(int));
    for(int i = 0; i < tam; i++){
        vet[i] = valor;
    }
}

int main(){
    //Teste 1
    int *vet = criaVetor(5, 0);
    //Teste 2
    criarVetor(10, -1, &vet);
    return 0;
}


/*Escreva uma função para criar um vetor dinamicamente com um determinado tamanho e
preenche‒lo com um determinado valor. Desenvolva duas versões desta função:
a) usando a estratégia convencional
b) usando a estratégia do scanf.*/