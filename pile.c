#include <stdlib.h>
#include <string.h>
#include "BlockWorld.h"
#include "extras.h"
#include "pile.h"

int Pile(lista vlb,tokens t, int numeroBlocos){
    TBlocos *p, *aux1, *aux2;
    int i,a,b;

    if(strcmp(t.a,t.b) == 0){
        return 0;
    }

    a = atoi(t.a);
    b = atoi(t.b);

    if(strcmp(t.c2,"onto") == 0){
        for(i=0; i<=numeroBlocos; i++){
            p = vlb[i].inicio;

            while(p){///Loop para buscar no vetor a referencia do elemento a ser movido.
                if(p->id == a)
                    aux1 = p;
                else
                    p = p->next;
            }

            while(p){///Loop para buscar no vetor a referencia do elemento para onde será movido.
                if(p->id == b)
                    aux2 = p;
                else
                    p = p->next;
            }
        }

        p = aux1->next;
        while(p){///Removendo todos os nodos acima do nodo para o qual o elemento será movido.
            vlb[p->id].inicio = p;
            p = p->next;
        }

        aux1->next = aux2;

        return 1;
    }
    else{
        if(strcmp(t.c2,"over") == 0){
            for(i=0; i<=numeroBlocos; i++){
                p = vlb[i].inicio;

                while(p){///Loop para buscar no vetor a referencia do elemento a ser movido.
                    if(p->id == a)
                        aux1 = p;
                    else
                        p = p->next;
                }

                while(p){///Loop para buscar no vetor a referencia do elemento para onde será movido.
                    if(p->id == b)
                        aux2 = p;
                    else
                        p = p->next;
                }
            }

            aux1->next = aux2;
            return 1;
        }
    }

    return 0;
}
