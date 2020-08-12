#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream archivo;
    char tipoUva;
    int sizeUva, kilos;
    float precioKilo, total, subtotal;

    archivo.open("Vinicultores.txt", ios::out);

    cout << "Ingrese el precio por kilo de uva: ";
    cin >> precioKilo;
    cout << "Total de kilos que se Produjeron: ";
    cin >> kilos;
    cout << "Ingrese el tipo de uva (A/B): ";
    cin >> tipoUva;
    cout << "Ingrese el tamaño de uva (1/2): ";
    cin >> sizeUva;
    subtotal = kilos * precioKilo;
    cout << "Precio Inicial: " << subtotal << " $" << endl;

    if (tipoUva =='A'){
        if(sizeUva ==1){
            total= (subtotal) +0.20;
            cout << "Precio Final: " << total <<" $" << endl;
        
        }else{
            total = (subtotal) +0.30;
            cout << "Precio Final: " << total << " $" <<endl;
        }
    }else{
        if(sizeUva == 1){
            total= (subtotal) -0.30;
            cout << "Precio Final: " << total << " $" <<endl;
        
        }else{
            total = (subtotal) -0.50;
            cout << "Precio Final: " << total << " $" <<endl;
        }
    }

    archivo << "Precio por kilo: " << precioKilo << " $" << endl;
    archivo << "Total de kilos: " << kilos << endl;
    archivo << "Tipo de uva: " << tipoUva << endl;
    archivo << "Tamaño de uva: " << sizeUva << endl
            << "Precio inicial: " << subtotal << " $" << endl
            << "Precio final: " << total << " $" << endl;
    return 0;
}
