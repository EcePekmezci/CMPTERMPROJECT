#include "Unit.h"
#include "Hero.h"
#include "MoveSkill.h"
void Hero::moveHero(std::vector<Hero>& vec,int currentpos, int changetopos){
/*
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
*/

Move heroMoveSkill;
heroMoveSkill.moveHero(vec, currentpos, changetopos);

}
