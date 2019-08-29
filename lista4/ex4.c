#include <stdio.h>

void intercalaVetores(int *v1, int tam1, int *v2, int tam2){
    int v3[tam1+tam2];
    int j=0;
    int k=0;
    for(int i = 0; i < tam1+tam2; i++){
        if(v1[j] < v2[k]){
            v3[i] = v1[j];
            j++;
        }else{
            v3[i] = v2[k];
            k++;
        }
    }
}

int *IntercalaVetores(int *v1, int tam1, int *v2, int tam2, int *v3){
    v3[tam1+tam2];
    int j=0;
    int k=0;
    for(int i = 0; i < tam1+tam2; i++){
        if(v1[j] < v2[k]){
            v3[i] = v1[j];
            j++;
        }else{
            v3[i] = v2[k];
            k++;
        }
    }
    return v3;
}

int main(){
    int v1[] = {1,3,5};
    int v2[] = {-1,2,4,6};
    int tam1 = 3;
    int tam2 = 4;
    intercalaVetores(v1, tam1, v2, tam2);
    int vet[tam1+tam2];
    int *vetor = IntercalaVetores(v1,tam1,v2,tam2,&vet);
    for(int i = 0; i < tam1+tam2; i++){
        printf("%d ", vet[i]);
    } 
    return 0;
}

/*Escreva uma função para intercalar dois vetores. Assuma que os vetores recebidos já estão
ordenados. Desenvolva duas versões desta função:
a) usando a estratégia convencional
b) usando a estratégia do scanf.

*/