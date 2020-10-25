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

#endif // RAZAS_H_INCLUDED
