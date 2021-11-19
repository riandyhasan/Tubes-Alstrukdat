/* File : state.c */
// Implementasi dari state.h
#include "../boolean.h"
#include "state.h"
#include <stdlib.h>
#include <stdio.h>



boolean IsEmptyState (State S){
    /* Mengirim true jika state kosong */
    return First(S) == Nil;
}

address PlayerTurn(Player p, int post){
  /* Mengembalikan sebuah address yang menyimpan turn pemain  */
  address turn;
  turn = (address) malloc (sizeof(PlayerState));
  if (turn != Nil){
        PLAYER(turn) = p;
        PLAYERPOS(turn) = post;
        Next(turn) = Nil;
   }
  return turn;
}

void AddTurn (State *S, address turn){
/* I.S. Sembarang, turn sudah dialokasi  */
/* F.S. turn ditambahkan sebagai elemen terakhir yang baru */
    address loc;
    if (turn != Nil){
    if(IsEmptyState(*S)) {
        Next(turn) = First(*S);
        First(*S) = turn;
    }
    else{
        loc = First(*S);
        while (Next(loc) != Nil){
            loc = Next(loc);
        }
        Next(loc) = turn;
        Next(turn) = Nil;
        }
    }
}


void CreateRound (State *S){
  /* Membuat sebuah State baru */
  First(*S) = Nil;
}

void AddPlayerToGame(int nPlayer){
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */
  State newState;
  CreateRound(&newState);
  for(int i = 1; i <= nPlayer; i++){
    Player newPlayer;
    address turn;
    CreatePlayer(&newPlayer, i);
    turn = PlayerTurn(newPlayer, 0);
    AddTurn(&newState, turn);
  }
}

address SearchPlayer(State S, Player P){
  /* Mencari address dari Player */
  address loc;
  loc = First(S);
  while (loc != Nil && INFOPLAYER(PLAYER(loc)) != INFOPLAYER(P)){
    loc = Next(loc);
  }
  return loc; 
}

void ChangePlayerPosition(State *S, Player P, int newPost){
/* I.S. Game sudah dimulai dan player telah memiliki posisi masing-masin  */
/* F.S. Posisi player diubah sesuai dengan roll yang dilakukan */
  address players;
  players = SearchPlayer(*S, P);
  if(!IsEmptyState(*S) && players != Nil) {
      PLAYERPOS(players) = newPost;
    }
}