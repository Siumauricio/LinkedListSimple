#pragma once
#ifndef NODO_H
#define NODO_H

class Nodo {

private:
	int valor;
	Nodo* siguiente;
public:
	Nodo(void);
	Nodo(int,Nodo*);
	~Nodo(void);//Eliminar la memoria

	void setValor(int);
	int getValor(void);
	void setSiguiente(Nodo*);
	Nodo* getSiguiente(void);
};
#endif
