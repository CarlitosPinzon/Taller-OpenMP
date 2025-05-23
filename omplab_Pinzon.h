/**********************************************************
*    Pontificia Universidad Javeriana
*    Fecha: 22 de mayo 2025
*    Autor: Carlos Santiago Pinzón Caicedo
*    Materia: Sistemas operativos
*    Tópico: Uso de OMP OpenMP
*    Descripción: Archivo de cabecera para funciones de utilidad
*                 OpenMP para paralelización.
*
*----------------------------------------------------------*/

#ifndef OMPLAB_PINZON_H
#define OMPLAB_PINZON_H

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Prototipos de funciones
void validarArgumentos(int argc, char *argv[]);
void mostrarInfoHilos(int maxHilos, int numHilos);
void realizarCalculoParalelo(int hilos, int *a, int *b);

#endif // OMPLAB_PINZON_H
