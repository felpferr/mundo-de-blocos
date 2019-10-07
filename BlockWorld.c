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

///TESTAR ESSA FUNÇÃO DEPOIS!!!
///O(n);
int getComando(FILE *fc, char *comando){

    fseek(fc,0,SEEK_CUR);

    while(fread(comando,14,1,fc) == 1){
        return 1;
    }

    return 1;
}

///O(2n);
int interpretaComando(lista vlb,char *comando,int numeroBlocos){
     tokens t;

    if(strcmp(comando,"quit") == 0)
        return 0;

    if(strcmp(comando,"move") == 0){
        getToken(comando,t);
        Move(vlb,t,numeroBlocos);
        return 1;
    }
    else{
        getToken(comando,t);
        Pile(vlb,t,numeroBlocos);
        return 1;
    }
}
