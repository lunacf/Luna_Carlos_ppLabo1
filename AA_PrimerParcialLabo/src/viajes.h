/*
 * viajes.h
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */

#ifndef VIAJES_H_
#define VIAJES_H_

typedef struct{
	int idViaje;
	char descripcion[51];
	float kms;
}eViajes;

void mostrarTipo(eViajes viajes);
int listarViajes(eViajes* list, int length);
int cargarDescripcionViajes(char descripcion[], int idViajes, eViajes viajes[], int tamViajes);
int buscarViajePorID(int id, eViajes viajes[], int tamViaje);
#endif /* VIAJES_H_ */
