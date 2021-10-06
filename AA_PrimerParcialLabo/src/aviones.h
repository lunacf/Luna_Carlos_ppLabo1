/*
 * aviones.h
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */


#ifndef AVIONES_H_
#define AVIONES_H_
#include "aviones.h"
#include "viajes.h"
#include "marcas.h"

#define TEXT_SIZE 20
#define CANT_AUX 5

typedef struct{
	int idAvion;
	int matricula;
	int fecha;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int isEmpty;
}eAvion;

int inicializarArray(eAvion array[], int tam);
/*int listarAvion(eAvion* list, int length, eViajes viajes[], int lenViajes, eMarca marcas[], int lenMarcas);*/
int mostrarAvionesConTodosSusDatos(eAvion* listAvion,int lenAvion, eViajes* listViajes, int lenViajes, eMarca* listMarcas, int lenMarcas);
int mostrarAvion(eAvion* array, int tam, eMarca* marcas, int tamM);
int cargarDescripcionAvion(int descripcion, int idAvion,
								eAvion list[], int tamAvion);
int bajaAvion(eAvion* array, int tam, int indice);
int encontrarAvionPorID(eAvion* list, int len,int id);
int altaAvion(eAvion* array, int tam, int indice, int* id);
int cargaAvion(eAvion* list, int lenAvion, int id, int matricula,int fecha,int idViaje,int idMarca,int modelo,int cantAsientos, int index);
int buscarAvionPorMatricula(eAvion avion[], int tamN, int matricula);
int buscarEspacioLibre(eAvion* array, int tam);
int modificarAvion(eAvion* array, int tam, int indice);
void hardcodeoAvion(eAvion* array, int tam);
#endif /* AVIONES_H_ */
