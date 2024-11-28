#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*-----STRUCT LISTA E STRUCT FILA-----*/ 

struct grupo
{
	int senha_grp;//guarda a senha única, pertencente ao grupo de clientes que estah esperando ser chamado
	int num_membros;//guarda quantos membros ha nesse grupo (serah atualizado cfe as mesas forem liberadas)
	struct grupo* prox;// aopnta para a proxima struct lista do grupo atras desse
};
typedef struct grupo Grupo;

struct fila
{
	Grupo* ini;//guarda o inicio da fila (aponta para o 1º grp da fila)
	Grupo* fim;//guarda o final da fila (aponta para o ultimo grp da fila)
};
typedef struct fila Fila;


/*-----FUNCOES FILA-----*/

/*MALLOC DA STRUCT FILA*/
Fila* criaFila();

void grupoEntraNaFila(Fila* f, int n_membros);

int filaVazia(Fila* f);

void retiraDaFila(Fila* f);

Grupo* desisteDaFila(Grupo* inicio, int senha);
	
void liberaFila(Fila* f);

void contaFila(Fila* f);
