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
	char descripcion[51];
}eMarca;

/// @brief muestra datos de una marca
///
/// @param marca
void mostrarMarca(eMarca marca);
/// @brief lista todas las marcas
///
/// @param list
/// @param length
/// @return
int listarMarcas(eMarca* list, int length);
/// @brief carga la descripcion de las marcas
///
/// @param descripcion
/// @param idMarca
/// @param list
/// @param tamMarcas
/// @return retorna 1 si pudo, sino 0
int cargarDescripcionMarca(char descripcion[], int idMarca, eMarca list[], int tamMarcas);
#endif /* MARCAS_H_ */
