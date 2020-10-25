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

int IsEmpty_Raza(eRazas datosRazas[], int cantRazas);

void InicializarRazas(eRazas datosRazas[],int cantRazas);

eRazas cargarUnaRaza();

int cargarRazas(eRazas datosRazas[],int cantRazas);

int AsignandoTamanioRaza(char tamanioRaza[],int opcionIngresada);
#endif // RAZAS_H_INCLUDED
