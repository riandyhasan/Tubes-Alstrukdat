#ifndef Map_h
#define Map_h

#include "array.h"

// Definisi
// Map berisi mapConfig : konfigurasi peta;
// teleporters : array of teleporter, dan
// defaultMaxRoll : max roll yang default.
// 
typedef struct MapStruct {
    TabChar mapConfig;
    TabInt teleporters;
    int defaultMaxRoll;
} Map;

extern Map* MAP;

void inisialisasiMap();
/* Konstruktor dari Map */
/* Alokasi memori sebesar ukuran dari map. */

void alokasiMap(int N);
/* Inisialisasi Map */

void dealokasiMap();
/* Destruktor dari Map */
/* Melakukan dealokasi map yang sudah dialokasi sebelumnya */

void readMap (const char* fileloc);
/* Membaca file konfigurasi map */

#endif