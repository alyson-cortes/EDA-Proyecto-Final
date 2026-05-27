/* Esta sera como la lista simple para guardar las entregas exitosas*/
#ifndef HISTORIAL_H
#define HISTORIAL_H

#include "estructuras.h"

/* La informacion de una entrega exitosa */
typedef struct {
    Paquete paquete;
    int id_camion;     
} Entrega;

/* El nodo de la lista simple uwu */
typedef struct NodoHistorial {
    Entrega entrega;
    struct NodoHistorial *siguiente;
} NodoHistorial;

/* Y la estructura del historial completo */
typedef struct {
    NodoHistorial *cabeza;
    int total_entregas;
} Historial;

/* Anche los prototipos */
void inicializar_historial(Historial *h);
int  registrar_entrega(Historial *h, Paquete paquete, int id_camion);
void imprimir_historial(Historial *h);
void liberar_historial(Historial *h);
int  historial_vacio(Historial *h);

#endif
