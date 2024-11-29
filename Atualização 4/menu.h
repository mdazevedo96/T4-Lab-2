#include <stdio.h>
#include <stdlib.h>

menu();

/*Faça um menu que permita no mínimo as seguintes operações:

1) Abrir restaurante: informar quantidade de mesas (linhas e colunas da matriz) e arrumar as mesas completas.
COMPLETO:
a.nao tem como usar as demais opções do menu se a opção 1 ainda não foi selecionada(se o restaurante ainda não foi aberto);
b.se o restaurante jah foi aberto antes, ele nao abre dnv (opcao 1 não vai ser executada dnv, repetida)
c.fila e pilha são alocadas com sucesso, e a pilha fica com a quantidade de pratos certos e o prato no topo tem o numero de n.
(ex. 12 mesas * 4 pratos = 48 pratos na pilha e o prato no topo eh o de numero 48)
d.todos pratos sao retirados da pilha pois eh necessario abrir o restaurante com as mesas arrumadas
(eles nao vao de fato pras mesas, mas a pilha eh alterada cfe a quantidade de pratos que precisa colocar ou tirar da mesa)	

2) Chegar (grupo de) clientes ao restaurante: implica em ocupar mesa se há disponibilidade ou ir pra fila de espera.
a.pede-se para dizer quantos clientes tem naquele grupo. dentro da ocpcao, os clientes vao para as mesas como esperado e se imprime em que mesas eles estao
(ex. 13 clientes, eles ficam nas mesas 1, 2, 3, e o 13º cliente que ficou solito, fica na mesa 4, ele e apenas ele: dps de outra opercao 2 ninguem de outro grp vai pra mesa 4)
b.em outras chamadas da opcao, mesma coisa. Se for o caso do numero de clientes exceder o limite de mesas disponiveis, os q conseguirem pegam mesas e o resto escolhe se quer ir pra fila
(ex.45 pessoas, mesas 5 6 7 8 9 10 11 12; 13 pessoas ficaram de fora pq nao tem mais mesas, entao eh perguntado se querem entrar na fila. Se sim, programa informa o numero da senha, 1 por ex) 
c.se clientes optarem por nao ficar na fila de espera, opcao 2 soh encerra

3) Finalizar refeição/liberar mesa: sempre que uma mesa é liberada, a mesa completa é arrumada (4 pratos), clientes
são chamados da fila de espera (se houver) e a quantidade de pratos é ajustada na mesa (tirar pratos excedentes da mesa, se necessário, e recolocá-los na pilha).


4) Desistir de esperar: sair da fila de espera.
COMPLETO:
a.avisa se a fila estah vazia
b.retira certinho o grp cfe o numero da senha do grp. se for o caso da senha nao "existir"(nenhum grp tem aquele numero), avisa q nao tem e nao retira ninguem, volta pro menu

5) Repor pratos: adicionar pratos na pilha.
(precisa da opcao 3 pra funcionar direito, pra quando um grupo termina de comer. quando as pessoas se sentam a mesa, os pratos que sobram ja voltam automaticamente pra pilha, mas no caso 3 ainda nao)
*duvidas*

COMPLETO: todas funcionam aparentemente bem, antes e depois das pilhas, filas e mesas serem mexidas (conferir dnv após completar tudo e dar uma arrumada no visual da impressao)
6) Imprimir pilha de pratos, fila de espera e ocupação das mesas, conforme descrito a seguir:

Apos readicionar pratos que estavam sobrando na mesa, pilha continua como vazia ao imprimir. mas se pilha vazia de fato, avisa normal; teste na opcao 1 foi adc pra conferir funcao push e pop 
6.Pilha de pratos (quantos pratos existem na pilha de pratos).

OK, se vazia, avisa; senao, imprime normal como pedido e, cfe grupos desistirem ou entrarem no restaurante, a impressao fica aualizada certinho
7.Fila de espera (quantos grupos estão na fila de espera, e quantas pessoas aguardam na fila de espera. Por ex:
grupo 1 aguarda por 3 lugares, grupo 2 aguarda por 5 lugares, logo há 2 grupos aguardando, e um total de 8 pessoas esperam na fila);

OK, imprime cfe opcao selecionada(mesa espec. ou todas), se recem aberto, imprime como livres, senao, cfe estah, e quantos clientes em cada mesa
8. Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa) - o usuário pode pesquisar por número de mesa ou então consultar todas as mesas;*/

