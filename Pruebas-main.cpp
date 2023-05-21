#include "iostream"
using namespace std;

#include "Inventario.h"

int main(){
    
   
    int dinero = 500;
    Inventario *operaciones[3]; // Se hace un arrreglo de objetos
    operaciones[0] = new GestionEnvio(dinero); // se crea un objeto de operaciones 1
    operaciones[0] -> mostrarDinero(); // se muestra el dinero
    operaciones[0]-> gastar();
    operaciones[0] -> mostrarDinero();
    dinero = operaciones[0] -> RegresarDinero();
    Inventario objeto(dinero);
    objeto.mostrarDinero();
    int decision=1;
    int eleccion;
    Menu menu;
    
    while(decision==1){
        menu.MenuGeneral();
        cout<<"Quieres acabar?  1=NO, 2=Si"<<endl;
        cin>>decision;
        while(decision>2 or decision<1){
            cout<<"Invalido respuesta,try again"<<endl;
            cin>>decision;
        }
    }
    return 0;
}