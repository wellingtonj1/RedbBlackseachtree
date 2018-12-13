#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include <iomanip>

class Item
{
private:
    std::string nomeprod,codbarras;
    int quanti;
    float valor;

public:
    Item();
    int getquanti();
    void setquanti(int);
    float getpreco();
    void setpreco(float);
    std::string getnomeprod();
    std::string getcodbarras();
    void setcodbarras(std::string);
    void setnomeprod(std::string);
    std::string gettudo();
};

#endif // ITEM_H
