#include "vector"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int COLUMNAS = 3;
const int FILAS = 5;
class promocion {
   private:
    int matriz[FILAS][COLUMNAS];
    string nombres[FILAS][COLUMNAS];

   public:
    promocion();
    void GuardarCambiosEnArchivo( string nombreArchivo);

    void ActualizarMATRIZ( string nombreArchivo); 
    void imprimirMatriz(); 
    void modificarValor(int fila, int Valor,int operacion);
    void menu(); 

};
promocion::promocion(){
    // Inicializar la matriz con valores predeterminados(solo ocurre la primera que se corre el programa)
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                matriz[i][j] = 0;
            }
        }
        nombres[0][0] = "2x1";
        nombres[1][0] = "50%";
        nombres[2][0] = "20% ";
        nombres[3][0] = "-100$";
        nombres[4][0] = "Envio gratis";
       
}
void promocion::GuardarCambiosEnArchivo(string nombreArchivo){
    ofstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    archivo << setw(3) << matriz[i][j] << " ";
                }
                archivo << endl;
            }

            archivo.close();
            cout << "Datos guardados exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar los datos." << endl;
        }

}
void promocion::ActualizarMATRIZ( string nombreArchivo){
    ifstream archivo(nombreArchivo);

        if (archivo.is_open()) {
            int valor;

            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    archivo >> valor;
                    matriz[i][j] = valor;
                }
            }

            archivo.close();  
        } 
}

void promocion::imprimirMatriz(){
    int numOp=1;
        for (int i = 0; i < FILAS; i++) {
            //for (int j = 0; j < COLUMNAS; j++) {}
                
                cout <<"Opcion.- "<<numOp<< setw(3) <<"|"<< matriz[i][0] <<"|  "<<nombres[i][0] <<" ";
                numOp=numOp+1;
            
            cout << endl;
        }
}
void promocion::modificarValor(int fila, int Valor,int Operacion){
   if (fila >= 0 or fila < FILAS) {
         if(Operacion==1){
            matriz[fila][0]+=Valor;
         }else if(Operacion==2){
            matriz[fila][0]-=Valor;
         }else if(Operacion==3){
            matriz[fila][0] = Valor;
         }
    } else {
        cout << "Opcion inválida." << endl;
    }
}
void promocion::menu(){
    promocion::ActualizarMATRIZ("Promociones_Cantidades.txt");

    int  fila,valor;
    int eleccion,eleccOp;
    cout << "*************************************************"  <<endl;
    cout << "*******       Menu de Promociones     *************" <<endl;
    cout << "*************************************************"  <<endl;
    cout <<" 1) Mostrar promociones                       "<<endl;
    cout <<" 2) Modificar Cantidades                        "<<endl;
    cout<<"Que eliges"<<endl;
    cin>>eleccion;//eleccion solo para elegir menu
    while(eleccion>2 or eleccion<1){
        cout<<"No se puede, solo 1 o 2 ,try again"<<endl;
        cin>>eleccion;
    }
    if (eleccion==1){
        promocion::imprimirMatriz();
        
    }else{
        system("cls");
        promocion::imprimirMatriz();
        cout<<" "<<endl;
        cout << "Que opcion de promocion? ";
        cin >> fila;
        while(fila<0 or fila >5){//no hay opcion aarriba de 5
         cout<<"Respuesta incorrecta,try again"<<endl;
         cin>>fila;
        }
        fila=fila-1;//porque se cuenta desde el 0
        cout<<"Que operacion harás?  Suma(1)  Resta(2) Dar nuevo valor(3)"<<endl;
        cin>>eleccOp;
        while(eleccOp>3 or eleccOp<1){
         cout<<"No se puede, solo 1  2  o 3,try again"<<endl;
         cin>>eleccOp;
        }

        cout << "Que valor ";
        cin >> valor;
        while(valor<0 ){//por si pone negativos
         cout<<"Respuesta incorrecta,try again"<<endl;
         cin>>valor;
        }

        promocion::modificarValor(fila,valor,eleccOp);
        promocion::GuardarCambiosEnArchivo("Promociones_Cantidades.txt");
        cout<<"Lista modificada"<<endl;
        promocion::imprimirMatriz();

    }
}