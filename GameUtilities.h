#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define ID_LENGTH 3

using namespace std;

class Player;

class ObjInv {

private:
    string name;
    string description;
    bool isObjectMision;

public:
    ObjInv(string name,string description, bool isObjectMision = false);
    ~ObjInv();
    void info();
    virtual void use(Player * player);
    string getName();
    bool getisObjectMision();
};

typedef struct Node {
    ObjInv* item;
    Node* next;
    string id;
};

class Inventory {

private:
    Node* head;
    Node* tail;

public:

    Inventory();
    ~Inventory();
    void clear();
    void addItem(ObjInv* item);
    void addObjMision(string name, string description);
    void useConsumable(string ID, Player* player);
    void showInventory();
    void useIventory(Player* player);
    bool searchObjMision(string name);
    void delObjMision(string name);

private:
    Node* getNew(ObjInv* item);
    string generarID(int sizeID);
};

class Player {

private:
    stack<int> life;
    stack<int> shield;
    int maxShield, maxLife;
    string name;

public:
    Inventory inventario = Inventory();
    Player(string name, int lives, int shield);
    ~Player();
    void takeDamage();
    void heal();
    void shieldPlayer();
    int getLife();
    int getShield();
    string getName();
    void increaseMaxShield();
    void increaseMaxLife();
};

class Potion : public ObjInv{

public:
    Potion(string name,string description);
    ~Potion();
    void use(Player* player) override;
};

class Shield : public ObjInv{

public:
    Shield(string name,string description);
    ~Shield();
    void use(Player* player) override;
};
