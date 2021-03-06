/*                                                                  *
 *                                                                  *
 *          League of Bus - Sistema de gerenciamento de ônibus      *
 *                                                                  *
 *          Integrantes:                                            *
 *          - João Pedro Gaffuri                                    *
 *          - Nicolas Battisti                                      *
 *          - Lucas Vilain Matras                                   *
 *                                                                  *
 *                                                                  */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "../hdr/library.h"


int main(){
    int opcaoSelecionada;
    char inicio, zerar[10];
    Cliente Clientes[TAMC];
    Poltrona Poltronas[TAMP];
    
    // Caso deseja resetar o sistema, o usuário deve digitar 0 e confirmar a ação
    warningMessage("Digite 0 para zerar vetores ou outra tecla para continuar... ");
    scanf("%c",&inicio);
    
    if(inicio == '0'){
        printf("Tem certeza? Digite ZERAR\n\n");
        scanf("%s",zerar);
        if(strcmp(zerar,"ZERAR") == 0){
            zerarVetores(Clientes,Poltronas);
            salvarArquivo(Clientes,Poltronas);
            printf("\nZerado com sucesso");
        }
    }

    carregarArquivo(Clientes,Poltronas);
    printf("\nArquivo carregado com sucesso\n\n");

    // printf("\nClientes:\n");
    // for(int i=0;i<TAMC;i++){
    //     printf("%s\n", Clientes[i].nome);
    // }

    // printf("\nPoltronas:\n");
    // for(int i=0;i<TAMP;i++){
    //     printf("%d\n", Poltronas[i].status);
    // }    

    //Menu de opções
    do{
        printf("\n\n\t\tMenu:\n"
        "---------------------------------\n"
        "[1] Cadastrar Cliente.\n"
        "[2] Reservar assento.\n"
        "[3] Vender assento.\n"
        "[4] Alterar assento.\n"
        "[5] Retirar poltrona da reserva.\n"
        "[6] Pesquisar cliente.\n"
        "[7] Imprimir.\n"
        "[8] Excluir cadastro.\n"
        "[0] Sair.\n\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcaoSelecionada);
        if(opcaoSelecionada >=0 || opcaoSelecionada<=9){
            opcaoSelect(opcaoSelecionada, Clientes, Poltronas);
        
        } else{
            printf("\n\nOpção invalida.\n\n");
        }
        
    } while (opcaoSelecionada != 0); 
 
}