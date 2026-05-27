/* Aqui es como la pila para deshacer la ultima asignacion */
#ifndef DESHACER_H
#define DESHACER_H

#include "estructuras.h"

/* Una asignacion es que paquete fue puesto en que camion */
typedef struct {
    Paquete paquete;
    int id_camion;
} Asignacion;

/* El nodo de la pila */
typedef struct NodoPila {
    Asignacion asignacion;
    struct NodoPila *siguiente;
} NodoPila;

/* La estructura de la pila */
typedef struct {
    NodoPila *tope;
    int total;
} PilaDeshacer;

/* Y los prototipos */
void inicializar_pila(PilaDeshacer *p);
int  apilar_asignacion(PilaDeshacer *p, Paquete paquete, int id_camion);
int  desapilar_asignacion(PilaDeshacer *p, Asignacion *salida);
int  pila_vacia(PilaDeshacer *p);
void liberar_pila(PilaDeshacer *p);

#endif
