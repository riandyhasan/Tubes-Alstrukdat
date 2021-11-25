#include "teleporter.h"
#include <stdio.h>
#include <stdlib.h>



void MakeEmptyTele (arrayTele * T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax */
    int i;
    for (i = IdxMin; i <= IdxMax; i++) {
        (*T).bufferTele[i].IdxMasuk = -1;
        (*T).bufferTele[i].IdxKeluar = -1;
    }
    (*T).Neff = 0;
}

int TotalElmtTele (arrayTele T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
   return T.Neff;
}

int MaxElmtTele (arrayTele T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return IdxMax;
}

IdxType GetFirstIdxTele (arrayTele T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return IdxMin;
}

IdxType GetLastIdxTele (arrayTele T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
    return T.Neff;
}


void PetakInAndOut (Teleporter * T, int X, int Y) {
/* I.S T terdefinisi
   F.S Membuat sebuah teleporter terdefinisi terdiri dari Petak Masuk dan Petak Keluar  */
    (*T).IdxMasuk = X;
    (*T).IdxKeluar = Y;
}

boolean IsTeleport (arrayTele aT, int nomorPetak){
/* Mengecek apakah sebuah petak merupakan sebuah teleport */
    return aT.bufferTele[nomorPetak].IdxMasuk > -1 && aT.bufferTele[nomorPetak].IdxKeluar > -1;
}

int PetakOut (arrayTele aT, int nomorPetak){
/* Mendapatkan petak keluar dari sebuah kumpulan tele pada petak masuk tertentu */
    return aT.bufferTele[nomorPetak].IdxKeluar;
}

void PrintTele (arrayTele T) { 
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mencetak indeks petak masuk, petak keluar */
    for (int i = 1; i <= T.Neff ;i++) {
        printf("%d Masuk: %d, Keluar: %d\n",i, T.bufferTele[i].IdxMasuk, T.bufferTele[i].IdxKeluar);
    }
}


