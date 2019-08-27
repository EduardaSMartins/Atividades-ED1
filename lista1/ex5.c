#include <stdio.h>
int calculaCedulas(int valor, int *vetor){
    if (valor % 10 == 1)
        return 0;
    if (valor % 10 == 3)
        return 0;
    int resto = valor;
    vetor[0] = resto / 100;
    resto = resto % 100;
    vetor[1] = resto / 50;
    resto = resto % 50;
    vetor[2] = resto / 20;
    resto = resto % 20;
    vetor[3] = resto / 10;
    resto = resto % 10;
    vetor[4] = 0;
    if (resto % 2 == 1){
        vetor[4] = resto / 5;
        resto = resto % 5;
    }
    vetor[5] = resto / 2;
    return 1;
}

void imprimeQtdCedulas(int valor, int *cedulas){
    printf("\nValor: %d\n", valor);
    printf("Cedulas: \n");
    printf("R$ 100,00: %d \n", cedulas[0]);
    printf("R$  50,00: %d \n", cedulas[1]);
    printf("R$  20,00: %d \n", cedulas[2]);
    printf("R$  10,00: %d \n", cedulas[3]);
    printf("R$   5,00: %d \n", cedulas[4]);
    printf("R$   2,00: %d \n", cedulas[5]);
}

int main(){
    int valor;
    int cedulas[6];
    valor = 11;
    if (calculaCedulas(valor, cedulas)){
        imprimeQtdCedulas(valor, cedulas);
    }else{
        printf("Valor: %d \nNao eh possivel retirar esse valor\n", valor);
    }
    valor = 534;
    if (calculaCedulas(valor, cedulas)){
        imprimeQtdCedulas(valor, cedulas);
    }else{
        printf("Valor: %d \nNao eh possivel retirar esse valor\n", valor);
    }
    int valor;
