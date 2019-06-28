#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"AVL.h"
#include"HASH.h"
#include "lista.h"
#include"ABB.h"
#define TAM_MAX 100000

int compara(char* ptr, int cont_linha)
{
	FILE* arqPalavra = fopen("palavras.txt", "rt");
	char texto_str[256];
	// char* ptr2;
	// int cont_linha_palavras_chave;
	// char delim2[] = " ";
	
	int soma=0, soma2=0;
	while(fgets(texto_str, 256, arqPalavra) != NULL) 
	{
		char *pos;
		if ((pos=strchr(texto_str, '\n')) != NULL)
			*pos = '\0';

		printf("PAU %s\n", texto_str);

		printf(" COMPARAÇÃO #### %s %s \n",ptr, texto_str );

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
		//if (((soma == soma2)) && (strlen(ptr) > 4) && (strlen(ptr) <32))
			// printf("soma 1: %d soma 2: %d \n",soma,soma2 );
		if (soma == soma2)
		{	
			printf("soma IGUAL!\n");
			fclose(arqPalavra);
			return 0;
		}
	// 	    ptr2 = strtok(NULL, delim2);

	// 	    }
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
	//char delim2[] = "\n";
	char texto_str[256];
	char *ptr = malloc(32 * sizeof(*ptr));
	char *auxPalavra = malloc(32 * sizeof(*auxPalavra));
	Lista* lista = criaLISTA();
	
	NO *HASH[TAM_MAX];
    funcaohash(846.5);
	inicializa(HASH);

	//cont_linha = 0;

	
	FILE* arqtexto = fopen("texto.txt", "rt");
	if(arqtexto == NULL)
	{
	    printf("ERRO - algum arquivo não existe \n");
	    exit(1);
	}

	int	cont_linha = 0;
	while(fgets(texto_str, 256, arqtexto) != NULL) 
	{

		printf("##################################################\n");
		printf("### LINHA: %s\n", texto_str );
		ptr = strtok(texto_str, delim);
		cont_linha++;
		// printf("%s \n", texto_str);33
		// printf("%d \n", cont_linha);
		while(ptr != NULL)
		{
			// printf("QNTO DEU A FUNCAO DE COMPARA:  %d\n", compara(ptr, cont_linha));
			copy_string(auxPalavra, ptr);
			printf("### TEXTO: %s\n", ptr );

			ptr = strtok(NULL, delim);
			if(compara(auxPalavra, cont_linha) == 0){

				
				//  insereAVL(raiz, ptr, cont_linha); 
				// // printf(" INSERIDO: %s - %d\n", ptr, cont_linha );
				printf("%s - Linha %d\n", auxPalavra, cont_linha);
				// insereLISTA(lista, auxPalavra , cont_linha);
				// // printf(" INSERIDO: %s - %d\n", ptr, cont_linha );
				//  insereABB(auxPalavra, cont_linha, &raizABB);
				//  insereHASH(auxPalavra,cont_linha, HASH);
			}

		}
	}
	fclose(arqtexto);

	// printf("\n########### LISTA ###########\n");
	// // exibeLISTA(lista);
	
	printf("\n########### ABB ###########\n");
	/*ABB*/
	insereABB("banana",9, &raiz);
	insereABB("amora",4, &raizABB);
	insereABB("couve",3, &raizABB);
	insereABB("banana",3, &raiz);
	insereABB("amora",3, &raiz);
	insereABB("flor",5, &raiz);
	insereABB("vida",6, &raiz);
	insereABB("a",12, &raiz);

	// printf("\n\n");
	//imprimeABB(raizABB,0);
	//imprimeABB(raizABB, igual);
	emordemABB(raizABB);
	// imprime(raiz,0);
	// printf("\n\n");
	// imprime(raiz,1);
	// printf("\n\n");
	// imprime(raiz,2);

	printf("\n############### AVL ##############\n");


	insereAVL(raiz, "rodrigo", 5);
	imprimeAVL(raiz, 0);
	printf("&*\n");
	insereAVL(raiz,"gostoso", 3);
	imprimeAVL(raiz, 1);
	insereAVL(raiz,"lindo", 1);
	imprimeAVL(raiz, 2);
	insereAVL(raiz,"lindo", 2);
	imprimeAVL(raiz, 3);
	insereAVL(raiz,"amor", 1);
	imprimeAVL(raiz, 4);
	insereAVL(raiz,"amor", 5);
	imprimeAVL(raiz, 5);
	insereAVL(raiz,"vida", 6);
	imprimeAVL(raiz, 6);
	insereAVL(raiz,"meu", 1);
	imprimeAVL(raiz, 7);
	insereAVL(raiz,"amor", 1);
	insereAVL(raiz,"gato", 1);
	imprimeAVL(raiz, 8);
	insereAVL(raiz,"amor", 1);
	imprimeAVL(raiz, 9);
	printf("#########3%s\n",raiz ->palavra );
	exibir_ordenadoAVL(raiz);

	//  printf("\n #################### HASH ####################\n");
	// imprimeHASH(HASH);
	printf("\n");

	// insereHASH("rodrigo",3, HASH);
	// insereHASH("a",6, HASH);
	// insereHASH("a",8, HASH);
	// insereHASH("a",19, HASH);
	// insereHASH("v",3, HASH);
	// insereHASH("p",10, HASH);
	// insereHASH("l",15, HASH);
	// insereHASH("botina",15, HASH);
	// insereHASH("leremuitobomleremuitobomleremuitobomleremuitobomleremuitobom",15, HASH);

	// insereHASH("r",3, HASH);
	// insereHASH("pk",20, HASH);



	return 0;

}