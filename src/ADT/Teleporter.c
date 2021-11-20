#include "Teleporter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* INI JUGA BELUM KELAR */ 

void MakeEmpty (arrayTele * T) {
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
    T->Neff = 0;
}

int TotalElmt (arrayTele T) {
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
    int t;
    t = T.Neff;
    return t;
}

int MaxElmt (arrayTele T) {
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    return (IdxMax);
}

Teleporter GetElmt (arrayTele T, IdxType i) {
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel T yang ke-i */
    return T.bufferTele[i];
}

void PetakIn (arrayTele * T, ElType X) {
/* Mengirimkan alamat indeks petak yang merupakan teleporter */
    IdxType i;
    T->bufferTele[i].IdxMasuk = X;
}

void PetakOut (arrayTele * T, ElType X) {
/* Mengirimkan alamat indeks petak keluar */
    IdxType i;
    T->bufferTele[i].IdxKeluar = X;
}

void GetTeleporter (PlayerState * PS, arrayTele T, ElType X) { 
/* Mengirimkan alamat indeks petak keluar dari player yang harus menggunakan teleporter */
    IdxType i;
    for (i = IdxMin; i < IdxMax; i++) {
        if (PLAYERPOS(PS) == T.bufferTele[i].IdxMasuk) {
            PLAYERPOS(PS) = T.bufferTele[i].IdxKeluar;
        }
    }
}

void cmdInspect (arrayTele T, PlayerState PS, ElType X) { 
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mengirimkan indeks petak masuk, petak keluar, serta informasi mengenai petak kosong dan petak terlarang */
    int IdxPetak;
    printf("Masukkan Petak: ");
    scanf("%d", &IdxPetak);
}


