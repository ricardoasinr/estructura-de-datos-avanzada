//
//  Arbol.cpp
//  Árboles
//
//  Created by Ricardo Asin on 18/2/23.
//

#include "Arbol.hpp"
#include <iostream>
#include <string>
using namespace std;
typedef string tipoElemento;

Arbol::Arbol (void) {
    
}

void Arbol::Praiz(Nodo* r)
    {
        raiz = r;
    }
    Nodo* Arbol::Oraiz()
    {
        return raiz;
    }
    Nodo Arbol::raizArbol()
    {
        if (raiz)
            return *raiz;
        else
            throw " arbol vacio";
          //  cout << " arbol vacio"<<endl;
    }
    bool Arbol::esVacio()
    {
        return raiz == NULL;
        //cout << " arbol vacio"<<endl;
    }
    Nodo* Arbol::hijoIzdo()
    {
        if (raiz)
            return raiz->subirArbolIzquierdo();
        else
            throw " arbol vacio";
          //  cout << " arbol vacio"<<endl;
        

    }
    Nodo* Arbol::hijoDcho()
    {
        if (raiz)
            return raiz->subirArbolDerecho();
        else
            throw " arbol vacio";
        //cout << " arbol vacio"<<endl;
    }
    Nodo* Arbol::nuevoArbol(Nodo* ramaIzqda, tipoElemento dato, Nodo* ramaDrcha)
    {
        return new Nodo(ramaIzqda, dato, ramaDrcha);
    }
    // recorrido en preorden
    void Arbol::preorden()
    {
        Arbol::preorden(raiz);
    }
    // recorrido en ineorden
    void Arbol::inorden()
    {
        Arbol::inorden(raiz);
    }
    // recorrido en postorden
    void Arbol::postorden()
    {
        Arbol::postorden(raiz);
    }

    // Recorrido de un árbol binario en preorden
    void Arbol::preorden(Nodo* r)
    {
        if (r != NULL)
        {
            r->visitar();
            preorden(r->subirArbolIzquierdo());
            preorden(r->subirArbolDerecho());
        }
    };
    // Recorrido de un árbol binario en inorden
    void Arbol::inorden(Nodo* r)
    {
        if (r != NULL)
        {
            inorden(r->subirArbolIzquierdo());
            r->visitar();
            inorden(r->subirArbolDerecho());
        }
    }
    // Recorrido de un árbol binario en postorden
    void Arbol::postorden(Nodo* r)
    {
        if (r != NULL)
        {
            postorden(r->subirArbolIzquierdo());
            postorden(r->subirArbolDerecho());
            r->visitar();
        }
    }

