#pragma once

#include "Chest.h"

using namespace std;

class CuartoDef {

    private:
        bool firstTime = true;

    public:
        Chest cofre = Chest();
        bool paths[4];

        CuartoDef(){
            paths[0] = true;
            paths[1] = true;
            paths[2] = true;
            paths[3] = true;
        }

        ~CuartoDef(){

        }

        void setWays(bool left, bool right, bool up, bool down){
            paths[0] = left;
            paths[1] = right;
            paths[2] = up;
            paths[3] = down;
        }

        bool getfirstTime(){
            return firstTime;
        }

        void setfirstTime(bool option){
            firstTime = option;
        }
};



