
#include "GameUtilities.h"

Player::Player(string name, int lives, int shield){
    maxLife = lives;
    maxShield = shield;
    this->name = name;

    for(int i = 0; i < lives; i++){
        life.push(1);
    }
}

Player::~Player()= default;

void Player::takeDamage() {
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
}

void Player::heal(){
    if(life.size() < maxLife){

        life.push(1);

    }else cout << "Ya tienes la vida al maximo, desperdiciaste la pocion..." << endl;

}

void Player::shieldPlayer() {
    if(shield.size() < maxShield){

        shield.push(1);

    }else cout << "Ya tienes el escudo al maximo, desperdeciaste el escudo..." << endl;
}

int Player::getShield(){
    return shield.size();
}

int Player::getLife(){
    return life.size();
}

string Player::getName() {
    return name;
}

Inventory::Inventory() {
    head = NULL;
    tail = NULL;
}

Inventory::~Inventory(){
    clear();
}

void Inventory::clear(){

    while(head){
        Node* lTemp = head->next;
        delete head;
        head = lTemp;
    }
    tail = NULL;
}

void Inventory::addItem(ObjInv* item){

    Node* temp = getNew(item);

    if(head == NULL && temp!=NULL){
        head = temp;
        tail = temp;
    }
    else if(temp!=NULL){
        tail->next = temp;
        tail = temp;
    }
}

void Inventory::showInventory() {

    Node* temp = head;

    if(temp == NULL){
        cout << "No tienes ningun objeto en el inventario." << endl;
    }

    while(temp != NULL){

        cout << "(" << temp->id << ")";
        temp->item->info();
        cout << endl;

        temp = temp->next;
    }
}

void Inventory::useConsumable(string ID, Player* player){

    Node* temp = head;
    Node* father = NULL;
    bool founded = false;

    while(temp != NULL){

        if(temp->id == ID){

            founded = true;

            if(temp->item->getisObjectMision()){
                cout << "Esto parece importante, no deberia de hacerlo..." << endl;
            }
            else{
                temp->item->use(player);
                //Borrar el nodo del objeto consumido

                if(father){
                    if(father->next != NULL){
                        temp = father->next;
                        father->next = temp->next;

                        if(temp ==tail){
                            tail = father;
                        }
                        delete temp;
                    }
                }
                else{

                    if(head){

                        temp = head->next;

                        if(head == tail){
                            tail = NULL;
                        }
                        delete head;
                        head = temp;
                    }
                }

            }
            break;
        }
        father = temp;
        temp = temp->next;
    }
    if(!founded) cout << "No existe el ID ingresado" << endl;
}

void Inventory::useIventory(Player* player) {

    int option = 0; bool enough = false;
    string id;

    do{
        cout << "1) Mostrar objetos del inventario" << endl;
        cout << "2) Usar algun objeto del inventario" << endl << endl;
        cout << "Que deberia hacer?: ";
        cin >> option;

        switch(option){
            case 1: showInventory(); break;
            case 2:
                cout << endl << "Ingresa el ID del objeto a usar: ";
                cin.ignore();
                getline(cin, id);
                useConsumable(id, player);
                break;
            default:
                cout << "Ponte serio..." << endl;
        }

        cout << endl << "1) Si" << endl;
        cout << "2) Cualquier otro numero, No" << endl << endl;
        cout << "Cerrar inventario?: ";
        cin >> option;

        if(option == 1){
            enough = true;
        }else continue;

    }while(!enough);

}

Node* Inventory::getNew(ObjInv* item) {

    if(item != NULL){
        Node* temp = new Node;
        temp->item = item;
        temp->next = NULL;
        temp->id = generarID(ID_LENGTH);
        return temp;
    }
    return NULL;
}

string Inventory::generarID(int sizeID){
    string id;
    int random = 0;

    for(int i = 0; i < ID_LENGTH ; i++)
    {
        random = 0 + (rand() % (9+1));
        id += to_string(random);
    }
    return id;
}

ObjInv::ObjInv(string name,string description, bool isObjectMision){

    this->name = name;
    this->description = description;
    this->isObjectMision = isObjectMision;
}

ObjInv::~ObjInv()= default;

void ObjInv::info() {
    cout << "Nombre: " << name << endl;
    cout << "Descripcion: " << description << endl;
}

void ObjInv::use(Player * player){

}

string ObjInv::getName() {
    return name;
}

bool ObjInv::getisObjectMision() {
    return isObjectMision;
}

Potion::Potion(string name,string description):ObjInv(name,description){

}

Potion::~Potion()= default;

void Potion::use(Player *player) {
    player->heal();
    this->~Potion();
}

Shield::Shield(string name,string description):ObjInv(name,description){

}

Shield::~Shield()= default;

void Shield::use(Player *player){
    player->shieldPlayer();
    this->~Shield();
}