#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"AVL.h"
#include"HASH.h"
#include "lista.h"
#include"ABB.h"
#define TAM_MAX 100000




char palavra(char texto_str2){
	char delim2[] = "\n";
	FILE* arqPalavra = fopen("palavras.txt", "rt");

		while(fgets(texto_str2, 256, arqPalavra) != NULL) 
		{
			// char *ptr2 = strtok(texto_str2, delim2);
			// while(ptr2 != NULL)
			// {
				printf("%s\n",texto_str2 );
				return texto_str2	
			
			// }
			//  ptr2 = strtok(NULL, delim2);

		}
}


	// FILE* arqPalavra = fopen("palavras.txt", "rt");
	// char texto_str2[256];
	// int igual, soma=0, soma2=0;
	// char* ptr2;
	// int cont_linha_palavras_chave;
	// char delim2[] = " ";
	
	// 	while(fgets(texto_str2, 256, arqPalavra) != NULL) 
	// 	{
	// 		char *ptr2 = strtok(texto_str2, delim2);
	// 		while(ptr2 != NULL)
	// 		{
	// 			printf("###### ARQUIVO PALAVRAS %s\n", ptr2);
	// 			//texto_str2 = strtok(texto_str2, "\n");
	// 			soma=0, soma2=0;

	// 	    	printf(" #### %s %s \n",ptr, ptr2 );
	// 	    	for (int i = 0; i < strlen(ptr2); ++i)
	// 			{
	// 				soma += (ptr2[i]);
	// 				soma2 += (ptr[i]);
	// 				printf("%d %d \n",soma,soma2 );
	// 				if (soma != soma2)
	// 				{
	// 					break;
	// 				}
	// 			}

	// 	    	if (((soma == soma2)) && (strlen(ptr) > 4) && (strlen(ptr) <32))
	// 	    	{	
	// 	    		printf("FECHOU!\n");			
	// 				fclose(arqPalavra);
	// 				return 0;
	// 	    	}
	// 	    ptr2 = strtok(NULL, delim2);

	// 	    }
	// 	}
	
	// fclose(arqPalavra);

//}

int main(int argc, char const *argv[])
{
	char delim[] = " ";
	char texto_str[256];
	int	cont_linha = 0;
	Lista* lista = criaLISTA();
	
	char texto_str2[256];
	int igual, soma=0, soma2=0;
	char* ptr2;
	int cont_linha_palavras_chave;
	//char delim2[] = " ";
	
	NO *HASH[TAM_MAX];
    funcaohash(846.5);
	inicializa(HASH);

	FILE* arqPalavra = fopen("palavras.txt", "rt");
	FILE* arqtexto = fopen("texto.txt", "rt");
	cont_linha = 0;

	if(arqtexto == NULL)
	{
	    printf("ERRO - algum arquivo não existe \n");
	    exit(1);
	}
	

	while(fgets(texto_str, 256, arqtexto) != NULL) 
	{

		cont_linha++;
		printf("%s\n", texto_str);
		char *ptr = strtok(texto_str, delim);
		while(ptr != NULL)

		{
		palavra();
					printf("###### ARQUIVO PALAVRAS %s\n", ptr2);
					//texto_str2 = strtok(texto_str2, "\n");
					soma=0, soma2=0;

			    	printf(" #### %s %s \n",ptr, ptr2 );
			    	for (int i = 0; i < strlen(ptr2); ++i)
					{
						soma += (ptr2[i]);
						soma2 += (ptr[i]);
						printf("%d %d \n",soma,soma2 );
						if (soma != soma2)
						{
							break;
						}
					}

			    	if (((soma == soma2)) && (strlen(ptr) > 4) && (strlen(ptr) <32))
			    	{	
					    insereAVL(raiz, ptr, cont_linha); 
						// printf(" INSERIDO: %s - %d\n", ptr, cont_linha );
						insereLISTA(lista, ptr , cont_linha);
						// printf(" INSERIDO: %s - %d\n", ptr, cont_linha );
						insereABB(ptr, cont_linha, &raizABB);
						insereHASH(ptr,cont_linha, HASH);			
														
			    	}
			   
		}
	}
	fclose(arqtexto);

	printf("\n########### LISTA ###########\n");
	//exibeLISTA(lista);
	
	printf("\n########### ABB ###########\n");
	/*ABB*/
	// insere("banana",9, &raiz);
	// insereABB("amora",4, &raizABB);
	// insereABB("couve",3, &raizABB);
	// insere("banana",3, &raiz);
	// insere("amora",3, &raiz);
	// insere("flor",5, &raiz);
	// insere("vida",6, &raiz);
	// insere("a",12, &raiz);

	// printf("\n\n");
	//imprimeABB(raizABB,0);
	//imprimeABB(raizABB, igual);
	//emordemABB(raizABB);
	// imprime(raiz,0);
	// printf("\n\n");
	// imprime(raiz,1);
	// printf("\n\n");
	// imprime(raiz,2);

	printf("\n############### AVL ##############\n");


	// insereAVL(raiz, "rodrigo", 5);
	// imprimeAVL(raiz, 0);
	// printf("&*\n");
	// insere(raiz,"gostoso", 3);
	// imprimeAVL(raiz, 1);
	// insere(raiz,"lindo", 1);
	// imprimeAVL(raiz, 2);
	// insere(raiz,"lindo", 2);
	// imprimeAVL(raiz, 3);
	// insere(raiz,"amor", 1);
	// imprimeAVL(raiz, 4);
	// insere(raiz,"amor", 5);
	// imprimeAVL(raiz, 5);
	// insere(raiz,"vida", 6);
	// imprimeAVL(raiz, 6);
	// insere(raiz,"meu", 1);
	// imprimeAVL(raiz, 7);
	// insere(raiz,"amor", 1);
	// insere(raiz,"gato", 1);
	// imprimeAVL(raiz, 8);
	// insere(raiz,"amor", 1);
	// imprimeAVL(raiz, 9);
	// printf("#########3%s\n",raiz ->palavra );
	//exibir_ordenadoAVL(raiz);

	 printf("\n #################### HASH ####################\n");
	//imprimeHASH(HASH);
	//printf("\n");

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