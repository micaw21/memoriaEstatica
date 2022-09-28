#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 20

//Definicion de Tipos
typedef char tString [50];
typedef struct{
	tString nombreApellido;
	int tipoCobertura;
}tPacientes;

typedef struct{
	tPacientes paciente[20];
	int frente;
	int final;
}tCola;

tString cobertura[3] = {"Obra Social","Pre Paga","Particular"};

//Variables Globales
tCola colaPacientes;
int contador = 0;

//Prototipo de Funciones
void inicializarCola();
bool colaLlena(tCola);
bool colaVacia(tCola);
void menu();
void opcionesMenu(int);
void ingresarPacientes();
void turnosDisponibles();
void eliminarPaciente(); //Frente Movil

int main() {
	inicializarCola();
	menu();
	return 0;
}

//Implementacion
void inicializarCola(){
	
	colaPacientes.frente = -1;
	
	colaPacientes.final = -1;
	
	printf("Cola inicializada!\n");
}

bool colaLlena(tCola pCola){
	
	return(pCola.final == MAX - 1);
}

bool colaVacia(tCola pCola){
	
	return(pCola.frente == -1);
}

void menu() {
	
	int respuesta;
	
	printf("Elija una opcion: \n");
	printf("1-Ingresar paciente\n2-Conocer si hay turnos disponibles\n3-Eliminar paciente\n4-Salir: ");
	scanf("%d",&respuesta);
	
	opcionesMenu(respuesta);
}

void opcionesMenu(int pOpciones){
	switch(pOpciones){
		case 1:
			ingresarPacientes();
			menu();
		break;
		case 2:
			turnosDisponibles();
			menu();
		break;
		case 3:
			eliminarPaciente();
			menu();
		break;
		case 4:
		break;
		default:
			printf("Opcion Incorrecta!\n");
			menu();
		break;
	}
}

void ingresarPacientes(){
	
	if(colaLlena(colaPacientes)){
		
		printf("No hay lugar!\n");
		
	} else {
		
		contador++;
		
		colaPacientes.final++;
		
		fflush(stdin);
		printf("Ingrese su nombre y apellido: ");
		gets(colaPacientes.paciente[colaPacientes.final].nombreApellido);
		fflush(stdin);
		
		printf("Ingrese su tipo de cobertura: 1-Obra Social, 2-Pre Paga, 3-Particular: ");
		scanf("%d",&colaPacientes.paciente[colaPacientes.final].tipoCobertura);
		
		if(colaPacientes.final == 0){
			colaPacientes.frente = 0;
		}
		printf("Paciente ingresado!\n");
	}
}

void turnosDisponibles(){
	if(contador < 20) {
		if(colaLlena(colaPacientes)){
		
			printf("La cola esta llena!\n");
		
		} else {
		
			printf("Hay turnos disponibles!\n");
		
		}
	} else {
		printf("No hay turnos disponibles!\n");
	}
	
	
}

void eliminarPaciente(){
	
	int coberturaElim = 0;
	
	tString nombreElim = "";
	
	if(colaVacia(colaPacientes)){
		
		printf("La cola esta vacia!\n");
		
	} else {
		
		coberturaElim = colaPacientes.paciente[colaPacientes.frente].tipoCobertura;//Guarda el elemento
		
		colaPacientes.paciente[colaPacientes.frente].tipoCobertura = 0; //Borra elemento en frente

		strcpy(nombreElim,colaPacientes.paciente[colaPacientes.frente].nombreApellido);//Guarda elemento

		strcpy(colaPacientes.paciente[colaPacientes.frente].nombreApellido,"");//Borra
		
		if(colaPacientes.frente == colaPacientes.final){
			
			inicializarCola();
			
		} else {
			
			colaPacientes.frente++;
		}
		
		printf("Se ha eliminado al paciente %s - %s\n",nombreElim,cobertura[coberturaElim-1]);
	}
}



