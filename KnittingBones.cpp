#include <time.h>
#include "Skills.h"
#include "KnittingBones.h"

KnittingBones::KnittingBones(){}
KnittingBones::~KnittingBones(){}

void KnittingBones::KnittingBonesBuff(std::vector<Monster> vec2){
srand(time(0));
int healAmount = rand()%2 +2;
int whoToBuff = rand()%4;

while(vec2[whoToBuff].getIsDead() == true){ whoToBuff= (whoToBuff+1)%4;}  //if target is dead, try next one

vec2[whoToBuff].setHP(vec2[whoToBuff].getHP() + healAmount);

if ( vec2[whoToBuff].getHP() > vec2[whoToBuff].getMaxHP()){

    vec2[whoToBuff].setHP(vec2[whoToBuff].getMaxHP());
}
cout << vec2[whoToBuff].getName() << " is healed " << healAmount << " HP. ->  \t ";
cout << vec2[whoToBuff].getName() << " has now " << vec2[whoToBuff].getHP() << " HP. \n";
};




