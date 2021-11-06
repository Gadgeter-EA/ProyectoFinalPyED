#pragma once

enum PQuest {intro, mid, end};

class Laberinto {

    private:
        //Cuarto maze[5][5];
        int x, y; // Coordenadas del jugador
        PQuest quest[3];

    public:
        Laberinto();
        ~Laberinto();
        void playRoom(int x, int y);
};

class Fase1:Laberinto{

};

class Fase2:Laberinto{

};
