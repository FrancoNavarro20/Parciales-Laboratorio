#ifndef RAZAS_H_INCLUDED
#define RAZAS_H_INCLUDED

typedef struct
{
    int idRazas;
    char descripcion[30];
    char tamanio[30];
    int idPais;
    int IsEmpty;
    //char Pais[30];
   //ePais datosPaises;
}eRazas;

int inicializar_IsEmty_Raza(eRazas datosRazas[], int cant);

void InicializarRazas(eRazas datosRazas[],int cantRazas);



#endif // RAZAS_H_INCLUDED
