#include <iostream>
#include <cstdlib>
#include "ListaEncad.h"

using namespace std;

ListaEncad::ListaEncad ()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad ()
{
    // OMITIDO
}

void ListaEncad::insereInicio(int val)
{
    No *novo = new No ();
    novo->setInfo (val);
    novo->setProx (primeiro);
    primeiro = novo;
}

void ListaEncad::imprime ()
{
    cout << "[";
    for (No *p = primeiro; p != NULL; p = p->getProx ())
    {
        cout << p->getInfo ();
        if (p->getProx () != NULL)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q4

void ListaEncad::removeBloco(int a, int b)
{
    // Implemente aqui a sua solução para a questão 3.
    No *p = primeiro;
    No *ant = NULL;
    while(p != NULL && p->getInfo() != a)
    {
        ant = p;
        p = p->getProx();
    }

    if(p != NULL)
    {
        while(p != NULL && p->getInfo() != b)
        {
            No *t = p->getProx();
            delete p;
            p = t;
        }

        if(p != NULL)
        {
            if(ant == NULL)
                primeiro = p->getProx();
            else
                ant->setProx( p->getProx() );
            delete p;
        }
        else
        {
            if(ant != NULL)
                ant->setProx(NULL);
            else
                primeiro = NULL;
        }
    }

    // SE FOR ENTRE A E B MANTENDO OS EXTREMOS DO BLOCO

//    No *pA = primeiro;
//    while(pA != NULL && pA->getInfo() != a)
//    {
//        pA = pA->getProx();
//    }
//
//    if(pA != NULL)
//    {
//        No *pB = pA->getProx();
//        while(pB != NULL && pB->getInfo() != b)
//        {
//            No *t = pB->getProx();
//            delete pB;
//            pB = t;
//        }
//
//        pA->setProx(pB);
//    }
}

//-Q4
// ----------------------------------------------------------------------------
