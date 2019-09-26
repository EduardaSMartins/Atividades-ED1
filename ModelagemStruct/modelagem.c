#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char numero[16];
    char whatsapp[2];
}Telefone;

typedef struct{
    char cep[11];
    int numero;
    char estado[3];
}Endereco;

typedef struct{
    char *nome;
    int idade;
    char *email;
    Endereco endereco;
    Telefone *telefones;
    int qtdeContatos;
}Pessoa;

typedef struct{
    char *descricao;
    Pessoa **pessoas;
    int tamVetor;
    int qtdePessoas;
}Agenda;

//Protótipo de Funções
Pessoa *pessoa_novo(char *nome, int idade, char *email);
void pessoa_defineEndereco(Pessoa *p, char *cep, int num, char *estado);
void pessoa_cadastrarContato(Pessoa *p, char *numero, char *flagWhats);
void agenda_verificaReduzTamanho(Agenda *agenda);
int agenda_consultaPorEstado(Agenda *agenda, char *estado, Telefone **referencia);
void agenda_inserirPessoa(Agenda* agenda, Pessoa* p);
Pessoa* agenda_removerPessoa(Agenda* agenda, char* email);
void pessoa_desalocar(Pessoa* p);

//Implementação das Funções acima
Pessoa *pessoa_novo(char *nome, int idade, char *email){
    //Alocar a estrutura Pessoa
    Pessoa *novo = (Pessoa *)malloc(sizeof(Pessoa));
    //Alocar o que compõe a estrutura Pessoa (nome e email - inicialmente) e armazenar os dados em novo
    // + 1: para o \n
    novo->nome = (char *)calloc(strlen(nome) + 1, sizeof(char));
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->email = (char *)calloc(strlen(email) + 1, sizeof(char));
    strcpy(novo->email, email);
    novo->qtdeContatos = 0;
    //retornar o endereço de onde está a estrutura dessa pessoa
    return novo;
}

void pessoa_defineEndereco(Pessoa *p, char *cep, int num, char *estado){
    //Faz com que o endereco da pessoa seja armazenado em seu respectivo local
    //O campo "cep" da estrutura recebe o cep que foi passado por parâmetro
    strcpy(p->endereco.cep, cep);
    //O número da residência também é recebido na própria estrutura
    p->endereco.numero = num;
    //O campo "estado" da estrutura recebe o estado que foi passado por parâmetro
    strcpy(p->endereco.estado, estado);
}

void pessoa_cadastrarContato(Pessoa *p, char *numero, char *flagWhats){
    //Aloca-se o campo do telefone que será inserido no cadastro da pessoa
    Telefone *contato = (Telefone *)malloc(sizeof(Telefone));
    //Copia o número recebido para a estrutura na posição i do vetor
    strcpy(contato->numero, numero);
    //Indica se o número possui zapzap
    strcpy(contato->whatsapp, flagWhats);
    //Incrementa a quantidade de contatos da pessoa indicada
    p->telefones[p->qtdeContatos++];
}

void agenda_verificaReduzTamanho(Agenda *agenda){
    
}

int agenda_consultaPorEstado(Agenda *agenda, char *estado, Telefone **referencia){
    
}

void agenda_inserirPessoa(Agenda *agenda, Pessoa *p){
    
}

Pessoa *agenda_removerPessoa(Agenda *agenda, char *email){

}

void pessoa_desalocar(Pessoa *p){
    
}

int main(){
    Pessoa *p1 = pessoa_novo("Eduarda", 18, "eduarda@alunos.utfpr.edu.br");
    printf("Pessoa: %s, %d, %s\n", p1->nome, p1->idade, p1->email);
    pessoa_defineEndereco(p1, "87.309-123", 1317, "PR");
    printf("Endereco: %s, %d, %s\n", p1->endereco.cep, p1->endereco.numero, p1->endereco.estado);
    pessoa_cadastrarContato(p1, "(44)999852828", "S");
    //printf("Contato de P1: %s\nPossui WhatsApp? %c\n", p1->telefones,p1->telefones);
    return 0;
}