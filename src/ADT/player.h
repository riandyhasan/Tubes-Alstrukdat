/* File: prioqueuelist.h */
#ifndef _PEMAIN_H
#define _PEMAIN_H
#include "../boolean.h"
#include "listlinier.h"
#include <stdlib.h>

/* Deklarasi type elemen */
typedef struct {
int playernum;
char name;
List skill;
List buff;
} Player;

/* Selektor */
#define INFOPLAYER(p) (p).playernum
#define INFOSKILL(p) (p).skill
#define INFOBUFF(p) (p).buff
#define NAME(p) (p).name

void CreatePlayer(Player *p, char name[50], int id);

#endif