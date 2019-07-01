/*
*   Arvore ABB
*
*   Estrutura da arvore ABB
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

/* 
*	Estrutura da arvore binaria de busca. Cada no
*	possui uma palavra de tamanho 32, um vetor que
*	contem os numeros das linhas e os apontadores
*	necessarios.
*/

typedef struct _no{
	char palavra[32];
	int linha[10000];
	int cont;

	struct _no *esq, *dir, *pai;
}no;

no *raizABB;

/* Metodos usados nessa estrutura. */
void vaziaArvore(no *raiz);
void insereABB (char* palavra, int linha, no **p);
int contarNosABB(no *p);
no* buscaABB(no **p, char* palavra);
void imprimeABB(no *p, int nivel);
void emordemABB(no *arvore);