#include "mascotas.h"
#include "razas.h"
#include "pais.h"
#ifndef MASCOTASYRAZAS_H_INCLUDED
#define MASCOTASYRAZAS_H_INCLUDED



int FuncionesSwitchMenu(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int cantMascotas,int cantRazas, int opcionIngresada);

int BuscarRaza(eRazas datosRazas[],int idMascotaRaza,int cantRazas,int* razaEncontrada);
int mostrar(eMascotas datosMascotas[],eRazas datosRazas[], ePais datosPais[], int cantMascotas, int cantRazas, int cantPaises);

//int mostrarMascotasYRazas(eMascotas datosMascotas[], eRazas datosRazas[],ePais datosPaises[],int cantMascotas,int cantRazas);

int MostrarRazaDeLasMascota(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int idRaza,int cantMascotas);

int MostrarRazasDeLasMascotas(eMascotas datosMascotas[],eRazas datosRazas[],ePais datosPaises[],int cantMascotas);

int eliminarMascota(eMascotas datosMascotas[],eRazas datosRazas[],int idEliminar,int cantMascotas);

int OrdenandoMacotasPorPeso(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas);

int OrdenandoMacotasPorId(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas);

int OrdenandoIds(eMascotas datosMascotas[], eRazas datosRazas[],int cantMascotas);

int modificarMascota(eMascotas datosMascotas[],int idModificar,int cantMascotas);
#endif // MASCOTASYRAZAS_H_INCLUDED
