#include "map.h"
#include "array.h"
#include "mesin_kata.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct MapStruct {
//     TabChar mapConfig;
//     int defaultMaxRoll;
//     arrayTele tele;
// } Map;
// #define MAPC(M) M.mapConfig;
// #define MAXROLL(M) (M).defaultMaxRoll;
// #define TELE(M) (M).tele;


void inisialisasiMap(Map *M){
    MakeEmptyArr(&MAPC(*M));
    MAXROLL(*M) = 0;
    MakeEmptyTele(&TELE(*M));
}


void readMap(Map *M){
    int mapLen, nTel, maxRoll, telSucc, telPred;
    STARTKATA();
    mapLen = KataToInt(CKata);
    // panjang map = mapLen
    SetNeff(&MAPC(*M), mapLen);
    ADVKATA();
    // salin map
    for (int i = 1; i <= mapLen; i++){
        SetEl(&MAPC(*M),i, CKata.TabKata);
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
        PetakInAndOut(&TELE(*M), telSucc, telPred);
    }
    EndKata = true;
}

boolean isForbidden(Map M, int loc){
    return MAPC(M).TI[loc] == "#";
}