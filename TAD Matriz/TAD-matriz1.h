#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **matriz;
    int linhas;
    int colunas;
}Matriz;

//Protótipos de Funções

Matriz* matriz_cria(int linhas, int colunas);
void matriz_destroi(Matriz *m);
int matriz_acessa1(Matriz *m, int lin, int col);
void matriz_atribui(Matriz *m, int lin, int col, int valor);
void matriz_imprime(Matriz *m);
int matriz_linhas(Matriz* m);
int matriz_colunas(Matriz* m);
void matriz_map1(Matriz* m, void (*funcao)(int*));
