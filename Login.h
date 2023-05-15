/* 
Usuario y contraseña en un archivo clase
*/

#include "iostream"
#include "fstream" // manejo de archivos
using namespace std;

class Login{
    private:
        string usuario;
        string contrasena;
        ofstream archivo;
        ifstream leer;
        bool encontradoUsuario;
        bool encontradoContra;
    public:
        Login();
        void crearCuenta();
        void ponUsuario();
        void ponContrasena();
        ~Login();
};


Login::Login(){
    string usuario = "----";
    string contrasena = "------";
    bool encontradoUsuario = false;
    bool encontradoContra = false;
}
void Login::crearCuenta(){
    string contra;
    int w = 0;
     archivo.open("login.txt", ios::app);

    if(archivo.is_open()){
        cout << "Ingrese su usuario: ";
        getline(cin, usuario);
        //usuario.append(".");
        archivo << usuario << endl;


        cout << "Ingrese contraseña: ";
        getline(cin, contrasena);
        
        do {
            cout << "Porfavor ingrese de nuevo su contraseña para confirmar: ";
            getline(cin,contra);
            if(contrasena == contra){
                cout << "Se ha creado tu cuenta" << endl;
                w = 1;
                //contrasena.append(".");
                archivo << contrasena << endl;
            }else{
                cout << "La contraseña es distinta favor de ingresar de nuevo" << endl;

            }
        }while(w == 0);

        archivo.close();
        
    }
}
void Login::ponUsuario(){
    
    int w = 0;
    do {
        leer.open("login.txt", ios::binary);
        if(leer.is_open()){

            string busqueda = "---";
            string linea;
            
            
            cout << "Ingrese su usuario: ";
            getline(cin, usuario);
            busqueda = usuario;
            
            while(getline(leer,linea)){
                if(linea.find(busqueda) != string::npos){ //busca la palabra
                    
                    encontradoUsuario = true; // cambiamos la bandera a verdadero
                    
                    cout << "Se ha encontrado la palabra en el archivo" << endl; 
                    w = 1;
                } 
            }
            
            if(!encontradoUsuario){
                    cout << "Usuario incorrecto. Intente de nuevo" << endl;
            }
        
            leer.close();

        }else{
            cout << "La pagina esta caida una disculpa..." << endl;
        }
    } while(w == 0);

}
void Login::ponContrasena(){
    int w = 0;
    int c = 3;
    do {
        leer.open("login.txt", ios::binary);
        
        if(leer.is_open()){
            string busqueda = "---";
            string linea;

            cout << "Ingrese su contraseña: ";
            getline(cin, contrasena);
            busqueda = contrasena;

            while(getline(leer,linea)){
                if(linea.find(busqueda) != string::npos){ //busca la palabra
                    
                    encontradoContra = true; // cambiamos la bandera a verdadero
                    
                    cout << "Se ha encontrado la palabra en el archivo" << endl; 
                    w = 1;
                } 
            }
            if(w == 0){
                cout << "Palabra no encontrada" << endl;
                c = c-1;
                cout << "Le quedan " << c << " intentos." << endl;
                
                if(c==0){
                    cout << "Ha pasado el numero de intentos... Se cerrara el programa" << endl;;
                    break;
                }
            }
        }else{
            cout << "El archivo no se puede abrir" << endl;
        }
        leer.close();
    }while(w==0);
}
Login::~Login(){}
