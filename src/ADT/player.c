#include <stdio.h>
#include <stdlib.h>
#include "player.h"

void CreatePlayer(Player *p, int id){
    List skill, buff;
    CreateEmptyList(&skill);
    CreateEmptyList(&buff);
    INFOPLAYER(*p) = id;
    INFOSKILL(*p) = skill;
    INFOBUFF(*p) = buff;
}
