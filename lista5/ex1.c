#include <stdio.h>

void cloneA(int vet[], int tam, int *copia){
    
}

int main(){
    int vet[] = {10,20,30,40,50,60,70,80,90,100};
    int tam=10;
    int *copia1, *copia2;
    cloneA(vet,tam,&copia1);
    copia2 = cloneB(vet,tam);
    return 0;
}