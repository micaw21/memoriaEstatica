#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 30

//Definicion de Tipos
typedef char tString [50];
typedef struct{
	tString editorial;
	int ISBN;
	tString titulo;
}tLibros;


typedef struct{
	tLibros libro[MAX];
	int tope;
}tPila;

//Variables Globales
tPila pilaLibros;

//Prototipo de Funciones
void inicializarPila();
bool pilaVacia(tPila);
bool pilaLlena(tPila);
void elegirMenu();
void opcionesMenu(int);
void apilarLibros();
void listar5Libros();
void desapilarLibros();
void libroEnTope();

int main() {
	inicializarPila();
	elegirMenu();
	
	return 0;
}

//Implementacion
void inicializarPila(){
	pilaLibros.tope = -1;
	printf("Pila inicializada!\n");
}
void elegirMenu() {
	int respuesta = 0;
	printf("\nElija una opcion: \n");
	printf("1-Apilar libro\n2-Listar ultimos 5 libros\n3-Desapilar libros\n4-Detectar libro en tope\n5-Salir: ");
	scanf("%d",&respuesta);
	opcionesMenu(respuesta);
}

void opcionesMenu(int pRespuesta){
	switch(pRespuesta) {
		case 1:
			apilarLibros();
			elegirMenu();
		break;
		case 2: 
			listar5Libros();
			elegirMenu();
		break;
		case 3:
			desapilarLibros();
			elegirMenu();
		break;
		case 4:
			libroEnTope();
			elegirMenu();
		case 5:
		break;
		default:
			printf("Opcion Incorrecta!\n");
			elegirMenu();
		break;
	}
}

bool pilaVacia(tPila pPila ){
	return (pPila.tope == -1);
}

bool pilaLlena(tPila pPila){
	return(pPila.tope == MAX - 1);
}

void apilarLibros() {
	if(pilaLlena(pilaLibros)) {
		printf("No se pueden apilar mas libros!\n");
	} else {
		pilaLibros.tope++;
		printf("Ingrese el titulo del libro: ");
		fflush(stdin);
		gets(pilaLibros.libro[pilaLibros.tope].titulo);
		printf("Ingrese su editorial: ");
		fflush(stdin);
		gets(pilaLibros.libro[pilaLibros.tope].editorial);
		printf("Ingrese el ISBN: ");
		scanf("%d",&pilaLibros.libro[pilaLibros.tope].ISBN);
	}
}

void listar5Libros() {
	int i;
	if(pilaVacia(pilaLibros)) {
		printf("No hay libros por visualizar!\n");
	} else {
		if(pilaLibros.tope < 4) {
			printf("No hay 5 libros apilados!\n");
		} else {
			printf("Ultimos 5 libros apilados: \n");
			for(i=0;i<5;i++){
				printf("%s - %s: %d\n",pilaLibros.libro[i].titulo,pilaLibros.libro[i].editorial,pilaLibros.libro[i].ISBN);
			}	
		}
	}
} 
 
void desapilarLibros(){
	if(pilaVacia(pilaLibros)){
		printf("No hay libros por desapilar!\n");
	} else {
		pilaLibros.tope--;
	}
}

void libroEnTope() {
	if(pilaVacia(pilaLibros)){
		printf("No hay libros en la pila!\n");
	} else {
		printf("El libro en tope es: %s - %s: %d",pilaLibros.libro[pilaLibros.tope].titulo,pilaLibros.libro[pilaLibros.tope].editorial,pilaLibros.libro[pilaLibros.tope].ISBN);
	}
}
