#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

menu()
{
	int opcao, linhas, colunas, total_mesas;
	Mesa*** mesas;
	
	do
	{
		int tam_grp;
		
		printf("\nMENU:");
		printf("\n1.ABRIR RESTAURANTE");
		printf("\n2.CHEGAR CLIENTES AO RESTAURANTE");
		printf("\n3.FINALIZAR REFEI플O/LIBERAR MESA");
		printf("\n4.DESISTIR DE ESPERAR");
		printf("\n5.REPOR PRATOS");
		printf("\n6.IMPRIMIR PILHA DE PRATOS");
		printf("\n7.IMPRIMIR FILA DE ESPERA");
		printf("\n8.IMPRIMIR OCUPA플O DAS MESAS");
	
		scanf("%d", &opcao);
		printf("OPCAO SELECIONADA: %d", opcao);	
		
		switch(opcao)
		{
			//1.ABRIR RESTAURANTE
			case 1:
				printf("INFORME COMO AS MESAS ESTAO DISTRIBUIDAS (linhas x colunas)");
				scanf("%d %d", linhas, colunas);
			
				mesas = alocaMatrizDeStructs(linhas, colunas);
				total_mesas = linhas*colunas;
				
				printf("RESTAURANTE ABERTO!");
				break;
				
			//2.CHEGAR (GRUPO DE) CLIENTES NO RESTAURANTE
			case 2:
				printf("QUANTAS PESSOAS HA NESSE GRUPO?: ");
				scanf("%d", &tam_grp);
				
				int i=0;
				
				for(int i=0; i<linhas; i++){
					for(int j=0; i<colunas; j++){
						if(mesas[i][j]->ocupada == false){
							if(tam_grp <= 4){
								mesas->q_pessoas = tam_grp;
								printf("\nO GRUPO DE CLIENTES ESTAH NA MESA %d.\n", mesas[i][j]->n_mesa);
							}else{
								mesas->q_pessoas = 4;
							}
							tam_grp -= 4;
						}
						if(tam_grp <= 0)
							printf("O GRUPO DE CLIENTES ESTAO NAS MESAS %d.\n", mesas[i][j]->n_mesa);
					}
				}
				break;
				
			//3.FINALIZAR REFEI플O/LIBERAR MESA
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
			
			//8.IMPRIMIR OCUPA플O DAS MESAS
			case 8:
				
				break;	
		}
	}
	
}
