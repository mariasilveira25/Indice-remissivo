
struct arvore{
    int linha[1000], fb, cont;
    char palavra[32];
    struct arvore *esquerda;
    struct arvore *direita;
    struct arvore *pai;
};


struct arvore *raiz;

struct arvore* insereAVL(struct arvore *aux1, char* palavra, int linha);
void exibir_ordenadoAVL(struct arvore *aux);
struct arvore* buscaAVL(struct arvore *aux, char* palavra);
int alturaAVL(struct arvore *aux);
struct arvore* rot_direitaAVL(struct arvore *aux);
struct arvore* rot_esquerdaAVL(struct arvore *aux);
struct arvore* balanceiaAVL(struct arvore *aux);
void imprimeAVL(struct arvore *aux, int nivel);
