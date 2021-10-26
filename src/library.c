#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../hdr/library.h"

//Recebe as opções que o usuário digitar na main  e chama as funções
void opcaoSelect(int opcao, char *nomeArquivoCliente, char *nomeArquivoOnibus, Cliente vetorClientes[]){
    //Opção direcionando para a função
    if (opcao == 1)
    {
        cadastrarCliente(nomeArquivoCliente, vetorClientes);
    } else if (opcao == 2)
    {
        reservarAcento();
    } else if (opcao == 3)
    {
        venderAcento();
    } else if (opcao == 4)
    {
        alterar();
    } else if (opcao == 5)
    {
        retirarPoltronaDaReserva();
    } else if (opcao == 6)
    {
        pesquisar();
    }else if (opcao == 7)
    {
        imprimir(nomeArquivoCliente, vetorClientes);
    } else if (opcao == 8)
    {
        excluirCadastro();
    } else if( opcao == 0){
        printf("Fim.");
    } else {
        printf("Opção inválida");
    }   
}
// Verifica se o arquivo existe
int arquivoExiste(char *nomeArquivo){
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo)
    {
        fclose(arquivo);
        return 1;
    } 
    return 0;
}

// Função para realizar o cadastro de clientes.
void cadastrarCliente(char *nomeArquivoCliente, Cliente vetor[]){
    FILE *escrever = fopen("clientes.txt", "a");

    char nome[50];
    int cpf;
    int poltrona = -1;

    printf("Digite o nome: ");
    scanf(" %[^\n]", nome);
    // continua solicitando o nome do cliente até ele ser preenchido
    while (nome == NULL){
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);
        if(nome == NULL){
        printf("O campo nome precisa ser preenchido!");
        }
    }

    printf("Digite o CPF: ");
    scanf("%d", &cpf);
    // continua solicitando o cpf do cliente até ele ser preenchido
    while (cpf == ' '){
        printf("Digite o CPF: ");
        scanf("%d", &cpf);
    if(cpf == ' '){
        printf("O campo CPF precisa ser preenchido!");
        }  
    }

    fprintf(escrever, "%s %d\n", nome, cpf);

    fclose(escrever);    
};

void reservarAcento(){

}

void venderAcento(){

}

void alterar(){

}

void retirarPoltronaDaReserva(){

}

void pesquisar(){

}

void imprimir(char *nomeArquivoCliente, Cliente vetor[]){
    FILE *cliente = fopen("clientes.txt", "r");
    int imprimirOq;
    char aux;


    printf("\nImprimir:\n1 - Cadastrados.\n2 - Onibus.\n");
    scanf("%d", &imprimirOq);

    if (imprimirOq == 1)
    {
        while (fscanf(cliente, "%c", &aux) != EOF)
        {
            //cadastro
            printf("%c", aux);
        }
        
    } else {
        printf("Opção invalida.\n");
    }
    
    fclose(cliente);
}

/*void imprimirOnibus(Poltronas assentos[]){
    for(int i=0;i<40;i++){
        switch(assentos[i].status){
            case 0:
                printf("[%02d]",i);
                break;
            case 1:
                printf("[AR]");            
                break;
            case 2:
                printf("[AV]");
                break;
            default:
                printf("\n\n\nERRO NO PROGRAMA!\n\n");
                exit(1);
        }
        if( (i+1) % 10 == 0){
            printf("\n");
        }else if((i+1) % 20 == 0){
            printf("\n");
        }
    }
}*/

void criarOnibus(Poltronas assentos[]){
    for(int i=0;i<40;i++){
        assentos[i].cpfCliente = 0;
        assentos[i].status = 0;
    }
}

void excluirCadastro(){
}


