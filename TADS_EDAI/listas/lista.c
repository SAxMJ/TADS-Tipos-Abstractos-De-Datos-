#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lista.h"



int
creaVacia(Lista *l)
{
    if (l == NULL)
        return -2;
    else if (NULL == (l->raiz = l->ultimo = (tipoCelda *)malloc(sizeof(tipoCelda))))
        return -1;
    else {
        l->raiz->sig = NULL;
        return 0;
    }
}


int
vacia(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig == NULL)
        return 1;
    else
        return 0;
}

int
destruye(Lista *l)
{
    if (l == NULL || l->raiz == NULL) {
        return -1;
    }
    else if (l->raiz->sig != NULL){
        return -2;
    }
    else {
        free(l->raiz);
        l->raiz = l->ultimo = NULL;
        return 0;
    }
}


void
imprime(Lista *l)
{
    tipoCelda *aImprimir;
    int posicion;
    
    if (l == NULL || l->raiz == NULL) {
        return;
    }
    else {
        posicion = 1;
        aImprimir = l->raiz->sig;
        while (aImprimir != NULL) {
            printf("Valor: %d en posición: %d\n",aImprimir->elemento, posicion++);
            aImprimir = aImprimir->sig;
        }
    }
}

tipoPosicion
anterior(tipoPosicion p, Lista *l)
{
    tipoCelda *anterior;
    
    if (l == NULL || l->raiz == NULL || p == NULL) {
        return NULL;
    }
    else if (p == l->raiz){
        return l->raiz;
    }
    else {
        anterior = l->raiz;
        while (anterior->sig != p)
            anterior = anterior->sig;
        return anterior;
    }
}


tipoPosicion
primero(Lista *l)
{
	if(l->raiz==NULL){
	fin(l);
	}	else{
		return l->raiz;
		}
}


tipoPosicion
fin(Lista *l)
{
tipoPosicion tp;
	if(l==NULL){
    	printf("ERROR: La lista no existe\n");
    	return NULL;
    }
    tp=l->ultimo;
	while(tp->sig!=NULL){
		tp=tp->sig;
	}
    return tp;   
}



//En inserta creo que tendíamos que llamar antes a la funcion anterior

int
inserta(tipoElemento x, tipoPosicion p, Lista *l)
{
	
	tipoPosicion postemp;

	//Si lista vacia
	if(l==NULL){
	return -3;
	}

	//Posicion de memoria apunta a nada
	if(p==NULL){
	return -2;
	}

	if(l->raiz==NULL)
	return -1;

	postemp=(tipoCelda *) malloc(sizeof(tipoCelda));
	if(postemp==NULL)
	return -1;

	if(p==fin(l)){
	p->sig=postemp;
	postemp->elemento=x;
	postemp->sig=NULL;
	l->ultimo=postemp;
	return 1;
	}

	postemp->elemento=x;
	postemp->sig=p->sig;
	p->sig=postemp;
	
	//if(postemp->sig==NULL)
		//l->ultimo=postemp;

	return 1;
}



tipoElemento
suprime (tipoPosicion p, Lista *l)
{

	tipoPosicion postemp;

    if(l==NULL)
	return -3;
	if(p==NULL)
	return -2;
	if(l->raiz==NULL)
	return -1;

	postemp=p->sig;
    p->sig=postemp->sig;
    free(postemp);

    if(p->sig==NULL){
    l->ultimo=p;
	}
	return 0;
	
    
}



tipoPosicion
siguiente(tipoPosicion p,Lista *l)
{
    
	if(l==NULL)
	return NULL;
	if(p==NULL)
	return NULL;

	if(p==fin(l))
	return fin(l);
	
    return p->sig;
}




tipoPosicion
localiza (tipoElemento x, Lista *l)
{
	
	tipoPosicion auxpos;
	
	if(l==NULL)
	return NULL;

	auxpos=(l->raiz)->sig;
	while(auxpos->sig!=NULL){
		if(auxpos->elemento==x){
		return auxpos;
		}
		auxpos=auxpos->sig;
	}

	return fin(l);	
}



tipoElemento
recupera(tipoPosicion p, Lista *l)
{

	if(l==NULL)
	return -3;
	if(p==NULL)
	return -2;

	if(p==fin(l)){
	return fin(l)->elemento;
	}
	

	return (p->sig)->elemento;
    
}


int
anula(Lista *l)
{
	tipoPosicion auxpos;
	tipoPosicion temp;

	if(l==NULL)
	return -3;

	auxpos=(l->raiz)->sig;
	
	while(auxpos!=NULL){
	temp=auxpos;
	auxpos=auxpos->sig;
	free(temp);
	}

	l->ultimo=l->raiz;
	return 0;
    
}

int
concatena(Lista *lA, Lista *lB)
{
	
	if(lA==NULL)
	return -4;

	if(lB==NULL)
	return -3;
	
	lA->ultimo->sig=lB->raiz->sig;
	(lA->ultimo)=(lB->ultimo);
	lB->raiz->sig=NULL;
	lB->ultimo=NULL;
	
return 0;

}



