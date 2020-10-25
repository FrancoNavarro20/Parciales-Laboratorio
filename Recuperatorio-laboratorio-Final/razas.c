#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "razas.h"
#define VACIO 0
#define LLENO 1

int inicializarIsEmpty_Razas(eRazas datosRazas[],int cantRazas)
{
    int retorno = -1;
    int i;
    if(datosRazas!=NULL)
    {
        for(i=0;i<cantRazas;i++)
        {
            datosRazas[i].IsEmpty = VACIO;
            //printf("\nIsEmpty razas %d: %d\n",i+1,datosRazas[i].IsEmpty);
        }
    }
    return retorno;
}

int hardcodear_Razas(eRazas datosRazas[])
{
    int retorno = -1;
    char descripcion[6][30]={"siames","doberman","persa","pastor belga","Dogo","pastor aleman"};
    char tamanio[6][20]={"chico","grande","mediano","grande","mediano","grande"};
    //char pais[][30]={"tailandia","alemania","persia","belgica"};
    int  idRazas[6] = {1,2,3,4,5,6};
    int  idPais[6] = {1,2,3,4,5,2};
    /*Pasar estos valores a un array de duenios*/
    int i;
    for(i=0;i<6;i++)
    {
        strncpy(datosRazas[i].descripcion,descripcion[i],30);
        strncpy(datosRazas[i].tamanio,tamanio[i],20);

        datosRazas[i].idRazas = idRazas[i];
        datosRazas[i].idPais = idPais[i];
        datosRazas[i].IsEmpty = LLENO;
        retorno = 0;
        /*
        printf("--%s----%s-----%d-----%d----%d\n",datosRazas[i].descripcion,datosRazas[i].tamanio,datosRazas[i].idRazas
                                               ,datosRazas[i].idPais,datosRazas[i].IsEmpty);
        */
    }

    return retorno;
}

