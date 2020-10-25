#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "razas.h"
#define LLENO 1
#define VACIO 0


//------------iSEmpty-------------------------------
int inicializar_IsEmty_Raza(eRazas datosRazas[], int cant)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL && cant >0)
    {
        for(i=0;i<cant;i++)
        {
            datosRazas[i].IsEmpty = VACIO;
            retorno =0;
        }
    }

    return retorno;
}

//-------------Hardcodeando razas-----------------
void InicializarRazas(eRazas datosRazas[],int cantRazas)
{

    char descripcion[][30]={"siames","doberman","persa","pastor belga","Dogo","Pastor aleman"};
    char tamanio[][20]={"chico","grande","mediano","grande","grande","grande"};
    //char pais[][30]={"tailandia","alemania","persia","belgica"};
    int  idRazas[] = {1,2,3,4,5,6};
    int  idPais[] = {1,2,3,4,5,2};

    /*Pasar estos valores a un array de duenios*/
    int i;
    for(i=0;i<6;i++)
    {
        strncpy(datosRazas[i].descripcion,descripcion[i],30);
        strncpy(datosRazas[i].tamanio,tamanio[i],20);
        datosRazas[i].idRazas = idRazas[i];
        datosRazas[i].idPais = idPais[i];

        printf("%s--%s---%d---%d\n",datosRazas[i].descripcion,datosRazas[i].tamanio,datosRazas[i].idRazas,datosRazas[i].idPais);
    }

}
