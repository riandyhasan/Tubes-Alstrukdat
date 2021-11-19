/* File : Skill.h */
/* ADT List untuk Skill dalam implementasi game mobitangga */

#ifndef listSkill_H
#define listSkill_H

#include "boolean.h"

#define Nil NULL

/* Definisi Type Data */
typedef int infoSkill;

typedef struct lListSkill *idx;
typedef struct lListSkill {
	infoSkill idSkill;
	idx next;
	idx prev;
	int neff;
} Skill;

typedef struct { 
	idx First;
	idx Last;
} ListSkill;

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define infoSkill(P) (P)->idSkill
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define neff(P) (P)->neff

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (ListSkill L);
/* Mengirim true jika list kosong */


/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (ListSkill *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */


/****************** Manajemen Memori ******************/
idx Alokasi (infoSkill X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */


void Dealokasi (idx *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */


/****************** PRIMITIF BERDASARKAN ALAMAT ******************/

/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (ListSkill *L, infoSkill X);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */


void InsertLast (ListSkill *L, infoSkill X);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */


/*** PENGHAPUSAN SEBUAH ELEMEN ***/

void DelAt (ListSkill *L, infoSkill X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */


/****************** PROSES GET SKILL ******************/

void printRandoms (int lower, int upper, int count);


int DrivePrintRandoms (int lower, int upper, int count);


int GetSkills ();


/****************** PROSES SEMUA ELEMEN ******************/

int NbElmt (ListSkill L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */


/******************************* SKILL *******************************/

void PrintSkill ();
/* mengeluarkan list skill yang dimiliki player */


void CommandSkill ();
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */


void useSkill ();
/* menggunakan skill yang dimiliki oleh player */

void SenterPembesarHoki ();

void SenterPengecilHoki ();

void MesinPenukarPosisi ();

void TeknologiGagal ();

#endif