#include <stdio.h>
#include <stdlib.h>

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

void liberaMatrizDeStructs(Mesa** mesas, int n_linhas)
{
	int i;
    if (mesas != NULL) {
        for (i = 0; i < n_linhas; i++)
	        free(mesas[i]);
        free(mesas);
    }
}

