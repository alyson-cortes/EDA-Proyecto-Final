/* Esta debe seria la implementacion de la pila */
#include <stdio.h>
#include <stdlib.h>
#include "deshacer.h"

void inicializar_pila(PilaDeshacer *p) {
    p->tope = NULL;
    p->total = 0;
}

int apilar_asignacion(PilaDeshacer *p, Paquete paquete, int id_camion) {
    NodoPila *nuevo = (NodoPila *)malloc(sizeof(NodoPila));
    if (nuevo == NULL) {
        return 0;
    }

    nuevo->asignacion.paquete = paquete;
    nuevo->asignacion.id_camion = id_camion;
    nuevo->siguiente = p->tope;  /* el nuevo apuntaría al tope actual */
    p->tope = nuevo;             /* entonces el nuevo es ahora el tope */
    p->total++;
    return 1;
}

int desapilar_asignacion(PilaDeshacer *p, Asignacion *salida) {
    if (pila_vacia(p)) {
        return 0;
    }

    NodoPila *temp = p->tope;
    *salida = temp->asignacion;   /* aqui guardamos lo que devolvemos */
    p->tope = temp->siguiente;    /* y ahora el tope ahora es el siguiente */
    free(temp);                   /* despues liberamos el nodo viejo */
    p->total--;
    return 1;
}

int pila_vacia(PilaDeshacer *p) {
    return (p->tope == NULL);
}

void liberar_pila(PilaDeshacer *p) {
    NodoPila *actual = p->tope;
    NodoPila *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    p->tope = NULL;
    p->total = 0;
}
