#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "razas.h"
#include "franco_validaciones.h"
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

//Alta razas !!!

eRazas cargarUnaRaza(eRazas datosRazas[],ePais datosPaises[])
{
    eRazas CargarUnaRaza;
    char guardarDescripcionRaza[30];
    int idRazaDescripcion;
    //
    char guardarTamanioRaza[30];
    int tamanioRaza;
    //
    char guardarPais[30];
    int idRazaPais;


    //Descripcion Raza;
    ingresarOpcionChar(guardarDescripcionRaza,"Ingrese la descripcion de la raza(ej : Doberman,Persa,Pastor aleman):");
    opcionErrorCadena(guardarDescripcionRaza,"Error,re-ingrese el nombre de la mascota");

    strncpy(CargarUnaRaza.descripcion,guardarDescripcionRaza,30);
    AsignarIdRaza(datosRazas,10,&idRazaDescripcion);
    CargarUnaRaza.idRazas = idRazaDescripcion;

    //Tipo mascota
    menu("1.Chico\n2.Mediano\n3.Grande","Ingrese el tamanio de la raza:","Error,re-ingrese el tamanio de la raza:",&tamanioRaza);
    AsignandoTamanioRaza(guardarTamanioRaza,tamanioRaza);
    strncpy(CargarUnaRaza.tamanio,guardarTamanioRaza,30);

    //Descripcion Raza;
    mostrarPaises(datosPaises,6);
    ingresarOpcionChar(guardarPais,"\nIngrese el id del pais de la raza:");
    opcionErrorNumeros(guardarPais,"Error,re-ingrese el pais de la raza:",&idRazaPais);
    //idRazaPais = atoi(guardarPais);
    while(idRazaPais<1 || idRazaPais>6)
    {
        ingresarOpcionChar(guardarPais,"\nIngrese el id del pais de la raza:");
        opcionErrorCadena(guardarPais,"Error,re-ingrese el pais de la raza:");
        idRazaPais = atoi(guardarPais);
    }
    //strncpy(CargarUnaRaza.Pais,guardarPais,30);
    CargarUnaRaza.idPais = idRazaPais;
    asignando_Pais_Continente_tel(datosRazas,datosPaises,idRazaPais,10);

    return CargarUnaRaza;
}

int cargarRazas(eRazas datosRazas[],ePais datosPais[],int cantRazas)
{
    int  retorno = -1;
    int i;
    if(datosRazas!=NULL && cantRazas > 0)
    {   for(i=0;i<cantRazas;i++)
        {
            if(datosRazas[i].IsEmpty == VACIO)
            {
                datosRazas[i] = cargarUnaRaza(datosRazas,datosPais);
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

int AsignarIdRaza(eRazas datosRazas[],int tamRazas,int* idDescripcion)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL && tamRazas > -1)
    {
        for(i=0;i<tamRazas;i++)
        {
            if(datosRazas[i].IsEmpty != LLENO)
            {
                *idDescripcion = i+1;
                retorno = 0;
            }

        }
    }

    return retorno;
}

int asignando_Pais_Continente_tel(eRazas datosRazas[],ePais datosPaises[],int idElegido,int tamPais)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL && tamPais > -1)
    {
        for(i=0;i<tamPais;i++)
        {
            if(datosPaises[i].isEmpty == VACIO)
            {
                strcpy(datosPaises[i].nombrePais,datosPaises[idElegido-1].nombrePais);
                strcpy(datosPaises[i].continente,datosPaises[idElegido-1].continente);
                datosPaises[i].CodigoTelefonico = datosPaises[idElegido-1].CodigoTelefonico;
                datosPaises[i].isEmpty = LLENO;
                retorno = 0;
                break;
            }

        }
    }

    return retorno;
}



