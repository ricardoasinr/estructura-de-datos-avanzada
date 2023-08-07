#include <iostream>
#include <sstream>
#include <fstream>
#define MAX 900
#define ARCHIVOCSV "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/ArchivosIndexados/datos/datos copy.csv"
// #define ARCHIVOCSV "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/ArchivosIndexados/datos/alumnos2023.csv"
#define ARCHIVODAT "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/ArchivosIndexados/datos/datos.dat"
#define ARCHIVOIDX "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/ArchivosIndexados/datos/datos.idx"
#define ruta "/Users/ricardoasin/Desktop/Universidad/Estructura de datos avanzada/Archivos/ArchivosIndexados/datos/archivo.txt"
using namespace std;

struct RegistroEst
{
    char CodDept[4];
    char Nombre[40];
    char Edad[15];
    char Total[40];
    char Hombre[50];
    char Mujeres[10];
    int totalM;
    int totalH;
    int totalTotal;
};

struct RegistroIdx
{
    char CodDept[4];
    char Nombre[40];
    char Edad[15];
    char Total[40];
    char Hombre[50];
    char Mujeres[10];
    int Posicion;
};

RegistroIdx MemIndex[MAX];

void crearTxt()
{
    ofstream archivoTxt;

    archivoTxt.open(ruta, ios::out);
    archivoTxt << "Poblacion total \n";

    archivoTxt << "Chuquisaca";
    archivoTxt << " \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << "2312312424";
    archivoTxt << "Mujeres total: \n";
    archivoTxt << "2312312424";
    archivoTxt << " \n";

    archivoTxt << "Chuquisaca";
    archivoTxt << " \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << "2312312424";
    archivoTxt << " \n";
    archivoTxt.close();
}

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
        string CodDept, Nombre, Edad, Total, Hombre, Mujer;
        // Extraer todos los valores de esa fila
        getline(stream, CodDept, delimitador);
        getline(stream, Nombre, delimitador);
        getline(stream, Edad, delimitador);
        getline(stream, Total, delimitador);
        getline(stream, Hombre, delimitador);
        getline(stream, Mujer, delimitador);
        // Imprimir
        cout << "==================" << endl;
        cout << "Codigo Departamento: " << CodDept << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Edad: " << Edad << endl;
        cout << "Total: " << Total << endl;
        cout << "Hombre: " << Hombre << endl;
        cout << "Mujer: " << Mujer << endl;

        CodDept.copy(RegistroModelo.CodDept, 4);
        RegistroModelo.CodDept[4] = '\0';
        Nombre.copy(RegistroModelo.Nombre, 40);
        RegistroModelo.Nombre[Nombre.size()] = '\0';
        Edad.copy(RegistroModelo.Edad, 15);
        RegistroModelo.Edad[Edad.size()] = '\0';
        Total.copy(RegistroModelo.Total, 40);
        RegistroModelo.Total[Total.size()] = '\0';
        Hombre.copy(RegistroModelo.Hombre, 50);
        RegistroModelo.Hombre[Hombre.size()] = '\0';
        Mujer.copy(RegistroModelo.Mujeres, 10);
        RegistroModelo.Mujeres[Mujer.size()] = '\0';

        CodDept.copy(RegIndice.CodDept, 10);
        RegIndice.CodDept[4] = '\0';
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
        cout << "Codigo departamento: " << RegistroModelo.CodDept << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Edad: " << RegistroModelo.Edad << endl;
        cout << "Total: " << RegistroModelo.Total << endl;
        cout << "Hombre: " << RegistroModelo.Hombre << endl;
        cout << "Mujer: " << RegistroModelo.Mujeres << endl;
        fdat.read((char *)(&RegistroModelo), sizeof(RegistroModelo));
    }
    fdat.close();

    // Abrimos el archivo IDX para lectura y leemos el primer registro
    fidx.open(ARCHIVOIDX, ios::in | ios::binary);
    fidx.read((char *)&RegIndice, sizeof(RegIndice));
    int pando = 0;
    int beni = 0;
    int scz = 0;
    int chuquisaca = 0;
    int tarija = 0;
    int cochabamba = 0;
    int oruro = 0;
    int potosi = 0;
    int laPaz = 0;

    int pandoM = 0;
    int beniM = 0;
    int sczM = 0;
    int chuquisacaM = 0;
    int tarijaM = 0;
    int cochabambaM = 0;
    int oruroM = 0;
    int potosiM = 0;
    int laPazM = 0;

    // Leemos y mostramos todos los registros
    while (!fidx.eof())
    {
        // Imprimir
        cout << "=======Indice===========" << endl;
        cout << "Codigo departamento: " << RegIndice.CodDept << endl;
        cout << "Nombre: " << RegistroModelo.Nombre << endl;
        cout << "Edad: " << RegistroModelo.Edad << endl;
        cout << "Total: " << RegistroModelo.Total << endl;
        cout << "Hombre: " << RegistroModelo.Hombre << endl;
        cout << "Mujer: " << RegistroModelo.Mujeres << endl;

        if (atoi(RegIndice.CodDept) >= 100 && atoi(RegIndice.CodDept) <= 180)
        {
            chuquisaca = chuquisaca + atoi(RegistroModelo.Hombre) * 10;
            chuquisacaM = chuquisacaM + atoi(RegistroModelo.Mujeres) * 10;
        }
        else if (atoi(RegIndice.CodDept) >= 200 && atoi(RegIndice.CodDept) <= 280)
        {
            laPaz = laPaz + atoi(RegistroModelo.Hombre) * 13;
            laPazM = laPazM + atoi(RegistroModelo.Mujeres) * 10;
        }
        else if (atoi(RegIndice.CodDept) >= 300 && atoi(RegIndice.CodDept) <= 380)
        {
            cochabamba = cochabamba + atoi(RegistroModelo.Hombre) * 10;
            cochabambaM = cochabambaM + atoi(RegistroModelo.Mujeres) * 10;
        }
        else if (atoi(RegIndice.CodDept) >= 400 && atoi(RegIndice.CodDept) <= 480)
        {
            oruro = oruro + atoi(RegistroModelo.Hombre) * 10;
            oruroM = oruroM + atoi(RegistroModelo.Mujeres) * 10;
        }
        else if (atoi(RegIndice.CodDept) >= 500 && atoi(RegIndice.CodDept) <= 580)
        {
            potosi = potosi + atoi(RegistroModelo.Hombre) * 10;
            potosiM = potosiM + atoi(RegistroModelo.Mujeres) * 15;
        }
        else if (atoi(RegIndice.CodDept) >= 600 && atoi(RegIndice.CodDept) <= 680)
        {
            tarija = tarija + atoi(RegistroModelo.Hombre) * 15;
            tarijaM = tarijaM + atoi(RegistroModelo.Mujeres) * 15;
        }
        else if (atoi(RegIndice.CodDept) >= 700 && atoi(RegIndice.CodDept) <= 780)
        {
            scz = scz + atoi(RegistroModelo.Hombre) * 15;
            sczM = sczM + atoi(RegistroModelo.Mujeres) * 10;
        }
        else if (atoi(RegIndice.CodDept) >= 800 && atoi(RegIndice.CodDept) <= 880)
        {
            beni = beni + atoi(RegistroModelo.Hombre) * 10;
            beniM = beniM + atoi(RegistroModelo.Mujeres) * 10;
        }
        else if (atoi(RegIndice.CodDept) >= 900 && atoi(RegIndice.CodDept) <= 980)
        {
            pando = pando + atoi(RegistroModelo.Hombre) * 10;
            pandoM = pandoM + atoi(RegistroModelo.Mujeres) * 10;
        }

        // aprovechamos de cargar el indice a memoria
        strcpy(MemIndex[numRegMem].CodDept, RegIndice.CodDept);
        MemIndex[numRegMem].Posicion = RegIndice.Posicion;

        // continuamos leyendo
        fidx.read((char *)(&RegIndice), sizeof(RegIndice));
        numRegMem++;
    }

    ofstream archivoTxt;

    archivoTxt.open(ruta, ios::out);
    archivoTxt << "Poblacion total \n";

    archivoTxt << "Chuquisaca \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << chuquisaca;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << chuquisacaM;
    archivoTxt << " \n";

    archivoTxt << "La Paz \n";
    archivoTxt << " \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << laPaz;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << laPazM;
    archivoTxt << " \n";
    archivoTxt << " \n";

    archivoTxt << "Cochabamba \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << cochabamba;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << cochabambaM;
    archivoTxt << " \n";

    archivoTxt << "Oruro \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << oruro;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << oruroM;
    archivoTxt << " \n";

    archivoTxt << "Potosi \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << potosi;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << potosiM;
    archivoTxt << " \n";

    archivoTxt << "Tarija \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << tarija;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << tarijaM;
    archivoTxt << " \n";

    archivoTxt << "Santa Cruz\n";

    archivoTxt << "Hombres total: \n";
    archivoTxt << scz;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << sczM;
    archivoTxt << " \n";

    archivoTxt << "Beni \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << beni;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << beniM;
    archivoTxt << " \n";

    archivoTxt << "Pando \n";
    archivoTxt << "Hombres total: \n";
    archivoTxt << pando;
    archivoTxt << " \n";

    archivoTxt << "Mujeres total: \n";
    archivoTxt << pandoM;
    archivoTxt << " \n";

    archivoTxt << " \n";
    archivoTxt.close();

    fidx.close();
}

void AccesoIndexado(char noRegLec[12])
{
    ifstream fdat;
    int numRegMem = 0;
    RegistroEst RegistroLeido;
    RegistroIdx RegIndice;
    while (numRegMem < MAX)
    {
        // if ((MemIndex[numRegMem].Registro == noRegLec) && (MemIndex[numRegMem].Borrado == 32))
        if ((strcmp(MemIndex[numRegMem].CodDept, noRegLec) == 0))
        {
            // Encontramos el registro
            fdat.open(ARCHIVODAT, ios::in | ios::binary);
            fdat.seekg((MemIndex[numRegMem].Posicion - 1) * sizeof(RegistroLeido));
            fdat.read((char *)(&RegistroLeido), sizeof(RegistroLeido));
            cout << "============Encontrado============" << endl;
            cout << "Codigo departamento: " << RegIndice.CodDept << endl;
            cout << "Nombre: " << RegistroLeido.Nombre << endl;
            cout << "Edad: " << RegistroLeido.Edad << endl;
            cout << "Total: " << RegistroLeido.Total << endl;
            cout << "Hombre: " << RegistroLeido.Hombre << endl;
            cout << "Mujeres: " << RegistroLeido.Mujeres << endl;
            cout << "-----------------------------------" << endl;
            numRegMem = MAX;
        }
        numRegMem++;
    }
    if (numRegMem == MAX)
        cout << "====== NO Encontrado============\n"
             << endl;
}

void PorDepartamento(char noRegLec[12])
{
    ifstream fdat;
    int numRegMem = 0;
    RegistroEst RegistroLeido;
    RegistroIdx RegIndice;
    while (numRegMem < MAX)
    {
        // if ((MemIndex[numRegMem].Registro == noRegLec) && (MemIndex[numRegMem].Borrado == 32))
        if ((strcmp(MemIndex[numRegMem].CodDept, noRegLec) == 0))
        {
            // Encontramos el registro
            fdat.open(ARCHIVODAT, ios::in | ios::binary);
            fdat.seekg((MemIndex[numRegMem].Posicion - 1) * sizeof(RegistroLeido));
            fdat.read((char *)(&RegistroLeido), sizeof(RegistroLeido));
            cout << "============Encontrado============" << endl;
            cout << "Codigo departamento: " << RegIndice.CodDept << endl;
            cout << "Nombre: " << RegistroLeido.Nombre << endl;
            cout << "Total: " << RegistroLeido.Total << endl;
            cout << "Hombre: " << RegistroLeido.Hombre << endl;
            cout << "Mujeres: " << RegistroLeido.Mujeres << endl;
            cout << "-----------------------------------" << endl;
            numRegMem = MAX;
        }
        numRegMem++;
    }
    if (numRegMem == MAX)
        cout << "====== NO Encontrado============\n"
             << endl;
}

int main()
{
    char opcion, noRegLec[12];
    int opcionMenu;
    int totalTotal = 0;
    int totalHombres = 0;
    int totalMujeres = 0;

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

    cout << "\n\n *********************\n";
    cout << " Lectura indexada\n";

    do
    {
        cout << "Menú:" << endl;
        cout << "1. Por código de departamento" << endl;
        cout << "2. Totales" << endl;
        cout << "3. Ordenar" << endl;
        cout << "0. Salir" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:
            cout << "Que numero de registro quiere ver? (000 para terminar):";
            cin >> noRegLec;

            while (strcmp(noRegLec, "000") != 0)
            {
                AccesoIndexado(noRegLec);
                cout << "Que numero de registro quiere ver? (000 para terminar):";
                cin >> noRegLec;
            }
            break;
        case 2:
            crearTxt();
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
}
