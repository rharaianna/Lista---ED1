#include "../Headers/ListaOrdenadaE.h"
#include <iostream>
using namespace std;


ListaOrdenadaE::ListaOrdenadaE()
{
    primeiro = NULL;
}

ListaOrdenadaE::~ListaOrdenadaE()
{
    No*p = primeiro;
    while(p!=NULL){
        No *t = p->getProx();
        delete p;
        p = t;
    }
}


void ListaOrdenadaE::insere(int val){
    No *p = new No ();
    No *ant = NULL;
    No *atual = primeiro;

    p->setInfo(val);

    while(atual!=NULL && val>=atual->getInfo()){
        ant = atual;
        atual = atual->getProx();
    }

    if(ant == NULL){
        p->setProx(primeiro);
        primeiro = p;
    }

    else{
        ant->setProx(p);
        p->setProx(atual);
    }

}
void ListaOrdenadaE::remove(int val){

}
int ListaOrdenadaE::busca (int val){

}

void ListaOrdenadaE::insereK(int k){

}
void ListaOrdenadaE::removeK(int k){

}
int ListaOrdenadaE::buscaK (int k){
    
}


void ListaOrdenadaE::imprime(){

}