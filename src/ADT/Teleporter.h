#ifndef Teleport_h
#define Teleport_h

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"

#define IdxMax 500
#define IdxMin 1

typedef int IdxType;

typedef struct {
    int IdxMasuk; /* Petak Masuk yang terdapat Teleporter */
    int IdxKeluar; /* Petak Keluar dari Teleporter */
} Teleporter;

typedef struct {
    Teleporter bufferTele[IdxMax]; /* Menyimpan Teleporter */
    int Neff; /* Jumlah Teleporter dalam array */
} arrayTele;


void MakeEmptyTele (arrayTele * T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax */

int TotalElmtTele (arrayTele T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */

int MaxElmtTele (arrayTele T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */

IdxType GetFirstIdxTele (arrayTele T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IdxType GetLastIdxTele (arrayTele T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */

/* Konstruktor Teleporter */
void PetakInAndOut (Teleporter * T, int X, int Y);
/* I.S T terdefinisi
   F.S Membuat sebuah teleporter terdefinisi terdiri dari Petak Masuk dan Petak Keluar  */

boolean IsTeleport(arrayTele aT, int nomorPetak);
/* Mengecek apakah sebuah petak merupakan sebuah teleporter */
/* Mengirimkan nilai true jika petak tersebut merupakan teleporter */

int PetakOut (arrayTele aT, int nomorPetak);
/* Mendapatkan petak keluar dari sebuah kumpulan tele pada petak masuk tertentu */

void PrintTele (arrayTele T);
/* I.S T terdefinisi dan tidak kosong */
/* F.S Mengirimkan indeks petak masuk dan petak keluar */

#endif /* Teleporter_h */
