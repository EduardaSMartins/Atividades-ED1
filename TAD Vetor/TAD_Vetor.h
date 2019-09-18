#include <stdio.h>
#include <stdlib.h>

//DEFINICAO DA ESTRUTURA Vetor
typedef struct{
    int *vetor;
    int size;
    int lenght;
}Vetor;

//CRIAÇÃO DE NOVOS TIPOS
typedef int DataType;
typedef enum {false,true} Boolean;

//PROTOTIPO DAS FUNCOES
Vetor* vetor_new(DataType tam);     //Parâmetro: tamanho do vetor a ser alocado
void vetor_free(Vetor* v);
void vetor_print(Vetor *v);
void vetor_dobra(Vetor* v, DataType tam);
Boolean vetor_insert(Vetor* v, DataType element, int index);
Boolean vetor_add(Vetor* v, DataType element);
DataType vetor_remove1(Vetor* v, int index);
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);

//IMPLEMENTACAO DAS FUNCOES
//Cria o vetor
Vetor* vetor_new(DataType tam){
    Vetor *vet = (Vetor*) malloc (sizeof(Vetor));
    vet->vetor = (DataType*) calloc (tam,sizeof(DataType));
    vet->lenght = tam;
    vet->size = 0;
    return vet;
}

//Destruir o vetor
void vetor_free(Vetor* v){
    free(v->vetor);
    free(v); 
    printf("Desalocado com Sucesso!!!\n\n");
}

//Imprimir o vetor
void vetor_print(Vetor* v){
    for(int i = 0; i < v->lenght; i++){
        printf("[%d] = [%d]\n", i, v->lenght);
    }
    printf("\n");
}

//Funcao que providencia espaço no vetor sempre que necessário
void vetor_dobra(Vetor* v, int tam){
    if(v->size != v->lenght)
        return;
    DataType *temp = (DataType*) calloc (tam*2, sizeof(DataType));
    for(int i = 0; i < tam; i++){
        temp[i] = v->vetor[i];
    }
    v->lenght = tam*2;
    free(v->vetor);
}

//Adicionar um elemento em uma posicao do vetor
Boolean vetor_insert(Vetor* v, DataType element, int index){
    vetor_dobra(v, v->lenght);
    for(int i = v->lenght; i > index; i--){
        v->vetor[i+1] = v->vetor[i]; 
    }
    v->vetor[index] = element;
    return true; 
}

//Adicionar um elemento no final do vetor
Boolean vetor_add(Vetor* v, DataType element){
    vetor_dobra(v, v->lenght);
    v->vetor[v->size] = element;
    return true;
}

//Remover um elemento do vetor de uma posição específica
DataType vetor_remove1(Vetor* v, int index){
    int i=0;
    while (i != index){
        i++;
    }
    if(i == index){
        v->vetor[i] = NULL;
    }
    for(int j = i; j < v->size-1; j++){
        v->vetor[j] = v->vetor[j+1];
    }
        return v->vetor[index];
}

//
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr){
    int i=0;
    while (i != index){
        i++;
    }
    if(i == index){
        v->vetor[i] = NULL;
        ptr = v->vetor[i];
    }
    for(int j = i; j < v->size-1; j++){
        v->vetor[j] = v->vetor[j+1];
    }
    if(*ptr != NULL)
        return true;
}

