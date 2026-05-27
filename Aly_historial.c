/* Aqui será la mplementacion de la lista simple */
#include <stdio.h>
#include <stdlib.h>
#include "historial.h"

void inicializar_historial(Historial *h) {
    h->cabeza = NULL;
    h->total_entregas = 0;
}

int registrar_entrega(Historial *h, Paquete paquete, int id_camion) {
    NodoHistorial *nuevo = (NodoHistorial *)malloc(sizeof(NodoHistorial));
    if (nuevo == NULL) {
        return 0;  /*Aqui es para error de memoria */
    }

    nuevo->entrega.paquete = paquete;
    nuevo->entrega.id_camion = id_camion;
    nuevo->siguiente = NULL;

    if (h->cabeza == NULL) {
        /* En la lista vacia el nuevo es el primero */
        h->cabeza = nuevo;
    } else {
        /* Y aca es para buscar el ultimo nodo y enganchar */
        NodoHistorial *actual = h->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    h->total_entregas++;
    return 1;
}

void imprimir_historial(Historial *h) {
    if (historial_vacio(h)) {
        printf("El historial esta vacio. No hay entregas registradas.\n");
        return;
    }

    printf("=== HISTORIAL DE ENTREGAS (%d) ===\n", h->total_entregas);
    NodoHistorial *actual = h->cabeza;
    int i = 1;
    while (actual != NULL) {
        printf("%d) Paquete ID %d -> Destino: %s | Peso: %.2f kg | Camion ID: %d\n",
               i,
               actual->entrega.paquete.id,
               actual->entrega.paquete.destino,
               actual->entrega.paquete.peso_kg,
               actual->entrega.id_camion);
        actual = actual->siguiente;
        i++;
    }
    printf("===================================\n");
}

void liberar_historial(Historial *h) {
    NodoHistorial *actual = h->cabeza;
    NodoHistorial *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    h->cabeza = NULL;
    h->total_entregas = 0;
}

int historial_vacio(Historial *h) {
    return (h->cabeza == NULL);
}
