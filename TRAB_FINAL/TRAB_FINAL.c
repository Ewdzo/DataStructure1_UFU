#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

typedef struct client{
    long long int cpf;
    char nome[50];
    long long int telefone;
    endereco endereco;
    data data_nasc;

    struct client *prox;
    struct client *ant;
} cliente;

typedef struct product{
    int codigo;
    char descricao[100];
    int estoque;
    int preco_unitario;

    struct product *prox;
    struct product *ant;
} produto;

typedef struct transaction{
    int codVenda;
    long long int cpf_cliente;
    int cod_produto;
    int qtd_comprada;
    
    struct transacao *prox;
    struct transacao *ant;
} venda;

cliente *inicio_cliente = NULL;
produto *inicio_produto = NULL;
venda *inicio_venda = NULL;

void insereCliente(cliente *clienteNovo, long long int cpf, char nome[50], long long int telefone, endereco endereco_cliente, data data_nasc){
    cliente *aux;

    clienteNovo->cpf = cpf;
    strcpy(clienteNovo->nome, nome);
    clienteNovo->telefone = telefone;
    clienteNovo->endereco = endereco_cliente;
    clienteNovo->data_nasc = data_nasc;
    clienteNovo->prox = NULL;
    
    if(inicio_cliente == NULL) inicio_cliente = clienteNovo;
    else {
        aux = inicio_cliente;

        while(aux->prox != NULL){ 
            if(aux->cpf == cpf){
                printf("\n== CPF ja registrado ==\n");
                return;
            }
            aux = aux->prox; 
        }
        aux->prox = clienteNovo;
    }

    printf("\n\n== Cliente Registrado ==");
}

void alterarCliente(long long int cpf_busca, char nome[50], long long int telefone, endereco endereco_cliente, data data_nasc){
    cliente *aux; 

    if(inicio_cliente == NULL) printf("\n\n== Não há Clientes Cadastrados ==\n\n");
    else {
        aux = inicio_cliente;

        while(aux->prox != NULL || aux->cpf == cpf_busca){ 
            if(aux->cpf == cpf_busca){
                strcpy(aux->nome, nome);
                aux->telefone = telefone;
                aux->endereco = endereco_cliente;
                aux->data_nasc = data_nasc;
                printf("\n\n== Cliente de CPF %d Alterado ==\n\n", cpf_busca);
                return;
            }
            aux = aux->prox; 
        }
    }
}
void main(){
    int option = 0;

    while(option != 18){
        printf("\n\n1 - Insercao de Cliente\n2 - Alteracao de Cliente\n3 - Consulta de Cliente\n4 - Delecao de Cliente\n\n5 - Insercao de Produto\n6 - Alteracao de Produto\n7 - Consulta de Produto\n8 - Delecao de Produto\n\n9 - Insercao de Venda\n10 - Alteracao de Venda\n11 - Consulta de Venda\n12 - Delecao de Venda\n\n13 - Listar Clientes\n14 - Listar Produtos\n15 - Listar Vendas\n16 - Checar Clientes por Gasto\n17 - Checar Estoque Baixo\n18 - Sair\n\nOpcao: ");
        
        scanf("%d", &option);
        setbuf(stdin, NULL);

        if(option == 1){
            cliente *aux_cliente;
            long long int cpf_aux, telefone_aux;
            char nome_aux[50];
            endereco endereco_cliente_aux;
            data data_nasc_aux;

            printf("\nInsira o CPF: ");
            setbuf(stdin, NULL);
            scanf("%lld", &cpf_aux);

            printf("\nInsira o Nome: ");
            setbuf(stdin, NULL);
            gets(nome_aux);

            printf("\nInsira o Telefone: ");
            setbuf(stdin, NULL);
            scanf("%lld", &telefone_aux);

            printf("\nInsira a Rua do Endereco: ");
            setbuf(stdin, NULL);
            gets(endereco_cliente_aux.rua);

            printf("\nInsira o Numero do Endereco: ");
            setbuf(stdin, NULL);
            scanf("%d", &(endereco_cliente_aux.numero));

            printf("\nInsira a Cidade do Endereco: ");
            setbuf(stdin, NULL);
            gets(endereco_cliente_aux.cidade);

            printf("\nInsira o Estado do Endereco: ");
            setbuf(stdin, NULL);
            gets(endereco_cliente_aux.estado);

            printf("\nInsira o Dia do Nascimento (DD/MM/AAAA): ");
            setbuf(stdin, NULL);
            scanf("%d/%d/%d", &(data_nasc_aux.dia), &(data_nasc_aux.mes), &(data_nasc_aux.ano));
            setbuf(stdin, NULL);

            aux_cliente = (cliente *)malloc(sizeof(cliente));
 
            if(!aux_cliente) printf("\nOut of Memory");
            else insereCliente(aux_cliente, cpf_aux, nome_aux, telefone_aux, endereco_cliente_aux, data_nasc_aux);
        }
        else if(option == 2){
            long long int cpf_aux, telefone_aux;
            char nome_aux[50];
            endereco endereco_cliente_aux;
            data data_nasc_aux;

            printf("\nInsira o CPF do Cliente a Alterar: ");
            setbuf(stdin, NULL);
            scanf("%lld", &cpf_aux);

            printf("\nInsira o Novo Nome: ");
            setbuf(stdin, NULL);
            gets(nome_aux);

            printf("\nInsira o Novo Telefone: ");
            setbuf(stdin, NULL);
            scanf("%lld", &telefone_aux);

            printf("\nInsira a Nova Rua do Endereco: ");
            setbuf(stdin, NULL);
            gets(endereco_cliente_aux.rua);

            printf("\nInsira o Novo Numero do Endereco: ");
            setbuf(stdin, NULL);
            scanf("%d", &(endereco_cliente_aux.numero));

            printf("\nInsira a Nova Cidade do Endereco: ");
            setbuf(stdin, NULL);
            gets(endereco_cliente_aux.cidade);

            printf("\nInsira o Novo Estado do Endereco: ");
            setbuf(stdin, NULL);
            gets(endereco_cliente_aux.estado);

            printf("\nInsira o Novo Dia do Nascimento (DD/MM/AAAA): ");
            setbuf(stdin, NULL);
            scanf("%d/%d/%d", &(data_nasc_aux.dia), &(data_nasc_aux.mes), &(data_nasc_aux.ano));
            setbuf(stdin, NULL);

            alterarCliente(cpf_aux, nome_aux, telefone_aux, endereco_cliente_aux, data_nasc_aux);
        }
        else if(option == 3){}
        else if(option == 4){}
        else if(option == 5){}
        else if(option == 6){}
        else if(option == 7){}
        else if(option == 8){}
        else if(option == 9){}
        else if(option == 10){}
        else if(option == 11){}
        else if(option == 12){}
        else if(option == 13){}
        else if(option == 14){}
        else if(option == 15){}
        else if(option == 16){}
        else if(option == 17){}
    }
}