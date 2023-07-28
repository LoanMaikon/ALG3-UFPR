typedef struct no
{
    struct no *esq;
    struct no *dir;
    int chave;
    int altura;
} no_t;

typedef struct arvore
{
    no_t *topo;
} arvore_t;

no_t *cria_no(int chave);

arvore_t *cria_arvore();

no_t *busca(no_t *no, int chave);

void emordem(no_t *no);

int altura(no_t *no);

int fator_balanceamento(no_t *no);

int maximo(int a, int b);

no_t *antecessor(no_t *no);

no_t *rotacao_direita(no_t *y);

no_t *rotacao_esquerda(no_t *x);

void inverter_altura(no_t *no, int altura);