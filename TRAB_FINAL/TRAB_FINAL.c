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

void main(){
    int option = 0;
    cliente *inicio_cliente = NULL;
    produto *inicio_produto = NULL;

    while(option != 19){
        printf("\n1 - Insercao de Cliente\n2 - Alteracao de Cliente\n3 - Consulta de Cliente\n4 - Delecao de Cliente\n\n5 - Insercao de Produto\n6 - Alteracao de Produto\n7 - Consulta de Produto\n8 - Delecao de Produto\n\n9 - Insercao de Venda\n10 - Alteracao de Venda\n11 - Consulta de Venda\n12 - Delecao de Venda\n\n14 - Listar Clientes\n15 - Listar Produtos\n16 - Listar Vendas\n17 - Checar Clientes por Gasto\n18 - Checar Estoque Baixo\n19 - Sair\n\nOpcao: ");
        scanf("%d", &option);
    }
}