#ifndef skill_H
#define skill_H

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
#include "player.h"

/****************** PROSES GET SKILL ******************/

void printRandoms (int lower, int upper, int count);
/* I.S. Batas atas dan batas bawah serta jumlah output yang diinginkan terdefinisi */


int DrivePrintRandoms (int lower, int upper, int count);
/* Mengirimkan hasil angka yang telah dirandom */


int GetSkills ();
/* Mengirimkan hasil skill yang didapat menggunakan randomizer */


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