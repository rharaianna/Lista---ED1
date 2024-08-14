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
    No *ant = NULL;
    No *atual = primeiro;

    while(atual!= NULL && val != atual->getInfo()){
        ant= atual;
        atual = atual->getProx();
    }

    if(ant == NULL){
        cout<<"Lista vazia, nada a remover"<< endl;
    }
    
    else{
        ant->setProx(atual->getProx());
        delete atual;
        cout<<"Removido com sucesso!"<< endl;
    }
    imprime();
}


int ListaOrdenadaE::busca (int val){
    No *procura = primeiro;
    int contador = 0;
    while(procura != NULL){
        if(procura->getInfo()== val){
            return contador;
        }
        contador ++;
        procura = procura->getProx();
    }
    return -1;
}


void ListaOrdenadaE::removeK(int k){
    No *ant = NULL;
    No *atual = primeiro;
    int contador = 0;
    while (contador<=k && atual!=NULL){
        ant = atual;
        atual = atual->getProx();
        contador++;
    }
    if (atual == NULL){
        cout<<"Posição não encontrada na lista"<< endl;
    }
    else{
        ant = atual->getProx(); // e se for o penultimo da lista?
        delete atual;
        cout<<"Posição removida"<< endl;
        imprime();
    }
}

int ListaOrdenadaE::buscaK (int k){
    No *ant = NULL;
    No *atual = primeiro;
    int contador = 0;
    while (contador<=k && atual!=NULL){
        ant = atual;
        atual = atual->getProx();
        contador++;
    }
    if (ant == NULL){
        cout<<"Lista Vazia"<< endl;
        return -1; 
    }
    else if (atual == NULL){
        cout<<"Posição não encontrada na lista"<< endl;
        return -1;
    }
    else{
        cout<<"Posição encontrada na lista"<< endl;
        return atual->getInfo();
    }

}

void ListaOrdenadaE::imprime(){
    cout<<"Lista: ";
    for(No*p = primeiro; p!=NULL; p = p->getProx()){
        cout<<p->getInfo()<<" ";
    }
    cout<<endl;
}