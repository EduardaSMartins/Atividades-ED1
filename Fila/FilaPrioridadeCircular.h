#include <stdio.h>
#include <stdlib.h>

typedef enum Boolean{False = 0,True = 1}Boolean;

typedef int Tipo;

typedef struct{
    Tipo *vetor;
    int tam;
    int inicio;
    int fim;
}Fila;

Fila *fila_criar(int tamanho);
void fila_destruir(Fila *f);

Boolean fila_inserir(Fila *f, Tipo elemento);
Tipo *fila_remover1(Fila *f);
Boolean fila_remover2(Fila *f, Tipo *endereco);

Boolean fila_primeiro(Fila *f, Tipo *endereco);
int fila_tamanho(Fila *f);
int fila_contem(Fila *f, Tipo elemento);
void fila_imprimir(Fila *f);

/*Cria a fila 
@return endereço da fila criada e inicializada*/
Fila *fila_criar(int tamanho){
    Fila *fila = (Fila*) malloc (sizeof(Fila));
        fila->inicio = 0;
        fila->fim = 0;
        fila->tam = tamanho;
    return fila;
}

/*Destrói a fila  
@return */
void fila_destruir(Fila *f){
    free(f->vetor);
    free(f);
}

/*Inseri um elemento no final da fila 
@param: fila
@param: elemento a ser inserido
@return true se conseguir inserir, do contrário false;*/
Boolean fila_inserir(Fila *f, Tipo elemento){
    if (f->inicio == f->fim){
        f->vetor[0] = elemento;
    }else if (f->tam == f->fim)
        return False;
    //incremento e inserção
    f->vetor[f->fim] = elemento;
    f->fim++;
    f->tam++;
    return True;
}

/*
Remove o primeiro elemento da fila (FIFO)
@return 
*/
Tipo *fila_remover1(Fila *f){
    Tipo *temp;
    if(f->tam == 0)
        return temp;
    *temp = f->vetor[f->inicio];
    f->tam--;
    return temp;
}

Boolean fila_remover2(Fila *f, Tipo *endereco){
    if (f->tam == 0)
        return False;
    *endereco = f->vetor[f->inicio];
    for (int i = 0; i <= f->fim; i++){
        if (f->vetor[i] == *endereco)
            return True;
    }
    return True;
}


Boolean fila_primeiro(Fila *f, Tipo *endereco){
    if (f->tam == 0)
        return False;
    *endereco = f->vetor[f->inicio];
    return True;
}

/*
Informa o tamanho da fila
@return 
*/
int fila_tamanho(Fila *f){
    return f->tam;
}

int fila_contem(Fila *f, Tipo elemento){
    for (int i = 0; i < f->tam - 1; i++){
        if (f->vetor[i] == elemento){
            return i;
        }
    }
    return 0;
}

void fila_imprimir(Fila *f){
    for (int i = 0; i < f->tam-1; i++){
        printf("%d ", f->vetor[i]);
    }
    printf("\n");
}