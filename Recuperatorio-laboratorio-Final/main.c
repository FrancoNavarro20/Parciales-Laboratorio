#include <stdio.h>
#include <stdlib.h>
#include "mascotas_razas_paises.h"
#include "franco_validaciones.h"
#define cantMascotas 10
#define cantRazas 10
#define cantPaises 10
#define VACIO 0
#define LLENO 1



int main()
{

    eMascotas datosMascotas[cantMascotas];
    eRazas datosRazas[cantRazas];
    ePais datosPais[cantPaises];
    int opcionMenu;

    //int i;
    printf("Vamos que estoy contigo Hijito vamos a lograrlo juntos togeter \n");
    //****
    inicializarIsEmpty_Mascotas(datosMascotas,cantMascotas);
    hardcodear_Mascotas(datosMascotas);
    //****
    inicializarIsEmpty_Razas(datosRazas,cantRazas);
    hardcodear_Razas(datosRazas);
    //****
    hardcodear_Paises(datosPais);


    do
    {
        menu("1.Mostrar mascotas ,razas y paises\n2.Alta mascotas\n3.Eliminar mascotas\n4.Modificar mascotas\n5.Mostrar mascotas con sus razas\n6.Mostrar mascotas por peso\n7.Alta Raza","Ingrese una opcion:","Error solo numeros,vuelva a ingresar la opcion:",&opcionMenu);
        switchFuncionesMenu(datosMascotas,datosRazas,datosPais,cantMascotas,cantRazas,cantPaises,opcionMenu);
    }while(opcionMenu != 10);


    //***


    return 0;
}





















