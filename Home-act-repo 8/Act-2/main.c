#include <stdio.h>
#include <stdlib.h>
// I N T E G R A N T E S
// David Hernández Camacho
// Victor Sebastian Huerta Silva

int main(void) {
  int N, i;
  float prom;

  printf("Ingresa la cantidad de numeros a promediar: ");
  scanf("%i", &N);

  // Pedir memoria dinámica para almacenar los números
  int *num = (int *)malloc(N * sizeof(int));

  // Leer los números del usuario y almacenarlos en el arreglo
  printf("Ingresa %i numeros: \n", N);
  for (i = 0; i < N; i++) {
    scanf("%i", &*(num + i));
  }

  // Calcular el promedio
  for (i = 0; i < N; i++) {
    prom += *(num + i);
  }

  printf("El promedio es de: %.2f\n", prom /= N);

  // Liberar la memoria dinámica
  free(num);

  // Imprimir la cantidad de memoria utilizada
  printf("Cantidad de memoria utlizada: %lu bytes\n", N * sizeof(int));

  return 0;
}