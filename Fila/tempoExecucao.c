#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include "FilaPrioridadeCircular.h"
// #include "FilaPrioridadeEncadeada.h"
#include "FilaPrioridadeHeap.h"



FilaPrioridade* filaAleatoria(int tam){
    FilaPrioridade* f = fila_criar(tam);
    srand(time(NULL));
    for(int i=0; i<tam; i++){
        fila_inserir(f, rand()%(tam*10));
    }
    return f;
}


int main(){
    int tam = 100000000;

    FilaPrioridade* f = filaAleatoria(tam);

    // int removido;
    // while(fila_tamanho(f) > 0){
    //     fila_remover(f, &removido);
    //     printf("%d ", removido);
    // }
    

}