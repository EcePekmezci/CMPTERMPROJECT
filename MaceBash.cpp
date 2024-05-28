#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <vector>
#include "Skills.h"
#include "AttackSkill.h"
#include "MaceBash.h"


MaceBash::MaceBash(){}

void MaceBash::MaceBashAttack(Monster &M, int damage){
//    cout << "monster hp was: " << M.HP << endl;
M.setHP(M.getHP() - damage);
   if(M.getHP() > 0){
    cout << M.getName() << " hp reduced to: " << M.getHP() << "\n"; }
    else  {M.setIsDead(true);
     cout << "--" << M.getName() << " died! \n"; }
};



