#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extras.h"
#include "BlockWorld.h"

void removeBarraN(char *palavra){
    if(palavra[strlen(palavra)-1] == '\n')
        palavra[strlen(palavra)-1] = '\0';
}

void limpaTela(){
    system("clear || cls");
}

int inicio(){
    char comando[14];
    FILE *fc;
    int numeroBlocos;
    lista vlb;

    fc = fopen("entrada.txt","r");

    if(fc == NULL){
        return 0;
    }

    fseek(fc,0,SEEK_SET);

    getComando(fc,comando);

    removeBarraN(comando);

    numeroBlocos = atoi(comando);

    vlb = inicializaMundo(numeroBlocos);

    do{
        getComando(fc,comando);

        removeBarraN(comando);

    }while(interpretaComando(vlb,comando,numeroBlocos) != 0);

    return 1;
}

int getToken(char *palavra,tokens *t){

    sscanf(palavra,"%s %s %s %s",t->c1,t->a,t->c2,t->b);

    return 1;
}
