#ifndef LISTAORDENADAE_H
#define LISTAORDENADAE_H
#include "No.h"
#pragma once

class ListaOrdenadaE
{
public:
    ListaOrdenadaE();
    ~ListaOrdenadaE();
    void insere(int val);
    void remove(int val);
    int busca (int val); //vai retornar o k

    void insereK(int k);
    void removeK(int k);
    int buscaK (int k); //vai retornar o val


    void imprime();

private:
    No *primeiro;
};

#endif