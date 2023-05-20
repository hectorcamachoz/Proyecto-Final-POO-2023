#include "fstream"
#include "vector"
#include "string"
#include "iomanip"//para setw
using namespace std;
class Inventario{
     private:
       vector<string>nombres;//de articulos
       vector<int>cantidades;
       vector<float>costos;

     public:
      Inventario();
      void imprimirInventario();
      void guardarInventario();
      void cargarInventario();
      void modificarInventario();
      void menuInventario();
      void borrarVectores();
};
Inventario::Inventario(){
    
}
void Inventario::imprimirInventario(){
    cout << " ----------- Inventario ----------- "<< endl;
    cout << "Nombre"<<setw(15)<<"Cantidad"<<setw(15)<<"Costo" << endl;
    cout << "------------------------------------" << endl;
    int Size=nombres.size();//para conocer el tamaño de los vectores
    //es el mismo para los 3
    for(int i=0;i<Size;i++){
        cout<<nombres[i]<<setw(15)<<cantidades[i]<<setw(15)<<costos[i]<<endl;
    }
}
void Inventario::guardarInventario(){
    ofstream archivo("Inventario.txt");//escritura en .txt
    if(archivo.is_open()){
        archivo<<nombres.size()<<endl;//aqui se guarda en el archivo la cantidad de los productos y se pasa de linea para que sigan los nombres
    }for(string nombre:nombres){
        archivo<<nombre<<",";//pone nombre, nombre,
    }
    archivo<<endl;//son para saltar de linea
    for(int cantidad : cantidades){
        archivo << cantidad << ",";
    }
    archivo<<endl;
    for(float costo:costos){
        archivo<<costo<<",";
    }
    archivo<<endl;
    archivo.close();
    cout<<"Guardado finalizado"<<endl;
}
void Inventario::cargarInventario(){
     int size;
     ifstream archivo("Inventario.txt");//lectura en .txt
     if(archivo.is_open()){
        archivo>>size;
        archivo.ignore();
        //se lee la primera linea del .txt (ahi dice cuantos productos hay)
        //.ignore() es para ignorar lo que haya despues de este valor
        for (int i=0;i<size;i++){
            string nombre;
            getline(archivo,nombre,',');
            //de archivo
            nombres.push_back(nombre);
            //lee la linea hasta llegar a un ' , '
        }
        //size dice el tamaño del vector
        for (int i=0;i<size;i++){
            int cantidad;
            archivo>>cantidad;
            archivo.ignore();//evita que se lea el \n porque sino,este se puede tomar cuando se capture los datos
            cantidades.push_back(cantidad);
            //lee la linea hasta llegar a un ' , '
        }
        for (int i=0;i<size;i++){
            float costo;
            archivo>>costo;
            archivo.ignore();
            costos.push_back(costo);
        }
        archivo.close();
        cout<<"Datos cargados"<<endl;
    }
}
void Inventario::modificarInventario(){
    int decision;
    cout<<"Ingresa el numero del producto a modificar"<<endl;
    Inventario::imprimirInventario();//se muestra el inventario
    cin>>decision;
    
    while(decision<1 or decision>nombres.size())//con nombres .size se puede saber cuantos productos hay en total
    {
        cout<<"Respuesta invalida,try again"<<endl;
        cin>>decision;
    }
    decision=decision-1;//porque se empieza de 0
    cout<<"Que modificaras?  1)Nombre 2)Cantidad 3)Precio 4)Completo"<<endl;
    int Accion;
    string NuevoNombre;
    int NuevaCantidad;
     float NuevoPrecio;
    cin>>Accion;
    while(Accion>4 or Accion<1){
        cout<<"Respuesta invalida,try again"<<endl;
        cin>>Accion;
    }
    if(Accion==1){
        
        cout<<"Inserta nuevo nombre"<<endl;
        cin.ignore();
        getline(cin,NuevoNombre);
        nombres[decision]=NuevoNombre;
    }else if(Accion==2){
        cout<<"Ingresa la nueva cantidad"<<endl;
        
        cin>>NuevaCantidad;
        cantidades[decision]=NuevaCantidad;
    }else if(Accion==3){
       
        cout<<"Inserta nuevo precio"<<endl;
        cin>>NuevoPrecio;
        costos[decision]=NuevoPrecio;
    }else if(Accion==4){
        cout<<"Inserta nuevo nombre"<<endl;
        cin.ignore();
        getline(cin,NuevoNombre);
        cout<<"Ingresa la nueva cantidad"<<endl;
        cin>>NuevaCantidad;
        cout<<"Inserta nuevo precio"<<endl;
        cin>>NuevoPrecio;

        //se van los datos a la posicion dentro del vector
        costos[decision]=NuevoPrecio;
        cantidades[decision]=NuevaCantidad;
        nombres[decision]=NuevoNombre;
       
    }
}
void Inventario::menuInventario(){
    int  button,salir;
    Inventario::cargarInventario();
    button = 1;
    salir;
    
        while(salir!=2){
            system("cls");
		    cout << "<================================>" << endl;
		    cout << "<===== Menu Inventario ==========> " << endl;
		    cout << "<================================>" << endl;
	        cout << "1: Visualizar inventario " << endl;
            cout << "2: Modificar datos de producto " << endl;
            cout << "3: Agregar productos " << endl;
            cout << "4: Guardar datos " << endl;
	        cout << "0: Salir" << endl;
	   	    cout << "Que opcion quieres? "<< endl ;
		    cout<< "====================="<<endl;
	        cin >> button;
            while(button<0 or button>4 ){
                cout<<"Respuesta invalida,try again"<<endl;
                cin>>button;
            }
            if(button==1){
                   system("cls");
                   Inventario::imprimirInventario();
                   system("pause");
            }else if(button==2){
                system("cls");
                Inventario::modificarInventario();
                system("pause");

            }else if(button==3){
                    int cantidad ,costo;
                    string Nombre;
                    cin.ignore();
                    cout<<"Ingresa nombre del producto"<<endl;
                    getline(cin,Nombre);
                    cout<<"Ingresa la cantidad"<<endl;
                    cin>>cantidad;
                    cout<<"Ingresa el precio"<<endl;
                    cin>>costo;
                    nombres.push_back(Nombre);
                    cantidades.push_back(cantidad);
                    costos.push_back(costo);
                    cout<<"Producto agregado"<<endl;

            }else if(button==4){
                    system("cls");
                    Inventario::guardarInventario();
                    system("pause");
            }
            cout<<"Quieres hacer otra cosa?  1)Si 2 NO"<<endl;
            cin>>salir;
            while(salir>2 or salir<1){
                cout<<"Solo 1 o 2 try again"<<endl;
                cin>>salir;
            } 
        }
        
		    

}
void Inventario::borrarVectores(){
    nombres.clear();
    cantidades.clear();
    costos.clear();
    //para llamar a este metodo al finalizar el programa y se borre lo que haya 
    //en los vectores
}