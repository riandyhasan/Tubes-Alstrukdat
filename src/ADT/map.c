#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void inisialisasiMap(Map *M){
    MakeEmptyArr(&(*M).mapConfig);
    MAXROLL(*M) = 0;
    MakeEmptyTele(&(*M).tele);
}


void readMap(Map *M, char *filename){
    int mapLen, nTel, maxRoll, telSucc, telPred;
    STARTKATA(filename);
    mapLen = KataToInt(CKata);
    // panjang map = mapLen
    SetNeff(&(*M).mapConfig, mapLen);
    ADVKATA();
    // salin map
    for (int i = 1; i <= mapLen; i++){
        (*M).mapConfig.TI[i] = CKata.TabKata[i];
    }
    ADVKATA();
    maxRoll = KataToInt(CKata);
    MAXROLL(*M) = maxRoll;
    ADVKATA();
    nTel = KataToInt(CKata);
    (*M).tele.Neff = nTel;
    for (int i = 1; i <= nTel; i++){
        ADVKATA();
        telSucc = KataToInt(CKata);
        ADVKATA();
        telPred = KataToInt(CKata);
        PetakInAndOut(&(*M).tele.bufferTele[i], telSucc, telPred);
    }
}

boolean isForbidden(Map M, int loc){
    return M.mapConfig.TI[loc] == '#';
}

void showPlayerPos(Map M, int loc){
    for(int i=1; i <= M.mapConfig.Neff; i++){
        if (i == loc) printf("*");
        else{
            printf("%c", M.mapConfig.TI[i]);
        }
    }
    printf(" %d", loc);
    printf("\n");
}

void CmdInspect (Map peta) {
    int teleOut;
    int petak;
    printf("Masukkan Petak: ");
    scanf("%d", &petak);
    teleOut = PetakOut(peta.tele,petak);
    if (IsTeleport(peta.tele,petak)) {
        printf("Petak %d memiliki teleporter menuju %d.", petak, teleOut);
    } else {
       if (isForbidden(peta,petak)) {
           printf("Petak %d merupakan petak terlarang.", petak);
       } else {
           printf("Petak %d merupakan petak kosong.", petak);
       }
    }
}