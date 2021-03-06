// ABBEjemplo.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>

using namespace std;

struct Nodo
{
public:
	int codigoJugador;
	int posicion;
	int altura;
	int potencia;
	int ptsAnotados;
	int balonesAnotados;
	int rebotes;
	int tapones;
	int votacion;
	string conferencia;
	string habilidad;
	string equipo;
	Nodo *izquierdo;
	Nodo *derecho;

public:
	Nodo(int value, int posicion, int altura, int potencia,  int ptsAnotados, int balonesAnotados, 
		int rebotes,int tapones,int votacion, string conferencia, string habilidad, string equipo) {
		codigoJugador = value;
		this->posicion = posicion;
		this->altura = altura;
		this->potencia = potencia;
		this->ptsAnotados = ptsAnotados;
		this->balonesAnotados = balonesAnotados;
		this->rebotes = rebotes;
		this->tapones = tapones;
		this->votacion = votacion;
		this->conferencia = conferencia;
		this->habilidad = habilidad;
		this->equipo = equipo;


		izquierdo = NULL;
		derecho = NULL;
	};

	~Nodo() {};
};

class ArbolBB
{
public:
	Nodo *raiz;
	int* codigoJugador = new int[200];
	int* posicion = new int[200];
	int* altura = new int[200];
	int* potencia = new int[200];
	int* ptsAnotados = new int[200];
	int* balonesAnotados = new int[200];
	int* rebotes = new int[200];
	int* tapones = new int[200];
	int* votacion = new int[200];
	string *conferencia = new string[200];
	string *habilidad = new string[200];
	string *equipo = new string[200];

	
	int ultimovalor = 0;

public:
	ArbolBB() {
		raiz = NULL;
	};

	void Insertar(int value, int posicion, int altura,int potencia, int ptsAnotados, int balonesAnotados,
				  int rebotes, int tapones,int votacion,string conferencia,string habilidad ,string equipo) 
	{
		Nodo *nuevo = new Nodo(value, posicion, altura, potencia, ptsAnotados, balonesAnotados,
								rebotes,tapones,votacion,conferencia, habilidad,equipo);
	
		if (raiz == NULL) {
			raiz = nuevo;
		}
		else
		{
				if (nuevo->codigoJugador > raiz->codigoJugador){
					InsertarAux(nuevo, raiz, true);
				}
				else if (nuevo->codigoJugador< raiz->codigoJugador) {
					InsertarAux(nuevo, raiz, false);
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
			codigoJugador[ultimovalor] = miNodo->codigoJugador;
			posicion[ultimovalor] = miNodo->posicion;
			altura[ultimovalor] = miNodo->altura;
			potencia[ultimovalor] = miNodo->potencia;
			ptsAnotados[ultimovalor] = miNodo->ptsAnotados;
			balonesAnotados[ultimovalor] = miNodo->balonesAnotados;
			rebotes[ultimovalor] = miNodo->rebotes;
			tapones[ultimovalor] = miNodo->tapones;
			votacion[ultimovalor] = miNodo->votacion;
			conferencia[ultimovalor] = miNodo->conferencia;
			habilidad[ultimovalor] = miNodo->habilidad;
			equipo[ultimovalor] = miNodo->equipo;
			ultimovalor++;
		}

		//Visitar todos los hijos derechos
		if (miNodo->derecho != NULL) {
			RecorridoInOrden(miNodo->derecho);
		}

	};

	void buscar(int codigo, ofstream   &escribir)
	{
		
		Nodo *aux = raiz;
		while (aux != NULL)
		{
			if (codigo > aux->codigoJugador)
			{
				aux = aux->derecho;
			}
			else if (codigo < aux->codigoJugador)
			{
				aux = aux->izquierdo;
			}
			else
			{
				cout << "Jugador: " << aux->codigoJugador << "\n" << "Posicion: " << aux->posicion << "\n" << "Altura: " << aux->altura << "\n"
					<< "Potencia: " << aux->potencia << "\n" << "Puntos Anotados: " << aux->ptsAnotados << "\n"
					<< "Balones Anotados: " << aux->balonesAnotados << "\n" << "Rebotes: " << aux->rebotes << "\n"
					<< "Tapones: " << aux->tapones << "\n" << "Anotacion: " << aux->votacion << "\n"
					<< "Conferencia: " << aux->conferencia << "\n" << "Habilidad: " << aux->habilidad << "\n"
					<< "Equipo: " << aux->equipo << "\n" << "*************************" << endl;
				escribir<<"Se busco a: "<< "Jugador: " << aux->codigoJugador << "\n" << "Posicion: " << aux->posicion << "\n" << "Altura: " << aux->altura << "\n"
					<< "Potencia: " << aux->potencia << "\n" << "Puntos Anotados: " << aux->ptsAnotados << "\n"
					<< "Balones Anotados: " << aux->balonesAnotados << "\n" << "Rebotes: " << aux->rebotes << "\n"
					<< "Tapones: " << aux->tapones << "\n" << "Anotacion: " << aux->votacion << "\n"
					<< "Conferencia: " << aux->conferencia << "\n" << "Habilidad: " << aux->habilidad << "\n"
					<< "Equipo: " << aux->equipo << "\n" << "*************************" << endl;
				break;
			}
		}
	}
	
	void BuscarS(Nodo *miNodo,string equipo, ofstream   &escribir) {
		
		if (miNodo == raiz) {

			ultimovalor = 0;
		}

		//Visitar todos los hijos izquierdos
		if (miNodo->izquierdo != NULL) {
			BuscarS(miNodo->izquierdo,equipo,escribir);
		}

		//Visito el centro
		if (miNodo != NULL) {
			if (miNodo->equipo == equipo)
			{
				cout << miNodo->codigoJugador << endl;
				escribir<<miNodo->codigoJugador << endl;
				
			}
		}

		//Visitar todos los hijos derechos
		if (miNodo->derecho != NULL) {
			BuscarS(miNodo->derecho,equipo,escribir);
		}

	};
	void InsertarAux(Nodo *nuevo, Nodo *padre, bool esDerecho) {
			if (esDerecho) {
				if (padre->derecho == NULL) {
					padre->derecho = nuevo;
				}
				else
				{
					if (nuevo->codigoJugador > padre->derecho->codigoJugador)
					{
						InsertarAux(nuevo, padre->derecho, true);
					}
					else if (nuevo->codigoJugador < padre->derecho->codigoJugador) {
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
					if (nuevo->codigoJugador > padre->izquierdo->codigoJugador)
					{
						InsertarAux(nuevo, padre->izquierdo, true);
					}
					else if (nuevo->codigoJugador < padre->izquierdo->codigoJugador) {
						InsertarAux(nuevo, padre->izquierdo, false);
					}
				}
			}
		}
};
void leerTodos(istream &, vector< vector<string> > &);
int main()
{
	ofstream escribir;
	string a;
	fstream archivo("S1.csv", ios::in);
	escribir.open("ab.csv");
	
	typedef vector< vector<string> > vectorDatos;
	vectorDatos doc1;
	leerTodos(archivo, doc1);
	for (vectorDatos::iterator i = doc1.begin() + 1; i != doc1.end(); ++i)
	{
		for (vector<string>::iterator j = i->begin(); j != i->end(); ++j)
		{
			a = *j;
			escribir << a << "-";
		}
		escribir << "\n";
	}
	escribir.close();
	archivo.close();

	std::ifstream temporal("ab.csv");
	std::string codigoJugador, posicion, altura,  potencia, ptsAnotados, balonesAnotados, rebotes, tapones, votacion, conferencia, habilidad, equipo;
	std::getline(temporal, codigoJugador, '-');
	std::getline(temporal, posicion, '-');
	std::getline(temporal, altura, '-');
	std::getline(temporal, potencia, '-');
	std::getline(temporal, ptsAnotados, '-');
	std::getline(temporal, balonesAnotados, '-');
	std::getline(temporal, rebotes, '-');
	std::getline(temporal, tapones, '-');
	std::getline(temporal, votacion, '-');
	std::getline(temporal, conferencia, '-');
	std::getline(temporal, habilidad, '-');
	std::getline(temporal, equipo, '-');


	ArbolBB *Arbol = new ArbolBB();

	while (temporal) {
		Arbol->Insertar(atoi(codigoJugador.c_str()), atoi(posicion.c_str()), atoi(altura.c_str()),
			atoi(potencia.c_str()), atoi(ptsAnotados.c_str()),atoi(balonesAnotados.c_str()),
			atoi(rebotes.c_str()),atoi(tapones.c_str()), atoi(votacion.c_str()),conferencia,habilidad,equipo);
		std::getline(temporal, codigoJugador, '-');
		std::getline(temporal, posicion, '-');
		std::getline(temporal, altura, '-');
		std::getline(temporal, potencia, '-');
		std::getline(temporal, ptsAnotados, '-');
		std::getline(temporal, balonesAnotados, '-');
		std::getline(temporal, rebotes, '-');
		std::getline(temporal, tapones, '-');
		std::getline(temporal, votacion, '-');
		std::getline(temporal, conferencia, '-');
		std::getline(temporal, habilidad, '-');
		std::getline(temporal, equipo, '-');
	}
	temporal.close();
	escribir.open("ab.csv");
	cout << "Los valores son" << endl;
	Arbol->RecorridoInOrden(Arbol->raiz);
	for (int i = 0; i < Arbol->ultimovalor; i++) {
		cout << 
			"Jugador: "<< Arbol->codigoJugador[i]<<"\n" << "Posicion: " << Arbol->posicion[i] << "\n" << "Altura: " << Arbol->altura[i] << "\n" 
			<< "Potencia: " << Arbol->potencia[i] << "\n" << "Puntos Anotados: " << Arbol->ptsAnotados[i] << "\n" 
			<< "Balones Anotados: " <<Arbol->balonesAnotados[i] << "\n" << "Rebotes: " << Arbol->rebotes[i] << "\n"
			<< "Tapones: " <<Arbol->tapones[i] << "\n" << "Anotacion: "<< Arbol->votacion[i] << "\n" 
			<< "Conferencia: " <<Arbol->conferencia[i] << "\n" << "Habilidad: "<< Arbol->habilidad[i] << "\n"
			<<"Equipo: " << Arbol->equipo[i] <<"\n"<<"*************************"<< endl;
		
		escribir << 
			Arbol->codigoJugador[i] << "-" << Arbol->posicion[i] << "-" << Arbol->altura[i] << "-" << Arbol->potencia[i] << "-"
			<< Arbol->ptsAnotados[i] << "-" << Arbol->balonesAnotados[i] << "-" << Arbol->rebotes[i] << "-" <<Arbol->tapones[i]<< "-"
			<< Arbol->votacion[i] << "-" <<Arbol->conferencia[i] << "-" << Arbol->habilidad[i] << "-" 
			<< Arbol->equipo[i] << "-" << endl;

	}
	
	escribir.close();
	bool salir=false;
	int opcion;
	int busqueda;
	string busquedaS;
	ofstream escribirN;
	escribirN.open("Reporte.csv");
	while (salir != true)
	{
		cout << "Para ver la informacion de algun jugador presione 1" << endl;
		cout << "Para ver la informacion de algun equipo presione 2" << endl;
		cout << "Para simular jugada presione 3" << endl;
		cout << "Para salir presione cualquier otro numero" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			cout << "Ingrese el codigo del jugador: " << endl;
			cin >> busqueda;
			Arbol->buscar(busqueda,escribirN);
			break;
		case 2: 
			cout << "Ingrese nombre del equipo: " << endl;
			cin >> busquedaS; 
			cout << "Codigos de jugadores: " << endl;
			escribirN << "Se busco a integrantes del equipo: " + busquedaS<<endl;
			escribirN << "Codigos de jugadores: " << endl;
			Arbol->BuscarS(Arbol->raiz, busquedaS,escribirN);
			cout << "**********************" << endl;
			escribirN << "**********************" << endl;

			break;
		case 3:
			int jugada;
			cout << "ingrese la jugada que desea relizar" << endl;
			cout << "Jugada 1" << endl;
			cout << "Jugada 2" << endl;
			cin >> jugada;

			switch (jugada)
			{
			case 1:
			{
				// tres jugadores aleatorios
				int opt = 0;
				cout << "Que equipo desea jugar" << endl;
				//ofensiva
				cout << "su equipo jugador es" << endl;
				cout << "base pasa la pelota" << endl;
				cout << "el alero recibe la pelota y dribla" << endl;
				cout << " que opcion desea relizar?" << endl;
				cout << "1. tirar" << endl;
				cout << "2. Pasar la pelota al pivote" << endl;
				cin >> opt;
				switch (opt)
				{
				case 1:
				{
					bool canasta = false;
					int tiro;
					cout << "como desea tirar la pelota?" << endl;
					cout << "1. de frente" << endl;
					cout << "2. de lado" << endl;
					cout << "3. tres pasos y tiro" << endl;
					cin >> tiro;

					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "el equipo contrario roba la pelota" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro == 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
				}
				break;
				case 2:
				{
					bool canasta = false;
					int tiro;
					cout << "pivote recibe la pelota y debe tirar" << endl;
					cout << "como desea tirar la pelota?" << endl;
					cout << "1. de frente" << endl;
					cout << "2. de lado" << endl;
					cout << "3. tres pasos y tiro" << endl;
					cin >> tiro;
					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "roba la pelota" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro = 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestadotiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
				}
				break;
				default:
					break;
				}
			}
			case 2:
			{
				int equi = 0;
				cout << "con que equipo desea jugar?" << endl;
				cout << "1.DKS" << endl;
				cout << "2.GST" << endl;
				cout << "3.NBA" << endl;
				cout << "4.Spyas" << endl;
				cout << "5.LVK" << endl;
				cin >> equi;

				if (equi == 1)
				{
					int tiro;
					cout << "tiro libre de DKS, DOnde desea tirar" << endl;
					cout << "1. al frente" << endl;
					cout << "2. atras " << endl;
					cout << "3. al centro" << endl;
					cin >> tiro;

					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "el equipo contrario roba la pelota y usted tiene una falta" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro == 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}


				}

				if (equi == 2)
				{
					int tiro;
					cout << "tiro libre de GST, DOnde desea tirar" << endl;
					cout << "1. al frente" << endl;
					cout << "2. atras " << endl;
					cout << "3. al centro" << endl;
					cin >> tiro;

					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "el equipo contrario roba la pelota y usted tiene una falta" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro == 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}


				}

				if (equi == 3)
				{
					int tiro;
					cout << "tiro libre de NBA, DOnde desea tirar" << endl;
					cout << "1. al frente" << endl;
					cout << "2. atras " << endl;
					cout << "3. al centro" << endl;
					cin >> tiro;

					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "el equipo contrario roba la pelota y usted tiene una falta" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro == 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}


				}


				if (equi == 4)
				{
					int tiro;
					cout << "tiro libre de Spyas, DOnde desea tirar" << endl;
					cout << "1. al frente" << endl;
					cout << "2. atras " << endl;
					cout << "3. al centro" << endl;
					cin >> tiro;

					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "el equipo contrario roba la pelota y usted tiene una falta" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro == 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}


				}


				if (equi == 5)
				{
					int tiro;
					cout << "tiro libre de LVK, DOnde desea tirar" << endl;
					cout << "1. al frente" << endl;
					cout << "2. atras " << endl;
					cout << "3. al centro" << endl;
					cin >> tiro;

					if (tiro == 1)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "el equipo contrario roba la pelota y usted tiene una falta" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted a encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}
					if (tiro == 2)
					{
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;

						}

						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "alero para el driple" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted ha encestado tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}

					if (tiro == 3) {
						int defensa;
						int num, c;
						srand(time(NULL));

						for (c = 1; c <= 10; c++)
						{
							num = rand() % 51;
						}

						return 0;
						int ran;
						ran = num % 2;
						if (ran == 0)
						{
							cout << "pivote tapa el tiro" << endl;
							cout << "**********************" << endl;
						}
						else
						{
							cout << "usted tiene 3 puntos" << endl;
							cout << "**********************" << endl;
						}
					}


				}


			}
			  break;
			   default:
				break;
			}
			break;
		default: salir = true; break;
		}
	}
	cout << "HASTA PRONTO :D"<<endl;
	system("pause");

}
void leerTodos(istream &entrada, vector< vector<string> > &salida)
{
	string linea;
	while (getline(entrada, linea))
	{
		istringstream leer(linea);
		vector<string> columna;
		string parte;

		while (getline(leer, parte, '-'))
		{
			columna.push_back(parte);
		}
		salida.push_back(columna);
	}
}
