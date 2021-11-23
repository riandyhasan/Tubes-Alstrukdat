#include "teleporter.h"
#include "map.c"
#include "skill.c"
#include "state.c"
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
    int i = 1;
    while ((nomorPetak != aT.bufferTele[i].IdxMasuk) && (i < aT.Neff-1)) {
        i++;
    }
    return aT.bufferTele[i].IdxMasuk == nomorPetak;
}

int PetakOut (arrayTele aT, int nomorPetak){
/* Mendapatkan petak keluar dari sebuah kumpulan tele pada petak masuk tertentu */
    int i = 1;
    int Out;
    while (aT.bufferTele[i].IdxMasuk != nomorPetak) {
        i++;
    }
    if (aT.bufferTele[i].IdxMasuk != nomorPetak){
        return Out = -1; /* Mengirimkan -1 jika petak tersebut tidak memiliki petak keluar */
    } else {
        return Out = aT.bufferTele[i].IdxKeluar; /* Mengirimkan IdxKeluar ketika petak masuk memiliki petak keluar */
    }
    return Out;
}

void MovePemain (PlayerState * PS, arrayTele T) { 
/* Teleporter ditemukan dan Mengarahkan player ke petak keluar jika player tidak mempunyai buff imunitas */
    int i;
    if (PintuGaKemanaMana) {
        /* DO NOTHING */
    } else if (IsTeleport(T,PLAYERPOS(PS)) && (!PintuGaKemanaMana)) {
        PLAYERPOS(PS) = PetakOut(T,PLAYERPOS(PS));
    }
}

void PrintTele (arrayTele T) { 
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mencetak indeks petak masuk, petak keluar */
    int i = 1;
    for (i = 0; i <= T.Neff ;i++) {
        printf("%d Masuk: %d, Keluar: %d\n",i+1, T.bufferTele[i].IdxMasuk, T.bufferTele[i].IdxKeluar);
    }
}


