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

int inicializar_IsEmty(eMascotas datosMascotas[], int cant);
void InicializarMascotas(eMascotas datosMascotas[]);

eMascotas cargarUnaMascota();
int cargarArrayMascotas(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas);

int AsignandoTipoMascota(char tipoMascota[],int opcionIngresada);
int AsignandoIdRaza(int* idRazas,int opcionIngresada);

int mostrarOpcionesRazas(eRazas datosRazas[],int cant, int* cantidad);
int verificarIdRazaExiste(eRazas datosRazas[],int cant, int razaIngresada);
#endif // MASCOTAS_H_INCLUDED
