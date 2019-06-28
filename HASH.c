//https://gist.github.com/divanibarbosa/d09dfedc344ef5bdf2020d0a3fdd68cc

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 100000
#include"HASH.h"
#include<string.h>


int funcaohash(float chave) {	
	return abs(chave) % TAM_MAX;
}

void inicializa(NO **HASH)
{
	int i;
	for(i=0; i<TAM_MAX; i++)
	{
		 HASH[i]=NULL;	
	}
}

void insereHASH(char* palavra ,int linha, NO **HASH) { // argumentos: palavra a ser inserido e tabela HASH
	int num = 0; 
	printf("%d\n", num);
	for (int i = 0; i < strlen(palavra); ++i)
	{
		num += (palavra[i]);
	}
	int pos = funcaohash(num); // CALCULA POSIÇAO
	
	if (HASH[pos] != NULL) { // se ocorreu colisao
		
		if (buscalista(palavra,HASH)) { // verificando se a chave ja existe
			
			//printf(" *** ATENCAO O palavra %s ja foi cadastrado ***", palavra);
			(HASH[pos]) -> linha[(HASH[pos]) -> cont] = linha;
			(HASH[pos]) -> cont++;
			
			return;
		}
	}
	
	inserelista(palavra,linha,HASH);
}

void inserelista(char* palavra, int linha,NO **HASH) {
	
	int num = 0; 
	printf("%d\n", num);
	for (int i = 0; i < strlen(palavra); ++i)
	{
		num += (palavra[i]);
	}

	int pos = num;
	NO **lista = &HASH[pos];
	printf("%d\n", pos);
	
	if (*lista == NULL) {
			*lista = (NO *) malloc(sizeof(NO));
  		if (*lista == NULL) {
			printf("\nErro alocacao memoria!");
			exit(1);
  		}
  		printf("%s\n",palavra );

  		//strcpy((*lista)-> palavra, palavra);
  		(*lista)-> palavra = palavra;

  	  		(*lista)-> linha[(*lista)->cont] = linha;
  		(*lista)->cont++;
  		(*lista)->prox=NULL;
  		
  		printf("-> Inserido HASH[%d]",pos);
 	}
	else { // Se ocorreu colisao
		printf("-> Colisao  HASH[%d]",pos);
	
	    NO *guarda= HASH[pos]; // guardando posicao inicial ponteiro
		while ((*lista)->prox != NULL) 
		// Caminha para fim da lista caso contenha mais de 2 itens
			*lista=(*lista)->prox; 

		(*lista)->prox=(NO *) malloc(sizeof(NO));
		if ((*lista)->prox == NULL) {
			printf("\nErro alocacao memoria!");
			exit(1);
	
  		}
  		
		*lista=(*lista)->prox;
  		(*lista)->palavra=palavra;
  		(*lista)-> linha[(*lista)->cont] = linha;
  		(*lista)->cont++;
  		(*lista)->prox=NULL; 
  		
  		HASH[pos]=guarda; // retornando ponteiro para a posiçao inicial
	}
	
}

void imprimeHASH(NO **HASH) { // Imprime tabela HASH
	int i;
	puts("");
	for (i=0; i<TAM_MAX; i++) 
	{
		if (HASH[i] != NULL)
		{
			printf("\n %s", HASH[i] -> palavra);
			// for(int i = 0; i < HASH[i]->cont; i++)
			// {
			// 	printf("%d ", HASH[i]->linha[i]);
			// }
		}
	}
}

int buscalista(char* palavra, NO **HASH) {
	int num = 0; 
	printf("%d\n", num);
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



