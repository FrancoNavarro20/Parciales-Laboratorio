#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct
{
    int idMascota;
    char nombreMascota[30];
    int edad;
    char sexo;
    char tipo[20];
    float pesoMascota;
    int idRazas;
    int isEmpty;

}eMascotas;

int inicializar_IsEmty(eMascotas datosMascotas[], int cant);

void InicializarMascotas(eMascotas datosMascotas[]);
#endif // MASCOTAS_H_INCLUDED
