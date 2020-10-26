#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    char nombrePais[30];
    char continente[30];
    int CodigoTelefonico;
    int Idpais;
    int isEmpty;
}ePais;

int hardcodear_Paises(ePais datosPais[]);

int mostrarPaises(ePais datosPais[],int tamPaises);
#endif // PAIS_H_INCLUDED
