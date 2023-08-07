//
//  main.cpp
//  Arboles ordenados
//
//  Created by Ricardo Asin on 25/2/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Header.h"

using namespace std;

void menu(bool emptyTree){
    
    
    if(emptyTree==false){
        cout<<"--------------MENU--------------"<<endl;
        cout<<"4.Buscar un nodo en el árbol"<<endl;
        cout<<"5.Eliminar un nodo"<<endl;
        cout<<"6.Mostrar recorrido en pre-orden"<<endl;
        cout<<"7.Mostrar recorrido en entre-orden"<<endl;
        cout<<"8.Mostrar recorrido en post-orden"<<endl;
        cout<<"9.Verificar si esta balanceado"<<endl;
    }
    else {
        cout<<"--------------MENU--------------"<<endl;
        cout<<"Digitar una opción del menú"<<endl;
        cout<<"1.Introducir arbol NO balanceado"<<endl;
        cout<<"2.Introducir arbol balanceado"<<endl;
        cout<<"3.Introducir los primeros N números primos "<<endl;
    }
    cout<<"0.Digite '0' para salir"<<endl;
    cout<<"--------------------------------"<<endl;
  
}



int main() {
    
    int option;
    
    bool emptyTree = true;
 
    BinaryTree tree;
    int CantidadDeNumeros =0 ;
    int numero;
    int valorEliminar;
    int  fib = 0;
    int  aux = 1;
    int buscar;
    
    
    
    do{
        menu(emptyTree);
        cin>>option;
        switch (option) {
            case 1:
                cout<<"------------No balanceado------------"<<endl;
                cout<<"Cuantos números va a introducir?"<<endl;
                cin>>CantidadDeNumeros;
                for (int i = 1; i <= CantidadDeNumeros; i++) {
                    cout<<"Ingrese dato ["<<i<<"]: ";
                    cin>>numero;
                    tree.insert(numero);
                    emptyTree = false;
               
                }
                cout<<"\n"<<endl;
            
                break;
                
            case 2:
                cout<<"------------Balanceado------------"<<endl;
                cout<<"Cuantos números va a introducir?"<<endl;
                cin>>CantidadDeNumeros;
                for (int i = 1; i <= CantidadDeNumeros; i++) {
                    cout<<"Ingrese dato ["<<i<<"]: ";
                    cin>>numero;
                    //tree.insert(numero);
                    tree.insertBalancee(numero);
                    emptyTree = false;
                    
                    cout<<"\n"<<endl;
                  
               
                }
                
                break;
                
            case 3:
                cout<<"------------Fibonacci------------"<<endl;
                cout<<"\n"<<endl;
                cout<<"Cuantos números va a introducir?"<<endl;
                cin>>CantidadDeNumeros;
                for(int i = 1; i<= CantidadDeNumeros; i++){
                        aux += fib;
                        fib = aux - fib;
                    cout<<fib<<endl;
                        tree.insertBalancee(fib);
                            
                   }
                emptyTree = false;
                cout<<"\n"<<endl;
            
                
                break;
                
            case 4:
                cout<<"------------Buscar------------"<<endl;
                cout<<"Digite el nodo a buscar:"<<endl;
                cin>>buscar;
                tree.search( buscar);
                cout<<"\n"<<endl;
            
                break;
                
            case 5:
                cout<<"------------Eliminar------------"<<endl;
                cout<<"Que valor desea eliminar?"<<endl;
                cin>>valorEliminar;
                tree.eliminar(valorEliminar);
                cout<<"\n"<<endl;
                break;
                
            case 6:
                cout<<"\n"<<endl;
                cout << "Árbol binario en orden: ";
                    tree.inOrder();
                cout << endl;
                cout<<"\n"<<endl;
                break;
                
            case 7:
                cout<<"\n"<<endl;
                cout << "Árbol binario en orden: ";
                    tree.preOrder();
                cout << endl;
                cout<<"\n"<<endl;
                break;
                
            case 8:
                cout<<"\n"<<endl;
                cout << "Árbol binario en orden: ";
                    tree.postOrder();
                cout << endl;
                cout<<"\n"<<endl;
                break;
                
            case 9:
                if(tree.isBalanced() == true){
                    cout<<"Si esta balanceado"<<endl;
                }
                else{
                    cout<<"NO esta balanceado"<<endl;
                 
                }
                cout<<"\n"<<endl;
                break;
                
                
            default:
                if(option == 0) {
                    cout<<"\n"<<endl;
                    cout<<"--------------Saliendo del programa--------------"<<endl;
                    cout<<"\n"<<endl;
                }
                
                break;
        }
        
    }while(option != 0);
   
   
    
 
   
    

    return 0;
}

