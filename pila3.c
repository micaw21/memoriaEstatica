#include <stdio.h>
#include <stdbool.h>
#define MAX 8

//Definicion de Tipos
typedef int tVectorId [MAX];
typedef struct {
	tVectorId nroIdentificacion;
	int tope;
}rContenedores;

//Variables Globales
rContenedores contenedor;
int respuesta = 0;

//Prototipo de Funciones
void inicializarPila();
bool pilaVacia(rContenedores);
bool pilaLlena(rContenedores);
void elegirMenu();
void menu();
void ingresarContenedor();
void egresarContenedor();

int main() {
	inicializarPila();
	elegirMenu();
	return 0;
}

//Implementacion
void inicializarPila() {
	contenedor.tope = -1;
	printf("Pila inicializada!\n\n");
}

bool pilaVacia(rContenedores pContenedor) {
	return(pContenedor.tope == -1);
}

bool pilaLlena(rContenedores pContenedor) {
	return(pContenedor.tope == MAX - 1);
}

void elegirMenu() {
	printf("\tMENU\n");
	printf("1 - Ingresar Contenedor\n2 - Egresar Contenedor\n3 - Salir\n ");
	scanf("%d",&respuesta);
	menu();
}

void menu() {
	switch(respuesta) {
		case 1:
			ingresarContenedor();
			elegirMenu();
		break;
		case 2:
			egresarContenedor();
			elegirMenu();
		break;
		case 3:
		break;
		default:
			printf("Numero equivocado!\n");
			elegirMenu();
		break;
	}
}

void ingresarContenedor(){
	if(pilaLlena(contenedor)) {
		printf("La pila esta llena!\n");
	} else {
		contenedor.tope++;
		printf("Ingrese numero de identificacion: ");
		scanf("%d",&contenedor.nroIdentificacion[contenedor.tope]);
	}
}

void egresarContenedor() {
	if(pilaVacia(contenedor)) {
		printf("No hay contenedores por egresar!\n");
	} else {
		contenedor.tope--;
	}
}
