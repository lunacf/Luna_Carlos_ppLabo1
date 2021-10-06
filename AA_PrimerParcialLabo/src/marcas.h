/*
 * marcas.h
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */

#ifndef MARCAS_H_
#define MARCAS_H_

typedef struct{
	int id;
	char descripcion[20];
}eMarca;

void mostrarMarca(eMarca marca);
int listarMarcas(eMarca* list, int length);
int cargarDescripcionMarca(char descripcion[], int idMarca,
		eMarca list[], int tamMarca);
int buscarMarcaPorId(int id, eMarca marca[], int tamMarca);
#endif /* MARCAS_H_ */
