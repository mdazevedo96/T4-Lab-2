#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fila.h"

/*-----FUNCOES FILA-----*/

/*MALLOC DA STRUCT FILA*/
Fila* criaFila()
{
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	
	if(f->ini==NULL && f->fim==NULL)
		printf ("\nFila alocada com sucesso!\n");
	else{
		printf ("\nErro na alocacao da fila! Programa serah encerrado!\n");
		return 0;
	}
	
	return f;
}

void grupoEntraNaFila(Fila* f, int n_membros)
{
	Grupo* novo = (Grupo*) malloc(sizeof(Grupo));//malloc espaço para o novo noh do tipo lista
	novo->num_membros = n_membros;//novo noh guarda quantos membros ha no grupo
	novo->prox = NULL;//o novo noh serah o ultimo agora, entao ele aponta para NULL
	if(f->fim == NULL){//se o fim da fila for NULL, quer dizer que a fila estava vazia
		novo->senha_grp = 1;//a senha do primeiro grp serah 1
		f->ini = novo;//o inicio da fila serah o novo noh
	}else{//se jah houver um noh no final da fila
		novo->senha_grp = f->fim->senha_grp + 1;//a senha do novo noh serah 1+senha do noh anterior(do fim da fila)
		f->fim->prox = novo;//o ultimo noh da fila apontarah para o novo noh
	}
	f->fim = novo;//o novo noh agora eh o fim da fila
}

int filaVazia(Fila* f)
{
	return (f->ini==NULL);
}

void retiraDaFila(Fila* f)
{
	Grupo* aux;
	
	if(filaVazia(f)){
		printf("NAO HA NENHUM GRUPO NA FILA DE ESPERA.\n");
		return;
	}
	aux = f->ini;
	
	f->ini = aux->prox;
	if(f->ini==NULL)
		f->fim == NULL;
	
	free(aux);
}

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
	return inicio;
}

void liberaFila(Fila* f)
{
	Grupo* aux = f->ini;
	while(aux != NULL)
	{
		Grupo* l = aux->prox;
		free(aux);
		aux = l;
	}
	free(f);
}

void contaFila(Fila* f)
{
	int n_grupos = 0;
	int n_clientes = 0;
	
	Grupo* aux = f->ini;
	
	while(aux != NULL)
	{
		n_clientes += aux->num_membros;
		n_grupos += 1;
		aux = aux->prox;
	}
	printf("HA %d GRUPO(S) E %d CLIENTE(S) NA FILA DE ESPERA.\n", n_grupos, n_clientes);
}
