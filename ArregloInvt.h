// crear una clase donde se pueda abrir, imprimir, modificar el inventario y guardarlo en un archivo de texto
#include "fstream" // archivos
#include "iomanip" // setw();
#include "cctype" // para eliminar espacios en blanco
#include "algorithm"
#include "iostream"
#include "string"
using namespace std;
const int COLUMNAS = 3; // se define el tamanio del arreglo
const int FILAS = 3;   

class ArregloInvt{
    private:
    string invent[FILAS][COLUMNAS]; // arreglo para el inventario
    public:
    ArregloInvt(); // constructor
    //void arreglo(); // se pasan los datos del archivo de texto a un arreglo para poder modificarlos
    void imprimirInvt(); // se imprime el arreglo
    void guardar(string nombreArchivo);      // se guardan los datos del arreglo en el archivo de texto
    void modificar(int fila, int Valor,int operacion);    // cambios
    void menuInvt();
    ~ArregloInvt(); // destructor
};

// Derivacion de funciones
ArregloInvt::ArregloInvt(){
    ifstream archivo;  // instanciando la clase para leer archivos
    string nombre, cantidad, costo; // agrupación
    int contador = 0;

    archivo.open("inventario.txt");
    if(archivo.is_open()){ //validamos si está abierto
       // vamos a leer cada columna de datos separados por la ","
       // guardar cada columna en el arreglo//////////////////////////////////////////////////////////
       while(getline(archivo, nombre, ',')){// tomamos todo hasta la , / siempre y cuando exista un valor en el archivo esto avanza
            getline(archivo, cantidad, ',');
            getline(archivo, costo, ',');
            nombre.erase(std::remove_if(nombre.begin(), nombre.end(), ::isspace), nombre.end()); // se eliminan espacios en blanco
            cantidad.erase(std::remove_if(cantidad.begin(), cantidad.end(), ::isspace), cantidad.end()); // se eliminan espacios en blanco
            costo.erase(std::remove_if(costo.begin(), costo.end(), ::isspace), costo.end()); // se eliminan espacios en blanco
            invent[contador][0] = nombre;
            invent[contador][1] = cantidad;
            invent[contador][2] = costo;
            contador += 1;
        }
       archivo.close(); //cerramos el archivo
    } else {
        cout << "No se pudo abrir el archivo!" << endl;
    }
    cout << endl;
}

/*void ArregloInvt::arreglo(){
}*/

void ArregloInvt::imprimirInvt(){
    int i,j;
    cout << " ----------- Inventario ----------- "<< endl;
    cout << "Nombre   \tCantidad   \tCosto" << endl;
    cout << "------------------------------------" << endl;
    for (i=0; i< FILAS; i++){
        for (j=0; j< 3; j++){
            cout << invent[i][j] << "\t\t" ;
        }
        cout << endl;
    }
}

void ArregloInvt::guardar(string nombreArchivo){
    ofstream archivo(nombreArchivo);
        if (archivo.is_open()) {
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    archivo << invent[i][j] << ",";
                }
                if(i <=2 ){
                    archivo << endl;
                }
            }
            archivo.close();
            cout << "Datos guardados exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo para guardar los datos." << endl;
        }
}

void ArregloInvt::modificar(int fila, int Valor,int operacion){}

void ArregloInvt::menuInvt(){
    char salir, button;
    salir = 'n';
    button = '1';
    string nombre, nombreN;
    bool encontrado = false;
    do { // ciclo para repetir menu
        do{
            //ArregloInvt::arreglo();
            encontrado = false;
            system("cls");
		    cout << "<================================>" << endl;
		    cout << "<===== Menu Inventario ==========> " << endl;
		    cout << "<================================>" << endl;
	        cout << "1: Visualizar inventario " << endl;
            cout << "2: Cambiar nombre de producto " << endl;
            cout << "3: Agregar productos " << endl;
            cout << "4: Modificar precio " << endl;
	        cout << "0: Regresar" << endl;
	   	    cout << "Que opcion quieres? "<< endl ;
		    cout<< "====================="<<endl;
	        cin >> button;
		    switch (button) {
			    case '1':
                    system("cls");
                    ArregloInvt::imprimirInvt();
                    system("pause");
			        break;
                case '2':
                    // opcion para cambiar el nombre de los productos
                    system("cls");
                    cout << "-----Modificar nombre-----" << endl;
                    cout << "A que producto le quiere cambiar el nombre? ";
                    cin >> nombre;
                    for(int i = 0; i < 3; i++){
                        if(invent[i][0] == nombre){
                            cout << "Cual es el nuevo nombre? ";
                            cin >> nombreN;
                            invent[i][0] = nombreN;
                            encontrado = true;
                        }
                    }
                    if(encontrado == false){
                        cout << "No se encontro el producto, intente con otro nombre la proxima" << endl;
                    }
                    system("pause");
                    break;
                case '3':
                    //esto es pura curiosidad
                    cout << "primera fila posicion 0 " << invent[0][0] << "d" << endl;
                    cout << "segunda fila posicion 0 " << invent[1][0] << "d" << endl;
                    cout << "tercera fila posicion 0 " << invent[2][0] << "d" << endl;
                    system("pause");
                    break;
		        case '0':
		  	        cout << "regresar " << endl;
			        break;
		        default:
			        cout << "error en opciOn " << endl;
		    }    
        } while (button!='0');
        cout << "Desea regresar si o no? (Escribir s o n) "; // regresar a menu de inventario
        cin >> salir;
    }while(salir =='n'); // ciclo para repetir menu
    ArregloInvt::guardar("inventario.txt");
}

ArregloInvt::~ArregloInvt(){}
