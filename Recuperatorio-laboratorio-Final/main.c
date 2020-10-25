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
        menu("1.Mostrar mascotas ,razas y paises\n","Ingrese una opcion:","Error solo numeros,vuelva a ingresar la opcion:",&opcionMenu);
        switchFuncionesMenu(datosMascotas,datosRazas,datosPais,cantMascotas,cantRazas,cantPaises,opcionMenu);
    }while(opcionMenu != 5);


    //***


    return 0;
}





















