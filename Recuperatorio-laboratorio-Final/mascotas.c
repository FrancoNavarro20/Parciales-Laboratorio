#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
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
    float peso[7]={4.2,3.2,5.1,6.5,7.7,4.2,8.2};
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





































