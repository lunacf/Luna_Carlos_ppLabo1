/*
 * marcas.c
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marcas.h"

void mostrarMarca(eMarca marca){
   printf(" �       [%d]               %6s   �\n", marca.id, marca.descripcion);
}

int listarMarcas(eMarca* list, int length){
	printf(" ######################################�\n");
	printf(" �       Lista de Marcas      �\n");
	printf(" �         Id            Descripcion   �\n");

	for (int i = 0;i<length;i++){
		if (list[i].id!=0){
			mostrarMarca(list[i]);
		}
	}
	return 0;
}

int cargarDescripcionMarca(char descripcion[], int idMarca,
		eMarca list[], int tamMarca){
	int retorno = 0;
	for (int i=0;i<tamMarca;i++){
		if(list[i].id == idMarca){
			strcpy(descripcion, list[i].descripcion);
			retorno = 1;
		}
	}
	return retorno;
}

int buscarMarcaPorId(int id, eMarca marca[], int tamMarca){
	int indice = -1;

	for(int i = 0; i < tamMarca; i++){
		if(marca[i].id == id){
			indice = i;
			break;
		}
	}
	return indice;
}
