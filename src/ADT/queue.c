#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q){
/* Mengirim true jika Q kosong: lihat definisi di atas */
    return ((Head(Q) == NilQ) && (Tail(Q) == NilQ));
}

boolean IsFullQ (Queue Q){
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxElQ */
    return !(Head(Q) - (Tail(Q) % MaxElQ(Q) + 1));
}

int NBElmtQ (Queue Q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsEmptyQ(Q)){
        return 0;
    }
    else if (IsFullQ(Q)){
        return MaxElQ(Q);
    }
    else{
        if (Head(Q) > Tail(Q)){
            return (MaxElQ(Q)+((Tail(Q) - Head(Q) + 1)%MaxElQ(Q)));
        }else{
            return (Tail(Q) - Head(Q) + 1);
        }
    }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max){
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxElQ=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */
    (*Q).T = (infoqueue *) malloc ((Max+1) * sizeof(infoqueue));
	MaxElQ(*Q) = Max;
	Head(*Q) = NilQ;
	Tail(*Q) = NilQ;
}

/* *** Destruktor *** */
void DeAlokasiQ(Queue * Q){
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxElQ(Q) diset 0 */
    MaxElQ(*Q) = 0;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void Add (Queue * Q, infoqueue X){
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
    if(IsEmptyQ(*Q)){
        Head(*Q) = 1;
    }
    if (Tail(*Q) == MaxElQ(*Q)){
        Tail(*Q) = 1;
    }
    else{
        Tail(*Q)++;
    }
    InfoTail(*Q) = X;
}

void Del (Queue * Q, infoqueue * X){
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer; 
        Q mungkin kosong */
    *X = InfoHead(*Q);
    if (Head(*Q) == Tail(*Q)){
        Head(*Q) = NilQ;
        Tail(*Q) = NilQ;
    }
    else{
        if (Head(*Q) > MaxElQ(*Q)){
            Head(*Q) = 1;
        }
        else{
            Head(*Q)++;
        }
    }
}