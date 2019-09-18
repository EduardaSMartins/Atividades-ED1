#include <stdio.h>

char conc(float nota){
    if(nota < 6.0 && nota >= 0.0){
        return 'I';
    }else if(nota >= 6.0 && nota < 7.0){
        return 'C';
    }else if(nota >= 7.0 && nota < 9.0){
        return 'B';
    }else if(nota >= 9.0 && nota < 10.1){
        return 'A';
    }else{
        return '*';
    }
}


int main(){
    //Teste 1
    printf("Nota: 10.1\nConceito: %c\n\n", conc(10.1));
    printf("Nota: 6.9\nConceito: %c\n\n", conc(6.9));
    printf("Nota: 5.6\nConceito: %c\n\n", conc(5.6));
    printf("Nota: 7.5\nConceito: %c\n\n", conc(7.5));
    
    //Tese 2
    char conceito;
    return 0;
}