#include<stdio.h>
#include<stdlib.h>


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

Lista* criaLISTA();
void insereLISTA(Lista *P, char* palavra, int linha);
void exibeLISTA(Lista *lista);