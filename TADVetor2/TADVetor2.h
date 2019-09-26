#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* vetor;
    int size;
    int length;
}Vetor;

typedef int DataType;

//typedef enum {false,true} Boolean;

//Protótipo das funções
Vetor* vetor_new(DataType tam);
int vetor_insert(Vetor* v, DataType element, int index);
void vetor_imprime(Vetor* v);
void vetor_dobra(Vetor* v, DataType tam);
void vetor_sort(Vetor* v);

//Implementação das funções
Vetor* vetor_new(DataType tam){
    Vetor *vet = (Vetor*) malloc (sizeof(Vetor));
    vet->vetor = (DataType*) calloc (tam,sizeof(DataType));
    vet->length = tam;
    vet->size = 0;
    return vet;
}

int vetor_insert(Vetor* v, DataType element, int index){
    //vetor_dobra(v, v->length);
    //for(int i = v->length; i > index; i--){
    //    v->vetor[i+1] = v->vetor[i]; 
    //}
    v->vetor[index] = element;
    v->size += 1;
    return 1; 
}

void vetor_imprime(Vetor* v){
    for(int i = 0; i < v->size; i++){
        printf("%d  ", v->vetor[i]);
    }
}

void vetor_dobra(Vetor* v, int tam){
    if(v->size != v->length)
        return;
    DataType *temp = (DataType*) calloc (tam*2, sizeof(DataType));
    for(int i = 0; i < tam; i++){
        temp[i] = v->vetor[i];
    }
    v->length = tam*2;
    free(v->vetor);
}

void vetor_sort(Vetor* v){
    int temp=0;
    for(int i = 0; i < v->size; i++){
        if(v->vetor[i] > v->vetor[i+1]){
            temp = v->vetor[i];
            v->vetor[i] = v->vetor[i+1];
            v->vetor[i+1] = v->vetor[i];
        }
    }
}
