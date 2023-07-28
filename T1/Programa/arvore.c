#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

no_t *cria_no(int chave)
{
    no_t *no;

    no = malloc(sizeof(no_t));

    no->dir = NULL;
    no->esq = NULL;
    no->chave = chave;
    no->altura = 0;

    return no;
}

arvore_t *cria_arvore()
{
    arvore_t *arvore;

    arvore = malloc(sizeof(arvore_t));

    arvore->topo = NULL;

    return arvore;
}

/* no recebe o topo da arvore */
no_t *busca(no_t *no, int chave)
{
    if (! no)
        return NULL;
    
    if (chave == no->chave)
        return no;
    
    if (chave < no->chave)
        return busca(no->esq,chave);
    return busca(no->dir,chave);
}

void emordem(no_t *no)
{
    if (! no)
        return;
    
    emordem(no->esq);

    printf("%d,%d\n",no->chave,no->altura);

    emordem(no->dir);
}

int altura(no_t *no)
{
    if (no == NULL)
        return -1;
    return no->altura;
}

int fator_balanceamento(no_t *no)
{
    int fator;

    fator = altura(no->esq) - altura(no->dir);

    return fator;
}

int maximo(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

no_t *antecessor(no_t *no)
{
    no_t *aux = no->esq;

    while (aux->dir != NULL)
        aux = aux->dir;
    
    return aux;
}

/*
         y                               x
        / \     Right Rotation          /  \
       x   T3   - - - - - - - >        T1   y 
      / \       < - - - - - - -            / \
     T1  T2     Left Rotation            T2  T3
*/

no_t *rotacao_direita(no_t *y)
{
    no_t *x;
    no_t *t;

    x = y->esq;
    t = x->dir;

    /* rotacao */
    x->dir = y;
    y->esq = t;

    /* recalculando as alturas */
    y->altura = maximo(altura(y->dir),altura(y->esq)) + 1;
    x->altura = maximo(altura(x->dir),altura(x->esq)) + 1;

    return x; /* x e a nova raiz */
}

no_t *rotacao_esquerda(no_t *x)
{
    no_t *y;
    no_t *t;

    y = x->dir;
    t = y->esq;

    /* rotacao */
    y->esq = x;
    x->dir = t;

    /* recalculando as alturas */
    y->altura = maximo(altura(y->dir),altura(y->esq)) + 1;
    x->altura = maximo(altura(x->dir),altura(x->esq)) + 1;

    return y; /* y e a nova raiz */
}

void inverter_altura(no_t *no, int altura)
{
    if (! no)
        return;
    
    inverter_altura(no->esq,altura+1);

    no->altura = altura;

    inverter_altura(no->dir,altura+1);
}