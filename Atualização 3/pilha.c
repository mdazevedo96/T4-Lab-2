#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

bool pilha_vazia(Pilha* p){
    return (p->prim == NULL);
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

void pilha_push(Pilha* p){

    if(pilha_cheia){
            printf("Pilha esta cheia!\n");
            printf("Nao eh possivel empilhar pratos\n");;
    }
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->pratos = p;
    n->prox = p->prim;
    p->prim = n;

     printf("Prato %d inserido na pilha\n", p->prim->pratos);
}

int pilha_pop(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha de pratos vazia\n");
        exit(1);
    }
    Lista* t;
    int prato;
    t=p->prim;
    prato = t->pratos;
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
    printf("Pilha: ");
    while(t != NULL){
        printf("%d", t->pratos);
        t = t->prox;
    }
    printf("\n");
}
