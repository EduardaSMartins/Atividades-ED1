#include <stdio.h>
#include "TAD_Vetor.h"

//Definição de outros tipos
typedef struct{
    int *vetor;
    int size;
    int lenght;
} Vetor;

typedef int DataType;

int main(){
    DataType tam = 5;
    DataType vetor[tam];
    Vetor *vet = vetor_new(tam);
    vetor_free(vet);
    vetor_print(vet);
    return 0;
}