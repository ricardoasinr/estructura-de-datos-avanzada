#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#define ARCHIVOCSV "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/Parcial2/datos/datos.csv"
#define ARCHIVODAT "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/Parcial2/datos/datos.dat"
#define ARCHIVOIDX "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/Parcial2/datos/datos.idx"
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
        string Registro, Nombre, Carrera, email, emailpers, telefono;
        // Extraer todos los valores de esa fila
        getline(stream, Registro, delimitador);
        getline(stream, Nombre, delimitador);
        getline(stream, Carrera, delimitador);
        getline(stream, email, delimitador);
        getline(stream, emailpers, delimitador);
        getline(stream, telefono, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "Registro: " << Registro << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Carrera: " << Carrera << endl;
        cout << "Email UPSA: " << email << endl;
        cout << "Email Personal: " << emailpers << endl;
        cout << "Telefono: " << telefono << endl;

        RegistroModelo.Borrado = 32;
        Registro.copy(RegistroModelo.CodDept, 10);
        RegistroModelo.CodDept[10] = '\0';
        Nombre.copy(RegistroModelo.Nombre, 40);
        RegistroModelo.Nombre[Nombre.size()] = '\0';
        Carrera.copy(RegistroModelo.Edad, 15);
        RegistroModelo.Edad[Carrera.size()] = '\0';
        email.copy(RegistroModelo.Total, 40);
        RegistroModelo.Total[email.size()] = '\0';
        emailpers.copy(RegistroModelo.Hombre, 50);
        RegistroModelo.Hombre[emailpers.size()] = '\0';
        telefono.copy(RegistroModelo.Mujeres, 10);
        RegistroModelo.Mujeres[telefono.size()] = '\0';

        RegIndice.Borrado = 32;
        Registro.copy(RegIndice.Registro, 10);
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
        cout << "Registro: " << RegistroModelo.CodDept << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Carrera: " << RegistroModelo.Edad << endl;
        cout << "Email UPSA: " << RegistroModelo.Total << endl;
        cout << "Email Personal: " << RegistroModelo.Hombre << endl;
        cout << "Telefono: " << RegistroModelo.Mujeres << endl;
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
        cout << "Registro: " << RegIndice.Registro << endl;
        cout << "Marcado para borrar: " << RegIndice.Borrado << endl;
        cout << "Posicion: " << RegIndice.Posicion << endl;

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
        cout << "==================" << endl;
        cout << "Registro: " << RegistroModelo.CodDept << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Carrera: " << RegistroModelo.Edad << endl;
        cout << "Email UPSA: " << RegistroModelo.Total << endl;
        cout << "Email Personal: " << RegistroModelo.Hombre << endl;
        cout << "Telefono: " << RegistroModelo.Mujeres << endl;
    }
    else
    {
        cout << "Registro no encontrado." << endl;
    }

    // Cerramos los archivos
    fidx.close();
    fdat.close();
}

int main()
{
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
    cout << "Que numero de registro quiere ver? (000 para terminar):";
    cin >> noRegLec;
    while (strcmp(noRegLec, "000") != 0)
    {
        AccesoIndexado(noRegLec);
        cout << "Que numero de registro quiere ver? (000 para terminar):";
        cin >> noRegLec;
    }
    return 0;
}