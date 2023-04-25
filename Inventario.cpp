/* Ejercicio 800. Desarrolla un programa que almacene datos en un arreglo bidimensional */

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
using namespace std;

int invent (int a[][4], string b[], int n);
 
int main(){
    system ("cls");
    int i,j,cuAntos,precioa, preciov, num,numc, x;
    int A[100][4];
    string B[100], descrip;
    srand (time(NULL));

    cout << " ---------------------------" << endl;
    cout << " ---- altas ---- " << endl;
    do {
        cout<<"Dime cuAntos productos quieres registrar (>0 y < 100) : "; cin>> num; 
    } while (num <= 0);
    for (i=0; i< num; i++){
        A[i][0] = -1;
    }

    for (i=0; i< num; i++){
        A[i][0] = i;
        cout<<"------------------------------------------------"<< endl;
        cout<<"Dime cuAntos productos compraste del producto "<< i<<endl;
        cin>> cuAntos;
        A[i][1] = cuAntos;
        cout<<"Dime el precio de adquisiciOn del producto "<< i<<endl;
        cin>> precioa;
        A[i][2] = precioa;
        cout<<"Dime el precio de venta del producto "<< i<<endl;
        cin>> preciov;
        A[i][3] = preciov;
        cout <<"Dime la descripciOn del producto " << i << endl;
        cin >> descrip;
        B[i] = descrip;
    }
    cout << " ---------------------------" << endl;
    cout<< "Inventario " << endl;
    cout<< "#p  \t #   \tpa   \tpv  \tdescrip" << endl;
    for (i=0; i< num; i++){
        for (j=0; j< 4; j++){
            cout << A[i][j] << "\t" ;
        }
        cout<< B[i];
        cout << endl;
    }
    cout << " ---------------------------" << endl;
    cout << "Ventas por nUm de producto "<< endl;
    do {
        cout<<"Dime cuAl nUmero de producto quieres comprar " <<endl;
        cin>> numc;
    } while (numc<0 || numc >= num);

    for (i=0; i< num; i++){
        if (numc== A[i][0]){
            cout << "El precio de ese producto es $ " << A[i][3] << " y quedan " << A[i][1]<< endl;
            cout << "DescripciOn " << B[i] << endl;
            if (A[i][1] > 0){
                do {
                    cout << "CuAntos quieres comprar? " ; 
                    cin >> x ;
                } while (x < 1 || x > A[i][1]);
                A[i][1] = A[i][1] - x;
            }
        }
    }
    invent (A,B,num);
    cout << " ---------------------------" << endl;
    cout << "Ventas por descripciOn de producto "<< endl;
    cout<<"Dime descripciOn de producto quieres comprar " <<endl;
    cin>> descrip;

    for (i=0; i< num; i++){
        if (descrip == B[i]){
            cout << "El precio de ese producto es $ " << A[i][3] << " y quedan " << A[i][1]<< endl;
            cout << "DescripciOn " << B[i] << endl;
            if (A[i][1] > 0){
                do {
                    cout << "CuAntos quieres comprar? " ; 
                    cin >> x ;
                } while (x < 1 || x > A[i][1]);
                A[i][1] = A[i][1] - x;
            }
            else {
                cout << "No se tiene producto, lo lamentamos " << endl;
            }
        }
    }
    invent (A,B,num);

    getch();
    return 0;
}
int invent( int a[][4], string b[], int n){
    int i,j;
    cout<< " --- Inventario --- "<< endl;
    cout<< "#p  \t #   \tpa   \tpv  \tdescrip" << endl;
    for (i=0; i< n; i++){
        for (j=0; j< 4; j++){
            cout << a[i][j] << "\t" ;
        }
        cout<< b[i];
        cout << endl;
    }
}