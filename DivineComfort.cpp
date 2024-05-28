#include <time.h>
#include "Skills.h"
#include "DivineComfort.h"

DivineComfort::DivineComfort(){}
DivineComfort::~DivineComfort(){}

void DivineComfort::DivineComfortBuff(std::vector<Hero>& vec){
int healAmount = rand()%3 +1;
int i;
for(i=0; i < 4 ; i++){
if(vec[i].getIsDead()==false){
vec[i].setHP( vec[i].getHP() + healAmount);

if ( vec[i].getHP() > vec[i].getMaxHP()){

    vec[i].setHP(vec[i].getMaxHP());
}
}
if(vec[i].getDeathDoorState() == true && vec[i].getHP() > 0){ vec[i].setDeathDoorState(false); } //target is healed enough to leave Deaths Door state.
}
cout  << "All alive allies are healed " << healAmount << " HP. \n";
};





