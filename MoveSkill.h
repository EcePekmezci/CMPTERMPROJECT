#ifndef MOVE_H
#define MOVE_H
#include "Skills.h"
#include "Hero.h"
#include "Monster.h"

class Move : public Skills {
    public:

void moveHero(std::vector<Hero>& vec,int currentpos, int changetopos);
void moveMonster(std::vector<Monster>& vec2,int currentpos, int changetopos);
};
#endif // MOVE_H
