#include "../Headers/ListaOrdenadaC.h"
#include <iostream>

using namespace std;

ListaOrdenadaC::ListaOrdenadaC(int tam)
{
    max = tam;
    n = 0;
    vet = new int[max];
}

ListaOrdenadaC::~ListaOrdenadaC()
{
    delete [] vet;
}

int ListaOrdenadaC::get(int k){
    if(k>=0 && k<=n) //garante que o no k pedido existe um nó preenchido
    {
        return vet[k];
    }
    cout<<"Posição inválida"<< endl;
    exit(1);
}
    
void ListaOrdenadaC::inserir(int val){
    int i;
    if(n == max){
        cout<<"aumentando capacidade"<<endl;
        aumentaCapacidade();
    }
    for(i = n-1; i>=0 && vet[i]>=val; i--){
        vet[i+1]=vet[i];
    }
    vet[i+1]=val;
    n= n+1;
}

void ListaOrdenadaC::removerK(int k){
    if(k>=0 && k<n){
        for(int i = k; i<n; i++){
            vet[i]= vet[i+1];
        }
        n--;
        cout<<"Indice<<"<< k <<"removido com sucesso"<<endl;
    }
    else{
        cout<<"Posicao invalida"<<endl;
    }

}

void ListaOrdenadaC::removerVal(int val){
    int indice = buscaBinaria(val);
    while (indice>=0 && indice<n){
        removerK(indice);
        indice = buscaBinaria(val);
    }

    cout<< "Nada a remover, a Lista ficou: "<<endl;
    imprime();
}
    
void ListaOrdenadaC::imprime(){
    cout<<"Lista Ordenada: ";
    for(int i=0;i<n;i++){
        cout<<vet[i]<<" ";
    }
    cout<<endl;
}

void ListaOrdenadaC::aumentaCapacidade(){
    int *temp = new int[max*2];
    for(int i=0;i<max;i++){
        temp[i]=vet[i];
    }
    delete [] vet;
    vet= temp;
    max *= 2;
}

int ListaOrdenadaC::buscaBinaria(int val){
    int esq = 0; //Índice da extrema esquerda
    int dir = n-1; //Índice da extrema direita
    while(esq>=dir){
        int meio = (esq+dir)/2;
        if(val> vet[meio]){
            esq= meio +1;
        }
        if(val< vet[meio]){
            dir= meio -1;
        }
        else{
            return meio;
        }
    }
    return -1;
}