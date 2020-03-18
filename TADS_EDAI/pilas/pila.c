#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "pila.h"


int pilaCreaVacia(Pila *p)
{
    *p=NULL;

return 0;	
}

int pilaVacia(Pila *p)
{
   if(*p==NULL)
	return 1;
		else
		 return 0;
    
}


//EXPLICACION DE PILAINSERTA:
//Creamos un nueva celda y le insertamos el elemento, después con el puntero
//siguiente de la celda apuntamos a lo que apunta pila y por último con pila
//apuntamos a la nueva celda creada
int pilaInserta(Pila *p,tipoElemento elemento)
{
	tipoCelda *nCelda;

	nCelda= (tipoCelda *) malloc (sizeof (tipoCelda));
	if(nCelda==NULL){
	return -2;
	}	

	if(pilaVacia(p)){
	nCelda->elemento=elemento;
	nCelda->sig=NULL;
	*p=nCelda;
	return 1;
	} 
		else{		
		nCelda->elemento=elemento;
		nCelda->sig=*p;
		*p=nCelda; 
		return 1;
	  	}  
}

//ELIMINAMOS EL NODO AL QUE APUNTA PILA Y DEVOLVEMOS EL VALOR QUE TIENE ALMACENADO
//Para ello utilizamos un puntero auxiliar que le informe a pila cual es el siguiente valor que tiene que apuntar y se libera la celda/nodo que apunta el puntero auxiliar.
tipoElemento pilaSuprime(Pila *p)
{

	tipoCelda *aux;
	tipoElemento elimina;

	if(pilaVacia(p))
	return -1;

	aux=*p;
	elimina=aux->elemento;
	*p=aux->sig;
	free(aux);

return elimina;   
}




