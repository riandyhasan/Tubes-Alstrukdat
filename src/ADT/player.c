#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void CreatePlayer(Player *p, char name[50], int id){
    List skill, buff;
    CreateEmptyList(&skill);
    CreateEmptyList(&buff);
    INFOPLAYER(*p) = id;
    NAME(*p) = name[50];
    INFOSKILL(*p) = skill;
    INFOBUFF(*p) = buff;
}
