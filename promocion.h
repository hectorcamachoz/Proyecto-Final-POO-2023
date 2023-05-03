class promocion{
    private:
     int descuento;
     string Promos;
     
    public:
     promocion();
     void promociones();
     void descuentos();
     void damepromocion(int i);
     void damedescuento(string s);
     void menu();
};
promocion::promocion(){
    
}

void promocion::damepromocion(int i){
     descuento=i;
}
void promocion::damedescuento(string s){
     Promos=s;   
}
void promocion::promociones(){
     cout<<"Estas son las promociones que tenemos"<<endl;
     cout<<"2x1"<<endl;
     cout<<"25%"<<endl;
     cout<<"hola"<<endl;
}
void promocion::descuentos(){
    
}
void promocion::menu(){
     int decision;
     cout<<"Que quieres hacer?"<<endl;
    cout << "*******       Menu de promociones    *************" <<endl;
    cout << "*************************************************"  <<endl;
    cout <<" 1) Agregar promociones                                           "<<endl;
    cout <<" 2) Agregar descuentos                                            "<<endl;
    cout <<" 3) Mostrar descuentos                                          "<<endl;
    cout <<" 4) Mostrar promociones                                           "<<endl;
    cout <<" 5) Quitar                                          "<<endl;
    cin>>decision;
    if (decision=4){
       promocion::promociones();
    }
}

