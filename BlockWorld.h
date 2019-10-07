#ifndef BLOCKWORLD_H_INCLUDED
#define BLOCKWORLD_H_INCLUDED

#include <stdio.h>

typedef int id_bloco;

typedef struct tipo_bloco{
    struct tipo_bloco *next;
    id_bloco id;
}TBlocos;

typedef struct{
    TBlocos *inicio,*fim;
}tipo_lista;

typedef tipo_lista *lista;

/*a funçao getComando lê cada comando escrito no arquivo, linha por linha e altera
  uma string passada por referencia escrevendo nela o comando lido.*/
int getComando(FILE*, char*);///Retorna 1 enquanto não chegar no final do arquivo.

int interpretaComando(lista, char*, int);

/*a função inicializa mundo recebe um inteiro que é o número total de blocos do mundo e retorna o vetor de listas do mundo.*/
lista inicializaMundo(const int);


#endif // BLOCKWORLD_H_INCLUDED
