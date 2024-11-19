#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"

/*-----FUNCOES MESA-----*/

/*MALLOC MATRIZ MESAS*/
Mesa** alocaMatrizDeStructs(int n_linhas, int n_colunas)
{
    int i, j, num = 1;

	//malloc da matriz dinamica
	Mesa** matriz = (Mesa**) malloc(n_linhas*sizeof(Mesa*));
	if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        return 0;
    }
	for(i=0; i<n_linhas; i++){
		matriz[i] = (Mesa*) malloc(n_colunas*sizeof(Mesa));
    	if (matriz[i] == NULL) {
        	printf("Erro ao alocar memória para as colunas.\n");
			return 0;
    	}
    }
//numera as mesas
    for(i=0; i<n_linhas; i++){
        for(j=0; j<n_colunas; j++){	
        	matriz[i][j].n_mesa = num;
        	matriz[i][j].ocupada = false;
        	matriz[i][j].q_pessoas = 0;
        	matriz[i][j].n_comanda = num;
        	num += 1;
        }
    }
    
	return matriz;
}


void imprimeMesas(Mesa** mesas, int n_linhas, int n_colunas) {
    if (mesas == NULL) {
        printf("Nenhuma mesa alocada.\n");
        return;
    }
	int i, j;	
    printf("\nEstado das Mesas:\n");
    for (i = 0; i < n_linhas; i++) {
        for (j = 0; j < n_colunas; j++) {
            Mesa m = mesas[i][j];
            printf("Mesa %2d: ", m.n_mesa);

            if (m.ocupada) {
                printf("Ocupada | Pessoas: %d | Comanda: %d\n", m.q_pessoas, m.n_comanda);
            } else {
                printf("Livre\n");
            }
        }
    }
}


int calculaQuantasMesas(int tamanho_grupo)
{
	int cheias = tamanho_grupo / 4;
	int sobra = 0;
	if(tamanho_grupo % 4 != 0)
		sobra = 1;
	int total = cheias+sobra;
}


Mesa** procuraMesasProGrupo(Mesa** mesas, int linhas, int colunas, int tamanho_grupo, int* mesas_usadas)
{
	Mesa** aux = mesas;
	int i, j, k = 0;
	 
	for(i=0; i<linhas && tamanho_grupo>0; i++){
		for(j=0; j<colunas && tamanho_grupo>0; j++){
			if(aux[i][j].ocupada == false){
				if(tamanho_grupo > 4){
					aux[i][j].q_pessoas = 4;
					aux[i][j].ocupada = true;
					mesas_usadas[k] = aux[i][j].n_mesa;
					k++;
					tamanho_grupo -= 4;								
				}else{
					aux[i][j].q_pessoas = tamanho_grupo;
					aux[i][j].ocupada = true;
					mesas_usadas[k] = aux[i][j].n_mesa;
					k++;
					tamanho_grupo = 0;
				}
			}
		}
	}
	if(tamanho_grupo>0)
		printf("\nNAO HA MESAS SUFICIENTES PARA TODO O GRUPO\n");
			
	return aux;
}


void imprimeLocalizacaoGrupo(int* mesas_usadas, int tam_grp)
{
	int i = 0;
	int tam = calculaQuantasMesas(tam_grp);
	if(tam == 1)
		printf("\nO GRUPO DE CLIENTES SE ENCONTRA NA MESA %d.\n", mesas_usadas[i]);
	else{ 
		printf("\nO GRUPO DE CLIENTES SE ENCONTRA NAS MESAS");
		for(i=0; i<tam; i++)
			printf(" %d", mesas_usadas[i]);
	}
	printf("\n");
}


void liberaMatrizDeStructs(Mesa** mesas, int n_linhas)
{
	int i;
    if (mesas != NULL) {
        for (i = 0; i < n_linhas; i++)
	        free(mesas[i]);
        free(mesas);
    }
}

