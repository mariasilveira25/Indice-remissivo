/*
*	Trabalho II de Estrutura de Dados I
*
*	Indice Remissivo
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"AVL.h"
#include"HASH.h"
#include "lista.h"
#include"ABB.h"
#define TAM_MAX 100000

/*
*	Compara as palavras encontradas no texto.
*/
int compara(char* ptr, int cont_linha)
{
	// FILE* arqPalavra = fopen("palavras.txt", "rt");
	FILE* arqPalavra = fopen("chave2.txt", "rt");
	char texto_str[256];

	int soma=0, soma2=0;
	while(fgets(texto_str, 256, arqPalavra) != NULL) 
	{
		char *pos;
		if ((pos=strchr(texto_str, '\n')) != NULL)
			*pos = '\0';

		soma=0, soma2=0;
		for (int i = 0; i < strlen(ptr); ++i)
		{
			soma += (ptr[i]);
			soma2 += (texto_str[i]);
			if (soma != soma2)
			{
				break;
			}
		}

		if (soma == soma2)
		{
			fclose(arqPalavra);
			return 0;
		}

	}
	
	fclose(arqPalavra);
	return 1;
}

/*
*	Copia uma palavra para outra.
*/
void copy_string(char *target, char *source) {
	while (*source) {
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}

/*
*	Executa todas as estruturas criadas.
*/
double rodaEstrutura(int numEstrutura, char* arqEntrada) {

	char delim[] = " ";
	char texto_str[256];
	char *ptr = malloc(32 * sizeof(*ptr));
	char *auxPalavra = malloc(32 * sizeof(*auxPalavra));
	Lista* lista = criaLISTA();
	double tempo;
	NO *HASH[TAM_MAX];
    funcaohash(846.5);
	inicializa(HASH);

	// FILE* arqtexto = fopen("texto.txt", "rt");
	FILE* arqtexto = fopen(arqEntrada, "rt");
	if(arqtexto == NULL)
	{
	    printf("ERRO - algum arquivo não existe \n");
	    exit(1);
	}

	int	cont_linha = 0;
	int numInsercoes = 0;
	clock_t Ticks[2], Ticks1[2], Ticks2[2], Ticks3[2];
	while(fgets(texto_str, 256, arqtexto) != NULL) 
	{

		ptr = strtok(texto_str, delim);
		cont_linha++;
		while(ptr != NULL)
		{
			copy_string(auxPalavra, ptr);

			if((compara(auxPalavra, cont_linha) == 0)&&(strlen(auxPalavra) >=4) && (strlen(auxPalavra)<32)){

			
				// printf("%s - Linha %d\n", auxPalavra, cont_linha);

				switch (numEstrutura) {
					// Arvore ABB
					case 1:
		    			Ticks[0] = clock();
						insereABB(auxPalavra, cont_linha, &raizABB);
					    Ticks[1] = clock();
						tempo += (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
						numInsercoes++;
						break;
					// LISTA
					case 2:
		    			Ticks1[0] = clock();	
						insereLISTA(lista, auxPalavra , cont_linha);
						Ticks1[1] = clock();
						tempo += (Ticks1[1] - Ticks1[0]) * 1000.0 / CLOCKS_PER_SEC;
						numInsercoes++;
						break;
					// Arvore AVL
					case 3:
		    			Ticks2[0] = clock();
						insereAVL(raiz,auxPalavra, cont_linha);
						Ticks2[1] = clock();
						tempo += (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;
						numInsercoes++;
						break;
					// HASH
					case 4:
		    			Ticks3[0] = clock();
						insereHASH(auxPalavra,cont_linha, HASH);
						Ticks3[1] = clock();
						tempo += (Ticks3[1] - Ticks3[0]) * 1000.0 / CLOCKS_PER_SEC;
						numInsercoes++;
						break;
					case 5:
						break;
					case 6:
						break;
					case 7:
						break;
				}
			}
			ptr = strtok(NULL, delim);
		}
	}
	// printf("Número de inserções %d\n",numInsercoes );
	// imprimeHASH(HASH);s
	fclose(arqtexto);
	return tempo/numInsercoes;

} 

/*
*	Codigo principal onde eh executado o programa.
*/
int main(int argc, char const *argv[])
{

	FILE *arqSaida = fopen("saida.txt","w");
	int numInteracoes = 50;
	double somaLISTA = 0;
	double somaABB = 0;
	double somaAVL = 0;
	double somaHASH = 0;
	char* arqEntrada = "teste.txt";

	//##################################################################### //
	// fprintf(arqSaida, "\n########### LISTA ###########\n");
	// for (int i = 0; i < numInteracoes; i++) {
	// 	somaLISTA += rodaEstrutura(2, arqEntrada);
	// }
	// fprintf(arqSaida, "Tempo gasto para a lista: %g ms.\n", somaLISTA/numInteracoes);

	// printf("\n########### LISTA ###########\n");
	// printf("Tempo gasto para a lista: %g ms.\n", somaLISTA/numInteracoes);
	// exibeLISTA(lista);
	
	// // ##################################################################### //
	// fprintf(arqSaida, "\n########### ABB ###########\n");
	// for (int i = 0; i < numInteracoes; i++) {
	// 	somaABB += rodaEstrutura(1, arqEntrada);
	// }
	// fprintf(arqSaida, "Tempo gasto para a árvore binária (ABB): %g ms.\n", somaABB/numInteracoes);

	// printf("\n########### ABB ###########\n");
	// printf("Tempo gasto para a arvore binaria: %g ms.\n", somaABB/numInteracoes);
	// emordemABB(raizABB);
	// imprimeABB(raizABB,0);

	// // ##################################################################### //

	fprintf(arqSaida, "\n############### AVL ##############\n");
	for (int i = 0; i < numInteracoes; i++) {
		somaAVL += rodaEstrutura(3, arqEntrada);
	}
	fprintf(arqSaida, "Tempo gasto para a AVL: %g ms.\n", somaAVL/numInteracoes);
	
	printf("\n############### AVL ##############\n");
	printf("Tempo gasto para a AVL: %g ms.\n", somaAVL/numInteracoes);
	// // exibir_ordenadoAVL(raiz);

	// ##################################################################### //
	
	// fprintf(arqSaida, "\n #################### HASH ####################\n");
	// for (int i = 0; i < numInteracoes; i++) {
	// 	somaHASH += rodaEstrutura(4, arqEntrada);
	// }
	// fprintf(arqSaida, "Tempo gasto para a HASH: %g ms.\n", somaHASH/numInteracoes);
	
	// printf("\n #################### HASH ####################\n");
	// printf("Tempo gasto para a HASH: %g ms.\n", somaHASH/numInteracoes);
	// imprimeHASH(HASH);
	// printf("\n");

	fclose(arqSaida);
	return 0;
}