#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include "Graph.h"

using namespace std;
Graph g;

class Player{
protected:
    int intHealth;
    int intArmor;
    int intDam;
public:
    Player(){
        cout<<"Let the adventure begin!"<<endl;
        intHealth = 100;
        intArmor = 0;
        intDam = 5;
    }~Player(){}

    void changeHealth(int intChange){
        intHealth += intChange;
        if (intChange > 0){
            cout<<"You gained "<<intChange<<" health."<<endl;
        }if (intChange < 0){
            cout<<"You lost "<<intChange<<" health."<<endl;
        }cout<<"Health: "<<intHealth<<endl;
    }

    int getPHealth(){
        return intHealth;
    }int getPArmor(){
        return intArmor;
    }int getPDam(){
        return intDam;
    }
};

struct Enemy{
protected:
    int intEHealth;//Health
    int intBAttack;//Base attack value
    int intRVal;//Determines reward
    int intTVal;//Turn which it can be used
    bool isAlive;
    string strName;
public:
    Enemy(){}
    ~Enemy(){}
    int getTurn(){
        return intTVal;
    }int getEHealth(){
        return intEHealth;
    }int getBAttack(string strN){
        cout<<"You are attacked by a "<<strN<<endl;
        return intBAttack;
    }string getName(){
        return strName;
    }void takeDam(int dam){
        intEHealth -= dam;
    }bool getAlive(){
        return isAlive;
    }void kill(){
        isAlive = false;
    }
};

int main()
{
    //Player P1;
    int intLevel = 0;
    int health = 100;
    string str;
    //while(P1.getPHealth() > 0){
    while(health > 0){
        intLevel++;
        g.emptyG();
        for(int intRoom = 0; intRoom <= intLevel*2; intRoom++){
            g.newRoom(intRoom);
        }
        cout<<"What do you do?"<<endl;
        cin >> str;
    }
    return 0;
}
