#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char cod[6];
    char* nome;
    float preco;
    int qtde;   //qtde de produtos no estoque
    int qtdePrecos; //qtde de precos
}Produto;

typedef struct{
    char* nome;
    int qtde;   //quantidade de produtos
    int tam;    //tamanho do vetor de produtos
    Produto** produtos;
}Empresa;

//Protótipo das Funções
Produto* novoProduto(char* cod, char* nome, float preco, int qtde);
float mediaDePreco(Empresa* e);
int buscaRemoveDuplicados(Empresa* e, char* cod);

//Implementação das Funções 
Produto* novoProduto(char* cod, char* nome, float preco, int qtde){
    Produto *p = (Produto*) malloc (sizeof(Produto));
    //p->cod = (char*) calloc (strlen(cod)+1, sizeof(char));
    strcpy(p->cod, cod);
    p->nome = (char*) calloc (strlen(nome)+1, sizeof(char));
    strcpy(p->nome, nome);
    p->preco = preco;
    p->qtde = qtde;
    return p;
}

void imprimeProduto(Produto* p){
    int aux=0;
    printf("Produto 1: {");
    for(int i = 0; i < 6; i++){
        printf("%c", p->cod[i]);
    }
    printf(", ");
    aux = strlen(p->nome);
    for(int i = 0; i < aux; i++){
        printf("%c", p->nome[i]);
    }
    printf(", ");
    printf("%.2f, ",p->preco);
    printf("%d}\n", p->qtde);
}


int main(){
    Produto* p1;
    Empresa* e1;
    p1->qtdePrecos = 1;
//    p1->preco[p1->qtdePrecos] = {200.5,300.5,250};
    p1 = novoProduto("m1", "Mesa", 20.50, 25);
    imprimeProduto(p1);
  return 0;
}

/*b) Escreva uma função que dado uma empresa, devolva a média de preço de todos os produtos existentes. 
Percebam que cada produto possui um conjunto dos últimos preços praticados. Portanto, 
o preço do produto é obtido pela média dos seus preços.
float mediaDePreco(Empresa* e);

c) Escreva uma função que dado um código de produto, realize uma busca no vetor e remova todas as ocorrências do produto. A função deve manter os produtos armazenados de forma contígua na memória. Portanto, não deve haver “buracos” no vetor. O gerenciamento da memória faz parte da avaliação.
int buscaRemoveDuplicados(Empresa* e, char* cod);
A função devolve a quantidade de ocorrências removidas. 
*/