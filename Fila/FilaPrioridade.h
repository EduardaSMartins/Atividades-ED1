#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{False=0, True=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;    
}FilaPrioridade;

//PROTÓTIPOS DAS FUNÇÕES
FilaPrioridade* fila_criar();
void fila_destruir(FilaPrioridade* f);

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento);
Tipo fila_remover1(FilaPrioridade* f);
Boolean fila_remover2(FilaPrioridade* f, Tipo* endereco);

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco);
int fila_tamanho(FilaPrioridade* f);
int fila_contem(FilaPrioridade* f, Tipo elemento);
void fila_imprimir(FilaPrioridade* f);

//IMPLEMENTAÇÃO DAS FUNÇÕES
FilaPrioridade* fila_criar(){
    FilaPrioridade* f = (FilaPrioridade*) malloc (sizeof(FilaPrioridade));
    return f;
}

void fila_destruir(FilaPrioridade* f){
    free(f->vetor);
    free(f);
}

Boolean fila_inserir(FilaPrioridade* f, Tipo elemento);

Tipo fila_remover1(FilaPrioridade* f){
    Tipo elem;
    int  i=0;
    if(f->vetor[i] != NULL){
        elem = f->vetor[i];
        f->vetor[i] = NULL;
        return elem;
    }
}

Boolean fila_remover2(FilaPrioridade* f, Tipo* endereco);

Boolean fila_primeiro(FilaPrioridade* f, Tipo* endereco){
    if(f->vetor[0] == NULL) return False;
    *endereco = f->vetor[0];
    return True;
}

int fila_tamanho(FilaPrioridade* f){
    return f->qtde;
}

int fila_contem(FilaPrioridade* f, Tipo elemento){
    for(int i = 0; i < f->qtde; i++){
        if(f->vetor[i] == elemento)
            return i;
    }
}

void fila_imprimir(FilaPrioridade* f){
    for(int i = 0; i < f->qtde; i++){
        printf("%d ", f->vetor[i]);
    }
}