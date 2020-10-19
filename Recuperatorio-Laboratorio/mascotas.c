#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "menuYvalidaciones.h"
#define cMascotas 10
#define cRazas 4
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
            retorno =0;
        }
    }

    return retorno;
}

//------------Hardcodear Mascotas-------------------------------
void InicializarMascotas(eMascotas datosMascotas[])
{
    int codigo[]={1,2,3,4,5,6,7};
    char nombre[][20]={"Michi","Firulais","Dobby","Bobby","Pucky"};
    int edad[]={3,2,4,1,2,3,7};
    char tipo[][20]={"Gato","Perro","Perro","Gato","Gato"};
    char sexo[]={'m','f','m','f','m'};
    float peso[] = {8.5,3.5,6,2.7,9.8};
    int  idRazas[] = {4,2,1,3,2};

    /*Pasar estos valores a  un array de mascotas*/
    int i;
    for(i=0;i<5;i++)
    {
        datosMascotas[i].idMascota = codigo[i];
        strcpy(datosMascotas[i].nombreMascota,nombre[i]);
        datosMascotas[i].edad = edad[i];
        strcpy(datosMascotas[i].tipo,tipo[i]);
        datosMascotas[i].sexo = sexo[i];
        datosMascotas[i].idRazas = idRazas[i];
      //datosMascotas[i].idPais = idPaises[i];
        datosMascotas[i].pesoMascota = peso[i];
        datosMascotas[i].isEmpty = LLENO;
    }

}


eMascotas cargarUnaMascota()
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
    //Nombre mascota;
    ingresarOpcionChar(guardarNombreMascota,"Ingrese el nombre de la mascota:");
    opcionErrorCadena(guardarNombreMascota,"Error,re-ingrese el nombre de la mascota");

    strncpy(mascotas.nombreMascota,guardarNombreMascota,30);

    //Edad mascota
    ingresarOpcionChar(guardarEdadMascota,"Ingrese la edad de la mascota:");
    opcionErrorNumeros(guardarEdadMascota,"Error,re.-ingrese la edad de las mascota:");
    EdadMascota = atoi(guardarEdadMascota);
    mascotas.edad = EdadMascota;

    //Sexo mascota
    ingresarOpcionSoloUnChar(&sexo,"Ingrese el sexo de la mascota(m/f):");
    //printf("El valor del sexo es : %c",sexo);
    opcionErrorSexo(sexo,"Error, re-ingrese el sexo de la mascota (m/f):");
    mascotas.sexo = sexo;

    //Tipo mascota
    do
    {
        menu("1.perro\n2.gato\n3.raro","Ingrese el numero del tipo de la mascota:","Error,re-ingrese el numero del tipo de su mascota:",&opcion);
        AsignandoTipoMascota(guardarTipoMascota,opcion);

    }while(opcion <1 || opcion>3);

    strncpy(mascotas.tipo,guardarTipoMascota,20);

    //Peso mascota
    ingresarOpcionChar(guardarPesoMascota,"Ingrese el peso de la mascota(ej 8.3, 4.1, 7.2):");
    opcionErrorNumerosFlotantes(guardarPesoMascota,"Error,re-ingrese el peso de la mascota(ej 8.3, 4.1, 7.2):");
    PesoMascota = atof(guardarPesoMascota);
    mascotas.pesoMascota = PesoMascota;

    do
    {
        menu("1.Siames\n2.Doberman\n3.Persa\n4.Pastor belga","Ingrese el numero de la raza de la mascota:","Error,re-ingrese el numero de la raza de su mascota:",&IdrazaAsignada);
        AsignandoIdRaza(mascotas.idRazas,IdrazaAsignada);
    }while(IdrazaAsignada <1 || IdrazaAsignada>4);


    return mascotas;
}

int cargarArrayMascotas(eMascotas datosMascotas[],int cantMascotas)
{
    int  retorno =-1;
    int i;
    if(datosMascotas!=NULL && cantMascotas > 0)
    {   for(i=0;i<cantMascotas;i++)
        {
            if(datosMascotas[i].isEmpty == VACIO)
            {
                datosMascotas[i]= cargarUnaMascota();
                datosMascotas[i].idMascota = i+1;
                datosMascotas[i].isEmpty = LLENO;
                retorno = 0;
                break;
            }
        }

    }
    return retorno;
}


int AsignandoIdRaza(int idRazas,int opcionIngresada)
{
    int retorno = -1;

    switch(opcionIngresada)
    {
        case 1:
            idRazas = opcionIngresada;
            retorno =0;
            break;
        case 2:
            idRazas = opcionIngresada;
            retorno =0;
            break;
        case 3:
            idRazas = opcionIngresada;
            retorno =0;
            break;
        case 4:
            idRazas = opcionIngresada;
            retorno =0;
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


int AsignandoTipoMascota(char tipoMascota[],int opcionIngresada)
{
    int retorno = -1;
    char tipo[15];

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
            printf("La opcion ingresada no esta dentro de las opciones.");
            retorno =0;
            system("pause");
            system("cls");
            break;
    }

    return retorno;
}





















