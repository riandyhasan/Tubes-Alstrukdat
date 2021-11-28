#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "array.c"
#include "teleporter.c"
#include "mesin_kar.c"
#include "mesin_kata.c"

int main(){
    Map M;
    inisialisasiMap(&(M));
    readMap(&M, "50.txt");
    CmdInspect(M);
    int pos;
    printf("Masukkan posisi player: ");
    scanf("%d", &pos);
    showPlayerPos(M, pos);
}