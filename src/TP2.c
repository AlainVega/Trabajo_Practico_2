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
#include "entrada.h"
#include "declaracionesTP2.h"

char PILA[PUNTOS]; // pila que contiene los nodos de un camino actual
int ULTIMO = 0; // indice que indica cual es el ultimo elemento de la pila

int main(void) {
	ImprimirMatriz(distancias);
}

int CaminosPosibles(char origen, char destino){
	int cant_caminosposibles = 0;
	return cant_caminosposibles;
}

void ImprimirMatriz(int distancias[PUNTOS][PUNTOS]){
	int i, j;
	for (i = 0; i < PUNTOS; i++){
		for (j = 0; j < PUNTOS; j++){
			printf("| %d ", distancias[i][j]);
		}
		printf("| \n");
	}
}

void PushPila(char PILA[PUNTOS], char elemento){
	if (ULTIMO >= PUNTOS - 1) { //preguntamos si la pila esta llena
		printf("ERROR Pila llena, checkear la dimension del array pila\n");
	}else {
		//no esta llena, podemos agregar un elemento
		PILA[ULTIMO + 1] = elemento;
		ULTIMO++;
	}
}

char PopPila(char PILA[PUNTOS]){
	if (ULTIMO <= 0) {
		printf("ERROR Pila vacia, no es posible hacer un pop de una pila vacia.\n");
		return '?'; //retornamos ? a modo de saber que la pila esta vacia
	}else {
		// no esta vacia
		return PILA[ULTIMO--]; //retornamos el elemento al que hicimos pop
	}
}
