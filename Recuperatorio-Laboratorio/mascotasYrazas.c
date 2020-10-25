#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotasYrazas.h"
#include "pais.h"
#include "mascotas.h"
#include "menuYvalidaciones.h"
#define cMascotas 10
#define cRazas 4
#define LLENO 1
#define VACIO 0



int FuncionesSwitchMenu(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int cantMascotas,int cantRazas, int opcionIngresada)
{
    int retorno = -1;
    //variables case 4;
    char guardarOpcionEliminar[10];
    int opcionEliminar;
    //variables case 6
    char guardarOpcionModificar[10];
    int opcionModificar;
    //variables case 8
    //int contadoresMascotas[10];
    //int idPaisConMasMascotas;

    switch(opcionIngresada)
    {
        case 1:
            system("cls");
        printf("   %-6d   %-14s   %-9c   %-6d  %-9s %-9.2f %-18s %-9s\n",datosMascotas[0].idMascota,datosMascotas[0].nombreMascota,datosMascotas[0].sexo,datosMascotas[0].edad, datosMascotas[0].tipo, datosMascotas[0].pesoMascota,datosRazas[0].descripcion, datosPaises[0].nombrePais);

            printf("************Mostrar listado de mascotas y Razas*************\n");
           // mostrarMascotasYRazas(datosMascotas,datosRazas,datosPaises,cantMascotas,cantRazas);
            mostrar(datosMascotas,datosRazas,datosRazas,cantMascotas,cantRazas,cantRazas);
            retorno =0;
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            printf("************Alta Mascotas*************\n");
            cargarArrayMascotas(datosMascotas,datosRazas,cantMascotas);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("************Mostrando las razas con sus mascotas*************\n");
            MostrarRazasDeLasMascotas(datosMascotas,datosRazas,datosPaises,cantMascotas);

            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            //mostrarMascotasYRazas(datosMascotas,datosRazas,datosPaises,cantMascotas,cantRazas);
            ingresarOpcionChar(guardarOpcionEliminar,"Ingrese el id de la mascota que desea eliminar:");
            opcionErrorNumeros(guardarOpcionEliminar,"Error,re-ingrese el id de la mascota que desea eliminar:",&opcionEliminar);
            if(eliminarMascota(datosMascotas,datosRazas,opcionEliminar,cantMascotas) == -1)
            {
                printf("\nNo se encontro el id ingresado.\n");
            }
            else
            {
                printf("\nLa mascota se elimino correctamente.\n");
            }
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            printf("**************Mostar mascotas y razas por peso*********************\n");
            OrdenandoMacotasPorPeso(datosMascotas,datosRazas,cantMascotas);
            //mostrarMascotasYRazas(datosMascotas,datosRazas,datosPaises,cantMascotas,cantRazas);

            printf("\n");
            //OrdenandoMacotasPorId(datosMascotas,datosRazas,cantMascotas);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            printf("**************Modificar Mascotas************************************\n");
            //mostrarMascotasYRazas(datosMascotas,datosRazas,datosPaises,cantMascotas,cantRazas);
            ingresarOpcionChar(guardarOpcionModificar,"Ingrese el id de la mascota que desea modificar:");
            opcionErrorNumeros(guardarOpcionModificar,"Error,re-ingrese el id de la mascota que desea eliminar:",&opcionModificar);
            if(modificarMascota(datosMascotas,opcionModificar,cantMascotas) == -1)
            {
                printf("\nNo se encontro el id de la mascota que se quiere modificar\n");
            }
            else
            {
                printf("\nLa mascota se modifico correctamente\n");
            }
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            printf("**************Alta Razas**********************************\n");
            /*
            cargarRazas(datosRazas,cantRazas);
            */
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            /*
            PaisConMasMascotas(datosMascotas,datosRazas,cantMascotas,&idPaisConMasMascotas);
            printf("\nEl pais con mas mascotas dentro de la veterinaria es: %s", datosRazas[idPaisConMasMascotas].Pais);

            printf("*********Mostrando el pais con mas mascotas dentro de la Veterinaria***********\n");
            ContadoresDeMascotas(datosMascotas,datosRazas,cantMascotas,contadoresMascotas);
            PaisConMasMascotas(datosMascotas,datosRazas,cantMascotas,contadoresMascotas,&idPaisConMasMascotas);
            printf("\nEl pais con mas mascotas dentro de la veterinaria es: %s", datosRazas[idPaisConMasMascotas].Pais);
            printf("\n");
            */
            system("pause");
            system("cls");
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
int mostrar(eMascotas datosMascotas[],eRazas datosRazas[], ePais datosPais[], int cantMascotas, int cantRazas, int cantPaises)
{
    int retorno=-1;
    int i;
    for(i=0;i<cantMascotas;i++)
    {
        if(datosMascotas[i].isEmpty == LLENO)
        {
            printf("     %-14s   %-7c   %-6d  %-9s %-12.2f %-12s %-9s\n",datosMascotas[i].nombreMascota,datosMascotas[i].sexo,datosMascotas[i].edad, datosMascotas[i].tipo, datosMascotas[i].pesoMascota,datosRazas[i].descripcion, datosPais[i].nombrePais);
            retorno =0;
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
                break;
            }
        }
    }

    return retorno;
}

//------------------------------------------------Buscar raza------------------------------||

int BuscarPais(ePais datosPais[],int idRaza,int cantPaises,int* PaisEncontrada)
{
    int retorno =-1;
    int i;
    if(datosPais!= NULL && PaisEncontrada!= NULL && cantPaises>0&& idRaza>0)
    {
        for(i=0;i<cantPaises;i++)
        {
            if(idRaza == datosPais[i].Idpais)
            {
                *PaisEncontrada = i;
                retorno=0;
                break;

            }
        }
    }

    return retorno;
}


//-------------------Mostrar Listado de razas con sus animales---------------------||

int MostrarRazaDeLasMascota(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int idRaza,int cantMascotas)
{
    int retorno = -1;
    int j;

    if(datosMascotas!= NULL && cantMascotas>0&& idRaza>0)
    {
        printf("\n |   NOMBRE      |  SEXO   |   EDAD  |   TIPO   |  PESO   |    RAZA      |    PAIS\n");
        for(j=0;j<cantMascotas;j++)
        {
            if(idRaza == datosMascotas[j].idRazas && datosMascotas[j].isEmpty == LLENO)
            {
                printf("     %-14s   %-7c   %-6d  %-9s %-12.2f %-12s %-9s\n",datosMascotas[j].nombreMascota,datosMascotas[j].sexo,datosMascotas[j].edad, datosMascotas[j].tipo, datosMascotas[j].pesoMascota,datosRazas[idRaza-1].descripcion, datosPaises[idRaza-1].nombrePais);
                retorno = 0;
            }
        }
    }

    return retorno;
}

//-------------------Mostrar Listado de razas con sus animales---------------------||

int MostrarRazasDeLasMascotas(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int cantMascotas)
{
    int retorno = -1;
    int j;
    if(datosMascotas!= NULL && cantMascotas>0)
    {

        for(j=0;j<cantMascotas;j++)
        {

            if(datosMascotas[j+1].isEmpty == LLENO)
            {
                MostrarRazaDeLasMascota(datosMascotas,datosRazas,datosPaises,j+1,cantMascotas);
                retorno = 0;
            }
        }
    }

    return retorno;
}
//-------------------ELIMINAR MASCOTAS---------------------||


int eliminarMascota(eMascotas datosMascotas[],eRazas datosRazas[],int idEliminar,int cantMascotas)
{
    int retorno = -1;
    int i;
    if(datosMascotas != NULL &&datosMascotas != NULL && cantMascotas > 0 && idEliminar > 0)
    {
        for(i=0;i<cantMascotas;i++)
        {
            if(idEliminar == datosMascotas[i].idMascota)
            {
                datosMascotas[i].isEmpty = VACIO;
                retorno =0;
            }
        }
    }
    return retorno;
}


//-------------------MODIFICAR MASCOTAS---------------------||


int modificarMascota(eMascotas datosMascotas[],int idModificar,int cantMascotas)
{
    int retorno = -1;
    int i;
    if(datosMascotas != NULL &&datosMascotas != NULL && cantMascotas > 0 && idModificar > 0)
    {
        for(i=0;i<cantMascotas;i++)
        {
            if(idModificar == datosMascotas[i].idMascota)
            {
                datosMascotas[i].isEmpty = VACIO;
                datosMascotas[i] = cargarUnaMascota();
                datosMascotas[i].isEmpty = LLENO;
                datosMascotas[i].idMascota = idModificar;
                retorno = 0;
            }
        }
    }
    return retorno;
}

//-------------------ORDENAR MASCOTAS POR PESO---------------------||

int OrdenandoMacotasPorPeso(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas)
{
    int retorno = -1;
    int i,j;
    eMascotas auxMascotas;

    if(datosMascotas !=NULL && datosMascotas !=NULL && cantMascotas > 0)
    {
        for(i=0;i<cantMascotas-1;i++)
        {
            for(j=i+1;j<cantMascotas;j++)
            {
                if(datosMascotas[i].pesoMascota < datosMascotas[j].pesoMascota && datosMascotas[i].isEmpty == LLENO)
                {
                   auxMascotas = datosMascotas[i];
                   datosMascotas[i] =datosMascotas[j];
                   datosMascotas[j] = auxMascotas;
                   break;
                }
            }

        }
    }

    return retorno;
}

//-------------------ORDENAR MASCOTAS POR ID (REPARACION) ---------------------||
/*
int OrdenandoMacotasPorId(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas)
{
    int retorno = -1;
    int i,j;
    eMascotas auxMascotas;

    if(datosMascotas !=NULL && datosMascotas !=NULL && cantMascotas > 0)
    {
        for(i=0;i<cantMascotas-1;i++)
        {
            for(j=i+1;j<cantMascotas;j++)
            {
                if(datosMascotas[i].idMascota > datosMascotas[j].idMascota && datosMascotas[i].isEmpty == LLENO)
                {
                   auxMascotas = datosMascotas[i];
                   datosMascotas[i] =datosMascotas[j];
                   datosMascotas[j] = auxMascotas;
                }
            }

        }
    }

    return retorno;
}
*/
/*
int PaisConMasMascotas(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas,int* idPaisMascotas)
{
    int retorno = -1;
    int contador = 0;
    int i,j;

    if(datosMascotas!= NULL && cantMascotas>0)
    {
        for(i=0;i<cantMascotas-1;i++)
        {
            for(j=0;j<cantMascotas;j++)
            {
                if(strcmp(datosRazas[i].Pais,datosRazas[j].Pais) == 0 && datosMascotas[i].isEmpty == LLENO)
                {
                    contador++;
                    *idPaisMascotas = contador;
                    retorno = 0;
                }
            }

        }
    }

    return retorno;
}




int ContadoresDeMascotas(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas,int* cargarContadores)
{
    int retorno = -1;
    int j;

    if(datosMascotas!= NULL && cantMascotas>0)
    {
        for(j=0;j<cantMascotas;j++)
        {
            if(datosMascotas[j].isEmpty == LLENO)
            {
                cargarContadores[j] = ContadorMascotas(datosMascotas,j+1,cantMascotas);
                retorno = 0;
            }
        }
    }

    return retorno;
}




int ContadorMascotas(eMascotas datosMascotas[],int idRaza,int cantMascotas)
{
    int retorno = 0;
    int j;
    int contador = 0;
    if(datosMascotas!= NULL && cantMascotas>0&& idRaza>0)
    {
        for(j=0;j<cantMascotas;j++)
        {
            if(idRaza == datosMascotas[j].idRazas && datosMascotas[j].isEmpty == LLENO)
            {
                contador++;
            }
        }
        retorno = contador;
    }


    return retorno;
}

*/




