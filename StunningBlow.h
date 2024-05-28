#include <vector>

class StunningBlow : public AttackSkill {
protected:

int dmgMod = -50;
int baseAcc = 90;
int critMod = 0;
int stunBase = 100;

public:
StunningBlow();
~StunningBlow(){}

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };
int getStunBase(){ return stunBase; };

void StunningBlowAttack(Monster &M , int damage);

};
