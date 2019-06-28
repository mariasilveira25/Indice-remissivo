
typedef struct _no{
	char palavra[32];
	int linha[1000];
	int cont;

	struct _no *esq, *dir, *pai;
}no;

no *raizABB;

void vaziaArvore(no *raiz);
void insereABB (char* palavra, int linha, no **p);
int contarNosABB(no *p);
no* buscaABB(no **p, char* palavra);
void imprimeABB(no *p, int nivel);
void emordemABB(no *arvore);
