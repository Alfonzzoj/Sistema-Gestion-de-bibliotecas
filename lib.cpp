#include <iostream>
#include <stdlib.h>
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

		void printAutores(Autor autor);

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
	void printElemento(Elemento *element);
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
void printElemento(Libro book);
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
	bool activo;
	int indice;

  public:
	Elemento *prestados[15];

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

void Autor::printAutores(Autor autorcito){
		cout << "- "<<autorcito.getNombre()<<autorcito.getApellidos()<<endl;

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
void Elemento::printElemento(Elemento *element){
		cout << " "<<element->getTitulo();

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

	// Clase Libro

		Libro::Libro(): Elemento(){
			paginas = 0;
			editorial = "";
		}

		Libro::Libro(string id, string ub, string tit, int fechaP, float precio, bool sts,
				string tipo, int pag, string ed):Elemento(id, ub, tit, fechaP, precio, sts, tipo){
			paginas = pag;
			editorial = ed;
		}
void Libro::printElemento(Libro book){
		cout << " "<<book.getTitulo();

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
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
bool Prestamo::realizarPrestamo(){
	bool exito = true;

	for(int i = 0; prestados[i] != NULL && i < 5; i++){
		exito = exito && prestados[i]->prestar();
		Elemento *elem = prestados[i];
		if(elem->getTipo().compare("coleccion") == 0){							//Del array prestados tengo un Elemento de tipo Coleccion
			
			Coleccion *col ;
			col->addElemento(prestados[i]);													//Tomo la coleccion y el numelementos que tiene esta 
			int numE = col->getNumElementos();
			for(int j = 0; col->getElementos()!=NULL && j < numE; j++){			//mientras los "elementos[15] no sea null y aun no se reccorran todos los elementos de la col"
				Elemento *e = col->getElemento(j);	
				e->prestar();							//voy pasando elemento por lemento de la coleccion cambiando su estado 
				e->setEstatus(true);														//si elemento esta prestado  retorna false y se mantiene , si no esta prestado estado se convierte en true 
			}																	//convirtiendo el elemento en prestado 		
		}

	}
	activo = exito;
	return activo;
}
Prestamo hacerPrestamo(Elemento *elemento){
	Prestamo p0;
	if (elemento->isEstatus()==0)
	{

		Prestamo p1;
		p1.setFechaIni(20200805); p1.setFechaFin(20200810);

		p1.agregarPrestado(elemento);
		bool resultado = p1.realizarPrestamo();

		cout<<	" Prestamo ejecutado  "<<endl;
		return p1;
	}else if (elemento->isEstatus()==1)
	{
		cout<<	" Elemento Ya esta prestado por alguien mas  "<<endl;
	}
		return p0;



};
void Prestamo::devolverPrestamo(){
	int i=0;
	
	if (prestados[i]->isEstatus())	{
		for(i=0; prestados[i] != NULL && i < 5; i++){
			prestados[i]->setEstatus(false);
			Elemento *elem = prestados[i];

		if(elem->getTipo().compare("coleccion") == 0){							//Del array prestados tengo un Elemento de tipo Coleccion
			
			Coleccion *col ;													//Tomo la coleccion y el numelementos que tiene esta 
			int numE = col->getNumElementos();
			
			for(int j = 0; col->getElementos()!=NULL && j < numE; j++){			//mientras los "elementos[15] no sea null y aun no se reccorran todos los elementos de la col"
				Elemento *e = col->getElemento(j);
				hacerPrestamo(e);								//voy pasando elemento por lemento de la coleccion cambiando su estado 
				e->setEstatus(false);														//si elemento esta prestado  retorna false y se mantiene , si no esta prestado estado se convierte en true 
			}																	//convirtiendo el elemento en prestado 		
		}

			//Si el elemento es una coleccion entonces cambiar el estatus a cada elemento de la coleccion
		}
		activo = false;
		cout<<	" Elemento Devuelto  ";

	}else if (prestados[i]->isEstatus()==false) {
		for(i=0; prestados[i] != NULL && i < 5; i++){
			prestados[i]->isEstatus();
			//Si el elemento es una coleccion entonces cambiar el estatus a cada elemento de la coleccion
		}
	cout<<	" No puedes devolver este elemento, porque no lo tienes   "<<endl;
	}


}

//======================================================================================================
//======================================================================================================
//======================================================================================================
//======================================================================================================
//======================================================================================================
int main(){
	int opc=1;
	static int cantidadElementos=0;
	static bool band=false;


			// Cabe recalcar si un elemento tiene estatus false no esta prestado , estatus true prestado
		// Creando bibliotecas por defect
			// Creacion de bibliotecas
			// Creacion Libros (id 0-10) (Harry p Coleccion 00)
				//   id	   Ubicacion	    Titulo		          FechaP   Precio status   Tipo   pags  Editorial
				Libro l1("01", "STD01/5",   "Resistencia Materiales", 20031010, 13.2, false, "libro", 452, "Grijalba");
				Libro l2("02", "STD01/6.1", "Harry Potter I", 		  20000910, 17.3, false, "libro", 560, "Ed01");
				Libro l3("03", "STD01/6.2", "Harry Potter II", 		  20010910, 17.3, false, "libro", 570, "Ed01");
				Libro l4("04", "STD01/6.3", "Harry Potter III", 	  20020910, 17.3, false, "libro", 810, "Ed01");
			// Creacion de revistas (id 10-20) (Coleccion 10)
					//  id	 Ubicacion	    Titulo		                FechaP   Precio  status   Tipo     Pages  editorial
				Revista r2("12", "STD10/1.2", "Cocinado en casa - Grill", 	20190910, 5.3, false,   "revista", 810, "Televisa");
				Revista r3("13", "STD10/1.3", "Cocinado en casa - Asiatica",20190910, 5.3, false,   "revista", 811, "Televisa");
				Revista r1("11", "STD10/1.1", "Cocinado en casa - Marina", 	20190910, 5.3, false,   "revista", 812, "Televisa");
				Revista r4("14", "STD10/1.4", "Cocinado en casa - Italiana",20190910, 5.3, false,   "revista", 813, "Televisa");
			// Peliculas (id 20-30) (Coleccion 20)
						//   id		Ubicacion	Titulo		  FechaP   Precio   status   Tipo      dur   Genero
				Pelicula pelic1("21", "STD20/4.1", "Avengers 1 ", 20200111, 4.8, 	false,  "pelicula",1024,"Accion" );
				Pelicula pelic2("22", "STD20/4.2", "Avengers 2 ", 20200112, 5, 	 	false, 	"pelicula",1024,"Accion" );
				Pelicula pelic3("23", "STD20/4.3", "Avengers 3 ", 20200113, 6, 	 	false, 	"pelicula",1024,"Accion" );
				Pelicula pelic4("24", "STD20/4.4", "Avengers 4 ", 20200114, 7, 	 	false, 	"pelicula",1024,"Accion" );
				Pelicula pelic5("25", "STD20/4.5", "Avengers 5 ", 20200115, 80, 	false, 	"pelicula",1024,"Accion" );
			// Creacion y vinculacion de autores
				//       Name    Apellido	  FechaNa		Premio
				Autor a1("James ","Poter",19800912,	"Literarius]Maximus");
				Autor a2("Carlos ","Ortiz",19700610,	"Chef abc");
				Autor a3("Stan ","leectura",19600811,	"Pelicula del siglo ");
				Autor a4("JAKE ","fisica",19600811,	"Matematicas ");
				// Libros Harry potrer
				l1.agregarAutor(&a4);
				l2.agregarAutor(&a1);
				l3.agregarAutor(&a1);
				l4.agregarAutor(&a1);
				// Revista
				r1.agregarAutor(&a2);
				r2.agregarAutor(&a2);
				r3.agregarAutor(&a2);
				r4.agregarAutor(&a2);
				// Libros Harry potrer
				pelic1.agregarAutor(&a3);
				pelic2.agregarAutor(&a3);
				pelic3.agregarAutor(&a3);
				pelic4.agregarAutor(&a3);
				pelic5.agregarAutor(&a3);
			// cout << l1.printElemento(l1);
		// Creacion de colecciones  pueden ser creadas de 3 maneras, para este caso usaremos la forma 1
			//Forma1
			// Coleccion de libros
					//  	id	  Ubicacion	 	Titulo		 FechaP  Precio status    Tipo      Numero elementos
			Coleccion col1("00", "STD01/6", "Harry Potter", 20020910, 100, 	false, "coleccion", 3);
			col1.addElemento(&l2);
			col1.addElemento(&l3);
			col1.addElemento(&l4);
			// Coleccion de revistas
					//  	id	  Ubicacion	 	Titulo		 	FechaP  Precio status    Tipo      Numero elementos
			Coleccion col2("10", "STD10/1", "Cocinado en casa", 20020911, 50, 	false, "coleccion", 4);
			col2.addElemento(&r1);
			col2.addElemento(&r2);
			col2.addElemento(&r3);
			col2.addElemento(&r4);
			// Coleccion de peliculas
					//  	id	  Ubicacion	 	Titulo		 FechaP  Precio status    Tipo      Numero elementos
			Coleccion col3("20", "STD20/4", "The Avengers", 20200116, 200, 	false, "coleccion", 	5);
			col3.addElemento(&pelic1);
			col3.addElemento(&pelic2);
			col3.addElemento(&pelic3);
			col3.addElemento(&pelic4);
			col3.addElemento(&pelic5);

			Prestamo prestamos[16];
			Prestamo presta1;


	do
	{
	cout<<endl;
	cout<<	"            M E N U   D E  O P C I O N E S   "<<endl;
	cout<<	"       (Libros , Peliculas  ,revistas, coleccion) "<<endl;
	cout<<	"1-. Solicitar Prestamo "<<endl;
	cout<<	"2-. Ejecutar devolucion    "<<endl;
	cout<<	"0-. Exit"<<endl<<endl;
	cin>>	opc;
	switch (opc)
	{
	case 1:

		int miniopc;
		cout<<	endl<<" M E N U   D E   P R E S T A M O S  "<<endl;
		cout<<	endl<<" Que Desea solicitar  "<<endl;
		cout<<	"1-. Libro "<<endl;
		cout<<	"2-. Revista "<<endl;
		cout<<	"3-. Pelicula "<<endl;
		cout<<	"4-. Coleccion "<<endl;
		cin >> miniopc;
			if (miniopc==1)
			{
				int opclibro;
				cout <<endl<<" L I B R O S   D I S P O N I B L E S"<<endl;
				cout<<	"1-. Resistencia Materiales"<<endl;
				cout<<	"2-. Harry Potter I "<<endl;
				cout<<	"3-. Harry Potter I "<<endl;
				cout<<	"4-. Harr y Potter III "<<endl;
				cin >>opclibro;
				// Realizacion de Prestamos
				if (opclibro==1)	{
					presta1.agregarPrestado(&l1);
					prestamos[0]	=	hacerPrestamo(&l1);
				}else if (opclibro==2)	{
					presta1.agregarPrestado(&l2);
					prestamos[1]	=		hacerPrestamo(&l2);

				}else if (opclibro==3)	{
					presta1.agregarPrestado(&l3);
					prestamos[2]	=		hacerPrestamo(&l3);
				}
				else if (opclibro==4){
					presta1.agregarPrestado(&l4);
					prestamos[3]	=		hacerPrestamo(&l4);
				}


			}else if (miniopc==2)	{
				int opcRevista;
				cout <<endl<<" R E V I S T A S    D I S P O N I B L E S"<<endl;
				cout<<	"1-. Cocinado en casa - Grill"<<endl;
				cout<<	"2-. Cocinado en casa - Asiatica"<<endl;
				cout<<	"3-. Cocinado en casa - Marina"<<endl;
				cout<<	"4-. Cocinado en casa - Italiana "<<endl;
				cin >>opcRevista;
				if (opcRevista==1)	{
					// Realizacion de Prestamos
					presta1.agregarPrestado(&r1);
					prestamos[4]	=		hacerPrestamo(&r1);
				}else if (opcRevista==2)	{
					presta1.agregarPrestado(&r2);
					prestamos[5]	=		hacerPrestamo(&r2);

				}else if (opcRevista==3)	{
					presta1.agregarPrestado(&r3);
					prestamos[6]	=		hacerPrestamo(&r3);
				}
				else if (opcRevista==4){
					presta1.agregarPrestado(&r4);
					prestamos[7]	=		hacerPrestamo(&r4);
				}

			}else if (miniopc==3)	{
				int opcPelicula;
				cout <<" P E L I C U L A S     D I S P O N I B L E S"<<endl;
				cout<<	"1-. Avengers 1"<<endl;
				cout<<	"2-. Avengers 2"<<endl;
				cout<<	"3-. Avengers 3"<<endl;
				cout<<	"4-. Avengers 4 "<<endl;
				cin >>opcPelicula;
				if (opcPelicula==1)	{
					presta1.agregarPrestado(&pelic1);
					prestamos[8]	=		hacerPrestamo(&pelic1);
				}else if (opcPelicula==2)	{
					presta1.agregarPrestado(&pelic2);
					prestamos[9]	=		hacerPrestamo(&pelic2);

				}else if (opcPelicula==3)	{
					presta1.agregarPrestado(&pelic3);
					prestamos[10]	=		hacerPrestamo(&pelic3);
				}
				else if (opcPelicula==4){
					presta1.agregarPrestado(&pelic4);
					prestamos[11]	=		hacerPrestamo(&pelic4);
				}
			}
			else if (miniopc==4)	{
				int opcColeccion;
				cout <<" C O L E C C I O N E S      D I S P O N I B L E S"<<endl;
				cout<<	"1-. Harry Potter		(Libros)	"<<endl;
				cout<<	"2-. Cocinado en casa	(Revistas)"<<endl;
				cout<<	"3-. Avengers			(Peliculas)	"<<endl;
				cin >>opcColeccion;
				if (opcColeccion==1)	{
					// Realizacion de Prestamos
					presta1.agregarPrestado(&col1);
					prestamos[12]	=		hacerPrestamo(&col1);
				}else if (opcColeccion==2)	{
					presta1.agregarPrestado(&col2);
					prestamos[13]	=		hacerPrestamo(&col2);

				}else if (opcColeccion==3)	{
					presta1.agregarPrestado(&col3);
					prestamos[14]	=			hacerPrestamo(&col3);
				}
			}
	cantidadElementos++;
	band=true;
	break;

// 	CASO D E V O L U C I O N E S
	case 2:


		if (band==false)
		{
			cout<<	" No hay prestamos activos "<<endl;
		}
		else if (band==true)
		{
				cout<<	" Tiene "<<cantidadElementos<<" prestamos activos "<<endl;
			int miniopc2;
			cantidadElementos--;
			cout<<	endl<<" M E N U   D E   D E V O L U C I O N E S   "<<endl;
			cout<<	endl<<" Que Desea devolver  "<<endl;
			cout<<	"1-. Libro "<<endl;
			cout<<	"2-. Revista "<<endl;
			cout<<	"3-. Pelicula "<<endl;
			cout<<	"4-. Coleccion "<<endl;
			cin >> miniopc2;
				if (miniopc2==1)
				{
					int opclibro;
					cout <<endl<<" L I B R O S   D I S P O N I B L E S"<<endl;
					cout<<	"1-. Resistencia Materiales"<<endl;
					cout<<	"2-. Harry Potter I "<<endl;
					cout<<	"3-. Harry Potter I "<<endl;
					cout<<	"4-. Harry Potter III "<<endl;
					cin >>opclibro;
					// Realizacion de devoluciones
					if (opclibro==1)	{
						cout << l1.getTitulo();
						 presta1.devolverPrestamo();
						a4.printAutores(a4);
					}else if (opclibro==2)	{
						cout << l2.getTitulo();
						 presta1.devolverPrestamo();
						a1.printAutores(a1);

					}else if (opclibro==3)	{
						cout << l3.getTitulo();
						 presta1.devolverPrestamo();
						a1.printAutores(a1);

					}
					else if (opclibro==4){
						cout << l4.getTitulo();
						 presta1.devolverPrestamo();
						a1.printAutores(a1);

					}


				}else if (miniopc2==2)	{
					int opcRevista;
					cout <<endl<<" R E V I S T A S    D I S P O N I B L E S"<<endl;
					cout<<	"1-. Cocinado en casa - Grill"<<endl;
					cout<<	"2-. Cocinado en casa - Asiatica"<<endl;
					cout<<	"3-. Cocinado en casa - Marina"<<endl;
					cout<<	"4-. Cocinado en casa - Italiana "<<endl;
					cin >>opcRevista;
					if (opcRevista==1)	{
						// Realizacion devoluciones
						cout << r1.getTitulo();
						presta1.devolverPrestamo();
						a2.printAutores(a2);

					}else if (opcRevista==2)	{
						cout << r2.getTitulo();
						 presta1.devolverPrestamo();
						a2.printAutores(a2);

					}else if (opcRevista==3)	{
						cout << r3.getTitulo();
						 presta1.devolverPrestamo();
						a2.printAutores(a2);
					}
					else if (opcRevista==4){
						cout << r4.getTitulo();
						 presta1.devolverPrestamo();
						a2.printAutores(a2);					}

				}else if (miniopc2==3)	{
					int opcPelicula;
					cout <<" P E L I C U L A S     D I S P O N I B L E S"<<endl;
					cout<<	"1-. Avengers 1"<<endl;
					cout<<	"2-. Avengers 2"<<endl;
					cout<<	"3-. Avengers 3"<<endl;
					cout<<	"4-. Avengers 4 "<<endl;
					cin >>opcPelicula;
					if (opcPelicula==1)	{
						// Realizacion de Prestamos
						cout << pelic1.getTitulo();
						 presta1.devolverPrestamo();
						a3.printAutores(a3);
					}else if (opcPelicula==2)	{
						cout << pelic2.getTitulo();
						 presta1.devolverPrestamo();
						a3.printAutores(a3);

					}else if (opcPelicula==3)	{
						cout << pelic3.getTitulo();
						 presta1.devolverPrestamo();
						a3.printAutores(a3);
					}
					else if (opcPelicula==4){
						cout <<pelic4.getTitulo();
						 presta1.devolverPrestamo();
						a3.printAutores(a3);
					}
				}
				else if (miniopc2==4)	{
					int opcColeccion;
					cout <<" C O L E C C I O N E S      D I S P O N I B L E S"<<endl;
					cout<<	"1-. Harry Potter		(Libros)	"<<endl;
					cout<<	"2-. Cocinado en casa	(Revistas)"<<endl;
					cout<<	"3-. Avengers			(Peliculas)	"<<endl;
					cin >>opcColeccion;
					if (opcColeccion==1)	{
						// Realizacion de Prestamos
						cout <<col1.getTitulo();
						 presta1.devolverPrestamo();
						a1.printAutores(a1);
					}else if (opcColeccion==2)	{
						cout <<col2.getTitulo();
						 presta1.devolverPrestamo();
						a2.printAutores(a2);

					}else if (opcColeccion==3)	{
						cout <<col2.getTitulo();
						 presta1.devolverPrestamo();
						a3.printAutores(a3);
					}
				}
		}
		if (cantidadElementos==0)
		{
			band= false;
		}

	break;
	case 0:
		cout<<	" Gracias por preferirnos "<<endl;
	break;
	default:
		cout<<	" Ingrese opcion valida "<<endl;
	break;
	}


	// opc= 0;
	} while (opc!=0);

		return 0;
}

