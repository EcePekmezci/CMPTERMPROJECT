#include <vector>

class GraveyardSlash : public AttackSkill {
protected:

int dmgMod = 0;
int baseAcc = 85;
int critMod = 6;

public:
GraveyardSlash();
~GraveyardSlash(){};

int getDmgMod(){ return dmgMod; };
int getBaseAcc(){ return baseAcc; };
int getCritMod(){ return critMod; };


void GraveyardSlashAttack(Hero &H, int damage);

};


