//
//  main.cpp
//  Fibonacci
//
//  Created by Ricardo Asin on 11/2/23.
//

#include <iostream>
#define MAX 100000
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int vec[MAX];
    int  vecInv[MAX];
    int  n;
    int  fib = 0;
    int  aux = 1;
    int  j =0;
    cin>>n;
    cout << "Hello, World!\n";
    for(int i = 0; i<= n; i++){
        
        aux += fib;
        fib = aux - fib;
        vec[i] = fib;
        
    }
    cout<<"----------------"<<endl;
    cout<<"Mostrando vector"<<endl;
    for(int i = 0; i<= n; i++){
        cout<<i<<":"<<vec[i]<<endl;
    }
    cout<<"----------------"<<endl;
    cout<<"Mostrando vector inverso"<<endl;
        for(int i = n; i>= 0; i--){
            j++;
            cout<<vec[i]<<endl;
            vecInv[j] = vec[i];
    
        }
    
    cout<<"----------------"<<endl;
    cout<<"Mostrando vector inverso cargado"<<endl;
        for(int i = 1; i<= n+1; i++){
            cout<<vecInv[i]<<endl;
        }
    
    //¿Cuántos elementos es capaz de generar este programa?
    //R. Es capaz de generar hasta el elemento número 45
    
    //¿Cuál es el valor máximo de elemento que soporta este programa?
    //R. 1836311903
    

    
    return 0;
}
