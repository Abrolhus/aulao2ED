#include <iostream>
#include <cstdlib>
#include "ListaCont.h"

using namespace std;

ListaCont::ListaCont (int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaCont::~ListaCont ()
{
    delete [] vet;
}

void ListaCont::insereFinal (int val)
{
    if (n == max)
    {
        cout << "ERRO: Vetor Cheio!" << endl;
        exit (1);
    }
    vet[n] = val;
    n = n + 1;
}

void ListaCont::imprime ()
{
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << vet[i];
        if (i + 1 < n)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// ----------------------------------------------------------------------------
//Q2

bool ListaCont::insereIntervalo(int a, int b)
{//a <= b
    // Implemente aqui a sua solução para a questão 2.
    // Se necessário, remova o código abaixo.

    bool alterouMax = false;
    int totalAdicionais = b - a + 1;
    if(totalAdicionais > max-n)
    {
        max = max + totalAdicionais;
        alterouMax = true;

        int *novoVet = new int[max];
        for(int i = 0; i < n; i++)
        {
            novoVet[i] = vet[i];
        }
        delete [] vet;
        vet = novoVet;
    }

    for(int i = a; i <= b; i++)
    {
        //insereFinal(i);
        // OU
        vet[n] = i;
        n++;
    }

    return alterouMax;
}
//-Q2
// ----------------------------------------------------------------------------
