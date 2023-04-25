#include<iostream>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
using namespace std;

string userAdmin = "uno";
string contraAdmin = "2023";
string userUsuario = "acceso";
string contraUsuario = "2022";
string userEmpleado = "dos";
string contraEmpleado = "2024";

int main(){
    string usuario, password;
    int contador = 0;
    bool ingresa = false;
    bool user = false;
    bool admin = false;
    bool empleado = false;
    do{
    cout <<"\t\t\tLOGIN DE USUARIO (LaCafe)"<<endl;
        cout<<"\t\t\t------------------------" <<endl;
        cout<<"\n\tUsuario: ";
        cin >> usuario;
        cout << "\tPassword: ";
        cin >> password;

        if ((usuario == userUsuario && password == contraUsuario) or (usuario == userAdmin && password == contraAdmin) or (usuario == userEmpleado && password == contraEmpleado)) {
            if(usuario == userUsuario && password == contraUsuario){
                user = true;
            }
            else if (usuario == userAdmin && password == contraAdmin){
                admin = true;
            }
            else{
                empleado = true;
            }
            ingresa=true;
        } else {
            cout<<"\n\tEl usuario y/o password son incorrectos " <<endl;
            contador++;

        }
    } while(ingresa==false && contador<3);
    
    if(ingresa==false){
        cout<< "-----Usted no pudo ingresar al sistema por varios intentos. Hasta la próxima----"<<endl;
        return 0;
    }else{
        cout<<"\n\tBienvenido al sistema!!! " <<endl;
    }
    
    if(user){
        cout<<"\tUsted ha ingresado al sistema como usuario." <<endl<<endl;
        //funciones de usuario/
        cout<<"\tPresione cualquier tecla para continuar";
        getch();
        system("cls");
        //aquí debería empezar todo lo de empleado y admin, debe ir dentro de este if
    }
    else if(admin){
        cout<<"\tUsted ha ingresado al sistema como administrador." <<endl;
        cout<<"\tIngrese la fecha"<<endl;
        cout<<"Presione cualquier tecla para continuar";
        getch();
        system("cls");
        //funciones de admin/
    }
    else{
        cout<<"\t\tUsted ha ingresado al sistema como empleado." <<endl;
        cout<<"Presione cualquier tecla para continuar";
        getch();
        system("cls");
        //funciones de empleado/
    }
    return 0;
	}
