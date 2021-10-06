/*
 * aviones.c
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aviones.h"
#include "marcas.h"
#include "viajes.h"

int inicializarArray(eAvion array[], int tam) {
			int retorno=-1;
			int i;
			if(array != NULL && tam > 0) {
				for(i=0;i<tam;i++){
					array[i].isEmpty=1;
					retorno=0;
				}
			}
			return retorno;
	}

int buscarEspacioLibre(eAvion* array, int tam){
	int i;
	int retorno=-1;

			if(array != NULL && tam > 0) { //Si hay lugar recorro
				for(i=0;i<tam;i++){
					if(array[i].isEmpty == 1){ //Si hay lugar libre
						retorno=i;
						break;
					}
				}
			}
			return retorno;
}

int buscarAvionPorMatricula(eAvion avion[], int tamN, int matricula){
	int retorno = -1;

	for(int i = 0; i < tamN; i++){
		if(avion[i].matricula == matricula && avion[i].matricula > 0){
			retorno = i;
			break;
		}
	}
	return retorno;
}
void hardcodeoAvion(eAvion* array, int tam){

	int id[5]={0,1,2,3,4};
	int matricula[5]={1000,1001,1002,1003,1004};
	int fecha[5]={10,11,12,13,14};
	int idViaje[5]={100,101,102,103,104};
	int idMarca[5]={1001,1001,1002,1003,1004};
	int modelo[5]={1999,2000,2009,2010,2020};
	int cantAsientos[5]={5,6,7,11,21};
	int i;

	for(i=0;i<5;i++){
		array[i].idAvion=id[i];
		array[i].matricula=matricula[i];
		array[i].fecha=fecha[i];
		array[i].idAvion=id[i];
		array[i].idViaje=idViaje[i];
		array[i].idMarca=idMarca[i];
		array[i].modelo=modelo[i];
		array[i].cantAsientos=cantAsientos[i];
		array[i].isEmpty=0;
	}
}

int altaAvion(eAvion* array, int tam, int indice, int* id) {
	int respuesta=-1;
	eAvion auxAvion;

	if(array != NULL && tam > 0 && indice < tam && indice >= 0 && id != NULL)
	{
		if( utn_getNumero(&auxAvion.matricula,"\nIngrese matricula: [0-99]","\nError, reingrese: ",0,99,2) == 0 &&
			utn_getNumero(&auxAvion.fecha,"\nIngrese fecha: [10-15]","\nError, reingrese fecha: ",10,15,2) == 0 &&
			utn_getNumero(&auxAvion.modelo,"\nIngrese modelo: [1999-2021]","\nError, reingrese modelo: ",1999,2021,2) == 0 &&
			utn_getNumero(&auxAvion.fecha,"\nIngrese cant asientos: [1-30]","\nError, reingrese fecha: ",1,30,2))

		{
			respuesta=0;
			auxAvion.idAvion=*id;
			auxAvion.isEmpty=0;
			array[indice]=auxAvion;
			(*id)++; //ID Autoincremental
		}
	}

	return respuesta;
}

int encontrarAvionPorID(eAvion* list, int len,int id){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (list[i].idAvion == id && list[i].idAvion>0){
			retorno = i;
			break;
		}
	}
	return retorno;
}
int cargarDescripcionAvion(int descripcion, int idAvion,
								eAvion list[], int tamAvion){
	int retorno = 0;
	for (int i=0;i<tamAvion;i++){
		if(list[i].idAvion == idAvion){
			strcpy(descripcion, list[i].modelo);
			retorno = 1;
		}
	}
	return retorno;
}

int mostrarAvion(eAvion* array, int tam, eMarca* arrayM, int tamM){
	int i;
	int retorno=-1;
	eAvion auxOrdenar;
	int flag=0;
	//por desc y matricu
	for(int i=0; i<tam-1; i++){
	       for(int j=i+1; j<tam; j++){
	        if(strcmp(arrayM[j].descripcion,arrayM[i].descripcion)>0){
	        	auxOrdenar = array[i];
	        	array[i] = array[j];
	        	array[j] = auxOrdenar;
	                }
	                else if(strcmp(arrayM[j].descripcion,arrayM[i].descripcion)==0 &&
	                		array[i].matricula>array[j].matricula){
	                		auxOrdenar = array[i];
	                		array[i] = array[j];
	                		array[j] = auxOrdenar;
	                }
	            }
	        }
	retorno=1; //si salio bien el ordenamiento
	system("cls");

		if(array!=NULL && tam>0)
		{
			printf("Se muestran aviones ordenadas por marca y matricula. \n\n");
			printf("ID MATRICULA   FECHA IDVIAJ IDMARCA MODELO   CANTASIENT\n\n");

			for(i=0; i<tam; i++)
			{
				if(array[i].isEmpty==0)
				{
					printf("%d %d %d %d %d %d %d\n",array[i].idAvion,array[i].matricula,array[i].fecha,array[i].idViaje,array[i].idMarca,array[i].modelo,array[i].cantAsientos );
					retorno=0;
				}
			}
		}

	    printf("\n\n");


	    return retorno;
}



int modificarAvion(eAvion* array, int tam, int indice) {
	int retorno=-1;
	eAvion auxAvion;
	if(array != NULL && tam > 0 && indice < tam && indice >= 0 && array[indice].isEmpty == 0)
		{
		if(utn_getNumero(&auxAvion.matricula,"\nIngrese nueva matricula: [0-99]","\nError, reingrese: ",0,99,2) == 0 &&
				utn_getNumero(&auxAvion.fecha,"\nIngrese nueva fecha: [10-15]","\nError, reingrese fecha: ",10,15,2) == 0 &&
				utn_getNumero(&auxAvion.modelo,"\nIngrese nuevo modelo: [1999-2021]","\nError, reingrese modelo: ",1999,2021,2) == 0 &&
				utn_getNumero(&auxAvion.fecha,"\nIngrese nueva cant asientos: [1-30]","\nError, reingrese fecha: ",1,30,2))
		{
				retorno = 0;
				auxAvion.idAvion = array[indice].idAvion;
				auxAvion.isEmpty = 0;
				array[indice] = auxAvion;
		}

		}
	return retorno;
}
/*int listarAvion(eAvion* list, int length, eViajes viajes[], int lenViajes, eMarca marcas[], int lenMarcas){

	printf("             Lista de Aviones       \n");
	printf("   ID	 Matricula    Fecha   IDviaje  IDmarca Modelo 	CantAsientos  �\n");
	for (int i = 0;i<length;i++){
		if (list[i].idAvion>0){
			mostrarAvion(list[i], length, viajes, lenViajes, marcas, lenMarcas);
		}
	}
	return 0;
}
*/

int bajaAvion(eAvion* array, int tam, int indice) {
	int retorno=-1;
	if(array != NULL && tam > 0 && indice < tam && indice >= 0 && array[indice].isEmpty == 0) {
		array[indice].isEmpty=1;
		retorno=0;
	}
	return retorno;
}
