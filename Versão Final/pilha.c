#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

/*-----FUNCOES PILHA-----*/

/*MALLOC DA STRUCT PILHA*/
Pilha* pilha_cria(int linhas, int colunas)
{
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro na alocacao da pilha\n");
        exit(1);
    }
    p->prim = NULL; // Inicializa pilha vazia
    p->total_pratos = linhas*colunas*4;  // Quantidade total de pratos

	pilha_push(p, p->total_pratos);//coloca o total de pratos necessarios na pilha
    return p;
}

/*COLOCA NA PILHA O TANTO DE PRATOS QUE FOI INFORMADO*/
void pilha_push(Pilha* p, int colocar)
{
    if(pilhaCheia(p))
        return;
        
	int i;
	//repete o push ate colocar todos os pratos que se desejava adicionar na pilha
	for(i=0; i<colocar; i++){
	    Lista* novo = (Lista*) malloc(sizeof(Lista));
	
		if(pilha_vazia(p))
			novo->num_prato =  1;//se vazia, o primeiro prato serah o 1
		else	
    		novo->num_prato =  p->prim->num_prato + 1;//senao, serah o numero do prato do topo + 1
    
		novo->prox = p->prim;
	    p->prim = novo;//o topo agora eh o recem adicionado
	}
}

/*RETIRA DA PILHA O TANTO DE PRATOS QUE FOI INFORMADO*/
void pilha_pop(Pilha* p, int retirar)
{
	int i;
	
    if(pilha_vazia(p)){
		return;
	}

	//repete o push ate retirar todos os pratos que se desejava tirar da pilha
	for(i=0; i<retirar; i++){
	    Lista* t = p->prim;
    	p->prim = t->prox;
    	free(t);
	}
}

/*CONFERE SE HA PRATOS SUFICIENTES NA PILHA PARA ARRUMAR A MESA*/
bool haPratosSuficientes(Pilha* pilha, int n, int usando)
{
	int resposta;
	if(pilha_vazia(pilha)){
    	printf("MESA NAO PODE SER ARRUMADA POIS FALTA PRATOS. REABASTECER A PILHA DE PRATOS?\n1-SIM\t0-NAO: \t");
		scanf("%d", &resposta);
			
		if(resposta==1){
			pilha_push(pilha, pilha->total_pratos-usando);
			printf("PILHA FOI REABASTECIDA");
		}else{
			printf("\nVOLTANDO AO MENU\n");
			return false;
		}
	}
	
	if(pilha->prim->num_prato > n)//se o numero do topo for maior do que a quantidade q precisa colocar
		return true;
	else
		return false;
}	


/*IMPRIME A PILHA DE PRATOS*/
void pilha_imprime(Pilha* p)
{
    if(pilha_vazia(p)){
    	printf("A PILHA DE PRATOS ESTAH VAZIA\n");
    	return;
    }
    
    printf("\n-PILHA DE PRATOS-\nCAPACIDADE MAXIMA: %d\nQUANTIDADE ATUAL: %d \n", p->total_pratos, p->prim->num_prato);
}

/*LIBERA A PILHA DE PRATOS*/
void pilha_libera(Pilha* p)
{
    Lista* q=  p->prim;
    while(q!=NULL){
        Lista* t = q->prox;//guarda o proximo noh
        free(q);//libera o anterior
        q = t;
    }
    free(p);
}

/*RETORNA TRUE SE PILHA ESTAH VAZIA, SENAO, FALSE*/
bool pilha_vazia(Pilha* p)
{
    return (p->prim == NULL);
}
	
/*IMPRIME MENSAGEM E RETORNA TRUE SE PILHA ESTAH CHEIA, SENAO, FALSE*/
bool pilhaCheia(Pilha* p)
{
	if(p->prim!= NULL && p->prim->num_prato == p->total_pratos){
    	printf("PILHA ESTAH CHEIA! NAO EH POSSIVEL EMPILHAR PRATOS.\n");
		return true;
	}
	
	return false;
}
