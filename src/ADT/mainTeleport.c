#include "Teleporter.h"
#include "Teleporter.c"
#include <stdio.h>
#include <stdlib.h>

/* Coba buat input sesuain file konfigurasi */


int main() {
    int N,addIn,addOut;
    IdxType i;
    arrayTele Tele;
    scanf("%d", &N);
    MakeEmpty(&Tele);
    for (i = 0; i < N; i++) {
        scanf("%d %d", &addIn, &addOut);
        PetakInAndOut(&Tele,addIn,addOut); /* Ini buat nyimpen sebagai IdxMasuk sama IdxKeluar */                                      
    }                                     
    printf("Sudah Kelar\n");
}


