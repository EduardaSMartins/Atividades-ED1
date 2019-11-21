#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{False = 0, True = 1} Boolean;

typedef int Tipo;

typedef struct no{
    Tipo dado;
    struct no *prox;
    struct no *ant;
} No;

typedef struct{
    No *primeiro;
    No *ultimo;
    int qtde;
} Lista;

//PRTÓTIPOS DAS FUNÇÕES
Lista *lista_criar();
No *criaNo(Tipo elemento);
No *getNo(Lista *l, int pos);
void insereEsq(No *aux, No *novo);
void lista_inserir_fim(Lista *l, No *novo);
void lista_inserir(Lista *l, int posicao, Tipo elemento);
int* lista_remover1(Lista *l, int posicao);
Boolean lista_remover_elemento(Lista *l, Tipo elemento);
Boolean lista_buscar(Lista *l, int posicao);
Boolean lista_contem(Lista *l, Tipo elemento);
int lista_posicao(Lista *l, Tipo elemento);
void lista_imprimir(Lista *l);

//IMPLEMENTAÇÃO
Lista *lista_criar(){
    Lista *l = (Lista *)malloc(sizeof(Lista));
    l->primeiro = NULL;
    l->ultimo = NULL;
    l->qtde = 0;
    return l;
}

No *criaNo(Tipo elemento){
    No *n = (No *)malloc(sizeof(No));
    n->ant = n->prox = NULL;
    n->dado = elemento;
    printf("%d ", n->dado);
    return n;
}

No *getNo(Lista *l, int pos){
    No *aux = l->primeiro;
    for (int i = 0; i < pos; i++)
        aux = aux->prox;
    return aux;
}

void insereEsq(No *aux, No *novo){
    novo->ant = aux->ant;
    novo->prox = aux;
    aux->ant->prox = novo;
    aux->ant = novo;
}

void lista_inserir_fim(Lista *l, No *novo){
    novo->ant = l->ultimo;
    l->ultimo->prox = novo;
    l->ultimo = novo;
}

void lista_inserir(Lista *l, int posicao, Tipo elemento){
    No *novo = criaNo(elemento);
    if (posicao > l->qtde - 1 || posicao < 0)
        return;
    else if (posicao == l->qtde - 1)
        lista_inserir_fim(l, novo);
    else if (posicao == 0){
        novo->prox = l->primeiro;
        l->primeiro->ant = novo;
        l->primeiro = novo;
    }else{
        No *aux = getNo(l, posicao);
        insereEsq(aux, novo);
    }
    l->qtde++;
}

//Remove pela posicao e devolve a posição da memória que ele estava alocado
int* lista_remover1(Lista *l, int posicao){
    int *endereco;
    No *aux;
    if (l->primeiro == NULL)
        return;
    else if (posicao == 0){ //Remoção do primeiro elemento da lista
        aux = l->primeiro;
        l->primeiro = l->primeiro->prox;
        l->primeiro->ant = NULL;
        endereco = &aux->dado;
    }else if (posicao == l->qtde - 1){ //Remoção do ultimo elemento da lista;
        aux = l->ultimo;
        l->ultimo = l->ultimo->ant;
        l->ultimo = NULL;
        endereco = &aux->dado;
    }else{
        aux = l->primeiro;
        for (int i = 0; i < posicao; i++) aux = aux->prox;
            
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        endereco = &aux->dado;
    }
    l->qtde--;
    free(aux);
    return endereco;
}

//Remove o nó a partir do elemento
Boolean lista_remover_elemento(Lista *l, Tipo elemento){
    No* aux = l->primeiro;
    int num = aux->dado;
    if (l->primeiro == NULL){
        free(l);
        return;
    }else{
        for(int i = 0; i < l->qtde; i++){
            if(num == elemento){
                if(i==0){
                    l->primeiro = aux->prox;
                    l->primeiro->ant = NULL;
                    l->qtde--;
                    free(aux);
                    return True;
                }else if(i == l->qtde-1){
                    l->ultimo = aux->ant;
                    l->ultimo->prox = NULL;
                    l->qtde--;
                    free(aux);
                    return True;
                }else{
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    l->qtde--;
                    free(aux);
                    return True;
                }
            }else{
                aux = aux->prox;
                num = aux->dado;
            }
        }
    }
    return False;
}

//Busca o elemento, caso a posição não seja válida retorna falso
Boolean lista_buscar(Lista *l, int posicao){
    if (posicao > l->qtde || posicao < l->qtde)
        return False;
    for (int i = 0; i < posicao; i++){
        if (i == posicao)
            return True;
    }
    return False;
}

//Retorna verdadeiro se o elemento solicitado está na lista
Boolean lista_contem(Lista *l, Tipo elemento){
    No *aux = l->primeiro;
    for (int i = 0; i < l->qtde; i++){
        if (aux->dado == elemento) return True;
        else aux = aux->prox;
    }
    return False;
}

//Retorna a posição da lista em que o elemento está - retorna -1 se o elemento não estiver na lista
int lista_posicao(Lista *l, Tipo elemento){
    No *aux;
    for (int i = 0; i < l->qtde; i++){
        aux = l->primeiro;
        if (aux->dado == elemento) return i;
        else aux = aux->prox;
    }
    return -1;
}

//Imprime os elementos presentes na lista
void lista_imprimir(Lista *l){
    No* aux = l->primeiro;
    for (int i = 0; i < l->qtde; i++){
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}