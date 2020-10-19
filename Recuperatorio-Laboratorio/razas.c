#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "razas.h"
#include "menuYvalidaciones.h"
#define VACIO 0
#define LLENO 1

//-------------Hardcodeando razas-----------------
void InicializarRazas(eRazas datosRazas[],int cantRazas)
{

    char descripcion[][30]={"siames","doberman","persa","pastor belga"};
    char tamanio[][20]={"chico","grande","mediano","grande"};
    char pais[][30]={"tailandia","alemania","persia","belgica"};
    int  idRazas[] = {1,2,3,4,5};

    /*Pasar estos valores a un array de duenios*/
    int i;
    for(i=0;i<cantRazas;i++)
    {
        strncpy(datosRazas[i].descripcion,descripcion[i],30);
        strncpy(datosRazas[i].tamanio,tamanio[i],20);
        strncpy(datosRazas[i].Pais,pais[i],30);
        //strncpy(datosRazas[i].pais,pais[i],30);
        datosRazas[i].idRazas = idRazas[i];
    }

}
