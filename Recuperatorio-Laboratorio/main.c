#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotasYrazas.h"
#include "menuYvalidaciones.h"
#define cMascotas 10
#define cRazas 4
#define LLENO 1
#define VACIO 0
/*
#-Tenemos un listado de mascotas(nombre,edad,sexo{f o m},tipo{gato ,perro o raro})
tenemos por ahora 5 mascotas ​pero tengo lugar para 10.
#Tenemos un listado de razas(descripción,tamaño{chico ,mediano o grande},país de
origen)
listado de razas para hardcodear :
a-siames, chico,tailandia
b- doberman ,grande,alemania
c- persa,mediano,persia
d-pastor belga, grande, bélgica
las 5 mascotas están formadas por los siguientes datos:
a- 3 gatos
b- 2 perros
c- los demás datos deben ser hardcodeados por el alumno.
1-Se debe mostrar un listado de mascotas con sus razas y países de origen .

*/
int main()
{
    eMascotas  datosMascotas[cMascotas];
    eRazas datosRazas[cRazas];
    int opcionMenuPrincipal;

    //1.Inicializar Isempty de mascotas;
    inicializar_IsEmty(datosMascotas,cMascotas);
    //2.Harcodear datos;
    InicializarMascotas(datosMascotas);
    InicializarRazas(datosRazas,cRazas);
    do
    {
        menu("1.Mostrar mascotas y razas\n2.Alta mascota","Ingrese una opcion:","Error-re-Ingrese la opcion:",&opcionMenuPrincipal);
        FuncionesSwitchMenu(datosMascotas,datosRazas,cMascotas,cRazas,opcionMenuPrincipal);


    }while(opcionMenuPrincipal!= 5);

    return 0;

}
