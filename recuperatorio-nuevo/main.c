#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "razas.h"
#include "MostrarMascotasYrazasYpais.h"
#define cMascotas 10
#define cRazas 6

int main()
{
    eMascotas datosMascotas[cMascotas];
    eRazas datosRazas[cRazas];

    inicializar_IsEmty(datosMascotas,cMascotas);
    InicializarMascotas(datosMascotas);

    inicializar_IsEmty_Raza(datosMascotas,cRazas);
    InicializarRazas(datosRazas,cRazas);


    mostrar(datosMascotas,datosRazas,cMascotas,cRazas);
    return 0;
}
