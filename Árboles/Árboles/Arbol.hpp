//
//  Arbol.hpp
//  Árboles
//
//  Created by Ricardo Asin on 18/2/23.
//

#ifndef Arbol_hpp
#define Arbol_hpp

#include <stdio.h>
#include "Nodo.hpp"
#include <iostream>
#include <string>
using namespace std;
typedef string tipoElemento;


class Arbol {
protected:
    Nodo* raiz;
public:
    //Constructuroes
    Arbol();
    Arbol(Nodo* r);
    
    //Métodos
    void Praiz(Nodo* r);
    Nodo* Oraiz();
    Nodo raizArbol();
    bool esVacio();
    Nodo* hijoIzdo();
    Nodo* hijoDcho();
    Nodo* nuevoArbol(Nodo* ramaIzqda, tipoElemento dato, Nodo* ramaDrcha);
    // recorrido en preorden
    void preorden();
    // recorrido en ineorden
    void inorden();
    // recorrido en postorden
    void postorden();
    
private:
    // Recorrido de un árbol binario en preorden
    void preorden(Nodo* r);
    // Recorrido de un árbol binario en inorden
    void inorden(Nodo* r);
    // Recorrido de un árbol binario en postorden
    void postorden(Nodo* r);
};


#endif /* Arbol_hpp */
