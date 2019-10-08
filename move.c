#include <stdlib.h>
#include <string.h>
#include "move.h"
#include "BlockWorld.h"

int Move(lista vlb, tokens t,int numeroBlocos){
    TBlocos *p,*aux1,*aux2;
    int i,a,b;

    if(strcmp(t.a,t.b) == 0){///Se 'a' for igual a 'b' o comando é pulado.
        return 0;
    }

    a = atoi(t.a);
    b = atoi(t.b);

    if(strcmp(t.c2,"onto") == 0){

        for(i=0; i<numeroBlocos; i++){
            p = vlb[i].inicio;

            while(p){
                if(p->id == a)///busca no vetor a referencia do elemento a ser movido.
                    aux1 = p;

                if(p->id == b)///busca no vetor a referencia do elemento para onde o elemento será movido.
                    aux2 = p;

                p = p->next;
            }

        }

        p = aux2->next;
        while(p){
            vlb[p->id].inicio = p;
            p = p->next;
        }
        vlb[aux2->id].fim = aux1;

        p = aux1->next;
        while(p){
            vlb[p->id].inicio = p;
            p = p->next;
        }

        aux1->next = NULL;

        return 1;

    }
    else{
        if(strcmp(t.c2,"over") == 0){
            for(i=0; i<numeroBlocos; i++){
                p = vlb[i].inicio;

                while(p){
                    if(p->id == a)///busca no vetor a referencia do elemento a ser movido.
                        aux1 = p;

                    if(p->id == b)///busca no vetor a referencia do elemento para onde o elemento será movido.
                        aux2 = p;

                    p = p->next;
                }

            }

            p = aux1;
            while(p->next){
                p = aux1->next;
            }

            p->next = aux2;
            aux2->next = NULL;

            return 1;
        }
    }
    return 0;
}
