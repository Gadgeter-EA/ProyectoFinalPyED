#include "Laberinto.h"

using namespace std;

int main() {

    srand(time(NULL));

    Fase1 phase1 = Fase1();
    phase1.runGame();
    
    return 0;
}
