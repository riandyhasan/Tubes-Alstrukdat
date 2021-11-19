/* File : state.h */
#ifndef state_H
#define state_H

#include "../boolean.h"
#include "player.h"
#include <stdlib.h>

#define Nil NULL

/* Deklarasi type elemen */
typedef struct StateNode *address;
typedef struct StateNode {
  Player pemain;
  int position;
  address next;   
} PlayerState;
typedef struct {
  address First;  
} State;

/* Selektor */
#define PLAYERPOS(ps) (ps)->position
#define PLAYER(ps) (ps)->pemain
#define Next(ps) (ps)->next
#define FIRST(s) (s)->First



void CreateRound (State *S);
/* Membuat sebuah State baru */

boolean IsEmptyState(State S);
/* Mengirim true jika state kosong */

address SearchPlayer(State S, Player P);
/* Mencari address dari Player */

address PlayerTurn(Player p, int post);
/* Mengembalikan sebuah address yang menyimpan turn pemain  */

void AddPlayerToGame(int nPlayer);
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */

void ChangePlayerPosition(State *S, Player P, int newPost);
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */

void AddTurn(State *S, address turn);
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */



#endif
