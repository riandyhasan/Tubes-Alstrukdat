// Implementasi dari stack.h.

#include "stack.h"
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack (Stack *S){
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP berNilStackai NilStack */
    Top(*S) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack (Stack S){
/* Mengirim true jika Stack kosong: lihat definisi di atas */
    return (Top(S) == NilStack);
}
boolean IsFullStack (Stack S){
/* Mengirim true jika tabel penampung NilStackai elemen stack penuh */
    return (Top(S) == MaxEl);
}

int NElStack(Stack S){
    int count = 0;
    while(!IsEmptyStack(S)){
        State dummy;
        count++;
        Pop(&S, &dummy);
    }
    return count;
}

void CopyStack(Stack *S1, Stack S2){
    CreateEmptyStack(S1);
    State dummy;
    FIRSTPLAYER(dummy) = Nil;
    while(!IsEmptyStack(S2)){
        Pop(&S2, &dummy);
        Push(S1, dummy);
    }
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infostack X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
    Top(*S)++;
    PushState(&(InfoTop(*S)), X);
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack* S, infostack* X){
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah NilStackai elemen TOP yang lama, TOP berkurang 1 */
    PushState(X, InfoTop(*S));
    Top(*S)--;
}