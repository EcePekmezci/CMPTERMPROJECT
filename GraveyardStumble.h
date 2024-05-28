#include <vector>

class GraveyardStumble: public AttackSkill {
protected:

int dmgMod = -50;
int baseAcc = 55;
int critMod = 0;

int Move = 1;

public:
GraveyardStumble();
~GraveyardStumble(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };

void GraveyardStumbleAttack(Hero &H, int damage);

};

