#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <stdint.h> 

using namespace std;

struct Nodo{
    int valor;
    Nodo* izquierda;
    Nodo* derecha;


    Nodo(int val=INT32_MIN){
        valor=val;
        izquierda=NULL;
        derecha=NULL;
    }

};

void DeleteArbol(Nodo* nodo){
    if(nodo==NULL){
        return;
    }
    DeleteArbol(nodo->izquierda);
    DeleteArbol(nodo->derecha);
    delete nodo;
}

void RecorridoBFS(Nodo* nodo){
    if(nodo==NULL){
        return;
    }
    queue<Nodo*> cola;
    cola.push(nodo);

    while(!cola.empty()){
        Nodo* nodoActual=cola.front();
        cola.pop();
        
        cout << nodoActual->valor << " ";

        if(nodoActual->izquierda!=NULL){
            cola.push(nodoActual->izquierda);
        }
        if(nodoActual->derecha != NULL){
            cola.push(nodoActual->derecha);
        }
    }
    cout << endl;
}


void RecorridoDFS_PreOrden(Nodo* nodo){
    if(nodo==NULL){
        return;
    }

    cout << nodo->valor << " "; 
    
    RecorridoDFS_PreOrden(nodo->izquierda); 
    
    RecorridoDFS_PreOrden(nodo->derecha); 
}

void RecorridoDFS_InOrden(Nodo* nodo){
    if(nodo==NULL){
        return;
    }

    RecorridoDFS_InOrden(nodo->izquierda); 

    cout << nodo->valor << " "; 
A
    RecorridoDFS_InOrden(nodo->derecha); 
}


void RecorridoDFS_PostOrden(Nodo* nodo){
    if(nodo==NULL){
        return;
    }

    RecorridoDFS_PostOrden(nodo->izquierda); 

    RecorridoDFS_PostOrden(nodo->derecha); 

    cout << nodo->valor << " ";
}


void RecorridoDFS_PreOrden_I(Nodo* nodo){
    if(nodo==NULL){
        return;
    }
    stack<Nodo*>pila;
    pila.push(nodo);
    
    while(!pila.empty()){
        Nodo* nodoActual=pila.top();
        pila.pop();
        
        cout << nodoActual->valor << " ";
        
        if(nodoActual->derecha!=NULL){
            pila.push(nodoActual->derecha);
        }

        if(nodoActual->izquierda!=NULL){
            pila.push(nodoActual->izquierda);
        }
    }
    cout << endl;
}

void RecorridoDFS_InOrden_I(Nodo* nodo){
    if(nodo==NULL){
        return;
    }
    stack<Nodo*> pila;
    Nodo* nodoActual=nodo;
    
    while(nodoActual!=NULL||!pila.empty()){
        
        while(nodoActual!=NULL){
            pila.push(nodoActual);
            nodoActual=nodoActual->izquierda;
        }
        
        nodoActual=pila.top();
        pila.pop();
        cout << nodoActual->valor << " ";
        
        nodoActual=nodoActual->derecha;
    }
    cout << endl;
}


void RecorridoDFS_PostOrden_I(Nodo* nodo){
    if(nodo==NULL) {
        return;
    }

    stack<Nodo*> pila1; 
    stack<Nodo*> pila2; 
    pila1.push(nodo);
    

    while(!pila1.empty()){
        Nodo* nodoActual=pila1.top();
        pila1.pop();
        pila2.push(nodoActual); 
        
        if (nodoActual->izquierda!=NULL){
            pila1.push(nodoActual->izquierda);
        }
        if (nodoActual->derecha!=NULL){
            pila1.push(nodoActual->derecha);
        }
    }
    

    while(!pila2.empty()){
        Nodo* nodoActual=pila2.top();
        pila2.pop();
        cout << nodoActual->valor << " ";
    }
    cout << endl;
}



void crearArbol(Nodo* &nodo, int N){
    if(N<0){
        nodo=NULL;
        return;
    }

    nodo=new Nodo(rand() % 1000 + 1);
    if(N==0){
        return;
    }
    queue<Nodo*> cola;
    cola.push(nodo);
    int nivelActual=0;
    while(nivelActual<N){
        int nodosEnElNivel=cola.size();
        for(int i=0; i<nodosEnElNivel; i++){
            Nodo* nodoActual=cola.front();
            cola.pop();
            
            nodoActual->izquierda=new Nodo(rand()%1000+1);
            cola.push(nodoActual->izquierda);

            nodoActual->derecha=new Nodo(rand()%1000+1);
            cola.push(nodoActual->derecha);
        }
        nivelActual++;
    }
}