#include <stdio.h>
#include <stdlib.h>


typedef enum boolean{False=0, True=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;

//PROTOTIPOS
Fila* fila_criar();
Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);
void fila_destruir(Fila* f);

//IMPLEMENTAÇÃO
Fila* fila_criar(int tam){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->vetor = (Tipo*) calloc (tam, sizeof(Tipo));
    f->fim = 0;
    f->inicio = 0;
    return f;
}

Boolean fila_inserir(Fila* f, Tipo elemento){
    if((f->fim+1) == f->tam) return False;
    f->fim++;
    f->vetor[f->fim] = elemento;
    return True;
}

Tipo* fila_remover1(Fila* f){
    f->vetor[f->inicio] = NULL;
    if(f->inicio+1 == f->tam){
        f->inicio = 0;
        f->fim = 0;
    }
    else
        f->inicio++;
    return f->vetor;
}

Boolean fila_remover2(Fila* f, Tipo* endereco){
    if(f->vetor[f->inicio] == NULL) return False;
    f->vetor[f->inicio] = NULL;
    if(f->inicio+1 == f->tam){
        f->inicio = 0;
        f->fim = 0;
    }
    else
        f->inicio++;
    return True;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f->vetor == NULL) return False;
    endereco = f->vetor;
    return True;
}

int fila_tamanho(Fila* f){
    return f->tam;    
}

int fila_contem(Fila* f, Tipo elemento){
    for(int i = 0; i < f->tam; i++){
        if(f->vetor[i] == elemento)
            return i;
    }
}

void fila_imprimir(Fila* f){
    for(int i = 0; i < f->tam; i++){
        printf("[%d] ", f->vetor[i]);
    }
    printf("\n");
}

void fila_destruir(Fila* f){
    free(f->vetor);
    free(f);
}