#include <stdio.h>
#include "TADVetor2.h"

// typedef struct{
//     int* vetor;
//     int size;
//     int length;
// }Vetor;


int main(){
    Vetor* v;
    int resultado;
    v = vetor_new(5);
    resultado = vetor_insert(v,50,0);
    resultado = vetor_insert(v,30,1);
    resultado = vetor_insert(v,20,2);
    resultado = vetor_insert(v,10,3);
    resultado = vetor_insert(v,40,4);
    vetor_imprime(v);
    vetor_sort(v);
    vetor_imprime(v);
    return 0;
}