#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{
    char nombrePais[30];
    char continente[30];
    int CodigoTelefonico;
    int Idpais;
}ePais;

int hardcodear_Paises(ePais datosPais[]);
#endif // PAIS_H_INCLUDED
