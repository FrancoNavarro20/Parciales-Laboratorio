#include "mascotas.h"
#include "razas.h"

#ifndef MASCOTASYRAZAS_H_INCLUDED
#define MASCOTASYRAZAS_H_INCLUDED



int FuncionesSwitchMenu(eMascotas datosMascotas[],eRazas datosRazas[],int cantMascotas,int cantRazas, int opcionIngresada);

int mostrarMascotasYRazas(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas,int cantRazas);

int BuscarRaza(eRazas datosRazas[],int idMascotaRaza,int cantRazas,int* razaEncontrada);
#endif // MASCOTASYRAZAS_H_INCLUDED
