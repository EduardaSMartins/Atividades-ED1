#include <stdio.h>

int main(){
    float nota=7.9;
    if(nota < 6.0){
        printf("Conceito I\n");
    }else if(nota >= 6.0 && nota < 7.0){
        printf("Conceito C\n");
    }else if(nota >= 7.0 && nota < 9.0){
        printf("Conceito B\n");
    }else if(nota >=  9.0){
        printf("Conceito A\n");
    }else{
        printf("Conceito Desconhecido\n");
    }
    return 0;
}