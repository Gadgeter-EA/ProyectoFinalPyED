#pragma once

#include "CuartoDef.h"
#include <windows.h>

using namespace std;

enum PQuest {intro, mid, end};

class Laberinto {

    protected:
        CuartoDef maze[5][5];
        int x, y; // Coordenadas del jugador
        PQuest quest[3];

    public:
        Laberinto(){

        }
        ~Laberinto(){

        }
        void playRoom(int x, int y);
};

class Fase1: public Laberinto{

    private:
        PQuest tutorial;
        Player *player;


    public:
        Fase1(){

            string playerName;

            cout << "Bienvenido a la Pre-Alpha de Rey Carmesi" << endl;
            system("pause");
            system("cls");

            while(true){
                cout << "Ingrese el nombre de su personaje: ";
                getline(cin, playerName);
                if(!playerName.empty()){
                    break;
                }
                else{
                    cout << "Ingresa un nombre valido..." << endl;
                    system("pause");
                    system("cls");
                }
            }


            system("cls");

            cout << endl << "Lo que vas a jugar es el tutorial y la version muy temprana del juego. Por lo que errores y crasheos pueden ocurrir." << endl;
            cout << "Teniendo en mente eso empecemos..." << endl;
            system("pause");
            system("cls");

            player = new Player(playerName, 3, 3);

            x = 0; y = 0;
            tutorial = intro;

            maze[0][0].setWays(false, true, false, true);
            maze[0][1].setWays(true, false, false, false);
            maze[0][2].setWays(false, false, false, true);
            maze[1][0].setWays(false, true, true, false);
            maze[1][1].setWays(true, true, false, false);
            maze[1][2].setWays(false, false, true, false);

            cout << "....." << endl;
            system("pause");
            system("cls");
            cout << "Te despiertas en un cuarto oscuro, parece un calabozo..." << endl;
            system("pause");
            system("cls");
        }
        ~Fase1(){
            delete player;
        }

        void runGame(){

            int option, i;
            bool goodOption = true;

            while(true){

                playRoom(x, y);

                goodOption = false;

                while(!goodOption){

                    cout << "Ubicacion: (" << x << ")(" << y <<")" << endl << endl;
                    cout << "Vida: " << player->getLife() << endl;
                    cout << "Escudo: " << player->getShield() << endl << endl;
                    cout << "1)Ir a la izquierda" << endl;
                    cout << "2)Ir a la derecha" << endl;
                    cout << "3)Ir arriba" << endl;
                    cout << "4)Ir abajo" << endl;
                    cout << "5)Abrir inventario" << endl;
                    cout << "6)Abrir cofre del cuarto" << endl << endl;
                    cout << "Que vas a hacer a continuacion?: " ;
                    cin >> option;


                    switch(option){

                        case 1:
                            if(maze[x][y].paths[0]){
                                y--;
                                goodOption = true;
                            } else cout << "No hay camino a la izquierda..." << endl;
                            system("pause");
                            system("cls");
                            break;

                        case 2:
                            if(maze[x][y].paths[1]){
                                y++;
                                goodOption = true;
                            } else cout << "No hay camino a la derecha..." << endl;
                            system("pause");
                            system("cls");
                            break;

                        case 3:
                            if(maze[x][y].paths[2]){
                                x--;
                                goodOption = true;
                            } else cout << "No hay camino arriba..." << endl;
                            system("pause");
                            system("cls");
                            break;

                        case 4:
                            if(maze[x][y].paths[3]){
                                x++;
                                goodOption = true;
                            } else cout << "No hay camino abajo..." << endl;
                            system("pause");
                            system("cls");
                            break;

                        case 5:
                            player->inventario.showInventory();
                            goodOption = true;
                            system("pause");
                            system("cls");
                            break;

                        case 6:
                           player->inventario.addItem(maze[x][y].cofre.openChest((player)));
                           goodOption = true;
                           system("pause");
                           system("cls");
                           break;

                        default:
                            cout << "Ponte serio..." << endl;
                            system("pause");
                            system("cls");
                    }
                }
            }
        }

        void playRoom(int x, int y){

            if(x == 0 && y==0){ //SPAWN

                if(maze[x][y].getfirstTime() && tutorial == intro){

                    string dialog = "Hay una nota en tu frente, dice:\nTu nombre es: " + player->getName() + "\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    dialog =  "Parece que solo hay 2 caminos...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }

            }
            else if(x == 0 && y==1){ // GNOMO
                if(maze[x][y].getfirstTime() && tutorial == intro){ // GNOMO INTRO

                    int option = 0;
                    bool passTree = false;

                    string dialog =  "Al entrar al cuarto, hay pequenio enano con un hacha en la espalda, pantalones cafes y un oberol roto...\nPor la forma en la que te mira parece que quiere hablar contigo\nTe acercas para hablar con el.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "GNOMO: No tienes ni idea de que pasa verdad?\n\n";
                    writeDialogs(dialog);
                    cout << "1)No, ayuda porfavor. QUE ESTA PASANDO AQUI!" << endl;
                    cout << "2)No...Tu sabes algo?" << endl;
                    cout << "3)Emm...Que se supone eres?....Hueles mal..." << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "GNOMO: Hey Hey, calmado....no te alteres\n"; passTree = true; break;
                            case 2: dialog = "GNOMO: Hehe, pues...si, unas cosas se podria decir...\n"; passTree = true; break;
                            case 3: dialog = "GNOMO: A TI QUE TE IMPORTA COMO HUELO!....agg....\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "GNOMO: Mira..., hagamos un trato. Llevo mucho sin comer...\nSi vas al arbol que esta por aqui cerca y me traes una manzana, te puede decir unas cosillas que te seran utiles..\nTrato? Ahora..LARGO!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Sin algo mejor que hacer, decides ayudar al gnomo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
            }
        }

        void writeDialogs(string dialog){

            int i=0;
            while ( dialog[i] != '\0')
            {
                cout << dialog[i];
                Sleep(50);
                i++;
            };
        }
};
