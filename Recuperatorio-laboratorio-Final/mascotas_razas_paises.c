#include <stdio.h>
#include <stdlib.h>
#include "mascotas_razas_paises.h"
#include "franco_validaciones.h"
#define cantMascotas 10
#define cantRazas 10
#define cantPaises 10
#define VACIO 0
#define LLENO 1



int switchFuncionesMenu(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPais[],int tamMascotas,int tamRazas, int tamPaises, int opcion)
{
    int retorno = -1;
    //case 3
    char guardarOpcionEliminar[15];
    int opcionEliminar;
    //case 4
    char guardarOpcionModificar[15];
    int opcionModificar;


    if(datosMascotas !=NULL && datosRazas != NULL && datosPais!=NULL  && tamMascotas>0 && tamRazas>0 && tamPaises>0)
    {
        switch(opcion)
        {
            case 1:
                system("cls");
                printf("******Mostrando lista de mascotas con sus razas y paises(recorda agrandar la consola para ver bien los datos)********\n\n");
                //mascotasPorID(datosMascotas,tamMascotas);
                mostrarMascotas_Razas_Paises(datosMascotas,datosRazas,datosPais,tamMascotas,cantRazas,cantPaises);
                system("pause");
                system("cls");
                break;
            case 2:
                system("cls");
                printf("*******Alta mascotas**********\n");
                cargarArrayMascotas(datosMascotas,datosRazas,tamMascotas);
                system("pause");
                system("cls");
                break;
            case 3:
                system("cls");
                printf("*********Eliminar Mascotas*****\n");
                mostrarMascotas_Razas_Paises(datosMascotas,datosRazas,datosPais,tamMascotas,tamRazas,tamPaises);
                ingresarOpcionChar(guardarOpcionEliminar,"Ingrese el id de la mascota que desea eliminar:");
                opcionErrorNumeros(guardarOpcionEliminar,"Error,re-ingrese el id de la mascota que desea eliminar:",&opcionEliminar);
                if(eliminarMascota(datosMascotas,datosRazas,opcionEliminar,tamMascotas) == -1)
                {
                    printf("No se ha encontrado la mascota\n");
                }else
                {
                    printf("La mascota se a eliminado correctamente\n");
                }
                system("pause");
                system("cls");
                break;
            case 4:
                system("cls");
                printf("**************Modificar Mascotas************************************\n");
                mostrarMascotas_Razas_Paises(datosMascotas,datosRazas,datosPais,tamMascotas,tamRazas,tamPaises);
                ingresarOpcionChar(guardarOpcionModificar,"\nIngrese el id de la mascota que desea Modificar:");
                opcionErrorNumeros(guardarOpcionModificar,"Error,re-ingrese el id de la mascota que desea Modificar:",&opcionModificar);
                if(modificarMascota(datosMascotas,datosRazas,opcionModificar,tamMascotas)== -1)
                {
                    printf("\nNo se ha encontrado la mascota.");

                }else
                {
                    printf("\nSe modifico correctamente la mascota.");
                }
                system("pause");
                system("cls");
                break;
            case 5:
                system("cls");
                printf("**************Mostrar Mascotas con sus Razas************************************\n");
                mostrarMascotasPorRazasTodas(datosMascotas,datosRazas,datosPais,tamMascotas);
                system("pause");
                system("cls");
                break;
            case 6:
                system("cls");
                printf("**************Mostrar Mascotas por Peso************************************\n");
                mascotasPorPeso(datosMascotas,tamMascotas);
                mostrarMascotas_Razas_Paises(datosMascotas,datosRazas,datosPais,tamMascotas,tamRazas,tamPaises);
                system("pause");
                system("cls");
                break;
            case 7:
                system("cls");
                printf("*******Alta raza***********\n");
                cargarRazas(datosRazas,datosPais,tamRazas);
                system("pause");
                system("cls");
                break;
            default:
                printf("La opcion ingresada no esta dentro de las opciones de la lista, vuelva a intentarlo...\n");
                system("pause");
                system("cls");
                break;
        }
    }


    return retorno;
}



//**************************************
int mostrarMascotas_Razas_Paises(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPais[],int tamMascotas,int tamRazas, int tamPaises)
{
    int retorno = -1;
    int i;
    int razaEncontrada;
    int paisEncontrada;
    if(datosMascotas !=NULL && datosRazas != NULL && datosPais!=NULL  && tamMascotas>0 && tamRazas>0 && tamPaises>0)
    {   printf(" ID   |  NOMBRE   |  EDAD  |   SEXO  |   TIPO   |  PESO   |   DESCRIPCION  |   TAMANIO   |   PAIS    |   CONTINENTE    |   CODIGO TEL\n");
        for(i=0;i<tamMascotas;i++)
        {
            buscarRazas(datosMascotas[i].idRazas,datosRazas,tamRazas,&razaEncontrada);
            //buscarPais(razaEncontrada,datosPais,tamPaises,&paisEncontrada);

            if(datosMascotas[i].isEmpty == LLENO)
            {
               printf("  %-6d %-12s %-9d %-9c %-9s %-9.2f %-15s  %-12s %-13s %-18s %-5d\n",datosMascotas[i].idMascota,datosMascotas[i].nombreMascota
                                 ,datosMascotas[i].edad,datosMascotas[i].sexo,datosMascotas[i].tipo,datosMascotas[i].pesoMascota
                                 ,datosRazas[razaEncontrada].descripcion,datosRazas[razaEncontrada].tamanio,datosPais[razaEncontrada].nombrePais,datosPais[razaEncontrada].continente
                                 ,datosPais[razaEncontrada].CodigoTelefonico);
            }
        }
    }

    return retorno;
}


int buscarRazas(int idRazaMascotas,eRazas datosRazas[],int tamRazas,int* razaEncontrada)
{
    int retorno = -1;
    int i;
    if(datosRazas !=NULL&& razaEncontrada!=NULL&& tamRazas>0 && idRazaMascotas>0)
    {
        for(i=0;i<tamRazas;i++)
        {
            if(idRazaMascotas == datosRazas[i].idRazas)
            {
                *razaEncontrada = i;
                 retorno =0;
                 break;
            }
        }
    }

    return retorno;
}
/*
int buscarPais(int idRazaPais,ePais datosPais[],int tamPais,int* paisEncontrada)
{
    int retorno = -1;
    int i;
    if(datosPais !=NULL&& paisEncontrada!=NULL&& tamPais>-1)
    {
        for(i=0;i<tamPais;i++)
        {
            if(idRazaPais+1 == datosPais[i].Idpais)
            {
                *paisEncontrada = i;
                 retorno =0;
                 break;
            }
        }
    }

    return retorno;
}
*/
//-------------------ELIMINAR MASCOTAS---------------------||

int eliminarMascota(eMascotas datosMascotas[],eRazas datosRazas[],int idEliminar,int tamMascotas)
{
    int retorno = -1;
    int i;
    if(datosMascotas != NULL &&datosMascotas != NULL && tamMascotas > 0 && idEliminar > 0)
    {
        for(i=0;i<tamMascotas;i++)
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


int modificarMascota(eMascotas datosMascotas[],eRazas datosRazas[],int idModificar,int tamMascotas)
{
    int retorno = -1;
    int i;
    if(datosMascotas != NULL &&datosMascotas != NULL && tamMascotas > 0 && idModificar > 0)
    {
        for(i=0;i<tamMascotas;i++)
        {
            if(idModificar == datosMascotas[i].idMascota)
            {
                datosMascotas[i].isEmpty = VACIO;
                datosMascotas[i] = cargarUnaMascota(datosRazas);
                datosMascotas[i].isEmpty = LLENO;
                datosMascotas[i].idMascota = idModificar;
                retorno = 0;
            }
        }
    }
    return retorno;
}
//-------------------Mostrar Listado de razas con sus animales---------------------||

int mostrarMascotasPorRaza(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int idRaza,int tamMascotas)
{
    int retorno = -1;
    int j;

    if(datosMascotas!= NULL && tamMascotas>0&& idRaza>0)
    {
        printf("\n |   NOMBRE      |  SEXO   |   EDAD  |   TIPO   |  PESO   |    RAZA           |    PAIS\n");
        for(j=0;j<tamMascotas;j++)
        {

            if(idRaza == datosMascotas[j].idRazas && datosMascotas[j].isEmpty == LLENO)
            {

                printf("     %-14s   %-7c   %-6d  %-9s %-12.2f %-17s %-9s\n",datosMascotas[j].nombreMascota,datosMascotas[j].sexo,datosMascotas[j].edad, datosMascotas[j].tipo
                                                                            , datosMascotas[j].pesoMascota,datosRazas[idRaza-1].descripcion, datosPaises[idRaza-1].nombrePais);
                retorno = 0;
            }
        }
    }

    return retorno;
}



int mostrarMascotasPorRazasTodas(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int tamMascotas)
{
    int retorno = -1;
    int j;
    //int canMascotasCargadas;
    if(datosMascotas!= NULL && tamMascotas>0)
    {

        for(j=0;j<tamMascotas;j++)
        {
            if(datosMascotas[j].isEmpty == LLENO && datosMascotas[j+1].isEmpty == LLENO)
            {

                mostrarMascotasPorRaza(datosMascotas,datosRazas,datosPaises,j+1,tamMascotas);
                retorno = 0;
            }
        }
    }

    return retorno;
}

//*******Mostrar masotas por peso************************



void mascotasPorPeso(eMascotas arrayMascotas[], int tamanioMascotas)
{
    int i;
    int j;
    eMascotas auxMascota;


    for (i=0;i<tamanioMascotas-1;i++)
    {
        for (j=i+1;j<tamanioMascotas;j++)
        {
            if (arrayMascotas[i].isEmpty == 1 && arrayMascotas[i].pesoMascota <= arrayMascotas[j].pesoMascota)
            {
                auxMascota = arrayMascotas[i];
                arrayMascotas[i] = arrayMascotas[j];
                arrayMascotas[j] = auxMascota;
            }
        }

    }

}
void mascotasPorID(eMascotas arrayMascotas[], int tamanioMascotas)
{
    int i;
    int j;
    eMascotas auxMascota;


    for (i=0;i<tamanioMascotas-1;i++)
    {
        for (j=i+1;j<tamanioMascotas;j++)
        {
            if (arrayMascotas[i].isEmpty == 1 && arrayMascotas[i].idMascota >= arrayMascotas[j].idMascota)
            {
                auxMascota = arrayMascotas[i];
                arrayMascotas[i] = arrayMascotas[j];
                arrayMascotas[j] = auxMascota;
            }
        }

    }
}

/*
int OrdenandoMacotasPorPeso(eMascotas datosMascotas[], eRazas datosRazas[],int tamMascotas)
{
    int retorno = -1;
    int i,j;
    eMascotas auxMascotas;

    if(datosMascotas !=NULL && datosMascotas !=NULL && tamMascotas > 0)
    {
        for(i=0;i<tamMascotas-1;i++)
        {
            for(j=i+1;j<tamMascotas;j++)
            {
                if(datosMascotas[i].pesoMascota > datosMascotas[j].pesoMascota && datosMascotas[i].isEmpty == LLENO)
                {
                   auxMascotas = datosMascotas[i];
                   datosMascotas[i] = datosMascotas[j];
                   datosMascotas[j] = auxMascotas;
                   break;
                }
            }

        }
    }

    return retorno;
}

int OrdenandoMacotasPorPeso(eMascotas datosMascotas[], eRazas datosRazas[],int tamMascotas)
{
    int retorno = -1;
    int i,j;
    eMascotas auxMascotas;

    if(datosMascotas !=NULL && datosMascotas !=NULL && tamMascotas > 0)
    {
        for(i=0;i<tamMascotas-1;i++)
        {
            for(j=i+1;j<tamMascotas;j++)
            {
                if(datosMascotas[i].pesoMascota > datosMascotas[j].pesoMascota && datosMascotas[i].isEmpty == LLENO)
                {
                   auxMascotas = datosMascotas[i];
                   datosMascotas[i] = datosMascotas[j];
                   datosMascotas[j] = auxMascotas;
                   break;
                }
            }

        }
    }

    return retorno;
}
*/








