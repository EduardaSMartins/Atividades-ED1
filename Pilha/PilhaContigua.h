#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{False=0, True=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;
}Pilha;

//PROTÓTIPOS
Pilha* pilha_criar(int tam);
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
void pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_tamanho(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
int pilha_posicao(Pilha* p, Tipo elemento);
//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
void pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);


//IMPLEMENTAÇÃO
Pilha* pilha_criar(int tam){
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->qtde = 0;
    p->tam = tam;
    return p;
}

Boolean pilha_push(Pilha* p, Tipo elemento){
    if(p->qtde >= p->tam) return False;
    p->vetor[p->qtde] = elemento;
    p->qtde++;
    return True;
}

Tipo* pilha_pop1(Pilha* p){
    Tipo aux;
    aux = p->vetor[p->qtde-1];
    p->qtde--;
    return p->vetor;
}

Boolean pilha_pop2(Pilha* p, Tipo* end){
    *end = p->vetor[p->qtde-1];
    p->qtde--;
    return True;
}

void pilha_destruir(Pilha* p){
    free(p->vetor);
    free(p);
}

void pilha_imprimir(Pilha* p){
    for(int i = 0; i < p->qtde; i++){
        printf("%d ", p->vetor[i]);
    }
    printf("\n");
}

int pilha_posicao(Pilha* p, Tipo elemento){
    int i;
    for(i = 0; i < p->qtde; i++){
        if(p->vetor[i] == elemento) break;
    }
    return i;
}

int pilha_tamanho(Pilha* p){
    return p->qtde;
}

//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    if(tam > (p->tam)-(p->qtde)) return 0;
        for(int i = 0; i < tam; i++){
            pilha_push(p, vetor[i]);
        } 
    return tam;
}
void pilha_inverter(Pilha* p){
     Pilha* clone = pilha_clone(p);
    int j=p->qtde-1, i;
    for(i = 0; i < p->qtde; i++){
        p->vetor[i] = clone->vetor[j];
        j--;
    }
}

Pilha* pilha_clone(Pilha* p){
    Pilha* clone = (Pilha*)malloc(sizeof(Pilha));
    clone->tam = p->tam;
    clone->vetor = (Tipo*)calloc(p->tam, sizeof(Tipo));
    clone->qtde = p->qtde;
    for(int i=0; i < p->qtde; i++){
        clone->vetor[i] = p->vetor[i];
    }
    return clone;
}