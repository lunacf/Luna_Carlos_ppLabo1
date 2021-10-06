/*
 * viajes.c
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "viajes.h"

void mostrarViajes(eViajes viajes){
   printf(" º      [%d]             %9s        %.2f º\n", viajes.idViaje, viajes.descripcion,viajes.kms);
}

int listarViajes(eViajes* list, int length){
	printf(" ######################################\n");
	printf(" º         Lista de Viajes          º\n");
	printf(" º         Id            Descripcion        kms º\n");
	for (int i = 0;i<length;i++){
		if (list[i].idViaje!=0){
			mostrarViajes(list[i]);
		}
	}
	return 0;
}

int cargarDescripcionViajes(char descripcion[], int idViajes,
		eViajes list[], int tamViajes, float km){
	int pudo = 0;
	for (int i=0;i<tamViajes;i++){
		if(list[i].idViaje == idViajes){
			strcpy(descripcion, list[i].descripcion);
			list[i].kms=km;
			pudo = 1;
		}
	}
	return pudo;
}
