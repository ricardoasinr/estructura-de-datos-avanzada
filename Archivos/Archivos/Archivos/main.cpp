//
//  main.cpp
//  Archivos
//
//  Created by Ricardo Asin on 1/4/23.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fichero;
    char nombre[81];
    char c;
    cout << "Nombre del archivo: ";
    cin >> nombre;
    fichero.open(nombre, ios::out);
    if (!fichero.good())
    {
        cout << "Error al abrir el archivo" << endl;
        exit(-1);
    }
    cout << "Escriba texto: control+z para terminar\n";
    while (cin.get(c))
        fichero.put(c);
    fichero.close();
    cout << "Lectura y escritura del archivo anterior\n";
    ifstream fichero1(nombre, ios::in);
    while (fichero1.get(c)){
        cout.put(c);
        
    }
    fichero1.close();
    return 0;
}



//#include <cstdlib>
//#include <iostream>
//#include <fstream>
//using namespace std;
//int main()
//{
//    ofstream fichero;
//    char nombre[81];
//    char c;
//    cout << "Nombre del archivo: ";
//    cin >> nombre;
//    fichero.open(nombre, ios::out);
//    if (!fichero.good())
//    {
//        cout << "Error al abrir el archivo" << endl;
//        exit(-1);
//    }
//    cout << " Escriba texto: control+z para terminar\n";
//    while (cin.get(c))
//        fichero.put(c);
//    fichero.close();
//    cout << " Lectura y escritura del archivo anterior\n";
//    ifstream fichero1(nombre, ios::in);
//    while (fichero1.get(c))
//        cout.put(c);
//    fichero1.close();
//    return 0;
//}


