#ifndef TDA_H_INCLUDED
#define TDA_H_INCLUDED

struct EstructuraSucursales
{
    int codigo;
    char provincia[20];
    int cantidad_articulos;
    float monto_mensual;
    float m_cuadrados;
    int casa_matriz;
};

//typedef struct EstructuraSucursales* Sucursal;

void crearSucursal (EstructuraSucursales* sucur,int codigo, char Provincia[20],int Articulos, float MontoMensual, float mCuadrados, int casaMatriz);

void destruirSucursal(EstructuraSucursales* sucur);

int getCodigo (EstructuraSucursales* sucur);
void setCodigo (EstructuraSucursales* sucur, int NewCodigo);

char *getProvincia(EstructuraSucursales* sucur);
void setProvincia (EstructuraSucursales* sucur,char NewProvincia[20]);

int getCantidadArticulos(EstructuraSucursales* sucur);
void setCantidadArticulos(EstructuraSucursales* sucur, int NewCantidad);

float getMontoMensual(EstructuraSucursales* sucur);
void setMontoMensual (EstructuraSucursales* sucur, float NewMontoMensual);

float getMCuadrados(EstructuraSucursales* sucur);
void setMCuadrados (EstructuraSucursales* sucur,float NewMetros);

int getCasaMatriz(EstructuraSucursales* sucur);
void setCasaMatriz(EstructuraSucursales* sucur, int NewCasaMatriz);

void mostrarSucursal (EstructuraSucursales* sucur);

#endif // TDA_H_INCLUDED
