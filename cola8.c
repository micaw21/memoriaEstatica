#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 40

//Definicion de Tipos
typedef char tString[20];
typedef long tNumeros[MAX];
typedef struct{
	unsigned long nroTelefono;
	tString localidad;
}rTelefonos;

typedef struct{
	rTelefonos celular[MAX];
	int frente;
	int final;
}rCola;

//Variables Globales
rCola llamada;
tNumeros vNroCelular;

//Prototipo de Funciones
void inicializarCola();
bool colaVacia(rCola);
bool colaLlena(rCola);
void atenderLlamada();
void cortarLlamada();//Frente Movil
int contarLlamadas();
void visualizarCantLlamadas();
void visualizarNumerosAtendidos();

//Funcion Principal 
int main() {
	inicializarCola();
	atenderLlamada();
	visualizarCantLlamadas();
	visualizarNumerosAtendidos();
	return 0;
}

//Implementacion
void inicializarCola(){
	llamada.frente = -1;
	llamada.final = -1;
	printf("\tCola inicializada!\n");
}

bool colaVacia(rCola pCola){
	return(pCola.final == -1);
}

bool colaLlena(rCola pCola){
	return(pCola.final == MAX - 1);
}

void atenderLlamada(){
	int respuesta = 0;
	do {
		if(colaLlena(llamada)){
			printf("No se puede atender mas llamadas!\n");
			break;
		}else{
			llamada.final++;
			printf("Ingrese el numero de telefono: ");
			scanf("%lu",&llamada.celular[llamada.final].nroTelefono);
			vNroCelular[llamada.final] = llamada.celular[llamada.final].nroTelefono;
			fflush(stdin);
			printf("Ingrese la localidad: ");
			fflush(stdin);
			gets(llamada.celular[llamada.final].localidad);
			fflush(stdin);
			contarLlamadas();
			cortarLlamada();
			if(llamada.final == 0){
				llamada.frente = 0;
			}
			printf("Llamada atendida!\n");
			
		}
		printf("Desea atender otra llamada? 1-Si 2-No: ");
		scanf("%d",&respuesta);
	} while (respuesta == 1);
	
}

void cortarLlamada(){
	unsigned long numero = 0;
	if(colaVacia(llamada)){
		printf("No hay llamadas por eliminar!\n");
	} else {
		numero = llamada.celular[llamada.frente].nroTelefono;
		llamada.celular[llamada.frente].nroTelefono = 0;
		strcpy(llamada.celular[llamada.frente].localidad,"");
		
		if(llamada.frente == llamada.final){
			inicializarCola();
		}else{
			llamada.frente++;
		}
	}
	
}

void visualizarCantLlamadas(){
	int cantidad = contarLlamadas();
	printf("Se han registrado %d llamadas!\n",cantidad);
}

int contarLlamadas(){
	int contador = 0;
	contador++;
	return contador;
}

void visualizarNumerosAtendidos(){
	int i;
	printf("Numeros registrados atendidos: \n");
	for(i=llamada.frente;i<=llamada.final;i++){
		printf("Numero de Telefono: %lu\n",vNroCelular[i]);
	}
	
}

