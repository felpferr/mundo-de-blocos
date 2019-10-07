#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

#include "extras.h"

typedef struct{
    char *c1,*c2,*a,*b;
}tokens;

void removeBarraN(char*);
void limpaTela();
int inicio();
int getToken(char *, tokens);

#endif // EXTRAS_H_INCLUDED
