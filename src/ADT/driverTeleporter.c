#include "Teleporter.h"
#include "Teleporter.c"
#include "Skill.h"
#include "Skill.c"
#include "state.h"
#include "state.c"
#include <stdio.h>
#include <stdlib.h>

int main () {
    int N,i,addIn,addOut,noPetak;
    arrayTele arrTele;
    PlayerState ps;
    Teleporter tele;

    MakeEmpty(&arrTele);

    PetakInAndOut(&tele,addIn,addOut);

    TotalElmt(arrTele);

    MaxElmt(arrTele);

    GetFirstIdx(arrTele);

    GetLastIdx(arrTele);

    IsTeleport(arrTele,noPetak);

    PetakOut(arrTele,noPetak);

    MovePemain(&ps,arrTele);

    PrintTele(arrTele);

    printf("\n");

    CmdInspect(arrTele);

    printf("\n");

    printf("Sudah Selesai\n");
}