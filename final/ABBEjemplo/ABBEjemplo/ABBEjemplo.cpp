// ABBEjemplo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Nodo
{
public:
	int id;
	string nombre;
	int telefono;
	int edad;
	string direccion;
	Nodo *izquierdo;
	Nodo *derecho;

public:
	Nodo(int value,string nombre,int telefono,int edad,string direccion) {
		id = value;
		this->nombre = nombre;
		this->telefono = telefono;
		this->edad = edad;
		this->direccion = direccion;
		izquierdo = NULL;
		derecho = NULL;
	};

	~Nodo() {};
};

class ArbolBB
{
public:
	Nodo *raiz;
	int* id = new int[150];
	string *nombre = new string[150];
	int* telefono = new int[150];
	int* edad = new int[150];
	string *direccion = new string[150];

	int ultimovalor = 0;

public:
	ArbolBB() {
		raiz = NULL;
	};

	void Insertar(int value,string nombre,int telefono,int edad,string direccion) {
		Nodo *nuevo = new Nodo(value,nombre,telefono,edad,direccion);
		if (raiz == NULL) { 
			raiz = nuevo;
		}
		else 
		{
			if (buscar(value == true))
			{
				value = value * rand() % 100+1;
				if (nuevo->id > raiz->id) {
					InsertarAux(nuevo, raiz, true);
				}
				else if (nuevo->id < raiz->id) {
					InsertarAux(nuevo, raiz, false);
				}
			}
			else
			{
				if (nuevo->id > raiz->id) {
					InsertarAux(nuevo, raiz, true);
				}
				else if (nuevo->id < raiz->id) {
					InsertarAux(nuevo, raiz, false);
				}
			}
		
		}
	};
	
	void RecorridoInOrden(Nodo *miNodo) {
		
		if (miNodo == raiz) {
			 
			ultimovalor = 0;
		}

		//Visitar todos los hijos izquierdos
		if (miNodo->izquierdo != NULL) {
			RecorridoInOrden(miNodo->izquierdo);
		}

		//Visito el centro
		if (miNodo != NULL) {
			id[ultimovalor] = miNodo->id;
			nombre[ultimovalor] = miNodo->nombre;
			telefono[ultimovalor] = miNodo->telefono;
			edad[ultimovalor] = miNodo->edad;
			direccion[ultimovalor] = miNodo->direccion;
			ultimovalor++;
		}

		//Visitar todos los hijos derechos
		if (miNodo->derecho != NULL) {
			RecorridoInOrden(miNodo->derecho);
		}
		
	};
	/*
	void RecorridoPreOrden(Nodo *miNodo) {

		if (miNodo == raiz) {
			salida = new int[100];
			ultimovalor = 0;
		}

		//Visito el centro
		if (miNodo != NULL) {
			salida[ultimovalor] = miNodo->dato;
			ultimovalor++;
		}

		//Visitar todos los hijos izquierdos
		if (miNodo->izquierdo != NULL) {
			RecorridoInOrden(miNodo->izquierdo);
		}
		
		//Visitar todos los hijos derechos
		if (miNodo->derecho != NULL) {
			RecorridoInOrden(miNodo->derecho);
		}

	};

	void RecorridoPostOrden(Nodo *miNodo) {

		if (miNodo == raiz) {
			salida = new int[100];
			ultimovalor = 0;
		}

		//Visitar todos los hijos izquierdos
		if (miNodo->izquierdo != NULL) {
			RecorridoInOrden(miNodo->izquierdo);
		}

		//Visitar todos los hijos derechos
		if (miNodo->derecho != NULL) {
			RecorridoInOrden(miNodo->derecho);
		}

		//Visito el centro
		if (miNodo != NULL) {
			salida[ultimovalor] = miNodo->dato;
			ultimovalor++;
		}

	};
	*/
	bool buscar(int id)
	{
		Nodo *aux = raiz;
		while (aux != NULL)
		{
			if (id > aux->id)
				aux = aux->derecho;

			else if (id < aux->id)
				aux = aux->izquierdo;
			else
				return true;
		}
		return false;
	}

private:
	void InsertarAux(Nodo *nuevo, Nodo *padre, bool esDerecho) {
		if (esDerecho) {
			if (padre->derecho == NULL) { 
				padre->derecho = nuevo;
			}
			else 
			{
				if (nuevo->id > padre->derecho->id)
				{
					InsertarAux(nuevo, padre->derecho, true);
				}
				else if (nuevo->id < padre->derecho->id) {
					InsertarAux(nuevo, padre->derecho, false);
				}
			}
		}
		else
		{
			if (padre->izquierdo == NULL) {
				padre->izquierdo = nuevo;
			}
			else
			{
				if (nuevo->id > padre->izquierdo->id)
				{
					InsertarAux(nuevo, padre->izquierdo, true);
				}
				else if (nuevo->id < padre->izquierdo->id) {
					InsertarAux(nuevo, padre->izquierdo, false);
				}
			}
		}
	}	
};
void leerTodos(istream &, vector< vector<string> > &);
int main()
{
	/*
	do
	{
		cout << "Seleccione su opción: " << endl;
		cout << "1. insertar valor" << endl;
		cout << "2. Recorrido en Orden" << endl;
		cout << "3. Recorrido en Preorden" << endl;
		cout << "4. Recorrido en Postorden" << endl;
		cout << "5. Eliminar valor" << endl;
		cout << "0. Salir" << endl;
		cin >> opt;

		switch (opt)
		{
		case 0: {
			cout << "Adios..." << endl;
		}break;

		case 1:{
			cout << "Ingrese el valor a insertar" << endl;
			int value = 0;
			cin >> value;
			miArbolBB->Insertar(value);
			cout << "Insertado exitosamente " << endl;
		}break;

		case 2: {
			cout << "Los valores son" << endl;
			miArbolBB->RecorridoInOrden(miArbolBB->raiz);
			for (int i = 0; i < miArbolBB->ultimovalor; i++) {
				cout << miArbolBB->salida[i] << endl;
			}
			cout << "fin" << endl;

		}break;

		case 3: {
			cout << "Los valores son" << endl;
			miArbolBB->RecorridoPreOrden(miArbolBB->raiz);
			for (int i = 0; i < miArbolBB->ultimovalor; i++) {
				cout << miArbolBB->salida[i] << endl;
			}
			cout << "fin" << endl;

		}break;

		case 4: {
			cout << "Los valores son" << endl;
			miArbolBB->RecorridoPostOrden(miArbolBB->raiz);
			for (int i = 0; i < miArbolBB->ultimovalor; i++) {
				cout << miArbolBB->salida[i] << endl;
			}
			cout << "fin" << endl;

		}break;

		case 5: {
			cout << "Ingrese el valor a eliminar" << endl;
			int value = 0;
			cin >> value;
			miArbolBB->EliminarNodo(NULL, miArbolBB->raiz, false, value);
			cout << "Eliminado exitosamente " << endl;
		}break;

		default:
			cout << "Opción no válida" << endl;
			break;
		}

	} while (opt != 0);
	*/
	ofstream escribir;
	string a;
	fstream archivo("S1.csv", ios::in);
	fstream archivo1("S2.csv", ios::in);
	fstream archivo2("S3.csv", ios::in);
	escribir.open("ab.csv");

		typedef vector< vector<string> > vectorDatos;
		vectorDatos doc1;
		vectorDatos doc2;
		vectorDatos doc3;
		
		leerTodos(archivo, doc1);
		leerTodos(archivo1, doc2);
		leerTodos(archivo2, doc3);
		for (vectorDatos::iterator i = doc1.begin()+1; i != doc1.end(); ++i)
		{
			for (vector<string>::iterator j = i->begin(); j != i->end(); ++j)
			{
				a = *j;
				cout << a << " ";
				escribir << a << ",";

			}
			escribir << "\n";
			cout << "\n";
		}
		for (vectorDatos::iterator i = doc2.begin()+1; i != doc2.end(); ++i)
		{
			for (vector<string>::iterator j = i->begin(); j != i->end(); ++j)
			{
				a = *j;
				cout << a << " ";
				escribir << a << ",";

			}
			escribir << "\n";
			cout << "\n";
		}
		for (vectorDatos::iterator i = doc3.begin()+1; i != doc3.end(); ++i)
		{
			for (vector<string>::iterator j = i->begin(); j != i->end(); ++j)
			{
				a = *j;
				cout << a << " ";
				escribir << a << ",";
			}
			escribir << "\n";
			cout << "\n";
		}
		escribir.close();
		std::ifstream temporal("ab.csv");
		
		std::string id,nombre,telefono,edad,direccion;
		
		std::getline(temporal, id, ',');
		std::getline(temporal, nombre, ',');
		std::getline(temporal, telefono, ',');
		std::getline(temporal, edad, ',');
		std::getline(temporal, direccion, ',');

		ArbolBB *Arbol = new ArbolBB();

		while (temporal) {
			Arbol->Insertar(atoi(id.c_str()), nombre, atoi(telefono.c_str()), atoi(edad.c_str()), direccion);
			std::getline(temporal, id, ',');
			std::getline(temporal, nombre, ',');
			std::getline(temporal, telefono, ',');
			std::getline(temporal, edad, ',');
			std::getline(temporal, direccion, ',');
		}
		temporal.close();
		//CODIGO SI SE NECESITA INGRESAR UN DATO ANTES DE PROCEDER A GUARDAR LOS DATOS :T
		escribir.open("ab.csv");
		cout << "Los valores son" << endl;
		Arbol->RecorridoInOrden(Arbol->raiz);
		for (int i = 0; i < Arbol->ultimovalor; i++) {
			cout << Arbol->id[i] << "," << Arbol->nombre[i] << "," << Arbol->telefono[i] << "," << Arbol->edad[i] << "," <<
				Arbol->direccion[i] << "," << endl;

			escribir << Arbol->id[i]<<","<< Arbol->nombre[i] << ","<< Arbol->telefono[i] << ","<< Arbol->edad[i] << "," <<
				      Arbol->direccion[i] << ","<<endl;
			
		}
		escribir.close();
		system("pause");

	return 0;
}

void leerTodos(istream &entrada, vector< vector<string> > &salida)
{
	string linea;
	while (getline(entrada, linea))
	{
		istringstream leer(linea);
		vector<string> columna;
		string parte;
	
		while (getline(leer, parte, ','))
		{
			columna.push_back(parte);
		}
		salida.push_back(columna);
	}
}
