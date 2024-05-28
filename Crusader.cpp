#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Unit.h"
#include "Hero.h"
#include "Crusader.h"
#include "Skills.h"
#include "AttackSkill.h"
#include "Smite.h"
#include "StunningBlow.h"
#include "HolyLance.h"
#include "UtilitySkill.h"
#include "BulwarkOfFaith.h"

Crusader::Crusader(int a){
 name = "Crusader" + to_string(a);
 MaxHP = 33;
 HP=33;
 dodge=5;
 prot=0;
 speed=1;
 accMod=0;
 baseCrit=3;
 minDmg=6;
 maxDmg=12;
 deathBlowResist=67;
 deathsDoor= false;
 stunResist=40;
 BoFCounter = 0;
 position = a;
}


Crusader::~Crusader(){
//cout << "crusader has been destroyed" << endl;
}

//---------Automatic Skill Functions-----------//
void Hero::SmiteAttack(std::vector<Monster>& vec2){
if(vec2[0].getIsDead() == false || vec2[1].getIsDead() == false) { // Is there any alive targets to attack?
int targetposition = (rand()%2);  //Smite targets 1 or 2
while(vec2[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%2; } //change target until finding an alive one

srand(time(0));
Smite crusaderSmites;
hitChance = crusaderSmites.getBaseAcc() + accMod - vec2[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

// cout << "hit chance: " << hitChance << endl;
// cout << "does it hit random: " << doesHit << endl;

if ( doesHit <= hitChance ){
critChance = baseCrit + crusaderSmites.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt
//cout << "attack is critic!" << endl;
}
 // cout << "crit chance: " << critChance << endl;
 // cout << "does it crit random: " << doesCrit << endl;
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + crusaderSmites.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec2[targetposition].getProt()/100);
}
// cout << "final damage:" << actualDmg << endl;
cout << name << " hits " << vec2[targetposition].getName() << " with Smite! Damage dealt: " << actualDmg << " \t ->\t";
    crusaderSmites.SmiteAttack(vec2[targetposition], actualDmg);

}
else { cout << name << " missed the smite attack.\n"; }
}
else {cout << name << " missed! No rivals alive to attack with Smite! \n";
}
}

void Hero::StunningBlowAttack(std::vector<Monster>& vec2){
if(vec2[0].getIsDead() == false || vec2[1].getIsDead() == false) { // Is there any alive targets to attack?
int targetposition = (rand()%2);  //Stunning Blow targets 1 or 2
while(vec2[targetposition].getIsDead() == true ) { targetposition = (targetposition+1)%2; } //change target until finding an alive one

StunningBlow crusaderStunningBlows;
hitChance = crusaderStunningBlows.getBaseAcc() + accMod - vec2[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss


if ( doesHit <= hitChance ){
critChance = baseCrit + crusaderStunningBlows.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to critic or not (normal hit)
stunChance = crusaderStunningBlows.getStunBase() - vec2[targetposition].getStunResist();

if ( doesCrit <= critChance ) {
actualDmg = maxDmg * 1.5;
stunChance =+ 20; } //Critic damage is dealt
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + crusaderStunningBlows.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec2[targetposition].getProt()/100);
}

cout << name << " hits " << vec2[targetposition].getName() << " with Stunning Blow! Damage dealt: " << actualDmg <<  " ->\t";
crusaderStunningBlows.StunningBlowAttack(vec2[targetposition], actualDmg);
if(vec2[targetposition].getIsDead() == false){
doesStun = (rand()%100);  //Game generates a random number to Stun or not
if (doesStun <= stunChance) {
    vec2[targetposition].setIsStunned(true);
    cout << vec2[targetposition].getName() << " is stunned for 1 Round! \n" ;
}
}
}
else { cout << name << " missed the smite attack. \n" ; }
}
else {cout << name << " missed! No rivals alive to attack with Smite! \n";
}
}

void Hero::HolyLanceAttack(std::vector<Monster>& vec2){
if(vec2[1].getIsDead() == false || vec2[2].getIsDead() == false || vec2[3].getIsDead() == false) { // Is there any alive targets to attack?
int targetposition = (rand()%3)+1;  //Holy Lance targets 2,3 or 4
while(vec2[targetposition].getIsDead() == true ) { targetposition = (targetposition%3)+1; } //change target until finding an alive one

HolyLance crusaderHolyLances;
hitChance = crusaderHolyLances.getBaseAcc() + accMod - vec2[targetposition].getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + crusaderHolyLances.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt
}
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + crusaderHolyLances.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(vec2[targetposition].getProt()/100);
}
cout << name << " hits " << vec2[targetposition].getName() << " with Holy Lance! Damage dealt: " << actualDmg << "\t->\t";
    crusaderHolyLances.HolyLanceAttack(vec2[targetposition], actualDmg);

}
else { cout << name << " missed the Holy Lance attack.\n" ; }
}
else {cout << name << " missed! No rivals alive to attack with Holy Lance! \n";
}
}

void Hero::BulwarkOfFaithBuff(){
BulwarkOfFaith crusaderBuffsBoF;
prot = crusaderBuffsBoF.BulwarkOfFaithBuff(prot);
BoFCounter = 3 ;  //counts rounds for Bulwark Of Faith Skill
cout << name << " buffed himself +20 protection with Bulwark Of Faith for 3 rounds! \n";
}
//---------Automatic Skill Functions-----------//

//---------User Selected Skill Functions-----------//
void Hero::SmiteAttack(Monster& usertarget){
srand(time(0));
Smite crusaderSmites;
hitChance = crusaderSmites.getBaseAcc() + accMod - usertarget.getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss


if ( doesHit <= hitChance ){
critChance = baseCrit + crusaderSmites.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt

}

else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + crusaderSmites.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(usertarget.getProt()/100);
}
// cout << "HP change :" << usertarget.getHP() << endl;
cout << name << " hits " << usertarget.getName() << " with Smite! Damage dealt: " << actualDmg << " \t ->\t";
    crusaderSmites.SmiteAttack(usertarget, actualDmg);
// cout << "HP change :" << usertarget.getHP() << endl;
}
else { cout << name << " missed the smite attack.\n"; }

}

void Hero::StunningBlowAttack(Monster& usertarget){
StunningBlow crusaderStunningBlows;
hitChance = crusaderStunningBlows.getBaseAcc() + accMod - usertarget.getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + crusaderStunningBlows.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to critic or not (normal hit)
stunChance = crusaderStunningBlows.getStunBase() - usertarget.getStunResist();

if ( doesCrit <= critChance ) {
actualDmg = maxDmg * 1.5;
stunChance =+ 20; } //Critic damage is dealt
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + crusaderStunningBlows.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(usertarget.getProt()/100);
}

cout << name << " hits " << usertarget.getName() << " with Stunning Blow! Damage dealt: " << actualDmg <<  " ->\t";
crusaderStunningBlows.StunningBlowAttack(usertarget, actualDmg);
if(usertarget.getIsDead() == false){
doesStun = (rand()%100);  //Game generates a random number to Stun or not
if (doesStun <= stunChance) {
    usertarget.setIsStunned(true);
    cout << usertarget.getName() << " is stunned for 1 Round! \n" ;
}
}
}
else { cout << name << " missed the smite attack. \n" ; }
}

void Hero::HolyLanceAttack(Monster& usertarget){
HolyLance crusaderHolyLances;
hitChance = crusaderHolyLances.getBaseAcc() + accMod - usertarget.getDodge() ; //calculating hit chance of attack
doesHit = (rand()%100);  //Game generates a random number to hit or miss

if ( doesHit <= hitChance ){
critChance = baseCrit + crusaderHolyLances.getCritMod() ;
doesCrit = (rand()%100);  //Game generates a random number to crit or not (normal hit)

if ( doesCrit <= critChance ) { actualDmg = maxDmg * 1.5;  //Critic damage is dealt
}
else {
dmg = rand()%(maxDmg - minDmg) + minDmg;
rawDmg = dmg*(100 + crusaderHolyLances.getDmgMod())/100;
actualDmg = rawDmg - rawDmg*(usertarget.getProt()/100);
}
cout << name << " hits " << usertarget.getName() << " with Holy Lance! Damage dealt: " << actualDmg << "\t->\t";
    crusaderHolyLances.HolyLanceAttack(usertarget, actualDmg);

}
else { cout << name << " missed the Holy Lance attack.\n" ; }
}

//---------User Selected Skill Functions-----------//
