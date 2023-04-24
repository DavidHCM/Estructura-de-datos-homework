#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "set.h"


void print_rom(TYPE data);
void print_entero(TYPE data);
int comparador_enteros(TYPE a, TYPE b);
int comparador_romanos(TYPE a, TYPE b);


char *conv_rom(int num) {
    const char *romanos[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int valores[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    char *resultado = (char *)malloc(sizeof(char) * 16); // Asignar memoria para el resultado
    resultado[0] = '\0'; // Inicializar el resultado como un string vacío

    for (int i = 0; i < 13; i++) {
        while (num >= valores[i]) {
            strcat(resultado, romanos[i]);
            num -= valores[i];
        }
    }

    return resultado;
}


int main()
{
    int rando;
    char rom[13];
    srand(time(NULL));
    SET *numero_ent = set_create(comparador_enteros, print_entero);
    SET *numero_rom = set_create(comparador_romanos, print_rom);

    for (int i = 0; i < 10; i++)
    {
        rando = rand() % (100 + 1 - 1) + 1;
        set_add(numero_ent, int_create(rando));
        char *reto_num_rom = conv_rom(rando);
        set_add(numero_rom, string_create(reto_num_rom));
    }
    printf("\n---------------------------------------------------------------------------\n");
    set_print(numero_ent);
    printf("\n---------------------------------------------------------------------------\n");
    set_print(numero_rom);

    set_destroy(numero_ent);
    set_destroy(numero_rom);

    return 0;
}


// ---------------------------------------------------

void print_rom(TYPE data)
{
    printf("%s", (char *) data);
    printf("\n");
}

// ---------------------------------------------------

int comparador_romanos(TYPE a, TYPE b)
{
    return strcmp((char *) a, (char *) b);
}

// ---------------------------------------------------

int comparador_enteros(TYPE a, TYPE b)
{
    int i1 = *((int *) a);
    int i2 = *((int *) b);
    return i1 - i2;
}

// ---------------------------------------------------

void print_entero(TYPE dato)
{
    // Reviso que no sea null para no tener problemas
    if(dato != NULL)
    {
        printf("%d\n", *((int *)dato));
    }
}

