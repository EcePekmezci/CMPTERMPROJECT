#include <time.h>
#include "Skills.h"
#include "DivineGrace.h"

DivineGrace::DivineGrace(){}
DivineGrace::~DivineGrace(){}

void DivineGrace::DivineGraceBuff(std::vector<Hero>& vec){
srand(time(0));
int healAmount = rand()%2 +4;
int whoToBuff = rand()%4;

while(vec[whoToBuff].getIsDead() == true){ whoToBuff= (whoToBuff+1)%4;}  //if target is dead, try next one

vec[whoToBuff].setHP(vec[whoToBuff].getHP() + healAmount);

if ( vec[whoToBuff].getHP() > vec[whoToBuff].getMaxHP()){

    vec[whoToBuff].setHP(vec[whoToBuff].getMaxHP());
}

if(vec[whoToBuff].getDeathDoorState() == true && vec[whoToBuff].getHP() >0){ vec[whoToBuff].setDeathDoorState(false); } //target is healed enough to leave Deaths Door state.

cout << vec[whoToBuff].getName() << " is healed " << healAmount << " HP. \t\t  ->\t ";
cout << vec[whoToBuff].getName() << " has now " << vec[whoToBuff].getHP() << " HP. \n";
};

void DivineGrace::DivineGraceBuff(Hero usertarget){
srand(time(0));
int healAmount = rand()%2 +4;

usertarget.setHP(usertarget.getHP() + healAmount);

if ( usertarget.getHP() > usertarget.getMaxHP()){

    usertarget.setHP(usertarget.getMaxHP());
}

if(usertarget.getDeathDoorState() == true && usertarget.getHP() >0){ usertarget.setDeathDoorState(false); } //target is healed enough to leave Deaths Door state.

cout << usertarget.getName() << " is healed " << healAmount << " HP. \t\t  ->\t ";
cout << usertarget.getName() << " has now " << usertarget.getHP() << " HP. \n";
};



