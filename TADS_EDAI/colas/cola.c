#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "cola.h"



int colaCreaVacia(Cola *c)
{
    c->frente=NULL;
    c->fondo=NULL;

	return 1;
    
}

int colaVacia(Cola *c)
{
    
    if(c->frente==NULL && c->fondo==NULL){
	return 1;
	}	else{
		return 0;
		}
    
}


int colaInserta(Cola *c,tipoElemento elemento)
{
    
    tipoCelda *nuevaC;

	nuevaC=(tipoCelda *) malloc(sizeof(tipoCelda));
	
	if(nuevaC==NULL)
	return -2;

	nuevaC->sig=NULL;
	nuevaC->elemento=elemento;
	
	if(colaVacia(c)){
	c->frente=nuevaC;
	c->fondo=nuevaC;
	return 1;
	}

	//La siguiente celda a la que apunta fondo
	c->fondo->sig=nuevaC;
	c->fondo=nuevaC;
    return 1;
}

tipoElemento colaSuprime(Cola *c)
{

	tipoCelda *aux;
	tipoElemento elemento;
    
	if(colaVacia(c))
	return -1;

	aux=c->frente;
	elemento=aux->elemento;
	c->frente=c->frente->sig;
	//Si se borra el ultimo nodo que hay el fondo tambien apunta a null
	if(c->frente==NULL){
	c->fondo=NULL;	
	free(c->frente);
	}

	free(aux);
    
return elemento;
}







