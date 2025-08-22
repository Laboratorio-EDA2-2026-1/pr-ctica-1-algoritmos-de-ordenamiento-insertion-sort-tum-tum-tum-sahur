#include <stdio.h>
#include <stdlib.h>

/*
 * EJERCICIO:
 * Se quiere definir un programa que, dada una matriz cuadrada con valores enteros,
 * devuelva una permutación de los valores de modo que:
 *
 * 1. Cada renglón esté ordenado de menor a mayor.
 * 2. Todos los elementos del segundo renglón (de arriba hacia abajo)
 *    sean mayores que los del primero, los del tercero mayores que los del segundo, etc.
 *
 * Regla importante:
 * - Cuando se ordenan los elementos de un renglón, por cada elemento de dicho renglón,
 *   se mueven también todos los elementos que se encuentran por debajo en la misma columna.
 *
 * INSTRUCCIONES:
 * - Completa la función sort_matrix() que debe modificar la matriz en su lugar.
 * - Puedes escribir funciones auxiliares si lo deseas.
 * - NO cambies la firma de sort_matrix().
 */

void sort_matrix(int **matrix, int n) {
    // TODO: Implementa aquí el algoritmo.
    // Necesitarás el método de inserción,
    // pero recuerda aplicar la regla de mover toda la columna.
    int key;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            key = matrix[i][j];
            int k = j-1;
            while (k >= 0 && matrix[i][k] > key) {
                for (int m = i; m < n; m++) {
                    matrix[m][k+1] = matrix[m][k];
                }
                k--;
            }
            for (int m = i; m < n; m++) {
                if(m == i){
                    matrix[i][k+1] = key;
                }else{
                    matrix[m][k+1] = matrix[m][j];
                }
            }
        }
    }
}

    int main() {
        int n = 3;
        // Reserva dinámica de la matriz
        int **matrix = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *)malloc(n * sizeof(int));
        }
        
        // Ejemplo de entrada
        int ejemplo[3][3] = {
            {4, 7, 2},
            {9, 5, 6},
            {8, 1, 3}
        };
        
        // Copiar ejemplo a la matriz dinámica
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = ejemplo[i][j];
            }
        }
        
        printf("Matriz original:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        
        // Llamada a la función que deben completar
        sort_matrix(matrix, n);
        
        printf("\nMatriz ordenada:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        
        // Liberar memoria
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
        
        return 0;
    }
