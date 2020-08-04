#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string nombre, apellido, direccion, nacimiento, estcivil;
    int e;
    char r;
    ofstream datoPersonal;

    datoPersonal.open("datosPersonales.txt", ios::out); //nombre de archivo y operación
    
    cout << "Ingrese el nombre: ";
    getline(cin, nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, apellido);
    cout << "Edad: ";
    cin >> e;
    cout << "Ingrese la dirección: ";
    getline(cin, direccion);
    cin.ignore();
    cout << "Digite su lugar de nacimiento: ";
    getline(cin, nacimiento);
    cin.ignore();
    cout << "Digite su estado civil: ";
    getline(cin, estcivil);
    cin.ignore();
    datoPersonal << nombre << " " << apellido << " " << e  << " " << direccion << " "  << nacimiento << " " << estcivil << "\n";
    datoPersonal.close();


    //Lectura archivo
    ifstream archivoLectura; // variable tipo texto
    string texto;

    archivoLectura.open("datosPersonales.txt", ios::in);
    
    if(archivoLectura.fail()){
        cout << "El archivo no se puede abrir";
    
    }else{
        while(!archivoLectura.eof()){// while para leer linea por linea siempre y cuando haiga texto
                getline(archivoLectura, texto);
                cout << texto << endl;
        }  
    }

    datoPersonal.close();
    return 0;
}