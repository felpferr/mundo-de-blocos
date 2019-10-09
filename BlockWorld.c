#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BlockWorld.h"
#include "extras.h"
#include "move.h"
#include "pile.h"

///O(n);
lista inicializaMundo(const int ntb){
    lista vlb = (lista)malloc(sizeof(tipo_lista)*ntb);
    int i;

    if(vlb){
        for(i=0; i<ntb; i++){
            vlb[i].inicio = (TBlocos*)malloc(sizeof(TBlocos));
            vlb[i].inicio->id = i;
            vlb[i].inicio->next = NULL;
            vlb[i].fim = vlb[i].inicio;
        }
        return vlb;
    }
    else{
        return NULL;
    }
}

///O(n);
int getComando(FILE *fc, char *comando,int indice){

    fgets(comando,indice,fc);

    removeBarraN(comando);

    return 1;
}

///O(2n);
int interpretaComando(lista vlb,char *comando,int numeroBlocos){
    tokens t;
    int i;
    TBlocos *p;

    removeBarraN(t.c1);
    removeBarraN(t.a);
    removeBarraN(t.c2);
    removeBarraN(t.b);
    if(strcmp(comando,"quit") == 0)
        return 0;

    getToken(comando,&t);

    ///printf("\nComando interpretado: %s",comando);

    if(strcmp(t.c1,"move") == 0){
        Move(vlb,t,numeroBlocos);

        return 1;
    }
    else{
        Pile(vlb,t,numeroBlocos);
        return 1;
    }
}
