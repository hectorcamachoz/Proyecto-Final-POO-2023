class iventario{
    private:
    protected:
    public:
     string Usuarioinicial="fer";
     int contrasenainicial=1234;
     inventario();
     int darinventario();

};
class menu{
    public:
     void menu123();
};

iventario::inventario(){};

void menu::menu123(){
    cout << "*************************************************"  <<endl;
    cout << "*******       Menu de triangulo      *************" <<endl;
    cout << "*************************************************"  <<endl;
    cout <<" 1) envio                                           "<<endl;
    cout <<" 2) pago                                            "<<endl;
    cout <<" 3) pedido                                          "<<endl;
    cout <<" 4) venta                                           "<<endl;
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

