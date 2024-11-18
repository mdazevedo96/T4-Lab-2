#include <stdio.h>
#include <stdlib.h>

#include "mesa.h"

/*-----FUNCOES MESA-----*/

/*MALLOC MATRIZ MESAS*/
Mesa*** alocaMatrizDeStructs(int n_linhas, int n_colunas)
{
	//malloc da matriz dinamica
	Mesa*** matriz = (Mesa***) malloc(n_linhas*sizeof(Mesa**));
	for(int i=0; i<n_linhas; i++)
		matriz[i] = (Mesa**) malloc(n_colunas*sizeof(Mesa*));
	//malloc da struct (na matriz)
	for(int i=0; i<n_linhas; i++){
		for(int j=0; j<n_colunas; j++)
			matriz[i][j] = (Mesa*) malloc(sizeof(Mesa));
	}
	return matriz;
}


