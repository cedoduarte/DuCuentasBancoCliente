#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

#define ARCHIVO_CLIENTE "./cliente.bin"
#define ARCHIVO_CUENTA "./cuenta.bin"

int main(void)
{
    Cliente clientes[] = {
        { 1, "Juan", "Direccion 1", "555666555" },
        { 2, "Ana", "Direccion 2", "8888999988" },
        { 3, "Luis", "Direccion 3", "111222333" },
        { 4, "Fernando", "Direccion 4", "33445" },
        { 5, "Maribel", "Direccion 5", "898989" }
    };
    const int nClientes = sizeof(clientes) / sizeof(Cliente);
    int i;

    for (i = 0; i < nClientes; ++i) {
        almacenaCliente(&clientes[i], ARCHIVO_CLIENTE);
    }

    Cuenta cuentas[] = {
        { 1, 5, 1000.0 },
        { 2, 4, 2000.0 },
        { 3, 3, 3000.0 },
        { 4, 2, 4000.0 },
        { 5, 1, 5000.0 }
    };

    const int nCuentas = sizeof(cuentas) / sizeof(Cuenta);

    for (i = 0; i < nCuentas; ++i) {
        almacenaCuenta(&cuentas[i], ARCHIVO_CUENTA, ARCHIVO_CLIENTE);
    }

    Cliente *misClientes;
    Cuenta *misCuentas;
    int sizeCliente;
    int sizeCuenta;

    misClientes = leeClientes(ARCHIVO_CLIENTE, &sizeCliente);
    misCuentas = leeCuentas(ARCHIVO_CUENTA, &sizeCuenta);

    for (i = 0; i < sizeCliente; ++i) {
        printf("%d\n", misClientes[i].id);
        printf("%s\n", misClientes[i].nombre);
        printf("%s\n", misClientes[i].direccion);
        printf("%s\n", misClientes[i].telefono);
        printf("\n");
    }
    printf("=============================\n");
    for (i = 0; i < sizeCuenta; ++i) {
        printf("%d\n", misCuentas[i].id);
        printf("%d", misCuentas[i].idCliente);
        printf("%f\n", misCuentas[i].saldo);
        printf("\n");
    }

    free(misClientes);
    free(misCuentas);
    return 0;
}

