#include "iostream"
using namespace std;

#include "iventario.h"

int main(){
    int dinero = 500;
    iventario *operaciones[3]; // Se hace un arrreglo de objetos
    operaciones[0] = new envio(dinero); // se crea un objeto de operaciones 1
    operaciones[0] -> mostrarDinero(); // se muestra el dinero
    operaciones[0]-> gastar();
    operaciones[0] -> mostrarDinero();
    dinero = operaciones[0] -> RegresarDinero();
    iventario objeto(dinero);
    objeto.mostrarDinero();

    return 0;
}