//
//  main.cpp
//  Grafos
//
//  Created by Ricardo Asin on 24/3/23.
//

#include <iostream>
#include "Grafos.h"

using namespace std;



int main(int argc, const char * argv[]) {

    
        Grafo g;
        g.llenarGrafo();
        Nodo* primerNodo = g.escogerDondeInicia();
    
        
        int opcion;
        do {
            cout << endl;
            cout<<"------------------------------------------"<<endl;
            cout << "1. Recorrido en amplitud (BFS)" << endl;
            cout << "2. Recorrido en profundidad (DFS)" << endl;
            cout << "3. Búsqueda de un elemento en el grafo" << endl;
            cout << "4. Salir" << endl;
            cout << "Ingrese una opción: "<<endl;
            cout<<"------------------------------------------"<<endl;
            cin >> opcion;
            
            switch (opcion) {
                case 1: {
                    cout<<"------------------------------------------"<<endl;
                    cout << "Recorrido del grafo en amplitud (BFS): ";
                      g.amplitud(primerNodo);
                    cout<<"------------------------------------------"<<endl;
                    break;
                }
                case 2: {
                    cout<<"------------------------------------------"<<endl;
                    cout << "Recorrido del grafo en profundidad (DFS): ";
                        g.profundidad(primerNodo);
                    cout<<"------------------------------------------"<<endl;
                    break;
                }
                case 3: {
                    int val;
                        cout << "Ingrese el valor a buscar: ";
                        cin >> val;
                        
                        if (g.buscar(val)) {
                            cout<<"------------------------------------------"<<endl;
                            cout << "El valor " << val << " se encuentra en el grafo." << endl;
                            cout<<"------------------------------------------"<<endl;
                        } else {
                            cout<<"------------------------------------------"<<endl;
                            cout << "El valor " << val << " no se encuentra en el grafo." << endl;
                            cout<<"------------------------------------------"<<endl;
                        }
                    break;
                }
                case 4: {
                    cout << "Saliendo del programa..." << endl;
                    break;
                }
                default: {
                    cout << "Opción inválida" << endl;
                    break;
                }
            }
        } while (opcion != 4);
        

    return 0;
}
