//
//  main.cpp
//  Punteros
//
//  Created by Ricardo Asin on 11/2/23.
//

#include <iostream>
using namespace std;
void mostrar(int vector[], int tamano);
void ordenar_mayor(int vec[], int ta);
void ordenar_menor(int vector_[], int tamano_);


int main(int argc, const char * argv[]) {
    // insert code here...
    int t;
       int n;
       
       
       cout << "Ingrese tamano del vector " << endl;
       cin >> t;
       int *V, r;

       V = new  int[t];
       for (int i = 0; i < t; i++)
       {
           cout << "Vector " << "[" << i << "]: " << endl;
           cout << "Ingrese dato" << endl;
           cin >> r;
           V[i] = { r };
       }

       cout << "Ordenado mayor-menor" << endl;
       ordenar_mayor(V, t);
       cout << "El mayor numero es: " << V[0] << endl;
       cout << "El menor numero es: " << V[t-1] << endl;
    mostrar(V, t);


    
    return 0;
}



void mostrar(int vector[], int tamano)
{
    
    for (int i = 0; i < tamano; i++)
    {
        cout << "Vector " << "[" << i << "] " << ": " << vector[i] << endl;
    }

}

void ordenar_mayor(int vec[], int ta) {
    float temporal;
    for (int i = 0; i < ta; i++) {
        for (int j = 0; j < ta - 1; j++) {
            if (vec[j] < vec[j + 1]) {
                temporal = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temporal;
            }
        }
    }
}

void ordenar_menor(int vector_[], int tamano_) {
        float temporal;

        for (int i = 0; i < tamano_; i++) {
            for (int j = 0; j < tamano_ - 1; j++) {
                if (vector_[j] > vector_[j + 1]) {
                    temporal = vector_[j];
                    vector_[j] = vector_[j + 1];
                    vector_[j + 1] = temporal;
                    }
                }
            }
}


