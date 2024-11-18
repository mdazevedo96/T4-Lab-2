#include <stdio.h>
#include <stdlib.h>

//Sobre cada mesa, guardar o número da mesa e se está livre ou ocupada;
//se estiver ocupada, guardar a quantidade de pessoas sentadas e o número da comanda. Cada mesa possui uma comanda. 

/*-----STRUCT MESA-----*/ 

struct mesa {
    int n_mesa; //guarda numero da mesa
    bool ocupada;//guarda se esta livre ou ocupada (true se ocupada, false se livre)
    //se estiver ocupada:
    int q_pessoas;//guarda quantidade de pessoas sentadas
    int n_comanda;//guarda o numero da comanda(caada mesa tem apenas uma comanda)
    struct mesa* prox;//guarda a proxima mesa
};
typedef struct mesa Mesa;


/*-----FUNCOES MESA-----*/

/*MALLOC MATRIZ MESAS*/
Mesa*** alocaMatrizDeStructs(int n_linhas, int n_colunas);

