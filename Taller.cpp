#include <iostream>
#include <fstream>
using namespace std;

int busqueda(int a[], int n, int dato);
int main(){
    ofstream archivo;
    int a[5] = {4,1,3,2,5};
    int dato;
    archivo.open("Lineal.txt", ios::out);
    
    if(archivo.fail()){
        cout << "No se puedo abrir el archivo " << endl;
    }

    archivo << "El arreglo de elementos es: " << endl;

    for(int i = 0; i < 5; i++){
        archivo << a[i] << " ";
    }

    cout << "digite un número: ";
    cin >> dato;
    archivo << "\nEl elemento a buscar es: " << dato << endl;
    
    if(busqueda(a, 5, dato) == -1){
        archivo << "El elemento no se ha encontrado" << endl;

    }else{
        archivo << "El Elemento " << dato << " se ha encontrado en la posición " << busqueda(a,5,dato) << endl; 
    }


    return 0;
}

int busqueda(int a[], int n, int dato){
    for(int i = 0; i <= n; i++){
        if(a[i] == dato){
            return i;       
        }
    }
    return -1;
}
