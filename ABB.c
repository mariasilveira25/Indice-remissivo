/*https://github.com/AlefeVariani/Basic-C/blob/master/arvores/arvore.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ABB.h"


int quantidadeNos = 0;


no* auxPai = NULL;

void vaziaArvore(no *raiz)
{
	if (raiz == NULL)
	{
		printf("   A arvore esta vazia\n\n");
	}
	else 
	{
		printf("   A arvore nao esta vazia\n\n");
	}
}

void insereABB(char* palavra, int linha, no **p)
{


	if (*p==NULL){
		*p=(no *)malloc(sizeof(no));
		(*p)->palavra = palavra;
		
		(*p)->linha[ (*p)-> cont ]= linha;
		(*p)->dir=NULL;
		(*p)->esq=NULL;
		(*p)->pai = auxPai;
	}
	else
	{


		if (strcmp(palavra,(*p)->palavra) == 0)
		{
			
			auxPai = *p;
			(*p)->linha[(*p)->cont] = linha;
			(*p) -> cont++;

		}

		if(strcmp( palavra, (*p)->palavra ) > 0);
		{
			
			auxPai = *p;
			insereABB(palavra,linha, &(*p)->dir);
		}

		if(strcmp( palavra, (*p)->palavra ) < 0)
		{
			
			auxPai = *p;
			insereABB(palavra,linha, &(*p)->esq);
		}
	}

}
int contarNosABB(no *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + contarNosABB(p->esq) + contarNosABB(p->dir);
}

no* buscaABB(no **p, char* palavra){
	if (p == NULL)
		return NULL;
	if (strcmp(palavra,(*p)->palavra) == 0)
		return (*p);
	if (strcmp(palavra,(*p)->palavra) < 0)
		return buscaABB(&(*p)->esq, palavra);
	else 
		return buscaABB(&(*p)->dir, palavra);
}




void imprimeABB(no *p, int nivel)
{
	int i;
	if(p == NULL)
		return;
	imprimeABB(p->dir, nivel+1);
	for(i=0;i<nivel;i++)
		printf("      ");
	printf("%s\n\n",p->palavra);
	imprimeABB(p->esq,nivel+1);

}



void emordemABB(no *arvore)
{
	if(arvore != NULL){
		emordemABB(arvore->esq);
		printf("%s",arvore->palavra);
			for (int i = 0; i < arvore-> cont; ++i)
			{
				printf(" %d ", arvore -> linha[i]);
			}
		printf("\n");
		emordemABB(arvore->dir);
	}
}



