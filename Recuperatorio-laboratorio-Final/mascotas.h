#include "razas.h"
#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
typedef struct
{
    int idMascota;
    char nombreMascota[30];
    int edad;
    char sexo;
    char tipo[20];
    float pesoMascota;
    int idRazas;
    int isEmpty;

}eMascotas;

int inicializarIsEmpty_Mascotas(eMascotas datosMascotas[],int cantMascotas);

int hardcodear_Mascotas(eMascotas datosMascotas[]);

eMascotas cargarUnaMascota(eRazas datosRazas[]);
int cargarArrayMascotas(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas);
int mostrarOpcionesRazas(eRazas datosRazas[],int cant, int* cantidad);
int verificarIdRazaExiste(eRazas datosRazas[],int cant, int razaIngresada);
int AsignandoTipoMascota(char tipoMascota[],int opcionIngresada);
int AgregarIdRazasEnRazas(eMascotas datosMascotas[],eRazas datosRazas[],int cant, int idRazasAsignado);

#endif // MASCOTAS_H_INCLUDED
