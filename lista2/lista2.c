#include <stdio.h>
#include <string.h>

void ex1()
{
    int i = 10;                 //endereço: 0
    char c = 'a';               //endereço: 4
    float f = 2.5;              //endereço: 5
    printf("i: %d \n", i);      //10
    printf("&i: %u \n\n", &i);  //0
    printf("c: %c \n", c);      //a
    printf("&c: %u' \n\n", &c); //4
    printf("f: %.02f \n", f);   //2.5
    printf("&f: %u \n\n", &f);  //5
}

void ex2()
{
    int a = 100;                     //endereço: 10
    int v[4] = {10, 20, 30, 40};     //endereço: 14
    printf("a: %d \n", a);           //100
    printf("&a: %u \n\n", &a);       //10
    printf("v: %d \n", v);           //14
    printf("&v: %u \n\n", &v);       //14
    printf("&v[0]: %u \n", &v[0]);   //14
    printf("&v[1]: %u \n", &v[1]);   //18
    printf("&v[2]: %u \n", &v[2]);   //22
    printf("&v[3]: %u \n\n", &v[3]); //26
    printf("v+0: %u \n", v + 0);     //14
    printf("v+1: %u \n", v + 1);     //18
    printf("v+2: %u \n", v + 2);     //22
    printf("v+3: %u \n\n", v + 3);   //26
}

void ex3()
{
    char nome[10] = "Joao";                           //endereço: 32
    char fruta[] = "laranja";                         //endereço: 42
    printf("sizeof(nome): %ld \n", sizeof(nome));     //10
    printf("sizeof(fruta): %ld \n\n", sizeof(fruta)); //8
    printf("fruta: %u \n", fruta);                    //42
    printf("&fruta: %u \n", &fruta);                  //42
    printf("&fruta[0]: %u \n", &fruta[0]);            //42
    printf("&fruta[1]: %u \n", &fruta[1]);            //43
    printf("&fruta[2]: %u \n\n", &fruta[2]);          //44
    printf("fruta+0: %u \n", fruta + 0);              //42
    printf("fruta+1: %u \n", fruta + 1);              //43
    printf("fruta+2: %u \n\n", fruta + 2);            //44
}

void ex4()
{
    short int m[3][3] = {{10, 11, 12}, {20, 21, 22}, {31, 32, 33}}; //endereço: 64
    printf("m: %u \n", m);                                          //64
    printf("&m: %u \n\n", &m);                                      //64
    printf("&m[0][0]: %u \n", &m[0][0]);                            //64
    printf("&m[0][1]: %u \n", &m[0][1]);                            //66
    printf("&m[1][0]: %u \n", &m[1][0]);                            //70
    printf("&m[1][1]: %u \n", &m[1][1]);                            //72
    printf("&m[2][0]: %u \n", &m[2][0]);                            //76
    printf("&m[2][1]: %u \n", &m[2][1]);                            //78
    printf("\n");
    printf("m+0: %u \n", m + 0); //64
    printf("m+1: %u \n", m + 1); //70
    printf("m+2: %u \n", m + 2); //76
    printf("\n");
    printf("m[0]: %u \n", m[0]); //64
    printf("m[1]: %u \n", m[1]); //70
    printf("m[2]: %u \n", m[2]); //76
    printf("\n");
    printf("m[1]+0: %u \n", m[1] + 0); //70
    printf("m[1]+1: %u \n", m[1] + 1); //72
    printf("m[1]+2: %u \n", m[1] + 2); //74
    printf("\n");
}

void ex5()
{
    struct aluno
    {
        short int ra;
        char nome[10];
        float nota
    };

    struct aluno a;                    //endereço: 96
    printf("&a: %u \n", &a);           //96
    printf("&a.ra: %u \n", &a.ra);     //96
    printf("&a.nome: %u \n", &a.nome); //98
    printf("&a.nota: %u \n", &a.nota); //108
    printf("\n");
}

void ex6()
{
    int x = 20;      //sugestão de endereço: 112
    int *p1 = &x;    //sugestão de endereço: 116
    int **p2 = &p1;  //sugestão de endereço: 124
    int ***p3 = &p2; //sugestão de endereço: 132

    printf("x: %d \n", x);   //20
    printf("&x: %d \n", &x); //112
    printf("\n");
    printf("p1: %d \n", p1);   //112
    printf("&p1: %d \n", &p1); //116
    printf("*p1: %d \n", *p1); //20
    printf("\n");
    printf("p2: %d \n", p2);     //116
    printf("&p2: %d \n", &p2);   //124
    printf("*p2: %d \n", *p2);   //112
    printf("**p2: %d \n", **p2); //20
    printf("\n");
    printf("p3: %d \n", p3);       //124
    printf("&p3: %d \n", &p3);     //132
    printf("*p3: %d \n", *p3);     //116
    printf("**p3: %d \n", **p3);   //112
    printf("***p3: %d \n", ***p3); //20
    printf("\n");
}

void ex7()
{
    short int v[4]; //endereço: 130
    for (short int i = 1; i <= 4; i++)
    {
        *(v + i) = i;
        printf("i: %d\n", i);
        //printf("&i: %d\n\n", &i);
        printf("v: %d\n", v);
        printf("&v[%d]: %d\n", i, &v);
        printf("v[%d]: %d\n\n", i, v[i]);
    }
}

void ex8()
{
    struct produto
    {
        int codigo;
        char descricao[8];
        float preco;
    };
    struct produto p1; //endereço: 138
    struct produto p2; //endereço: 154
    p1.codigo = 1;
    strcpy(p1.descricao, "Mouse");
    p1.preco = 25.50;
    p2 = p1;
    p2.codigo = 2;
    printf("p1: %d\n", p1);                       //1
    printf("&p1: %d\n\n", &p1);                   //138
    printf("p2: %d\n", p2);                       //2
    printf("&p2: %d\n\n", &p2);                   //154
    printf("p1.codigo: %d\n", p1.codigo);         //1
    printf("p1.descricao: %s\n", p1.descricao);   //Mouse
    printf("p1.preco: %.2f\n\n", p1.preco);       //25.50
    printf("p2.codigo: %d\n", p2.codigo);         //2
    printf("p2.descricao: %s\n", p2.descricao);   //Mouse
    printf("p2.preco: %.2f\n\n", p2.preco);       //25.50
    printf("&p1.codigo: %d\n", &p1.codigo);       //138
    printf("&p1.descricao: %s\n", &p1.descricao); //142
    printf("&p1.preco: %.2f\n\n", &p1.preco);     //150
    printf("&p2.codigo: %d\n", &p2.codigo);       //154
    printf("&p2.descricao: %s\n", &p2.descricao); //158
    printf("&p2.preco: %.2f\n\n", &p2.preco);     //166
}

void ex9()
{
    struct aluno
    {
        short int ra;
        short int notas[2];
    };
    typedef struct aluno Aluno;
    Aluno a1 = {1, {85, 90}};   //endereço: 192
    Aluno *p1 = &a1;            //endereço: 199
    short int *v = (*p1).notas; //endereço: 208
    v[1] = 55;
    printf("a1.ra: %d\n", a1.ra);                           //192
    printf("a1.notas: %d, %d\n", a1.notas[0], a1.notas[1]); // 194, 196
}

void ex10()
{
    short int v1[] = {1, 2, 3};   //sugestão de endereço: 224
    short int v10[3] = {1, 2, 3}; //sugestão de endereço: 231
    short int *v2 = v1;           //sugestão de endereço: 238

    v2[0] = 10;
    *(v2 + 1) = 20;

    short int i; //sugestão de endereço: 247
    for (i = 0; i < 3; i++)
    {
        printf("%d ", v1[i]); // 0 1 2
    }
}

void ex11(){
    struct produto{
        int codigo;
        char descricao[8];
        float preco;
    };
    struct produto prod = {10, "memoria", 100.55}; //sugestão de endereço: 320
    void *p;                                       //sugestão de endereço: 336
    p = &prod.codigo;
    short int *cod = (short int *)p; //sugestão de endereço: 344
    printf("Codigo: %d\n", *cod);
    p = &prod.preco;
    printf("Preco: %.2f\n", *(float *)p);
}

void ex12(){
    short int i1 = 100;
    short int i2 = 200;
    short int i3 = 300;
    short int *v2[3];
    for(int i = 0; i < 3; i++){
        printf("v[%d] = %n\n", i, v2[i]);
    }
}

int main()
{
    printf("Exercício 01\n");
    ex1();
    printf("Exercício 02\n");
    ex2();
    printf("Exercício 03\n");
    ex3();
    printf("Exercício 04\n");
    ex4();
    printf("Exercício 05\n");
    ex5();
    printf("Exercício 06\n");
    ex6();
    printf("Exercício 07\n");
    ex7();
    printf("Exercício 08\n");
    ex8();
    printf("Exercício 09\n");
    ex9();
    printf("Exercício 10\n");
    ex10();
    printf("Exercício 11\n");
    ex11();
//    printf("Exercício 12\n");
//    ex12();
  
    return 0;
}