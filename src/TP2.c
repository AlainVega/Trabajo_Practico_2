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
