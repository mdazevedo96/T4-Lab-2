#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"
#include "mesa.h"

bool pilha_vazia(Pilha* p){
    return (p->prim == NULL);
}

bool pilhaCheia(Pilha* p)
{
	if(p->prim!= NULL && p->prim->num_prato == p->total_pratos){
    	printf("Pilha esta cheia!\n");
        printf("Nao eh possivel empilhar pratos\n");
		return true;
	}else
		return false;
}

Pilha* pilha_cria(int linhas, int colunas)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro na alocacao da pilha\n");
        exit(1);
    }
    p->prim = NULL; // Inicializa pilha vazia
    p->total_pratos = linhas*colunas*4;  // Quantidade total de pratos
    printf("Pilha criada com sucesso\n");

	pilha_push(p, p->total_pratos);
		
	printf("\nTotal de pratos: total %d topo %d\n", p->total_pratos, p->prim->num_prato);

    return p;
}

void pilha_push(Pilha* p, int colocar)
{
    if(pilhaCheia(p) == true)
        return;
	int i;
	for(i=0; i<colocar; i++){
	    Lista* novo = (Lista*) malloc(sizeof(Lista));
	
		if(pilha_vazia(p))
			novo->num_prato =  1;
		else	
    		novo->num_prato =  p->prim->num_prato + 1;
    
		novo->prox = p->prim;
	    p->prim = novo;
	}
//	printf("Prato %d inserido na pilha\n", p->prim->num_prato);
}

void pilha_pop(Pilha* p, int retirar)
{
    if(pilha_vazia(p)){
        printf("Pilha de pratos vazia\n");
        exit(1);
    }
	int i;
	int prato;
	for(i=0; i<retirar; i++){
	    Lista* t;
    	t = p->prim;
    	prato = t->num_prato;
    	p->prim = t->prox;
    	free(t);
	    printf("Prato %d removido da pilha\n", prato);	
	}
}

void pratosNaoUsados(Pilha* pilha, Mesa** mesas, int* usadas, int quantia, int linhas, int colunas)
{
	Mesa** aux = mesas;
	int i, j, k = 0;
	int colocar;
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			if((aux[i][j].n_mesa == usadas[k]) && (aux[i][j].q_pessoas < 4)){
				colocar = 4 - aux[i][j].q_pessoas;
				pilha_push(pilha, colocar);		
			}
			if(usadas[k] == quantia)
				return;
		}
	}	
}

void pilha_libera(Pilha* p){
    Lista* q=  p->prim;
    while(q!=NULL){
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
}

void pilha_imprime(Pilha* p){
    if(pilha_vazia(p)){
    	printf("Pilha de pratos estah vazia\n");
    	return;
    }
	
	Lista* t = p->prim;
    printf("Pilha:\n");
    while(t != NULL){
        printf("%d\t", t->num_prato);
        t = t->prox;
    }
    printf("\n");
}
