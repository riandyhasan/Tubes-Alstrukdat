#ifndef Teleport_h
#define Teleport_h

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "state.h"

#define IdxMax 100
#define IdxMin 0

/* INI BELUM SELESAI ADT NYA */

typedef int IdxType;
typedef int ElType;

typedef struct {
    int IdxMasuk;
    int IdxKeluar;
} Teleporter;

typedef struct {
    Teleporter bufferTele[IdxMax];
    int Neff;
} arrayTele;


void MakeEmpty (arrayTele * T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

int TotalElmt (arrayTele T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElmt (arrayTele T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */

Teleporter GetElmt (arrayTele T, IdxType i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

void PetakIn (arrayTele * T, ElType X);
/* Mengirimkan alamat indeks petak yang merupakan teleporter */

void PetakOut (arrayTele * T, ElType X);
/* Mengirimkan alamat indeks petak keluar*/

void GetTeleporter (PlayerState * PS, arrayTele T, ElType X);
/* I.S T terdefinisi dan tidak kosong */
/* F.S Teleporter ditemukan dan Mengarahkan player ke petak keluar jika player tidak mempunyai buff imunitas */

void cmdInspect (arrayTele T, PlayerState PS, ElType X);
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mengirimkan indeks petak masuk, petak keluar, serta informasi mengenai petak kosong dan petak terlarang */

#endif /* adtteleport_h */
