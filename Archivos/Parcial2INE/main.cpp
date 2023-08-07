#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#define ARCHIVOCSV "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/Parcial2INE/datos/datos.csv"
#define ARCHIVODAT "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/Parcial2INE/datos/datos.dat"
#define ARCHIVOIDX "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/Parcial2INE/datos/datos.idx"
using namespace std;

struct RegistroEst
{
    char Borrado;
    char CodDept[12];
    char Nombre[40];
    char Edad[15];
    char Total[40];
    char Hombre[50];
    char Mujeres[10];
};

struct RegistroIdx
{
    char Borrado;
    char Registro[12];
    int Posicion;
};

RegistroIdx MemIndex[100];

/* Lee el CSV y crea el archivo binario DAT */
void CrearOrigen()
{
    ifstream archivo(ARCHIVOCSV);
    string linea;
    char delimitador = ';';
    int numReg = 1;
    ofstream fdat, fidx;
    RegistroEst RegistroModelo;
    RegistroIdx RegIndice;

    // Leemos la primer línea del CSV para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Creamos el archivo DAT donde guardaremos la estructura completa
    fdat.open(ARCHIVODAT, ios::out | ios::binary);
    // Creamos el archivo IDX donde guardaremos la estructura indice
    fidx.open(ARCHIVOIDX, ios::out | ios::binary);

    // Leemos todas las líneas del CSV y guardamos en DAT e IDX
    while (getline(archivo, linea))
    {
        stringstream stream(linea); // Convertir la cadena a un stream
        string CodDept, Nombre, Edad, Total, Hombre, Mujeres;
        // Extraer todos los valores de esa fila
        getline(stream, CodDept, delimitador);
        getline(stream, Nombre, delimitador);
        getline(stream, Edad, delimitador);
        getline(stream, Total, delimitador);
        getline(stream, Hombre, delimitador);
        getline(stream, Mujeres, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "Codigo departamento: " << CodDept << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Edad: " << Edad << endl;
        cout << "Total: " << Total << endl;
        cout << "Hombre: " << Hombre << endl;
        cout << "Mujer: " << Mujeres << endl;

        RegistroModelo.Borrado = 32;
        CodDept.copy(RegistroModelo.CodDept, 10);
        RegistroModelo.CodDept[10] = '\0';
        Nombre.copy(RegistroModelo.Nombre, 40);
        RegistroModelo.Nombre[Nombre.size()] = '\0';
        Edad.copy(RegistroModelo.Edad, 15);
        RegistroModelo.Edad[Edad.size()] = '\0';
        Total.copy(RegistroModelo.Total, 40);
        RegistroModelo.Total[Total.size()] = '\0';
        Hombre.copy(RegistroModelo.Hombre, 50);
        RegistroModelo.Hombre[Hombre.size()] = '\0';
        Mujeres.copy(RegistroModelo.Mujeres, 10);
        RegistroModelo.Mujeres[Mujeres.size()] = '\0';

        RegIndice.Borrado = 32;
        CodDept.copy(RegIndice.Registro, 10);
        RegIndice.Registro[10] = '\0';
        RegIndice.Posicion = numReg;
        fdat.write((char *)&RegistroModelo, sizeof(RegistroModelo));
        fidx.write((char *)&RegIndice, sizeof(RegIndice));
        numReg++;
    }
    archivo.close();
    fdat.close();
    fidx.close();
}

void PorCodDept(char cod[10])
{
    int numRegMem = 0;
    ifstream fdat, fidx;
    RegistroEst RegistroModelo;
    RegistroIdx RegIndice;

    // Abrimos el archivo DAT para lectura y leemos el primer registro
    fdat.open(ARCHIVODAT, ios::in | ios::binary);
    fdat.read((char *)&RegistroModelo, sizeof(RegistroModelo));

    // Leemos y mostramos todos los registros
    while (!fdat.eof())
    {
        // Imprimir si el código de departamento coincide
        if (strcmp(RegistroModelo.CodDept, cod) == 0)
        {
            cout << "==================" << endl;
            cout << "Codigo departamento: " << RegistroModelo.CodDept << endl;
            cout << "Nombre: " << RegistroModelo.Nombre << endl;
            cout << "Edad: " << RegistroModelo.Edad << endl;
            cout << "Total: " << RegistroModelo.Total << endl;
            cout << "Hombre: " << RegistroModelo.Hombre << endl;
            cout << "Mujer: " << RegistroModelo.Mujeres << endl;
            cout << "Marcado para borrar: " << RegistroModelo.Borrado << endl;
        }
        // Leer el siguiente registro
        fdat.read((char *)&RegistroModelo, sizeof(RegistroModelo));
    }
    fdat.close();
}

/* Lee el DAT secuencialmente */
void MostrarDatos()
{
    int numRegMem = 0;
    ifstream fdat, fidx;
    RegistroEst RegistroModelo;
    RegistroIdx RegIndice;

    // Abrimos el archivo DAT para lectura y leemos el primer registro
    fdat.open(ARCHIVODAT, ios::in | ios::binary);
    fdat.read((char *)&RegistroModelo, sizeof(RegistroModelo));

    // Leemos y mostramos todos los registros
    while (!fdat.eof())
    {
        // Imprimir
        cout << "==================" << endl;
        cout << "Codigo departamento: " << RegistroModelo.CodDept << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Edad: " << RegistroModelo.Edad << endl;
        cout << "Total: " << RegistroModelo.Total << endl;
        cout << "Hombre: " << RegistroModelo.Hombre << endl;
        cout << "Mujer: " << RegistroModelo.Mujeres << endl;
        cout << "Marcado para borrar: " << RegistroModelo.Borrado << endl;
        fdat.read((char *)(&RegistroModelo), sizeof(RegistroModelo));
    }
    fdat.close();

    // Abrimos el archivo IDX para lectura y leemos el primer registro
    fidx.open(ARCHIVOIDX, ios::in | ios::binary);
    fidx.read((char *)&RegIndice, sizeof(RegIndice));

    // Leemos y mostramos todos los registros
    while (!fidx.eof())
    {
        // Imprimir
        cout << "==================" << endl;
        cout << "Codigo departamento: " << RegIndice.Registro << endl;
        cout << "Posicion: " << RegIndice.Posicion << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Edad: " << RegistroModelo.Edad << endl;
        cout << "Total: " << RegistroModelo.Total << endl;
        cout << "Hombre: " << RegistroModelo.Hombre << endl;
        cout << "Mujer: " << RegistroModelo.Mujeres << endl;
        cout << "Marcado para borrar: " << RegIndice.Borrado << endl;

        // aprovechamos de cargar el indice a memoria
        MemIndex[numRegMem].Borrado = RegIndice.Borrado;
        strcpy(MemIndex[numRegMem].Registro, RegIndice.Registro);
        MemIndex[numRegMem].Posicion = RegIndice.Posicion;

        // continuamos leyendo
        fidx.read((char *)(&RegIndice), sizeof(RegIndice));
        numRegMem++;
    }
    fidx.close();
}

void AccesoIndexado(char noRegLec[12])
{
    int i = 0, encontrado = 0;
    RegistroEst RegistroModelo;
    RegistroIdx RegIndice;
    ifstream fdat, fidx;

    // Abrimos los archivos
    fidx.open(ARCHIVOIDX, ios::in | ios::binary);
    fdat.open(ARCHIVODAT, ios::in | ios::binary);

    // Buscamos el registro en el archivo IDX
    while (!fidx.eof())
    {
        fidx.read((char *)&RegIndice, sizeof(RegIndice));
        if (strcmp(RegIndice.Registro, noRegLec) == 0 && RegIndice.Borrado == ' ')
        {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
    {
        // Si lo encontramos, buscamos el registro correspondiente en el archivo DAT
        fdat.seekg((RegIndice.Posicion - 1) * sizeof(RegistroModelo));
        fdat.read((char *)&RegistroModelo, sizeof(RegistroModelo));
        // Imprimimos el registro

        cout << "Codigo departamento: " << RegistroModelo.CodDept << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Edad: " << RegistroModelo.Edad << endl;
        cout << "Total: " << RegistroModelo.Total << endl;
        cout << "Hombre: " << RegistroModelo.Hombre << endl;
        cout << "Mujer: " << RegistroModelo.Mujeres << endl;
    }
    else
    {
        cout << "Departamento no encontrado." << endl;
    }

    // Cerramos los archivos
    fidx.close();
    fdat.close();
}

int main()
{

    int opcionMenu;
    // Variables para almacenar los totales
    int totalTotal = 0;
    int totalHombres = 0;
    int totalMujeres = 0;
    char opcion, noRegLec[12];
    cout << " Manejo de archivos indexados\n";
    cout << "Debemos crear el archivo DAT? (S/N):";
    cin >> opcion;
    if ((opcion == 'S') || (opcion == 's'))
    {
        CrearOrigen();
    }
    else
    {
        MostrarDatos();
    }

    cout << "\n\n *******\n";
    cout << " Lectura indexada\n";

    do
    {
        cout << "Menú:" << endl;
        cout << "1. Por código de departamento" << endl;
        cout << "2. Nombre de departamento" << endl;
        cout << "3. Total total" << endl;
        cout << "4. Total de hombres" << endl;
        cout << "5. Total de mujeres" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:
            cout << "Que codigo de departamento quiere ver? (000 para terminar):";
            cin >> noRegLec;
            while (strcmp(noRegLec, "000") != 0)
            {
                // AccesoIndexado(noRegLec);
                PorCodDept(noRegLec);
                cout << "Que codigo de departamento quiere ver? (000 para terminar):";
                cin >> noRegLec;
            }

            break;
        case 2:
            // Opción 2: por nombre de departamento
            // Aquí puedes escribir el código para procesar esta opción
            break;
        case 3:
            // Opción 3: total total
            cout << "El total total es: " << totalTotal << endl;
            break;
        case 4:
            // Opción 4: total de hombres
            cout << "El total de hombres es: " << totalHombres << endl;
            break;
        case 5:
            // Opción 5: total de mujeres
            cout << "El total de mujeres es: " << totalMujeres << endl;
            break;
        case 0:
            // Opción 0: salir
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            // Opción inválida
            cout << "Opción inválida. Inténtalo de nuevo." << endl;
        }

    } while (opcionMenu != 0);

    return 0;
}