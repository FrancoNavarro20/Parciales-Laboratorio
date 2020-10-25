#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"
#include "MostrarMascotasYrazasYpais.h"
#define cMascotas 10
#define LLENO 1
#define VACIO 0

int mostrar(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas,int cantRazas)
{
    int i;
    int RazaEncontrada;
    for(i=0;i<cantMascotas;i++)
    {
        BuscarRaza(datosRazas,datosMascotas[i].idRazas,cantRazas,&RazaEncontrada);
        if(datosMascotas[i].isEmpty == LLENO)
        {
            datosMascotas[1].pesoMascota = 3.5;
            printf("%-5d--%-5s---%-5d---%-5s--%-5c--%-5f--%-5d--%-5s\n",datosMascotas[i].idMascota,datosMascotas[i].nombreMascota
            ,datosMascotas[i].edad,datosMascotas[i].tipo,datosMascotas[i].sexo,datosMascotas[i].pesoMascota,
            datosMascotas[i].isEmpty, datosRazas[RazaEncontrada].descripcion);
        }
    }

    return 0;
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
