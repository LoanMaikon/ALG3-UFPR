Trabalho de algoritmos e estruturas de dados 3
Aluno: Luan Marko Kujavski
GRR: GRR20221236

O objetivo do trabalho é implementar um algoritmo Cuckoo Hashing, que é um algoritmo que usa como base o Hash. Nele, cada célula não vazia contém uma chave. A partir disso, usa-se uma função Hash para determinar a localização dessa chave.
Além disso, o Cuckoo Hashing usa duas tabelas de tamanhos iguais com duas funções de Hashing diferentes, sendo que a primeira tabela fornece dados mais recentes.

Para a execução correta do programa, foi criada uma biblioteca (hash.h) que contém função de inclusão, exclusão e busca de uma chave em uma das tabelas.

Para implementar a inclusão, foram seguidos os mesmos passos da especificação:
1.    A inclusão deve ser feita sempre em T1: Se a posição calculada por h1(k) estiver vazia ou marcada como "excluída", então insira a chave k.
2.    Senão, temos colisão em T1 e devemos realizar duas operações:
    1.    considere a chave atual como ki e a nova chave a ser inserida como kj e considere a colisão quando h1(ki) == h1(kj)
    2.    copiar ki que está em h1(ki) de T1 para T2. O objetivo é permitir inclusão da nova chave kj em T1 sem perder ki na colisão. A chave ki deverá ser incluida em T2 usando h2(ki).
    3.    incluir a nova chave kj na posição h1(kj) de T1.
3.    A estrutura deverá ignorar chaves duplicadas neste caso simplesmente mantendo a primeira chave inserida.

Na exclusão, também foram seguidos os passos da especificação:

1.    Podemos excluir qualquer chave de qualquer tabela. Considere que a chave a ser excluída ki existe em T1 ou T2.
2.    Se a chave ki estiver na posição calculada por h2(ki) em T2, então apenas exclua a chave ki de T2.
3.    Senão, a chave está na posição calculada por h1(ki) em T1. Neste caso precisamos ter cuidado, pois podem existir chaves inseridas em T2 que dependem de uma busca em T1 e se encontrarem um valor nul a busca retorna "chave inexistente". Então exclua ki de h1(ki) em T1 e marque a posição em T1 como "excluída" para que uma busca não encontre posição nula e devolva chave não encontrada. Não esqueça de alterar o algoritmo de busca para considerar o estado de "excluída".


A execução do programa se dá pelo comando:
1.    ./myht < entrada.txt
Onde entrada.txt é um arquivo em que cada linha contém uma operação (i de inclusão ou r de exclusão) e a chave da operação

A saída é dada na seguinte sequência:
chave, tabela(t1 ou t2), posição na tabela
