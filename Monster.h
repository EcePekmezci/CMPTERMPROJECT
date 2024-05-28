#ifndef MONSTER_H
#define MONSTER_H
#include "Unit.h"

class Hero;

class Monster : public Unit {
public:

void GraveyardSlashAttack(std::vector<Hero>& vec);
void GraveyardStumbleAttack(std::vector<Hero>& vec);
void AxebladeAttack(std::vector<Hero>& vec);
void DeadWeightAttack(std::vector<Hero>& vec);
void KnittingBonesBuff(std::vector<Monster> vec2);

void moveMonster(std::vector<Monster>& vec2,int currentpos, int changetopos);
};


#endif // MONSTER_H
