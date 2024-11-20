#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*-----STRUCT MESA-----*/ 

struct mesa {
    int n_mesa; //guarda numero da mesa
    bool ocupada;//guarda se esta livre ou ocupada (true se ocupada, false se livre)
    //se estiver ocupada:
    int q_pessoas;//guarda quantidade de pessoas sentadas
    int n_comanda;//guarda o numero da comanda(caada mesa tem apenas uma comanda)
};
typedef struct mesa Mesa;


/*-----FUNCOES MESA-----*/

/*CASE 1: MALLOC MATRIZ MESAS*/
Mesa** alocaMatrizDeStructs(int linhas, int colunas);

/*MALLOC E REALLOC DO VETOR DAS MESAS USADAS*/
int* reAllocaVetor(int n, int tam, int* vetor);

/*RECEBE MATRIZ DAS MESAS E RETORNA QUANTAS MESAS ESTAO VAGAS*/
int haMesasVagas(Mesa** mesas, int linhas, int colunas);

/*CALCULA QUANTAS MESAS SERAO NECESSARIAS PARA O GRUPO*/
int calculaQuantasMesas(int tamanho_grupo);

/*CASE 2: OCUPA AS MESAS QUE ESTAO LIVRES, ATUALIZA A MATRIZ, A VAR RESTANTE(DE CLIENTES) E O TAMANHO DO VET DO NUMERO DAS MESAS USADAS*/
Mesa** procuraMesasProGrupo(Mesa** mesas, int linhas, int colunas, int* mesas_usadas, int* restante);

/*IMPRIME O NUMERO DAS MESAS EM QUE O GRUPO SE ENCONTRA*/
void imprimeLocalizacaoGrupo(int* mesas_usadas, int tantas);

/*CASE 8: IMPRIME AS INFOS DE CADA MESA DO RESTAURANTE*/
void imprimeMesas(Mesa** mesas, int linhas, int colunas, int num);

/*LIBERA MATRIZ MESAS*/
void liberaMatrizDeStructs(Mesa** mesas, int linhas);
