#include "pais.h"
#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED
typedef struct
{
    int idRazas;
    char descripcion[30];
    char tamanio[30];
    //char Pais[30];
    int IsEmpty;
    int idPais;
   //ePais datosPaises;
}eRazas;

int inicializarIsEmpty_Razas(eRazas datosRazas[],int cantRazas);

int hardcodear_Razas(eRazas datosRazas[]);

eRazas cargarUnaRaza(eRazas datosRazas[],ePais datosPaises[]);
int cargarRazas(eRazas datosRazas[],ePais datosPais[],int cantRazas);
int AsignandoTamanioRaza(char tamanioRaza[],int opcionIngresada);
int AsignarIdRaza(eRazas datosRazas[],int tamRazas,int* idDescripcion);
int asignando_Pais_Continente_tel(eRazas datosRazas[],ePais datosPaises[],int idElegido,int tamPais);
#endif // RAZAS_H_INCLUDED
