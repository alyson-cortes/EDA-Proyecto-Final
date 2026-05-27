/* Esta es la prueba aislada del historial y la pila de deshacer */
#include <stdio.h>
#include <string.h>
#include "estructuras.h"
#include "historial.h"
#include "deshacer.h"

int main(void) {
    Historial historial;
    PilaDeshacer pila;

    inicializar_historial(&historial);
    inicializar_pila(&pila);

    /* Aqui son los paquetes de prueba */
    Paquete p1 = {1, "CDMX", 5.0f};
    Paquete p2 = {2, "Guadalajara", 10.5f};
    Paquete p3 = {3, "Monterrey", 3.2f};

    /* Aqui se simulan tres asignaciones (paquetes puestos en camiones) */
    apilar_asignacion(&pila, p1, 101);
    apilar_asignacion(&pila, p2, 102);
    apilar_asignacion(&pila, p3, 101);
    printf("Asignaciones en la pila: %d\n\n", pila.total);

    /* Aqui hay que deshacer la ultima asignacion */
    Asignacion deshecha;
    if (desapilar_asignacion(&pila, &deshecha)) {
        printf("Deshecho: paquete %d (%s) del camion %d\n",
               deshecha.paquete.id, deshecha.paquete.destino, deshecha.id_camion);
        printf("Asignaciones restantes: %d\n\n", pila.total);
    }

    /* Y simulamos que p1 y p2 si fueron entregados */
    registrar_entrega(&historial, p1, 101);
    registrar_entrega(&historial, p2, 102);

    /* Ya depues se muestra el historial */
    imprimir_historial(&historial);

    /* Y al final se libera la memoria */
    liberar_historial(&historial);
    liberar_pila(&pila);

    return 0;
}
