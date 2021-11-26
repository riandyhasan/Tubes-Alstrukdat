/* File: player.h */
#ifndef _PEMAIN_H
#define _PEMAIN_H
#include "../boolean.h"
#include <stdlib.h>

/* Deklarasi type elemen */
typedef struct {
int playernum;
char name[100];
List skill;
boolean buff[4];
} Player;

/* Selektor */
#define INFOPLAYER(p) (p).playernum
#define INFOSKILL(p) (p).skill
#define NAME(p) (p).name

void CreatePlayer(Player *p, char *name, int id);

boolean isSamePlayer(Player p1, Player p2);


/******************************* BUFF *******************************/

/* LIST BUFF
    1. Imunitas teleport
    2. Cermin pengganda
    3. Senter pembesar hoki
    4. Senter pengecil hoki
*/

void printBuff (Player P);
/* mengeluarkan list Buff yang dimiliki player */

void resetBuff (Player *P);
/* me-reset seluruh buff kecuali imunitas teleport setiap ronde
(karena buff hanya berlaku sekali di suatu ronde) */

/****************** SKILL ******************/

int printRandoms (int lower, int upper, int count);
/* I.S. Batas atas dan batas bawah serta jumlah output yang diinginkan terdefinisi */

int GetSkills ();
/* Mengirimkan hasil skill yang didapat menggunakan randomizer */

/******************************* PROSES SKILL *******************************/

void PrintSkill ();
/* I.S. Sembarang  */
/* F.S. Mengeluarkan list skill yang dimiliki oleh player */

void insPlayerSkill (Player *P);
/* I.S. Skill Player mungkin kosong  */
/* F.S. Skill baru ditambahkan ke dalam list skill player */

void DoubleMirror(Player *P);
/* I.S.  terdapat skill Cermin Pengganda di dalam list skillnya.*/
/* F.S. Skill Cermin Pengganda -> Menghapus dirinya sendiri dan mendapatkan 2 buah skill baru */


// void TukarPosisiPlayer (Player P1, Player P2, State *S);
// /* I.S. Posisi Player berada pada posisi sebenarnya (posisi aslinya) */
// /* F.S. Posisi Player 1 berubah menjadi posisi Player 2 dan begitu sebaliknya */

// void UseTukarPosisiPlayer (State *S, int Playernum1);
// /* I.S. Posisi Player berada pada posisi sebenarnya (posisi aslinya) */
// /* F.S. Posisi Player 1 berubah menjadi posisi Player 2 dan begitu sebaliknya */

#endif