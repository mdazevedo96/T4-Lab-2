#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int pilha_vazia(Pilha* p){
    return (p->prim->pratos == 0);
}

Pilha* pilha_cria(int linhas, int colunas) {
    int total_pratos = linhas * colunas * 4;  // Quantidade total de pratos
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro na alocacao da pilha\n");
        exit(1);
    }
    p->prim = NULL; // Inicializa pilha vazia
    printf("Pilha criada com sucesso\n");


    Lista* novo = (Lista*) malloc(total_pratos * sizeof(Lista));
    if (novo == NULL) {
        printf("Erro na alocacao da pilha\n");
        free(p);
        exit(1);
    }

    else{
         novo->pratos = total_pratos;
         novo->prox = NULL;
         p->prim = novo;
         printf("Total de pratos: %d\n", novo->pratos);
    }

    return p;
}

void pilha_push(Pilha* p, int v){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->pratos = v;
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
    v = t->pratos;
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
