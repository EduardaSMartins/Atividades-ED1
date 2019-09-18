#include <stdio.h>

void imprimeValor(int vet[], int tam){
    printf("[");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("]\n");
}

void intercala1(int vet1[], int tam1, int vet2[], int tam2){
    int tam3=tam1+tam2;
    int vet3[tam3];
    int a=0, b=0;
    for(int i = 0; i < tam3; i++){
        if(i % 2 == 0 && a < tam1){
            vet3[i] = vet1[a];
            a++;
        }else if(i % 2 != 0 && b < tam2){
            vet3[i] = vet2[b];
            b++;
        }
    }
    imprimeValor(vet3,tam3);
}

void imprimeReferencia(int *vet, int tam){
    printf("[");
    for(int i = 0; i < tam; i++){
        printf("%d ", vet[i]);
    }
    printf("]\n");
}

int *intercala2(int *v1, int tam1, int *v2, int tam2){
    int tam3=tam1+tam2;
    int v3[tam3];
    int a=0, b=0;
    for(int i = 0; i < tam3; i++){
        if(i % 2 == 0 && a < tam1){
            v3[i] = v1[a];
            a++;
        }else if(i % 2 != 0 && b < tam2){
            v3[i] = v2[b];
            b++;
        }
    }
    imprimeReferencia(v3,tam3);
    return v3;
}

int main(){
    int tam1=5, tam2=5;
    int vet1[] = {10,20,30,40,50};
    int vet2[] = {60,70,80,90,0};
    intercala1(vet1, tam1, vet2, tam2);
    int *retornoVetor = intercala2(&vet1, tam1,&vet2,tam2);
    return 0;
}