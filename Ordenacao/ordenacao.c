#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    char nome[30];
    double preco;
}Produto;

/**************************************
            BUBBLE SORT
**************************************/

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* v, int n){
    int i, fim;
    for (fim = n-1; fim>0; fim--) {
        int houve_troca = 0;
        for (i=0; i<fim; i++){
            if (v[i]>v[i+1]) {
                troca(&v[i], &v[i+1]);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0) return;
    }
}

/**************************************
 * FUNÇÕES GENÉRICAS DE COMPARACAO
 * ************************************/

int comparaInt(void* a, void* b){
    int* x = (int*)a; //100
    int* y = (int*)b; //104
    if(*x > *y) return 1;
    else if(*x < *y) return -1;
    else return 0;
}
int comparaChar(void* a, void* b){
    char* x = (char*)a; //100
    char* y = (char*)b; //104
    if(*x > *y) return 1;
    else if(*x < *y) return -1;
    else return 0;
}

int comparaProdutoPreco(void* a, void* b){
    Produto* x = (Produto*)a; //100
    Produto* y = (Produto*)b; //104
    if(x->preco > y->preco) return 1;
    else if(x->preco < y->preco) return -1;
    else return 0;
}

/**************************************
 * BUBBLE SORT GENÉRICO
 * ************************************/

void bubble_generico(void* v, int n, int tamElemento, int (*funcao)(void* a, void* b)){
    //implementar
}

/**************************************
 * MAIN
 * ************************************/

int main(){
    int v1[8] = {25,48,37,12,57,86,33,92}; //100
    
    Produto vp[5] = { // 300
        {5,"555",5.5},
        {1,"111",1.1},
        {4,"444",4.4},
        {3,"333",3.3},
        {2,"222",2.2}
    };

    

    char vetChar[5] = {'x','d', 'e', 'a', 'r'}; //1000

    bubble_generico(v1, 8, sizeof(int), &comparaInt);
    bubble_generico(vp, 5, sizeof(Produto), &comparaProdutoPreco);
    bubble_generico(vetChar, 5, sizeof(char), &comparaChar);

    printf(v1, 8, sizeof(int));
    printf(vp, 5, sizeof(Produto));
    printf(vetChar, 5, sizeof(char));

}   