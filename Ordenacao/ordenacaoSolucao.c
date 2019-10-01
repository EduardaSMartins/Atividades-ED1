#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cod;
    char nome[30];
    double preco;
}Produto;

/**************************************
 * BUBBLE SORT
 * ************************************/

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *v, int n){
    int i, fim;
    for (fim = n - 1; fim > 0; fim--){
        int houve_troca = 0;
        for (i = 0; i < fim; i++){
            if (v[i] > v[i + 1]){
                troca(&v[i], &v[i + 1]);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0)
            return;
    }
}

/**************************************
 * FUNÇÕES GENÉRICAS DE COMPARACAO
 * ************************************/

int comparaInt(void *a, void *b){
    int *x = (int *)a; //100
    int *y = (int *)b; //104
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    else
        return 0;
}

int comparaChar(void *a, void *b){
    char *x = (char *)a; //100
    char *y = (char *)b; //104
    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;
    else
        return 0;
}

int comparaProdutoPreco(void *a, void *b){
    Produto *x = (Produto *)a; //100
    Produto *y = (Produto *)b; //104
    if (x->preco > y->preco)
        return 1;
    else if (x->preco < y->preco)
        return -1;
    else
        return 0;
}

int comparaProdutoCodigo(void *a, void *b){
    Produto *x = (Produto *)a; //100
    Produto *y = (Produto *)b; //104
    if (x->cod > y->cod)
        return 1;
    else if (x->cod < y->cod)
        return -1;
    else
        return 0;
}
/**************************************
 * BUBBLE SORT GENÉRICO
 * ************************************/
void troca_generica(void *a, void *b, int tamElemento){
    void *temp = malloc(tamElemento);
    memcpy(temp, a, tamElemento); //int temp = *a;
    memcpy(a, b, tamElemento);    //*a = *b;
    memcpy(b, temp, tamElemento); //*b = temp;
    free(temp);
}

void bubble_generico(void *v, int n, int tamElemento, int (*funcao)(void *a, void *b)){
    //implementar
    int i, fim;
    for (fim = n - 1; fim > 0; fim--){
        int houve_troca = 0;
        for (i = 0; i < fim; i++){
            // v[i] == v + (i * tamElemento)
            // v[i+1] == v + ((i+1) * tamElemento)
            void *a = v + (i * tamElemento);
            void *b = a + tamElemento; //(i+1)
            if (funcao(a, b) > 0){                                      // if (v[i] > v[i+1])
                troca_generica(a, b, tamElemento); //troca(&v[i], &v[i+1]);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0)
            return;
    }
}

void printInt(void *elemento){
    int *p = (int *)elemento;
    printf("%d", *p);
}

void printChar(void *elemento){
    char *p = (char *)elemento;
    printf("%c", *p);
}

void printProduto(void *elemento){
    Produto *p = (Produto *)elemento;
    printf("(%d, %s, %.2f)", p->cod, p->nome, p->preco);
}

void printProdutoCod(void *elemento){
    Produto *p = (Produto *)elemento;
    printf("(%d)", p->cod);
}

void printVetor(void *v, int n, int tamElemento, void (*print)(void *)){
    printf("[");
    int i;
    for (i = 0; i < n; i++){
        void *elemento = v + (i * tamElemento);
        print(elemento); // printf("%d", v[i]);
        if (i < n - 1)
            printf(",");
    }
    printf("]\n");
}

/**************************************
 * MAIN
 * ************************************/

int main(){
    int v1[8] = {25, 48, 37, 12, 57, 86, 33, 92}; //100

    Produto vp[5] = {// 300
                     {5, "555", 12.5},
                     {1, "111", 30.67},
                     {4, "444", 4.4},
                     {3, "333", 23.11},
                     {2, "222", 47.12}};

    char vet_char[5] = {'x', 'd', 'e', 'a', 'r'}; //1000

    bubble_generico(v1, 8, sizeof(int), &comparaInt);
    bubble_generico(vp, 5, sizeof(Produto), &comparaProdutoPreco);
    bubble_generico(vet_char, 5, sizeof(char), &comparaChar);

    printVetor(v1, 8, sizeof(int), &printInt);
    printVetor(vp, 5, sizeof(Produto), &printProduto);
    printVetor(vet_char, 5, sizeof(char), &printChar);

    bubble_generico(vp, 5, sizeof(Produto), &comparaProdutoCodigo);
    printVetor(vp, 5, sizeof(Produto), &printProdutoCod);
}