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

IdxType GetFirstIdx (arrayTele T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdx (arrayTele T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */

void PetakInAndOut (arrayTele * T, int X, int Y);
/* I.S T Kosong */
/* F.S T berisi alamat indeks petak yang merupakan teleporter dan petak keluar dari teleporter */

int GetPetakIn (arrayTele T, IdxType i);
/* Mengirimkan alamat Petak yang terdapat Teleporter */

int GetPetakOut (arrayTele T, IdxType i);
/* Mengirimkan alamat Petak Keluar dari Teleporter */

void GetTeleporter (PlayerState * PS, arrayTele T, Teleporter X);
/* I.S T terdefinisi dan tidak kosong */
/* F.S Teleporter ditemukan dan Mengarahkan player ke petak keluar jika player tidak mempunyai buff imunitas */

void cmdInspect (arrayTele T, PlayerState PS, int X);
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mengirimkan indeks petak masuk, petak keluar, serta informasi mengenai petak kosong dan petak terlarang */

#endif /* adtteleport_h */
