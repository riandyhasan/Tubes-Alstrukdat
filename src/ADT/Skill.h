#ifndef skill_H
#define skill_H

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"

/****************** PROSES GET SKILL MELALUI RANDOMIZER ******************/

void printRandoms (int lower, int upper, int count);
/* I.S. Batas atas dan batas bawah serta jumlah output yang diinginkan terdefinisi */


int DrivePrintRandoms (int lower, int upper, int count);
/* Mengirimkan hasil angka yang telah dirandom */


int GetSkills ();
/* Mengirimkan hasil skill yang didapat menggunakan randomizer */

void insPlayerSkill (Player P);

/******************************* PROSES SKILL *******************************/

void PrintSkill ();
/* mengeluarkan list skill yang dimiliki player */


int CommandSkill (Player P);
/* mengeluarkan command untuk meminta masukkan skill yang ingin dipakai */


void useSkill ();
/* menggunakan skill yang dimiliki oleh player */

boolean PintuGaKemanaMana;
/* Mengirimkan true apabila skill digunakan */

boolean CerminPengganda;
/* Mengirimkan true apabila skill digunakan */

boolean SenterPembesarHoki;
/* Mengirimkan true apabila skill digunakan */

boolean SenterPengecilHoki;
/* Mengirimkan true apabila skill digunakan */

boolean MesinPenukarPosisi;
/* Mengirimkan true apabila skill digunakan */

#endif