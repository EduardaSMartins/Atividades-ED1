#include <stdio.h>
    //Escreva um algoritmo que calcule e mostre a potência de um determinado 
    //número somente usando ooperador de multiplicaçã
int main(){
    int numero=3, pot=2, result=1;
    for(int i = 1; i <= pot+1; i++){
        result *= result;
    }
    printf("Potência de %d: %d\n", numero, result);
}