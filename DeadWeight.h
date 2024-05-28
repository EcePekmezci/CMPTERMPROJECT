#include <vector>

class DeadWeight : public AttackSkill {
protected:

int dmgMod = -25;
int baseAcc = 82;
int critMod = 6;
int stunBase = 100;

public:
DeadWeight();
~DeadWeight(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };
int getStunBase(){ return stunBase; };


void DeadWeightAttack(Hero &H, int damage);

};


