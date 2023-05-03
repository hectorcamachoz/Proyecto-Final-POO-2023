#include "promocion.h"
class iventario{
    private:
     
    protected:
     promocion objeto;
     string nombreempresa;
    public:
     
     iventario();
     string Usuarioinicial="fer";
     int contrasenainicial=1234;
     //int darinventario();

};
class menu:protected iventario{
    public:
     int hola=0;
     void menu123();
};

iventario::iventario(){
    cout<<"Cual es el nombre de la empresa?"<<endl;
    getline(cin,nombreempresa);
}

void menu::menu123(){
    
    cout << "*************************************************"  <<endl;
    cout << "*******       Menu de "<<nombreempresa<< "    *************" <<endl;
    cout << "*************************************************"  <<endl;
    cout <<" 1) envio                                           "<<endl;
    cout <<" 2) pago                                            "<<endl;
    cout <<" 3) pedido                                          "<<endl;
    cout <<" 4) venta                                           "<<endl;
    cout <<" 5) promociones                                     "<<endl;
    cin>>hola;
    if(hola==5){
        cout<<"gi"<<endl;
        objeto.menu();
    }
    //tal vez se podrian hacer clases por separado y de ahi entonces solo con una funcion,salga el menu de sus opciones y que se quiere hacer
}
class gestion_pedido{
    public:
     void mostrar();
};
void gestion_pedido::mostrar(){
    cout<<"Estas en pedidos"<<endl;
}
class gestion_envio{
    public:
     void mostrar();
};
void gestion_envio::mostrar(){
    cout<<"Estas en envios"<<endl;
}
class gestion_venta{
    public:
     void mostrar();
};
void gestion_venta::mostrar(){
    cout<<"Estas en ventas"<<endl;
}
class gestion_pago{
    public:
     void mostrar();
};
void gestion_pago::mostrar(){
    cout<<"Estas en pagos"<<endl;
}

