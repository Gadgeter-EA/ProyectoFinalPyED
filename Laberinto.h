#pragma once

#include "CuartoDef.h"
#include <windows.h>

using namespace std;

enum PQuest {intro, mid, mid2, finall};
enum Elementals {water, fire, ice};

class Laberinto {

    protected:
        CuartoDef maze[5][5];
        int x, y; // Coordenadas del jugador
        PQuest quest[2] = {intro};

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
        bool ended;


    public:
        Fase1(){

            string playerName;
            ended = false;

            cout << "Beta Version" << endl;
            system("pause");
            system("cls");

            cout << endl << "Errores y crasheos pueden ocurrir." << endl;
            cout << "Teniendo en mente eso empecemos..." << endl;
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

            player = new Player(playerName, 3, 3);

            x = 0; y = 0;
            tutorial = intro;

            maze[0][0].setWays(false, true, false, true);
            maze[0][1].setWays(true, false, false, false);
            maze[0][2].setWays(false, false, false, true);
            maze[1][0].setWays(false, false, true, false);
            maze[1][1].setWays(true, true, false, false);
            maze[1][2].setWays(true, false, true, false);
            // SEGUNDA FASE
            maze[2][0].setWays(false, true, false, false);
            maze[2][1].setWays(true, true, false, false);
            maze[2][2].setWays(true, true, false, false);
            maze[2][3].setWays(true, false, true, false); // GOTA
            maze[0][3].setWays(false, false, false, true); // DRAGON
            maze[1][3].setWays(false, true, true, true); // COSTURERA
            maze[3][3].setWays(false, false, true, true); // LAVA
            maze[4][3].setWays(false, true, true, false); // LAGO
            maze[0][4].setWays(false, false, false, true); // COFRE +VIDA
            maze[1][4].setWays(true, false, true, true); // LLAVE +VIDA
            maze[2][4].setWays(false, false, true, false); // MERCADER
            maze[3][4].setWays(false, false, false, true); // LORE ROOM
            maze[4][4].setWays(true, false, true, false); // DEF ROOM

            //TERCERA FASE
            maze[3][1].setWays(true, false, false, true); // LLEGADA PUERTA PEQUEÑA
            maze[3][0].setWays(false, true, false, false); // CAIN
            maze[4][0].setWays(false, true, false, false); // VOMITO ARCOIRIS
            maze[4][1].setWays(true, true, true, false); // Cuarto X
            maze[4][2].setWays(true, false, false, false); // PUERTA GIGANTE

            string dialog = "\"El mundo es solo para aquellos que realmente lo valoran, Seras digno de el?\"\n"
                            "El frio penetrante del ambiente retuerce tus huesos, abres los ojos y de una profunda oscuridad poco a poco logras vislumbrar el ambiente que tienes frente a ti.\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");

            dialog = "-...-\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");

            dialog = player->getName() + ": D...Donde estoy?\nQ...Quien soy yo?\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");

            dialog = "Te das cuenta que te encuentras en un cuarto circular sin ventanas, el cuarto esta iluminado en el centro por un tragaluz el cual alumbra una mesa con algunos objetos.\n"
                     "Con todo y el dolor en tus huesos te incorporas y caminas poco a poco hacia la mesa, en ella te encuentras una linterna de aceite, tres frascos y una nota.\n"
                     "Tomas la nota en tus manos y la lees.\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");

            dialog = "\"Que vuestro paso por el dedalo de nuestro Rey Carmesi llene su alma de viveza y cognicion, ya que solo los dignos sereis capaces de superar esta prueba.\n"
                     "...Eres uno de ellos " + player->getName() + "\"?\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");

            dialog = player->getName() + ": " + player->getName()+ "? Me llamo " + player->getName() + "? \n"
                     "Que es esto? No entiendo nada...\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");

            dialog = "Tomas todos los demas objetos que estaban en la mesa y despues de observar bien toda la recamara, \n"
                     "sales por el unico acceso  que hay, una inmensa puerta de Roble pintada de rojo con un dibujo de un buho con una corona.\n";
            writeDialogs(dialog);
            system("pause");
            system("cls");
        }

        ~Fase1(){
            delete player;
        }

        void runGame(){

            int option;
            bool goodOption;

            while(!ended){

                playRoom(x, y);

                if(ended) continue;

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
                            system("cls");
                            player->inventario.useIventory(player);
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

                    string dialog = player->getName() + ": Hola!?\n"
                                    "Hay alguien que me escuche!? Que es esto?! No entiendo nada...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    dialog =  "Despues de salir de la puerta te encuentras otro cuarto oscuro alumbrado por un candelabro de velas rojas,\nel cual "
                              "alumbra un cofre de madera con detalles dorados en sus extremos.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }

            }
            else if(x == 0 && y==1){ // GNOMO
                if(maze[x][y].getfirstTime() && tutorial == intro){ // GNOMO

                    int option = 0;
                    bool passTree = false;

                    string dialog =  "Entras a un cuarto lleno de arboles y arbustos, tras caminar y apartar algunos de ellos que cubren tu camino escuchas algunos sonidos y quejidos,\n"
                                     "caminas lentamente hacia lo que sea que emita esos sonidos, paso a paso los sonidos aumentan su intencidad hasta que un solo arbusto los separa de ti.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Con mucho miedo atraviesas el ultimo arbusto que te separa de la fuente de los ruidos y detras del\n"
                             "mismo te encuentras un pequenio ser de de piel amarilla y enormes ojos brillantes acostado debajo de un pequenio arbol.\n"
                             "Lanzas un grito ante la desconocida forma de vida el cual lo alerta de tu presencia.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "GNOMO: Ohh un viajante. No sabes ni que esta pasando aqui verdad?\n\n";
                    writeDialogs(dialog);
                    cout << "1)Ughh. Que cosa eres?, te vez asqueroso..." << endl;
                    cout << "2)Yo soy el que te soprende? Solo mirate?" << endl;
                    cout << "3)Que es esto? Donde estoy!" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "GNOMO: OYE NO SEAS GROSERO, SOY UNA CRIATURA LEGENDARIA Y NO PERMITIRE ESE COMPORTAMIENTO CONTRA MI!\n"; passTree = true; break;
                            case 2: dialog = "GNOMO: Pues de donde vengo nadie es tan alto y con la cara tan extrania.\n"; passTree = true; break;
                            case 3: dialog = "GNOMO: No desesperes joven viajante...\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Soy Winklipet el gnomo jardinero, disculpa mi sorpresa pero hace mucho que nadie pasa por aqui,\n"
                             "pense que nadie entraria nunca mas al laberinto por lo que me rendi y deje de cortar las hojas de los arboles y arbustos.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Despues de eso me quede dormido mas tiempo de lo que yo pretendia, tanto que cuando desperte no logre orientarme y ahora estoy aqui perdido muriendome de hambre.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El duende hace una cara de emocion y continua...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Hagamos un trato, si me consigues una manzana del arbol rejuvenecedor de aqui cerca,\n"
                             "algunos secretos que este laberinto tiene saldran de mi boca pero por ahora, LARGATE!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Sin tener alguna otra alternativa, decides ayudar a WINKLIPET.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                    tutorial = mid;
                }
                else if(!maze[x][y].getfirstTime() && tutorial == mid && player->inventario.searchObjMision("Manzana")){

                    int option = 0;
                    bool passTree = false;

                    string dialog = "Regresas a la habitacion con el gnomo, con mucho esfuerzo el pequenio ser se arrastra hacia ti con desesperacion en sus ojos.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Por que tardaste tanto?! Estuve a punto de morir aqui.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Le ofreces la manzana al gnomo y este te la arrebata con locura de la mano y la devora de un solo mordisco,\n"
                             "despues de unos segundos el gnomo se pone de un color palido y a continuacion su piel comienza a descarapelarse de su cara poco a poco.\n\n";
                    writeDialogs(dialog);
                    cout << "1)QUE ESTA PASANDO!" << endl;
                    cout << "2)Ughh que asco.... alejate de mi." << endl;
                    cout << "3)Que puedo hacer por ayudarte? Eso se ve muy mal..." << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "WINKLIPET: Es momento de despedirce de este mal.\n"; passTree = true; break;
                            case 2: dialog = "WINKLIPET: No me desconcentres...\n"; passTree = true; break;
                            case 3: dialog = "WINKLIPET: Silencio, que no me puedo centrar en lo que estoy haciendo.\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Despues de unos segundos toda la piel de WINKLIPET se cae dejando ver una nueva por debajo...\nunos momentos despues el gnomo se levanta con una cara llena de vida.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Muchas gracias viajero realmente, me fuiste de mucha utilidad, sin ti solo el REY CARMESI se hubiese apiadado de mi alma.\n\n";
                    writeDialogs(dialog);
                    cout << "1)El REY CARMESI? Quien es el?" << endl;
                    cout << "2)Todavia hay reyes en este mundo...?." << endl;
                    cout << "3)REY CARMESI... suena a una banda de rock extrania." << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "WINKLIPET: No conoces al REY CARMESI!?\n"; passTree = true; break;
                            case 2: dialog = "WINKLIPET: El es el Rey de reyes.\n"; passTree = true; break;
                            case 3: dialog = "WINKLIPET: NO TE ATREVAS A INSULTAR A NUESTRA MAJESTAD!\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: El REY CARMESI es el soberano del reino de Doorbell, hace mucho tiempo los enanos,\ngnomos, artesanos y los caballeros de obsidiana viviamos en constantes guerras y disputas,\n"
                             "pero un dia el REY CARMESI llego y unio a nuestros pueblos bajo el amor y la paz...,\nel es el que construyo este laberinto el cual tenia el proposito de purgar el alma de los impuros,\n"
                             "pero un dia los viajeros dejaron de llegar e este laberinto por lo que el rey perdio el interes,\npero todos los que vivimos aqui nos rehusamos a irnos ya que este es nuestro hogar.\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Yo controlo la fauna de este lugar y se que hay una puerta que esta obstruida por la naturaleza, permiteme abrirla para ti.\n\n"
                             "El gnomo se va rapidamente de tu lado y en un instante regresa...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Listo! El camino obstruido por las enrredaderas ahora esta abierto como muestra de mi agradecimiento!.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Elimando objeto de mision Manzana del inventario.\n";
                    player->inventario.delObjMision("Manzana");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Espera! todavia no te vayas...\nSi bien ahora sabes del heroismo de nuestra majestad, lo que te he dicho no te ayudara a sobreponerte a lo que viene.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Esto... como era?, dame un momento... Debeia estar por aqui en alguna parte.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El gnomo saca una pequenio libro de un hoyo en el suelo.\nWINKLIPET: Ah! Aqui esta, mhm. Presta atencion, que no lo voy a repetir.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: El laberinto esta conformado por 25 cuartos, formando un cuadrado 5x5. Cada cuarto tiene grabadas sus coordenadas en la pared,\n"
                             "y cuenta con un cofre, este puede contener una pocion, un escudo, o una devastadora lluvia de flechas que te quitaran una vida.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Al inicio de tu aventura cuentas con 3 vidas y 3 cargas de escudo por defecto,\n"
                             "si pierdes todas tus vidas, habras fracasado la prueba del gran REY CARMESI\n"
                             "y moriras. Si tienes escudo, este tomara el danio en tu lugar.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Todos los objetos que obtengas se guardaran en tu inventario. Cada objeto se guarda con su codigo runico correspondiente.\n"
                             "Dentro de este puedes consumir y usar los escudos y pociones, para hacerlo, necesitaras el codigo runico del objeto.\n"
                             "Este ultimo lo puedes consultar en el mismo inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: De ahora en adelante, hay una pequenia probabilidad de que te encuentres con enemigos en los cuartos sin sucesos importantes....\n"
                             "Agg... Las paginas de esto son inentendibles... En fin pasare a lo siguiente.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: En las conversaciones, pueden saltar pequenias decisiones de dialogo. Ten cuidado al elegir, no solo cambiara la respuesta de con\n"
                             "quien hablas, si das una buena impresion, te pueden otorgar objetos que seran de ayuda en tu prueba.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Para orientarte al viajar entre cuartos, siempre miraras hacia el Norte a la hora de elegir a donde ir.\n"
                             "No todos lo cuartos tienen los 4 caminos posibles, algunos estaran bloqueados o simplemente son inexistentes.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");


                    dialog = "WINKLIPET: Explora el laberinto, adentrate en el, conoce a mas gente y resuelve todo lo que te eche en cara.\n"
                             "Solo asi podras superar la prueba de su majestad del gran REY CARMESI...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "WINKLIPET: Que libro mas raro...en fin eso es todo.\nComo sea, suerte en tu prueba viajero!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[1][0].setWays(false, true, true, false);
                    tutorial = mid2;
                }

            }else if(x == 1 && y == 0){ // Cuarto del árbol

                if(maze[x][y].getfirstTime() && tutorial == intro){
                    string dialog = "Entras al cuarto y un arbol dorado resplandece frente a ti, de sus ramas cuelgan manzanas doradas.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "La puerta de la derecha esta obstruida con una enredadera de pinchos.\nLa de abajo por pilares de obsidiana...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
                else if(maze[x][y].getfirstTime() && tutorial == mid){
                    string dialog = "Entras al cuarto y un arbol dorado resplandece frente a ti...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El arbol...Debe ser el arbol que menciono el gnomo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "La puerta de la derecha esta obstruida con una enredadera de pinchos.\nLa de abajo por pilares de obsidiana.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te acercas al arbol y tomas una de sus manzanas en la cual puedes ver tu reflejo gracias a su brillante superficie...\nAgregado objeto de mision Manzana al inventario.\n";
                    player->inventario.addObjMision("Manzana", "Manzana que te pidio WINKLIPET.");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
                else if(!maze[x][y].getfirstTime() && tutorial == mid && !player->inventario.searchObjMision("Manzana")){

                    string dialog = "El arbol...Debe ser el arbol que menciono el gnomo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te acercas al arbol y tomas una de sus manzanas en la cual puedes ver tu reflejo gracias a su brillante superficie...\nAgregado objeto de mision Manzana al inventario.\n";
                    player->inventario.addObjMision("Manzana", "Manzana que te pidio el WINKLIPET.");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
                else if(!maze[x][y].getfirstTime() && tutorial == finall){

                    string dialog = "La puerta que antes estaba sellada por troncos de obsidiana esta ahora abierta.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }

            }else if(x == 1 && y == 1){

                if(maze[x][y].getfirstTime()){

                    string dialog = "Las lianas que cubrian la entrada a este cuarto han desaparecido, entras a la habitacion y te encuentras sumergido en una total oscuridad.\n"
                                    "Lo unico que logras escuchar es como algo se desliza en lo profundo de la habitacion, con nerviosismo sacas la linterna de aceite y la prendes con rapides.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Parece que no era nada...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "De todos modos, buscas en tu mochila algo que te pueda ayudar en caso de emergencia, pero solo encuentras los tres frascos que habia al comienzo de tu viaje,\n"
                             "dentro de los cuales hay piedras de diferente color, unas son de color rojo, unas de color azul y otras de color morado, en uno de los frascos hay una nota...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    cout << "---COMBATES ELEMENTALES---" << endl << endl;
                    dialog = "\"Los frascos contienen piedras elementales que sirven para tus batallas, cada piedra provoca un ataque de un diferente elemento:\n"
                             "-Rojas (fuego)\n"
                             "-Azules (agua)\n"
                             "-Moradas (hielo)\n"
                             "Para ganar una batalla deberas elegir un tipo de piedra con la que atacaras a tu enemigo, si tu ataque elemental es dominante sobre el del enemigo derrotaras a tu enemigo,\n"
                             "de lo contrario perderas una vida.\"\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El circulo de dominios sobre cada ataque es: \n"
                             "\t\t\t\t\tLos ataques de Agua -> Vencen a los ataques de Fuego\n"
                             "\t\t\t\t\tLos ataques de Fuego -> Vencen a los ataques de Hielo\n"
                             "\t\t\t\t\tLos ataques de Hielo -> Vencen a los ataques de Agua\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    writeDialogs("......\n");
                    system("pause");
                    system("cls");

                    dialog = "Una figura amorfa se levanta frente a ti, parece un esqueleto humano el cual esta cubierto de una sustancia oscura y espesa, el ser genera sonidos guturales.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te quedas mudo ante ese escenario y retrocedes para salir por donde viniste, pero sin querer pisas una rama que genera un sonido que llama la atencion de la criatura,\n"
                             "la cual se voltea y con sus cuencas llenas de liquido oscuro te dirije una profunda mirada, la criatura hace un grito que te eriza todos los pelos del cuerpo y se acerca con rapidez hacia ti...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Intentas correr pero la criatura es muy rapida y te bloquea la salida con su cuerpo, despues abre su boca y genera una llamarada que pasa muy cerca de ti...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Con la desesperacion se te cae una de las piedras rojas la cual genera una llamarada que detiene el grito de fuego del esqueleto....\nLas piedras...!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "Despues de la batalla, tu enemigo queda reducido a polvo en el suelo, entre sus cenizas deja una llave de color plateado con un diamante grabado en el agarre la cual tomas,\n"
                             "en la pared del cuarto hay algo escrito por lo que te acercas con la linterna en la mano para leer lo que hay en el muro.\n"
                             "\"Que tu camino no termine en la desesperanza o de la contrario tu alma se transformara en un ente vacio, te volveras un Transfugo\"...\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.addObjMision("Llave de plata", "Llave recogida de tu primer batalla con un Transfugo");
                    dialog = "Llave de plata aniadida a tu inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog =  player->getName() + ": Transfugo, esa cosa era un Transfugo...\n"
                             "Si no salgo de aqui, pronto terminare como una de esas cosas, mas vale que me de prisa.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                }

            }else if(x == 1 && y == 2){

                if(maze[x][y].getfirstTime()){

                    string dialog = "Entras a un cuarto que tiene un tragaluz en el techo, en el centro hay un cofre plateado con un diamante grabado en la parte superior,\n"
                                    "te acercas al cofre y te das cuenta que tiene unas palabras escritas las cuales dicen....\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "\"Las recompenzas exigen sacrificios\"\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Decides probar la llave recien adquirida en el cofre...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    int prob = 0 + (rand() % (99+1));

                    if(prob <= 14){
                        dialog = "Un escudo de un metal extranio se encuentra dentro...\nVibra con una energia reconfortante.\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");

                        dialog = "Tu capacidad de cargas de escudo ha aumentado en uno.\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");
                        player->inventario.delObjMision("Llave de plata");
                        player->increaseMaxShield();
                    }
                    else{
                        dialog = "Una lluvia de flechas sale disparada hacia ti.\nPierdes una vida.\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");
                        player->inventario.delObjMision("Llave de plata");
                        player->takeDamage();
                    }

                    maze[x][y].setfirstTime(false);
                }
            }else if(x == 0 && y == 2){

                if(maze[x][y].getfirstTime()){

                    string dialog = "Entras por un hueco a una nueva habitacion, pero esta es algo peculiar, esta llena de enormes bloques de obsidiana creciendo desde el suelo\n"
                                    "los cuales brillan gracias a un tragaluz que deja entrar los rayos del sol.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Al fondo del cuarto escuchas gritos de algunos Transfugos y quejidos de una persona, guias la vista hasta el origen del alboroto y puedes visualizar el ruidoso evento.\n"
                             "Un hombre de piel morena alto y fornido esta peleando con un hacha de cristal oscuro contra tres Transfugos que lo tienen rodeado.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te acercas con rapidez hasta que el hombre logra verte.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    int option = 0;
                    bool passTree = false;

                    dialog = "DESCONOCIDO: TU VIAJERO, VEN Y AYUDAME TE LO SUPLICO!\n\n";
                    writeDialogs(dialog);
                    cout << "1)Yo? Pero si tu estas en mejor forma para derrotar a esos Transfugos!" << endl;
                    cout << "2)No lo se..., Como me beneficiaria ayudarte?" << endl;
                    cout << "3)Claro, pero... quien eres?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "DESCONOCIDO: NO SEAS COBARDE Y AYUDAME!\n"; passTree = true; break;
                            case 2: dialog = "DESCONOCIDO: Tan avaro eres? Enserio? Ahora que estoy en peligro de muerte?!\n"; passTree = true; break;
                            case 3: dialog = "DESCONOCIDO: Vaya..., creo que no es el mejor momento para presentarme pero...\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Soy VILTRO, el leniador de obsidiana.\nSi me ayudas prometo que te regresare el favor!";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te apiadas del leniador y le ofreces tu ayuda.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "Un segundo transfugo se abalanza sobre tu ti...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "Terminas con el segundo transfugo y vez como el leniador destruye el craneo de la ultima bestia, volviendose polvo al instante.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");


                    dialog =  "El hombre se voltea y lo obserbas con mas detenimiento...\n"
                              "En su cara hay una cicatriz que atravieza su ceja, tambien le falta un pedazo de oreja izquierda.\n"
                              "Tiene una poblada barba negra que casi borra por completo su boca.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Tu batalla fue impresionante!\nAhora permiteme introducirme por completo..., como te dije soy VILTRO el leniador de este bosque de obsidiana.\n\n";
                    writeDialogs(dialog);
                    cout << "1)Creo que para ser un leniador necesitas arboles y aqui no veo ninguno..." << endl;
                    cout << "2)Es una labor algo infructifera en este lugar no crees?" << endl;
                    cout << "3)Vaya, y... En que bosque?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "VILTRO: En realidad no son los mismos tipos de arboles que tu conoces...\n"; passTree = true; break;
                            case 2: dialog = "VILTRO: No soy ese tipo de leniador...\n"; passTree = true; break;
                            case 3: dialog = "VILTRO: En este, aunque tu no lo creas.\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Este lugar es el bosque de los arboles de obsidiana, veras yo con mis companieros durante el apogeo de este lugar nos dedicabamos a proveer\n"
                             "de obsidiana a todo Doorbell, es un mineral que era muy utilizado en edificios y construcciones, pero cuando los viajeros dejaron de llegar aqui,\n"
                             "el rey pidio evacuar el laberinto, pero yo... no pude... me rehuse a abandonar mi hogar.\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO se inclina para sentarse sobre una piedra y deja ver un tatuaje de un lobo negro en la parte trasera de su cuello.\n\n";
                    writeDialogs(dialog);
                    cout << "1)Esta genial tu tatuaje en el cuello!" << endl;
                    cout << "2)Un tatuaje? Fuiste un motociclista o algo asi?" << endl;
                    cout << "3)Que es eso en tu cuello?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "VILTRO: Que? Mi marca? Vaya hace mucho que no recordaba que la tenia, la soledad no hace mucho por ti...\n"; passTree = true; break;
                            case 2: dialog = "VILTRO: Moto..queee? Que es eso? Algun hechicero famoso?\n"; passTree = true; break;
                            case 3: dialog = "VILTRO: Oh vaya hace mucho que no recordaba que la tenia...\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Veras yo solia pertenecer a los caballeros de Obsidiana, durante muchos anios participe en guerras por el control de Doorbell pero cuando llego el\n"
                             "REY CARMESI, nos mostro que estabamos en un circulo vicioso de violencia, por lo que bajamos nuestras armas y nos dedicamos a otras cosas...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Muchos se quitaron su marca de guerrero que nos identificaba, pero yo me la deje para recordar que la guerra solo hace danio a todos...\n"
                             "Es ironico que haya olvidado que la tenia. No crees? jajaja...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Veo que quieres salir de este lugar, en una habitacion por donde viniste selle un camino con troncos de obsidiana.\n"
                             "No te preocupes ahora mismo los quitare para que puedas continuar con tu viaje.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO se retira por unos minutos y despues de esperarlo regresa con algunos troncos de cristal de obsidiana en sus brazos.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VILTRO: Listo! Te deseo un buen viaje, esperemos que en algun momento nuestros caminos se topen de nuevo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[1][0].setWays(false, true, true, true);
                    maze[x][y].setfirstTime(false);

                    tutorial = finall;
                }

            }else if(x == 2 && y == 0){

                if(maze[x][y].getfirstTime() && quest[0] == intro){ // CAIDA DEL PUENTE

                    string dialog = "Despues de salir por la puerta antes bloqueada por troncos de obsidiana, encuentras un puente alumbrado por dos cristales azules,\n"
                                    "lo cruzas con lentitud para evitar que el movimiento te haga caer.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog  = "De pronto escuchas sonidos de algo hueco estampandose contra las paredes del acantilado por el que pasa el puente...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Con la linterna alumbras hacia abajo y te horrorizas al ver lo que se aproxima hacia ti...\n"
                             "Un grupo de Transfugos estan escalando el acantilado con el fin de alcanzarte.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");


                    dialog = "Con algo de miedo analizas la situacion que te rodea...\n"
                             "Del en el fondo del acantilado hay un rio que tiene a todos los Transfugos mojados.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Sin tambalear abres tu mochila y sacas el frasco con piedras moradas, tomas un puniado de ellas y las lanzas hacia el rio."
                             "\nLas piedras de hielo caen sobre el agua haciendo algo de burbujas y congelando todo el rio a su paso, cada uno de los Transfugos\n"
                             "quedan congelados al instante, al estar mojados por el agua del rio.\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Un ultimo transfugo lanza una llamarada que quema las lianas del extremo del puente, con la rapidez de un rayo corres hacia el otro extremo del puente,\n"
                             "y cuando este se derrumba saltas hacia el acantilado, alcanzando a sostenerte por un brazo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Uff eso estuvo muy cerca...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Logras subir todo tu cuerpo en tierra firme y te volteas a ver como ya no hay puente de regreso.\n" +
                             player->getName() + ": Parece que ya no hay vuelta atras...";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Volteas y para tu sorpresa un ultimo Transfugo se abalanza hacia ti, con un salto lo ezquivas y sacas de tu bolsa tus frascos elementales.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "Despues de tan agitada serie de eventos te sientas a pensar tu siguiente paso...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                    maze[2][0].setWays(false, true, false, false);
                }
                else if(!maze[x][y].getfirstTime() && quest[0] == intro){
                    string dialog = "Estas en el cuarto con el puente cortado.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }
            }
            else if(x == 2 && y == 1){ // RELAX

                if(maze[x][y].getfirstTime()){

                    string dialog = "Despues de lo del puente entras con desconfianza hacia la segunda habitacion esperando enfrentarte con algun enemigo.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Por el camino hacia abajo hay una diminuta puerta por la que apenas y cabe tu mano, no es posible pasar por ahi en este momento...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Despues de mucho tiempo encontraste una habitacion en calma...\n"
                             "Luego de tan agitada serie de eventos te sientas a pensar tu siguiente paso.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                }
                else if(!maze[x][y].getfirstTime() && player->inventario.searchObjMision("Pocion Diminutiva")){

                    string dialog = "Con la pocion que me dio CIEDA, puedo pasar por la puertita de abajo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }
            }
            else if(x == 2 && y == 2){ //ESFINGE

                if(maze[x][y].getfirstTime() && quest[0] == intro){

                    string dialog = "Entras a la habitacion y te encuentras un cuarto con una pintura en su pared y una enorme escultura de una ESFINGE.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Que extrania criatura...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te acercas a ver la pintura y en la misma se ve un Buho con una corona Roja en la cabeza, de sus ojos escurren lagrimas de sangre que se ve que alguien aniadio hace no mucho.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "En el pie de la pintura hay una leyenda que dice \"El REY CARMESI, el unificador de todos los pueblos\"...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");


                    maze[x][y].setfirstTime(false);
                }
                else if(!maze[x][y].getfirstTime() && quest[0] == mid && !player->inventario.searchObjMision("Sangre de Esfinge")){ // HACIENDO MISION COSTURERA (PENDIENTE)

                    string dialog = "Entras a la habitacion y encuentras la estatua de la ESFINGE frente a ti.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Donde diablos voy a encontrar a una ESFINGE?...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te sientas bajo la estatua y exhalas mientras dices...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Desearia que realmente estuvieras aqui...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Una voz tenebrosa y suave como un susurro se escucha en el aire...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "VOZ DESCONOCIDA: Ten cuidado con lo que deseasss.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "La estatua detras de ti comienza a temblar y sus ojos brillan de manera aterradora.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ESFINGE: YO SOY LA ESFINGE DE LOS DESEOS!\n"
                             "Puedo otorgarte lo que desees, siempre y cuando aciertes el acertijo que ante ti presente!\n\n";
                    writeDialogs(dialog);

                    int option = 0;
                    bool passTree = false;

                    cout << "1)AHHHHH! NO ME COMAS!" << endl;
                    cout << "2)Tu eres la ESFINGE?!..." << endl;
                    cout << "3)Vaya... eres muy alta..." << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "ESFINGE: No lo hare siempre y cuando sigas las reglas.\n"; passTree = true; break;
                            case 2: dialog = "ESFINGE: Acertaste mi invocador.\n"; passTree = true; break;
                            case 3: dialog = "ESFINGE: Mi tamanio es el que tu me diste.\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ESFINGE: Como ya lo mencione yo soy la ESFINGE y tu me invocaste con el proposito de que te cumpla un deseo accesible a mi.\n"
                             "Deseas un poco de mi sangre no es cierto? Pues adivina mi acertijo y te otorgare un poco de ella.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ESFINGE: Si fallas o te contestas algo que no, te hare danio...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    int randomQuiz = 0 + (rand() % (2+1));
                    int answer = 0;
                    bool right = false;

                    dialog = "ESFINGE: PREPARATE...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    do{
                        switch (randomQuiz){

                            case 0:
                                dialog = "Si te lo hiciera, te desgarraria con mis zarpas, pero eso solo ocurrira si no lo captas. Y no es facil la respuesta de esta adivinanza,\n"
                                         "porque esta lejana, en tierras de bonanza, donde empieza la region de las montanias de arena y acaba la de los toros, la sangre, el mar y la verbena.\n"
                                         "Y ahora contesta, tu, que has venido a jugar: ¿a que animal no te gustaria besar?\n\n";
                                writeDialogs(dialog);

                                cout << "1)La arania" << endl;
                                cout << "2)El escorpion" << endl;
                                cout << "3)La serpiente" << endl;
                                cout << "4)La rana" << endl << endl;
                                cout << "Respondes: ";
                                cin >> answer;

                                if(answer == 1){
                                    system("cls");
                                    cout << "ESFINGE: LA ARANIA! CORRECTO!" << endl;
                                    system("pause");
                                    system("cls");
                                    right = true;
                                }
                                else{
                                    system("cls");
                                    cout << "ESFINGE: INCORRECTO!" << endl;
                                    cout << "Pierdes una vida." << endl;
                                    system("pause");
                                    system("cls");
                                    player->takeDamage();
                                    cout << "ESFINGE: Repetire el acertijo..." << endl;
                                    system("pause");
                                    system("cls");
                                }
                                break;

                            case 1:
                                dialog = "Si me tienes, quieres compartirme. Si me compartes, no me tienes. Que soy?\n\n";
                                writeDialogs(dialog);

                                cout << "1)Deseo" << endl;
                                cout << "2)Puridad" << endl;
                                cout << "3)Pasion" << endl;
                                cout << "4)Desesperacion" << endl << endl;
                                cout << "Respondes: ";
                                cin >> answer;

                                if(answer == 2){
                                    system("cls");
                                    cout << "ESFINGE: PURIDAD! CORRECTO!" << endl;
                                    system("pause");
                                    system("cls");
                                    right = true;
                                }
                                else{
                                    system("cls");
                                    cout << "ESFINGE: INCORRECTO!" << endl;
                                    cout << "Pierdes una vida." << endl;
                                    system("pause");
                                    system("cls");
                                    player->takeDamage();
                                    cout << "ESFINGE: Repetire el acertijo..." << endl;
                                    system("pause");
                                    system("cls");
                                }
                                break;

                            case 2:
                                dialog = "Ponme de lado y soy todo. Cortame por la mitad y no soy nada. Que soy?\n\n";
                                writeDialogs(dialog);

                                cout << "1)El 0" << endl;
                                cout << "2)La letra B" << endl;
                                cout << "3)El 8" << endl;
                                cout << "4)El 9" << endl << endl;
                                cout << "Respondes: ";
                                cin >> answer;

                                if(answer == 3){
                                    system("cls");
                                    cout << "ESFINGE: EL 8! CORRECTO!" << endl;
                                    system("pause");
                                    system("cls");
                                    right = true;
                                }
                                else{
                                    system("cls");
                                    cout << "ESFINGE: INCORRECTO!" << endl;
                                    cout << "Pierdes una vida." << endl;
                                    system("pause");
                                    system("cls");
                                    player->takeDamage();
                                    cout << "ESFINGE: Repetire el acertijo..." << endl;
                                    system("pause");
                                    system("cls");
                                }
                                break;
                        }
                    }while(!right);

                    dialog = "Despues de acertar su acertijo, la ESFINGE levanta su mano y con su garra se corta la otra pata,\n"
                             "de su extremidad chorrea un liquido plateado que cae en un frasco y te la acerca con su cola.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ESFINGE: Usala con sabiduria.\nObjeto de mision Sangre de Esfinge aniadido al inventario\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->inventario.addObjMision("Sangre de Esfinge", "CIEDA menciono que la usara para cubrir una embarcacion");

                    if(player->inventario.searchObjMision("Embarcacion")){
                        quest[0] = mid2;
                    }
                }
            }
            else if(x == 2 && y == 3){ // GOTA

                if(maze[x][y].getfirstTime() && quest[0] == intro){

                    string dialog = "Dentro de la habitacion hay un candelabro azul que alumbra al cuarto y en la esquina te encuentras un Transfugo que al verte corre con desesperacion a ti...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "El Transfugo se hace polvo frente a tus ojos, entre sus cenizas encuentras un pequenio diamante en forma de gota que tomas y llevas contigo.\n"
                             "Objeto de mision Diamante de Gota aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->inventario.addObjMision("Diamante de Gota", "Tendra algun valor?");

                    dialog = "El cuarto de abajo esta inundado de lava, parece imposible pasar por ahi...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
                else if(!maze[x][y].getfirstTime() && quest[0] == mid){

                    string dialog = "El cuarto de abajo esta inundado de lava, necesito la sangre y una embarcacion...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }
                else if(!maze[x][y].getfirstTime() && quest[0] == mid2 && player->inventario.searchObjMision("Remaches Magicos") && player->inventario.searchObjMision("Embarcacion")
                        && player->inventario.searchObjMision("Sangre de Esfinge")){

                    string dialog = "Tienes todos los objetos: Con los remaches reparas la \"Embarcacion\" y con la Sangre de Esfinje la pintas.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.delObjMision("Remaches Magicos"); player->inventario.delObjMision("Embarcacion");
                    player->inventario.delObjMision("Sangre de Esfinge");

                    dialog = "Ahora puede pasar por el cuarto con lava\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Objeto de mision Embarcacion aprueba de lava aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->inventario.addObjMision("Embarcacion aprueba de lava", "Con esto puedo pasar el cuarto con lava");

                    maze[x][y].setWays(true, false, true, true);
                }

            }
            else if(x == 1 && y == 3){ // CIEDA

                if(maze[x][y].getfirstTime()){

                    string dialog = "Entras a un cuarto lleno de artilugios de costura, miles de estambres se encuentran en el suelo, agujas de tejer hay centenares esparcidas por toda la habitacion de color marron.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "En el fondo te encuentras a una mujer con un chaleco azul, una blusa roja y una falda larga de color blanco, esta sentada en un estambre de tamanio gigante llorando.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DESCONOCIDA: *sniff* \t*hummmm*\n"
                             "Solloza la mujer...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te acercas con lentitud esperando lo peor, la mujer se da cuenta de tu presencia y con tristeza te dice...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DESCONOCIDA: Un viajero...\n\n"
                             "Dice mientras se seca los mocos y se limpia los ojos hinchados de tanto llorar.\n\n";
                    writeDialogs(dialog);

                    int option = 0;
                    bool passTree = false;

                    cout << "1)Estas bien? Por que lloras?" << endl;
                    cout << "2)Meh... Es esto una trampa para matarme o algo?" << endl;
                    cout << "3)Ughhh, limpiate la cara antes de dirigirme la palabra..." << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "DESCONOCIDA: Ohhhh, esta es mi triste situacion, mi maldicion *sniff*\nTe rezo REY CARMESI que me salves de esta situacion...\n"; passTree = true; break;
                            case 2: dialog = "DESCONOCIDA: Yo no represento un peligro para ti, viajero... *sniff*, de hecho no se nada sobre pelear...\n"; passTree = true; break;
                            case 3: dialog = "DESCONOCIDA: Oh... *sniff* Me disculpo por que me veas en esta situacion....\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Me llamo CIEDA la costurera, o bueno.... lo solia ser antes de que fuera despojada de mi estudio de costura, ahora soy solo CIEDA... *sniff*\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Despojada... em, de que?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Mi estudio de costura..., mi templo esta lleno de miles de hilos de la mas fina seda y telas de la mas suave textura, de hecho cuando el REY CARMESI nos pidio evacuar\n"
                             "este laberinto, yo me negue con la excusa de que estaba enamorada de tan hermoso lugar y no podia irme...\n\n";
                    writeDialogs(dialog);

                    cout << "1)Pero... Como llegaste aqui?" << endl;
                    cout << "2)Pues si se ve igual de destruido que este lugar... no creo que fuera tan bonito desde el principio." << endl;
                    cout << "3)Y... Entonces que haces aqui?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "CIEDA: Es una complicada historia... pero... creo te la puedo resumir.\n"; passTree = true; break;
                            case 2: dialog = "CIEDA: NO SEAS GROSERO!... Perdon... Hablo enserio, mi santuario de costura es hermoso.\n"; passTree = true; break;
                            case 3: dialog = "CIEDA: Ese maldito ser me arrebato lo que tenia...\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Veras, cuando casi todos se fueron del laberinto, cerca de aqui un huevo de dragon se colo al laberinto y de el eclociono un ser lleno de pura maldad...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: No sabemos su nombre real..., o si tiene uno, pero todos lo conocemos con el nombre de \"Duo\", ese maldito ser se apropio de una habitacion que daba acceso al LAGO DE LAS LAGRIMAS,\n"
                             "el cual tiene un agua magica que es la unica cosa que existe para derrotarlo.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");


                    dialog = "CEIDA: Despues de anios de vivir, ahi crecio demasiado para caber en ese cuarto por lo que, sabiendo que mi santuario de costura es la habitacion mas grande del laberinto,\n"
                             "me expulso a pura llamarada, y para evitar que alguien intentara llegar al cuarto del LAGO DE LAS MIL LAGRIMAS, inundo de lava el cuarto que da acceso al lago y ahora\n"
                             "no hay forma de correrlo de mi santuario...\n\n";
                    writeDialogs(dialog);

                    cout << "1)Te gusta mucho coser por lo que veo..." << endl;
                    cout << "2)Pero... que mas da, solo busca otro cuarto en donde coser." << endl;
                    cout << "3)Por que no buscas otra aficion?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "CIEDA: Es todo lo que siempre he conocido...\n"; passTree = true; break;
                            case 2: dialog = "CIEDA: Me gustaria pero... en ese cuarto deje mis herramientas.\n"; passTree = true; break;
                            case 3: dialog = "CIEDA: No lo entiendes verdad? *sniff* No puedo solo \"Dejar de coser\".\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Veras, yo pertenezco a la raza de los artesanos, durante siglos trabajamos bajo el yugo de otra raza, pero con la llegada del REY CARMESI,\n"
                             "nos libero y nos ofrecio crear, bordar, coser y diseniar lo que nosotras quisieramos sin obedecer a nada ni nadie...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Pero ahora no puedo hacer lo que siempre he amado por estar controlada por otro ser. Ironico...no lo crees? *sniff*\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": No es posible derrotar a ese malvado ser de alguna otra forma?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: No..., solo el agua de el LAGO DE LAS MIL LAGRIMAS es capaz de derrotarlo, y su acceso esta lleno de lava.\n"
                             "La unica cosa que es inmune a tales temperaturas es la sangre de ESFINGE y encarar a esa bestia es... una locura.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Dices que si logro obtener su sangre y me la tomo me volvere invensible a la lava?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Por todos los estambres! NO! La sangre de ESFINGE es sumamante toxica con todo lo vivo.\n"
                             "La unica opcion que tienes seria pintar una embarcacion con la sangre y se volvera inmune a la lava,\n"
                             "creo que por aqui cerca hay un mercader el cual es propietario de toda clase de articulos,\n"
                             "tal vez tenga alguna embarcacion que puedas pintar con la sangre de ESFINGE...\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Se que esta mision suena como un suicidio, pero si logras ayudarme te otorgare esto.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA saca de una de sus bolsas un frasco con un liquido de color verde brillante...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Esta es la ultima pocion diminutiva que me queda..., si la tomas seras capaz de pasar por la puerta que te conducira a tu libertad.\n\n";
                    writeDialogs(dialog);

                    cout << "1)Es un trato CIEDA..., hare lo posible por ayudarte." << endl;
                    cout << "2)Sabes...solia ser programador, mi jefe era terrible..., pero yo no, asi que tendre misericordia, y te ayudare." << endl;
                    cout << "3)Acepto tu reto." << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    bool rightAnswer = false;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "CIEDA: Muchisimas gracias...\n"; passTree = true; break;
                            case 2:  passTree = true; rightAnswer = true; break;
                            case 3: dialog = "CIEDA: Ese es el espiritu viajero.\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");

                    if(rightAnswer){

                        dialog = "CIEDA: Progra..que?!...jajaja\nVeo que tu humor es oro jaja *sniff*..., nunca pierdas esa cualidad.\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");

                        writeDialogs("......\n");
                        system("pause");
                        system("cls");

                        dialog = "CIEDA: Como te llamas?\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");

                        dialog = player->getName() + ": " + player->getName() + "...\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");

                        dialog = "CIEDA: " + player->getName() + "..., ten esto tambien, es un manto magico especial que confeccione alguna vez, estoy segura te ayudara en tu viaje...\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");

                        dialog = "Tu capacidad de cargas de escudo ha aumentado en uno.\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");
                        player->increaseMaxShield();

                    }else{
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");

                    }

                    dialog = "CIEDA: Te deseo suerte...\n"
                             "Puede que esta herramiente te ayude, es de las pocas cosas que logre sacar de mi santuario antes de que el dragon me corriera,\n"
                             "son unos remaches magicos los cuales se pueden usar para reparar casi cualquier cosa.\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->inventario.addObjMision("Remaches Magicos", "CIEDA aseguro que pueden reparar cualquier cosa");

                    dialog = "Objeto de mision Remaches Magicos aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Por cierto, el dragon esta en el cuarto de arriba...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                    quest[0] = mid;
                }
                else if(!maze[x][y].getfirstTime() && quest[0] == mid){
                    string dialog = "CIEDA: Veo que estas ocupado..., no te distraigo mas.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }
                else if(!maze[x][y].getfirstTime() && quest[0] == finall && !player->inventario.searchObjMision("Pocion Diminutiva")){

                    string dialog = "Entras al cuarto donde se encuentra CIEDA con algunas cortadas, pero vivo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: LO HICISTE! LO LOGRASTE! ERES TODO UN VERDADERO HEROE!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Sonries un poco hacia CIEDA, ella te regresa el gesto.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Siempre estare en deuda por tu azania, ahora puedo continuar con el trabajo que amo...\n"
                             "Como la costurera de palabra que soy te entrego lo que prometi.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.addObjMision("Pocion Diminutiva", "Pocion capaz de reducir tu tamanio dada por CIEDA");

                    dialog = "Objeto de mision Pocion Diminutiva aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: Te deseo la mejor de las suertes viajero!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[2][1].setWays(true, true, false, true);
                }

            }else if(x == 0 && y == 3){ // DRAGON

                if(maze[x][y].getfirstTime() && !player->inventario.searchObjMision("Agua de Lagrimas")){

                    string dialog = "Entras al cuarto e inmediatamente una ola de calor te golpea el rostro.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DUO: QUE ESTAS HACIENDO AQUI?!?!?! LARGATE O TE CARBONIZARE!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Sales corriendo del cuarto de inmediato...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CIEDA: TEN MAS CUIDADO! PORFAVOR!...\n"
                             "No deberias entrar ahi sin EL AGUA DE LAS MIL LAGRIMAS.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    this->x++; // Regresamos con la costurera
                }
                else if(maze[x][y].getfirstTime() && quest[0] == mid2 && player->inventario.searchObjMision("Agua de Lagrimas")){

                    string dialog = "Entras al cuarto con sigilo mientras el dragon duerme, te acercas por detras y abres el frasco que contiene el Agua de Lagrimas,\n"
                                    "el sonido despierta al dragon y este se voltea freneticamente...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DUO: Has vuelto patetico huma....\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El dragon se da cuenta de lo que tienes en la mano y su semblante cambia a uno de terror inmediatamente.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DUO: NO! BAJA ESO! NO LO HAGAS! PUEDO SER UTIL... T-TE PUEDO HABLAR DEL SECRETO DEL REY C...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Lanzas el frasco con el agua a la cara del dragon este lanza un grito de agonia y poco a poco se transforma en cristal,\n"
                             "el ser logra lanzar un doloroso ultimo grito y explota en miles de cristales...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.delObjMision("Agua de Lagrimas");
                    maze[x][y].setfirstTime(false);
                    quest[0] = finall;
                }

            }
            else if(x == 1 && y == 4){ // LLAVE+

                if(maze[x][y].getfirstTime() && quest[0] == mid){

                    string dialog = "Entras a una habitacion oscura, sacas tu linterna y te das cuenta que el candelabro que iluminaba la habitacion esta apagado.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Del fondo de la habitacion sale un Transfugo que corre desesperado hacia ti...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "El Transfugo se hace polvo frente a ti y suelta una llave plateada con un diamante incrustado en el amarre.\n"
                             "Objeto de mision Llave de plata aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->inventario.addObjMision("Llave de plata", "Debe servir para abrir uno de esos cofres legendarios...");

                    maze[x][y].setfirstTime(false);
                }

            }
            else if( x == 0 && y == 4){ //VIDA+

                if(maze[x][y].getfirstTime() && player->inventario.searchObjMision("Llave de plata")){

                    string dialog = "Entras a la habitacion y te encuentras con un cofre plateado con grabado.\n"
                                    "Con la llave plateada de tu mochila abres el cofre.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Es una pocion, pero no se parece a las demas, brilla de una manera reconfortante.\n"
                             "Decides beberla...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Tu vida maxima ha aumentado en uno.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->increaseMaxLife();

                    player->inventario.delObjMision("Llave de plata");
                    maze[x][y].setfirstTime(false);

                }
            }
            else if(x == 2 && y == 4){

                if(maze[x][y].getfirstTime() && quest[0] == mid && player->inventario.searchObjMision("Diamante de Gota")){

                    string dialog = "Entras a la habitacion por una puerta de cristal que tiene grabada la frase \"El comercio beneficia a los correctos\".\n"
                                    "Abres la puerta y una lluvia de polvo cae sobre ti.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Cof.. Coff..\n"
                                                 "Estornudas y toces con fuerza...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "En el fondo una figura se levanta freneticamente alertado por tu presencia.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DESCONOCIDO: Alejate asqueroso Transfugo o te volvere polvo! AHHHHHHHH!\n\n"
                             "El pequenio ser enciende un candelabro y logras observarlo por completo.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El hombre que lanza el grito tiene una barba blanca y un pelo desalineado, pero su estatura no sobrepasa el metro, en su mano sostiene una espada muy vieja.\n"
                             "La pequenia persona se da cuenta que no eres un Transfugo y deja de gritar\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DESCONOCIDO: Oh.. ohh! Por el REY CARMESI! Eres un viajero!\n\n"
                             "El pequenio ser cambia su semblante por completo a uno de emocion y baja de la mesa en donde estaba parado.\n"
                             "Al hacerlo te das cuenta que apenas y te llega a la cintura...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "DESCONOCIDO: Hace siglos que no veo un viajero por estos rumbos...\n\n";
                    writeDialogs(dialog);

                    int option = 0;
                    bool passTree = false;

                    cout << "1)Que eres? Un leniador de bonsais de obsidiana? jajaja" << endl;
                    cout << "2)Quien eres tu?" << endl;
                    cout << "3)Eres el Mercader...?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "DESCONOCIDO: Provocame y cortare el cuello!\nDigo...\n"; passTree = true; break;
                            case 2: dialog = "DESCONOCIDO: Oh vaya perdona mis modales, permiteme presentarme.\n"; passTree = true; break;
                            case 3: dialog = "DESCONOCIDO: Eso es correcto, dejame introducirme.\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Soy ICICLES el enano mercader, me encargo de proveer a los viajeros de objetos que necesiten, claro..., siempre y cuando puedan otorgar algo a cambio...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El enano alza las manos para dar un efecto de impresion, pero solo logra levantar una nube de polvo a su alrededor.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Pero como te puedes dar cuenta hace mucho que no entro en negocios con nadie *cof* *cof*.\n"
                             "Dime viajero... Hay algo aqui que te interese para hacer un trueque?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Con la mirada examinas la tienda y en un rincon polvoriento encuentras una pequenia lancha rota en la que apenas y podria entrar un ninio.\n\n";
                    writeDialogs(dialog);

                    cout << "1)Que precio tiene este cachibache?" << endl;
                    cout << "2)Vaya este barquito se ve interesante..." << endl;
                    cout << "3)Que es esto?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "ICICLES: Cachibache?!\n"; passTree = true; break;
                            case 2: dialog = "ICICLES: No es un barco, ignorante!\n"; passTree = true; break;
                            case 3: dialog = "ICICLES: Vaya, tienes buen ojo...\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Esta es una lancha de madera de arbol de obsidiana, tiene unos pequeniiiiiitos rayones pero es completamente funcional.... \n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Creo...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Que puedes ofrecerme por ella?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Primero le ofreces un puniado de piedras elementales pero el frunce el cenio y dice...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Esas cosas solo le funcionan al portador original asi que olvidalo.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Mientras vacias tu mochila el enano ve el diamante en forma de gota y sus ojos se vuelven enormes.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Una Lagrima de Diosa! De donde sacaste eso!?\n\n";
                    writeDialogs(dialog);

                    cout << "1)Que esta baratij..... digo claro es un diamante muuuy valioso..." << endl;
                    cout << "2)Estas dispuesto a hablar de negocios?" << endl;
                    cout << "3)Lo quieres... Realmente lo quieres?" << endl << endl;
                    cout << "Respondes: ";
                    cin >> option;

                    while(!passTree){
                        switch (option) {
                            case 1: dialog = "ICICLES: Si... SI! dejame sostenerla solo un segundo.\n"; passTree = true; break;
                            case 2: dialog = "ICICLES: Si! Por favor!\n"; passTree = true; break;
                            case 3: dialog = "ICICLES: Te lo imploro... hagamos negocios.\n"; passTree = true; break;
                            default:  option = 1 + (rand() % (3+1)-1);
                        }
                    }

                    passTree = false;
                    system("cls");
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Esta Lagrima de Diosa acompleta tu compra de este cachibache.... digo esta gran y lujosa lancha, claro que si...\n\n"
                             "Le das una mirada sospechoza al enano pero aceptas el trato y el pequenio hombrecillo te entrega la pequenia embarcacion.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Objeto de mision Embarcacion aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ICICLES: Ahora largo...!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.addObjMision("Embarcacion", "Creo que no fue un buen trato...");
                    player->inventario.delObjMision("Diamante de Gota");
                    maze[x][y].setfirstTime(false);

                    if(player->inventario.searchObjMision("Sangre de Esfinge")){
                            quest[0] = mid2;
                    }
                }

            }
            else if(x == 3 && y == 3){ // CUARTO DE LAVA

                if(maze[x][y].getfirstTime() && quest[0] == mid2){

                    string dialog = "Entras en la lancha y te adentras en el cuarto lleno de lava, la lancha es muy pequenia y estas muy apretado pero lentamente avanzas en el cuarto...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                }
            }
            else if(x == 4 && y == 3){ // LAGO DE LAS MIL LAGRIMAS

                if(maze[x][y].getfirstTime() && quest[0] == mid2){

                    string dialog = "Te bajas de la lancha en la costa y puedes admirar en el centro de esta habitacion un lago iluminado por la luna...\n"
                                    "Te acercas y llenas el frasco donde antes estaba la Sangre de Esfinge de agua del LAGO DE LAS MIL LAGRIMAS.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Objeto de mision Agua de Lagrimas aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.addObjMision("Agua de Lagrimas", "Lo unico que mata al dragon..");

                    maze[x][y].setfirstTime(false);
                }

            }
            else if(x == 4 && y == 4){

                if(maze[x][y].getfirstTime() && quest[0] == mid2){

                    string dialog = "Entras a la habitacion y te encuentras un cartel escrito en piedra.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "\"En el cuarto de la izquierda se encuentra el LAGO DE LAS MIL LAGRIMAS, fundado por nuestro gobernante el REY CARMESI\".\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "En el pie de la pintura hay una leyenda que dice \"EL REY CARMESI el unificador de todos los pueblos...\"\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                }
            }
            else if(x == 3 && y == 1){

                if(maze[x][y].getfirstTime()){

                    string dialog = "Vas caminando poco a poco por el tunel, y esta tan obscuro que comienzas a caminar cada vez mas rapido por el miedo que te da.\n"
                                    "Al terminar de cruzar, vuelves a tu tamanio original, dandote cuenta de que ya no puedes volver atras...\n"
                                    "Al llegar al cuarto, te encuentras con otro Transfugo. Es un ser mas habilidadoso, pero estas dispuesto a derrocarlo como siempre...\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    player->inventario.delObjMision("Pocion Diminutiva");

                    dialog = "Acabando el combate, tienes que realizar tu siguiente movimiento.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
                else if(!maze[x][y].getfirstTime() && (quest[1] == mid || quest[1] == intro)){

                    string dialog = "Estas en el cuarto donde se encuentra la puerta diminuta...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }
            }else if(x == 3 && y == 0){

                if(maze[x][y].getfirstTime()){ //CUARTO DE CAIN

                    string dialog = "Vas caminando, y encuentras en tu camino a un... mercenario...?. Lo miras y parece que esta enfermo,\n"
                                    "asi que decides arriesgarte...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ERRANTE: Quien esta ahi?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Decides acercarte, asi que sacas tu linterna y te acercas con el.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "ERRANTE: Conque un viajero.\n"
                             "Cuanto tiempo ha sido desde que he visto a otra persona dentro de este viejo laberinto...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Esto... Y quien es usted?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Que modales los mios... te ofrezco una disculpa, joven viajero. Soy el errante CAIN.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Un errante?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Si, podriamos decir que soy un vagabundo. Voy de lugar en lugar sin un destino fijo.\n"
                             "Llevo siglos viviendo en este laberinto.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Pero, pareces humano... Como es que has vivido siglos?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Como explicarte chico. Efectivamente, yo soy humano. Sin embargo, este laberinto te mantiene joven.\n"
                             "Es como si el tiempo se detuviera estando aqui...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Mm, han pasado tantos anios... que he perdido la nocion del tiempo.\n"
                             "Pueden ser 200 anios... o habran sido 300? Desafortunadamente no lo recuerdo, y la verdad me da igual...*COUGH COUGH*\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "El errante comienza a toser sangre.\n"  ;
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Escucha chico..., aunque este laberinto me haya mantenido vivo, no me queda mucho tiempo de vida.\n"
                             "Estoy muy enfermo y no sé cuanto tiempo me quede.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Te puedo ayudar de alguna manera?\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Si...hehe.. Por lo que puedo ver parece que quieres encontrar una salida de este laberinto, No?.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Emm, si...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Hagamos un trato. Existe un gnomo que vomita arco iris, y ese liquido es capaz de curarte de cualquier mal.\n"
                             "Si logras conseguir un poco, podria vivir, y te ayudare a salir de aqui... *COUGH COUGH*\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Esta bien. Tenemos un trato, lo ayudare para que usted pueda mejorar y seguir viviendo.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Muchas gracias muchacho. *COUGH COUGH*.\n"
                             "Esperare aqui. Mucha suerte...la necesitaras\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setfirstTime(false);
                    quest[1] = mid;

                }else if(!maze[x][y].getfirstTime() && !player->inventario.searchObjMision("Vomito de Gnomo Mutado Arcoiris") && quest[1] != finall){

                    string dialog = "CAIN: Todavia nada chico?. Espero puedas ayudarme *COUGH COUGH*...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                }
                else if(!maze[x][y].getfirstTime() && player->inventario.searchObjMision("Vomito de Gnomo Mutado Arcoiris") && quest[1] == mid2){

                    string dialog = "Vuelves a acercarte con CAIN, y sacas el frasco de vomito de arco iris del gnomo magico mutante.\n"
                                    "Te lo arrebata bruscamente de las manos.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Al momento de que se lo toma, le cambia el gesto al errante. Vuelve a verse vivido.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Gracias chico. Me has salvado la vida, me toca cumplir con mi parte del trato...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Se ve que realmente quieres salir de aqui, asi que te dare la llave que lleva al final de este laberinto.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    player->inventario.addObjMision("Llave Final", "Llave para abrir la enorme puerta.");

                    dialog = "Objeto de mision Llave Final aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Ahora podremos salir de este lugar. Vamonos!\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Meeeh, yo me quedo aqui chico...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Te quedas mirando a CAIN sorprendido.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Que tiene?!...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: Ahhh, esta bien te contare algo, pero mas vale que no le digas a nadie.\n"
                             "La verdad, no creo tener nada que valga la pena afuera chico, digo... ha pasado tanto tiempo...\n"
                             "No hay nada que me motive a salir, ademas... la vida aqui no esta taaaan mal una vez te acostumbras.\n\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "CAIN: En fin, tu se libre. No desperdicies tu vida como yo lo hice con la mia. No sabes como me arrepiento hoy en dia\n"
                             "pero, ya no hay nada que pueda hacer...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Espero nos volvamos a ver...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Tal vez, asi sea algun dia muchacho. Mientras tanto, vive tu vida.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.delObjMision("Vomito de Gnomo Mutado Arcoiris");
                    quest[1] = finall;
                }

            }else if(x == 4 && y == 0){

                if(maze[x][y].getfirstTime() && quest[1] == intro){

                    string dialog = "Te encuentras a un gnomo... mutante?\n"
                                    "Esta vomitado arco iris...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }
                else if(maze[x][y].getfirstTime() && quest[1] == mid){

                    string dialog = "Te encuentras a un gnomo... mutante?\n"
                                    "Esta vomitado arco iris...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Es el gnomo del que hablaba CAIN.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Tomas el frasco que esta al lado para llevarle el vomito a CAIN.\n"
                             "Intentas acercarte, pero te encuentras con un Transfugo que esta resguardando al gnomo magico...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "Terminas de pelear con el Transfugo, y al fin tienes la oportunidad de agarrar el frasco con el vomito de arco iris del gnomo magico.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.addObjMision("Vomito de Gnomo Mutado Arcoiris", "Me recuerda a una caricatura...");

                    dialog = "Objeto de mision Vomito de Gnomo Mutado Arcoiris aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Espero que no sea demasiado tarde...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    quest[1] = mid2;
                    maze[x][y].setfirstTime(false);

                }else if(!maze[x][y].getfirstTime() && quest[1] == mid){

                    string dialog = "Es el gnomo del que hablaba CAIN.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Tomas el frasco que esta al lado para llevarle el vomito a CAIN.\n"
                             "Intentas acercarte, pero te encuentras con un Transfugo que esta resguardando al gnomo magico...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "Terminas de pelear con el Transfugo, y al fin tienes la oportunidad de agarrar el frasco con el vomito de arco iris del gnomo magico.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.addObjMision("Vomito de Gnomo Mutado Arcoiris", "Me recuerda a una caricatura...");

                    dialog = "Objeto de mision Vomito de Gnomo Mutado Arcoiris aniadido al inventario.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = player->getName() + ": Espero que no sea demasiado tarde...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    quest[1] = mid2;
                    maze[x][y].setfirstTime(false);
                }
            }else if(x == 4 && y == 1){

                if(maze[x][y].getfirstTime()){

                    string dialog = "Estas en el pasillo, y lo unico que encuentras son cenizas y artilleria vieja, pero no hay nada util, asi que decides no tomar nada.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");
                    maze[x][y].setfirstTime(false);
                }

            }else if(x == 4 && y == 2){

                if(maze[x][y].getfirstTime() && !player->inventario.searchObjMision("Llave Final")){

                    string dialog = "Te encuentras con una puerta colosal, y te das cuenta que tiene una pequenia abertura para meter una llave.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Parece ser la salida... Intentas abrirla pero, efectivamente, tiene llave.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Tambien te encuentras con una estatua de piedra cubierta de un liquido rojo, muy parecido a la sangre.\n"
                             "Consideras que es parte de la decoracion del cuarto. Atras se encuentra un cuadro del REY CARMESI parado sobre un esqueleto.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");


                    maze[x][y].setfirstTime(false);
                }
                else if(maze[x][y].getfirstTime() && player->inventario.searchObjMision("Llave Final")){

                    string dialog = "Te encuentras con una puerta colosal, y te das cuenta que tiene una pequenia abertura para meter una llave.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Parece ser la salida... Intentas abrirla pero, efectivamente, tiene llave.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Tambien te encuentras con una estatua de piedra cubierta de un liquido rojo, muy parecido a la sangre.\n"
                             "Consideras que es parte de la decoracion del cuarto. Atras se encuentra un cuadro del REY CARMESI parado sobre un esqueleto.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Pruebas abrir la enorme puerta con la llave que te dio CAIN...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Funciona... Parece que porfin saldras de aqui.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "La enorme puerta esta abierta.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    player->inventario.delObjMision("Llave Final");
                    maze[x][y].setfirstTime(false);
                    maze[x][y].setWays(true, false, true, false);
                }
                else if(!maze[x][y].getfirstTime() && player->inventario.searchObjMision("Llave Final")){

                    string dialog = "Pruebas abrir la enorme puerta con la llave que te dio CAIN...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "Funciona... Parece que porfin saldras de aqui.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    dialog = "La enorme puerta esta abierta.\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    maze[x][y].setWays(true, false, true, false);
                    player->inventario.delObjMision("Llave Final");
                    maze[x][y].setfirstTime(false);
                    maze[x][y].setWays(true, false, true, false);
                }

            }else if(x == 3 && y == 2){

                string dialog = "La puerta roja se abre lentamente provocando un chirrido ensordecedor, logras darte cuenta que la habitacion es de forma circular y en el\n"
                                "centro hay una GIGANTESCA estatua del REY CARMESI. En la cual el mismo esta posado sobre un esqueleto.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "DESCONOCIDO: Es admirable...\n\n"
                         "Escuchas que una voz imponente que se oye desde la sombra que genera la estatua.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "DESCONOCIDO: No muchos viajeros llegan hasta aqui.\n\n"
                         "Dos ojos oscuros resaltan por el brillo. Una imponente figura se materializa frente a ti y con unos colosales pasos se muestra ante la luz.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Una delgada y muy alta persona con cara cara de buho se asoma, sus brazos son exageradamente largos y estan llenos de plumas,\n"
                         "sus piernas tienen una especie de piel aspera y en lugar de pies tiene unas patas con tres dedos...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "De la impresion das unos pasos hacia atras.\n\n";
                writeDialogs(dialog);

                int option = 0; bool passTree = false;

                cout << "1)T-u..Tu eres el REY CARMESI?" << endl;
                cout << "2)Emmm, e-estas bien?" << endl;
                cout << "3)Eres horrible, ni en un millon de anios tu podrias ser el REY CARMESI." << endl << endl;
                cout << "Respondes: ";
                cin >> option;

                while(!passTree){
                    switch (option) {
                        case 1: dialog = "REY CARMESI: Como todo tu trayecto hacia aqui, has acertado.\n"; passTree = true; break;
                        case 2: dialog = "REY CARMESI: Yo..., me siento mejor que nunca ahora que has llegado.\n"; passTree = true; break;
                        case 3: dialog = "REY CARMESI: CUIDA TU BOCA INSOLENTE!\n"; passTree = true; break;
                        default:  option = 1 + (rand() % (3+1)-1);
                    }
                }

                passTree = false;
                system("cls");
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Yo soy el REY CARMESI y estoy aqui para felicitarte por tu victoria frente a mi laberinto.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "El monarca se detiene a respirar y genera un sonido ahogado, como si cada bocanada de aire le costara mucho..., tose una vez y continua con su discurso.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Veo que estas impaciente por regresar a tu mundo, por lo que no te aburro mas con mucha palabreria, solo debes pararte\n"
                         "sobre esa plataforma y con el cristal de mi cuello te enviare a casa...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Despues de escuchar esa noticia, te subes sobre la plataforma con emocion.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Listo, muy bien 1,2, y....\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "De la plataforma salen unas cadenas que se enganchan a tu cuello y brazos las cuales te tiran al suelo.\n"
                         "El REY CARMESI cambia su semblante por completo y genera una tetrica sonrisa de la cual un liquido negro sale de su boca.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Con tu caida tu linterna se suelta de tus manos y alumbra detras de la estatua, lo que a la vez te congela por completo.\n"
                         "Una pila de cientos o inclusive miles de esqueletos se encuentra detras de la estatua, el liquido que cae del pico del rey\n"
                         "se arrastra hacia uno de los esqueletos y se extiende por su interior, poco a poco el conjunto de huesos se incorpora lanzando un grito atronador,\n"
                         "has precenciado el nacimiento de un Transfugo.\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: PoR FiNNnnnnnnnn, Si lLeGaBAS uN pOCO MAsss tarDEE HuBierRA MuERTTo De HamBREEEEE\n\n";
                writeDialogs(dialog);

                cout << "1)Que es esto?!" << endl;
                cout << "2)Que esta pasando?!" << endl;
                cout << "3)Alejate! Aqueroso ser!" << endl << endl;
                cout << "Respondes: ";
                cin >> option;

                while(!passTree){
                    switch (option) {
                        case 1: dialog = "REY CARMESI: yA nO hAy cAmInO, vIaJeRo...\n"; passTree = true; break;
                        case 2: dialog = "REY CARMESI: nO lO eTiEnDes o si?\n"; passTree = true; break;
                        case 3: dialog = "REY CARMESI: eS InEvItAbLe...\n"; passTree = true; break;
                        default:  option = 1 + (rand() % (3+1)-1);
                    }
                }

                passTree = false;
                system("cls");
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "El REY CARMESI recupera un poco la compostura y sigue.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Durante siglos miles de viajeros llegaron a mi laberinto y me sirvieron como alimento,\n"
                         "pero de un momento a otro dejaron de llegar, no se por que mi magia ya no los atraia hacia mi...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Y por eso me comence a morir de hambre,... cuando estaba por perecer tome una decision necesaria,\n"
                         "les dije a todos los habitantes del laberinto que evacuaran... pero en realidad solo los traje aqui para alimentarme de ellos y no morir de hambre.\n"
                         "Pero eso solo me dio un poco mas de tiempo\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");


                dialog = "REY CARMESI: Cuando crei que ya no tenia salvacion... llegaste TU\n"
                         "y encendiste una chispa de esperanza en mi para sobrevivir al menos un poco mas.\n\n";
                writeDialogs(dialog);

                cout << "1)Eres un monstruo, mentiste sobre ese cuento de los pueblos unidos..." << endl;
                cout << "2)Pero... por que todavia existe el laberinto si estas tan debil?" << endl;
                cout << "3)Solo me mentiste con un poco de esperanza para terminar conmigo asi?!" << endl << endl;
                cout << "Respondes: ";
                cin >> option;

                while(!passTree){
                    switch (option) {
                        case 1: dialog = "REY CARMESI: Tal vez..., pero todos estamos dispuestos a hacer lo que sea para sobrevivir, si ese es el caso, todos somos un monstruo por dentro.\n"; passTree = true; break;
                        case 2: dialog = "REY CARMESI: Necesitaba que llegaras a mi por el camino correcto, de lo contrario tu espiritu no estaria puro para alimentarme de el...\n"; passTree = true; break;
                        case 3: dialog = "REY CARMESI: No te sientas mal... lo hice con miles de personas.\n"; passTree = true; break;
                        default:  option = 1 + (rand() % (3+1)-1);
                    }
                }

                passTree = false;
                system("cls");
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Cada vez que lograste pasar una etapa de mi laberinto destruia la anterior para no gastar mi energia y aguantar mas...\n\n";
                writeDialogs(dialog);

                cout << "1)Y los ultimos seres que vivian en el laberinto?!" << endl;
                cout << "2)Que les hiciste a todos los demas?!" << endl;
                cout << "3)Por que no terminaste con los demas que vivian aqui?!" << endl << endl;
                cout << "Respondes: ";
                cin >> option;

                while(!passTree){
                    switch (option) {
                        case 1: dialog = "REY CARMESI: Esos traidores...\n"; passTree = true; break;
                        case 2: dialog = "REY CARMESI: No me sirven asi...\n"; passTree = true; break;
                        case 3: dialog = "REY CARMESI:No crees que queria?\n"; passTree = true; break;
                        default:  option = 1 + (rand() % (3+1)-1);
                    }
                }

                passTree = false;
                system("cls");
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Para que pueda alimentarme de un ser es necesario que este haya pasado primero por el laberinto para purificar su espiritu y pueda alimentarme de ese ser...\n"
                         "PERO ESOS MALDITOS TRAIDORES NO QUISIERON ABANDONAR EL LABERINTO Y NO ME PODIA ALIMENTAR DE ELLOS ASI!\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Hasta el ultimo viajero que paso por aqui... DECIDIO QUEDARSE A VIVIR EN EL MALDITO LABERINTO Y VOLVERSE UN ERRANTE!,\n"
                         "es por eso que cree los Transfugos, para intentar correrlos del laberinto y venir hacia aqui para devorarlos, pero ahora no me importan,\n"
                         "por que cuando destrui el laberinto a tu paso lo mas probable es que hayan muerto...\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "El REY CARMESI se posa detras de ti y sujeta tu cuello con un poco de la sustancia oscura que cae de su pico a tu cara...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Pero creo que es momento de decir adios viajero... por que llego la hora de alimentarme...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "El REY CARMESI abre su pico por completo y se acerca para devorarte.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Lanzas un grito de desesperacion y por mas que intentas moverte no logras nada...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "De pronto un sonido en seco golpea la puerta, el REY CARMESI se detiene y voltea a ver el origen del sonido.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Un grupo de quejidos se escucha detras de la puerta y despues de un ultimo golpe la puerta cae hecha pedazos, de la misma se asoman 5 siluetas:\n"
                         "WINKLIPET el Gnomo\n"
                         "VILTRO el Leniador\n"
                         "CIEDA la Costurera\n"
                         "ICICLES el Mercader\n"
                         "y por ultimo CAIN el Errante...\n\n"
                         "Entran de un salto al cuarto, todos dirigen la mirada al \"Rey\" y lanzan un grito de miedo al ver la forma que este tiene.\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "CIEDA: QUE ES ESA COSA?!\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: INSOLENTE SUBORDINADA! INCLINATE ANTE TU REY!!\n\n"
                         "VILTRO: TU NO ERES NUESTRO REY, EL REY CARMESI ES UN SER LLENO DE BELLEZA QUE TRAJO LA PAZ EN NUESTRO REINO!\n\n"
                         "REY CARMESI: ESA ES LA FORMA QUE TOMABA FRENTE AL REINO, PERO CUANDO ME AYUDARON A CONSTRUIR ESTE LABERINTO SOLO ME SIRVIERON COMO ALIMENTO.\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");


                dialog = "WINKLIPET: Te maldigo asqueroso ser, tu cabeza la colgare en un arbol en lo alto por tus crimenes!\n\n"
                         "CAIN: ME ARRANCASTE DE MI MUNDO SOLO PARA SER ALIMENTO!? TE MATARE!\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "El rey extiende sus brazos y corre hacia el grupo de gente, con mucha agilidad todos escapan de sus garras,\n"
                         "CIEDA intenta lanzar agujas al ser amorfo que es el Rey mientras que VILTRO lo golpea con su hacha de obsidiana, los demas se acercan hacia ti con rapidez y cada uno te quita una cadena.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "CAIN: Creo que necesitaras esto...\n\n"
                         "Dice CAIN acercandote tu mochila con los frascos elementales.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "ICICLES: Pero sera mas practico si los combinas con esto.\n\n"
                         "ICICLES te lanza una especie de espada de plata que al chocar con los frascos se fusionan entregandote una espada de color blanco.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");


                dialog = "ICICLES: Cuando estuviste en mi tienda esperaba que no me preguntaras por este objeto por que es lo mas valiosos que tengo, pero ahora creo que eso queda de lado.\n\n"
                         "La espada es ligera y la levantas algo confundido, de un segundo a otro la espada se prende en fuego, despues se congela y despues se hace de un material liquido...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "La CIEDA y VILTRO salen volando por encima de los tres y caen detras de ti.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Es suficiente! ƆꓵƎꓤԀOS ꓥⱯƆIOS ꓶƎꓥⱯNꓕƎNƆƎ ⅄ ԀƎꓶƎƎN ԀOꓤ Sꓵ ꓤƎ⅄...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "El rey pronuncia unas palabras en una lengua que no entiendes... y de inmediato los esqueletos detras de la estatua comienzan a levantarse,\n"
                         "ahora se ven rodeados por cientos de Transfugos que amenazan con atacarlos.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = player->getName() + ": Encarguense de los Transfugos, el Rey es mio...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Todos en el grupo acienten y se adentran en batalla con todos los Transfugos.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "REY CARMESI: Es inutil, todos terminaran siendo alimento...\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");


                for(int i = 0; i<3; i++){
                    writeDialogs("Pelea " + to_string((i+1)) + "\n");
                    system("pause");
                    system("cls");
                    elementalFight();
                }

                dialog = "El REY CARMESI se empieza a hacer ceniza frente a todos los del grupo.\n\n"
                         "REY CARMESI: ESTO NO ES EL FINAL! YO VOLVERE Y JURO QUE DEVORARE SUS ALMAAAS!\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Lo que antes era el REY CARMESI ahora es solo un puniado de polvo, todos los recuerdos de quien eres vuelven a ti....\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = player->getName() + ": Se quien soy!, ahora lo recuerdo.\n";

                dialog = "CIEDA: Se termino?\n\n"
                         "VILTRO: Somos libres?!\n\n"
                         "WINKLIPET: Pero ahora... Que hacemos?\n\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "CAIN: Hace mucho que no estoy en el mundo, no se si me adapte...\n\n" +
                          player->getName() + ": Por que no vienen conmigo? No vivo en un palacio pero los puedo ayudar a adaptarse.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                dialog = "Todos asienten y con algo de miedo se suben sobre la plataforma que antes te aprisiono pero ahora esta brilla de color azul y todo se vuelve blanco...\n"
                         "De repente te encuentras viendo tu hogar, una bella casa de color azul que los espera a todos con las luces encendidas.\n";
                writeDialogs(dialog);
                system("pause");
                system("cls");

                this->ended = true;

            }
            else{ // Cuarto default

                if(maze[x][y].getfirstTime()){

                    string dialog = "Entras a una habitacion a oscuras, sacas tu linterna y te das cuenta que el candelabro se apago con todas las goteras que tiene el cuarto.\n"
                                    "En el fondo un Transfugo se levanta de un charco de un liquido oscuro y corre hacia ti para atacarte...\n";
                    writeDialogs(dialog);
                    system("pause");
                    system("cls");

                    elementalFight();

                    dialog = "El transfugo se hace polvo frente a ti...\n";
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
                Sleep(0);
                i++;
            };
        }

        void elementalFight(){
            system("cls");

            Elementals transfugoAttack = static_cast<Elementals>(0 + (rand() % (2 + 1)));
            Elementals playerAttack;
            bool fightEnd = false;
            int temp;


            do{

                cout << "1)Agua" << endl;
                cout << "2)Fuego" << endl;
                cout << "3)Hielo" << endl << endl;
                cout << "Elige con que vas a atacar...: ";
                cin >> temp;

                system("cls");

                if(temp > 3 || temp < 1){
                    cout << endl << "...Si no te lo tomas seriamente, entonces el destino eligira por ti." << endl;
                    system("pause");
                    system("cls");
                    temp = 0 + (rand() % (2+1));
                } else temp--;

                playerAttack = static_cast<Elementals>(temp);

                switch(playerAttack){
                    case water:
                        if(transfugoAttack == ice){
                            fightEnd = true;
                            cout << "Elegiste agua..." << endl;
                            cout << "El enemigo lanza hielo..." << endl << endl;
                            cout << "Haz perdido! Pierdes una vida... " << endl;
                            system("pause");
                            system("cls");
                            player->takeDamage();

                        }
                        else if(transfugoAttack == fire){
                            fightEnd = true;
                            cout << "Elegiste agua..." << endl;
                            cout << "El enemigo lanza fuego..." << endl << endl;
                            cout << "Haz ganado!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == water){
                            cout << "Elegiste agua..." << endl;
                            cout << "El enemigo lanza agua..." << endl << endl;
                            cout << "Empate!" << endl;
                            cout << "Vuelve a elegir tu ataque..." << endl;
                            transfugoAttack = static_cast<Elementals>(0 + (rand() % (2 + 1)));
                            system("pause");
                            system("cls");
                        }
                        break;

                    case fire:
                        if(transfugoAttack == water){
                            fightEnd = true;
                            cout << "Elegiste fuego..." << endl;
                            cout << "El enemigo lanza agua..." << endl << endl;
                            cout << "Haz perdido! Pierdes una vida..." << endl;
                            system("pause");
                            system("cls");
                            player->takeDamage();

                        }
                        else if(transfugoAttack == ice){
                            fightEnd = true;
                            cout << "Elegiste fuego..." << endl;
                            cout << "El enemigo lanza hielo..." << endl << endl;
                            cout << "Haz ganado!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == fire){
                            cout << "Elegiste fuego..." << endl;
                            cout << "El enemigo lanza fuego..." << endl << endl;
                            cout << "Empate!" << endl;
                            cout << "Vuelve a elegir tu ataque..." << endl;
                            transfugoAttack = static_cast<Elementals>(0 + (rand() % (2 + 1)));
                            system("pause");
                            system("cls");
                        }
                        break;

                    case ice:
                        if(transfugoAttack == fire){
                            fightEnd = true;
                            cout << "Elegiste hielo..." << endl;
                            cout << "El enemigo lanza fuego..." << endl << endl;
                            cout << "Haz perdido! Pierdes una vida..." << endl;
                            system("pause");
                            system("cls");
                            player->takeDamage();

                        }
                        else if(transfugoAttack == water){
                            fightEnd = true;
                            cout << "Elegiste hielo..." << endl;
                            cout << "El enemigo lanza agua..." << endl << endl;
                            cout << "Haz ganado!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == ice){
                            cout << "Elegiste hielo..." << endl;
                            cout << "El enemigo lanza hielo..." << endl << endl;
                            cout << "Empate!" << endl;
                            cout << "Vuelve a elegir tu ataque..." << endl;
                            transfugoAttack = static_cast<Elementals>(0 + (rand() % (2 + 1)));
                            system("pause");
                            system("cls");
                        }
                        break;
                }

            }while(!fightEnd);

        }

};
