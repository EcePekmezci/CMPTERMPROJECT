#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <vector>
#include "Skills.h"
#include "AttackSkill.h"
#include "Axeblade.h"
#include "Hero.h"

Axeblade::Axeblade(){}

void Axeblade::AxebladeAttack(Hero &H, int damage){
 //   cout << "Hero hp was: " << H.HP << endl;
H.setHP(H.getHP() - damage);
    cout << H.getName() << " hp reduced to: " << H.getHP() << "\n";
                if (H.getHP() <= 0) {H.setDeathDoorState(true);
     cout  << "--" << H.getName() << " is in Death's Door! \n" ; }
};




