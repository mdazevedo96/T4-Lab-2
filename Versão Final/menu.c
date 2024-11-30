#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "mesa.h"
#include "pilha.h"
#include "fila.h"
#include "menu.h"

/*CONFERE SE RESTAURANTE NAO FOI ABERTO AINDA. SENAO, AVISA*/
bool estahFechado(bool aberto)
{
	if(aberto == false){//se o restaurante nao foi aberto, encerra o case 8, volta pro menu
		printf("\nO RESTAURANTE AINDA NAO FOI ABERTO! DIGITE '1' A SEGUIR PARA ABRI-LO\n");
		return true;
	}
}

/*SE NAO HOUVER MAIS MESAS VAGAS, PERGUNTA SE QUER ENTAR NA FILA, ENTRA (OU NÃO)*/
void entrarNaFila(Fila* fila, int integrantes, int caso)
{
	int resposta;
	
	if(caso == 1){
		printf("\nNAO HA MESAS LIVRES PARA O GRUPO. DESEJA ENTRAR NA FILA DE ESPERA?\n1-SIM\t0-NAO: \t");
		scanf("%d", &resposta);
	}else{	
		printf("OBS: NAO HA MAIS MESAS VAGAS PARA %d DOS INTEGRANTES DO GRUPO\n", integrantes);
		printf("DESEJA ENTRAR NA FILA DE ESPERA?\n1-SIM\t0-NAO: \t");
		scanf("%d", &resposta);
	}
	
	if(resposta==1){
		grupoEntraNaFila(fila, integrantes);//grupo eh posto na fila de espera
		printf("A SENHA DA FILA DE ESPERA DO GRUPO EH '%d'", fila->fim->senha_grp);
	}else
		printf("\nVOLTANDO AO MENU\n");	
}

/*PROCURA A MESA DO GRUPO QUE TEM MENOS DE 4 PESSOAS E DEVOLVE OS PRATOS QUE ESTAO SOBRANDO PARA A PILHA*/
void pratosNaoUsados(Pilha* pilha, Mesa** mesas, int* usadas, int quantia, int linhas, int colunas)
{
	Mesa** aux = mesas;
	int i, j, k = 0;
	int colocar;
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			//se o numero da mesa for igual ao da mesa usada, e tem menos de 4 pessoas
			if((aux[i][j].n_mesa == usadas[quantia-1]) && (aux[i][j].q_pessoas < 4)){
				colocar = 4 - aux[i][j].q_pessoas;//guarda quantos pratos estao sobrando
				pilha_push(pilha, colocar);//coloca os pratos na pilha
			}
		}
	}	
}

/*RETORNA QUANTOS PRATOS ESTAO SENDO USADOS NAS MESAS*/
int sendoUsado(Mesa** mesas, int linhas, int colunas, bool prim_cliente)
{
	Mesa** aux = mesas;
	int i, j, somatorio = 0;

	if(prim_cliente == false)
		return somatorio = linhas*colunas*4;

	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++)
			somatorio = aux[i][j].q_pessoas + somatorio;
	}
	return somatorio;
}

/*PRINCIPAL*/
void menu()
{
	int opcao, linhas, colunas;
	Mesa** mesas;
	Pilha* pilha;
	Fila* fila;
	bool aberto = false;
	bool prim_cliente = false;

	do
	{
		int tam_grp, senha;

		printf("\nMENU:");
		printf("\n1.ABRIR RESTAURANTE");
		printf("\n2.CHEGAR CLIENTES AO RESTAURANTE");
		printf("\n3.FINALIZAR REFEICAO/LIBERAR MESA");
		printf("\n4.DESISTIR DE ESPERAR");
		printf("\n5.REPOR PRATOS");
		printf("\n6.IMPRIMIR PILHA DE PRATOS");
		printf("\n7.IMPRIMIR FILA DE ESPERA");
		printf("\n8.IMPRIMIR OCUPACAO DAS MESAS");
		printf("\n0.SAIR");

		printf("\nOPCAO SELECIONADA: ");
		scanf("%d", &opcao);

		switch(opcao)
		{

			//SAI DO MENU
			case 0:
				exit(1);


			//1.ABRIR RESTAURANTE
			case 1:

				if(aberto){//confere se o restaurante ja foi aberto
					printf("\nO RESTAURANTE JA FOI ABERTO!\n");
					break;
				}

				printf("\nINFORME COMO AS MESAS ESTAO DISTRIBUIDAS (linhas x colunas): ");
				scanf("%d %d", &linhas, &colunas);

				mesas = alocaMatrizDeStructs(linhas, colunas);//malloc espaço para a matriz de mesas
				fila = criaFila();//malloc espaço para a fila de cliente
				pilha = pilha_cria(linhas, colunas); //malloc pilha de pratos
				pilha_pop(pilha, linhas*colunas*4);//retira pratos da pilha, "arruma" mesas 
				aberto = true;//restaurante está aberto

				printf("\nRESTAURANTE ABERTO!\n");
				break;


			//2.CHEGAR (GRUPO DE) CLIENTES NO RESTAURANTE
			case 2:
				
				if(estahFechado(aberto)) break;

				printf("\nQUANTAS PESSOAS HA NESSE GRUPO?: ");
				scanf("%d", &tam_grp);

				if(haMesasVagas(mesas, linhas, colunas) == 0){//confere se todas as mesas foram ocupadas, se sim, vai pra fila e encerra case 2
					entrarNaFila(fila, tam_grp, 1);//entra ou nao na fila de espera
					break;
				}
				
				//o case 2 se inicia aqui, após conferir que o restaurante já está aberto e que há mesas sobrando
				int quantia = calculaQuantasMesas(tam_grp);//guarda quantia de mesas que terao de ser usadas pelo grupo
				int restante = tam_grp;//irah (a seguir) guardar o numero de intregrantes que sobrou/ficou sem mesa do grupo
				int* usadas = reAllocaVetor(1, quantia, usadas);//malloc para um vetor de int, que guarda o num das mesas usadas pelo grupo

				mesas = procuraMesasProGrupo(mesas, linhas, colunas, usadas, &restante);//clientes sentam-se a mesa, retorna matriz com infos atualizadas
				quantia = quantia - (calculaQuantasMesas(restante));//atualiza a quantia de mesas que estao sendo usadas pelo grupo
				usadas = reAllocaVetor(2, quantia, usadas);//realloca o tamanho do vetor de int

				if(quantia>0){//imprime quais as mesas o grupo estah usando
					imprimeLocalizacaoGrupo(usadas, quantia);//usadas: numero das mesas; quantia: quantas mesas(tam do vetor)
					pratosNaoUsados(pilha, mesas, usadas, quantia, linhas, colunas);//devolve a pilha de pratos os que estavam sobrando
				}
				
				if(restante>0)//se ter sobrado/restado clientes, informa quantos ficaram sem mesa
					entrarNaFila(fila, restante, 2);//entra ou nao na fila de espera

				free(usadas);//libera o vetor de int
				prim_cliente = true;

				break;

			//3.FINALIZAR REFEIÇÃO/LIBERAR MESA
			case 3:

				if(estahFechado(aberto)) break;

				int comanda;
				printf("PARA FINALIZAR A REFEICAO E SAIR DO RESTAURANTE, INFORME O NUMERO DE SUA COMANDA: ");
				scanf("%d", &comanda);
				
				if((comanda > 0) && (comanda <= linhas*colunas)){//se numero digitado for valido
					mesas = finalizaRefeicao(mesas, linhas, colunas, comanda);//atualiza matriz, agora com a mesa livre
					int em_uso = sendoUsado(mesas, linhas, colunas, prim_cliente);
					if(haPratosSuficientes(pilha, 4, em_uso))//confere se ha pratos suficientes pra arrumar a mesa
						pilha_pop(pilha, 4);//arruma a mesa novamente, coloca os pratos
					else//se nao tiver
						break;
					if(!filaVazia(fila))//se a fila nao estiver vazia
						chamaFilaDeEspera(fila, mesas, linhas, colunas);//chama o pessoal da fila de espera
				}else//valor digitado invalido
					printf("\nNUMERO DA COMANDA INFORMADO EH INVALIDO. VOLTANDO AO MENU\n");

				break;

			//4.DESISTIR DE ESPERAR
			case 4:

				if(estahFechado(aberto)) break;
				
				if(filaVazia(fila)){
					printf("NAO HA NENHUM GRUPO NA FILA DE ESPERA.\n");
					break;
				}
				
				printf("QUAL EH A SENHA DO GRUPO QUE DESEJA SAIR DA FILA DE ESPERA? ");
				scanf("%d", &senha);
				
				fila->ini = desisteDaFila(fila->ini, senha);//retira o grupo que desitiu da fila

				break;

			//5.REPOR PRATOS
			case 5:
				
				if(estahFechado(aberto)) break;				
				
				int na_pilha;//guarda os que estao na pilha
				int em_uso = sendoUsado(mesas, linhas, colunas, prim_cliente);//guarda os que estao na mesa
				
				if(pilha_vazia(pilha))
					na_pilha = 0;
				else
					na_pilha = pilha->prim->num_prato;
				
				int sujos = pilha->total_pratos - em_uso - na_pilha;// guarda os pratos que nao estao na mesa e nem na pilha
					
				if(sujos != 0){
					pilha_push(pilha, sujos);//os "sujos" serao "limpos" e irao pra pilha
					printf("PILHA DE PRATOS FOI REABASTECIDA\n");
				}else
					printf("NAO HA PRATOS DISPONIVEIS PARA PODER REPOR A PILHA\n");
				
				break;

			//6.IMPRIMIR PILHA DE PRATOS
			case 6:

				if(estahFechado(aberto)) break;
                
				if(pilha !=NULL)
                    pilha_imprime(pilha);
                    
				break;

			//7.IMPRIMIR FILA DE ESPERA
			case 7:

				if(estahFechado(aberto)) break;
				
				if(filaVazia(fila)){
					printf("NAO HA NENHUM GRUPO NA FILA DE ESPERA.\n");
					break;
				}
				
				imprimeFila(fila);
				
				break;

			//8.IMPRIMIR OCUPAÇÃO DAS MESAS
			case 8:
				
				if(estahFechado(aberto)) break;

				int resposta, num;

				printf("\nCOMO VOCE DESEJA PESQUISAR A OCUPACAO DAS MESAS?\n1.POR NUMERO DA MESA\n2.TODAS AS MESAS\nOPCAO ESCOLHIDA: ");
				scanf("%d", &resposta);

				switch(resposta)
				{
					case 1://pergunta qual eh o numero da mesa e confere se resposta eh valida
						printf("\nQUAL O NUMERO DA MESA QUE SE DESEJA PESQUISAR? ");
						scanf("%d", &num);
						if(num>0 && num<= linhas*colunas)
							imprimeMesas(mesas, linhas, colunas, num);//faz impressao de uma unica mesa
						else
							printf("\nNUMERO DA MESA INFORMADO EH INVALIDO. VOLTANDO AO MENU\n");
						break;

					case 2://se eh todas as mesas, manda imprimir tudo
						imprimeMesas(mesas, linhas, colunas, 0);
						break;

					default://se resposta invalida, volta
						printf("\nOPCAO INVALIDA. VOLTANDO AO MENU\n");
				}
				break;//fim case 8

			//CASO NUMERO DIGITADO NAO SEJA NENHUMA DAS OPCOES A CIMA
			default:
				printf("\nRESPOSTA INVALIDA. SAINDO DO MENU\n");
				exit(1);
		}
	}while(opcao != 0);

	pilha_libera(pilha);
	liberaFila(fila);
	liberaMatrizDeStructs(mesas, linhas);
}
