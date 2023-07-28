#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

/* CASO 1: altura(7) > altura(18) e 3 < 7   ***ZIG-ZIG***
        14                                          7
        / \                                        / \
       7   18                                     5   14
      / \            ==rotação direita==>        / \    \
     5   10                                     3   10    18
    /
  (3)
*/

/* CASO 2: altura(7) > altura(18) e 12 > 7   ***ZIG-ZAG***
        14                                   14                                  10
        / \                                 /  \                                 / \
       7   18                              10  18                               7   14
      / \       ==rotação esquerda==>     / \        ==rotação direita==>      /    / \
     5   10                              7  12                                5    12  18
          \                             /
          (12)                         5
*/

/* CASO 3: altura(7) < altura(18) e 24 > 14  ***ZIG-ZIG***
        14                                      18
        / \                                     / \
       7   18                                  14  20
           / \     ==rotação esquerda==>      /  \   \
         15   20                             7   15   24
               \             
               (24)        
*/

/* CASO 4 altura(16) ***ZIG-ZAG***
           z                                       z                                  x
          / \                                     / \                                /  \ 
        T1   y                                  T1   x                             z      y
            / \       ==rotação direita==>         /  \  ==rotação esquerda==>    / \    / \
           x   T4                                 T2   y                        T1  T2  T3  T4
          / \                                         /  \
        T2   T3                                      T3   T4 
*/

no_t *inclusao(no_t *topo, int chave)
{
    if (topo == NULL)
        return cria_no(chave);

    if (topo->chave > chave)
        topo->esq = inclusao(topo->esq,chave);
    
    if (topo->chave < chave)
        topo->dir = inclusao(topo->dir,chave);
    
    /* arrumando as alturas de cada no_t recursivamente */
    topo->altura = 1 + maximo(altura(topo->esq),altura(topo->dir));

    /* balanceamento */
    if (fator_balanceamento(topo) > 1) /* altura esquerda > altura direita */
    {
        if (chave < topo->esq->chave) /* CASO 1 */
            return rotacao_direita(topo);
            
        else
        if (chave > topo->esq->chave) /* CASO 2 */
        {
            topo->esq = rotacao_esquerda(topo->esq);
            return rotacao_direita(topo);
        }
    }
    else
    if (fator_balanceamento(topo) < -1) /* altura esquerda < altura direita */
    {
        if (chave > topo->dir->chave) /* CASO 3 */
            return rotacao_esquerda(topo);
        else
        if (chave < topo->dir->chave) /* CASO 4 */
        {
            topo->dir = rotacao_direita(topo->dir);
            return rotacao_direita(topo);
        }
    }

    return topo;
}

no_t *exclusao(no_t *topo, int chave)
{
    no_t *aux;

    if (topo == NULL)
        return topo;

    if (topo->chave > chave)
        topo->esq = exclusao(topo->esq,chave);
    
    else if (topo->chave < chave)
        topo->dir = exclusao(topo->dir,chave);

    else if (topo->chave == chave)
    {
        if (topo->dir == NULL && topo->esq == NULL) /* CASO 1 topo nao tem filhos */
        {
            aux = topo;
            topo = NULL;
            free(aux);
        }

        else if (topo->dir == NULL && topo->esq != NULL) /* CASO 2 topo tem um filho esquerdo */
        {
            aux = topo->esq;

            memcpy(topo,aux,sizeof(no_t));

            free(aux);
        }

        else if (topo->dir != NULL && topo->esq == NULL) /* CASO 3 topo tem um filho direito */
        {
            aux = topo->dir;

            memcpy(topo,aux,sizeof(no_t));

            free(aux);
        }

        else if (topo->dir != NULL && topo->esq != NULL) /* CASO 4 topo tem dois filhos */
        {
            aux = antecessor(topo);

            topo->chave = aux->chave;

            topo->esq = exclusao(topo->esq,aux->chave); /* entra no caso 1 ou 3 */
        }
    }

    if (topo == NULL)
        return topo;

    /* arrumando as alturas de cada no_t recursivamente */
    topo->altura = 1 + maximo(altura(topo->esq),altura(topo->dir));

    /* balanceamento */
    if (fator_balanceamento(topo) > 1) /* altura esquerda > altura direita */
    {
        if (fator_balanceamento(topo->esq) >= 0)
            return rotacao_direita(topo);
        
        if (fator_balanceamento(topo->esq) < 0)
        {
            topo->esq = rotacao_esquerda(topo->esq);
            return rotacao_direita(topo->dir);
        }
    }
    else
    if (fator_balanceamento(topo) < -1) /* altura esquerda < altura direita */
    {
        if (fator_balanceamento(topo->dir) <= 0)
            return rotacao_esquerda(topo->esq);
        
        if (fator_balanceamento(topo->esq) > 0)
        {
            topo->dir = rotacao_direita(topo->dir);
            return rotacao_esquerda(topo->esq);
        }
    }

    return topo;
}

int main()
{
    char *str;
    char operacao;
    int chave;
    arvore_t *arvore;

    if (!(str = malloc(100 * sizeof(char))))
        return 1;

    arvore = cria_arvore();

    /* para pegar o stdin */
    while (fgets(str,100,stdin))
    {
        sscanf(str,"%c %d",&operacao,&chave);

        if (operacao == 'i')
            arvore->topo = inclusao(arvore->topo,chave);
        else if (operacao == 'r')
            arvore->topo = exclusao(arvore->topo,chave);
    }

    inverter_altura(arvore->topo,0);

    emordem(arvore->topo);

    free(str);

    return 0;
}