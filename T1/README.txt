Trabalho de algoritmos e estruturas de dados 3
Aluno: Luan Marko Kujavski
GRR: GRR20221236

O objetivo do trabalho é implementar uma árvore AVL (Adelson Velsky Landis), que é uma árvore de busca balanceada na qual a altura de cada par de subárvores não difere de 1.
Para isso, devemos implementar funções que incluam e excluam chaves da árvore e, depois de cada operação, rebalanceiem-na.

Para o programa, foram criadas duas structs (arvore_t e no_t)
A struct "arvore_t" serve para armazenar um ponteiro para a raíz da árvore.
A struct "no_t" serve para armazenar a chave e a altura de cada nó, um ponteiro para o filho da direita e um para o filho da esquerda.

Também foram criadas funções (que estão na biblioteca arvore.h) que são usadas para auxiliar as operações de inclusão e exclusão:
no_t *cria_no(int chave): aloca memória para um nó e coloca valores iniciais nele.
arvore_t *cria_arvore(): aloca memória para a árvore.
no_t *busca(no_t *no, int chave): busca uma chave em uma árvore.
void emordem(no_t *no): imprime a árvore em ordem.
int altura(no_t *no): retorna a altura do nó.
int fator_balanceamento(no_t *no): retorna o fator de balanceamento do nó.
int maximo(int a, int b): retorna o maior valor entre "a" e "b".
no_t *antecessor(no_t *no): retorna o antecessor da chave do nó.
no_t *rotacao_direita(no_t *y): retorna uma rotação à direita do nó.
no_t *rotacao_esquerda(no_t *x): retorna uma rotação à esquerda do nó.
void inverter_altura(no_t *no, int altura): inverte a altura de cada nó da árvore para a altura da raíz começar em 0. A função foi criada para seguir a especificação do trabalho.


IMPLEMENTAÇÃO DA INCLUSÃO:
A função de inclusão é recursiva (caminha das folhas até a raíz).
1.   "pathing" de onde o nó será inserido e, quando nó == NULL, cria o nó e retorna ele para seguir com o balanceamento.
2.   Cálculo da altura do nó, que no caso é a soma de um com o maior valor entre o filho da direita e o filho da esquerda, já que, como a função de inclusão é recursiva, o cálculo da altura começa nas folhas (altura 0).
3.   Cálculo do fator de balanceamento, que é a altura do filho esquerdo menos a altura do filho direito.
4.   Balanceamento seguindo as seguintes regras (OBS: cada caso é exemplificado no início de myavl.c):
Se fator_balanceamento(nó) > 1
    Se chave < nó->esquerdo->chave
        CASO 1 (zig-zig)
    Se chave > nó->esquerdo->chave
        CASO 2 (zig-zag)
Se fator_balanceamento(nó) < 1
    Se chave > nó->direito->chave
        CASO 3 (zig-zig)
    Se chave < nó->direito->chave
        CASO 4 (zig-zag)


IMPLEMENTAÇÃO DA EXCLUSÃO:
A função de exclusão é recursiva (caminha das folhas até a raíz).
1.   Busca o nó com a chave que será excluída.
2.   Quando o nó é encontrado, a função verifica se o nó tem dois filhos, somente um filho esquerdo, somente um filho direito ou nenhum filho.
      1.   Se o nó tem dois filhos, a função faz o transplante com o antecessor e usa a mesma função para excluir a chave, também fazendo um recálculo de altura.
      2.   Se o nó tem somente um filho, a função copia a memória desse filho e insere no próprio nó onde está o recursão.
      3.   Se o nó não tem nenhum filho, simplesmente libera a memória desse nó.
3.   Cálculo da altura do nó, que no caso é a soma de um com o maior valor entre o filho da direita e o filho da esquerda.
4.   Cálculo do fator de balanceamento do nó, seu filho direito e seu filho esquerdo seguindo as seguintes regras:
Se fator_balanceamento(nó) > 1
    Se fator_balanceamento(nó->esquerdo) >= 0
        CASO 1 (zig-zig)
    Se fator_balanceamento(nó->esquerdo) < 0
        CASO 2 (zig-zag)
Se fator_balanceamento(nó) < -1
    Se fator_balanceamento(nó->direito) <= 0
        CASO 3 (zig-zig)
    Se fator_balanceamento(nó->esquerdo) > 0)
        CASO 4 (zig-zag)


Referências para o projeto:
https://www.geeksforgeeks.org/introduction-to-avl-tree/
https://github.com/Marcosddf/algoritmoseestruturasdedados
