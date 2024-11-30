#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mesa.h"

/*-----FUNCOES MESA-----*/

/*CASE 1: MALLOC MATRIZ MESAS*/
Mesa** alocaMatrizDeStructs(int linhas, int colunas)
{
    int i, j;
	int num = 1;//numera as mesas e as comandas

//malloc da matriz dinamica
	Mesa** matriz = (Mesa**) malloc(linhas*sizeof(Mesa*));
	if (matriz == NULL) {
        printf("Erro ao alocar memória para as linhas.\n");
        return 0;
    }
	for(i=0; i<linhas; i++){
		matriz[i] = (Mesa*) malloc(colunas*sizeof(Mesa));
    	if (matriz[i] == NULL) {
        	printf("Erro ao alocar memória para as colunas.\n");
			return 0;
    	}
    }
//numera as mesas
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){	
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
	//se 1, faz malloc
	if(n==1){
		int* v = malloc(tam * sizeof(int));
    	if (v != NULL)
   			return v;
	}
	//se 2, faz realloc
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
			if(aux[i][j].ocupada)//se mesa estiver ocupada
				vagas -= 1;//tira ela da contagem de mesas vagas
		}
	}
	return vagas;//devolverah quantas estao livres, ou zero se nenhuma estiver
}

/*CALCULA QUANTAS MESAS SERAO NECESSARIAS PARA O GRUPO*/
int calculaQuantasMesas(int tamanho_grupo)
{
	int cheias = tamanho_grupo / 4;//calcula quantas mesas cheias (4 lugares ocupados) precisa
	int sobra = 0;
	if(tamanho_grupo % 4 != 0)//se a sobra for igual a zero, var sobra continua sendo zero, mas se for diferente:
		sobra = 1;//uma mesa a mais serah necessaria para que 1 ou 3 clientes possam ocupa-la
	return cheias+sobra;
}

/*CASE 2: OCUPA AS MESAS QUE ESTAO LIVRES, ATUALIZA A MATRIZ, A VAR RESTANTE(DE CLIENTES) E O TAMANHO DO VET DO NUMERO DAS MESAS USADAS*/
Mesa** procuraMesasProGrupo(Mesa** mesas, int linhas, int colunas, int* mesas_usadas, int* restante)
{
	Mesa** aux = mesas;
	int i, j, k = 0;
	
	for(i=0; i<linhas && *restante>0; i++){
		for(j=0; j<colunas && *restante>0; j++){
			if(aux[i][j].ocupada == false){//se nao estiver ocupada, ocupa a mesa
				if(*restante > 4){//se for mais de 4 clientes
					aux[i][j].q_pessoas = 4;
					aux[i][j].ocupada = true;
					*restante -= 4;//retira os 4 clientes que sentaram nessa mesa para saber quantos faltam ainda	
				}else{//se for menos de ou for 4 clientes
					aux[i][j].q_pessoas = *restante;
					aux[i][j].ocupada = true;
					*restante = 0;//apenas zera o a var de clientes restantes, todos se sentaram em uma mesa
				}
				mesas_usadas[k] = aux[i][j].n_mesa;//guarda o numero da(s) mesa(s) q os clientes estao
				k++;//atualiza k para guardar o proximo numero de mesa
			}
		}
	}
				
	return aux;//retorna a matriz de mesas atualizada
}

/*PROCURA NUMERO DA COMANDA E LIBERA A MESA USADA PARA OUTRO GRUPO*/
Mesa** finalizaRefeicao(Mesa** mesas, int linhas, int colunas, int comanda)
{
	int i, j;
	Mesa** aux = mesas;
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			if(aux[i][j].n_comanda == comanda && aux[i][j].ocupada == true){//se as comandas forem iguais, atualiza infos
				aux[i][j].ocupada = false;
				aux[i][j].q_pessoas = 0;
				printf("A MESA COM A COMANDA %d FOI LIBERADA.\n", comanda);
				return aux;//retorna matriz aux com as infos atualizadas	
			}
		}
	}
	printf("A MESA COM A COMANDA %d JA ESTA LIVRE.\n", comanda);//se aux[][] ja estava livre
	return mesas;//retorna a matriz como era
	
}

/*IMPRIME O NUMERO DAS MESAS EM QUE O GRUPO SE ENCONTRA*/
void imprimeLocalizacaoGrupo(int* mesas_usadas, int tantas)
{
	int i = 0;
	
	if(tantas > 1){//se for mais de uma mesa usada
		printf("\nO GRUPO DE CLIENTES SE ENCONTRA NAS MESAS");
		for(i=0; i<tantas; i++)
			printf(" %d", mesas_usadas[i]);
	}
	else//se nao for, imprime soh a mesa usada
		printf("\nO GRUPO DE CLIENTES SE ENCONTRA NA MESA %d.", mesas_usadas[i]);
	printf("\n");
}

/*CASE 8: IMPRIME AS INFOS DE CADA MESA DO RESTAURANTE*/
void imprimeMesas(Mesa** mesas, int linhas, int colunas, int num) {

	int i, j;
	Mesa** aux = mesas;
	
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			if(num==0){//se numero for zero, quer dizer que imprime tudo
				if (aux[i][j].ocupada)
					printf("\nMESA %d   |  PESSOAS: %d", aux[i][j].n_mesa, aux[i][j].q_pessoas);
				else
					printf("\nMESA %d   |  LIVRE", aux[i][j].n_mesa);
			    printf("\n");
			}else{//se o numero nao for zero, quer dizer que soh imprime uma mesa
				if(num == aux[i][j].n_mesa){//se for os numeros das mesas(pesquisada e atual da matriz), imprime
					if (aux[i][j].ocupada)
						printf("\nMESA %d   |  PESSOAS: %d", aux[i][j].n_mesa, aux[i][j].q_pessoas);
					else
						printf("\nMESA %d   |  LIVRE", aux[i][j].n_mesa);
				    printf("\n");
					return;//retorna para nao ficar no loop
				}		
			}
		}
    }

}

/*LIBERA MATRIZ MESAS*/
void liberaMatrizDeStructs(Mesa** mesas, int linhas)
{
	int i;
    if (mesas != NULL) {
        for (i = 0; i < linhas; i++)
	        free(mesas[i]);
        free(mesas);
    }
}
