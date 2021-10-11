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
#include "carloslunavalidates.h"

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

int ordenoDobleCriterio(eAvion avion[], int tamA, eMarca marca[], int tamMm, eViajes viaje[], int tamV){
	int retorno=-1;
	int i, j;
	eAvion auxAvion;

	for(i=0;i<tamA;i++)
	{
		for(j=i+1;j<tamA;j++)
			{
			if(avion[i].idMarca>avion[j].idMarca)
			{
				auxAvion=avion[i];
				avion[i]=avion[j];
				avion[j]=auxAvion;
				if((avion[i].idMarca==avion[j].idMarca) && avion[i].matricula>avion[j].matricula){
					auxAvion=avion[i];
					avion[i]=avion[j];
					avion[j]=auxAvion;
					retorno=1;
				}
			}
		}
	}
	return retorno;
}



int arrayEmptyAvion(eAvion avion[], int tamA){
    int retorno = 1;
    if(avion != NULL && tamA > 0){
        for(int i=0; i<tamA;i++){
        if(avion[i].isEmpty == 0){
            retorno = -1;
        	}
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
	int flag=0;
	eAvion auxAvion;

	if(array != NULL && tam > 0 && indice < tam && indice >= 0 && id != NULL)
	{
		if( utn_getNumero(&auxAvion.matricula,"\nIngrese matricula: [10000-20000]","\nError, reingrese: ",10000,20000,2) == 0 &&
			utn_getNumero(&auxAvion.fecha,"\nIngrese fecha: [1-31]","\nError, reingrese fecha: [1-31] ",1,31,2) == 0 &&
			utn_getNumero(&auxAvion.modelo,"\nIngrese modelo: [1999-2021]","\nError, reingrese modelo: ",1999,2021,2) == 0 &&
			utn_getNumero(&auxAvion.fecha,"\nIngrese cant asientos: [1-30]","\nError, reingrese fecha: ",1,30,2)==0)

		{
			respuesta=0;
			auxAvion.idAvion=*id;
			auxAvion.isEmpty=0;
			flag=1;
			array[indice]=auxAvion;
			(*id)++; //ID Autoincremental
		}
		if(flag==0){
			printf("No hay espacio en el array. \n");
		}
		system("cls");
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

void mostrarAvion(eAvion arrayA, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV)
{

		 char marca[51];
		 char nombreViajes[51];

		 cargarDescripcionMarca(marca, arrayA.idMarca, arrayM, tamM);
		 cargarDescripcionViajes(nombreViajes, arrayA.idViaje, arrayV, tamV);

		//printf("ID  Matricula  Fecha  Viaje  Marca   Modelo  Asientos");
		printf("%d    %10d     %10d    %10s   %10s    %10d    %10d \n",
		arrayA.idAvion,arrayA.matricula,arrayA.fecha,nombreViajes,marca,arrayA.modelo, arrayA.cantAsientos);


}


int mostrarAviones(eAvion* array, int tam, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV){
	int i;
	int retorno=-1;


		if(array!=NULL && tam>0)
		{
			printf("ID     Matricula      Fecha         Viajes     Marca       Modelo      Asientos\n\n");

			for(i=0; i<tam; i++)
			{
				if(array[i].isEmpty==0)
				{
					mostrarAvion(array[i], arrayM, tamM, arrayV, tamV);
					retorno=1;
				}
			}
		}
		else{
			printf("No hay aviones cargados.\n\n");
		}
	    printf("\n\n");


	    return retorno;
}

void informarAvionesPorMarca(eAvion aviones[], int tamAviones, eMarca arrayM[], int tamM, eViajes arrayV[], int tamV){
	int cantAviones=0;
	int i;
	int j;
	system("cls");
	printf("#######################################################################\n\n");
	printf("##############################Lista de aviones######################### \n\n");
	printf("ID   Matricula     Fecha       IDviaje  Marca   Modelo    Asientos\n\n");

	if(arrayM != NULL && arrayM > 0 && arrayV != NULL && arrayV > 0){
		for(i=0;i<tamM;i++){
				for(j=0;j<tamV;j++){
					if(arrayM[j].id > 0 && arrayM[j].descripcion == aviones->idMarca){
						mostrarAvion(aviones[j], arrayM, tamM, arrayV, tamV);
						cantAviones=1;
					}
				}
		}
		if(cantAviones==0){
			printf("ID   Matricula     Fecha       IDviaje  Marca   Modelo    Asientos\n\n");
			printf(" Marca %10s -     No tiene aviones cargadas\n\n");
		}
	}
	printf("#######################################################################\n\n");
}

int modificarAvion(eAvion* array, int tam, int indice) {
	int retorno=-1;
	int flag=0;
	int opcion;
	int volver=0;
	eAvion auxAvion;

	if(array != NULL && tam > 0 && indice < tam && indice >= 0 && array[indice].isEmpty == 0)
		{
		do{
			printf("*********************************\n");
			printf("Matricula: %d\nModelo: %d\nCantidad de Asientos: %d\n",
					array[indice].matricula,
					array[indice].modelo,
					array[indice].cantAsientos);
			printf("*********************************\n");
			if(GetOption("1.Modelo\n2.Cantidad de Asientos\n3.Volver al menu \n Que quiere modificar?: ","Error, ingrese dato del 1 al 3\n", &opcion,3,1,3)==0){
				switch(opcion){
				case 1:
					if(utn_getNumero(&auxAvion.modelo,"Ingrese nuevo modelo: [1999-2021]","\nError, reingrese modelo: ",1999,2021,2)==0){
											strcpy(array[indice].modelo,auxAvion.modelo);
											flag=1; //Cambio activo
					}
					break;
				case 2:
					if(utn_getNumero(&auxAvion.cantAsientos,"Ingrese nueva cantidad de asientos: [10500-20500]","\nError, reingrese cantidad de asientos: ",1,40,2)==0){
						strcpy(array[indice].cantAsientos,auxAvion.cantAsientos);
						printf("Cantidad cambiada");
						flag=1; //Cambio activo
					}
					break;
				case 3:
					if(flag==1){
						retorno=0;
					}
					else{
						retorno=1;
					}
					volver=1;
					break;
				}
			}
		}while(volver!=1);

	}//end primer if

	return retorno;
}

int bajaAvion(eAvion* array, int tam, int indice) {
	int retorno=-1;
	if(array != NULL && tam > 0 && indice < tam && indice >= 0 && array[indice].isEmpty == 0) {
		array[indice].isEmpty=1;
		retorno=0;
	}
	return retorno;
}
