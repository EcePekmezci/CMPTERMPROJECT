#include <vector>

class DazzlingLight : public AttackSkill {
protected:

int dmgMod = -75;
int baseAcc = 90;
int critMod = 5;
int stunBase = 100;

public:
DazzlingLight();
~DazzlingLight(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };
int getStunBase(){ return stunBase; };
void DazzlingLightAttack(Monster &M, int damage);

};

