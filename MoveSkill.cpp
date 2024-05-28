#include "MoveSkill.h"

void Move::moveHero(std::vector<Hero>& vec,int currentpos, int changetopos){

int newPosition = currentpos - changetopos;

if(currentpos == 1 && changetopos == 1){
    cout << "Hero is already at first position. Can't move any further forward.\n" ;
}
else if (currentpos == 4 && changetopos == -1){
cout << "Hero is already at last position. Can't move any further back.\n" ;
}
else{
        for(int i =0 ; i<4 ; i++ ){
            if (vec[i].getPosition() == newPosition){
                  vec[i].setPosition(currentpos);
            }
            else if(vec[i].getPosition() == currentpos){
                vec[i].setPosition(newPosition);
            }
        }
cout << "Hero used move skill and change its position to " << newPosition <<"\n" ;
}
}

void Move::moveMonster(std::vector<Monster>& vec2,int currentpos, int changetopos){

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
}
}

