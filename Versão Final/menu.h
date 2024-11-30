#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mesa.h"
#include "pilha.h"
#include "fila.h"

/*MENU DO PROGRAMA EH CHAMADO NO MAIN.C*/
void menu();

/*CONFERE SE RESTAURANTE NAO FOI ABERTO AINDA. SENAO, AVISA*/
bool estahFechado(bool aberto);

/*SE NAO HOUVER MAIS MESAS VAGAS, PERGUNTA SE QUER ENTAR NA FILA, ENTRA (OU NÃO)*/
void entrarNaFila(Fila* fila, int integrantes, int caso);

/*PROCURA A MESA DO GRUPO QUE TEM MENOS DE 4 PESSOAS E DEVOLVE OS PRATOS QUE ESTAO SOBRANDO PARA A PILHA*/
void pratosNaoUsados(Pilha* pilha, Mesa** mesas, int* usadas, int quantia, int linhas, int colunas);

/*RETORNA QUANTOS PRATOS ESTAO SENDO USADOS NAS MESAS*/
int sendoUsado(Mesa** mesas, int linhas, int colunas, bool prim_cliente);

#endif
