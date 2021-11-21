#include "Teleporter.h"
#include "Skill.h"
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

IdxType GetFirstIdx (arrayTele T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
    return IdxMin;
}

IdxType GetLastIdx (arrayTele T) {
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
    return TotalElmt(T);
}


void PetakInAndOut (arrayTele * T, int X, int Y) {
/* Mengirimkan alamat indeks petak yang merupakan teleporter */
    IdxType i;
    for (i = GetFirstIdx(*T); i < GetLastIdx(*T); i++) {
        T->bufferTele[i].IdxMasuk = X;
        T->bufferTele[i].IdxKeluar = Y;
    }
}

int GetPetakIn (arrayTele T, IdxType i) { 
/* Mengirimkan alamat Petak yang terdapat Teleporter */
    return T.bufferTele[i].IdxMasuk;
    /* Masih error gabisa nge return value yang bener */
}

int GetPetakOut (arrayTele T, IdxType i) { 
/* Mengirimkan alamat Petak Keluar dari Teleporter */
    return T.bufferTele[i].IdxKeluar;
    /* Masih error gabisa nge return value yang bener */
}

void GetTeleporter (PlayerState * PS, arrayTele T, Teleporter X) { 
/* Mengirimkan alamat indeks petak keluar dari player yang harus menggunakan teleporter */
    IdxType i;
    for (i = GetFirstIdx(T); i < GetLastIdx(T); i++) {
        if (PintuGaKemanaMana){
            /*DO NOTHING*/
        }
        else if (PLAYERPOS(PS) == T.bufferTele[i].IdxMasuk) {
            PLAYERPOS(PS) = T.bufferTele[i].IdxKeluar;
        } else if (PLAYERPOS(PS) != T.bufferTele[i].IdxMasuk) {
            /* Nanti di kondisiin kalo misal playerpos nunjuk petak yang kosong (.) doang, keluar pernyataan dia petak kosong */
            /* Kalo ketemu (#) Kondisiinnya dia petak terlarang */
        }
    }
}

void cmdInspect (arrayTele T, PlayerState PS, int X) { 
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mengirimkan indeks petak masuk, petak keluar, serta informasi mengenai petak kosong dan petak terlarang */
    int IdxPetak;
    printf("Masukkan Petak: ");
    scanf("%d", &IdxPetak);
    /* if (GetTeleporter(&PS,T,IdxPetak)) { */

}


