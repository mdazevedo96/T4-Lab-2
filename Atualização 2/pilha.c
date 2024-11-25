#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int pilha_vazia(Pilha* p){
    return (p->prim->total_pratos == 0);
}

Pilha* pilha_cria(int linhas, int colunas){
    // Qtd de mesas (linha * col * 4 (qtd pratos totais)
    int total_pratos = linhas * colunas * 4;
    Pilha* p = (Pilha*) malloc (sizeof(Pilha));
    p->prim = NULL;
    if(p->prim == NULL){
        printf("Pilha criada com sucesso\n");
    }else{
        printf("Erro na alocacao da pilha\n");
        exit(1);
    }

    p->prim->total_pratos = (int*) malloc (total_pratos * sizeof(int));
    if (p->prim->total_pratos == NULL){
        printf("Erro na alocacao de pratos (pilha)");
        exit(1);
    }
    p->prim->total_pratos = total_pratos;

    return p;
}

void pilha_push(Pilha* p, int v){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->total_pratos = v;
    n->prox = p->prim;
    p->prim = n;
}

int pilha_pop(Pilha* p){
    Lista* t;
    int v;
    if(pilha_vazia(p)){
        printf("Pilha de pratos vazia\n");
        exit(1);
    }
    t=p->prim;
    v = t->total_pratos;
    p->prim = t->prox;
    free(t);
    return v;
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
