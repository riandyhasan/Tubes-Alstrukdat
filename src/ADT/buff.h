#ifndef buff_H
#define buff_H

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"
#include "../boolean.h"

typedef struct {
boolean isActive[4];
} Buff;

/* LIST BUFF
    1. Imunitas teleport
    2. Cermin pengganda
    3. Senter pembesar hoki
    4. Senter pengecil hoki
*/

/* Selektor */
#define BUFF(B) (B).isActive

/******************************* Buff *******************************/

void printBuff ();
/* mengeluarkan list Buff yang dimiliki player */

void resetBuff (Buff *b);
/* me-reset seluruh buff kecuali imunitas teleport setiap ronde
(karena buff hanya berlaku sekali di suatu ronde) */

#endif