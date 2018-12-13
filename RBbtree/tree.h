#ifndef TREE_H
#define TREE_H
#include "No.h"
#include<bits/stdc++.h>
#include<Item.h>

class tree
{
private:
    No *raiz,*nulo;

public:
    tree();
    bool inserir(Item*);
    Item* retirar(Item*);
    Item* consultar(Item*);
    No* pesq(Item*);
    void mostrarordem(No* pNo,std::string &aux)const;
    void mostrarordem(std::string &aux)const;
    void mostrarpreordem(No* pNo,std::string &aux)const;
    void mostrarpreordem(std::string &aux)const;
    void mostrarposordem(std::string &aux)const;
    void mostrarposordem(No* pNo,std::string &aux)const;
    bool vazia();
    void testaIntegridade(No *p, std::string &aux);
    void rotacao_direita(No *node);
    void rotacao_esquerda(No *node);
    void corrigir_violacao(No *node, No *root);
private:
    No* minima(No*);
    No* maximo(No*);
    No* antecessor(No*);
    No* sucessor(No*);

};

#endif // TREE_H
