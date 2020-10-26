#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "franco_validaciones.h"
#define VACIO 0
#define LLENO 1


int inicializarIsEmpty_Mascotas(eMascotas datosMascotas[],int cantMascotas)
{
    int retorno = -1;
    int i;
    if(datosMascotas != NULL && cantMascotas > 0)
    {
        for(i=0;i<cantMascotas;i++)
        {
            datosMascotas[i].isEmpty = VACIO;
            //printf("IsEmpty numero %d : %d\n",i+1,datosMascotas[i].isEmpty);
            retorno = 0;
        }

    }

    return retorno;
}

int hardcodear_Mascotas(eMascotas datosMascotas[])
{
    int retorno =-1;
    int id[7] ={1,2,3,4,5,6,7};
    char nombre[7][30] ={"Sami","Kechi","Tobi","Oso","Negro","Roke","Tofi"};
    int edad[7]={5,3,1,4,7,4,9};
    char sexo[7]={'f','f','m','m','m','m','m'};
    char tipo[7][20]={"perro","perro","gato","gato","gato","perro","perro"};
    float peso[7]={4.2,3.2,5.1,6.5,7.7,9.2,8.2};
    int idDeLasRazas[7] ={4,2,1,3,2,5,6};
    //*-------*
    int i;
    for(i=0;i<7;i++)
    {
        datosMascotas[i].idMascota = id[i];
        strcpy(datosMascotas[i].nombreMascota,nombre[i]);
        datosMascotas[i].edad = edad[i];
        datosMascotas[i].sexo = sexo[i];
        strcpy(datosMascotas[i].tipo,tipo[i]);
        datosMascotas[i].pesoMascota = peso[i];
        datosMascotas[i].idRazas = idDeLasRazas[i];
        datosMascotas[i].isEmpty = LLENO;
        /*
        printf("%d----%s----%d-----%c----%s---%.2f------%d\n",datosMascotas[i].idMascota,datosMascotas[i].nombreMascota
                                 ,datosMascotas[i].edad,datosMascotas[i].sexo,datosMascotas[i].tipo,datosMascotas[i].pesoMascota
                                 ,datosMascotas[i].idRazas);
        */
        retorno =0;
    }

    return retorno;
}

//****Alta mascotas******

eMascotas cargarUnaMascota(eRazas datosRazas[])
{
    eMascotas mascotas;
    char guardarNombreMascota[30];
    char guardarEdadMascota[5];
    int EdadMascota;
    char sexo;
    char guardarTipoMascota[20];
    char guardarPesoMascota[15];
    float PesoMascota;
    int IdrazaAsignada;
    int opcion;
    int cantidadMaximaValidada;
    char guardarIdRaza[10];
    //Nombre mascota;
    ingresarOpcionChar(guardarNombreMascota,"Ingrese el nombre de la mascota:");
    opcionErrorCadena(guardarNombreMascota,"Error,re-ingrese el nombre de la mascota");

    strncpy(mascotas.nombreMascota,guardarNombreMascota,30);

    //Edad mascota
    ingresarOpcionChar(guardarEdadMascota,"Ingrese la edad de la mascota:");
    opcionErrorNumeros(guardarEdadMascota,"Error,re.-ingrese la edad de las mascota:",&EdadMascota);
    mascotas.edad = EdadMascota;

    //Sexo mascota
    ingresarOpcionSoloUnChar(&sexo,"Ingrese el sexo de la mascota(m/f):");
    //printf("El valor del sexo es : %c",sexo);
    opcionErrorSexo(sexo,"Error, re-ingrese el sexo de la mascota (m/f):");
    mascotas.sexo = sexo;

    //Tipo mascota
    menu("1.perro\n2.gato\n3.raro","Ingrese el numero del tipo de la mascota:","Error,re-ingrese el numero del tipo de su mascota:",&opcion);
    AsignandoTipoMascota(guardarTipoMascota,opcion);

    strncpy(mascotas.tipo,guardarTipoMascota,20);

    //Peso mascota
    ingresarOpcionChar(guardarPesoMascota,"Ingrese el peso de la mascota(ej 8.3, 4.1, 7.2):");
    opcionErrorNumerosFlotantes(guardarPesoMascota,"Error,re-ingrese el peso de la mascota(ej 8.3, 4.1, 7.2):");
    PesoMascota = atof(guardarPesoMascota);
    mascotas.pesoMascota = PesoMascota;

    //Id raza
    mostrarOpcionesRazas(datosRazas,10,&cantidadMaximaValidada);
    menu(" ","Ingrese el numero de la raza de la mascota:","Error,re-ingrese el numero de la raza de su mascota:",&IdrazaAsignada);
    while(verificarIdRazaExiste(datosRazas,10,IdrazaAsignada) == -1)
    {
        ingresarOpcionChar(guardarIdRaza,"Ingrese nuevamente el numero de la raza:");
        opcionErrorNumeros(guardarIdRaza,"Error solo numeros, re-ingrese el numero de la raza:",&IdrazaAsignada);

    }

    mascotas.idRazas = IdrazaAsignada;
    //AgregarIdRazasEnRazas(datosMascotas,datosRazas,10,IdrazaAsignada);
    //datosRazas.idRazas = IdrazaAsignada;

    return mascotas;
}
/*
int AgregarIdRazasEnRazas(eMascotas datosMascotas[],eRazas datosRazas[],int cant, int idRazasAsignado)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL && datosMascotas != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(datosMascotas[i].isEmpty == LLENO)
            {
                datosRazas[i].idRazas = idRazasAsignado;
                retorno = 0;
            }
        }
    }

    return retorno;
}
*/
int mostrarOpcionesRazas(eRazas datosRazas[],int cant, int* cantidad)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(datosRazas[i].IsEmpty == LLENO)
            {
                printf("%d.%s\n",i+1 ,datosRazas[i].descripcion);
                *cantidad = i+1;
                retorno = 0;
            }
        }
    }

    return retorno;
}


int verificarIdRazaExiste(eRazas datosRazas[],int cant, int razaIngresada)
{
    int retorno = -1;
    int i;
    if(datosRazas != NULL && cant > 0 && razaIngresada > 0)
    {
        for(i=0;i<cant;i++)
        {
            if(razaIngresada == datosRazas[i].idRazas && datosRazas[i].IsEmpty == LLENO)
            {
                retorno = 0;
            }
        }
    }

    return retorno;
}


int AsignandoTipoMascota(char tipoMascota[],int opcionIngresada)
{
    int retorno = -1;
    char opcion[20];
    int opcionvalidada;
    switch(opcionIngresada)
    {
        case 1:
            strcpy(tipoMascota,"perro");
            //*tipoMascota = tipo;
            retorno =0;
            break;
        case 2:
            strcpy(tipoMascota,"gato");
            //strcpy(*tipoMascota,tipo);
            retorno =0;
            break;
        case 3:
            strcpy(tipoMascota,"raro");
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
                        strcpy(tipoMascota,"perro");
                        retorno =0;
                        break;
                    case 2:
                        strcpy(tipoMascota,"gato");
                        //strcpy(*tipoMascota,tipo);
                        retorno =0;
                        break;
                    case 3:
                        strcpy(tipoMascota,"raro");
                        retorno =0;
                        break;
                }
            }while(opcionvalidada < 1 || opcionvalidada > 3);
            retorno =0;
            break;
    }

    return retorno;
}

//**************Cargar Mascotas*******************
int cargarArrayMascotas(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas)
{
    int  retorno =-1;
    int i;
    if(datosMascotas!=NULL && cantMascotas > 0)
    {   for(i=0;i<cantMascotas;i++)
        {
            if(datosMascotas[i].isEmpty == VACIO)
            {
                datosMascotas[i]= cargarUnaMascota(datosRazas);
                datosMascotas[i].idMascota = i+1;
                datosMascotas[i].isEmpty = LLENO;
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}






























