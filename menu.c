#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "mesa.h"

menu()
{
	int opcao, linhas, colunas, total_mesas, aux;
	Mesa** mesas;
	
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
				printf("\nINFORME COMO AS MESAS ESTAO DISTRIBUIDAS (linhas x colunas): ");
				scanf("%d %d", &linhas, &colunas);

				mesas = alocaMatrizDeStructs(linhas, colunas);
				total_mesas = linhas*colunas;
				
				printf("\nRESTAURANTE ABERTO!\n");
				break;
				
			//2.CHEGAR (GRUPO DE) CLIENTES NO RESTAURANTE
			case 2:
				printf("\nQUANTAS PESSOAS HA NESSE GRUPO?: ");
				scanf("%d", &tam_grp);
				
				int i, j, k = 0;
				int restante = tam_grp;

				for(i=0; i<linhas && restante>0; i++){
					for(j=0; j<colunas && restante>0; j++){
						if(mesas[i][j].ocupada == false){
							if(tam_grp > 4){
								mesas[i][j].q_pessoas = 4;
								mesas[i][j].ocupada = true;
								printf("\nO GRUPO DE CLIENTES ESTAH NA MESA %d.\n", mesas[i][j].n_mesa);
								restante -= 4;								
							}else{
								mesas[i][j].q_pessoas = tam_grp;
								mesas[i][j].ocupada = true;
								printf("\nO GRUPO DE CLIENTES ESTAH NA MESA %d.\n", mesas[i][j].n_mesa);
								restante -= tam_grp;
							}
						}
					}
				}
				if(restante>0)
					printf("\nNAO HA MESAS SUFICIENTES\n");
				
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
	
}
