#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"

menu()
{
	int opcao, linhas, colunas, total_mesas, aux;
	Mesa** mesas;
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
				if(aberto){
					printf("\nO RESTAURANTE JA FOI ABERTO!\n");
					break;
				}
				
				printf("\nINFORME COMO AS MESAS ESTAO DISTRIBUIDAS (linhas x colunas): ");
				scanf("%d %d", &linhas, &colunas);

				mesas = alocaMatrizDeStructs(linhas, colunas);
				total_mesas = linhas*colunas;
				aberto = true;
				
				printf("\nRESTAURANTE ABERTO!\n");
				break;
				
			//2.CHEGAR (GRUPO DE) CLIENTES NO RESTAURANTE
			case 2:
				if(aberto == false){
					printf("\nO RESTAURANTE AINDA NAO FOI ABERTO! DIGITE '1' A SEGUIR PARA ABRI-LO\n");
					break;
				}
				
				if(haMesasVagas(mesas, linhas, colunas) == 0){
					printf("\nNAO HA MESAS LIVRES PARA O GRUPO\n");
					break;
				}
					
				printf("\nQUANTAS PESSOAS HA NESSE GRUPO?: ");
				scanf("%d", &tam_grp);
				
				int tam = calculaQuantasMesas(tam_grp);
				int restante = tam_grp;

				int* usadas = reAllocaVetor(1, tam, usadas);
            
				mesas = procuraMesasProGrupo(mesas, linhas, colunas, usadas, &restante);

				int tantas = tam - (calculaQuantasMesas(restante));
				
				if(tantas!=0)
					imprimeLocalizacaoGrupo(usadas, tantas);
				
				if(restante>0){
					printf("OBS: NAO HA MAIS MESAS VAGAS PARA %d DOS INTEGRANTES DO GRUPO\n", restante);
					reAllocaVetor(2, tantas, usadas);
  				}
				
				free(usadas);
				
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
				
				break;
			
			//7.IMPRIMIR FILA DE ESPERA
			case 7:
				
				break;
			
			//8.IMPRIMIR OCUPAÇÃO DAS MESAS
			case 8:
				imprimeMesas(mesas, linhas, colunas);
				break;	
			
			default:
				printf("\nRESPOSTA INVALIDA. ENCERRANDO\n");
				return 0;
		}
	}while(opcao != 0);
	
	liberaMatrizDeStructs(mesas, linhas);
}
