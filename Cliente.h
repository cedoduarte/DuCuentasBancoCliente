#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente Cliente;
typedef struct Cuenta Cuenta;

struct Cliente
{
    int id;
    char nombre[256];
    char direccion[256];
    char telefono[50];
};

struct Cuenta
{
    int id;
    int idCliente;
    float saldo;
};

void almacenaCliente(Cliente *cliente, const char *nombreArchivo);

void almacenaCuenta(Cuenta *cuenta, const char *nombreArchivoCuenta,
                    const char *nombreArchivoCliente);

Cliente *leeClientes(const char *nombreArchivoCliente, int *size);
Cuenta *leeCuentas(const char *nombreArchivoCuenta, int *size);

#endif // CLIENTE_H

