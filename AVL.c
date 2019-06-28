
//https://github.com/viniciusmarangoni/AVL-Tree/blob/master/avl.c
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"AVL.h"

struct arvore* insereAVL(struct arvore *aux1, char* palavra, int linha)
{
    struct arvore *aux2 = NULL;

    if(!raiz){

        raiz = (struct arvore*) malloc(sizeof(struct arvore));

        strcpy( raiz->palavra, palavra );
        raiz-> linha[raiz -> cont] = linha;
        raiz->cont++; 
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        raiz->pai = NULL;

        raiz->fb = 0;
    }

    else{
        aux1 = raiz;
        aux2 = aux1;

        while(aux2){
            if (strcmp( palavra, aux2->palavra ) == 0)
            {
                aux2-> linha[raiz -> cont] = linha;
                aux2->cont++; 

                break;
            }

            else if(strcmp( palavra, aux2->palavra ) < 0){

                aux2 = aux2->esquerda;

                if(!aux2){
                    aux1->esquerda = (struct arvore*) malloc(sizeof(struct arvore));

                    if(!aux1->esquerda){
                        printf("Erro ao alocar =(\n");
                        exit(1);
                    }

                    aux2 = aux1->esquerda;

                    aux2->esquerda = NULL;
                    aux2->direita = NULL;
                    aux2->pai = aux1;
                    strcpy( aux2->palavra, palavra);
                    //aux2->palavra = palavra;
                    //aux2-> linha[raiz -> cont] = linha;
                    //aux2->cont++; 

                    break;
                }
                else{
                    aux1 = aux2;
                }
            }

            else{

                aux2 = aux2->direita;

                if(!aux2){
                    aux1->direita = (struct arvore*) malloc(sizeof(struct arvore));

                    if(!aux1->direita){
                        printf("Erro ao alocar =(\n");
                        exit(1);
                    }

                    aux2 = aux1->direita;

                    aux2->esquerda = NULL;
                    aux2->direita = NULL;
                    aux2->pai = aux1;
                    strcpy( aux2->palavra, palavra );
                    //aux2->palavra = palavra;
                    //aux2-> linha[raiz -> cont] = linha;
                    //aux2->cont++; 
                    break;
                }

                else{
                    aux1 = aux2;
                }
            }
        }
    }

    printf("Elemento Inserido!\n");

    if(aux2){
        while(aux2){
            aux2->fb = alturaAVL(aux2->direita) - alturaAVL(aux2->esquerda);

            if(aux2->fb > 1 || aux2->fb < -1){
                aux2 = balanceiaAVL(aux2);
            }

            aux2 = aux2->pai;
        }
    }

    return aux1;
}


void exibir_ordenadoAVL(struct arvore *aux){
    
    if(!aux){
        return;
    }

    if(aux){
        exibir_ordenadoAVL(aux->esquerda);
        printf("#### %s - " , aux-> palavra);
        for (int i = 0; i < aux->cont; ++i)
        {
            printf("%d ", aux->linha[i]);
        }
        printf("\n");
        exibir_ordenadoAVL(aux->direita);
    }
   
}


void imprimeAVL(struct arvore *aux, int nivel)
{
    int i;
    if(aux == NULL)
        return;
    imprimeAVL(aux->direita, nivel+1);
    for(i=0;i<nivel;i++)
        printf("      ");
    printf("%s\n\n",aux->palavra);
    imprimeAVL(aux->esquerda,nivel+1);

}

struct arvore* buscaAVL(struct arvore *aux, char* palavra){

    aux = raiz;
    if (aux == NULL)
        return NULL;

    if (strcmp(palavra, aux->palavra) == 0)
        return (aux);

    if (strcmp(palavra,(aux)->palavra) < 0)
        return buscaAVL((aux->esquerda), palavra);
    
    else 
        return buscaAVL(aux->direita, palavra);
}


int alturaAVL(struct arvore *aux){
    if(!aux){
        return 0;
    }

    int ae = alturaAVL(aux->esquerda);
    int ad = alturaAVL(aux->direita);

    return (ae > ad) ? ae + 1: ad + 1;
}

struct arvore* rot_direitaAVL(struct arvore *aux){
    struct arvore *esquerda = aux->esquerda;

    aux->esquerda = esquerda->direita;
    esquerda->direita = aux;

    if(aux->esquerda){
        aux->esquerda->pai = aux;
    }

    esquerda->pai = aux->pai;
    aux->pai = esquerda;

    if(aux == raiz){
        raiz = esquerda;
    }

    if(esquerda->pai){
        if(strcmp(esquerda->palavra, esquerda->pai-> palavra) < 0 ){
            esquerda->pai->esquerda = esquerda;
        }
        else{
            esquerda->pai->direita = esquerda;
        }
    }

    esquerda->fb = alturaAVL(esquerda->direita) - alturaAVL(esquerda->esquerda);
    aux->fb = alturaAVL(aux->direita) - alturaAVL(aux->esquerda);

    return esquerda;
}

struct arvore* rot_esquerdaAVL(struct arvore *aux){
    struct arvore *direita = aux->direita;

    aux->direita = direita->esquerda;
    direita->esquerda = aux;

    if(aux->direita){
        aux->direita->pai = aux;
    }

    direita->pai = aux->pai;
    aux->pai = direita;

    if(aux == raiz){
        raiz = direita;
    }

    if(direita->pai){
        if(strcmp(direita->palavra, direita->pai-> palavra) < 0){
            direita->pai->esquerda = direita;
        }
        else{
            direita->pai->direita = direita;
        }
    }

    direita->fb = alturaAVL(direita->direita) - alturaAVL(direita->esquerda);
    aux->fb = alturaAVL(aux->direita) - alturaAVL(aux->esquerda);
    return direita;
}

struct arvore* balanceiaAVL(struct arvore *aux){
   
    if(aux->fb < -1){
        if(aux->esquerda->fb > 0){
            aux->esquerda = rot_esquerdaAVL(aux->esquerda);
        }

        aux = rot_direitaAVL(aux);
    }

    else if(aux->fb > 1){
        if(aux->direita->fb < 0){
            aux->direita = rot_direitaAVL(aux->direita);
        }

        aux = rot_esquerdaAVL(aux);
    }

    return aux;
}



