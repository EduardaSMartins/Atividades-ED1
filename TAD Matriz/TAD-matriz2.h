#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **matriz;
    int linhas;
    int colunas;
} Matriz;

//Protótipos de Funções
Matriz *matriz_cria(int linhas, int colunas);
void matriz_destroi(Matriz *m);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
void matriz_imprime(Matriz *m);
int matriz_linhas(Matriz *m);
int matriz_colunas(Matriz *m);
void matriz_map2(Matriz *m, int (*funcao)(int));

//Implementação
//Função que cria uma matriz
Matriz *matriz_cria(int lin, int col){
    Matriz *mat = (Matriz *)malloc(sizeof(Matriz));   //aloca a estrutura "Matriz"
    mat->matriz = (int **)calloc(lin, sizeof(int *)); // aloca o esqueleto de uma matriz (ponteiro de ponteiro)
    for (int i = 0; i < lin; i++){
        mat->matriz[i] = (int *)calloc(col, sizeof(int)); //aloca a quantidade de colunas necessárias para cada linha da matriz
    }
    mat->linhas = lin;  //a quantidade de linhas da estrutura 'Matriz' recebe a qtde exata de linhas que a matriz deve possuir
    mat->colunas = col; //a quantidade de colunas da estrutura 'Matriz' recebe a qtde exata de colunas que a matriz deve possuir
    return mat;
}

void matriz_destroi(Matriz *m){
    for(int i = 0; i < m->linhas; i++){
        free(m->matriz[i]);
    }
    free(m->matriz);
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end){
    *end = m->matriz[lin][col];
    printf("Elemento da posição [%d][%d] = [%d]\n", lin,col,*end);
}

void matriz_atribui(Matriz *m, int lin, int col, int valor){
    m->matriz[lin][col] = valor;    
}

void matriz_imprime(Matriz *m){
    int linhas = m->linhas;
    int colunas = m->colunas;
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Elemento [%d][%d] = [%d]\n", m->linhas,m->colunas,m->matriz[linhas][colunas]);
        }
        printf("\n");
    }
}

int matriz_linhas(Matriz *m){
    return m->linhas;
}
int matriz_colunas(Matriz *m){
    return m->colunas;
}
