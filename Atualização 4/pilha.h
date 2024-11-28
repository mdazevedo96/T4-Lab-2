#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Lista {
    int num_prato;      // int que guarda o "numero" do prato
    struct Lista* prox;  // Ponteiro para o próximo noh(prato)
} Lista;

typedef struct Pilha {
    Lista* prim;         // Ponteiro para o topo da pilha
	int total_pratos;	//guarda quantos pratos o restaurante precisa para todas as mesas
} Pilha;

Pilha* pilha_cria(int linhas, int colunas);

void pilha_push(Pilha* p);

int pilha_pop(Pilha* p);

void pilha_libera(Pilha* p);

bool pilha_vazia(Pilha* p);

bool pilhaCheia(Pilha* p);

void pilha_imprime(Pilha* p);
