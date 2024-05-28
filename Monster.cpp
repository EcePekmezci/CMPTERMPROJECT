#include "Unit.h"
#include "Monster.h"
#include "MoveSkill.h"

void Monster::moveMonster(std::vector<Monster>& vec2,int currentpos, int changetopos){
/*
int newPosition = currentpos - changetopos;

if(currentpos == 1 && changetopos == 1){
    cout << "Monster is already at first position. Can't move any further forward.\n" ;
}
else if (currentpos == 4 && changetopos == -1){
cout <<  "Monster is already at last position. Can't move any further back.\n" ;
}
else{
        for(int i =0 ; i<4 ; i++ ){
            if (vec2[i].getPosition() == newPosition){
                  vec2[i].setPosition(currentpos);
            }
            else if(vec2[i].getPosition() == currentpos){
                vec2[i].setPosition(newPosition);
            }
        }
cout << "Monster used move skill and change its position to " << newPosition <<"\n" ;
}*/

Move monsterMoveSkill;
monsterMoveSkill.moveMonster(vec2, currentpos, changetopos);
}

