#pragma once
#include "Nodo.h"
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

class ListaEnlazada{
private:
	Nodo* primero;
	int cantidadElementos();
	Nodo* ultimo;
public:
	ListaEnlazada(void);
	bool estaVacia(void);
	void agregar(int);
	void insertar(int,int);
	void imprimir(void);
	void eliminar(int);
	Nodo* Buscar(int);

};
#endif // !NODO_H
