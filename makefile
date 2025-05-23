# Makefile para compilar el programa OpenMP
# Pontificia Universidad Javeriana
# Fecha: 22 de mayo 2025
# Autor: Carlos Santiago Pinzón Caicedo
# Materia: Sistemas operativos
# Tópico: Uso de OMP OpenMP

# Compilador y banderas
CC = gcc
CFLAGS = -fopenmp -Wall
TARGET = omplab_Pinzon
SOURCES = omplab_Pinzon.c
OBJECTS = $(SOURCES:.c=.o)

# Regla principal
all: $(TARGET)

# Regla para generar el ejecutable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(CFLAGS)

# Regla para compilar los archivos fuente
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Regla para limpiar archivos generados
clean:
	rm -f $(OBJECTS) $(TARGET)

# Regla para ejecutar el programa (ejemplo con 4 hilos)
run: $(TARGET)
	./$(TARGET) 4

.PHONY: all clean run
