#include <stdio.h>

int main(){
    int dia=5, mes=8, ano=2019;
    switch (dia){
        case 1: printf("Primeiro de "); break;
        case 2: printf("Dois de "); break;
        case 3: printf("Três de "); break;
        case 4: printf("Quatro de "); break;
        case 5: printf("Cinco de "); break;
        case 6: printf("Seis de "); break;
        case 7: printf("Sete de "); break;
        case 8: printf("Oito de "); break;
        case 9: printf("Nove de "); break;
        case 10: printf("Dez de "); break;
        case 11: printf("Onze de "); break;
        case 12: printf("Doze de "); break;
        case 13: printf("Treze de "); break;
        case 14: printf("Catorze de "); break;
        case 15: printf("Qinze de "); break;
        case 16: printf("Dezesseis de "); break;
        case 17: printf("Dezessete de "); break;
        case 18: printf("Dezoito de "); break;
        case 19: printf("Dezenove de "); break;
        case 20: printf("Vinte de "); break;
        case 21: printf("Vinte e um de "); break;
        case 22: printf("Vinte e dois de "); break;
        case 23: printf("Vinte e três de "); break;
        case 24: printf("Vinte e quatro de "); break;
        case 25: printf("Vinte e cinco de "); break;
        case 26: printf("Vinte e seis de "); break;
        case 27: printf("Vinte e sete de "); break;
        case 28: printf("Vinte e oito de "); break;
        case 29: printf("Vinte e nove de "); break;
        case 30: printf("Trinta de "); break;
        case 31: printf("Trinta e um de "); break;
        default: printf("Bug\n"); break;
    }
    switch (mes){
    case 1: printf("Janeiro de"); break;
    case 2: printf("Fevereiro de"); break;
    case 3: printf("Março de"); break;
    case 4: printf("Abril de"); break;
    case 5: printf("Maio de"); break;
    case 6: printf("Junho de"); break;
    case 7: printf("Julho de"); break;
    case 8: printf("Agosto de"); break;
    case 9: printf("Setembro de"); break;
    case 10: printf("Outubro de"); break;
    case 11: printf("Novembro de"); break;
    case 12: printf("Dezembro de"); break;
    default:printf("Bug\n"); break;
    }
    printf(" %d\n", ano);
    return 0;
}