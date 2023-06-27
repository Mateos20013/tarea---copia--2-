#include <stdio.h>
#include "funcion.h"

#define MaxProducts 100


int main() {
    char nombre[MaxProducts][100];
    char describ[MaxProducts][100];
    int cantidades[MaxProducts];
    float precios[MaxProducts];
    int numProductos = 0;
    int opcion;

    do {
        printf("=== MENU ===\n");
        printf("1. Ver productos\n");
        printf("2. Ingresar producto\n");
        printf("3. Modificar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                verProductos(nombre, describ, cantidades, precios, numProductos);
                break;
            case 2:
                ingresarProducto(nombre,describ, cantidades, precios, &numProductos);
                break;
            case 3:
                modificarProducto(nombre,describ, cantidades, precios, numProductos);
                break;
            case 4:
                eliminarProducto(nombre,describ, cantidades, precios, &numProductos);
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}

