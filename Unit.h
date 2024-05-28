#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Unit {

protected:
string name;

int MaxHP;
int HP;
int dodge;
int prot;
int speed;
int accMod;
int baseCrit;
int minDmg;
int maxDmg;
int stunResist;

int dmg;
double rawDmg;
int actualDmg;
int position;
int hitChance;
int doesHit;
int critChance;
int doesCrit;
int stunChance;
int doesStun;

bool isStunned = false;
bool isDead = false;
// bool isMoved;

public:

void setIsStunned(bool stunnedOrNot){ isStunned = stunnedOrNot;}

bool getIsStunned(){ return isStunned; }

void setIsDead( bool deadOrNot){isDead = deadOrNot;}

bool getIsDead(){ return isDead; }

string getName(){ return name; }

int getMaxHP(){ return MaxHP; }

int getHP(){ return HP; }

void setHP(int newHP){ HP = newHP; }

int getDodge (){ return dodge; }

int getProt() { return prot; }

int getStunResist() { return stunResist; }

int getPosition() { return position; }

void setPosition(int a) { position =a; }

int setSpeed(int token) { int newSpeed = speed+token;
return newSpeed; }

int resetSpeed() { return speed; }

//Unit();
//~Unit(){};


};

#endif // UNIT_H
