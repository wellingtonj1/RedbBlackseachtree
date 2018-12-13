#ifndef NO_H
#define NO_H
enum Color {RED, BLACK};
#include "Item.h"

class No
{
private:
    No *pai,*fe,*fd;
    Item *dados;
    bool cor;

public:

    No();
    Item* getdados();
    void setdados(Item *aux){ dados=aux; }
    No* getpai();
    void setpai(No *x){ pai=x; }
    No* getfe();
    void setfe(No *x){ fe=x; }
    No* getfd();
    void setfd(No *x){ fd=x; }
    static No* montano(Item*);
    static Item* desmontano(No*);
    bool getCor(){return cor;}
    void setCor(bool value){cor = value;}

};

#endif // NO_H
