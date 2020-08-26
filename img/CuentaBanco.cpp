 #include<iostream>

using namespace std;

class Auditable{
	public:
    virtual void revisar() = 0;
};

class Persona{
//	friend class CuentaCheques;  //Da acceso a los miembros privados de la clase
//								 // a la clase CuentaCheques
	private:
    string nombre;
    int edad;
    bool activo;
public:
    Persona();
    Persona(string nombre, int edad, bool activo);
    void inactivar();
    void activar();
    void setNombre(string);
    void setEdad(int);
    bool getActivo();
    int getEdad();
    string getNombre();

};

class CuentaBanco {
	protected:
    Persona *propietario;
    float saldo;

	public:
    CuentaBanco();
    void setPropietario(Persona *p);
    Persona *getPropietario();
    float depositar(float cantidad);
    virtual float retirar(float cantidad) = 0;
};

class CuentaCheques : public CuentaBanco, Auditable {

	public:
    float cuotaRetiro;
    CuentaCheques();
    void revisar();
    float retirar(float cantidad);
};

class CuentaAhorro : public CuentaBanco{

	public:
    float porcentajeInteresAnual;
    CuentaAhorro(float porcentajeInteresAnual);
    float depositarInteres(int numeroMeses);
    float retirar(float cantidad);
};

Persona::Persona(){
    this-> nombre = "";
    this-> edad = 0;
    this-> activo = false;
}

Persona::Persona(string nombre, int edad, bool activo){
    this-> nombre = nombre;
    this-> edad = edad;
    this-> activo = activo;
}

void Persona::inactivar(){
    cout << "Se desactivo el cliente "  <<endl;
    this->activo = false;
}

void Persona::activar(){
    cout << "Se activo el cliente " <<endl;
    this->activo = true;
}

void Persona::setNombre(string nombre){
    this->nombre = nombre;
}

void Persona::setEdad(int edad){
    this->edad = edad;
}

bool Persona::getActivo(){
    return this->activo;
}

int Persona::getEdad(){
    return this-> edad;
}

string Persona::getNombre(){
    return this->nombre;
}

CuentaBanco::CuentaBanco(){
    this-> saldo = 0;
}

float CuentaBanco::depositar(float cantidad){
    this->saldo += cantidad;
    cout << "Se depositaron : " << cantidad <<endl;
    return this->saldo;
}

void CuentaBanco::setPropietario(Persona *p){
    this->propietario = p;
}

Persona *CuentaBanco::getPropietario(){
    return this->propietario;
}


CuentaCheques::CuentaCheques(){
    this-> cuotaRetiro = 30;
}

void CuentaCheques::revisar(){
    if(this->saldo > 100000){
        this->propietario->inactivar();
    }
    else{
        cout << "Cliente revisado, ningun problema" << endl;
    }
}

float CuentaCheques::retirar(float cantidad){
    this-> saldo = saldo - cantidad - cuotaRetiro;
     cout << "Se retiraron  "<< cantidad << endl;
    return this-> saldo;
}

CuentaAhorro::CuentaAhorro(float porcentajeInteresAnual){
    this-> porcentajeInteresAnual = porcentajeInteresAnual;
}

float CuentaAhorro::depositarInteres(int numeroMeses){
    float deposito =  saldo * porcentajeInteresAnual / 100.0 / 12.0 * numeroMeses;
    this->depositar(deposito);
     cout << " . Por " << numeroMeses<< " meses." << endl;
    return this->saldo;
}

float CuentaAhorro::retirar(float cantidad){
    this->saldo = saldo - cantidad;
     cout << "Se retiraron  "<< cantidad << endl;
    return this->saldo;
}


int main(){

	Persona p("Yolanda Torres", 25, true);
	CuentaCheques ch;
	ch.setPropietario(&p);

	cout << "Depositando 100000" << endl;
	float saldo = ch.depositar(100000);
	cout << "Saldo: " << saldo << endl;

	cout << "Retirando 1000" << endl;
	saldo = ch.retirar(1000);
	cout << "Saldo: " << saldo << endl;
	cout << "Revisando ..." << endl;
	ch.revisar();

	cout << "Depositando 2000" << endl;
	saldo = ch.depositar(2000);
	cout << "Saldo: " << saldo << endl;
	cout << "Revisando ..." << endl;
	ch.revisar();

	return 0;
}
