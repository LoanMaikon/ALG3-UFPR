#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "hash.h"

#define TAM 11
#define MIN_HASH -10
#define EXCLUIDO -11

int h1(int chave)
{
    return (chave % TAM);
}

int h2(int chave)
{
    return floor(TAM * (chave * 0.9 - floor(chave * 0.9)));
}

void busca(int *t1, int *t2, int chave)
{
    int l1 = h1(chave);
    int l2 = h2(chave);

    if (chave == MIN_HASH || chave == EXCLUIDO)
        return;

    if (t1[l1] == chave)
        printf("%d,T1,%d\n",chave,l1);
    
    if (t2[l2] == chave)
        printf("%d,T2,%d\n",chave,l2);
}

void inclusao(int *t1, int *t2, int chave)
{
    int l1 = h1(chave);
    int l2 = h2(chave);
    int temp;

    /* chaves duplicadas */
    if (t1[l1] == chave || t2[l2] == chave)
        return;

    /* t1 não está com a posição ocupada */
    if (t1[l1] == MIN_HASH)
    {
        t1[l1] = chave;
    }

    /* t1 está com a posição ocupada */
    else if (t1[l1] != MIN_HASH)
    {
        temp = h2(t1[l1]);
        t2[temp] = t1[l1];
        t1[l1] = chave;
    }
}

void exclusao(int *t1, int *t2, int chave)
{
    int l1 = h1(chave);
    int l2 = h2(chave);

    /* está em t2 */
    if (t2[l2] == chave)
        t2[l2] = EXCLUIDO;

    /* está em t1 */
    else if (t1[l1] == chave)
        t1[l1] = EXCLUIDO;
}