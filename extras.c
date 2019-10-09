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
    static int indice = 0;
    lista vlb;
    TBlocos *p;

    fc = fopen("entrada.txt","r");

    if(fc == NULL)
        fc = fopen("entrada.txt","w");


    fs = fopen("saida.txt","r");

    if(fs == NULL)
        fs = fopen("saida.txt","w");

    fseek(fc,0,SEEK_SET);

    getComando(fc,comando,indice);

    removeBarraN(comando);

    numeroBlocos = atoi(comando);

    vlb = inicializaMundo(numeroBlocos);

    do{
        indice += 15;
        getComando(fc,comando,indice);

    }while(interpretaComando(vlb,comando,numeroBlocos) != 0);

    p = vlb[0].inicio;
    /*for(i=0; i<numeroBlocos; i++){
        itoa(p->id,its,10);
        removeBarraN(its);

        printf("Numero %s\n",its);

        strcat(config,its);
        removeBarraN(config);

        printf("Comando %s\n",config);

        strcat(config,":");

        printf("%s",config);

        while(p){
            itoa(p->id,its,10);
            removeBarraN(its);
            strcat(config," ");
            strcat(config,its);
            p = p->next;
        }

        fseek(fs,0,SEEK_END);
        fwrite(config,14,0,fs);

        p = vlb[++i].inicio;
    }*/

    for(i=0; i<numeroBlocos;i++){
        printf("%d:",i);
        while(p){
            printf(" %d",p->id);
            p = p->next;
        }
        p = vlb[i].inicio;
        printf("\n");
    }

    return 1;
}

int getToken(char *palavra,tokens *t){
    printf("palavra: %s",palavra);

    strcpy(t->c1,strtok(palavra," "));
    printf("\nc1: %s",t->c1);

    strcpy(t->a,strtok(NULL," "));
    printf("\nA: %s",t->a);

    strcpy(t->c2,strtok(NULL," "));
    printf("\nc2: %s",t->c2);

    strcpy(t->b,strtok(NULL," "));
    printf("\nB: %s",t->b);

    return 1;
}
