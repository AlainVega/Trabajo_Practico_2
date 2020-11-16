/*
 * declaracionesTP2.h
 *
 *  Created on: 10 nov. 2020
 *      Author: lp1-2019
 */

#ifndef DECLARACIONESTP2_H_
#define DECLARACIONESTP2_H_
#include "entrada.h"


void ImprimirMatriz(int distancias[PUNTOS][PUNTOS]);

void PushPila(char PILA[PUNTOS], char elemento);

char PopPila(char PILA[PUNTOS]);

int BuscarNodo(char PILA[PUNTOS], int indice);

void ImprimirCamino(char PILA[PUNTOS], int suma);

void CalcularCaminos(char origen, char destino);

#endif /* DECLARACIONESTP2_H_ */
