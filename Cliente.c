#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>

void almacenaCliente(Cliente *cliente, const char *nombreArchivo)
{
    FILE *F;
    Cliente clienteAux;

    F = fopen(nombreArchivo, "rb");
    while (fread(&clienteAux, sizeof(Cliente), 1, F) > 0) {
        if (cliente->id == clienteAux.id) {
            return;
        }
    }
    fclose(F);
    F = fopen(nombreArchivo, "ab");
    fwrite(cliente, sizeof(Cliente), 1, F);
    fflush(F);
    fclose(F);
}

void almacenaCuenta(Cuenta *cuenta, const char *nombreArchivoCuenta,
                    const char *nombreArchivoCliente)
{
    FILE *Fcliente;
    FILE *Fcuenta;
    Cliente cliente;
    Cuenta cuentaAux;

    Fcuenta = fopen(nombreArchivoCuenta, "rb");
    while (fread(&cuentaAux, sizeof(Cuenta), 1, Fcuenta) > 0) {
        if (cuenta->id == cuentaAux.id) {
            return;
        }
    }
    fclose(Fcuenta);
    Fcliente = fopen(nombreArchivoCliente, "rb");
    while (fread(&cliente, sizeof(Cliente), 1, Fcliente) > 0) {
        if (cliente.id == cuenta->idCliente) {
            Fcuenta = fopen(nombreArchivoCuenta, "ab");
            fwrite(cuenta, sizeof(Cuenta), 1, Fcuenta);
            fflush(Fcuenta);
            fclose(Fcuenta);
            fclose(Fcliente);
            return;
        }
    }
    fclose(Fcliente);
}

Cliente *leeClientes(const char *nombreArchivoCliente, int *size)
{
    int idx;
    FILE *F;
    Cliente *clientes;
    Cliente cliente;

    clientes = (Cliente *) calloc(100, sizeof(Cliente));
    F = fopen(nombreArchivoCliente, "rb");
    idx = 0;
    while (fread(&cliente, sizeof(Cliente), 1, F) > 0) {
        clientes[idx] = cliente;
        ++idx;
    }
    *size = idx;
    fclose(F);
    return clientes;
}

Cuenta *leeCuentas(const char *nombreArchivoCuenta, int *size)
{
    int idx;
    FILE *F;
    Cuenta *cuentas;
    Cuenta cuenta;

    cuentas = (Cuenta *) calloc(100, sizeof(Cuenta));
    F = fopen(nombreArchivoCuenta, "rb");
    idx = 0;
    while (fread(&cuenta, sizeof(Cuenta), 1, F) > 0) {
        cuentas[idx] = cuenta;
        ++idx;
    }
    *size = idx;
    fclose(F);
    return cuentas;
}
