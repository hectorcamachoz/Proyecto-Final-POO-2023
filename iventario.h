// Clase padre
class iventario{
    protected:
        int dinero;
    public:
        iventario(int _dinero);
        virtual void mostrarDinero();
        virtual void gastar();
        virtual float RegresarDinero();
        ~iventario();
};

// primera clase con herencia
class envio  : public iventario{
    public:
        envio(int _dinero);// el dinero lo hereda de general
        void mostrarDinero();
        void gastar();
        int regresarDinero();
};

// derivacion de funciones
// Pruebas general
iventario::iventario(int _dinero){
    dinero = _dinero;
}

void iventario::mostrarDinero(){
    cout << "El dinero es " << dinero << endl;
}

void iventario::gastar(){
    cout << "Gasto general";
}

float iventario::RegresarDinero(){
    return dinero;
}

iventario::~iventario(){}


// Probando 1
envio::envio(int _dinero) : iventario(_dinero){
    dinero = _dinero;
}

void envio::mostrarDinero(){
    iventario::mostrarDinero();
    cout << "Probando 1" << endl;
}

void envio::gastar(){
    dinero = dinero - 10;
}

int envio::regresarDinero(){
    return dinero;
}