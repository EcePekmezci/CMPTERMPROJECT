#include <iostream>
#include <stdio.h>
#include <vector>
#include "Monster.h"
#include "BoneDefender.h"
#include "Skills.h"
#include "AttackSkill.h"
#include "Axeblade.h"
#include "DeadWeight.h"
#include "KnittingBones.h"

BoneDefender::BoneDefender(int a){
 if (a == 2) {name = "BoneDefender1"; }
 else {name = "BoneDefender2";}
 MaxHP = 22;
 HP=22;
 dodge=8;
 prot=45;
 speed=1;
 accMod=0;
 baseCrit=0;
 minDmg=2;
 maxDmg=4;
 stunResist=45;

 position = a;

}

void Monster::AxebladeAttack(std::vector<Hero>& vec){
if(vec[0].getIsDead() == false || vec[1].getIsDead() == false) { // Is there any alive targets to attack?
int targetposition = (rand()%2);  //Axeblade targets 1 or 2
while(vec[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%2; } //change target until finding an alive one

Axeblade monsterAxeblades;  //Ready to attack!
if(vec[targetposition].getDeathDoorState() == false){   //we need to check if the hero is in Death's Door situation
hitChance = monsterAxeblades.getBaseAcc() + accMod - vec[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + monsterAxeblades.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt
}
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + monsterAxeblades.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec[targetposition].getProt()/100);
}
cout << name << " hits " << vec[targetposition].getName() << " with Axeblade! Damage dealt: " << actualDmg << "\t->\t";
    monsterAxeblades.AxebladeAttack(vec[targetposition], actualDmg);

}
else { cout << name << " missed the Axeblade attack.\n"; }
}
else {
    int killingHit = rand()%100;
    if (killingHit > vec[targetposition].getDeathBlowResist()) {vec[targetposition].setIsDead(true); }
}
}
else {cout << name << " missed! No alive rivals to attack with Axeblade! \n"; }
};

void Monster::DeadWeightAttack(std::vector<Hero>& vec){
 if(vec[0].getIsDead() == false || vec[1].getIsDead() == false) { // Is there any alive targets to attack?
int targetposition = (rand()%2);  //Dead Weight targets 1 or 2
while(vec[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%2; } //change target until finding an alive one

DeadWeight monsterDeadWeightes;
if(vec[targetposition].getDeathDoorState() == false){   //we need to check if the hero is in Death's Door situation
hitChance = monsterDeadWeightes.getBaseAcc() + accMod - vec[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss


if ( doesHit <= hitChance ){
critChance = baseCrit + monsterDeadWeightes.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)
stunChance = monsterDeadWeightes.getStunBase() - vec[targetposition].getStunResist();

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;
stunChance =+ 20; } //Critic damage is dealt
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + monsterDeadWeightes.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec[targetposition].getProt()/100);
}

cout << name << " hits " << vec[targetposition].getName() << " with Dead Weight! Damage dealt: " << actualDmg << " ->\t";
monsterDeadWeightes.DeadWeightAttack(vec[targetposition], actualDmg);

if(vec[targetposition].getIsDead() == false){
doesStun = (rand()%100);  //Game generates a random number to Stun or not
if (doesStun <= stunChance) {
    vec[targetposition].setIsStunned(true);
    cout << vec[targetposition].getName() << " is stunned for 1 Round! \n" ;
}
}
}
else { cout << name << " missed the Dead Weight attack. \n" ; }
}
else {
    int killingHit = rand()%100;
    if (killingHit > vec[targetposition].getDeathBlowResist()) {vec[targetposition].setIsDead(true); }
}
}
else {cout << name << " missed! No alive rivals to attack with Dead Weight! \n";}
};


void Monster::KnittingBonesBuff(std::vector<Monster> vec2){
KnittingBones BoneDefenderBuffsKB;
cout << name << " buffs Knitting Bones. " ;
BoneDefenderBuffsKB.KnittingBonesBuff(vec2);
}


