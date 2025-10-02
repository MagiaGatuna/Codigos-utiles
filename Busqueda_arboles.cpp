#include <iostream>
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

bool busquedaBFS(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado){ 
        return encontrado;
    }
    queue<Nodo*> cola;
    cola.push(nodo);

    while(!cola.empty()){
        Nodo* nodoActual=cola.front();
        cola.pop();
        
        if(nodoActual->valor==M){
            encontrado=true; 
            return true; 
        }

        if (!encontrado) {
            if(nodoActual->izquierda!=NULL){
                cola.push(nodoActual->izquierda);
            }
            if(nodoActual->derecha != NULL){
                cola.push(nodoActual->derecha);
            }
        }
    }
    return encontrado;
}

bool busquedaDFS_PreOrden(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado){
        return encontrado;
    }
    if(nodo->valor==M) encontrado=true; 
    busquedaDFS_PreOrden(nodo->izquierda, encontrado, M); 
    busquedaDFS_PreOrden(nodo->derecha, encontrado, M); 
    return encontrado;
}

bool busquedaDFS_InOrden(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado){
        return encontrado;
    }
    busquedaDFS_InOrden(nodo->izquierda, encontrado, M); 
    if(nodo->valor==M) encontrado=true;
    busquedaDFS_InOrden(nodo->derecha, encontrado, M); 
    return encontrado;
}

bool busquedaDFS_PostOrden(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado){
        return encontrado;
    }
    busquedaDFS_PostOrden(nodo->izquierda, encontrado, M); 
    busquedaDFS_PostOrden(nodo->derecha, encontrado, M); 
    if(nodo->valor==M) encontrado=true;
    return encontrado;
}

bool busquedaDFS_PreOrden_I(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado){
        return encontrado;
    }
    stack<Nodo*>pila;
    pila.push(nodo);
    while(!pila.empty()){
        Nodo* nodoActual=pila.top();
        pila.pop();
        if(nodoActual->valor==M){
            encontrado=true; 
            return encontrado; 
        }
        if(nodoActual->derecha!=NULL){
            pila.push(nodoActual->derecha);
        }
        if(nodoActual->izquierda!=NULL){
            pila.push(nodoActual->izquierda);
        }
    }
    return encontrado;
}

bool busquedaDFS_InOrden_I(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado){
        return encontrado;
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
        if(nodoActual->valor==M){
            encontrado=true;
            return encontrado;
        }
        nodoActual=nodoActual->derecha;
    }
        return encontrado;
    
}

bool busquedaDFS_PostOrden_I(Nodo* nodo, bool& encontrado, int M){
    if(nodo==NULL||encontrado) {
        return encontrado;
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
        if(nodoActual->valor == M){
            encontrado=true; 
            return encontrado;  
        }
    }
    return encontrado;
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
