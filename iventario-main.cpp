#include "iostream"
using namespace std;

#include "iventario.h"

int main(){
    menu objeto1;
    gestion_envio objeto2;
    gestion_pago objeto3;
    gestion_pedido objeto4;
    gestion_venta objeto5;
    promocion promos[1][2];
    
    int decision=1;
    int eleccion;
    cout<<"gh"<<endl;
    while(decision==1){
        objeto1.menu123();//se despliega el menu de tipos de triangulo
        cout<<"Que eliges?"<<endl;
        cin>>eleccion;
        while (eleccion<=0){
            cout<<"Error,try again"<<endl;
            cin>>eleccion;
        }
        if(eleccion==1){
            objeto2.mostrar();//se despliega el submenu de cada tipo segun la eleccion¡
        }else if(eleccion==2){
            objeto3.mostrar();
        }else if(eleccion==3){
            objeto4.mostrar();
        }else if(eleccion==4){
            objeto5.mostrar();
        }
        cout<<"Quieres acabar?  1=NO, 2=Si"<<endl;
        cin>>decision;
        while(decision>2 or decision<1){
            cout<<"Invalido respuesta,try again"<<endl;
            cin>>decision;
        }
    }
    return 0;
}
