#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "menuYvalidaciones.h"
#define cMascotas 10
#define cRazas 10
#define LLENO 1
#define VACIO 0


//------------Hardcodear pais-------------------------------
void InicializarPaises(ePais datosPais[])
{

    char Nombrepais[][30]={"tailandia","alemania","persia","belgica","Argentina"};
    char continente[][30]={"Asia","Europa","Asia","Europa","America"};
    int codigoTel[] ={66,49,98,32,54};
    int id [] ={1,2,3,4,5};
    /*Pasar estos valores a  un array de mascotas*/
    int i;
    for(i=0;i<5;i++)
    {
        strcpy(datosPais[i].nombrePais,Nombrepais[i]);
        strcpy(datosPais[i].continente,continente[i]);
        datosPais[i].CodigoTelefonico = codigoTel[i];
        datosPais[i].Idpais = id[i];
    }

}
