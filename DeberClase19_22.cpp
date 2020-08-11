#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int menu();
void escribir(ofstream& archivo);
void lectura(ifstream& archivoLectura);
void agregar(ofstream& agrega);

string nombre, apellido;
string nombreArchivo;
string frase;
int e;

int main(){
    int numero;
    ofstream archivo, agrega;
    ifstream archivoLectura;
    cout << "Ingrese el nombre del archivo: ";
    getline(cin, nombreArchivo);
    
    archivo.open(nombreArchivo.c_str(), ios::out);
    numero = menu();
    do{

        switch(numero){
            case 1:{
                    escribir(archivo);
                    break;
            }
            case 2: {
                    archivoLectura.open(nombreArchivo, ios::in);
                    lectura(archivoLectura);
                    break;
            } 
            case 3: {
                    agrega.open(nombreArchivo, ios::app);
                    agregar(agrega);
                    break;
            }
            case 4:{
                    cout << "Fin del programa" << endl;
                    break;
            }
            default: {
                cout << "Opción inválida" << endl;
            }
            
        }
        if(numero == 4){
            break;
        } 
        numero = menu();
          
    }while(numero !=4);    
    return 0;
}
//*
int menu(){
    int opcion;
    do{
        cout << "1. Escritura" << endl;
        cout << "2. Lectura" << endl;
        cout << "3. Agregar texto" << endl;
        cout << "4. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;
    }while(opcion <= 0 || opcion >4);
    return opcion;
}

void escribir(ofstream& archivo){
    char r;
    do{
        cin.ignore(80, '\n');        
        cout << "\tIngrese el nombre: ";
        getline(cin, nombre, '\n');
        cout << "\tIngrese el apellido: ";
        getline(cin, apellido, '\n');
        cout << "\tEdad: ";
        cin >> e;
        archivo << nombre << " " << apellido << " " << e << "\n"; 

        cout << "desea add otro contacto s/n: ";
        cin >> r;

    }while(r == 's' || r == 'S');
    archivo.close();
}

void lectura(ifstream& archivoLectura){
    string nombreArchivo;
    string texto;

    while(!archivoLectura.eof()){
        archivoLectura >> nombre >> apellido >>e ;//>> frase; 
        if(!archivoLectura.eof()){ 
                getline(archivoLectura, texto);
                cout << "El nombre es: " << nombre << "\n";
                cout << "El apellido es: " << apellido << "\n";
                cout << "La edad es: " << e << "\n";
        //        cout << "Texto agregado: " << frase << "\n";
        }
        
    }if(archivoLectura.eof()){
            cout << "No hay texto" << endl; 
        }
    archivoLectura.close();
}

void agregar(ofstream& agrega){
    if(agrega.fail()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    cout << "Digite el texto a agregar: ";
    cin.ignore(80, '\n');
    getline(cin, frase, '\n');
    agrega << frase << "\n";

    agrega.close();

}
