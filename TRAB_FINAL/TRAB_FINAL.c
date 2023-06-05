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
    float preco_unitario;

    struct product *prox;
    struct product *ant;
} produto;

typedef struct transaction{
    int codVenda;
    long long int cpf_cliente;
    int cod_produto;
    int qtd_comprada;
    
    struct transaction *prox;
    struct transaction *ant;
} venda;

cliente *inicio_cliente = NULL;
produto *inicio_produto = NULL;
venda *inicio_venda = NULL;

void inserirCliente(cliente *clienteNovo, long long int cpf, char nome[50], long long int telefone, endereco endereco_cliente, data data_nasc){
    cliente *aux;

    clienteNovo->cpf = cpf;
    strcpy(clienteNovo->nome, nome);
    clienteNovo->telefone = telefone;
    clienteNovo->endereco = endereco_cliente;
    clienteNovo->data_nasc = data_nasc;
    clienteNovo->prox = NULL;
    clienteNovo->ant = NULL;
    
    if(inicio_cliente == NULL) inicio_cliente = clienteNovo;
    else {
        aux = inicio_cliente;

        if(aux->cpf == cpf){
            printf("\n== CPF Ja Registrado ==\n");
            return;
        }

        while(aux->prox != NULL){ 
            if(aux->cpf == cpf){
                printf("\n== CPF Ja Registrado ==\n");
                return;
            }
            clienteNovo->ant = aux;
            aux = aux->prox; 
        }
        aux->prox = clienteNovo;
    }

    printf("\n\n== Cliente Registrado ==");
}

void alterarCliente(long long int cpf_busca, char nome[50], long long int telefone, endereco endereco_cliente, data data_nasc){
    cliente *aux; 

    if(inicio_cliente == NULL) printf("\n\n== Nao ha Clientes Cadastrados ==\n");
    else {
        aux = inicio_cliente;

        while(aux != NULL){ 
            if(aux->cpf == cpf_busca){
                strcpy(aux->nome, nome);
                aux->telefone = telefone;
                aux->endereco = endereco_cliente;
                aux->data_nasc = data_nasc;
                printf("\n\n== Cliente de CPF %lld Alterado ==\n", cpf_busca);
                return;
            }
            aux = aux->prox; 
        }
    }

    printf("\n\n== Alteracao de Cliente de CPF %lld Falhou ==\n", cpf_busca);
}

void consultarCliente(long long int cpf_busca){
    cliente *aux; 
    if(inicio_cliente == NULL) printf("\n\n== Nao ha Clientes Cadastrados ==\n");
    else {
        aux = inicio_cliente;

        while(aux != NULL){ 
            if(aux->cpf == cpf_busca){
                printf("\n\n== Cliente de CPF %lld ==\n", cpf_busca);
                printf("\nNome: %s", aux->nome);
                printf("\nTelefone: %lld", aux->telefone);
                printf("\nEndereco: %s - %d - %s - %s", (aux->endereco).rua, (aux->endereco).numero, (aux->endereco).cidade, (aux->endereco).estado);
                printf("\nData de Nascimento: %d/%d/%d\n", (aux->data_nasc).dia, (aux->data_nasc).mes, (aux->data_nasc).ano);
                return;
            }
            aux = aux->prox; 
        }
    }
}

void removerCliente(long long int cpf_busca){
    cliente *aux, *p; 

    if(inicio_cliente == NULL) printf("\n\n== Nao ha Clientes Cadastrados ==\n");
    else {
        aux = inicio_cliente;
        p = aux;

        while(aux != NULL){ 
            if(aux->cpf == cpf_busca){
                (p)->prox = aux->prox;

                if(aux->ant == NULL) inicio_cliente = NULL;
                free(aux);

                printf("\n\n== Cliente de CPF %lld Removido ==\n", cpf_busca);
                return;
            }
            p = aux;
            aux = aux->prox; 
        }
    }

    printf("\n\n== Remocao de Cliente de CPF %lld Falhou ==\n", cpf_busca);
}

void listarClientes(){
    cliente *aux; 
    if(inicio_cliente == NULL) printf("\n\n== Nao ha Clientes Cadastrados ==\n");
    else {
        aux = inicio_cliente;

        while(aux != NULL){ 
            printf("\nCPF: %lld", aux->cpf);
            printf("\nNome: %s", aux->nome);
            printf("\nTelefone: %lld", aux->telefone);
            printf("\nEndereco: %s - %d - %s - %s", (aux->endereco).rua, (aux->endereco).numero, (aux->endereco).cidade, (aux->endereco).estado);
            printf("\nData de Nascimento: %d/%d/%d\n", (aux->data_nasc).dia, (aux->data_nasc).mes, (aux->data_nasc).ano);
            aux = aux->prox; 
        }
    }
};

void inserirProduto(produto *produtoNovo, int codigo, char descricao[100], int estoque, float preco_unitario){
    produto *aux;

    produtoNovo->codigo = codigo;
    strcpy(produtoNovo->descricao, descricao);
    produtoNovo->estoque = estoque;
    produtoNovo->preco_unitario = preco_unitario;
    produtoNovo->prox = NULL;
    produtoNovo->ant = NULL;
    
    if(inicio_produto == NULL) inicio_produto = produtoNovo;
    else {
        aux = inicio_produto;
       
        if(aux->codigo == codigo){
            printf("\n== Codigo Ja Registrado ==\n");
            return;
        }

        while(aux->prox != NULL){ 
            if(aux->codigo == codigo){
                printf("\n== Codigo Ja Registrado ==\n");
                return;
            }
            produtoNovo->ant = aux;
            aux = aux->prox; 
        }
        aux->prox = produtoNovo;
    }

    printf("\n\n== Produto Registrado ==");
}

void alterarProduto(int codigo_busca, char descricao[100], int estoque, float preco_unitario){
    produto *aux; 

    if(inicio_produto == NULL) printf("\n\n== Nao ha Clientes Cadastrados ==\n");
    else {
        aux = inicio_produto;

        while(aux != NULL){ 
            if(aux->codigo == codigo_busca){
                strcpy(aux->descricao, descricao);
                aux->estoque = estoque;
                aux->preco_unitario = preco_unitario;
                printf("\n\n== Produto de Codigo %d Alterado ==\n", codigo_busca);
                return;
            }
            aux = aux->prox; 
        }
    }

    printf("\n\n== Alteracao de Produto de Codigo %d Fracassou ==\n", codigo_busca);
}

void consultarProduto(int codigo_busca){
    produto *aux; 
    if(inicio_produto == NULL) printf("\n\n== Nao ha Produtos Cadastrados ==\n");
    else {
        aux = inicio_produto;

        while(aux != NULL){ 
            if(aux->codigo == codigo_busca){
                printf("\n\n== Produto de Codigo %d ==\n", codigo_busca);
                printf("\nDescricao: %s", aux->descricao);
                printf("\nEstoque: %d", aux->estoque);
                printf("\nPreco Unitario: %0.2f\n", aux->preco_unitario);
                return;
            }
            aux = aux->prox; 
        }
    }
}

void removerProduto(int codigo_busca){
    produto *aux, *p; 

    if(inicio_produto == NULL) printf("\n\n== Nao ha Produtos Cadastrados ==\n");
    else {
        aux = inicio_produto;
        p = aux;

        while(aux != NULL){ 
            if(aux->codigo == codigo_busca){
                (p)->prox = aux->prox;

                if(aux->ant == NULL) inicio_produto = NULL;
                free(aux);

                printf("\n\n== Produto de Codigo %d Removido ==\n", codigo_busca);
                return;
            }
            p = aux;
            aux = aux->prox; 
        }
    }

    printf("\n\n== Remocao de Produto de Codigo %d Fracassou ==\n", codigo_busca);
}

void listarProdutos(){
    produto *aux; 
    if(inicio_produto == NULL) printf("\n\n== Nao ha Produtos Cadastrados ==\n");
    else {
        aux = inicio_produto;

        while(aux != NULL){ 
            printf("\nCodigo: %d", aux->codigo);
            printf("\nDescricao: %s", aux->descricao);
            printf("\nEstoque: %d", aux->estoque);
            printf("\nPreco Unitario: %0.2f\n", aux->preco_unitario);
            aux = aux->prox; 
        }
    }
};

void estoqueProduto(int estoque){
    produto *aux; 
    if(inicio_produto == NULL) printf("\n\n== Nao ha Produtos Cadastrados ==\n");
    else {
        aux = inicio_produto;

        while(aux != NULL){ 
            if(aux->estoque < estoque){
                printf("\nCodigo: %d", aux->codigo);
                printf("\nDescricao: %s", aux->descricao);
                printf("\nEstoque: %d", aux->estoque);
                printf("\nPreco Unitario: %0.2f\n", aux->preco_unitario);
            }
            aux = aux->prox; 
        }
    }
}

void inserirVenda(venda *vendaNova, int codVenda, long long int cpf_cliente, int cod_produto, int qtd_comprada){
    venda *aux;
    cliente *cliente_aux;
    produto *produto_aux;

    int clienteConfirmado = 0, produtoConfirmado = 0;

    if(inicio_cliente == NULL || inicio_produto == NULL) {
        printf("\n\n== Nao Existem Clientes ou Produtos Cadastrados ==");
        return;
    }
    else {
        cliente_aux = inicio_cliente;
        produto_aux = inicio_produto;

        while(cliente_aux != NULL){ 
            if(cliente_aux->cpf == cpf_cliente) clienteConfirmado = 1;
            cliente_aux = cliente_aux->prox; 
        }

        while(produto_aux != NULL){ 
            if(produto_aux->codigo == cod_produto) {
                if(produto_aux->estoque < qtd_comprada) {
                    printf("\n\n== Quantidade Insuficiente Em Estoque ==");
                    return;
                }
                produto_aux->estoque -= qtd_comprada;
                produtoConfirmado = 1;
            }
            produto_aux = produto_aux->prox; 
        }

        if(!clienteConfirmado || !produtoConfirmado){
            printf("\n\n=== Cliente ou Produto Nao Encontrado ===");
            return;
        }

        vendaNova->codVenda = codVenda;
        vendaNova->cpf_cliente = cpf_cliente;
        vendaNova->cod_produto = cod_produto;
        vendaNova->qtd_comprada = qtd_comprada;
        vendaNova->prox = NULL;
        vendaNova->ant = NULL;

        if(inicio_venda == NULL) inicio_venda = vendaNova;
        else {
            aux = inicio_venda;

            if(aux->codVenda == codVenda){
                printf("\n== Codigo de Venda Ja Registrado ==\n");
                return;
            }

            while(aux->prox != NULL){ 
                if(aux->codVenda == codVenda){
                    printf("\n== Codigo de Venda Ja Registrado ==\n");
                    return;
                }
                vendaNova->ant = aux;
                aux = aux->prox; 
            }
            aux->prox = vendaNova;
        }
    }

    printf("\n\n== Venda Registrada ==");
}

void alterarVenda(int codVenda_busca, long long int cpf_cliente, int cod_produto, int qtd_comprada){
    venda *aux;

    if(inicio_venda == NULL) {
        printf("\n\n== Nao Existem Vendas Cadastradas ==");
        return;
    }
    else {
       aux = inicio_venda;

        while(aux != NULL){
            if(aux->codVenda == codVenda_busca){
                int clienteConfirmado = 0, produtoConfirmado = 0;
                cliente *cliente_aux = inicio_cliente;
                produto *produto_aux = inicio_produto;

                while(cliente_aux != NULL){ 
                    if(cliente_aux->cpf == cpf_cliente) clienteConfirmado = 1;
                    cliente_aux = cliente_aux->prox; 
                }

                while(produto_aux != NULL){ 
                    if(produto_aux->codigo == cod_produto) produtoConfirmado = 1;
                    produto_aux = produto_aux->prox; 
                }

                if(!clienteConfirmado || !produtoConfirmado){
                    printf("\n\n=== Cliente ou Produto Inserido Nao Encontrado ===");
                    return;
                }     

                produto_aux = inicio_produto;
                while(produto_aux != NULL){ 
                    if(produto_aux->codigo == aux->cod_produto && produto_aux->codigo != cod_produto) produto_aux->estoque += aux->qtd_comprada;
                    produto_aux = produto_aux->prox;
                }

                produto_aux = inicio_produto;
                while(produto_aux != NULL && produtoConfirmado){ 
                    if(produto_aux->codigo == aux->cod_produto && produto_aux->codigo == cod_produto) produto_aux->estoque += aux->qtd_comprada;
                    if(produto_aux->codigo == cod_produto) {
                        if(produto_aux->estoque < qtd_comprada) {
                            printf("\n\n== Quantidade Insuficiente Em Estoque ==");
                            return;
                        }

                        produto_aux->estoque -= qtd_comprada;
                    }
                    produto_aux = produto_aux->prox; 
                }

                aux->cpf_cliente = cpf_cliente;
                aux->cod_produto = cod_produto;
                aux->qtd_comprada = qtd_comprada;
                printf("\n\n== Venda de Codigo %d Alterada ==", codVenda_busca);
                return;
            }
            aux = aux->prox;
        }
    }

    printf("\n\n== Alteracao de Venda de Codigo %d Fracassou ==", codVenda_busca);
}

void consultarVenda(int codVenda_busca){
    venda *aux; 
    if(inicio_venda == NULL) printf("\n\n== Nao ha Vendas Cadastradas ==\n");
    else {
        aux = inicio_venda;

        while(aux != NULL){ 
            if(aux->codVenda == codVenda_busca){
                printf("\n\n== Produto de Codigo %d ==\n", codVenda_busca);
                printf("\nCPF do Cliente: %lld", aux->cpf_cliente);
                printf("\nCodigo do Produto: %d", aux->cod_produto);
                printf("\nQuantidade Comprada: %d\n", aux->qtd_comprada);
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
 
            if(!aux_cliente) printf("\nFalta de Memoria");
            else inserirCliente(aux_cliente, cpf_aux, nome_aux, telefone_aux, endereco_cliente_aux, data_nasc_aux);
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
        else if(option == 3){
            long long int cpf_aux;
            
            printf("\nInsira o CPF do Cliente a Buscar: ");
            setbuf(stdin, NULL);
            scanf("%lld", &cpf_aux);

            consultarCliente(cpf_aux);
        }
        else if(option == 4){
            long long int cpf_aux;
            
            printf("\nInsira o CPF do Cliente a Remover: ");
            setbuf(stdin, NULL);
            scanf("%lld", &cpf_aux);

            removerCliente(cpf_aux);
        }
        else if(option == 5){
            produto *aux_produto;
            int codigo_aux, estoque_aux;
            char descricao_aux[100];
            float preco_unitario_aux;

            printf("\nInsira o Codigo: ");
            setbuf(stdin, NULL);
            scanf("%d", &codigo_aux);

            printf("\nInsira a Descricao: ");
            setbuf(stdin, NULL);
            gets(descricao_aux);

            printf("\nInsira o Estoque: ");
            setbuf(stdin, NULL);
            scanf("%d", &estoque_aux);

            printf("\nInsira o Preco Unitario: ");
            setbuf(stdin, NULL);
            scanf("%f", &preco_unitario_aux);

            aux_produto = (produto *)malloc(sizeof(produto));
 
            if(!aux_produto) printf("\nFalta de Memoria");
            else inserirProduto(aux_produto, codigo_aux, descricao_aux, estoque_aux, preco_unitario_aux);
        }
        else if(option == 6){
            produto *aux_produto;
            int codigo_aux, estoque_aux;
            char descricao_aux[100];
            float preco_unitario_aux;

            printf("\nInsira o Codigo do Produto a Alterar: ");
            setbuf(stdin, NULL);
            scanf("%d", &codigo_aux);

            printf("\nInsira a Nova Descricao: ");
            setbuf(stdin, NULL);
            gets(descricao_aux);

            printf("\nInsira o Novo Estoque: ");
            setbuf(stdin, NULL);
            scanf("%d", &estoque_aux);

            printf("\nInsira o Novo Preco Unitario: ");
            setbuf(stdin, NULL);
            scanf("%f", &preco_unitario_aux);

            aux_produto = (produto *)malloc(sizeof(produto));
 
            if(!aux_produto) printf("\nFalta de Memoria");
            else alterarProduto(codigo_aux, descricao_aux, estoque_aux, preco_unitario_aux);
        }
        else if(option == 7){
            int codigo_aux;
            
            printf("\nInsira o Codigo do Produto a Buscar: ");
            setbuf(stdin, NULL);
            scanf("%d", &codigo_aux);

            consultarProduto(codigo_aux);
        }
        else if(option == 8){
            int codigo_aux;
            
            printf("\nInsira o Codigo do Produto a Remover: ");
            setbuf(stdin, NULL);
            scanf("%d", &codigo_aux);

            removerProduto(codigo_aux);
        }
        else if(option == 9){
            venda *aux_venda;
            int codVenda_aux, codProduto_aux, qtd_comprada_aux;
            long long int cpf_cliente_aux;

            printf("\nInsira o Codigo da Venda: ");
            setbuf(stdin, NULL);
            scanf("%d", &codVenda_aux);

            printf("\nInsira o CPF do Cliente: ");
            setbuf(stdin, NULL);
            scanf("%lld", &cpf_cliente_aux);

            printf("\nInsira o Codigo do Produto: ");
            setbuf(stdin, NULL);
            scanf("%d", &codProduto_aux);

            printf("\nInsira a Quantidade Comprada do Produto: ");
            setbuf(stdin, NULL);
            scanf("%d", &qtd_comprada_aux);

            aux_venda = (venda *)malloc(sizeof(venda));
 
            if(!aux_venda) printf("\nFalta de Memoria");
            else inserirVenda(aux_venda, codVenda_aux, cpf_cliente_aux, codProduto_aux, qtd_comprada_aux);
        }
        else if(option == 10){
            int codVenda_aux, codProduto_aux, qtd_comprada_aux;
            long long int cpf_cliente_aux;

            printf("\nInsira o Codigo da Venda A Alterar: ");
            setbuf(stdin, NULL);
            scanf("%d", &codVenda_aux);

            printf("\nInsira o CPF do Novo Cliente: ");
            setbuf(stdin, NULL);
            scanf("%lld", &cpf_cliente_aux);

            printf("\nInsira o Codigo do Novo Produto: ");
            setbuf(stdin, NULL);
            scanf("%d", &codProduto_aux);

            printf("\nInsira a Nova Quantidade Comprada do Produto: ");
            setbuf(stdin, NULL);
            scanf("%d", &qtd_comprada_aux);

            alterarVenda(codVenda_aux, cpf_cliente_aux, codProduto_aux, qtd_comprada_aux);
        }
        else if(option == 11){
            int codVenda_aux;
            
            printf("\nInsira o Codigo da Venda a Buscar: ");
            setbuf(stdin, NULL);
            scanf("%d", &codVenda_aux);

            consultarVenda(codVenda_aux);
        }
        else if(option == 12){}
        else if(option == 13) listarClientes();
        else if(option == 14) listarProdutos();
        else if(option == 15){}
        else if(option == 16){}
        else if(option == 17){
            int estoque_aux;
            
            printf("\nInsira o Valor Maximo de Estoque a Checar: ");
            setbuf(stdin, NULL);
            scanf("%d", &estoque_aux);

            estoqueProduto(estoque_aux);
        }
    }
}