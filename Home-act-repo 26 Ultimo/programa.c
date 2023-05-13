#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "map.h"
#define M 6

int main() {
    // Crear un mapa
    MAPLIST map;
    maplist_table_init(&map, M);

    // Insertar elementos en el mapa
    map_insert(&map, "hello", "world");
    map_insert(&map, "goodbye", "cruel world");
    map_insert(&map, "open", "source");
    map_insert(&map, "free", "software");

    // Buscar elementos en el mapa
    char *value;
    value = (char *) map_get(&map, "hello");
    if (value != NULL) {
        printf("Valor de \"hello\": %s\n", value);
    } else {
        printf("No se encontró \"hello\" en el mapa\n");
    }

    value = (int *) map_get(&map, "goodbye");
    if (value != NULL) {
        printf("Valor de \"goodbye\": %s\n", value);
    } else {
        printf("No se encontró \"goodbye\" en el mapa\n");
    }

    value = (char *) map_get(&map, "open");
    if (value != NULL) {
        printf("Valor de \"open\": %s\n", value);
    } else {
        printf("No se encontró \"open\" en el mapa\n");
    }

    value = (char *) map_get(&map, "free");
    if (value != NULL) {
        printf("Valor de \"free\": %s\n", value);
    } else {
        printf("No se encontró \"free\" en el mapa\n");
    }

    // Destruir el mapa
    map_destroy(&map);

    return 0;
}
