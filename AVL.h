/*
*   Arvore AVL
*
*   Estrutura da arvore AVL
*
*	Alunos: Elias Eduardo Silva Rodrigues, 0015920
*			Maria Eduarda da Silveira,     0035483
*/

/* 
*	Cada no da arvore contem uma palavra de tamanho 32, 
*	um vetor que contem os numeros das linhas que ela aparece,
*	o FB e os apontadores necessarios.
*/

struct arvore{
    int linha[10000], fb, cont;
    char palavra[32];
    struct arvore *esquerda;
    struct arvore *direita;
    struct arvore *pai;
};


struct arvore *raiz;

/* Cabecalho dos metodos usados nessa estrutura. */
struct arvore* insereAVL(struct arvore *aux1, char* palavra, int linha);
void exibir_ordenadoAVL(struct arvore *aux);
struct arvore* buscaAVL(struct arvore *aux, char* palavra);
int alturaAVL(struct arvore *aux);
struct arvore* rot_direitaAVL(struct arvore *aux);
struct arvore* rot_esquerdaAVL(struct arvore *aux);
struct arvore* balanceiaAVL(struct arvore *aux);
void imprimeAVL(struct arvore *aux, int nivel);