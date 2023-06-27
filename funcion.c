
#include <stdio.h>
#include <string.h>
#define MaxProducts 100


void verProductos(char nombre[][100], char describ[][100], int* cantidades, float* precios, int numProductos) {
    if (numProductos == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    printf("=== PRODUCTOS ===\n");
    printf("%-20s %-20s %-10s %-10s\n", "Nombre", "describ", "Cantidad", "Precio");

    for (int i = 0; i < numProductos; i++) {
        printf("%-20s %-20s %-10d %-10.2f\n", nombre[i], describ[i], cantidades[i], precios[i]);
    }
}


void ingresarProducto(char nombre[][100], char describ[][100], int* cantidades, float* precios, int* numProductos) {
    if (*numProductos >= MaxProducts) {
        printf("El inventario está lleno. No se pueden agregar más productos.\n");
        return;
    }
    
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombre[*numProductos]);
    printf("Ingrese la descripcion del producto: ");
    scanf("%s", describ[*numProductos]);
    printf("Ingrese la cantidad: ");
    scanf("%d", &cantidades[*numProductos]);
    printf("Ingrese el precio: ");
    scanf("%f", &precios[*numProductos]);

    (*numProductos)++;

    printf("Producto agregado al inventario.\n");
}

void modificarProducto(char nombre[][100], char describ[][100], int* cantidades, float* precios, int numProductos) {
    if (numProductos == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    printf("Ingrese el número de producto a modificar (1-%d): ", numProductos);
    int numeroProducto;
    scanf("%d", &numeroProducto);

    if (numeroProducto < 1 || numeroProducto > numProductos) {
        printf("Número de producto inválido.\n");
        return;
    }

    printf("Producto actual:\n");
    printf("Nombre: %s\n", nombre[numeroProducto - 1]);
    printf("Nombre: %s\n", describ[numeroProducto - 1]);
    printf("Cantidad: %d\n", cantidades[numeroProducto - 1]);
    printf("Precio: %.2f\n", precios[numeroProducto - 1]);

    printf("Ingrese el nuevo nombre: ");
    scanf("%s", nombre[numeroProducto - 1]);
     printf("Ingrese la nuevo descripcion: ");
    scanf("%s", describ[numeroProducto - 1]);
    printf("Ingrese la nueva cantidad: ");
    scanf("%d", &cantidades[numeroProducto - 1]);
    printf("Ingrese el nuevo precio: ");
    scanf("%f", &precios[numeroProducto - 1]);

    printf("Producto modificado.\n");
}

void eliminarProducto(char nombre[][100],char describ[][100], int* cantidades, float* precios, int* numProductos) {
    if (*numProductos == 0) {
        printf("El inventario está vacío.\n");
        return;
    }

    printf("Ingrese el número de producto a eliminar (1-%d): ", *numProductos);
    int numeroProducto;
    scanf("%d", &numeroProducto);

    if (numeroProducto < 1 || numeroProducto > *numProductos) {
        printf("Número de producto inválido.\n");
        return;
    }

    for (int i = numeroProducto - 1; i < *numProductos - 1; i++) {
        strcpy(nombre[i], nombre[i + 1]);
        strcpy(describ[i], describ[i + 1]);
        cantidades[i] = cantidades[i + 1];
        precios[i] = precios[i + 1];
    }

    (*numProductos)--;

    printf("Producto eliminado.\n");

   
    

}
