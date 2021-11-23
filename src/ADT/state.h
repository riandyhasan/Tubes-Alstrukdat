/* File : state.h */
#ifndef state_H
#define state_H

#include "../boolean.h"
#include "player.h"
#include <stdlib.h>

#define Nil NULL

/* Deklarasi type elemen */
typedef struct StateNode *addrPlayer;
typedef struct StateNode {
  Player pemain;
  int position;
  addrPlayer nextp;   
} PlayerState;
typedef struct {
  addrPlayer FirstP;
  int nPlayer;  
} State;

/* Selektor */
#define PLAYERPOS(ps) (ps)->position
#define PLAYER(ps) (ps)->pemain
#define NextPlayer(ps) (ps)->nextp
#define FIRSTPLAYER(s) (s).FirstP
#define NPLAYER(s) (s).nPlayer

void CreateRound (State *S);
/* Membuat sebuah State baru */

boolean IsEmptyState(State S);
/* Mengirim true jika state kosong */

addrPlayer SearchPlayer(State S, Player P);
/* Mencari addrPlayer dari Player */

addrPlayer PlayerTurn(Player p, int post);
/* Mengembalikan sebuah addrPlayer yang menyimpan turn pemain  */

void AddPlayerToGame(int nPlayer);
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */

void ChangePlayerPosition(State *S, Player P, int newPost);
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */

void AddTurn(State *S, addrPlayer turn);
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */



#endif
