#include <iostream>
#include <string.h>
#include "TDA.h"



using namespace std;

struct EstructuraSucursales;

void crearSucursal (EstructuraSucursales* sucur, int codigo, char provincia[20],int articulos, float montoMensual, float mCuadrados, int casaMatriz)
{

    //EstructuraSucursales * sucursal = new struct EstructuraSucursales;
    setCodigo(sucur,codigo);
    setProvincia(sucur,provincia);
    setCantidadArticulos(sucur,articulos);
    setMontoMensual(sucur,montoMensual);
    setMCuadrados(sucur,mCuadrados);
    setCasaMatriz(sucur,casaMatriz);
}

void destruirSucursal(EstructuraSucursales* sucursal)
{
    delete sucursal;
}

int getCodigo (EstructuraSucursales* sucursal)
{
    return sucursal->codigo;
}
void setCodigo (EstructuraSucursales* sucursal, int NewCodigo)
{
    sucursal->codigo=NewCodigo;
}

char *getProvincia(EstructuraSucursales* sucursal)
{
    return sucursal->provincia;
}
void setProvincia (EstructuraSucursales* sucursal,char NewProvincia[20])
{
    strcpy(sucursal->provincia,NewProvincia);
}

int getCantidadArticulos(EstructuraSucursales* sucursal)
{
    return sucursal->cantidad_articulos;
}
void setCantidadArticulos(EstructuraSucursales* sucursal, int NewCantidad)
{
    sucursal->cantidad_articulos=NewCantidad;
}

float getMontoMensual(EstructuraSucursales* sucursal)
{
    return sucursal->monto_mensual;
}
void setMontoMensual (EstructuraSucursales* sucursal, float NewMontoMensual)
{
    sucursal->monto_mensual=NewMontoMensual;
}

float getMCuadrados(EstructuraSucursales* sucursal)
{
    return sucursal->m_cuadrados;
}
void setMCuadrados (EstructuraSucursales* sucursal,float NewMetros)
{
    sucursal->m_cuadrados=NewMetros;
}

int getCasaMatriz(EstructuraSucursales* sucursal)
{
    return sucursal->casa_matriz;
}
void setCasaMatriz(EstructuraSucursales* sucursal, int NewCasaMatriz)
{
    sucursal->casa_matriz=NewCasaMatriz;
}

void mostrarSucursal (EstructuraSucursales* sucursal)
{
    cout<<endl<<".-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
    cout<<"Codigo Sucursar: "<<sucursal->codigo<<endl;
    cout<<"Provincia: "<<sucursal->provincia<<endl;
    cout<<"Cantidad de Articulos Vendidos: "<<sucursal->cantidad_articulos<<endl;
    cout<<"Monto Mensual: "<<sucursal->monto_mensual<<endl;
    cout<<"M2 del Local: "<<sucursal->m_cuadrados<<endl;
    cout<<"Casa Matriz: "<<sucursal->casa_matriz<<endl;
    cout<<endl<<"-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-"<<endl;
}


