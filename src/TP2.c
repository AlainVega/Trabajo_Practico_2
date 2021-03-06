/*
 ============================================================================
 Name        : TP2.c
 Author      : Alain Vega y Mathias Martinez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "entrada.h"
#include "declaracionesTP2.h"

char PILA[PUNTOS]; // pila que contiene los nodos de un camino actual
char PILACORTA[PUNTOS]; //pila con el camino mas corto
int ULTIMO = 0; // indice que indica cual es el ultimo elemento de la pila
int ULTIMO_MENOR = 0; // indice que indidca cual es el ultimo elemento de la pila del menor camino
int distancia_menor = 0; //contiene la menor distancia posible

int main(void) {
	PILA[0] = x;
	ImprimirMatriz(distancias);
	x = toupper(x);
	y = toupper(y);
	CalcularCaminos(x, y);
}

void ImprimirMatriz(int distancias[PUNTOS][PUNTOS]) {
	int i, j;
	for (i = 0; i < PUNTOS; i++) {
		for (j = 0; j < PUNTOS; j++) {
			printf("| %d ", distancias[i][j]);
		}
		printf("| \n");
	}
}

/*
 * Recorre la matriz empezando por la fila origen y cada vez que encuentra un camino
 * entra en el, si llega a un nodo del cual no puede seguir mas (o es el destino),
 * vuelve un nodo atras y busca mas caminos, repite este proceso hasta terminar de
 * recorrer la fila origen.
 * El camino que esta recorriendo actualmente se encuentra en la PILA, cuyos
 * valores se van sacando y agregando mientras se recorren los nodos.
 */
void CalcularCaminos(char origen, char destino) {
	// origen: fila de la que partis
	// destino: columna de destino
	int i;
	int band_vuelta = 0;
	int next_fila = origen - 'A', next_columna = 0;
	int band_salir = 0;
	int band = 1;
	while (band_salir == 0) {
		for (i = band_vuelta == 1 ? next_columna : 0; i < PUNTOS; i++) {
			if (distancias[next_fila][i] > 0) {
				if (BuscarNodo(PILA, i) == 1) {
					// Se intenta volver a un espacio ya recorrido, ignorar
					continue;
				}
				PushPila(PILA, i + 'A');
				if (i + 'A' == destino) {
					// Se llego al destino, printear el camino y volver
					puts("Camino encontrado.");
					if (band == 1) {
						ImprimirCamino(PILA, ULTIMO, band);
						band = 0;
					}
					else {
						ImprimirCamino(PILA, ULTIMO, band);
					}
					band_vuelta = 1;
					if (next_fila + 'A' == origen && next_columna == PUNTOS - 1) {
						band_salir = 1;
						break;
					}
					// Estamos en la ultima columna de una fila
					if (PILA[ULTIMO] - 'A' == PUNTOS - 1) {
						// Se va a volver a la ultima columna del origen, salir del bucle
						if (PILA[ULTIMO - 1] == origen) {
							next_fila = PILA[ULTIMO - 1] - 'A';
							band_salir = 1;
							break;
						}
						// Se va a volver 2 veces.
						else {
							next_fila = PILA[ULTIMO - 2] - 'A';
						}
						next_columna = PILA[ULTIMO - 1] + 1 - 'A';
						PopPila(PILA);
						PopPila(PILA);
						break;
					}
					else {
						next_fila = PILA[ULTIMO - 1] - 'A';
						next_columna = PILA[ULTIMO] + 1 - 'A';
						PopPila(PILA);
						break;
					}

				}
				else {
					// Se encontro un nodo al que se puede seguir, seguirlo
					next_fila = i;
					next_columna = 0;
					band_vuelta = 0;
					break;
				}
			}
			else {
				// Hay un 0 en esta posicion
				if (i == PUNTOS - 1) {
					if (next_fila + 'A' == origen) {
						band_salir = 1;
						break;
					}
					band_vuelta = 1;
					// Llegamos a la ultima columna de una fila y no se entro a ningun camino, volver
					if (PILA[ULTIMO] - 'A' == PUNTOS - 1) {
						// Se va a volver a volver a la ultima columna de la fila origen
						if (PILA[ULTIMO - 1] == origen) {
							next_fila = PILA[ULTIMO - 1] - 'A';
							band_salir = 1;
							break;
						}
						// Se va a volver 2 veces.
						else {
							next_fila = PILA[ULTIMO - 2] - 'A';
						}
						next_columna = PILA[ULTIMO - 1] + 1 - 'A';
						PopPila(PILA);
						PopPila(PILA);
						break;
					}
					else {
						next_fila = PILA[ULTIMO - 1] - 'A';
						next_columna = PILA[ULTIMO ] + 1 - 'A';
						PopPila(PILA);
						break;
					}
				}
			}
		}
	}
	puts("=-=-=-=-=-=Camino mas corto=-=-=-=-=-=");
	distancia_menor = ImprimirCamino(PILACORTA, ULTIMO_MENOR, band);
	printf("Distancia: %i", distancia_menor);
}

/*
 * Funcion PushPila: para agregar un elemento a la pila.
 * Recibe el vector pila y el elemento para introducir en la pila.
 * No retorna nada.
 */
void PushPila(char PILA[PUNTOS], char elemento) {
	if (ULTIMO >= PUNTOS - 1) { //preguntamos si la pila esta llena
		printf("ERROR Pila llena, checkear la dimension del array pila\n");
	} else {
		//no esta llena, podemos agregar un elemento
		PILA[ULTIMO + 1] = elemento;
		ULTIMO++;
	}
}

/*
 * Funcion PopPila: para sacar 1 elemento de la pila.
 * Recibe el vector pila.
 * Retorna el elemento que se saco de la pila.
 */
char PopPila(char PILA[PUNTOS]) {
	if (ULTIMO <= 0) {
		printf("ERROR Pila vacia, no es posible hacer un pop de una pila vacia.\n");
		return '?'; //retornamos ? a modo de saber que la pila esta vacia
	} else {
		// no esta vacia
		PILA[ULTIMO] = '\0';
		return PILA[ULTIMO--]; //retornamos el elemento al que hicimos pop
	}
}

/*
 * Funcion BuscarNodo: para buscar si hay un nodo anotado en la pila.
 * Recibe la pila y el indice el cual representa un nodo.
 * Retorna 1 si el nodo esta en la pila y 0 si no esta.
 */
int BuscarNodo(char PILA[PUNTOS], int indice) {
	int i, booleano = 0;
	for (i = 0; i <= ULTIMO; i++) {
		if (PILA[i] == indice + 'A') {
			booleano = 1; //ese valor si esta en la pila
		}
	}
	return booleano;
}

/*
 *Funcion ImprimirCamino: para imprimir el camino actual (el que esta en la pila)
 *Recibe la pila y la suma total de distancias de origen a destino
 *No retorna nada.
 */

int ImprimirCamino(char PILA[PUNTOS], int ULTIMO, int bandera) {
	int i, suma, fila, columna;
	suma = 0;
	//calculamos la suma de las distancias
	for (i = 0; i < ULTIMO; i++) {
		fila = PILA[ULTIMO - (i + 1)] - 'A';
		columna = PILA[ULTIMO - i] - 'A';
		suma = suma + distancias[fila][columna];
	}
	//imprimimos la pila con el camino
	for (i = 0; i <= ULTIMO; i++) {
		if (i == ULTIMO) {
			printf("%c = %d\n", PILA[i], suma);
		} else {
			printf("%c --> ", PILA[i]);
		}
	}
	//Se guarda el primer valor para luego compararlo con los siguientes
	if (bandera == 1) {
		distancia_menor = suma;
		ULTIMO_MENOR = ULTIMO;
		CopiarPila(PILA);
	} else if (suma < distancia_menor) {
		distancia_menor = suma;
		ULTIMO_MENOR = ULTIMO;
		CopiarPila(PILA);
	}
	return suma;
}

void CopiarPila(char PILA[PUNTOS]) {
	int i;
	for (i = 0; i <= ULTIMO; i++) {
		PILACORTA[i] = PILA[i];
	}
}
