#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Lista {
    int* pratos;      // Array que representa os pratos
    struct Lista* prox;  // Ponteiro para o próximo nó
} Lista;

typedef struct Pilha {
    Lista* prim;         // Ponteiro para o topo da pilha
} Pilha;

Pilha* pilha_cria(int linhas, int colunas);

void pilha_push(Pilha* p, int v);

int pilha_pop(Pilha* p);

void pilha_libera(Pilha* p);

int pilha_vazia(Pilha* p);



