#include <iostream>
#include <string>
using namespace std;
#include <fstream>

int main() {
   string nif, producto;
   int unidades;
   double precio;
   char aux;
   ofstream archivo;
   
   archivo.open("datos.txt"); 

   cout << "NIF del cliente (X para terminar): ";
   cin >> nif;
    while (nif != "X") {
      cin.get(aux); 
    
      cout << "Producto: ";
      getline(cin, producto);
      cout << "Unidades: ";
      cin >> unidades;
      cout << "Precio: ";
      cin >> precio;
      
      archivo << nif << " " << unidades << " "
         << precio << " " << producto << endl;
      cout << "NIF del cliente (X para terminar): ";
      cin >> nif;
   }

   archivo << "X";
   archivo.close();

   return 0;
}

