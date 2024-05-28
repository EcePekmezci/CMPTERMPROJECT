#include <vector>

class Axeblade: public AttackSkill {
protected:

int dmgMod = 0;
int baseAcc = 72;
int critMod = 6;

public:
Axeblade();
~Axeblade(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };

void AxebladeAttack(Hero &H, int damage);

};


