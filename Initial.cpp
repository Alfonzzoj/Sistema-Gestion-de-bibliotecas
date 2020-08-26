#include <iostream>
using namespace std;

class Autor{
	string nombre;
	string apellidos;
	int fechaNacimiento;
	string premios;

	public:
	Autor();
	Autor(string nom, string ape, int fechaNac,	string prem);
	string getApellidos();
	void setApellidos(string);
	int getFechaNacimiento();
	void setFechaNacimiento(int);
	string getNombre();
	void setNombre(string);
	string getPremios();
	void setPremios(string);
};


class Elemento{
	protected:
	string idElemento;
	string ubicacion;
	string titulo;
	int fechaPublicacion;
	float precioPrestamo;
	bool estatus;
	string tipo;
	int ultimoIndice;

	Autor *autores[10];

	public:
	Elemento();
	Elemento(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo);

	bool isEstatus();
	void setEstatus(bool);
	int getFechaPublicacion();
	void setFechaPublicacion(int);
	string getIdElemento();
	void setIdElemento(string);
	float getPrecioPrestamo();
	void setPrecioPrestamo(float);
	string getTipo();
	void setTipo(string);
	string getTitulo();
	void setTitulo(string);
	string getUbicacion();
	void setUbicacion(string);

	void agregarAutor(Autor *autor);
	Autor **getAutores();

	bool prestar();
	void virtual limpiar() = 0;
};


class Prestable{
	public:
	virtual bool verificarPrestamo() = 0;
};

class Libro: public Elemento, public Prestable{
	int paginas;
	string editorial;

	public:
	Libro();
	Libro(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int pag, string ed);
	int getPaginas();
	void setPaginas(int);
	string getEditorial();
	void setEditorial(string);

	void limpiar();							//Debe implementarse ya que es virtual en Elemento
	bool verificarPrestamo();	  //Debe implementarse ya que es virtual en Prestable

};


class Revista: public Elemento, public Prestable{
	int paginas;
	string editorial;

	public:
	Revista();
	Revista(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int pag, string ed);
	int getPaginas();
	void setPaginas(int);
	string getEditorial();
	void setEditorial(string);

	void limpiar();							//Debe implementarse ya que es virtual en Elemento
	bool verificarPrestamo();	  //Debe implementarse ya que es virtual en Prestable
	bool prestar();							//No es necesario que se implemente, pero Revista decide hacerlo para mejorar la operacion

};

class Pelicula: public Elemento{
	int duracion;
	string genero;

	public:
	Pelicula();
	Pelicula(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int dur, string gen);

	void setDuracion(int);
	int getDuracion();
	void setGenero(string);
	string getGenero();

	void limpiar();							//Debe implementarse ya que es virtual en Elemento

};

class Coleccion: public Elemento{
	int numElementos;
	int indice;
	Elemento *elementos[15];

	public:
	Coleccion();
	Coleccion(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int numE);
	Coleccion(Elemento **elementos, string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int numE);
	int getNumElementos();
	void setNumElementos(int numE);

	void addElemento(Elemento *);
	Elemento *getElemento(int ind);

	void setElementos(Elemento **elementos);
	Elemento **getElementos();
	void limpiar();							//Debe implementarse ya que es virtual en Elemento

};

class Prestamo{
	int fechaIni;
	int fechaFin;
	Elemento *prestados[15];
	bool activo;
	int indice;

  public:

	Prestamo();
	void setFechaIni(int fechaIni);
	int getFechaIni();
	void setFechaFin(int fechaFin);
	int getFechaFin();
	bool isActivo();

	void agregarPrestado(Elemento *);
	bool realizarPrestamo();
	void devolverPrestamo();
};


//Clase Autor

Autor::Autor(){
	nombre = "";
	apellidos = "";
	premios = "";
	fechaNacimiento = 0;
}

Autor::Autor(string nom, string ape, int fechaNac,	string prem){
	nombre = nom;
	apellidos = ape;
	premios = prem;
	fechaNacimiento = fechaNac;

}
string Autor::getApellidos(){
	return apellidos;
}

void Autor::setApellidos(string ape){
	apellidos = ape;
}

int Autor::getFechaNacimiento(){
	return fechaNacimiento;
}

void Autor::setFechaNacimiento(int fechaNac){
	fechaNacimiento = fechaNac;
}

string Autor::getNombre(){
	return nombre;
}

void Autor::setNombre(string nom){
	nombre = nom;
}

string Autor::getPremios(){
	return premios;
}

void Autor::setPremios(string prem){
	premios = prem;
}

//Clase Elemento
Elemento::Elemento(){
	idElemento = "";
	estatus = false;
	fechaPublicacion = 0;
	precioPrestamo = 0.0;
	tipo = "";
	titulo = "";
	ubicacion = "";
	ultimoIndice = -1;
}

Elemento::Elemento(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo){
	idElemento = id;
	ubicacion = ub;
	titulo = tit;
	fechaPublicacion = fechaP;
	precioPrestamo = precio;
	estatus = sts;
	this->tipo = tipo;
	ultimoIndice = -1;
}

bool Elemento::isEstatus(){
	return estatus;
}

void Elemento::setEstatus(bool est){
	estatus = est;
}

int Elemento::getFechaPublicacion(){
	return fechaPublicacion;
}

void Elemento::setFechaPublicacion(int fechaP){
	fechaPublicacion = fechaP;
}

string Elemento::getIdElemento(){
	return idElemento;
}

void Elemento::setIdElemento(string id){
	idElemento = id;
}

float Elemento::getPrecioPrestamo(){
	return precioPrestamo;
}

void Elemento::setPrecioPrestamo(float precioP){
	precioPrestamo = precioP;
}

string Elemento::getTipo(){
	return tipo;
}

void Elemento::setTipo(string tip){
	tipo = tip;
}

string Elemento::getTitulo(){
	return titulo;
}

void Elemento::setTitulo(string tit){
	titulo = tit;
}

string Elemento::getUbicacion(){
	return ubicacion;
}

void Elemento::setUbicacion(string ub){
	ubicacion = ub;
}

void Elemento::agregarAutor(Autor *autor){
	ultimoIndice++;
	autores[ultimoIndice] = autor;
}

Autor **Elemento::getAutores(){
	return autores;
}


bool Elemento::prestar(){
	if (estatus){ //Se encuentra prestado
		return false;
	}else{				//No est� prestado
		estatus = true;
		return true;
	}
}

//Clase Libro

Libro::Libro(): Elemento(){
	paginas = 0;
	editorial = "";
}

Libro::Libro(string id, string ub, string tit, int fechaP, float precio, bool sts,
		string tipo, int pag, string ed):Elemento(id, ub, tit, fechaP, precio, sts, tipo){
	paginas = pag;
	editorial = ed;
}

int Libro::getPaginas(){
	return paginas;
}

void Libro::setPaginas(int pag){
	paginas = pag;
}

string Libro::getEditorial(){
	return editorial;
}

void Libro::setEditorial(string ed){
	editorial = ed;
}

void Libro::limpiar(){
	cout << "El libro con id: " << idElemento << " se est� limpiando" << endl;
}

bool Libro::verificarPrestamo(){
	return prestar();
}

//Clase Revista

Revista::Revista(): Elemento(){
	paginas = 0;
	editorial = "";
}

Revista::Revista(string id, string ub, string tit, int fechaP, float precio, bool sts,
		string tipo, int pag, string ed):Elemento(id, ub, tit, fechaP, precio, sts, tipo){
	paginas = pag;
	editorial = ed;
}

int Revista::getPaginas(){
	return paginas;
}

void Revista::setPaginas(int pag){
	paginas = pag;
}

string Revista::getEditorial(){
	return editorial;
}

void Revista::setEditorial(string ed){
	editorial = ed;
}


void Revista::limpiar(){
	cout << "La revista con id: " << idElemento << " se est� limpiando" << endl;
}

bool Revista::verificarPrestamo(){
	return prestar();
}

bool Revista::prestar(){
	bool resultado = Elemento::prestar();
	if(resultado){
		cout << "Enviando mensaje de prestamo de revista" << endl;
	}
	return resultado;
}

//Clase Pelicula

Pelicula::Pelicula(): Elemento(){
	duracion = 0;
	genero = "";
}

Pelicula::Pelicula(string id, string ub, string tit, int fechaP, float precio, bool sts,
		string tipo, int dur, string gen):Elemento(id, ub, tit, fechaP, precio, sts, tipo){
	duracion = dur;
	genero = gen;
}

int Pelicula::getDuracion(){
	return duracion;
}

void Pelicula::setDuracion(int dur){
	duracion = dur;
}

string Pelicula::getGenero(){
	return genero;
}

void Pelicula::setGenero(string gen){
	genero = gen;
}

void Pelicula::limpiar(){
	cout << "La Pelicula con id: " << idElemento << " se est� limpiando" << endl;
}


//Clase Coleccion
Coleccion::Coleccion():Elemento(){
	numElementos = 0;
	indice = -1;
	int i;
	for(i = 0; i < 15; i++){
		elementos[i] = NULL;
	}
}

Coleccion::Coleccion(string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int numE):
		Elemento(id, ub, tit, fechaP, precio, sts, tipo){
	numElementos = numE;
	indice = -1;
	int i;
	for(i = 0; i < 15; i++){
		elementos[i] = NULL;
	}
}

Coleccion::Coleccion(Elemento **elems, string id, string ub, string tit, int fechaP, float precio, bool sts, string tipo, int numE):
				Elemento(id, ub, tit, fechaP, precio, sts, tipo){
		numElementos = numE;
		indice = -1;

		int i;
		for(i = 0; i < 15; i++){
			elementos[i] = NULL;
		}

		for(i = 0; elems[i] != NULL && i < 15; i++){
			indice++;
			elementos[i] = elems[i];
		}
}

int Coleccion::getNumElementos(){
	return numElementos;
}

void Coleccion::setNumElementos(int numE){
	numElementos = numE;
}

void Coleccion::addElemento(Elemento *elem){
	if(elem != NULL && indice < 14){
		indice++;
		elementos[indice] = elem;
	}

}

Elemento *Coleccion::getElemento(int ind){
	return elementos[ind];
}

void Coleccion::setElementos(Elemento **elems){
	indice = -1;

	int i;
	for(i = 0; i < 15; i++){
		elementos[i] = NULL;
	}

	for(i = 0; elems[i] != NULL && i < 15; i++){
		indice++;
		this->elementos[i] = elems[i];
	}
}

Elemento **Coleccion::getElementos(){
	return elementos;
}

void Coleccion::limpiar(){
	cout << "La coleccion con id: " << idElemento << " se est� limpiando" << endl;
}


//Clase Prestamo

Prestamo::Prestamo(){
	fechaIni = fechaFin = 0;
	activo = false;
	indice = -1;
	for(int i = 0; i < 5; i++){
		prestados[i] = NULL;
	}
}

void Prestamo::setFechaIni(int fechaIni){
	this->fechaIni = fechaIni;
}

int Prestamo::getFechaIni(){
	return fechaIni;
}

void Prestamo::setFechaFin(int fechaFin){
	this->fechaFin = fechaFin;
}

int Prestamo::getFechaFin(){
	return fechaFin;
}

bool Prestamo::isActivo(){
	return activo;
}

void Prestamo::agregarPrestado(Elemento *elem){
	if(elem != NULL){
		indice++;
		prestados[indice] = elem;
	}
}

bool Prestamo::realizarPrestamo(){
	bool exito = true;

	for(int i = 0; prestados[i] != NULL && i < 5; i++){
		exito = exito && prestados[i]->prestar();
		Elemento *elem = prestados[i];
		if(elem->getTipo().compare("coleccion") == 0){
			//Iterar por los elementos de la coleccion y prestar cada uno.
		}

	}
	activo = exito;
	return activo;
}

void Prestamo::devolverPrestamo(){
	for(int i = 0; prestados[i] != NULL && i < 5; i++){
		prestados[i]->setEstatus(false);
		//Si el elemento es una coleccion entonces cambiar el estatus a cada elemento de la coleccion
			if(elem->getTipo().compare("coleccion") == 0){
			//Iterar por los elementos de la coleccion y prestar cada uno.
		}

	}
	activo = false;
}

int main(){
	Libro l1("01", "STD01/5", "Resistencia Materiales", 20031010, 13.2, false, "libro", 452, "Grijalba");
	Libro l2("02", "STD02/6.1", "Harry Potter I", 20000910, 17.3, false, "libro", 560, "Ed01");
	Libro l3("03", "STD02/6.2", "Harry Potter II", 20010910, 17.3, false, "libro", 570, "Ed01");
	Libro l4("04", "STD02/6.3", "Harry Potter III", 20020910, 17.3, false, "libro", 810, "Ed01");
	Revista r1("05", "STD05/1", "Muy Interesante 1024", 20190910, 5.3, false, "revista", 810, "Televisa");

	//Forma1
	Coleccion col1("06", "STD02/6", "Harry Potter", 20020910, 50, false, "coleccion", 3);
	col1.addElemento(&l2);
	col1.addElemento(&l3);
	col1.addElemento(&l4);

	//Forma2
	//Coleccion col2("06", "STD02/6", "Harry Potter", 20020910, 50, false, "coleccion", 3);
	//Elemento *arr1[15] = {&l2, &l3, &l4, NULL};
	//col2.setElementos(arr1);

	//Forma3
	//Elemento *arr2[15] = {&l2, &l3, &l4, NULL};
	//Coleccion col3(arr2, "06", "STD02/6", "Harry Potter", 20020910, 50, false, "coleccion", 3);

	Prestamo p1;
	p1.setFechaIni(20200805);
	p1.setFechaFin(20200810);
	p1.agregarPrestado(&l1);
	p1.agregarPrestado(&col1);
	bool resultado = p1.realizarPrestamo();

	cout << "prestamo 1: " << resultado << endl;

	//p1.devolverPrestamo();

	Prestamo p2;
	p2.setFechaIni(20200805);
	p2.setFechaFin(20200810);
	p2.agregarPrestado(&l3);
	resultado = p2.realizarPrestamo();

	cout << "prestamo 2: " << resultado << endl;

	return 0;
}
