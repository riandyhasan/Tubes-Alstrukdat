#ifndef skill_H
#define skill_H

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"

/****************** PROSES GET SKILL MELALUI RANDOMIZER ******************/

int printRandoms (int lower, int upper, int count);
/* I.S. Batas atas dan batas bawah serta jumlah output yang diinginkan terdefinisi */

int GetSkills ();
/* Mengirimkan hasil skill yang didapat menggunakan randomizer */

void insPlayerSkill (Player *P);
/* I.S. Skill Player mungkin kosong  */
/* F.S. Skill baru ditambahkan ke dalam list skill player */

/******************************* PROSES SKILL *******************************/

void PrintSkill ();
/* I.S. Sembarang  */
/* F.S. Mengeluarkan list skill yang dimiliki oleh player */


void CommandSkill (State *S, int id);
/* I.S. Sembarang  */
/* F.S. mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */


void TukarPosisiPlayer (Player P1, Player P2, State *S);
/* I.S. Posisi Player berada pada posisi sebenarnya (posisi aslinya) */
/* F.S. Posisi Player 1 berubah menjadi posisi Player 2 dan begitu sebaliknya */

void UseTukarPosisiPlayer (State *S, int Playernum1);
/* I.S. Posisi Player berada pada posisi sebenarnya (posisi aslinya) */
/* F.S. Posisi Player 1 berubah menjadi posisi Player 2 dan begitu sebaliknya */

void DoubleMirror(Player *P);
/* I.S.  terdapat skill Cermin Pengganda di dalam list skillnya.*/
/* F.S. Skill Cermin Pengganda -> Menghapus dirinya sendiri dan mendapatkan 2 buah skill baru */

#endif