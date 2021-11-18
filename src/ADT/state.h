/* File : state.h */
#ifndef state_H
#define state_H

#include "../boolean.h"
#include "player.h"

#define Nil 0
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef int infotype;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
  Player pemain; /* tabel penyimpan elemen */
  int position;  /* alamat TOP: elemen puncak */
} State;
/* Definisi akses dengan Selektor : Set dan Get */

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */


#endif
