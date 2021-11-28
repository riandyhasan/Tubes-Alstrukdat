#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "../adt.h"

int main(){

    Player P1,P2;
    int X;

    CreatePlayer(&P1, "Valorant", 1);

    insPlayerSkill(&P1);

    PrintSkill(P1) ;

    printf("\n");

    CreatePlayer(&P2, "Dota", 2);

    if (!isSamePlayer(P1, P2)) printf("Gak sama mas\n");

    resetBuff(&P2);
    resetBuff (&P2);
    printBuff(P2);
    return 0;
}