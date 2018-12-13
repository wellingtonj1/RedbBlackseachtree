#include "tree.h"

tree::tree()
{
    raiz=nulo=No::montano(nullptr);
}
bool tree::inserir(Item* aux)
{
    if(!aux) return false;
    No *at = raiz, *an = raiz;
    while(at!=nulo)
    {
        if(aux->getcodbarras() < at->getdados()->getcodbarras())
        {
            an = at;
            at = at->getfe();
        }
        else
        {
            if(aux->getcodbarras() > at->getdados()->getcodbarras())
            {
                an = at;
                at = at->getfd();
            }
            else
                return false;
        }
    }
    No *novo = No::montano(aux);
    novo->setfe(nulo);
    novo->setfd(nulo);
    if(an == nulo)
    {
        raiz = novo;
        novo->setpai(nulo);
    }
    else
    {
        novo->setpai(an);
        if(aux->getcodbarras() < an->getdados()->getcodbarras())
            an->setfe(novo);
        else
            an->setfd(novo);
    }   
    corrigir_violacao(at,at->getpai());
    return true;
}

Item* tree::retirar(Item *obj)
{
    No * z = pesq(obj);
    Item * aux = 0;
    if(z != nulo)
    {
        aux = new Item;
        * aux = * z->getdados();
        No * y = nulo;
        No * x = nulo;

        if(z->getfd() == nulo || z->getfe() == nulo)
        {
            y = z ;
        }
        else
        {
            y = sucessor(z) ;
        }

        if(y->getpai() == nulo)
        {
            raiz = x;
            if(x != nulo){x->setpai(nulo);}
        }
        else{
            if(y==y->getpai()->getfe())
            {
                y->getpai()->setfe(x);
            }
            else
            {
                y->getpai()->setfd(x);
            }
        }
        if(y!=z){*z->getdados() = *y->getdados() ; }
        this->corrigir_violacao(z,z->getpai());
        delete y;
        return aux;
    }

        return aux;

}

Item* tree::consultar(Item *aux)
{

    if(aux==nullptr)
    {
        return nullptr;
    }

    No* ptr =raiz;
    while (ptr!=nulo)
    {

        if(aux->getcodbarras()<ptr->getdados()->getcodbarras())
        {
            ptr=ptr->getfe();
        }
        else
        {
            if(aux->getcodbarras()>ptr->getdados()->getcodbarras())
            {
                ptr=ptr->getfd();
            }
            else
            {
                break;
            }
        }
    }

    if(ptr==nulo)
    {
        return nullptr;
    }
    Item* copia;
    copia=ptr->getdados();

    return copia;
}

No* tree::pesq(Item *obj)
{
    No * aux = raiz;
    while(aux != nulo)
    {
        if(obj->getcodbarras()<aux->getdados()->getcodbarras())
        {
            aux = aux->getfe();
        }
        else
        {
            if(obj->getcodbarras()>aux->getdados()->getcodbarras())
            {
                aux = aux->getfd();
            }
            else
            {
                break;
            }
        }
    }

    return aux;
}

void tree::mostrarordem(No* pNo,std::string &aux)const
{
    if(pNo!=nulo)
    {
        mostrarordem(pNo->getfe(),aux);
        aux+=pNo->getdados()->gettudo()+"\n"; //ou getitem no lugar de gettudo
        mostrarordem(pNo->getfd(),aux);
    }
}

void tree::mostrarordem(std::string &aux)const
{
    if(raiz==nulo)
    {
        puts("Nada encontrado!");
    }
    mostrarordem(raiz,aux);
}

void tree::mostrarpreordem(No* pNo,std::string &aux)const
{
    if(pNo!=nulo)
    {
        aux+=pNo->getdados()->gettudo()+"\n"; //ou getitem no lugar de gettudo
        mostrarpreordem(pNo->getfe(),aux);
        mostrarpreordem(pNo->getfd(),aux);

    }
}

void tree::mostrarpreordem(std::string &aux)const
{
    if(raiz==nulo)
    {
        puts("Nada encontrado!");
    }
    mostrarpreordem(raiz,aux);
}

void tree::mostrarposordem(std::string &aux)const
{
   if(raiz==nulo)
   {
       puts("Nada encontrado!");
   }
   mostrarposordem(raiz,aux);
}

void tree::mostrarposordem(No* pNo,std::string &aux)const
{
    if(pNo!=nulo)
    {
        mostrarposordem(pNo->getfe(),aux);
        mostrarposordem(pNo->getfd(),aux);
        aux+=pNo->getdados()->gettudo()+"\n"; //ou getitem no lugar de gettudo
    }
}

bool tree::vazia()
{
    return (raiz==nulo);
}

No* tree::minima(No *pno)
{
    if(pno== nulo)
    {
        return nulo;
    }
    No *aux=nulo;
    while(aux->getfe()!=nulo)
    {
        aux=aux->getfe();
    }
    return aux;
}

No* tree::maximo(No *pno)
{
    if(pno==nulo)
    {
        return nulo;
    }
    No *aux=nulo;
    while(aux->getfd()!=nulo)
    {
        aux=aux->getfd();
    }
    return aux;
}

No* tree::antecessor(No *pno)
{
    if(pno==nulo)
    {
        return nulo;
    }
    if(pno->getfe()!=nulo)
    {
        return maximo(pno->getfe());
    }
    No *aux=pno->getpai();
    No *an= aux;
    while(aux->getfe()==an && aux!=nulo)
    {
        an=aux;
        aux=aux->getpai();
    }
    return aux;
}

No* tree::sucessor(No *pno)
{
    if(pno->getfd()!=nulo)
    {
        return minima(pno->getfd());
    }
    No *aux=pno->getpai();
    No *an=aux;
    while (aux->getfd()==an && aux!=nulo)
    {
        an=aux;
        aux=aux->getpai();
    }
    return aux;
}

void tree::testaIntegridade(No *p, std::string &aux)
{
    if(p==nulo || p == 0)
    {
        return;
    }
    if(p->getfe() != nulo)
    {
        if(p->getdados()->getcodbarras() < p->getfe()->getdados()->getcodbarras())
        {
            aux = aux + " Erro!! Pai: \n"+p->getdados()->gettudo();
            aux = aux + " menor que filho à esquerda: \n"+p->getfe()->getdados()->gettudo();
        }
    }
    if(p->getfd() != nulo)
    {
        if(p->getdados()->getcodbarras() > p->getfd()->getdados()->getcodbarras())
        {
            aux = aux + " Erro!! Pai: \n"+p->getdados()->gettudo();
            aux = aux + " maior que filho à direita: \n"+p->getfd()->getdados()->gettudo();
        }
    }
    testaIntegridade(p->getfe(),aux);
    testaIntegridade(p->getfd(),aux);
}

void tree::rotacao_esquerda(No *node)
{
    No *pai = node->getpai();
    No *aux = node->getfd();

    if(pai->getfd() == node)
    {
        pai->setfd(aux);
        node->setpai(aux);
        node->setfd(aux->getfe());
        aux->setfe(node);
    }else
    {
        pai->setfe(aux);
        node->setpai(aux);
        node->setfd(aux->getfe());
        aux->setfe(node);

    }
}

void tree::rotacao_direita(No *node)
{
    No *pai = node->getpai();
    No *aux = node->getfe();

    if(pai->getfd() == node)
    {
        pai->setfd(aux);
        node->setpai(aux);
        node->setfe(aux->getfd());
        aux->setfd(node);

    }else
    {
        pai->setfe(aux);
        node->setpai(aux);
        node->setfe(aux->getfd());
        aux->setfd(node);
    }
}

void tree::corrigir_violacao(No *node, No *root)
{
    No *pai = NULL;
    No *vo = NULL;
    puts("Erro aqui");
    while ((node != root) && (node->getCor() != BLACK) && (node->getpai()->getCor() == RED))
    {        
        pai = vo->getpai();
        vo = vo->getpai()->getpai();

        if (pai == vo->getfe())
        {

            No *tio = vo->getfd();
            if (tio != NULL && tio->getCor() == RED)
            {
                vo->setCor(RED);
                pai->setCor(BLACK);
                tio->setCor(BLACK);
                node = vo;
            }
            else
            {
                if (node == vo->getfd())
                {
                    rotacao_esquerda(pai);
                    node = pai;
                    pai = node->getpai();
                }

                rotacao_direita(vo);
                bool cor = pai->getCor();
                pai->setCor(vo->getCor());
                vo->setCor(cor);



                node = pai;
            }
        }

        else
        {
            No *tio = vo->getfe();

            if ((tio != NULL) && (tio->getCor() == RED))
            {
                vo->setCor(RED);
                pai->setCor(BLACK);
                tio->setCor(BLACK);
                node = vo;
            }
            else
            {

                if (node == pai->getfe())
                {
                    rotacao_direita(pai);
                    node = pai;
                    pai = node->getpai();
                }

                rotacao_esquerda(vo);
                bool cor = pai->getCor();
                pai->setCor(vo->getCor());
                vo->setCor(cor);

                node = pai;
            }
        }
    }


}
