#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotasYrazas.h"
#include "menuYvalidaciones.h"
#define cMascotas 10
#define cRazas 4
#define LLENO 1
#define VACIO 0



int FuncionesSwitchMenu(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas,int cantRazas, int opcionIngresada)
{
    int retorno = -1;
    switch(opcionIngresada)
    {
        case 1:
            system("cls");
            printf("************Mostrar listado de mascotas y Razas*************\n");
            mostrarMascotasYRazas(datosMascotas,datosRazas,cantMascotas,cantRazas);
            retorno =0;
            system("pause");
            system("cls");
            break;
        case 2:
            printf("************Alta Mascotas*************\n");
            cargarArrayMascotas(datosMascotas,cantMascotas);
            break;

        default:
            printf("La opcion ingresada no esta dentro de las opciones.");
            retorno =0;
            system("pause");
            system("cls");
            break;
    }

    return retorno;
}


//------------------------------------------------Mostrar Mascotas y Razas------------------------------
int mostrarMascotasYRazas(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas,int cantRazas)
{
    int retorno = -1;
    int i;
    int RazaEncontrada;

    if(datosMascotas !=NULL && datosMascotas !=NULL && cantMascotas > 0 &&cantRazas > 0)
    {   printf("\n   ID    |   NOMBRE      |  SEXO   |   EDAD  |   TIPO   |  PESO   |    RAZA        |    PAIS\n");
        for(i=0;i<cantMascotas;i++)
        {
            //Funcion buscar RAZA;
            //buscarRaza = buscarRazaDisponible(datosRazas,datosMascotas[i].idRazas,cantRazas);
            BuscarRaza(datosRazas,datosMascotas[i].idRazas,cantRazas,&RazaEncontrada);
            if(datosMascotas[i].isEmpty == LLENO)
            {
                printf("   %-6d   %-14s   %-9c   %-6d  %-9s %-9.2f %-18s %-9s\n",datosMascotas[i].idMascota,datosMascotas[i].nombreMascota,datosMascotas[i].sexo,datosMascotas[i].edad, datosMascotas[i].tipo, datosMascotas[i].pesoMascota,datosRazas[RazaEncontrada].descripcion, datosRazas[RazaEncontrada].Pais);
                retorno = 0;
            }
        }
    }

    return retorno;
}

//------------------------------------------------Buscar raza------------------------------||

int BuscarRaza(eRazas datosRazas[],int idMascotaRaza,int cantRazas,int* razaEncontrada)
{
    int retorno =-1;
    int i;
    if(datosRazas!= NULL && razaEncontrada!= NULL && cantRazas>0&& idMascotaRaza>0)
    {
        for(i=0;i<cantRazas;i++)
        {
            if(idMascotaRaza == datosRazas[i].idRazas)
            {
                *razaEncontrada = i;
                retorno=0;
            }
        }
    }

    return retorno;
}
