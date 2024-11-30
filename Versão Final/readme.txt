TRABALHO 4 - RESTAURANTE
DISCIPLINA: Lab de Programação II - ELC1067
DUPLA: Marcelo Azevedo e Helena L. Kellermann

IMPLEMENTADO:

-Structs allocadas dinamicamente;

-Funções, structs e demais foram separados em arquivos .c e .h:
A. main.c
B. menu.c e menu.h
C. mesa.c e mesa.h
D. pilha.c e pilha.h
E. fila.c e fila.h

-Todas opções do menu foram implementadas
1) Abrir restaurante: informar quantidade de mesas (linhas e colunas da matriz) e arrumar as mesas completas.

2) Chegar (grupo de) clientes ao restaurante: implica em ocupar mesa se há disponibilidade ou ir pra fila de espera. 

3) Finalizar refeição/liberar mesa: sempre que uma mesa é liberada, a mesa completa é arrumada (4 pratos), clientes 
são chamados da fila de espera (se houver) e a quantidade de pratos é ajustada na mesa (tirar pratos excedentes da mesa, se necessário, e recolocá-los na pilha). 

4) Desistir de esperar: sair da fila de espera. 

5) Repor pratos: adicionar pratos na pilha. 

6) Imprimir pilha de pratos(6), fila de espera(7) e ocupação das mesas(8), conforme descrito a seguir:  

6 - Pilha de pratos (quantos pratos existem na pilha de pratos).

7 - Fila de espera (quantos grupos estão na fila de espera, e quantas pessoas aguardam na fila de espera. Por ex: 
grupo 1 aguarda por 3 lugares, grupo 2 aguarda por 5 lugares, logo há 2 grupos aguardando, e um total de 8 pessoas esperam na fila); 

8 - Ocupação das mesas (número da mesa e quantidade de pessoas que ocupam a mesa)
o usuário pode pesquisar por número de mesa(1) ou então consultar todas as mesas(2); 


NÃO IMPLEMENTADO:

-A princípio, todos os itens que foram pedidos para serem implementados, foram realizados.
