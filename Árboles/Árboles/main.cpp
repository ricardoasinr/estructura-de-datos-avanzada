//
//  main.cpp
//  Árboles
//
//  Created by Ricardo Asin on 18/2/23.
//

#include <iostream>
#include "Nodo.hpp"
#include "Arbol.hpp"
#include <string>
using namespace std;
void menu();

int main(int argc, const char * argv[]) {
    int op;
        //system("color 0b");
        Arbol a1, a2, a3, a4, a;
        Nodo* n1, * n2, * n3, * n4;

        do
        {
            menu();
            cin >> op;
            switch (op)
            {
            case 1:
                /*
                            n1 = a1.nuevoArbol(NULL, 0, NULL);
                            n2 = a2.nuevoArbol(NULL, 1, NULL);
                            n3 = a3.nuevoArbol(n1, 2, n2);
                            n1 = a1.nuevoArbol(NULL, 3, NULL);
                            n2 = a2.nuevoArbol(NULL, 4, NULL);
                            n4 = a4.nuevoArbol(n1, 5, n2);
                            n1 = a1.nuevoArbol(n3, 6, n4);
                */

                /*
                            n1 = a1.nuevoArbol(NULL, "Maria", NULL);
                            n2 = a2.nuevoArbol(NULL, "Rodrigo", NULL);
                            n3 = a3.nuevoArbol(n1, "Esperanza", n2);
                            n1 = a1.nuevoArbol(NULL, "Anyora", NULL);
                            n2 = a2.nuevoArbol(NULL, "Abel", NULL);
                            n4 = a4.nuevoArbol(n1, "M Jesus", n2);
                            n1 = a1.nuevoArbol(n3, "Esperanza", n4);
                */
                n1 = a1.nuevoArbol(NULL, "A", NULL);
                n2 = a2.nuevoArbol(NULL, "B", NULL);
                n3 = a3.nuevoArbol(n1, "C", n2);
                n1 = a1.nuevoArbol(NULL, "D", NULL);
                n2 = a2.nuevoArbol(NULL, "E", NULL);
                n4 = a4.nuevoArbol(n1, "F", n2);
                n1 = a1.nuevoArbol(n3, "G", n4);

                a.Praiz(n1);
                a.esVacio();
                cout << "Hemos creado el arbol\n";
                cout << "Cualquier tecla para continuar...\n";
                break;
            case 2:
                cout << "Que elementos insertaremos?\n";
                cout << "Cualquier tecla para continuar...\n";
                break;
            case 3:
                cout << "El arbol recorrido en pre orden se ve asi\n";
                a.preorden();
                cout << "Cualquier tecla para continuar...\n";
                break;
            case 4:
                cout << "El arbol recorrido en entre orden se ve asi\n";
                a.inorden();
                cout << "Cualquier tecla para continuar...\n";
                break;
            case 5:
                cout << "El arbol recorrido en post orden se ve asi\n";
                a.postorden();
                cout << "Cualquier tecla para continuar...\n";
                break;
            case 6:
                if (a.esVacio())
                {
                    cout << "El arbol esta vacio\n";
                }
                else
                {
                    cout << "El arbol no esta vacio\n";
                }
                break;
            case 7:
                if (a.esVacio())
                {
                    cout << "El arbol esta vacio\n";
                }
                else
                {
                    cout << "La raiz del arbol es:\n";
                    a.raizArbol();
                    a.raizArbol().visitar();
                }
                break;
            }
          
        } while (op != 0);
  


 
    
    return 0;
    

}
void menu(){
    cout << "\n\tTRABAJANDIO CON ARBOLES:\n\n";
    cout << "1.- Crear el arbol" << endl;
    cout << "2.- Insertar nodos en el arbol" << endl;
    cout << "3.- Recorrido en preorden" <<endl;
    cout << "4.- Recorrido en entre orden" << endl;
    cout << "5.- Recorrido en post orden" << endl;
    cout << "6.- Esta vacio el arbol?" << endl;
    cout << "7.- Cual es la raiz del arbol?" << endl;
    cout << "0.- Salir" << endl;
    cout << "\n INGRESE OPCION: ";
    }
