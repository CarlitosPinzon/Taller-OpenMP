/**********************************************************
*    Pontificia Universidad Javeriana
*    Fecha: 22 de mayo 2025
*    Autor: Carlos Santiago Pinzón Caicedo
*    Materia: Sistemas operativos
*    Tópico: Uso de OMP OpenMP
*    Descripción: Implementación de funciones de utilidad para
*                 paralelización con OpenMP y programa principal.
*
*----------------------------------------------------------*/

#include "omplab_Pinzon.h"

// Función para validar argumentos de entrada
void validarArgumentos(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Entrada por consola \n\t &./ejecutable NumHilos");
        exit(0); // Termina el programa si no hay argumento
    }
}

// Función para mostrar información de hilos
void mostrarInfoHilos(int maxHilos, int numHilos) {
    omp_set_num_threads(numHilos);
    #pragma omp parallel
    printf("MaxHilos %d \t Equipo de hilos impuestos = %d\n", maxHilos, omp_get_num_threads());
}

// Función para realizar el cálculo paralelo
void realizarCalculoParalelo(int hilos, int *a, int *b) {
    const int N = 1000; // Tamaño del bucle
    int i;

    omp_set_num_threads(hilos);
    #pragma omp parallel for private(a, i)
    for (i = 0; i < N; i++) {
        *b = *a + i; // Asignación a 'b' (puede causar condiciones de carrera)
    }
}

// Función principal
int main(int argc, char *argv[]) {
    // Verifica si se pasó el número de hilos como argumento
    validarArgumentos(argc, argv);

    // Convierte el argumento de entrada en un entero para el número de hilos
    int hilos = (int) atoi(argv[1]);
    int i; // Variable para el bucle
    int a = 50; // Variable inicializada con valor 50
    int b = 0; // Variable compartida entre hilos
    int maxHilos = omp_get_max_threads(); // Obtiene el número máximo de hilos disponibles

    // Mostrar información de hilos
    mostrarInfoHilos(maxHilos, hilos);

    // Realizar cálculo paralelo
    realizarCalculoParalelo(hilos, &a, &b);

    // Imprime los valores finales de 'a' y 'b'
    printf("El valor de a = %d \t el valor de b = %d\n", a, b);

    return 0;
}

/* Conclusión:
 * Este código usa OpenMP para paralelizar un bucle que realiza cálculos simples,
 * pero tiene un problema: la variable 'b' es compartida y no está protegida contra
 * accesos concurrentes, lo que puede generar resultados inconsistentes debido a
 * condiciones de carrera. Para corregirlo, se debería usar sincronización (ej. #pragma omp critical)
 * o hacer 'b' privada y combinar resultados. Es un ejemplo útil para aprender OpenMP,
 * pero necesita ajustes para ser correcto en un entorno paralelo.
 */
