#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"

/*-----FUNCOES MESA-----*/

/*CASE 1: MALLOC MATRIZ MESAS*/
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

/*MALLOC E REALLOC DO VETOR DAS MESAS USADAS*/
int* reAllocaVetor(int n, int tam, int* vetor)
{
	if(n==1){
		int* v = malloc(tam * sizeof(int));
    	if (v != NULL)
   			return v;
	}
	if(n==2){
		int* v = vetor;
   		v = realloc(vetor, tam * sizeof(int));
		if (v != NULL)
        	return v;
	}
}

/*RECEBE MATRIZ DAS MESAS E RETORNA QUANTAS MESAS ESTAO VAGAS*/
int haMesasVagas(Mesa** mesas, int linhas, int colunas)
{
	int i, j;
	int vagas = linhas*colunas;
	Mesa** aux = mesas;
	
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			if(aux[i][j].ocupada)
				vagas -= 1;	
		}
	}
	return vagas;
}

/*CASE 8: IMPRIME AS INFOS DE CADA MESA DO RESTAURANTE*/
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

/*CALCULA QUANTAS MESAS SERAO NECESSARIAS PARA O GRUPO*/
int calculaQuantasMesas(int tamanho_grupo)
{
	int cheias = tamanho_grupo / 4;
	int sobra = 0;
	if(tamanho_grupo % 4 != 0)
		sobra = 1;
	int total = cheias+sobra;
}

/*CASE 2: OCUPA AS MESAS QUE ESTAO LIVRES, ATUALIZA A MATRIZ, A VAR RESTANTE(DE CLIENTES) E O TAMANHO DO VET DO NUMERO DAS MESAS USADAS*/
Mesa** procuraMesasProGrupo(Mesa** mesas, int linhas, int colunas, int* mesas_usadas, int* restante)
{
	Mesa** aux = mesas;
	int i, j, k = 0;
	
	for(i=0; i<linhas && *restante>0; i++){
		for(j=0; j<colunas && *restante>0; j++){
			if(aux[i][j].ocupada == false){
				if(*restante > 4){
					aux[i][j].q_pessoas = 4;
					aux[i][j].ocupada = true;
					*restante -= 4;								
				}else{
					aux[i][j].q_pessoas = *restante;
					aux[i][j].ocupada = true;
					*restante = 0;
				}
				mesas_usadas[k] = aux[i][j].n_mesa;
				k++;
			}
		}
	}
				
	return aux;
}

/*IMPRIME O NUMERO DAS MESAS EM QUE O GRUPO SE ENCONTRA*/
void imprimeLocalizacaoGrupo(int* mesas_usadas, int tantas)
{
	int i = 0;
	
	if(tantas > 1){
		printf("\nO GRUPO DE CLIENTES SE ENCONTRA NAS MESAS");
		for(i=0; i<tantas; i++)
			printf(" %d", mesas_usadas[i]);
	}
	else
		printf("\nO GRUPO DE CLIENTES SE ENCONTRA NA MESA %d.", mesas_usadas[i]);
	printf("\n");
}

/*LIBERA MATRIZ MESAS*/
void liberaMatrizDeStructs(Mesa** mesas, int n_linhas)
{
	int i;
    if (mesas != NULL) {
        for (i = 0; i < n_linhas; i++)
	        free(mesas[i]);
        free(mesas);
    }
}
