#include "ListaCircular.h"

ListaCircular::ListaCircular()
{
	inicio = NULL;
	fin = NULL;
}

void ListaCircular::agregar(int valor)
{
	//Crear un nuevo Nodo 
	Nodo* nuevo = new Nodo();
	nuevo->info = valor;
	if (inicio == NULL) {
		inicio = nuevo;
		fin = nuevo;
	}
	else {
		fin->sig = nuevo;
		nuevo->sig = inicio;
		fin = nuevo;
	}
}

void ListaCircular::mostrar()
{
	if (inicio == NULL) {
		cout << "Lista Circular vacia " << endl;
	}
	else {
		Nodo* reco = inicio;
		int i = 1;
		do {
			cout << i << ".- " << reco->info << endl;
			reco = reco->sig;
			i++;
		} while (reco != inicio);
		cout << "---------------------------" << endl;
	}
}

int ListaCircular::tamano()
{
	if (inicio == NULL) {
		return 0;
	}
	else {
		int i = 0;
		Nodo* reco = inicio;
		do {
			reco = reco->sig;
			i++;
		} while (reco != inicio);
		return i;
	}
}

void ListaCircular::borrar(int pos)
{
	Nodo* reco;
	Nodo* ante = inicio;
	if (inicio == NULL) {
		cout << "Lista circular vacia" << endl;
	}
	else if (pos == 0) {
		cout << "No existe no existe el elemento 0 inicia en 1" << endl;
	}
	else if (pos > tamano()) {
		cout << "la posicion " << pos << " excede el tanano de lista que es " << tamano() << endl;
	}
	else if (pos == 1){
		Nodo* borrar = inicio;
		inicio = inicio->sig;
		fin->sig = inicio;
		delete borrar;
	}
	else if (pos == tamano()) {
		Nodo* borrarUltimo;
		reco = inicio;
		int i = 0;
		do {
			i++;
			if (i == pos - 1) {
				ante = reco;
				ante->sig = inicio;
			}
			else if (i == pos) {
				borrarUltimo = reco;
				delete borrarUltimo;
			}
			reco = reco->sig;

		} while (reco != inicio);

	}
	else {
		reco = inicio->sig;
		Nodo* borrarMedio;
		int i = 1;
		do{
			i++;
			if (i == pos) {
				cout << "Posicion " << i << " con valor de " << reco->info << endl;
				borrarMedio = reco;
				ante->sig = reco->sig;
				delete borrarMedio;
				break;
			}
			else {
				ante = ante->sig;
				reco = reco->sig;
			}
			reco = reco->sig;

		} while (reco != inicio);

	}

}

