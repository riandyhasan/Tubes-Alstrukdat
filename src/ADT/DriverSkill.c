#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listlinier.h"
#include "player.h"
#include "boolean.h"
#include "state.h"
#include "skill.h"

int main(){

    Player P1;
    int X;

    CreatePlayer(&P1, "Valorant", 1010);

    insPlayerSkill(&P1);

    PrintSkill(P1) ;

    printf("\n");

    CommandSkill(&P1, &PintuGaKemanaMana, &CerminPengganda, &SenterPembesarHoki, &SenterPengecilHoki, &MesinPenukarPosisi) ;

}