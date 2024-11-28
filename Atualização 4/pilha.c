#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

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

	int i;

	for(i=0; i<p->total_pratos; i++)
		pilha_push(p);
		
	printf("\nTotal de pratos: total %d topo %d\n", p->total_pratos, p->prim->num_prato);

    return p;
}

void pilha_push(Pilha* p)
{
    if(pilhaCheia(p) == true)
        return;

    Lista* novo = (Lista*) malloc(sizeof(Lista));
	
	if(pilha_vazia(p))
		novo->num_prato =  1;
	else	
    	novo->num_prato =  p->prim->num_prato + 1;
    
	novo->prox = p->prim;
    p->prim = novo;
	
//	printf("Prato %d inserido na pilha\n", p->prim->num_prato);
}

int pilha_pop(Pilha* p)
{
    if(pilha_vazia(p)){
        printf("Pilha de pratos vazia\n");
        exit(1);
    }

    Lista* t;
    int prato;
    t = p->prim;
    prato = t->num_prato;
    p->prim = t->prox;
    free(t);

    printf("Prato %d removido da pilha\n: %d", prato);
    return prato;
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
    Lista* t = p->prim;
    printf("Pilha:\n");
    while(t != NULL){
        printf("%d\t", t->num_prato);
        t = t->prox;
    }
    printf("\n");
}
