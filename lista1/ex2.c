#include <stdio.h>

int main(){
    int u=0,d=0,c=0, numero=246, resto=0;
    c = numero / 100;
    resto = numero % 100;
    d = resto / 10;
    numero = resto % 10;
    u = numero;
    printf("%d%d%d\n", u,d,c);
    return 0;
}