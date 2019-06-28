struct reg {
	int linha[1000], cont; 
	char*  palavra;
	struct reg *prox; 
};
typedef struct reg NO;

void inicializa(NO **HASH);
int funcaohash(float chave);
void insereHASH(char* palavra,int linha, NO **HASH);
void inserelista(char* palavra, int linha,NO **HASH);
void imprimeHASH(NO **HASH);
// void percorrelista(int pos, NO **HASH);
int buscalista(char* palavra, NO **HASH);
void libera(NO **HASH);