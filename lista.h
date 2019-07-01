/*
*   Lista
*
*   Estrutura da lista
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

#include<stdio.h>
#include<stdlib.h>

/*
*	Estrutura da lista onde cada celula possui
*	uma palavra e um vetor com as linhas.
*/
struct no
{
	char palavra[32];
	int linha[1000];
	int li;
	struct no *prox;
	struct no *ant;
};

struct lista
{
	int tam;
	struct no *inicio;
	struct no *fim;
};

typedef struct no No;

typedef struct lista Lista;

/* Metodos usados. */
Lista* criaLISTA();
void insereLISTA(Lista *P, char* palavra, int linha);
void exibeLISTA(Lista *lista);