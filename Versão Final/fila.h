#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*-----STRUCT LISTA(GRUPO) E STRUCT FILA-----*/ 

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

/*NOVO GRUPO EH INSERIDO NA FILA DE ESPERA*/
void grupoEntraNaFila(Fila* f, int n_membros);

/*RETIRA DA FILA O GRUPO QUE DESISTIU DE ESPERAR*/
Grupo* desisteDaFila(Grupo* inicio, int senha);

/*RETIRA DA FILA DE ESPERA O PRIMEIRO GRUPO, SE TODOS INTEGRANTES CONSEGUIRAM MESA*/
void retiraDaFila(Fila* f);

/*IMPRIME QUNATOS GRUPOS E PESSOAS HA NA FILA DE ESPERA */
void imprimeFila(Fila* f);
	
/*LIBERA A FILA DE ESPERA*/
void liberaFila(Fila* f);

/*RETORNA TRUE SE FILA ESTAH VAZIA, SENAO, FALSE*/
bool filaVazia(Fila* f);
