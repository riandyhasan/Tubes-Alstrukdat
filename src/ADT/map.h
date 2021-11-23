#ifndef map_H
#define map_H


#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "teleporter.h"

// Definisi
// Map berisi mapConfig : konfigurasi peta;
// tele : array of teleporter, dan
// defaultMaxRoll : max roll yang default.

typedef struct MapStruct {
    TabChar mapConfig;
    int defaultMaxRoll;
    arrayTele tele;
} Map;

/* Selektor */
#define MAPC(M) (M).mapConfig
#define MAXROLL(M) (M).defaultMaxRoll
#define TELE(M) (M).tele

void inisialisasiMap(Map *M);
/* Konstruktor dari Map */
/* Alokasi memori sebesar ukuran dari map. */

void readMap(Map *M, char filename[50]);
/* Membaca file konfigurasi map */

boolean isForbidden(Map M, int loc);
/* Mengecek apakah isi map merupakan #, true jika # */


/* COMMAND INSPECT */
void CmdInspect (Map peta);
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mengirimkan indeks petak masuk, petak keluar, serta informasi mengenai petak kosong dan petak terlarang */


#endif