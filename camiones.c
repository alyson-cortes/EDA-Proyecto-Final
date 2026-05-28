#include <stdio.h>
#include <stdlib.h>
#include "camiones.h" 

// 1. FUNCIÓN: Insertar camión en la Lista Circular
void insertarCamion(NodoCamion** cabeza, Camion nuevoCamion) {
    NodoCamion* nuevoNodo = (NodoCamion*)malloc(sizeof(NodoCamion));
    if (nuevoNodo == NULL) {
        printf("Error: No hay memoria disponible en el sistema.\n");
        return;
    }
    nuevoNodo->dato = nuevoCamion;
    
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        nuevoNodo->siguiente = *cabeza; 
    } else {
        NodoCamion* temp = *cabeza;
        while (temp->siguiente != *cabeza) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->siguiente = *cabeza; 
    }
}

// 2. FUNCIÓN: Rotar coches manualmente
void rotarCoches(NodoCamion** cabeza) {
    if (*cabeza != NULL) {
        *cabeza = (*cabeza)->siguiente; 
        printf("Turno rotado de forma manual. Camion activo cambiado.\n");
    } else {
        printf("Error: No existen camiones registrados en el sistema para rotar.\n"); 
    }
}

// 3. FUNCIÓN: Asignar paquetes 
void asignarPaqueteACoche(void* cola, NodoCamion** camionActual, void* topePila) {
    if (cola == NULL) {
        printf("Alerta: Estructura de cola no inicializada.\n");
        return;
    }
    if (*camionActual == NULL) {
        printf("Error: No se han registrado camiones en el sistema.\n");
        return;
    }

    printf("[LOGÍSTICA] Módulo listo. Conectando asignación con el menú principal...\n");
}