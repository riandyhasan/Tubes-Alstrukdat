#include "map.h"
#include "array.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#include "../../boolean.h"
#include <string.h>

Map* MAP;

void inisialisasiMap(){
    MAP = (Map*)malloc(sizeof(Map));
}

void alokasiMap(int N){
    MAP -> mapConfig.TI = (char*)malloc(sizeof(char)*N+3);
    MAP -> mapConfig.Neff = N;
    MAP -> teleporters.TI = (int*)malloc(sizeof(int)*N+1);
    MAP -> teleporters.Neff = N;
    int x;
    for(x=0; x<=N; x++){
        MAP -> teleporters.TI[x] = 0;
    }
}

void dealokasiMap(){
    free(MAP);
}

void readMap (const char* fileloc){
    int N; /* Panjang dari map */
    int M; /* Jumlah dari teleporter */ 
    int MaxRoll; /* Jumlah maksimum roll dadu */
    int src, dest; /* Petak masuk dan keluar dari teleporter */
    int i, j; 
    const char* errorloc = "file konfigurasi";

    STARTKATA(fileloc, false);

    N = atoi(CKata.TabKata);
    alokasiMap(N);

    ADVKATA();
    if (CKata.Length != N) {
        logErrorThenExit("Panjang peta harus sesuai dengan input sebelumnya", errorloc);
    }
    
    i = 1;
    // validasi semua isi dari mapconfig kecuali ujung
    while(CKata.TabKata[i] == '.' || CKata.TabKata[i] == '#'){
        if(i == N-2){
            break;
        }
        i++;
    }
    if(i != N-2){
        logErrorThenExit("Petak hanya boleh diisi karakter '.' atau '#'", errorloc);
    }
    strcpy((MAP->mapConfig.TI), "|");
    strcat((MAP->mapConfig.TI), CKata.TabKata);

    // Input MaxRoll
    ADVKATA();
    MaxRoll = atoi(CKata.TabKata);
    MAP->defaultMaxRoll = MaxRoll;

    // Input jumlah teleporter
    ADVKATA();
    M = atoi(CKata.TabKata);

    // Input dan validasi dari teleporters
    for (i = 0 ; i < M ; i ++){
        ADVKATA();
        src = atoi(CKata.TabKata);
        if (i == M - 1){
            MBR = true;
        }
        ADVKATA();
        dest = atoi(CKata.TabKata);
        if (src == dest){
            logErrorThenExit("Petak masuk dan keluar teleporter tidak boleh sama", errorloc);
        }
        if (src < 1 || dest < 1 || src > N || dest > N){
            logErrorThenExit("Teleporter harus berada dalam map", errorloc);
        }
        MAP->teleporters.TI[src] = dest;
    }
};