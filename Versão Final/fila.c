#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mesa.h"
#include "fila.h"

/*-----FUNCOES FILA-----*/

/*MALLOC DA STRUCT FILA*/
Fila* criaFila()
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	
	if(f->ini==NULL && f->fim==NULL)
		return f;
	else{
		printf ("\n!Erro na alocacao da fila! Programa serah encerrado!\n");
		return 0;
	}
}

/*NOVO GRUPO EH INSERIDO NA FILA DE ESPERA*/
void grupoEntraNaFila(Fila* f, int n_membros)
{
	Grupo* novo = (Grupo*) malloc(sizeof(Grupo));//malloc espaço para o novo noh
	novo->num_membros = n_membros;//novo noh guarda quantos membros ha no grupo
	novo->prox = NULL;//o novo noh serah o ultimo agora, entao ele aponta para NULL
	
	if(filaVazia(f)){//se o fim da fila for NULL, a fila estava vazia
		novo->senha_grp = 1;
		f->ini = novo;//o inicio da fila serah o novo noh
	}else{//se jah houver um noh no final da fila
		novo->senha_grp = f->fim->senha_grp + 1;//a senha do novo noh serah 1+senha do noh anterior(do fim da fila)
		f->fim->prox = novo;//o ultimo noh da fila apontarah para o novo noh
	}
	f->fim = novo;//o novo noh agora eh o fim da fila
}

/*RETIRA DA FILA O GRUPO QUE DESISTIU DE ESPERAR*/
Grupo* desisteDaFila(Grupo* inicio, int senha)
{
	Grupo* anterior = NULL;//guarda o grupo anterior
	Grupo* aux = inicio;//percorre a lista
	
	//percorre os nohs da fila ate achar a senha ou chegar ao fim(sem a senha)
	while(aux != NULL && aux->senha_grp != senha){
		anterior = aux;
		aux = aux->prox;
	}
	
	if(aux == NULL){//se auxiliar chegou ao fim, significa que nao ha essa senha na fila
		printf("NAO HA NENHUM GRUPO COM ESTA SENHA NA FILA.\n");
		return inicio;
	}
	
	if(anterior == NULL)//se for NULL, quer dizer que o grupo com a senha estava no inicio da fila
		inicio = aux->prox;	
	else//se nao for, quer dizer que o grupo com a senha estava no meio ou no fim da fila
		anterior->prox = aux->prox;
	
	printf("O GRUPO COM A SENHA %d FOI RETIRADO DA FILA DE ESPERA.\n", senha);
	free(aux);
	return inicio;//retorna o primeiro grupo, agora com os ponteiros atualizados
}

/*COLOCA O PRIMEIRO GRUPO DA FILA NA MESA VAGA*/
void chamaFilaDeEspera(Fila* f, Mesa** mesas, int linhas, int colunas)
{
	int integrantes = f->ini->num_membros;//guarda quantas pessoas tem no grupo
	int* usada = reAllocaVetor(1, 1, usada);//aloca espaço pra 1 mesa

	mesas = procuraMesasProGrupo(mesas, linhas, colunas, usada, &integrantes);//pessoas do grupo se sentam a mesa
	
	//se ainda ha integrantes do grupo sobrando, avisa quantos ainda estao na fila de espera
	if((integrantes > 0) && (integrantes != f->ini->num_membros)){
		f->ini->num_membros = integrantes;//numero de membros na fila eh atualizado
		printf("\nO GRUPO COM SENHA %d DA FILA DE ESPERA FOI CHAMADO. AINDA HA %d INTEGRANTE(S) DO GRUPO ESPERANDO NA FILA\n", f->ini->senha_grp, integrantes);
		imprimeLocalizacaoGrupo(usada, 1);//imprime a mesa em que se sentaram
	}
	else{//se todos integrantes conseguiram se sentar a mesa, retira aquele grupo da fila de espera
		printf("O GRUPO COM SENHA %d DA FILA DE ESPERA FOI CHAMADO.\n", f->ini->senha_grp);
		imprimeLocalizacaoGrupo(usada, 1);//imprime a mesa em que se sentaram
		retiraDaFila(f);//
	}
	free(usada);//libera o vetor que guarda o numero da mesa
}


/*RETIRA DA FILA DE ESPERA O PRIMEIRO GRUPO, SE TODOS INTEGRANTES CONSEGUIRAM MESA*/
void retiraDaFila(Fila* f)
{
	Grupo* aux = f->ini;
	
	if(filaVazia(f)){
		printf("NAO HA NENHUM GRUPO NA FILA DE ESPERA.\n");
		return;
	}
	
	f->ini = aux->prox;//o grupo do inicio da fila agora eh o que estava atras do que foi retirado
	if(f->ini==NULL)//confere se a fila ficou vazia
		f->fim == NULL;
	
	free(aux);
}

/*IMPRIME QUANTOS GRUPOS E PESSOAS HA NA FILA DE ESPERA */
void imprimeFila(Fila* f)
{
	int n_grupos = 0;
	int n_clientes = 0;
	Grupo* aux = f->ini;//percorre a fila
	
	while(aux != NULL){
		n_clientes += aux->num_membros;
		n_grupos += 1;
		aux = aux->prox;//vai pro proximo noh
	}
	printf("HA %d GRUPO(S) E %d CLIENTE(S) NA FILA DE ESPERA.\n", n_grupos, n_clientes);
}

/*LIBERA A FILA DE ESPERA*/
void liberaFila(Fila* f)
{
	Grupo* aux = f->ini;
	while(aux != NULL){
		Grupo* l = aux->prox;//guarda o proximo noh
		free(aux);//libera o anterior
		aux = l;
	}
	free(f);
}

/*RETORNA TRUE SE FILA ESTAH VAZIA, SENAO, FALSE*/
bool filaVazia(Fila* f)
{
	return (f->ini==NULL);
}
