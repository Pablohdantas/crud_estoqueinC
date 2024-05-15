/* A proposta � fazer um controle de estoque de um armaz�m que abriga produtos diversos
para revenda. At� o momento, pensamos em implementar as op��es:

		- Adicionar produto
		- Retirar produto
		- Modificar informa��o
		- Excluir produto
		- Hist�rico de a��es
		
Isso ser� feito utilizando-se da TAD lista din�mica encadeada.
*/

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "./methods/functions.c"

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	char userNome[50];
	int opc, status;
	
	listaPont estoque = NULL;
    char id[20];
    char nome[70];
    float pesoUni;
    int quantidade;
    float precoUni;
	
	puts("========================================================================");
	puts("      BEM-VINDO AO SISTEMA DE CONTROLE DE ESTOQUE Almeida Storage!      ");
	puts("========================================================================");
	autenticacao(userNome);
	
	do{
		puts("============ CONTROLE DE ESTOQUE (menu) ============");
		puts("[1] - Adicionar produto");
		puts("[2] - Retirar produto");
		puts("[3] - Ver estoque atual");
		puts("[4] - Ver hist�rico de opera��es");
		puts("[5] - Excluir produto");
		puts("[6] - Alterar usu�rio");
		puts("[0] - Sair");
		puts("====================================================");
		printf("|| Escolha uma op��o: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 0:
				puts("<    PROGRAMA ENCERRADO   >");
				break;
				
			case 1:
				printf("Insira o ID do produto: "); // Sem espa�os...
                scanf("%s", id);
                getchar(); 

                printf("Insira o nome do produto: ");
                fgets(nome, sizeof(nome), stdin);

                printf("Insira o peso unit�rio do produto (kg): ");
                scanf("%f", &pesoUni);

                printf("Insira a quantidade a ser adicionada: ");
                scanf("%d", &quantidade);

                printf("Insira o pre�o unit�rio do produto: R$ ");
                scanf("%f", &precoUni);
                
                if(adicionar(&estoque, id, nome, pesoUni, quantidade, precoUni)){
                	puts("----------------------------------------------------");
                	printf("Produto adicionado com sucesso: %s", nome);
                    printf("ID do produto: %s\n", id);
				}
				else{
					printf("Erro ao adicionar o produto: %s\n", nome);
				}
                
                break;
                
			default:
				puts(">> Erro - Op��o inv�lida!");
				break;
		}
		puts("====================================================");
		
		system("pause");
		system("cls");
	} while(opc != 0);
	
	return 0;
}

