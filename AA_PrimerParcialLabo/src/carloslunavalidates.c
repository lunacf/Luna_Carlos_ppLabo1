/*
 * carloslunavalidates.c
 *
 *  Created on: 6 oct 2021
 *      Author: 54117
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <ctype.h>
#include "carloslunavalidates.h"

/// @brief
///
/// @return
char menu(){
	int opcionElegida;

			printf("------- CENTRO DE AVIONES SRL -------\n");
			printf("\nIngrese una opcion para operar: \n");
			printf("[1] - Alta avion.\n");
			printf("[2] - Modificar Datos avion .\n");
			printf("[3] - Baja avion.\n");
			printf("[4] - Listar aviones.\n");
			printf("[5] - Listar viajes.\n");
			printf("[6] - Listar marcas.\n");
			printf("[7] - Menu de informes.\n");
			printf("[8] - Salir del menu.\n");
			fflush(stdin);
			scanf("%d",&opcionElegida);
			opcionElegida = tolower(opcionElegida);

			return opcionElegida;
}
/// @brief
///
/// @param cadena
/// @param longitud
/// @return
int myGets(char* cadena, int longitud){
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param cadena
/// @param limite
/// @return
static int esNumerica(char* cadena, int limite){
	int retorno = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++){
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-')){
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0'){
			retorno = 0;
			break;
		}
		//CONTINUE
	}
	//BREAK
	return retorno;
}

/// @brief
///
/// @param pResultado
/// @return
static int getInt(int* pResultado){
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString))){
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}

/// @brief
///
/// @param msj
/// @param msjError
/// @param pDato
/// @param retries
/// @param min
/// @param max
/// @return
int GetOption(char* msj,char* msjError,int* pDato,int retries,int min,int max)
{
	int retorno=-1;
	int bufferInt;
	int resultScanf;
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0 && max>=min)
	{
		do
		{
			printf("%s",msj);
			fflush(stdin);
			resultScanf=scanf("%d",&bufferInt);
			if(resultScanf==1 && bufferInt>=min && bufferInt<=max)
			{
				*pDato=bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n",msjError,retries);
				retries--;
			}

		}while(retries>=0);
	}
	return retorno;
}

/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError,
					int minimo, int maximo, int reintentos){
	int retorno = -1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo){
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

/// @brief
///
/// @param cadena
/// @return
int esFlotante(char* cadena){
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0){
		for(i=0 ; cadena[i] != '\0'; i++){
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+')){
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' ){
				if(cadena[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}
				else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param pResultado
/// @return
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,
							float minimo, float maximo, int reintentos){
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0){
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/// @brief
///
/// @param cadena
/// @param longitud
/// @return
int getString(char* cadena, int longitud){
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param pResultado
/// @param longitud
/// @return
static int getNombre(char* pResultado, int longitud){
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/// @brief
///
/// @param cadena
/// @param longitud
/// @return
int esNombre(char* cadena,int longitud){
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0){
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
					(cadena[i] < 'a' || cadena[i] > 'z' )){
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param pResultado
/// @param longitud
/// @param mensaje
/// @param mensajeError
/// @param reintentos
/// @return
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos){
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < longitud ){
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

/// @brief
///
/// @param cadena
/// @param longitud
/// @return
int esDescripcion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/// @brief
///
/// @param pResultado
/// @param longitud
/// @return
static int getDescripcion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

/// @brief
///
/// @param pResultado
/// @param longitud
/// @param mensaje
/// @param mensajeError
/// @param reintentos
/// @return
int utn_getDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


