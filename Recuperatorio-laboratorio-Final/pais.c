#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#define VACIO 0
#define LLENO 1

int hardcodear_Paises(ePais datosPais[])
{
    int retorno = -1;
    char Nombrepais[6][30]={"tailandia","alemania","persia","belgica","Argentina","Alemania"};
    char continente[6][30]={"Asia","Europa","Asia","Europa","America","Europa"};
    int codigoTel[6] ={66,49,98,32,54,49};
    int id [6] ={1,2,3,4,5,6};
    /*Pasar estos valores a  un array de mascotas*/
    int i;
    for(i=0;i<6;i++)
    {
        strcpy(datosPais[i].nombrePais,Nombrepais[i]);
        strcpy(datosPais[i].continente,continente[i]);
        datosPais[i].CodigoTelefonico = codigoTel[i];
        datosPais[i].Idpais = id[i];
        datosPais[i].isEmpty = LLENO;
        retorno =0;
        /*
        printf("%s----%s---%d-----%d\n",datosPais[i].nombrePais,datosPais[i].continente,datosPais[i].CodigoTelefonico
                                     ,datosPais[i].Idpais);
        */
    }

    return retorno;
}
//Mostrar Paises

int mostrarPaises(ePais datosPais[],int tamPaises)
{
    int retorno = -1;
    int i;
    printf("   Id   |  PAIS   |  CONTINENTE\n");
    if(datosPais != NULL && tamPaises > 0)
    {
        for(i=0;i<tamPaises;i++)
        {
            printf("   %d---%s---%s\n",i+1,datosPais[i].nombrePais,datosPais[i].continente);
            retorno = 0;
        }
    }

    return retorno;
}


