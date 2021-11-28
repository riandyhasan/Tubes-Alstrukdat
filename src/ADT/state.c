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

void ResetStatePlayer(State *S){
  addrPlayer loc;
  loc = FIRSTPLAYER(*S);
  while(loc != Nil){
    ResetPlayer(&(loc->pemain));
    PLAYERPOS(loc) = 1;
    loc = NextPlayer(loc);
  }
}

addrPlayer PlayerTurn(Player p, int post){
  /* Mengembalikan sebuah addrPlayer yang menyimpan turn pemain  */
  addrPlayer turn;
  turn = (addrPlayer) malloc (sizeof(PlayerState));
  if (turn != Nil){
        turn-> pemain = p;
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

addrPlayer SalinPlayer(Player p, int pos){
  /* Mengembalikan sebuah addrPlayer yang menyimpan pemain  */
  addrPlayer turn;
  turn = (addrPlayer) malloc (sizeof(PlayerState));
  if (turn != Nil){
        strcpy(NAME(turn-> pemain), NAME(p));
        INFOPLAYER(turn -> pemain) = INFOPLAYER(p);
        SalinSkill(&(turn->pemain), p);
        PLAYERPOS(turn) = pos;
        NextPlayer(turn) = Nil;
   }
  return turn;
}

void PushState(State *S1, State S2){
  addrPlayer P1, P2;
  P2 = FIRSTPLAYER(S2);
  P1 = SalinPlayer((P2 -> pemain), PLAYERPOS(P2));
  FIRSTPLAYER(*S1) = P1;
  P2 = NextPlayer(P2);
  while (P2 != Nil){
    addrPlayer now;
    now = SalinPlayer((P2 -> pemain), PLAYERPOS(P2));
    NextPlayer(P1) = now;
    P2 = NextPlayer(P2);
  }
}


void CreateRound (State *S){
  /* Membuat sebuah State baru */
  FIRSTPLAYER(*S) = Nil;
  NPLAYER(*S) = 0;
}

void AddPlayerToGame(State *newState,int nPlayer){
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */
  NPLAYER(*newState) = nPlayer;
  for(int i = 1; i <= nPlayer; i++){
    Player newPlayer;
    addrPlayer turn;
    char Name[100];
    printf("Masukkan nama player ke-%d: ", i);
    scanf("%s",&Name);
    CreatePlayer(&newPlayer, Name, i);
    turn = PlayerTurn(newPlayer, 1);
    AddTurn(&(*newState), turn);
    printf("Player %s berhasil ditambahkan!\n", Name);
  }
}

void LoadPlayerToGame(State *newState,int nPlayer){
  /* I.S. Sembarang  */
/* F.S. Player ditambahkan ke dalam sebanyak yang diinginkan */
  NPLAYER(*newState) = nPlayer;
  for(int i = 1; i <= nPlayer; i++){
    Player newPlayer;
    addrPlayer turn;
    ADVKATALOAD();
    ADVKATALOAD();
    char copyy[LoadKata.Length];
    for (int i = 0; i <LoadKata.Length; i++){
        copyy[i] = LoadKata.TabKata[i+1];
    }
    CreatePlayer(&newPlayer, copyy, i);
    turn = PlayerTurn(newPlayer, 1);
    AddTurn(&(*newState), turn);
  }
}

addrPlayer SearchPlayer(State S, Player P){
  /* Mencari addrPlayer dari Player */
  addrPlayer loc;
  loc = FIRSTPLAYER(S);
  while (loc != Nil && INFOPLAYER(loc -> pemain) != INFOPLAYER(P)){
    loc = NextPlayer(loc);
  }
  return loc; 
}

Player SearchPlayerByName(State S, char *name){
  addrPlayer loc;
  loc = FIRSTPLAYER(S);
  while (loc != Nil && NAME(loc -> pemain) != name){
    loc = NextPlayer(loc);
  }
  return loc -> pemain;
}

Player SearchPlayerByPlayerNum(State S, int idx){
  addrPlayer loc;
  loc = FIRSTPLAYER(S);
  while (loc != Nil && INFOPLAYER(loc -> pemain) != idx){
    loc = NextPlayer(loc);
  }
  return loc -> pemain;
}

void ChangePlayerPosition(addrPlayer *P, int newPost){
/* I.S. Game sudah dimulai dan player telah memiliki posisi masing-masin  */
/* F.S. Posisi player diubah sesuai dengan roll yang dilakukan */
  if(P != Nil) {
      PLAYERPOS(*P) = newPost;
    }
}

void ShowPlayer(State S){
  addrPlayer loc;
  loc = FIRSTPLAYER(S);
  int i = 1;
  while (loc != Nil) {
    printf("%d. %s\n",INFOPLAYER(loc -> pemain),  NAME(loc -> pemain));
    loc = NextPlayer(loc);
    i++;
  }
}

void ResetAllPlayerBuff(State *S){
  addrPlayer P;
  P = FIRSTPLAYER(*S);
  while(P != Nil){
    resetBuff(&(P -> pemain));
    P = NextPlayer(P);
  }
}

void UseTukarPosisiPlayer (State *S, int Playernum1){
    int playernum2;
    boolean same;
    Player P1, P2;

    P1 = SearchPlayerByPlayerNum(*S, Playernum1);

    ShowPlayer(*S);
    printf("Silahkan masukkan no pemain yang ingin ditukar: ");
    scanf("%d", &playernum2);
    
    P2 = SearchPlayerByPlayerNum(*S, playernum2);
    same = isSamePlayer(P1, P2);
    while(same){
        printf("Tidak dapat menukar dengan diri sendiri!\n");
        printf("Silahkan masukkan no pemain yang ingin ditukar: ");
        scanf("%d", &playernum2);
        P2 = SearchPlayerByPlayerNum(*S, playernum2);
        same = isSamePlayer(P1, P2);
    }
    
    int temp;
    addrPlayer Plyr1, Plyr2;

    Plyr1 = SearchPlayer(*S, P1);
    temp = PLAYERPOS(Plyr1);

    Plyr2 = SearchPlayer(*S, P2);

    ChangePlayerPosition (&Plyr1, PLAYERPOS(Plyr2));
    ChangePlayerPosition (&Plyr2, temp);
}
