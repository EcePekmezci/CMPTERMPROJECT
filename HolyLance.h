#include <vector>

class HolyLance : public AttackSkill {
protected:

int dmgMod = 0;
int baseAcc = 85;
int critMod = 6.5;
int Move = 1;

public:
HolyLance();
~HolyLance(){}

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };

void HolyLanceAttack(Monster &M, int damage);

};

