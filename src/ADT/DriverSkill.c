#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./adt.h"

int main(){

    Player P1;
    int X;

    CreatePlayer(&P1, "Valorant", 1);

    insPlayerSkill(&P1);

    PrintSkill(P1) ;

    printf("\n");

    CommandSkill(&P1) ;

}