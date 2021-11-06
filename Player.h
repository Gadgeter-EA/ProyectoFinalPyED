#pragma once

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Player {

    private:
        stack<int> life;
        stack<int> shield;
        int maxShield, maxLife;       
        //Inventory inv;
        string name;

    public:

        Player(string name, int lives, int shield){

            maxLife = lives;
            maxShield = shield;
            this->name = name;

            for(int i = 0; i < lives; i++){
                life.push(1);
            }

        }//constructor
        
        ~Player(){
            
        }//destructor

        void takeDamage(){
            
            if(!shield.empty()){
                shield.pop();
            }
            else{
                life.pop();

                if(life.empty()){
                    cout << "GAME OVER" << endl;
                    exit(1);
                }
            }
            
        }//takeDamage
        
};



