#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"
#include "buff.h"

/******************************* Buff *******************************/

void printBuff (Buff b) {
/* mengeluarkan list Buff yang dimiliki player */
    for (int i = 0; i < 4; i++) {
        if (BUFF(b)[0]) {
            printf("Anda mendapatkan buff imunitas teleport. Anda tidak akan kemana-mana.");
        }
        else if (BUFF(b)[1]) {
            printf("Anda mendapatkan buff cermin pengganda. Selamat, anda bisa mendapatkan 2 skill baru!");
        }
        else if (BUFF(b)[2]) {
            printf("Anda mendapatkan buff senter pembesar hoki. Selamat, hoki anda jadi besar!");
        }
        else if (BUFF(b)[3]) {
            printf("Anda mendapatkan buff senter pengecil hoki. Anda kurang beruntung, Player.");
        }
    }
}

void resetBuff (Buff b) {
/* me-reset seluruh buff kecuali imunitas teleport setiap ronde
(karena buff hanya berlaku sekali di suatu ronde) */
    for (int i = 0; i < 4; i++) {
        BUFF(b)[i] = false;
    }
}