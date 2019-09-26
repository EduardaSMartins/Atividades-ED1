#include <stdio.h>
#include <stdlib.h>
#include<time.h>


void ordem_lgn(unsigned long int n, int carga){
    unsigned long int i, x;
    i = n;
    while(i>0){

        for(x=0; x < carga; x++); // CARGA
        i = i / 2;
    }
}

void ordem_n(unsigned long int n, int carga){
    unsigned long int i, x;
    for(i=0; i < n; i++){
        for(x=0; x < carga; x++); // CARGA
    }
}

void ordem_n2(unsigned long int tam, int carga){
    unsigned long int i,j,x;
    for(i=0; i < tam; i++){
        for(j=0; j < tam; j++){
            for(x=0; x < carga; x++); //CARGA
        }
    }
}

void medeTempo(unsigned long int n, int carga, void (*funcao)(unsigned long int, int)){
    clock_t inicio, fim, total; 
    inicio = clock(); 
    funcao(n, carga);   
    fim = clock();
    total = fim - inicio;
    double tempoExecutado = ((double)total)/CLOCKS_PER_SEC; // in seconds 
    printf("[%ld][%d]: %f\n", n, carga, tempoExecutado);
}


int main(){
    unsigned long int n = 100000;
    int carga = 10;
    
    medeTempo(n, carga, &ordem_n);
    medeTempo(n, carga, &ordem_lgn);
    medeTempo(n, carga, &ordem_n2);
    
    
}