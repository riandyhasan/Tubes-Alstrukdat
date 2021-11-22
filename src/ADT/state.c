/* File : state.c */
// Implementasi dari state.h
#include "../boolean.h"
#include "state.h"
#include <stdlib.h>
#include <stdio.h>



boolean IsEmptyState (State S){
    /* Mengirim true jika state kosong */
    return FIRSTPLAYER(S) == Nil;
}

addrPlayer PlayerTurn(Player p, int post){
  /* Mengembalikan sebuah addrPlayer yang menyimpan turn pemain  */
  addrPlayer turn;
  turn = (addrPlayer) malloc (sizeof(PlayerState));
  if (turn != Nil){
        PLAYER(turn) = p;
        PLAYERPOS(turn) = post;
        NextPlayer(turn) = Nil;
   }
  return turn;
}

void AddTurn (State *S, addrPlayer turn){
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */
    addrPlayer loc;
    if (turn != Nil){
    if(IsEmptyState(*S)) {
        NextPlayer(turn) = FIRSTPLAYER(*S);
        FIRSTPLAYER(*S) = turn;
    }
    else{
        loc = FIRSTPLAYER(*S);
        while (NextPlayer(loc) != Nil){
            loc = NextPlayer(loc);
        }
        NextPlayer(loc) = turn;
        NextPlayer(turn) = Nil;
        }
    }
}


void CreateRound (State *S){
  /* Membuat sebuah State baru */
  FIRSTPLAYER(*S) = Nil;
}

void AddPlayerToGame(int nPlayer){
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */
  State newState;
  CreateRound(&newState);
  for(int i = 1; i <= nPlayer; i++){
    Player newPlayer;
    addrPlayer turn;
    char Name;
    printf("Masukkan nama player ke-%d: ", i);
    scanf("%s",&Name);
    CreatePlayer(&newPlayer, i, Name);
    turn = PlayerTurn(newPlayer, 1);
    AddTurn(&newState, turn);
  }
}

addrPlayer SearchPlayer(State S, Player P){
  /* Mencari addrPlayer dari Player */
  addrPlayer loc;
  loc = FIRSTPLAYER(S);
  while (loc != Nil && INFOPLAYER(PLAYER(loc)) != INFOPLAYER(P)){
    loc = NextPlayer(loc);
  }
  return loc; 
}

void ChangePlayerPosition(State *S, Player P, int newPost){
/* I.S. Game sudah dimulai dan player telah memiliki posisi masing-masin  */
/* F.S. Posisi player diubah sesuai dengan roll yang dilakukan */
  addrPlayer players;
  players = SearchPlayer(*S, P);
  if(!IsEmptyState(*S) && players != Nil) {
      PLAYERPOS(players) = newPost;
    }
}