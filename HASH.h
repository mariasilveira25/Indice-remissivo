/*
*   Hash
*
*   Estrutura da hash
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

/*
*	Estrutura da tabela hash que possui uma palavra
*	e as linhas que ela aparece.
*/
struct reg {
	int linha[1000], cont; 
	char palavra[32];
	struct reg *prox; 
};

typedef struct reg NO;

/* Metodos usados. */
void inicializa(NO **HASH);
int funcaohash(float chave);
void insereHASH(char* palavra,int linha, NO **HASH);
void inserelista(char* palavra, int linha,NO **HASH);
void imprimeHASH(NO **HASH);
// void percorrelista(int pos, NO **HASH);
int buscalista(char* palavra, NO **HASH);
void libera(NO **HASH);
void percorrelista(int pos, NO **HASH);