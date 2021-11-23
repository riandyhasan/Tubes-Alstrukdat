#include "map.h"
#include "array.c"
#include "mesin_kata.c"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

void inisialisasiMap(Map *M){
    MakeEmptyArr(&MAPC(*M));
    MAXROLL(*M) = 0;
    MakeEmptyTele(&TELE(*M));
}


void readMap(Map *M, char filename[50]){
    int mapLen, nTel, maxRoll, telSucc, telPred;
    STARTKATA(filename);
    mapLen = KataToInt(CKata);
    // panjang map = mapLen
    SetNeff(&MAPC(*M), mapLen);
    ADVKATA();
    // salin map
    for (int i = 1; i <= mapLen; i++){
        char copy;
        strcpy(copy, CKata.TabKata);
        MAPC(*M).TI[i] = copy;
    }
    ADVKATA();
    maxRoll = KataToInt(CKata);
    MAXROLL(*M) = maxRoll;
    ADVKATA();
    nTel = KataToInt(CKata);
    TELE(*M).Neff = nTel;
    for (int i = 1; i <= nTel; i++){
        ADVKATA();
        telSucc = KataToInt(CKata);
        ADVKATA();
        telPred = KataToInt(CKata);
        PetakInAndOut(&TELE(*M).bufferTele[i], telSucc, telPred);
    }
    EndKata = true;
}

boolean isForbidden(Map M, int loc){
    return MAPC(M).TI[loc] == "#";
}

void CmdInspect (Map peta) {
    int teleOut;
    int petak;
    printf("Masukkan Petak: ");
    scanf("%d", &petak);
    teleOut = PetakOut(TELE(peta),petak);
    if (IsTeleport(TELE(peta),petak)) {
        printf("Petak %d memiliki teleporter menuju %d.", petak, teleOut);
    } else {
       if (isForbidden(peta,petak)) {
           printf("Petak %d merupakan petak terlarang.", petak);
       } else {
           printf("Petak %d merupakan petak kosong.", petak);
       }
    }
}