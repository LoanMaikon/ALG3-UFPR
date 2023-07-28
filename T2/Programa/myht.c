#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

#define BUFFERSIZE 100
#define TAM 11
#define MIN_HASH -10

int compara(const void *a, const void *b)
{
    int *valor1 = (int*) a;
    int *valor2 = (int*) b;

    if (*valor1 > *valor2)
        return 1;
    else if (*valor1 < *valor2)
        return -1;
    return 0;
}

int main()
{
    char *str;
    char operacao;
    int chave;
    int *t1;
    int *t2;
    int *t;
    int i;
    int j;

    t1 = malloc(TAM * sizeof(int));
    t2 = malloc(TAM * sizeof(int));
    t = malloc(2 * TAM * sizeof(int));
    str = malloc(BUFFERSIZE * sizeof(char));

    /* preenchendo os vetores com MIN_HASH */
    i = 0;
    while (i < TAM)
    {
        t1[i] = MIN_HASH;
        t2[i] = MIN_HASH;
        i++;
    }

    /* para pegar o stdin */
    while (fgets(str,BUFFERSIZE,stdin))
    {
        sscanf(str,"%c %d",&operacao,&chave);

        if (operacao == 'i')
            inclusao(t1,t2,chave);
        else if (operacao == 'r')
            exclusao(t1,t2,chave);
    }

    /* colocando t1 e t2 em t */
    i = 0;
    while (i < TAM)
    {
        t[i] = t1[i];
        i++;
    }

    j = 0;
    while (j < TAM)
    {
        t[i] = t2[j];
        j++;
        i++;
    }

    /* ordenando t */
    qsort(t,2 * TAM,sizeof(int),compara);

    /* imprimindo */
    i = 0;
    while (i < (2 * TAM))
    {
        busca(t1,t2,t[i]);
        i++;
    }

    free(str);
    free(t1);
    free(t2);
    free(t);

    return 0;
}