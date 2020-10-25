#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#define LLENO 1
#define VACIO 0


//------------iSEmpty-------------------------------
int inicializar_IsEmty(eMascotas datosMascotas[], int cant)
{
    int retorno = -1;
    int i;
    if(datosMascotas != NULL && cant >0)
    {
        for(i=0;i<cant;i++)
        {
            datosMascotas[i].isEmpty = VACIO;
            retorno = 0;
        }
    }

    return retorno;
}


//------------Hardcodear Mascotas-------------------------------
void InicializarMascotas(eMascotas datosMascotas[])
{
    int codigo[]={1,2,3,4,5,6,7};
    char nombre[][20]={"Michi","Firulais","Dobby","Bobby","Pucky","Roke","spike"};
    int edad[]={3,2,4,1,2,3,7};
    char tipo[][20]={"Gato","Perro","Perro","Gato","Gato","Perro","Perro"};
    char sexo[]={'m','f','m','f','m','m','m'};
    float peso[] = {8.5,3.5,6,2.7,9.8,4,6};
    int  idRazas[] = {4,2,1,3,2,5,6};

    /*Pasar estos valores a  un array de mascotas*/
    int i;
    for(i=0;i<7;i++)
    {
        datosMascotas[i].idMascota = codigo[i];
        strcpy(datosMascotas[i].nombreMascota,nombre[i]);
        datosMascotas[i].edad = edad[i];
        strcpy(datosMascotas[i].tipo,tipo[i]);
        datosMascotas[i].sexo = sexo[i];
        datosMascotas[i].idRazas = idRazas[i];

        datosMascotas[i].pesoMascota = peso[i];
        datosMascotas[i].isEmpty = LLENO;
        printf("%-5d--%-5s---%-5d---%-5s--%-5c--%-5f--%-5d\n",datosMascotas[i].idMascota,datosMascotas[i].nombreMascota
               ,datosMascotas[i].edad,datosMascotas[i].tipo,datosMascotas[i].sexo,datosMascotas[i].pesoMascota,
               datosMascotas[i].isEmpty);
    }
    datosMascotas[1].pesoMascota = 3.5;
}
