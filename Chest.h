#pragma once

#include "GameUtilities.h"

using namespace std;

class Chest {

    protected:
        ObjInv* item = NULL;
        bool isOpen;

    public:

        Chest(){

            generateItem();
            isOpen = 0;
        }

        ~Chest(){
            
            if(item != NULL){
                delete item;
            }
        }

        ObjInv* openChest(Player* player){

            if(!isOpen){

                isOpen = 1;
                
                if(item != NULL){

                    cout << "Has recogido un(a) " << item->getName() << endl;
                    return item;
                }
                else{
                    player->takeDamage();
                    cout << "Han salido flechas del cofre, pierdes un a vida." << endl;
                    return NULL;// Le dispara flechas al jugador, hiriendolo
                }
            }
            else{

                cout << "El cofre ya esta abierto" << endl;
                return NULL;
            }
        }
        
        void generateItem(){
            
            int n = 0 + (rand() % (99+1));
            
            if(n <= 39){
                item = new Potion("Pocion", "Aumenta tu vida en 1");
            }
            else if(n >=40 && n <= 79){
                item = new Shield("Escudo", "Aumenta tu escudo en 1");
            }
            else return;
        }
};



