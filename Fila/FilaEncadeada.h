#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{False=0, True=1} Boolean;
typedef int Tipo;

/** Registro utilizado para acomodar cada elemento da pilha (Nó). **/
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/** Estrutura usada para representar e armazenar a FILA com alocação encadeada. **/
typedef struct{
    No* prim;
    No* ult;
    int qtde;
}Fila;

//PROTOTIPOS DE FUNÇÕES
Fila* fila_criar();
void fila_destruir(Fila* f);
Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
int fila_contem(Fila* f, Tipo elemento);
void no_destruir(No* nozinho);
void fila_imprimir(Fila* f);

//IMPLEMENTAÇÃO
Fila* fila_criar(){
    Fila* f = (Fila*) malloc (sizeof(Fila));
    return f;    
}

No* cria_no(Tipo elemento){
    No* novo = (No*) malloc (sizeof(No));
    novo->dado = elemento;
    novo->prox = NULL;

    return novo;
}

Boolean fila_inserir(Fila* f, Tipo elemento){
    No* aux = cria_no(elemento);
    if(f->prim == NULL){
        f->prim = aux;
        f->ult = aux;
    }else
        f->ult->prox = aux;
    f->qtde++;
    return True;
}

Tipo* fila_remover1(Fila* f){
    No* aux = f->prim;
    Tipo* elem = &aux->dado;
    f->prim = f->prim->prox;
    f->qtde--;
    no_destruir(aux);
    *elem = f->prim->dado;
    return elem;
}
Boolean fila_remover2(Fila* f, Tipo* endereco){
    No* aux;
    if(f->prim == NULL) return False;
    aux = f->prim;
    f->prim = f->prim->prox;
    f->qtde--;
    no_destruir(aux);
    return True;
}

Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f->prim == NULL) return False;
    *endereco = f->prim->dado;
    //endereco->prox = f->prim->prox;
    return True;
}

int fila_tamanho(Fila* f){
    return f->qtde;
}

int fila_contem(Fila* f, Tipo elemento){
    
}

void fila_imprimir(Fila* f){
    No* aux;
    aux = f->prim;
    while(aux != NULL){
        printf("[%d] ", aux->dado);
        aux = aux->prox;
    }
    
}

void no_destruir(No* nozinho){
    free(nozinho);
}

void fila_destruir(Fila* f){
    free(f);
}