#ifndef EXTRAS_H_INCLUDED
#define EXTRAS_H_INCLUDED

#include "extras.h"

typedef struct{
    char c1[5],c2[5],a[5],b[5];
}tokens;

void removeBarraN(char*);
void limpaTela();
int inicio();
int getToken(char *, tokens *);

#endif // EXTRAS_H_INCLUDED
