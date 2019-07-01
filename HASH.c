//https://gist.github.com/divanibarbosa/d09dfedc344ef5bdf2020d0a3fdd68cc
/*
*   Hash
*
*   Estrutura da hash
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100000
#include"HASH.h"
#include<string.h>

int colisao=0;

/*
* 	Metodo da funcao hash 1, chave % tamanho.
*/
int funcaohash(float chave) {	
	return abs(chave) % TAM_MAX;
}

/*
*	Metodo da funcao hash 2, chave % 2, tentando
*	forcar a colisao.
*/
int funcaohash2(float chave) {	
	return abs(chave) % 2;
}

/*
* 	Metodo da funcao hash 3, método Horner.
*/
int funcaohash3(char* palavra) {
	int i, h = palavra[0];
	for (i = 1; palavra[i] != '\0'; i++) 
		h = h * 256 + palavra[i];
	return h % TAM_MAX;
}

/* 
*	Metodo para inicializar a hash com as posições iguais a NULL. 
*/
void inicializa(NO **HASH)
{
	int i;
	for(i=0; i<TAM_MAX; i++)
	{
		 HASH[i]=NULL;	
	}
}

/*
*	Metodo para inserir uma palavra na tabela open hash e as linhas
*	onde ela aparece.
*/
void insereHASH(char* palavra ,int linha, NO **HASH) { // argumentos: palavra a ser inserido e tabela HASH
	int num = 0; 
	//printf("%d\n", num);

	/* Encontra o tamanho da palavra. */
	for (int i = 0; i < strlen(palavra); ++i)
	{
		num += (palavra[i]);
	}

	int pos = funcaohash(num); // CALCULA POSIÇAO
	// int pos = funcaohash2(num); // CALCULA POSIÇAO
	// int pos = funcaohash3(palavra);
	
	if (HASH[pos] != NULL) { // se ocorreu colisao
		
		if (buscalista(palavra,HASH)) { // verificando se a chave ja existe
			
			// printf(" *** ATENCAO O palavra %s ja foi cadastrado ***", palavra);
			//printf(" - %d - ",linha );
	// 		(HASH[pos]) -> linha[(HASH[pos]) -> cont] = linha;
	// 		(HASH[pos]) -> cont++;
			
	// 		return;
		}
	}
	
	inserelista(palavra,linha,HASH);
}

/*
*	Metodo para iserir a palavra e as linhas na tabela de hash
*	exterior.
*/
void inserelista(char* palavra, int linha, NO **HASH) {
	
	int num = 0; 
	// printf("%d\n", num);

	/* Encontra o tamanho da palavra. */
	for (int i = 0; i < strlen(palavra); ++i)
	{
		num += (palavra[i]);
	}

	int pos = num;
	NO **lista = &HASH[pos];
	
	/* Se a lista estiver vazia insere a primeira palavra. */
	if (*lista == NULL) {
		*lista = (NO *) malloc(sizeof(NO));
  		if (*lista == NULL) {
			printf("\nErro alocacao memoria!");
			exit(1);
  		}

  		strcpy((*lista)-> palavra, palavra);
  		//(*lista)-> palavra = palavra;
  	  //	(*lista)-> linha[(*lista)->cont)] = linha;
  	  	(*lista)-> linha[0] = linha;
  		//(*lista)->cont++;
  		(*lista)->prox=NULL;
  		
  		//printf("-> Inserido HASH[%d]",pos);
 	}
	else { // Se ocorreu colisao
		// printf("-> Colisao HASH[%d]\n ",pos);
		colisao++;
		// printf("AQUI 1\n");
	    NO *guarda= HASH[pos]; // guardando posicao inicial ponteiro
		// printf("-> Antes - %s \n",(*lista) -> palavra);
		while ((*lista)->prox != NULL) {
		// Caminha para fim da lista caso contenha mais de 2 itens
			// printf("KKK\n");
			*lista=(*lista)->prox; 

		}

		// printf("-> Antes Colisao - %s \n",(*lista) -> palavra);
		(*lista)->prox=(NO *) malloc(sizeof(NO));
		if ((*lista)->prox == NULL) {
			printf("\nErro alocacao memoria!");
			exit(1);
	
  		}
  		
		*lista=(*lista)->prox;
  		strcpy((*lista)->palavra,palavra);
  		// (*lista)-> linha[(*lista)->cont] = linha;
  		// (*lista)->cont++;
  		(*lista)->prox=NULL; 
  		
  		HASH[pos]=guarda; // retornando ponteiro para a posiçao inicial
		// printf("-> Colisao - %s \n",(*lista) -> palavra);
	}
	
}

/*
*	Metodo para imprimir a tebala hash.
*/
void imprimeHASH(NO **HASH) { // Imprime tabela HASH
	int i;
	puts("");
	// printf("Quantidade de colisões: %d\n",colisao);
	for (i=0; i<TAM_MAX; i++) 
	{
		if (HASH[i] != NULL)
		{
			//printf("\n %s pos[%d] \n", HASH[i] -> palavra, i);
			percorrelista(i,HASH);
			// for (int j = 0; j < (HASH[i]) -> cont; ++j)
			// {
			// 	printf("%d\n",(HASH[i]) -> linha[j] );
			// }
		
		}
	}
}

/*
*	Metodo para buscar uma palavra na tabela hash.
*/
int buscalista(char* palavra, NO **HASH) {
	int num = 0; 

	// printf("%d\n", num);
	for (int i = 0; i < strlen(palavra); ++i)
	{
		num += (palavra[i]);
	}

	int pos = num;
	NO *lista = HASH[pos];
	while (lista != NULL) {
		if (strcmp(palavra, lista->palavra)==0) return 1; // Se encontrou retorna verdadeiro
		lista = lista->prox;
	}
	return 0;
}

void percorrelista(int pos, NO **HASH) { // Percorre lista imprimindo-a
	NO *lista = HASH[pos];
	while (lista != NULL) {
		//printf(" %.2f ->",lista->item);
		lista = lista->prox;
	}
} 