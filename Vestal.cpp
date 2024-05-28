#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include "Unit.h"
#include "Hero.h"
#include "Vestal.h"
#include "Skills.h"
#include "AttackSkill.h"
#include "MaceBash.h"
#include "DazzlingLight.h"
#include "DivineGrace.h"
#include "DivineComfort.h"

Vestal::Vestal(int a){
 name = "Vestal" + to_string((a%3)+1);
 MaxHP = 24;
 HP=24;
 dodge=0;
 prot=0;
 speed=4;
 accMod=0;
 baseCrit=1;
 minDmg=4;
 maxDmg=8;
 deathBlowResist=77;
 stunResist=30;

 position = a;
}

Vestal::~Vestal(){
//cout << "Vestal has been destroyed" << endl;
}

//--------- Automatic Skill Functions --------- //
void Hero::MaceBashAttack(std::vector<Monster>& vec2){
    int targetposition = (rand()%2);  //Mace Mash targets 1 or 2
if(vec2[0].getIsDead() == false || vec2[1].getIsDead() == false ) { // Is there any alive targets to attack?
while(vec2[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%2; } //change target until finding an alive one

srand(time(0));

MaceBash vestalMaceBashes;
hitChance = vestalMaceBashes.getBaseAcc() + accMod - vec2[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + vestalMaceBashes.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) {
    actualDmg = maxDmg * 1.5;  } //Critic damage is dealt
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + vestalMaceBashes.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec2[targetposition].getProt()/100);
}

cout << name << " hits " << vec2[targetposition].getName() << " with Mace Bash! Damage dealt: " << actualDmg << "\t->\t";
vestalMaceBashes.MaceBashAttack(vec2[targetposition], actualDmg);

}
else { cout << name << " missed the Mace Bash attack.\n"; }

}
else {cout << name << " missed! No rivals alive to attack with Mace Bash! \n";
}
};

void Hero::DazzlingLightAttack(std::vector<Monster>& vec2){
int targetposition = (rand()%3);  //Dazzling Light targets 1, 2 or 3
if(vec2[0].getIsDead() == false || vec2[1].getIsDead() == false || vec2[2].getIsDead() == false) { // Is there any alive targets to attack?
while(vec2[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%3; } //change target until finding an alive one

DazzlingLight vestalDazzlingLightes;
hitChance = vestalDazzlingLightes.getBaseAcc() + accMod - vec2[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + vestalDazzlingLightes.getBaseAcc() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)
stunChance = vestalDazzlingLightes.getStunBase() - vec2[targetposition].getStunResist();  //calculating the stun chance of attack

if ( doesCrit <= critChance ) {
actualDmg = maxDmg * 1.5;
stunChance =+ 20; } //Critic damage is dealt and stun chance is increased
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + vestalDazzlingLightes.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec2[targetposition].getProt()/100);
}

cout << name << " hits " << vec2[targetposition].getName() << " with Dazzling Light! Damage dealt: " << actualDmg << "\t->\t";
vestalDazzlingLightes.DazzlingLightAttack(vec2[targetposition], actualDmg);

if(vec2[targetposition].getIsDead() == false){
doesStun = (rand()%100);  //Game generates a random number to Stun or not
if (doesStun <= stunChance) {
    vec2[targetposition].setIsStunned(true);
    cout << vec2[targetposition].getName() << " is stunned for 1 Round! \n";
}
}
}
else { cout << name << " missed the Dazzling Light attack.\n"; }
}
else {cout << name << " missed! No rivals alive to attack with Mace Bash! \n";
}
};

void Hero::DivineGraceBuff(std::vector<Hero>& vec){
DivineGrace vestalBuffsDivineGrace;
cout << name << " buffs Divine Grace. " ;
vestalBuffsDivineGrace.DivineGraceBuff(vec);

}

void Hero::DivineComfortBuff(std::vector<Hero>& vec){
DivineComfort vestalBuffsDevineComfort;
cout << name << " buffs Divine Comfort. " ;
vestalBuffsDevineComfort.DivineComfortBuff(vec);

}
//--------- Automatic Skill Functions --------- //

//--------- User Selected Skill Functions --------- //
void Hero::MaceBashAttack(Monster& usertarget){
srand(time(0));

MaceBash vestalMaceBashes;
hitChance = vestalMaceBashes.getBaseAcc() + accMod - usertarget.getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + vestalMaceBashes.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) {
    actualDmg = maxDmg * 1.5;  } //Critic damage is dealt
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + vestalMaceBashes.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(usertarget.getProt()/100);
}

cout << name << " hits " << usertarget.getName() << " with Mace Bash! Damage dealt: " << actualDmg << "\t->\t";
vestalMaceBashes.MaceBashAttack(usertarget, actualDmg);

}
else { cout << name << " missed the Mace Bash attack.\n"; }

}

void Hero::DazzlingLightAttack(Monster& usertarget){
DazzlingLight vestalDazzlingLightes;
hitChance = vestalDazzlingLightes.getBaseAcc() + accMod - usertarget.getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + vestalDazzlingLightes.getBaseAcc() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)
stunChance = vestalDazzlingLightes.getStunBase() - usertarget.getStunResist();  //calculating the stun chance of attack

if ( doesCrit <= critChance ) {
actualDmg = maxDmg * 1.5;
stunChance =+ 20; } //Critic damage is dealt and stun chance is increased
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + vestalDazzlingLightes.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(usertarget.getProt()/100);
}

cout << name << " hits " << usertarget.getName() << " with Dazzling Light! Damage dealt: " << actualDmg << "\t->\t";
vestalDazzlingLightes.DazzlingLightAttack(usertarget, actualDmg);

if(usertarget.getIsDead() == false){
doesStun = (rand()%100);  //Game generates a random number to Stun or not
if (doesStun <= stunChance) {
    usertarget.setIsStunned(true);
    cout << usertarget.getName() << " is stunned for 1 Round! \n";
}
}
}
else { cout << name << " missed the Dazzling Light attack.\n"; }
}

void Hero::DivineGraceBuff(Hero& usertarget){
DivineGrace vestalBuffsDivineGrace;
cout << name << " buffs Divine Grace. " ;
vestalBuffsDivineGrace.DivineGraceBuff(usertarget);

}

//--------- User Selected Skill Functions --------- //

