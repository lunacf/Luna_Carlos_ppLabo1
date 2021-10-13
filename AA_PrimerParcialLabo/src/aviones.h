/*
 * aviones.h
 *
 *  Created on: 6 oct 2021
 *      Author: Luna Carlos Facundo
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

/// @brief Inicia la lista de aviones con el estado isEmpty=1
///
/// @param array: recibe la lista de aviones
/// @param tam: recibe el tamaño de la lisa
/// @return
int inicializarArray(eAvion array[], int tam);
/// @brief Imprime en pantalla los datos de todas las aviones
///
/// @param array
/// @param tam
/// @param arrayM
/// @param tamM
/// @param arrayV
/// @param tamV
/// @return
int mostrarAviones(eAvion* array, int tam, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
/// @brief  Imprime en pantalla los datos de un avion
///
/// @param arrayA
/// @param arrayM
/// @param tamM
/// @param arrayV
/// @param tamV
void mostrarAvion(eAvion arrayA, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV);
/// @brief  Da de baja un avion con el estado isEmpty=1
///
/// @param array
/// @param tam
/// @param indice
/// @return retorno 0 si no pudo, sino 1
int bajaAvion(eAvion* array, int tam, int indice);
/// @brief  busca el indice del avion
///
/// @param list
/// @param len
/// @param id
/// @return retorna el indice si encuentra o sino -1
int encontrarAvionPorID(eAvion* list, int len,int id);
/// @brief Da de alta un avion
///
/// @param array
/// @param tam
/// @param indice
/// @param id
/// @return Retorna 1 si pudo, sino retorna -1.
int altaAvion(eAvion* array, int tam, int indice, int* id);
/// @brief Ordena aviones por marca y matricula
///
/// @param avion
/// @param tamA
/// @param marca
/// @param tamMm
/// @param viaje
/// @param tamV
/// @return
int ordenoDobleCriterio(eAvion avion[], int tamA, eMarca marca[], int tamMm, eViajes viaje[], int tamV);

/// @brief  busca un avion por matricula
///
/// @param avion
/// @param tamN
/// @param matricula
/// @return retorna 0 si la encuentra, -1 si no se encuentra
int buscarAvionPorMatricula(eAvion avion[], int tamN, int matricula);
/// @brief Busca espacio libre dentro del array de aviones
///
/// @param array
/// @param tam
/// @return devuelve 1 si hay lugar, sino -1
int buscarEspacioLibre(eAvion* array, int tam);
/// @brief Modifica campos modelo y cantidad de asientos de aviones a traves de la matricula
///
/// @param array
/// @param tam
/// @param indice
/// @return devuelve 1 si hay lugar, sino -1
int modificarAvion(eAvion* array, int tam, int indice);
/// @brief pre-carga datos de aviones
///
/// @param array
/// @param tam
void hardcodeoAvion(eAvion* array, int tam);


#endif /* AVIONES_H_ */
