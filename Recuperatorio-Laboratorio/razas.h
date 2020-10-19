#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED
typedef struct
{
    int idRazas;
    char descripcion[30];
    char tamanio[30];
    char Pais[30];
   //ePais datosPaises;
}eRazas;


void InicializarRazas(eRazas datosRazas[],int cantRazas);
#endif // RAZAS_H_INCLUDED
