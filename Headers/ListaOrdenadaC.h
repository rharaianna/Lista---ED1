#ifndef LISTAORDENADAC_H
#define LISTAORDENADAC_H

#pragma once

class ListaOrdenadaC
{
public:
    ListaOrdenadaC(int tam);
    ~ListaOrdenadaC();

    int get(int k);
    void inserir(int val);
    void removerK(int k);
    void removerVal(int val);
    void imprime();
    bool busca(int val);

private:
    int max; //Capacidade máxixa
    int n;   //Número de nós
    int *vet; //ponteiro que será direcionado para o vetor que armazena a lista
    void aumentaCapacidade();
    int buscaBinaria(int val);
};

#endif