#include "Teleporter.h"
#include "Teleporter.c"
#include <stdio.h>
#include <stdlib.h>

/* DRIVER TELEPORTER.C */

int main () {
    int N,i,addIn,addOut,noPetak;
    arrayTele arrTele;
    Teleporter tele;
    MakeEmptyTele(&arrTele);
    scanf("%d", &N);
    printf("Silahkan masukkan Petak masuk dan Petak keluar!\n");
    for (i = 1; i <= N;i++) {
        scanf("%d %d", &addIn, &addOut);
        PetakInAndOut(&tele,addIn,addOut);
        arrTele.bufferTele[i].IdxMasuk = addIn;
        arrTele.bufferTele[i].IdxKeluar = addOut;
        arrTele.Neff++;
    }
    printf("\n");
    printf("Total Elemen dalam Array Teleporter adalah %d\n", TotalElmtTele(arrTele));
    printf("Total maksimal elemen dalam Array Teleporter adalah %d\n", MaxElmtTele(arrTele));
    printf("Indeks pertama dari Array Teleporter adalah %d\n", GetFirstIdxTele(arrTele));
    printf("Indeks terakhir dari Array Teleporter adalah %d \n", GetLastIdxTele(arrTele));
    printf("\n");
    printf("Masukkan Nomor Petak!\n");
    scanf("%d", &noPetak);
    printf("\n");
    if (IsTeleport(arrTele,noPetak)) {
        printf("Petak Keluar dari %d adalah %d \n", noPetak, PetakOut(arrTele,noPetak));
    } else {
        printf("Petak %d tidak memiliki Teleporter dan Petak Keluar\n", noPetak);
    }
    printf("\n");
    PrintTele(arrTele); /* Menampilkan Petak Teleporter dan Petak Keluar Teleporter */
    printf("\n");
    printf("Sudah Selesai yey!\n");
}