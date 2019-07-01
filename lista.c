/*
*   Lista
*
*   Metodos da lista
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

/*
*	Metodo que cria a lista com uma celula cabeca.
*/
Lista* criaLISTA()
{
	Lista *P = (Lista*) malloc(sizeof(Lista));
	P -> inicio = NULL;
	P -> fim = NULL;
	P -> tam = 0;
	return P;
}

/*
*	Metodo para inserir uma celula na lista.
*	A celula eh inserida com uma palavra e a linha
*	one ela aparece.
*/
void insereLISTA(Lista *lista, char palavra[32], int linha)
{
	No *D = (No*) malloc(sizeof(No));
	D->li = 0;

	/* Se a lista estiver vazia, insere a primeira celula. */
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

	/*
	*	Se a ultima palavra da lista for menor que a palavra
	*	informada uma celula eh criada no final.
	*/
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

	/*
	*	Se a ultima palavra da lista for maior que a palavra
	*	informada uma celula eh criada no comeco.
	*/
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
				/*
				*	Se a palavra ja existir apenas acrescenta a linha que ela aparece.
				*/
				aux->linha[aux->li] = linha;
				aux->li++;
				return;
			}
			aux = aux->prox;
		}
	}
}

/*
*	Metodo para exibir a lista do comeco ao fim.
*/
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