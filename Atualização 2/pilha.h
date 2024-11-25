#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista{
    int total_pratos;
    struct lista* prox;
};
typedef struct lista Lista;

struct pilha{
    Lista* prim;
};
typedef struct pilha Pilha;

Pilha* pilha_cria(int linhas, int colunas);

void pilha_push(Pilha* p, int v);

int pilha_pop(Pilha* p);

void pilha_libera(Pilha* p);

int pilha_vazia(Pilha* p);



