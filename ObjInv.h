#pragma once

#include <iostream>
#include <string>

using namespace std;

class ObjInv {

    private:
        string name;
        string description;

    public:
        ObjInv(string name,string description){
            this->name = name;
            this->description = description;
        }

        ~ObjInv(){

        }

        void info(){
            cout << "Name: " << name << endl;
            cout << "Description: " << description << endl;
        }
};    


