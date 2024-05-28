#include <vector>

class MaceBash : public AttackSkill {
protected:

int dmgMod = 0;
int baseAcc = 85;
int critMod = 0;


public:
MaceBash();
~MaceBash(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };

void MaceBashAttack(Monster &M, int damage);

};


