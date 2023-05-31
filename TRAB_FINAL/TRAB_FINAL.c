#include <stdio.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} data;

typedef struct {
    char rua[50];
    int numero;
    char cidade[50];
    char estado[50];
} endereco;

typedef struct node{
    long long int cpf;
    char nome[50];
    long long int telefone;
    endereco endereco;
    data data_nasc;

    struct node *prox;
    struct node *ant;
} cliente;

typedef struct {
    int codigo;
    char descricao[100];
    int estoque;
    int preco_unitario;

    struct node *prox;
    struct node *ant;
} produto;
