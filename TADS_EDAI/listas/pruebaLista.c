#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
int purga(Lista *l);

int
main(void)
{
    Lista miListaA,miListaB;
    tipoPosicion p;
    int i;
	int j=9;
    tipoElemento v[]={2,8,2,2,2};
    int n =sizeof(v)/sizeof(tipoElemento);

    printf("Creando listaA vacía: %d\n", creaVacia(&miListaA));

    p = primero(&miListaA);
    for (i = 0; i < n; i++) {
        inserta(v[i],p,&miListaA);
        p = siguiente(p,&miListaA);
    }
    imprime(&miListaA);
    printf("Eliminando repetidos \n");
	//suprime(p,&miListaA);
    purga(&miListaA);
    imprime(&miListaA);

	printf("Se ejecuta primero \n");
	primero(&miListaA);

	printf("Se ejecuta fin \n");
	fin(&miListaA);

	imprime(&miListaA);

	printf("Se localiza\n");
	localiza (2,&miListaA);

	printf("Se recupera\n");
	//printf("%d\n",recupera(p,&miListaA));

    printf("Creando listaB vacía: %d\n", creaVacia(&miListaB));

    for (i = n-1; i >= 0; i--) {
		j++;
        inserta(j,fin(&miListaB),&miListaB);
    }

    
	
	
	printf("\nAhora concateno:\n");
    concatena(&miListaA, &miListaB);
	imprime(&miListaA);
	
	
    anula(&miListaA);
    destruye(&miListaA);
    
    anula(&miListaB);
    destruye(&miListaB);
	
    return 0;
}


int
purga(Lista *l)
{
    tipoPosicion act, sig;
    
    act = primero(l);
    while (act != fin(l)) {
        sig = siguiente(act,l);
        while (sig != fin(l)) {
            if (recupera(act,l) == recupera(sig,l))
                suprime(sig, l);
            else
                sig = siguiente(sig,l);
        }
        act = siguiente(act,l);
    }
    return 0;
}


