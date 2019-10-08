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
    char comando[14], config[256], its[5];
    FILE *fc,*fs;
    int numeroBlocos, i;
    lista vlb;
    TBlocos *p;

    fc = fopen("entrada.txt","r");

    if(fc == NULL)
        fc = fopen("entrada.txt","w");


    fs = fopen("saida.txt","r");

    if(fs == NULL)
        fs = fopen("saida.txt","w");

    fseek(fc,0,SEEK_SET);

    getComando(fc,comando);

    removeBarraN(comando);

    numeroBlocos = atoi(comando);

    vlb = inicializaMundo(numeroBlocos);

    do{
        getComando(fc,comando);

        removeBarraN(comando);
        ///printf("\nComando: %s\n",comando);

    }while(interpretaComando(vlb,comando,numeroBlocos) != 0);

    /*p = vlb[0].inicio;
    for(i=0; i<numeroBlocos; i++){
        itoa(p->id,its,10);
        removeBarraN(its);
        strcat(config,its);
        removeBarraN(config);
        strcat(config,":");

        while(p){

        }
    }*/

    return 1;
}

int getToken(char *palavra,tokens *t){

    sscanf(palavra,"%s %s %s %s",t->c1,t->a,t->c2,t->b);

    return 1;
}
