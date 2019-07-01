/*https://github.com/AlefeVariani/Basic-C/blob/master/arvores/arvore.c*/
/*
*   Arvore ABB
*
*   Metodos da arvore ABB
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"ABB.h"


int quantidadeNos = 0;
no* auxPai = NULL;

/* Metodo para verificar se a arvore ABB esta vazia. */
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

/* 
*	Metodo para inserir um no na arvore ABB. 
*	Usando uma palavra e a linha que ela aparece.
*/
void insereABB(char* palavra, int linha, no **p)
{
	/* Se a arvore estiver vazia insere o primeiro no. */
	if (*p==NULL){
		*p=(no *)malloc(sizeof(no));
		// (*p)->palavra = palavra;
		strcpy((*p)->palavra, palavra);
		(*p)->linha[ (*p)-> cont ]= linha;
		(*p)-> cont++;
		(*p)->dir=NULL;
		(*p)->esq=NULL;
		(*p)->pai = auxPai;
	}
	else
	{
		/* 
		*	Se a palavra a ser inserida ja estiver em algum no, 
		*	apenas acresenta o numero da linha em que ela aparece.
		*/
		if (strcmp(palavra,(*p)->palavra) == 0)
		{			
			(*p)->linha[(*p)->cont] = linha;
			(*p) -> cont++;
		}

		/* 
		*	Se a palavra a ser inserida nao estiver em algum no e
		*	seu tamanho for maior que a ja inserida, entao eh inserido
		*	a direita.
		*/
		if(strcmp( palavra, (*p)->palavra ) > 0)
		{
			auxPai = *p;
			insereABB(palavra,linha, &(*p)->dir);
		}

		/* 
		*	Se a palavra a ser inserida nao estiver em algum no e
		*	seu tamanho for menor que a ja inserida, entao eh inserido
		*	a esquerda.
		*/
		if(strcmp( palavra, (*p)->palavra ) < 0)
		{
			auxPai = *p;
			insereABB(palavra,linha, &(*p)->esq);
		}
	}
}

/* Metodo para contar a quantidade de nos na arvore ABB. */
int contarNosABB(no *p)
{
	if(p == NULL)
		return 0;
	else
		return 1 + contarNosABB(p->esq) + contarNosABB(p->dir);
}

/* Metodo para buscar uma palavra na arovre ABB. */
no* buscaABB(no **p, char* palavra){
	if (p == NULL)
		return NULL;
	if (strcmp(palavra,(*p)->palavra) == 0)	/* Se a palavra for encontrada retorna. */
		return (*p);
	if (strcmp(palavra,(*p)->palavra) < 0)	/* Busca a palavra na arove ABB. */
		return buscaABB(&(*p)->esq, palavra);
	else 
		return buscaABB(&(*p)->dir, palavra);
}

/* Metodo para imprimir a arvore ABB por nivel. */
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

/* 
*	Metodo para exibir a arvore ABB em ordem, usando 
*	a recursividade e InOrdem.
*/
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