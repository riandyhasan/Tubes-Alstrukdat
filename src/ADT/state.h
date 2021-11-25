/* File : state.h */
#ifndef state_H
#define state_H

#include "../boolean.h"
#include <stdlib.h>

#define Nil NULL

/* Deklarasi type elemen */
typedef struct StateNode *addrPlayer;
typedef struct StateNode {
  Player pemain;
  int position;
  boolean isRoll;
  addrPlayer nextp;   
} PlayerState;

typedef struct {
  addrPlayer FirstP;
  int nPlayer;  
} State;

/* Selektor */
#define PLAYERPOS(ps) (ps)->position
#define ROLLED(ps) (ps)-> isRoll
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

void AddPlayerToGame(State *newState,int nPlayer);
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */

void ChangePlayerPosition(addrPlayer *P, int newPost);
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */

void AddTurn(State *S, addrPlayer turn);
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */

Player SearchPlayerByName(State S, char name[50]);

Player SearchPlayerByPlayerNum(State S, int idx);

void ShowPlayer(State S);

void insPlayerSkill (Player *P);
/* I.S. Skill Player mungkin kosong  */
/* F.S. Skill baru ditambahkan ke dalam list skill player */

void DoubleMirror(Player *P);
/* I.S.  terdapat skill Cermin Pengganda di dalam list skillnya.*/
/* F.S. Skill Cermin Pengganda -> Menghapus dirinya sendiri dan mendapatkan 2 buah skill baru */

#endif
