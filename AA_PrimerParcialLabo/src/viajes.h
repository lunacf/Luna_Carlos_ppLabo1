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
	char descripcion[25];
	float kms;
}eViajes;

void mostrarTipo(eViajes viajes);
int listarViajes(eViajes* list, int length);
int cargarDescripcioneViajes(char descripcion[], int idViajes,eViajes list[], int tamViajes);
#endif /* VIAJES_H_ */
