#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

Lista* criaLISTA()
{
	Lista *P = (Lista*) malloc(sizeof(Lista));
	P -> inicio = NULL;
	P -> fim = NULL;
	P -> tam = 0;
	return P;
}

void insereLISTA(Lista *lista, char palavra[32], int linha)
{
	No *D = (No*) malloc(sizeof(No));
	D->li = 0;

	if(lista->inicio == NULL)
	{
		D->ant = NULL;
		D->prox = NULL;
		strcpy(D->palavra, palavra);
		//D->palavra = palavra;
		D->linha[D->li] = linha;
		D->li++;

		lista->inicio = D;
		lista->fim = D;
		lista->tam++;
	}
	// ultima palavra da lista menor que a palavra informada
	else if (strcmp(lista->fim->palavra, palavra) < 0) {
		D->ant = lista->fim;
		D->prox = NULL;
		strcpy(D->palavra, palavra);
		//D->palavra = palavra;
		D->linha[D->li] = linha;
		D->li++;

		lista->fim->prox = D;		
		lista->fim = D;
		lista->tam++;
	}
	// primeira palavra da lista 
	else if (strcmp(lista->inicio->palavra, palavra) > 0) {
		D->ant = NULL;
		D->prox = lista->inicio;
		strcpy(D->palavra, palavra);
		//D->palavra = palavra;
		D->linha[D->li] = linha;
		D->li++;

		lista->inicio = D;
		lista->tam++;
	}
	else {
		No *aux = lista->inicio;
		while(aux != NULL) {
			// inserir antes do aux
			// palavra da lista menor que a palavra informada
			if ((strcmp(aux->palavra, palavra) < 0) && (strcmp(aux->prox->palavra, palavra) > 0)) {
				D->ant = aux;
				D->prox = aux->prox;
				strcpy(D->palavra, palavra);
				//D->palavra = palavra;
				D->linha[D->li] = linha;
				D->li++;

				aux->prox->ant = D;
				aux->prox = D;
				lista->tam += 1;
				return;
			}
			else if (strcmp(aux->palavra, palavra) == 0) {
				aux->linha[aux->li] = linha;
				aux->li++;
				return;
			}
			aux = aux->prox;
		}
	}
}

// int* busca(char* busca) {
// 	No* aux = lista->inicio;
// 	while(aux != NULL) {
		
// 	}
// }

void exibeLISTA(Lista *lista)
{
	No* aux = lista->inicio;
	if (aux != NULL) 
	{
		while(aux != NULL)
		{
			printf("%s ", aux->palavra);
			for(int i = 0; i < aux->li; i++)
			{
				printf("%d ", aux->linha[i]);
			}
			printf("\n");
			aux = aux->prox;
		}
	}
}