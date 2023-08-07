//
//  Nodo.cpp
//  Árboles
//
//  Created by Ricardo Asin on 18/2/23.
//

#include "Nodo.hpp"
#include <iostream>

#include <string>

using namespace std;
typedef string tipoElemento;

tipoElemento Nodo::valorNodo(){
    return dato;
}
Nodo* Nodo::subirArbolIzquierdo(){
    return izquierdo;
}
Nodo* Nodo::subirArbolDerecho(){
    return  derecho;
}

void Nodo::nuevoValor(tipoElemento d){
    dato = d;
}
void Nodo::ramaIzquierda(Nodo* n){
    izquierdo = n;
}
void Nodo::ramaDerecha(Nodo* n){
    derecho =n;
}
void Nodo::visitar(){
    cout<<"Dato: "<<dato<<endl;
}
