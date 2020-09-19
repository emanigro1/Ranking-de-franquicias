#include <iostream>
#include <conio.h>
#include "TDA.h"
struct nodo
{
    EstructuraSucursales* sucursal=new EstructuraSucursales;
    nodo *siguiente;

}*primero,*ultimo;

void insertarNodo();
void mostrarLista();
void eliminarSucursal();
void modificarSucursal();
void buscarSucursar();

void menu();

using namespace std;

/*  Se pide elaborar:

    ● Un listado con el orden de las sucursales que más facturaron a nivel nacional y en
    cada provincia, (incluir los totales por provincia).

    ● Un ranking con las sucursales que mayor cantidad de artículos vendieron a nivel
    nacional y por provincia.

    ● Un ranking de rendimiento donde se busca las sucursales que mejores rendimientos
    por metro cuadrado tienen, ordenando por el cociente de facturación/metros
    cuadrados del local.
*/

int main()
{
    menu();

    return 0;
}


void menu()
{
    int opcion;

    do
    {
        cout<<"Bienvenido al administrador de sucursales"<<endl;
        cout<<"Elija un numero de opcion:"<<endl<<endl ;
        cout<<"1. Agregar sucursal."<<endl;
        cout<<"2. Mostrar sucursales."<<endl;
        cout<<"3. Buscar sucursar por ID."<<endl;
        cout<<"4. Modificar sucursal."<<endl;
        cout<<"5. Eliminar sucursal."<<endl<<endl;
        cout<<"0. Salir"<<endl<<endl;

        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
        case 1:
            insertarNodo();
            break;

        case 2:

            mostrarLista();
            break;

        case 3:
            buscarSucursar();
            break;

        case 4:
            modificarSucursal();
            break;

        case 5:
            eliminarSucursal();
            break;

        case 0:
            exit;
            break;

        default:
            cout<<"Opcion no encontrada."<<endl;
        }
    }
    while(opcion!=0);
    if(opcion==0){
         system("cls");
         cout<<endl<<"Hasta luego!!"<<endl;
    }
}

void insertarNodo ()
{
    system("cls");

    nodo*nuevo=new nodo();
    int codigo,articulos,numeroCasaMatriz;
    float montoMensual,metrosCuadrados;
    char provincia[20];

    cout<<"Ingrese un codigo"<<endl;
    fflush(stdin);
    cin>>codigo;
    cout<<"Ingrese una provincia"<<endl;
    fflush(stdin);
    cin>>provincia;
    cout<<"Ingrese cantidad de articulos"<<endl;
    fflush(stdin);
    cin>>articulos;
    cout<<"Ingrese monto mensual"<<endl;
    fflush(stdin);
    cin>>montoMensual;
    cout<<"Ingrese metros cuadrados"<<endl;
    fflush(stdin);
    cin>>metrosCuadrados;
    cout<<"Ingrese numero casa matriz"<<endl;
    fflush(stdin);
    cin>>numeroCasaMatriz;

    crearSucursal(nuevo->sucursal,codigo,provincia,articulos,montoMensual,metrosCuadrados,numeroCasaMatriz);

    if(primero==NULL)
    {
        primero=nuevo;
        ultimo=nuevo;
        primero->siguiente=NULL;

    }
    else
    {
        ultimo->siguiente=nuevo;
        nuevo->siguiente=NULL;
        ultimo=nuevo;
    }

    cout<<"\nSucursar cargada."<<endl;

    system ("pause");
    system("cls");
}

void mostrarLista()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;

    if(actual==NULL)
    {
        cout<<"La lista esta vacia."<<endl<<endl;
    }
    else
    {
        while(actual!=NULL)
        {
            mostrarSucursal(actual->sucursal);
            actual=actual->siguiente;
        }
    }
    system ("pause");
    system("cls");
}

void eliminarSucursal()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;
    nodo*anterior=new nodo();
    anterior = NULL;
    int encontrado=0;
    int codigo;

    if(actual==NULL)
    {
        cout<<"La lista esta vacia."<<endl<<endl;
    }
    else
    {
        cout<<"Ingrese codigo de sucursal a eliminar: ";
        cin>>codigo;

        while(actual!=NULL && encontrado==0)
        {
            if(codigo==getCodigo(actual->sucursal))
            {
                destruirSucursal(actual->sucursal);
                if(actual==primero){
                    primero=primero->siguiente;
                }else if(actual==ultimo){
                    anterior->siguiente=NULL;
                    ultimo=anterior;
                }else{
                    anterior->siguiente=actual->siguiente;
                }

                cout<<endl<<"Sucursal ID= "<<codigo<<" eliminada."<<endl;
                encontrado=1;
            }
            anterior=actual;
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            cout<<"Codigo de sucursal no encontrado."<<endl;
        }
    }
    system ("pause");
    system("cls");
}

void modificarSucursal()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;
    int opcion;

    if(actual==NULL)
    {
        cout<<"La lista esta vacia"<<endl<<endl;
    }
    else
    {
        int nuevoCodigo,nuevoCasaMatriz,nuevaCantArt,codigo,encontrado=0;
        float nuevoMontoMensual,nuevoMCuadrados;
        char nuevaProvincia[20];

        cout<<"Ingrese codigo de sucursal a modificar: ";
        cin>>codigo;

        while(actual!=NULL&&encontrado==0)
        {
            if(codigo==getCodigo(actual->sucursal))
            {  cout<<"\nSucursal elegida:";
                mostrarSucursal(actual->sucursal);
                encontrado=1;

                cout<<"\nIngrese el numero de la opcion elegida a modificar:\n\n";
                cout<<"1. Codigo.\n";
                cout<<"2. Provincia.\n";
                cout<<"3. Cantidad de articulos.\n";
                cout<<"4. Monto Mensual.\n";
                cout<<"5. Metros Cuadrados.\n";
                cout<<"6. Casa Matriz.\n\n";
                cout<<"Opcion: ";
                cin>>opcion;

                switch(opcion)
                {
                case 1:
                    cout<<endl<<"Valor actual: "<<getCodigo(actual->sucursal)<<endl<<"Valor nuevo: ";
                    cin>>nuevoCodigo;
                    setCodigo(actual->sucursal,nuevoCodigo);
                    break;

                case 2:
                    cout<<endl<<"Valor actual: "<<getProvincia(actual->sucursal)<<endl<<"Valor nuevo: ";
                    cin>>nuevaProvincia;
                    setProvincia(actual->sucursal,nuevaProvincia);
                    break;

                case 3:
                    cout<<endl<<"Valor actual: "<<getCantidadArticulos(actual->sucursal)<<endl<<"Valor nuevo: ";
                    cin>>nuevaCantArt;
                    setCantidadArticulos(actual->sucursal,nuevaCantArt);
                    break;

                case 4:
                    cout<<endl<<"Valor actual: "<<getMontoMensual(actual->sucursal)<<endl<<"Valor nuevo: ";
                    cin>>nuevoMontoMensual;
                    setMontoMensual(actual->sucursal,nuevoMontoMensual);
                    break;

                case 5:
                    cout<<endl<<"Valor actual: "<<getMCuadrados(actual->sucursal)<<endl<<"Valor nuevo: ";
                    cin>>nuevoMCuadrados;
                    setMCuadrados(actual->sucursal,nuevoMCuadrados);
                    break;

                case 6:
                    cout<<endl<<"Valor actual: "<<getCasaMatriz(actual->sucursal)<<endl<<"Valor nuevo: ";
                    cin>>nuevoCasaMatriz;
                    setCasaMatriz(actual->sucursal,nuevoCasaMatriz);
                    break;

                default:
                    cout<<"Opcion no encontrada"<<endl;

                }
            }
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            cout<<endl<<"Dato no encontrado"<<endl;
        }
    }
    system ("pause");
    system("cls");
}

void buscarSucursar()
{
    system("cls");

    nodo*actual=new nodo();
    actual=primero;
    int codigo,encontrado=0;

    if(actual==NULL)
    {
        cout<<"La lista esta vacia."<<endl<<endl;
    }
    else
    {
        cout<<"Ingrese codigo de sucursal a buscar:";
        cin>>codigo;

        while(actual!=NULL && encontrado==0)
        {
            if(codigo==getCodigo(actual->sucursal))
            {
                mostrarSucursal(actual->sucursal);
                encontrado=1;
            }
            actual=actual->siguiente;
        }
        if(encontrado==0)
        {
            cout<<endl<<"Dato no encontrado"<<endl;
        }
    }
        system ("pause");
    system("cls");
}
