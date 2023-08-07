//
//  Nodo.hpp
//  Árboles
//
//  Created by Ricardo Asin on 18/2/23.
//

#ifndef Nodo_hpp
#define Nodo_hpp

#include <stdio.h>
#include <string>

using namespace std;

typedef string tipoElemento;


class Nodo {
protected:
    tipoElemento dato;
    Nodo* izquierdo;
    Nodo* derecho;
    
public:
    Nodo(tipoElemento valor){
        dato = valor;
        izquierdo = derecho = NULL;
    }
    Nodo(Nodo* ramaIzquierda, tipoElemento valor, Nodo* ramaDerecha){
        dato = valor;
        izquierdo = ramaIzquierda;
        derecho = ramaDerecha;
    };
    
    tipoElemento valorNodo();
    Nodo* subirArbolIzquierdo();
    Nodo* subirArbolDerecho();
    
    void nuevoValor(tipoElemento d);
    void ramaIzquierda(Nodo* n);
    void ramaDerecha(Nodo* n);
    void visitar();
    
    
    
    
    
    
    
};

#endif /* Nodo_hpp */
