#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"
#include "pilha.h"

menu()
{
	int opcao, linhas, colunas;
	Mesa** mesas;
	Pilha** pilha;
	bool aberto = false;

	do
	{
		int tam_grp;

		printf("\nMENU:");
		printf("\n1.ABRIR RESTAURANTE");
		printf("\n2.CHEGAR CLIENTES AO RESTAURANTE");
		printf("\n3.FINALIZAR REFEICAO/LIBERAR MESA");
		printf("\n4.DESISTIR DE ESPERAR");
		printf("\n5.REPOR PRATOS");
		printf("\n6.IMPRIMIR PILHA DE PRATOS");
		printf("\n7.IMPRIMIR FILA DE ESPERA");
		printf("\n8.IMPRIMIR OCUPACAO DAS MESAS");
		printf("\n0.SAIR");

		printf("\nOPCAO SELECIONADA: ");
		scanf("%d", &opcao);

		switch(opcao)
		{

			//SAI DO MENU
			case 0:
				return 0;


			//1.ABRIR RESTAURANTE
			case 1:

				if(aberto){//confere se o restaurante ja foi aberto
					printf("\nO RESTAURANTE JA FOI ABERTO!\n");
					break;
				}

				printf("\nINFORME COMO AS MESAS ESTAO DISTRIBUIDAS (linhas x colunas): ");
				scanf("%d %d", &linhas, &colunas);

				mesas = alocaMatrizDeStructs(linhas, colunas);//malloc espaço para a matriz de mesas
				pilha = pilha_cria(linhas, colunas); //malloc pilha de pratos
				aberto = true;//restaurante está aberto

//COLOCAR PRATOS NAS MESAS!!!

				printf("\nRESTAURANTE ABERTO!\n");
				break;


			//2.CHEGAR (GRUPO DE) CLIENTES NO RESTAURANTE
			case 2:

				if(aberto == false){//se o restaurante nao foi aberto, encerra o case 2, volta pro menu
					printf("\nO RESTAURANTE AINDA NAO FOI ABERTO! DIGITE '1' A SEGUIR PARA ABRI-LO\n");
					break;
				}

				if(haMesasVagas(mesas, linhas, colunas) == 0){//confere se todas as mesas foram ocupadas, se sim, encerra case 2
					printf("\nNAO HA MESAS LIVRES PARA O GRUPO\n");
					break;
				}
//IR PRA FILA DE ESPERA!!!

				//o case 2 se inicia aqui, após conferir que o restaurante já está aberto e que há mesas sobrando
				printf("\nQUANTAS PESSOAS HA NESSE GRUPO?: ");
				scanf("%d", &tam_grp);

				int quantia = calculaQuantasMesas(tam_grp);//guarda quantia de mesas que terao de ser usadas pelo grupo
				int restante = tam_grp;//irah (a seguir) guardar o numero de intregrantes que sobrou/ficou sem mesa do grupo
				int* usadas = reAllocaVetor(1, quantia, usadas);//malloc para um vetor de int, que guarda o num das mesas usadas pelo grupo

				mesas = procuraMesasProGrupo(mesas, linhas, colunas, usadas, &restante);

				quantia = quantia - (calculaQuantasMesas(restante));//atualiza a quantia de mesas que estao sendo usadas pelo grupo
				reAllocaVetor(2, quantia, usadas);//realloca o tamanho do vetor de int

				if(quantia>0)//imprime quais as mesas o grupo estah usando
					imprimeLocalizacaoGrupo(usadas, quantia);//usadas: numero das mesas; quantia: quantas mesas(tam do vetor)

				if(restante>0)//se ter sobrado/restado clientes, informa quantos ficaram sem mesa
					printf("OBS: NAO HA MAIS MESAS VAGAS PARA %d DOS INTEGRANTES DO GRUPO\n", restante);
//IR PRA FILA DE ESPERA!!!

				free(usadas);//libera o vetor de int

				break;

			//3.FINALIZAR REFEIÇÃO/LIBERAR MESA
			case 3:

				break;

			//4.DESISTIR DE ESPERAR
			case 4:

				break;

			//5.REPOR PRATOS
			case 5:

				break;

			//6.IMPRIMIR PILHA DE PRATOS
			case 6:
                pilha_imprime(pilha);
				break;

			//7.IMPRIMIR FILA DE ESPERA
			case 7:

				break;

			//8.IMPRIMIR OCUPAÇÃO DAS MESAS
			case 8:
				if(aberto == false){//se o restaurante nao foi aberto, encerra o case 8, volta pro menu
					printf("\nO RESTAURANTE AINDA NAO FOI ABERTO! DIGITE '1' A SEGUIR PARA ABRI-LO\n");
					break;
				}

				int resposta, num;

				printf("\nCOMO VOCE DESEJA PESQUISAR A OCUPACAO DAS MESAS?\n1.POR NUMERO DA MESA\n2.TODAS AS MESAS\nOPCAO ESCOLHIDA: ");
				scanf("%d", &resposta);

				switch(resposta)
				{
					case 1://pergunta qual eh o numero da mesa e confere se resposta eh valida
						printf("\nQUAL O NUMERO DA MESA QUE SE DESEJA PESQUISAR? ");
						scanf("%d", &num);
						if(num>0 && num<= linhas*colunas)
							imprimeMesas(mesas, linhas, colunas, num);//faz impressao de uma unica mesa
						else
							printf("\nNUMERO DA MESA INFORMADO EH INVALIDO. VOLTANDO AO MENU\n");
						break;

					case 2://se eh todas as mesas, manda imprimir tudo
						imprimeMesas(mesas, linhas, colunas, 0);
						break;

					default://se resposta invalida, volta
						printf("\nOPCAO INVALIDA. VOLTANDO AO MENU\n");
				}
				break;//fim case 8

			//CASO NUMERO DIGITADO NAO SEJA NENHUMA DAS OPCOES A CIMA
			default:
				printf("\nRESPOSTA INVALIDA. SAINDO DO MENU\n");
				return 0;
		}
	}while(opcao != 0);

	liberaMatrizDeStructs(mesas, linhas);
}
