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
#include "fecha.h"

#define TEXT_SIZE 20
#define CANT_AUX 5

typedef struct{
	int idAvion;
	int matricula;
	eFecha fecha;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int isEmpty;
}eAvion;

int inicializarArray(eAvion array[], int tam);
/*int listarAvion(eAvion* list, int length, eViajes viajes[], int lenViajes, eMarca marcas[], int lenMarcas);*/

int mostrarAviones(eAvion* array, int tam, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
void mostrarAvion(eAvion arrayA, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
int bajaAvion(eAvion* array, int tam, int indice);
int encontrarAvionPorID(eAvion* list, int len,int id);
int altaAvion(eAvion* array, int tam, int indice, int* id);
int ordenoDobleCriterio(eAvion avion[], int tamA, eMarca marca[], int tamMm, eViajes viaje[], int tamV);
int cargaAvion(eAvion* list, int lenAvion, int id, int matricula,int fecha,int idViaje,int idMarca,int modelo,int cantAsientos, int index);
int buscarAvionPorMatricula(eAvion avion[], int tamN, int matricula);
int buscarEspacioLibre(eAvion* array, int tam);
int modificarAvion(eAvion* array, int tam, int indice);
void hardcodeoAvion(eAvion* array, int tam);


void informarAvionesPorMarca(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
#endif /* AVIONES_H_ */
