#include "ListaEnlazada.h"
#include <iostream>
using std::cout;

ListaEnlazada::ListaEnlazada(void) :primero(nullptr), ultimo(nullptr) {}

bool ListaEnlazada::estaVacia() {
	return primero == nullptr;
}

		// primero=45   ultimo =45  -> siguiente=65;
		// ultimo->65  ultimo =nuevo(45)

void ListaEnlazada::agregar(int _Valor) {
	Nodo* nuevo = new Nodo(_Valor, nullptr);
	if (estaVacia())
	{
		primero = nuevo;

	}
	else {
		primero->setSiguiente(nuevo);
		nuevo->setSiguiente(ultimo);
		ultimo = nuevo;

	}
}
void ListaEnlazada::imprimir(void) {
	Nodo* actual = primero;
	while (actual != nullptr)
	{
		cout << "[" << actual->getValor() << "]";
		actual = actual->getSiguiente();
	}
}
void ListaEnlazada::insertar(int posicion, int valor) {
	if (posicion > cantidadElementos())
	{
		cout << "Error: Posicion de Nodo Incorrecta!";
		return;
	}
	Nodo* nuevo = new Nodo(valor, nullptr);
	if (estaVacia())
	{
		primero = nuevo;
		ultimo = nuevo;
	}
	else
	{
		int posRecorrido = 1;
		Nodo* actual = primero;
		Nodo* anterior = nullptr;
		while (actual != nullptr)
		{
			if (posicion == posRecorrido)
			{
				if (actual == primero)
				{
					nuevo->setSiguiente(primero);
					primero = nuevo;
				}
				else
				{
					anterior->setSiguiente(nuevo);
					nuevo->setSiguiente(actual);
				}
			}
			anterior = actual;
			actual = actual->getSiguiente();
			posRecorrido++;
		}

	}

}
int ListaEnlazada::cantidadElementos() {
	Nodo* actual = primero;
	int cantidad = 0;
	while (actual != nullptr)
	{
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}
void ListaEnlazada::eliminar(int valor) {
	Nodo* anterior = nullptr;
	Nodo* actual = primero;
	if (estaVacia())
		return;
	else
	{
		while (actual!=nullptr)
		{
			if (valor=actual->getValor())
			{
				if (actual==primero)
				{
					primero = actual->getSiguiente();
					delete actual;
				}
				else if (actual == ultimo) {
					ultimo = anterior;
					ultimo->setSiguiente(nullptr);
					delete actual;
				}
				else 
				{
					anterior->setSiguiente(actual->getSiguiente());
					delete actual;
				}
				return;
			}
		}
		anterior = actual;
		actual = actual->getSiguiente();

	}
}
