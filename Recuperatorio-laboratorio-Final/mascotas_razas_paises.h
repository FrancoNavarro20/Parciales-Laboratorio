#include "mascotas.h"
#include "razas.h"
#include "pais.h"
#ifndef MASCOTAS_RAZAS_PAISES_H_INCLUDED
#define MASCOTAS_RAZAS_PAISES_H_INCLUDED

int switchFuncionesMenu(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPais[],int tamMascotas,int tamRazas, int tamPaises, int opcion);
//***
int buscarRazas(int idRazaMascotas,eRazas datosRazas[],int tamRazas,int* razaEncontrada);
int buscarPais(int idRazaPais,ePais datosPais[],int tamPais,int* paisEncontrada);
int mostrarMascotas_Razas_Paises(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPais[],int tamMascotas,int tamRazas, int tamPaises);
//***
#endif // MASCOTAS_RAZAS_PAISES_H_INCLUDED
