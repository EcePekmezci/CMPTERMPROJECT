#ifndef HERO_H
#define HERO_H
#include "Unit.h"
class Monster;

class Hero : public Unit {
protected:
 int deathBlowResist;
 bool deathsDoor = false;

public:
 int getDeathBlowResist(){
 return deathBlowResist; }

  void setDeathDoorState(bool deadOrNot){
   deathsDoor = deadOrNot; }

 bool getDeathDoorState(){
    return deathsDoor; }

void SmiteAttack(std::vector<Monster>& vec2);
void StunningBlowAttack(std::vector<Monster>& vec2);
void HolyLanceAttack(std::vector<Monster>& vec2);
void MaceBashAttack(std::vector<Monster>& vec2);
void DazzlingLightAttack(std::vector<Monster>& vec2);
void BulwarkOfFaithBuff();
int BoFCounter;  //counts rounds for Bulwark Of Faith Skill
void DivineGraceBuff(std::vector<Hero>& vec);
void DivineComfortBuff(std::vector<Hero>& vec);

int resetBoFBuff() { return prot =-20; }

void SmiteAttack(Monster& usertarget);
void StunningBlowAttack(Monster& usertarget);
void HolyLanceAttack(Monster& usertarget);
void MaceBashAttack(Monster& usertarget);
void DazzlingLightAttack(Monster& usertarget);
void DivineGraceBuff(Hero& usertarget);

void moveHero(std::vector<Hero>& vec,int currentpos, int changetopos);
};


#endif // HERO_H
