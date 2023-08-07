//
//  Grafos.h
//  Grafos
//
//  Created by Ricardo Asin on 24/3/23.
//

#ifndef Grafos_h
#define Grafos_h
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Definición de la clase Nodo/Vértice
class Nodo {
    int valor;
    bool visitado;
    vector<Nodo*> vecinos;
    
public:
    Nodo(int val) {
        valor = val;
        visitado = false;
    }
    
    friend class Grafo;
};

// Definición de la clase Grafo
class Grafo {
    vector<Nodo*> nodos;
    
public:
    // Creación del grafo
    Grafo() {}
    
    
    Nodo* escogerDondeInicia() {
        int inicio;
        do{
            cout<<"Digitar la posición del nodo de donde se quiere iniciar"<<endl;
            cout<<"Tiene que ser menor o igual a "<<nodos.size()-1<<endl;
            cin>>inicio;
        }while(inicio> nodos.size() || inicio < 0);
        
        return nodos[inicio];
    }
    
    // Agregar un nodo al grafo
    void agregarNodo(int val) {
        Nodo* nuevoNodo = new Nodo(val);
        nodos.push_back(nuevoNodo);
    }
    
    // Agregar una arista entre dos nodos del grafo
    void agregarArista(int i, int j) {
        nodos[i]->vecinos.push_back(nodos[j]);
        nodos[j]->vecinos.push_back(nodos[i]);
    }
    
    // Llenado del grafo
    void llenarGrafo() {
        int n;
        cout << "Ingrese el número de nodos o vértices: ";
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            int val;
            cout << "Ingrese el valor del nodo o vértice posición [" << i << "]: ";
            cin >> val;
            agregarNodo(val);
        }
        cout<<"------------------------------------------"<<endl;

        int m;
        cout << "Ingrese el número de aristas: ";
        cin >> m;
        
        for (int i = 0; i < m; i++) {
            int u, v;
            cout << "Arista " << i+1<< ": "<<endl;
            cout<<"Inicia en: ";
            cin >> u;
            cout<<"Se dirige a: ";
            cin>> v;
            cout<<"------------------------------------------"<<endl;
            agregarArista(u, v);
        }
        cout<<"------------------------------------------"<<endl;

    }
    
    void reiniciarNodos() {
        for (Nodo* nodo : nodos) {
            nodo->visitado = false;
        }
    }
    
    // Recorrido del grafo en amplitud (BFS)
    void amplitud(Nodo* inicio) {
        reiniciarNodos();
        queue<Nodo*> cola;
        inicio->visitado = true;
        cola.push(inicio);
        
        while (!cola.empty()) {
            Nodo* actual = cola.front();
            cola.pop();
            cout << actual->valor << " ";
            
            for (Nodo* vecino : actual->vecinos) {
                if (!vecino->visitado) {
                    vecino->visitado = true;
                    cola.push(vecino);
                }
            }
        }
        
        cout << endl;
    }
    
    // Recorrido del grafo en profundidad (DFS)
    void profundidad(Nodo* inicio) {
        reiniciarNodos();
        stack<Nodo*> pila;
        pila.push(inicio);
        
        while (!pila.empty()) {
            Nodo* actual = pila.top();
            pila.pop();
            
            if (!actual->visitado) {
                actual->visitado = true;
                cout << actual->valor << " ";
                
                for (Nodo* vecino : actual->vecinos) {
                    pila.push(vecino);
                }
            }
        }
        
        cout << endl;
    }
    
    // Búsqueda de un elemento en el grafo
    bool buscar(int val) {
        for (Nodo* nodo : nodos) {
            if (nodo->valor == val) {
                return true;
            }
        }
        
        return false;
    }
};




#endif /* Grafos_h */
