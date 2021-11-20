/* File: prioqueuelist.h */
#ifndef _PEMAIN_H
#define _PEMAIN_H
#include "../boolean.h"
#include "listlinier.h"
#include <stdlib.h>

/* Deklarasi type elemen */
typedef struct {
int playernum;
List skill;
List buff;
} Player;

/* Selektor */
#define INFOPLAYER(p) (p).playernum
#define INFOSKILL(p) (p).skill
#define INFOBUFF(p) (p).buff

void CreatePlayer(Player *p, int id);

#endif