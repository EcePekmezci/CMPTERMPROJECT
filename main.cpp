#include <iostream>
#include <vector>
#include "Unit.h"
#include "Hero.h"
#include "Crusader.h"
#include "Vestal.h"
#include "Monster.h"
#include "BoneDefender.h"
#include "BoneSoldier.h"
#include "Skills.h"
#include "AttackSkill.h"
#include "UtilitySkill.h"
#include "MoveSkill.h"
#include <time.h>

using namespace std;

// A function to shuffle token array
void shuffle_array(int arr[], int arraysize)
{   srand(time(0));
    int indexToChange = 0;
    int temp=0;

    for(int i=0; i<arraysize; i++){
       indexToChange = rand()%arraysize;
       temp = arr[i];
       arr[i] = arr[indexToChange];
       arr[indexToChange] = temp;
    }
}

int main()
{

// --------------- SETTING THE TEAMS UP -------------------- //

Crusader Crusader1(1);  //Crusader created for position 1
Crusader Crusader2(2);  //Crusader created for position 2
Vestal Vestal1(3);      //Vestal created for position 3
Vestal Vestal2(4);      //Vestal created for position 4

BoneSoldier BoneSoldier1(1);     //BoneSoldier created for position 1
BoneDefender BoneDefender1(2);   //BoneDefender created for position 2
BoneSoldier BoneSoldier2(3);     //BoneSoldier created for position 3
BoneDefender BoneDefender2(4);   //BoneDefender created for position 4

std::vector<Hero> Heroes;
Heroes.push_back(Crusader1);    //Crusader1 is places in position 1 of Heroes Team
Heroes.push_back(Crusader2);    //Crusader2 is places in position 2 of Heroes Team
Heroes.push_back(Vestal1);      //Vestal1 is places in position 3 of Heroes Team
Heroes.push_back(Vestal2);      //Vestal2 is places in position 4 of Heroes Team


std::vector<Monster> Monsters;
Monsters.push_back(BoneSoldier1);   //BoneSoldier1 is places in position 1 of Monsters Team
Monsters.push_back(BoneDefender1);  //BoneDefender1 is places in position 2 of Monsters Team
Monsters.push_back(BoneSoldier2);   //BoneSoldier2 is places in position 3 of Monsters Team
Monsters.push_back(BoneDefender2);  //BoneDefender2 is places in position 4 of Monsters Team

// --------------- TEAMS ARE SET UP -------------------- //

// --------------- DECISION OF GAMEPLAY: AUTOMATIC OR USER SELECTION -------------------- //

char userinput;
char userdecision;
char movedirection;
char userskill;
int usertarget;

cout << "Select the Gameplay Mode: press A for Automatic Play or B for User-Selection Play ;\n";
cin >> userinput;
while ( userinput != 'A' && userinput != 'B' && userinput != 'a' && userinput != 'b' ){
    cout << "Incorrect decision! Please press A for Automatic Play or B for User-Selection Play; \n";
    cin >> userinput; };

// --------------- GAME MODE SELECTED -------------------- //

// --------------- CREATING TOKENS TO SORT THE TURNS OF EACH ROUND -------------------- //
int tokens[] = {1, 2, 3, 4, 5, 6, 7, 8};

 shuffle_array(tokens, 8);
 /*  for(int i=0; i<8 ; i++){ cout << tokens[i] << "  ";} */

// --------------- TOKENS SHUFFLED RANDOMLY -------------------- //
int round = 1;
bool heroesLost = false;
bool monstersLost = false;
        srand(time(0));
//--------------------- GAME PLAY -------------------//
while ( heroesLost == false && monstersLost == false ){
         shuffle_array(tokens, 8); // randomize the token array for each round
  for( int turn=12; turn>1; turn--){

  for (int i=0; i<4; i++){    //Sharing the tokens; first random 4 to Heroes, last random 4 to Monsters

//------- HERO PLAYS IF HE HAS THE TURN ------- //
 if( Heroes[i].setSpeed(tokens[i]) == turn) {  //Gives the turn to the Heroes with higher speed to lower speed

    if (Heroes[i].getIsDead() == false){  //if Hero is not dead he can play
        if(Heroes[i].getIsStunned() == false){ //if Hero is not stunned he can play
                int skillDecision = rand()%20;

          // --------- IF THE HERO IS A CRUSADER --------- //
                if(Heroes[i].getMaxHP() == 33) { //Means the skill user is a Crusader

                if(userinput == 'A' || userinput == 'a'){ // ------------ Automatic Game Play of Hero --------- //
                switch (Heroes[i].getPosition()){
                        case 1: case 2:
                            if(skillDecision < 6){ Heroes[i].SmiteAttack(Monsters); }
                            else if(skillDecision >= 6 && skillDecision < 12){ Heroes[i].StunningBlowAttack(Monsters); }
                            else if(skillDecision >= 12 && skillDecision < 18){ Heroes[i].BulwarkOfFaithBuff(); }
                            else{
                                 if(skillDecision%2 == 0)  {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1);}
                                 else {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}
                                    }
                            break;
                        case 3: case 4:
                            if( skillDecision < 18){ Heroes[i].HolyLanceAttack(Monsters);
                            Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1); }
                             else{
                                 if(skillDecision%2 == 0)  {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1);}
                                 else {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}
                                    }
                            break;
                        default:
                            break;
                    }
                }  // ------------ Automatic Game Play of Hero --------- //

                if(userinput == 'B' || userinput == 'b'){  // ------------ User Selection GamePlay of Hero --------- //
     cout <<"Turn of " << Heroes[i].getName() <<". Press S to use a skill, M to move\n" ;
    cin >> userdecision;
    while(userdecision != 'S' && userdecision != 's' && userdecision != 'M' && userdecision != 'm'){
        cout << "Invalid entry. Please press S to use a skill, M to move \n";
        cin >> userdecision;
    }
        if(userdecision == 'S' || userdecision == 's') {
                switch (Heroes[i].getPosition()){
                    case 1: case 2:
                    cout << "Select a skill for " << Heroes[i].getName() << ". Press A to Smite, B to Stunning Blow or C to Bulwark of Faith\n";
                    cin >> userskill;
                    while (userskill != 'A' && userskill != 'a' && userskill != 'B' && userskill != 'b' && userskill != 'C' && userskill != 'c'){
                        cout << "Invalid entry. Please press A to Smite, B to Stunning Blow or C to Bulwark of Faith\n";
                        cin >> userskill;
                    }
                    if(userskill == 'A' || userskill == 'a'){
                    if(Monsters[0].getIsDead() == true && Monsters[1].getIsDead() == true){
                    cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() ;
                    }
                    else{
                        cout << "Which target do you want to attack with Smite? Pick 1 or 2. \n Note: If you enter an invalid target number, the target will be chosen as (input%2) \n";
                        cin >> usertarget;
                        if (usertarget<1 || usertarget>2) { usertarget = (usertarget%2)+1; }
                        if (Monsters[usertarget-1].getIsDead()== true){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target.\n ";
                        usertarget = (usertarget%2)+1;      }

                Heroes[i].SmiteAttack(Monsters[usertarget-1]);
                        }

                    }

                    if(userskill == 'B' || userskill == 'b'){
                    if(Monsters[0].getIsDead() == true && Monsters[1].getIsDead() == true){
                    cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() <<"\n" ;
                    }
                      else{
                        cout << "Which target do you want to attack with Stunning Blow? Pick 1 or 2. \n Note: If you enter an invalid target number, the target will be chosen as (input%2) \n";
                        cin >> usertarget;
                        if (usertarget<1 || usertarget>2) { usertarget = (usertarget%2)+1; }

                        if (Monsters[usertarget-1].getIsDead()== true){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target.\n ";
                        usertarget = (usertarget%2)+1;      }

                Heroes[i].StunningBlowAttack(Monsters[usertarget-1]);
                      }

                        }


                    if(userskill == 'C' || userskill == 'c'){

                Heroes[i].BulwarkOfFaithBuff();
                        }
                        // else { move !!}
                        break;

                    case 3: case 4:
                    if(Monsters[1].getIsDead() == true && Monsters[2].getIsDead() == true && Monsters[3].getIsDead() == true){
                    cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() << "\n";
                    }
                    else{
                    cout <<  "Due to the position of " << Heroes[i].getName() << " you can only attack with Holy Lance. Pick your target 2 to 4: \n";
                    cout << "Note: If you enter an invalid target number, the target will be chosen as (input%3)+2 \n" ;
                        cin >> usertarget;
                        if (usertarget<2 || usertarget>4) { usertarget = (usertarget%3)+2; }

                        while (Monsters[usertarget-1].getIsDead()== true){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target.\n ";
                        usertarget = (usertarget%3)+2;      }

                Heroes[i].HolyLanceAttack(Monsters[usertarget-1]);
                Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1);
                }
                        //  else { move!!}
                        break;
                    default:
                        break;
                            }}
            if(userdecision == 'M' || userdecision == 'm') {
               switch (Heroes[i].getPosition())  {
                case 1:
                    Heroes[i].moveHero(Heroes, 1, -1);
                    break;
                case 2: case 3:
      cout <<"Press F to move forward, B to backward \n" ;
    cin >> movedirection;
    while(movedirection != 'F' && movedirection != 'f' && movedirection != 'B' && movedirection != 'b'){
        cout << "Invalid entry. Please press F to move forward, B to backward \n";
        cin >> movedirection;
                }
                if(movedirection == 'F' || movedirection == 'f' ){Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1); }
                if(movedirection == 'B' || movedirection == 'b' ){Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}
                break;
                case 4:
               Heroes[i].moveHero(Heroes, 4, -1);
                break;
                default:
                break;
               }
          }

      }// ------------ User Selection GamePlay of Hero --------- //
      }
        // --------- IF THE HERO IS A CRUSADER --------- //

          // --------- IF THE HERO IS A VESTAL ---------- //
                else if(Heroes[i].getMaxHP() == 24) { //Means the skill user is a Vestal

                if (userinput == 'A' || userinput == 'a'){   // ------------ Automatic Game Play of Hero --------- //
                    switch (Heroes[i].getPosition()){
                        case 1:
                            if(skillDecision < 18){ Heroes[i].MaceBashAttack(Monsters); }
                            else{
                                 if(skillDecision%2 == 0)  {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1);}
                                 else {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}
                                    }
                            break;
                        case 2:
                            if(skillDecision < 6){ Heroes[i].MaceBashAttack(Monsters); }
                            else if(skillDecision >= 6 && skillDecision < 12){ Heroes[i].DazzlingLightAttack(Monsters); }
                            else if(skillDecision >= 12 && skillDecision < 18){ Heroes[i].DivineComfortBuff(Heroes); }
                            else{
                                 if(skillDecision%2 == 0)  {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1);}
                                 else {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}
                                    }
                            break;
                        case 3: case 4:
                           if(skillDecision < 6){ Heroes[i].DazzlingLightAttack(Monsters); }
                           else if(skillDecision >= 6 && skillDecision < 12){ Heroes[i].DivineGraceBuff(Heroes); }
                           else if(skillDecision >= 12 && skillDecision < 18){ Heroes[i].DivineComfortBuff(Heroes); }
                            else{
                                 if(skillDecision%2 == 0)  {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1);}
                                 else {Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}
                                    }
                            break;
                        default:
                            break;
                }
                } // ------------ Automatic Game Play of Hero --------- //

                if (userinput == 'B' || userinput == 'b'){   // ------------ User Selection GamePlay of Hero --------- //
    cout <<"Turn of " << Heroes[i].getName() <<". Press S to use a skill, M to move\n" ;
    cin >> userdecision;
    while(userdecision != 'S' && userdecision != 's' && userdecision != 'M' && userdecision != 'm'){
        cout << "Invalid entry. Please press S to use a skill, M to move \n";
        cin >> userdecision;
    }
        if(userdecision == 'S' || userdecision == 's') {
                switch (Heroes[i].getPosition()){
                        case 1:
                     if( Monsters[0].getIsDead() == false || Monsters[1].getIsDead() == false ) {
                    cout <<  "Due to the position of " << Heroes[i].getName() << "you can only attack with Mace Bash. Pick your target 1 or 2: \n";
                    cout << "Note: If you enter an invalid target number, the target will be chosen as (input%2) \n" ;
                        cin >> usertarget;
                        if ( usertarget <1 || usertarget>2 ) { usertarget = (usertarget%2)+1; }

                        if(Monsters[usertarget-1].getIsDead() == true ){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target.\n ";
                        usertarget = (usertarget%2)+1;      }
                Heroes[i].MaceBashAttack(Monsters[usertarget-1]);
                     }
                     else { cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() <<"\n" ;}
                        //else{move!}
                            break;
                        case 2:
                    cout << "Select a skill for " << Heroes[i].getName() << ". Press A to Mace Bash, B to Dazzling Light or C to Divine Comfort\n";
                    cin >> userskill;
                    while (userskill != 'A' && userskill != 'a' && userskill != 'B' && userskill != 'b' && userskill != 'C' && userskill != 'c'){
                        cout << "Invalid entry. Press A to Mace Bash, B to Dazzling Light or C to Divine Comfort\n";
                        cin >> userskill;
                    }
                        if(userskill == 'A' || userskill == 'a'){

                        if(Monsters[1].getIsDead() == true && Monsters[0].getIsDead() == true ){
                  cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() <<"\n" ;
                        }
                        else{
                        cout << "Which target do you want to attack with Mace Bash? Pick 1 or 2. \n Note: If you enter an invalid target number, the target will be chosen as (input%2) \n";
                        cin >> usertarget;
                        if ( usertarget < 1 || usertarget>2) { usertarget = (usertarget%2)+1; }

                        if(Monsters[usertarget-1].getIsDead() == true ){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target.\n ";
                        usertarget = ((usertarget+1)%2)+1;     }
                Heroes[i].MaceBashAttack(Monsters[usertarget-1]);
                        }

                        }
                        if(userskill == 'B' || userskill == 'b'){
                    if(Monsters[0].getIsDead() == true && Monsters[1].getIsDead() == true && Monsters[2].getIsDead() == true ){
                  cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() <<"\n" ; }
                      else {
                        cout << "Which target do you want to attack with Dazzling Light? Pick 1 to 3. \n Note: If you enter an invalid target number, the target will be chosen as (input%3) \n";
                        cin >> usertarget;
                        if ( usertarget <1 || usertarget>3) { usertarget = (usertarget%3)+1; }

                        while(Monsters[usertarget-1].getIsDead() == true ){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target. \n ";
                        usertarget = (usertarget%3)+1;  }
                Heroes[i].DazzlingLightAttack(Monsters[usertarget-1]);
                        }
                    }
                        if(userskill == 'C' || userskill == 'c'){
                Heroes[i].DivineComfortBuff(Heroes);
                        }
                        // else { move !!}
                        break;
                        case 3: case 4:
                    cout << "Select a skill for " << Heroes[i].getName() << ". Press A to Dazzling Light, B to Divine Grace or C to Divine Comfort\n";
                    cin >> userskill;
                    while (userskill != 'A' && userskill != 'a' && userskill != 'B' && userskill != 'b' && userskill != 'C' && userskill != 'c'){
                        cout << "Press A to Dazzling Light, B to Divine Grace or C to Divine Comfort\n";
                        cin >> userskill;
                    }
                        if(userskill == 'A' || userskill == 'a'){
                    if(Monsters[0].getIsDead() == true && Monsters[1].getIsDead() == true && Monsters[2].getIsDead() == true ){
                  cout << "no alive rivals to attack from this position of the hero " << Heroes[i].getName() ; }
                      else {
                        cout << "Which target do you want to attack with Dazzling Light? Pick 1 to 3. \n Note: If you enter an invalid target number, the target will be chosen as (input%3) \n";
                        cin >> usertarget;
                        if ( usertarget <1 || usertarget>3) { usertarget = (usertarget%3)+1; }

                        while(Monsters[usertarget-1].getIsDead() == true ){
                        cout << "Target monster is dead. Your pick has been replaced by the alive available target. .\n ";
                        usertarget = (usertarget%3)+1;}
                Heroes[i].DazzlingLightAttack(Monsters[usertarget-1]);
                        }
                        }
                        if(userskill == 'B' || userskill == 'b'){
                        cout << "Which target do you want to heal with Divine Grace? Pick 1 to 4. \n Note: If you enter an invalid target number, the target will be chosen as (input%4) \n";
                        cin >> usertarget;
                        if ( usertarget<1 || usertarget>4) { usertarget = (usertarget%4)+1; }

                        while(Heroes[usertarget-1].getIsDead() == true ){
                        cout << "Target Hero is dead. Your pick has been replaced by the alive available target.\n ";
                        usertarget = (usertarget%4)+1; }

                Heroes[i].DivineGraceBuff(Heroes[usertarget-1]);
                        }
                        if(userskill == 'C' || userskill == 'c'){

                Heroes[i].DivineComfortBuff(Heroes);
                        }
                        // else { move !!}
                            break;
                        default:
                            break;
                } }
          if(userdecision == 'M' || userdecision == 'm') {
               switch (Heroes[i].getPosition())  {
                case 1:
                    Heroes[i].moveHero(Heroes, 1, -1);
                    break;
                case 2: case 3:
      cout <<"Press F to move forward, B to backward \n" ;
    cin >> movedirection;
    while(movedirection != 'F' && movedirection != 'f' && movedirection != 'B' && movedirection != 'b'){
        cout << "Invalid entry. Please press F to move forward, B to backward \n";
        cin >> movedirection; }

                if(movedirection == 'F' || movedirection == 'f' ){Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), 1); }
                if(movedirection == 'B' || movedirection == 'b' ){Heroes[i].moveHero(Heroes, Heroes[i].getPosition(), -1);}

                break;
                case 4:
               Heroes[i].moveHero(Heroes, 4, -1);
                break;
                default:
                break;
               }
          }

                }         // ------------ User Selection GamePlay of Hero --------- //

                }
        // --------- IF THE HERO IS A VESTAL ---------- //
        }
        else { Heroes[i].setIsStunned(false);
        cout << Heroes[i].getName() << " was stunned. He couldn't attack! \n";
        }  //Hero stunned round is over

        if(Heroes[i].BoFCounter >= 0){  //   IF THE HERO HAS BULWARK OF FAITH BUFF, DECREASE THE COUNTER UNTIL THE BUFF ENDS
            Heroes[i].BoFCounter--;
            if(Heroes[i].BoFCounter==0){ Heroes[i].resetBoFBuff();} //WHEN THE BUFF ENDS, RESET THE PROTECTION OF THE HERO
        }
  //  delay(500);  //Giving half second delays after each turn
    }
    else {cout << Heroes[i].getName() << " is dead. He can't use skills! \n";}
    }  //Hero stunned round is over

//------- HERO PLAYED IF HE HAD THE TURN ------- //


//------- MONSTER PLAYS IF HE HAS THE TURN ------- //
if( Monsters[i].setSpeed(tokens[i+4]) == turn){ //Gives the turn to the Monsters with higher speed to lower speed
    if (Monsters[i].getIsDead() == false){  //if Monster is not dead he can play
        if(Monsters[i].getIsStunned() == false){ //if Monster is not stunned he can play

        int skillDecision = rand()%20;

         if(Monsters[i].getMaxHP() == 10) { //Means Monster is a Bone Soldier
                    switch (Monsters[i].getPosition()){
                        case 0: case 1: case 2:
                            if(skillDecision < 18){ Monsters[i].GraveyardSlashAttack(Heroes); }
                            else{
                                 if(skillDecision%2 == 0)  {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), 1);}
                                 else {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), -1);}
                                    }
                            break;
                        case 4:
                            if(skillDecision < 18){ Monsters[i].GraveyardStumbleAttack(Heroes);
                            Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), 1);}
                            else{
                                 if(skillDecision%2 == 0)  {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), 1);}
                                 else {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), -1);}
                                    }
                            break;
                        default:
                            break;
                    }
         }

        else if (Monsters[i].getMaxHP() == 22) { //Means Monster is a Bone Defender
                        switch (Monsters[i].getPosition()){
                        case 0: case 1:
                            if(skillDecision < 9){ Monsters[i].AxebladeAttack(Heroes); }
                            else if(skillDecision > 9 && skillDecision < 18){ Monsters[i].DeadWeightAttack(Heroes); }
                            else{
                                 if(skillDecision%2 == 0)  {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), 1);}
                                 else {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), -1);}
                                    }
                            break;
                        case 2:
                            if(skillDecision < 9){ Monsters[i].DeadWeightAttack(Heroes); }
                            else if(skillDecision > 9 && skillDecision < 18){ Monsters[i].KnittingBonesBuff(Monsters); }
                            else{
                                 if(skillDecision%2 == 0)  {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), 1);}
                                 else {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), -1);}
                                    }
                            break;
                        case 3:
                            if(skillDecision < 18){ Monsters[i].KnittingBonesBuff(Monsters); }
                            else{
                                 if(skillDecision%2 == 0)  {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), 1);}
                                 else {Monsters[i].moveMonster(Monsters, Monsters[i].getPosition(), -1);}
                                    }
                            break;
                        default:
                            break;
                    }
         }

        }
        else { Monsters[i].setIsStunned(false);
        cout << Monsters[i].getName() << "was stunned! He couldn't attack! \n*"; }  //Monster stunned round is over

    }

    else {cout << Monsters[i].getName() << " is dead. He can't use skills! \n";}
  }
//------- MONSTER PLAYED IF HE HAD THE TURN ------- //


}
  }
  cout << "\n\n ----------------- End of Round " << round << " -----------------\n\n";
  round++;

  if(Heroes[0].getIsDead()==true && Heroes[1].getIsDead()==true && Heroes[2].getIsDead()==true && Heroes[3].getIsDead()==true){heroesLost = true;}
  if(Monsters[0].getIsDead()==true && Monsters[1].getIsDead()==true && Monsters[2].getIsDead()==true && Monsters[3].getIsDead()==true){monstersLost = true;}
}
  // -------------------------  GAME PLAY -------------------------------- //

  //-------------------------- DISPLAY RESULTS ----------------------------//
if(monstersLost == true && heroesLost == false) {
    cout << "\n\n Good Game! \n Heroes have won! \n\n Alive heroes are: \n" ;
    for (int i=0; i<4; i++){
        if(Heroes[i].getIsDead()==false) { cout << " " << Heroes[i].getName(); }
    }
}

if(monstersLost == false && heroesLost==true) {
    cout << "\n\n Bad Game! \n Monsters have won! \n\n Alive monsters are: \n" ;
    for (int i=0; i<4; i++){
        if(Monsters[i].getIsDead()==false) { cout << " " << Monsters[i].getName(); }
    }
}
  //-------------------------- DISPLAY RESULTS ----------------------------//


  }



