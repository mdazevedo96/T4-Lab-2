#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*-----STRUCT LISTA E STRUCT PILHA-----*/ 

typedef struct Lista {
    int num_prato;      // int que guarda o "numero" do prato(na pilha)
    struct Lista* prox;  // Ponteiro para o próximo noh(prato)
} Lista;

typedef struct Pilha {
    Lista* prim;         // Ponteiro para o topo da pilha
	int total_pratos;	//guarda quantos pratos o restaurante precisa para todas as mesas
} Pilha;


/*-----FUNCOES PILHA-----*/


/*MALLOC DA STRUCT PILHA*/
Pilha* pilha_cria(int linhas, int colunas);

/*COLOCA NA PILHA O TANTO DE PRATOS QUE FOI INFORMADO*/
void pilha_push(Pilha* p, int colocar);

/*RETIRA DA PILHA O TANTO DE PRATOS QUE FOI INFORMADO*/
void pilha_pop(Pilha* p, int retirar);

/*CONFERE SE HA PRATOS SUFICIENTES NA PILHA PARA ARRUMAR A MESA*/
bool haPratosSuficientes(Pilha* pilha, int n, int usando);

/*IMPRIME A PILHA DE PRATOS*/
void pilha_imprime(Pilha* p);

/*LIBERA A PILHA DE PRATOS*/
void pilha_libera(Pilha* p);

/*RETORNA TRUE SE PILHA ESTAH VAZIA, SENAO, FALSE*/
bool pilha_vazia(Pilha* p);

/*IMPRIME MENSAGEM E RETORNA TRUE SE PILHA ESTAH CHEIA, SENAO, FALSE*/
bool pilhaCheia(Pilha* p);

#endif
