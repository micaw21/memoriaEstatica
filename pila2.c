#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20

//Definicion de Tipos
typedef char tString[50];
typedef tString tVectorMarcas[20];
typedef int tVector[20];
typedef struct{
	tVectorMarcas marca;
	tVector pulgadas;
	int tope;
}rTelevisores;

//Variables Globales
rTelevisores televisor;

//Prototipo de Funciones
void inicializarPila();
bool pilaVacia(rTelevisores);
bool pilaLlena(rTelevisores);
void apilarTelevisores();
void listarPilaTelevisores();
void consultarCantidad();
int contarMayores(int);
void retirarTelevisores();
void detectarTelevisorEnTope();


int main() {
	inicializarPila();
	apilarTelevisores();
	listarPilaTelevisores();
	consultarCantidad();
	retirarTelevisores();
	return 0;
}

//Implementacion
void inicializarPila() {
	televisor.tope = -1;
	printf("Pila inicializada!\n\n");
}

bool pilaVacia(rTelevisores pTelevisor) {
	return (pTelevisor.tope == -1);
}

bool pilaLlena(rTelevisores pTelevisor) {
	return (pTelevisor.tope == (20 - 1));
}

void apilarTelevisores() {
	char respuesta;
	int pulgadas;
	
	if(pilaVacia(televisor)) {
		
		televisor.tope ++;
		
		do {
			printf("Ingrese pulgada de televisor: ");
			scanf("%d",&televisor.pulgadas[televisor.tope]);
		} while (televisor.pulgadas[televisor.tope] > 21);
				
		fflush(stdin);
				
		printf("Ingrese marca del televisor: ");
		gets(televisor.marca[televisor.tope]);
		
		printf("Ingresar otro televisor?\n");
		printf("s-Si, n-No: ");
		fflush(stdin);	
		scanf("%c",&respuesta);
		
	} else {
		printf("\tPila llena!\n");
	}
	
	fflush(stdin);
	
	while (respuesta == 's' || respuesta == 'S') {
	
		televisor.tope++;
			
		do {
			printf("Ingrese pulgada de televisor: ");
			scanf("%d",&televisor.pulgadas[televisor.tope]);
			
			if(televisor.pulgadas[televisor.tope] > televisor.pulgadas[televisor.tope-1]) {
					
				printf("No se puede apilar una caja grande sobre otra chica!\n\n");
			} 
				
		} while (televisor.pulgadas[televisor.tope] > televisor.pulgadas[televisor.tope-1]);
			
		fflush(stdin);
			
		printf("Ingrese marca del televisor: ");
		gets(televisor.marca[televisor.tope]);
			
		printf("Ingresar otro televisor?\n");
		printf("s-Si, n-No: ");
		fflush(stdin);	
		scanf("%c",&respuesta);
	}
}

void listarPilaTelevisores() {
	int respuesta = 0;
	printf("Desea ver la pila de televisores?\n");
	printf("1-Si, 2-No: ");
	scanf("%d",&respuesta);
	while(respuesta == 1) {
	
		int i;
		int max = televisor.tope;
		printf("\tLista de Televisores Apilados\n");
		for(i=0;i<= max;i++) {
			printf("Marca: %s - Pulgadas: %d\n",televisor.marca[i],televisor.pulgadas[i]);
		}
	}
}


void consultarCantidad() {
	int x = 0;
	do {
		printf("\n\nIngrese un valor de pulgadas: ");
		scanf("%d",&x);
		if(x > 20) {
			printf("No puede ser mayor a 20 pulgadas!\n\n");
		}
	} while (x > 20);
	
	int cantidad = contarMayores(x);
	printf("La cantidad de televisores con mayores pulgadas que %d es de: %d\n\n",x,cantidad);
	
}

int contarMayores(int pX) {
	int i;
	int contador = 0;
	int max = televisor.tope;
	for(i=0;i<=max;i++) {
		if(televisor.pulgadas[i] > pX) {
			contador++;
		}
	}
	return contador;
}


void retirarTelevisores() {
	int respuesta = -1;
	printf("Desea desapilar una caja?\n");
	printf("1-Si, 2-No: ");
	scanf("%d",&respuesta);
	while (respuesta == 1) {
		
		if(pilaVacia(televisor)) {
			printf("La pila esta vacia!\n\n");
		} else {
			televisor.tope --;
			detectarTelevisorEnTope();
		}
		printf("Desea desapilar otra caja?\n");
		printf("1-Si, 2-No: ");
		scanf("%d",&respuesta);
	}
	
}
void detectarTelevisorEnTope() {
	tString marca;
	strcpy(marca, televisor.marca[televisor.tope]);
	int pulgadas = televisor.pulgadas[televisor.tope];
	printf("Televisor en tope\n");
	printf("Marca: %s - Pulgadas: %d\n\n",marca, pulgadas);
}


