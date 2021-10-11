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
   printf(" º       [%d]               %6s º\n", marca.id, marca.descripcion);
}

int listarMarcas(eMarca* list, int length){
	printf(" ######################################\n");
	printf(" º       Lista de Marcas      º\n");
	printf(" º         Id            Descripcion º\n");

	for (int i = 0;i<length;i++){
		if (list[i].id!=0){
			mostrarMarca(list[i]);
		}
	}
	return 0;
}

int cargarDescripcionMarca(char descripcion[], int idMarca, eMarca list[], int tamMarcas){
	int retorno = 0;
	if(list != NULL && list > 0){
	for (int i=0;i<tamMarcas;i++){
		if(list[i].id == idMarca){
			strcpy(descripcion, list[i].descripcion);
			retorno = 1;

		}
	}
	return retorno;
}

}


