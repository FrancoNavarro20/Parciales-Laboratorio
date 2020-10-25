#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "razas.h"
#include "menuYvalidaciones.h"
#define VACIO 0
#define LLENO 1

//------------iSEmpty-------------------------------
int IsEmpty_Raza(eRazas datosRazas[], int cantRazas)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL && cantRazas > 0)
    {
        for(i=0;i<cantRazas;i++)
        {
            datosRazas[i].IsEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}


//-------------Hardcodeando razas-----------------
void InicializarRazas(eRazas datosRazas[],int cantRazas)
{

    char descripcion[][30]={"siames","doberman","persa","pastor belga","Dogo","pastor aleman"};
    char tamanio[][20]={"chico","grande","mediano","grande","grande", "grande"};
    //char pais[][30]={"tailandia","alemania","persia","belgica"};
    int  idRazas[] = {1,2,3,4,5,6};
    int  idPais[] = {1,2,3,4,5,2};
    /*Pasar estos valores a un array de duenios*/
    int i;
    for(i=0;i<6;i++)
    {
        strncpy(datosRazas[i].descripcion,descripcion[i],30);
        strncpy(datosRazas[i].tamanio,tamanio[i],20);
        //strncpy(datosRazas[i].Pais,pais[i],30);
        //strncpy(datosRazas[i].pais,pais[i],30);
        datosRazas[i].idRazas = idRazas[i];
        datosRazas[i].idPais = idPais[i];
        datosRazas[i].IsEmpty = LLENO;
    }

}
/*
eRazas cargarUnaRaza()
{
    eRazas CargarUnaRaza;
    char guardarDescripcionRaza[30];
    //
    char guardarTamanioRaza[30];
    int tamanioRaza;
    //
    char guardarPais[30];

    //Descripcion Raza;
    ingresarOpcionChar(guardarDescripcionRaza,"Ingrese la descripcion de la raza(ej : Doberman,Persa,Pastor aleman):");
    opcionErrorCadena(guardarDescripcionRaza,"Error,re-ingrese el nombre de la mascota");

    strncpy(CargarUnaRaza.descripcion,guardarDescripcionRaza,30);

    //Tipo mascota
    menu("1.Chico\n2.Mediano\n3.Grande","Ingrese el tamanio de la raza:","Error,re-ingrese el tamanio de la raza:",&tamanioRaza);
    AsignandoTamanioRaza(guardarTamanioRaza,tamanioRaza);
    strncpy(CargarUnaRaza.tamanio,guardarTamanioRaza,30);

     //Descripcion Raza;
    ingresarOpcionChar(guardarPais,"Ingrese el pais de la raza:");
    opcionErrorCadena(guardarPais,"Error,re-ingrese el pais de la raza:");

    strncpy(CargarUnaRaza.Pais,guardarPais,30);


    return CargarUnaRaza;
}

int cargarRazas(eRazas datosRazas[],int cantRazas)
{
    int  retorno = -1;
    int i;
    if(datosRazas!=NULL && cantRazas > 0)
    {   for(i=0;i<cantRazas;i++)
        {
            if(datosRazas[i].IsEmpty == VACIO)
            {
                datosRazas[i] = cargarUnaRaza();
                datosRazas[i].IsEmpty = LLENO;
                datosRazas[i].idRazas = i+1;
                break;
            }
        }

    }
    return retorno;
}


int AsignandoTamanioRaza(char tamanioRaza[],int opcionIngresada)
{
    int retorno = -1;
    char opcion[20];
    int opcionvalidada;
    switch(opcionIngresada)
    {
        case 1:
            strcpy(tamanioRaza,"Chico");
            //tipoMascota = tipo;
            retorno =0;
            break;
        case 2:
            strcpy(tamanioRaza,"Mediano");
            //strcpy(*tipoMascota,tipo);
            retorno =0;
            break;
        case 3:
            strcpy(tamanioRaza,"Grande");
            //strcpy(*tipoMascota,tipo);
            retorno =0;
            break;
        default:
            do
            {
                ingresarOpcionChar(opcion,"Error,Ingrese nuevamente la opcion:");
                opcionvalidada = atoi(opcion);
                switch(opcionvalidada)
                {
                    case 1:
                        strcpy(tamanioRaza,"Chico");
                        retorno =0;
                        break;
                    case 2:
                        strcpy(tamanioRaza,"Mediano");
                        //strcpy(*tipoMascota,tipo);
                        retorno =0;
                        break;
                    case 3:
                        strcpy(tamanioRaza,"Grande");
                        retorno =0;
                        break;
                }
            }while(opcionvalidada < 1 || opcionvalidada > 3);
            retorno =0;
            break;
    }

    return retorno;
}

*/
