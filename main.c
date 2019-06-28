#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include"AVL.h"
#include"HASH.h"
#include "lista.h"
#include"ABB.h"
#define TAM_MAX 100000

int compara(char* ptr, int cont_linha)
{
	FILE* arqPalavra = fopen("palavras.txt", "rt");
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

void copy_string(char *target, char *source) {
	while (*source) {
		*target = *source;
		source++;
		target++;
	}
	*target = '\0';
}

int main(int argc, char const *argv[])
{
	char delim[] = " ";
	char texto_str[256];
	char *ptr = malloc(32 * sizeof(*ptr));
	char *auxPalavra = malloc(32 * sizeof(*auxPalavra));
	Lista* lista = criaLISTA();
	double Tempo, Tempo1, Tempo2, Tempo3;
	NO *HASH[TAM_MAX];
    funcaohash(846.5);
	inicializa(HASH);

	FILE* arqtexto = fopen("texto.txt", "rt");
	if(arqtexto == NULL)
	{
	    printf("ERRO - algum arquivo não existe \n");
	    exit(1);
	}

	int	cont_linha = 0;
	while(fgets(texto_str, 256, arqtexto) != NULL) 
	{

		ptr = strtok(texto_str, delim);
		cont_linha++;
		while(ptr != NULL)
		{
			copy_string(auxPalavra, ptr);
			if((compara(auxPalavra, cont_linha) == 0)&&(strlen(auxPalavra) >=4) && (strlen(auxPalavra)<32)){

			
				printf("%s - Linha %d\n", auxPalavra, cont_linha);

				clock_t Ticks[2];
    			Ticks[0] = clock();
				insereABB(auxPalavra, cont_linha, &raizABB);
			    Ticks[1] = clock();
				Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

    			clock_t Ticks1[2];
    			Ticks1[0] = clock();	
				insereLISTA(lista, auxPalavra , cont_linha);
				Ticks1[1] = clock();
				Tempo1 = (Ticks1[1] - Ticks1[0]) * 1000.0 / CLOCKS_PER_SEC;

				clock_t Ticks2[2];
    			Ticks2[0] = clock();
				insereAVL(raiz,auxPalavra, cont_linha);
				Ticks2[1] = clock();
				Tempo2 = (Ticks2[1] - Ticks2[0]) * 1000.0 / CLOCKS_PER_SEC;

				clock_t Ticks3[2];
    			Ticks3[0] = clock();
				insereHASH(auxPalavra,cont_linha, HASH);
				Ticks3[1] = clock();
				Tempo3 = (Ticks3[1] - Ticks3[0]) * 1000.0 / CLOCKS_PER_SEC;
			}
			ptr = strtok(NULL, delim);
		}
	}
	fclose(arqtexto);

	printf("\n########### LISTA ###########\n");
	printf("Tempo gasto para a lista: %g ms.\n", Tempo1);
	exibeLISTA(lista);
	
	printf("\n########### ABB ###########\n");
	printf("Tempo gasto para a arvore binaria: %g ms.\n", Tempo);
	emordemABB(raizABB);
	imprimeABB(raizABB,0);


	printf("\n############### AVL ##############\n");
	printf("Tempo gasto para a AVL: %g ms.\n", Tempo2);
	exibir_ordenadoAVL(raiz);

	printf("\n #################### HASH ####################\n");
	printf("Tempo gasto para a HASH: %g ms.\n", Tempo3);
	imprimeHASH(HASH);
	printf("\n");

	return 0;

}