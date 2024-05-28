#include <iostream>
#include <stdio.h>
#include <vector>
#include "Unit.h"
#include "Monster.h"
#include "BoneSoldier.h"
#include "Skills.h"
#include "AttackSkill.h"
#include "GraveyardSlash.h"
#include "GraveyardStumble.h"

BoneSoldier::BoneSoldier(int a){
 if (a == 1) { name = "BoneSoldier1"; }
 else { name = "BoneSoldier2"; }
 MaxHP = 10;
 HP=10;
 dodge=10;
 prot=15;
 speed=2;
 accMod=0;
 baseCrit=0;
 minDmg=3;
 maxDmg=8;
 stunResist=25;

 position = a;
}

void Monster::GraveyardSlashAttack(std::vector<Hero>& vec){
if(vec[0].getIsDead() == false || vec[1].getIsDead() == false || vec[2].getIsDead() == false) { // Is there any alive targets to attack?
int targetposition = (rand()%3);  //Graveyard Slash targets 1, 2 or 3
while(vec[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%3; } //change target until finding an alive one

GraveyardSlash monsterGraveSlashes;
if(vec[targetposition].getDeathDoorState() == false){   //we need to check if the hero is in Death's Door situation
hitChance = monsterGraveSlashes.getBaseAcc() + accMod - vec[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + monsterGraveSlashes.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to critic or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt
}
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + monsterGraveSlashes.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec[targetposition].getProt()/100);
}
cout << name << " hits " << vec[targetposition].getName() << " with Graveyard Slash! Damage dealt: " << actualDmg <<" ->\t";
    monsterGraveSlashes.GraveyardSlashAttack(vec[targetposition], actualDmg);

}
else { cout << name << " missed the Graveyard Slash attack.\n"; }
}
else {
    int killingHit = rand()%100;
    if (killingHit > vec[targetposition].getDeathBlowResist()) {vec[targetposition].setIsDead(true); }
}
}
else {cout << name << " missed! No rivals alive to attack with Graveyard Slash! \n";
}};

void Monster::GraveyardStumbleAttack(std::vector<Hero>& vec){
if(vec[0].getIsDead() == false || vec[1].getIsDead() == false ) { // Is there any alive targets to attack?
int targetposition = (rand()%2);  //Grave Stumble targets 1 or 2
while(vec[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%2; } //change target until finding an alive one

GraveyardStumble monsterGraveStumbles;
if(vec[targetposition].getDeathDoorState() == false){   //we need to check if the hero is in Death's Door situation
hitChance = monsterGraveStumbles.getBaseAcc() + accMod - vec[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + monsterGraveStumbles.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt
}
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + monsterGraveStumbles.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec[targetposition].getProt()/100);
}
cout << name << " hits " << vec[targetposition].getName() << " with Grave Stumble! Damage dealt: " << actualDmg << " ->\t";
    monsterGraveStumbles.GraveyardStumbleAttack(vec[targetposition], actualDmg);

}
else { cout << name << " missed the Graveyard Stumble attack.\n"; }
}
else {
    int killingHit = rand()%100;
    if (killingHit > vec[targetposition].getDeathBlowResist()) {vec[targetposition].setIsDead(true); }
}
} else{ cout << name << " missed! No rivals alive to attack with Graveyard Stumble! \n";
}};
