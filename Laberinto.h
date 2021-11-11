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


    public:
        Fase1(){

            string playerName;

            cout << "Alpha" << endl;
            system("pause");
            system("cls");

            cout << endl << "Lo que vas a jugar es el tutorial y la version muy temprana del juego. Por lo que errores y crasheos pueden ocurrir." << endl;
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
            maze[2][0].setWays(false, true, false, false);
            maze[2][1].setWays(true, true, false, false);
            maze[2][2].setWays(true, true, false, false);

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

                    dialog = "WINKLIPET: El REY CARMESI es el soberano del reino de Doorbell, hace mucho tiempo los enanos,\ngnomos, las costureras y los caballeros de obsidiana viviamos en constantes guerras y disputas,\n"
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
                    player->inventario.addObjMision("Manzana", "Manzana que te pidio el WINKLIPET.");
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

                        dialog = "Tu capacidad de cargas de escudo a aumentado en uno.\n";
                        writeDialogs(dialog);
                        system("pause");
                        system("cls");
                        player->inventario.delObjMision("Llave de plata");
                        player->setMaxShield(4);
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
                            cout << "El transfugo lanza hielo..." << endl << endl;
                            cout << "Haz perdido! Pierdes una vida... " << endl;
                            player->takeDamage();
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == fire){
                            fightEnd = true;
                            cout << "Elegiste agua..." << endl;
                            cout << "El transfugo lanza fuego..." << endl << endl;
                            cout << "Haz ganado!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == water){
                            cout << "Elegiste agua..." << endl;
                            cout << "El transfugo lanza agua..." << endl << endl;
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
                            cout << "El transfugo lanza agua..." << endl << endl;
                            cout << "Haz perdido! Pierdes una vida..." << endl;
                            player->takeDamage();
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == ice){
                            fightEnd = true;
                            cout << "Elegiste fuego..." << endl;
                            cout << "El transfugo lanza hielo..." << endl << endl;
                            cout << "Haz ganado!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == fire){
                            cout << "Elegiste fuego..." << endl;
                            cout << "El transfugo lanza fuego..." << endl << endl;
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
                            cout << "El transfugo lanza fuego..." << endl << endl;
                            cout << "Haz perdido! Pierdes una vida..." << endl;
                            player->takeDamage();
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == water){
                            fightEnd = true;
                            cout << "Elegiste hielo..." << endl;
                            cout << "El transfugo lanza agua..." << endl << endl;
                            cout << "Haz ganado!" << endl;
                            system("pause");
                            system("cls");
                        }
                        else if(transfugoAttack == ice){
                            cout << "Elegiste hielo..." << endl;
                            cout << "El transfugo lanza hielo..." << endl << endl;
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
