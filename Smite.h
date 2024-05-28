#include <vector>

class Smite : public AttackSkill {
protected:

int dmgMod = 0;
int baseAcc = 85;
int critMod = 0;


public:
Smite();
~Smite(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };

void SmiteAttack(Monster &M , int damage);

};

