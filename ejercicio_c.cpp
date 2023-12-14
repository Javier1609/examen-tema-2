#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Materia {
    char nombre[50];
    float calificacion;
};


struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
    struct Materia* materias;
    int numMaterias;
    int capacidadMaterias;
};


void inicializarEstudiante(struct Estudiante* estudiante, const char* nombre, int edad, float promedio, int capacidadMaterias) {
    snprintf(estudiante->nombre, sizeof(estudiante->nombre), "%s", nombre);
    estudiante->edad = edad;
    estudiante->promedio = promedio;
    estudiante->materias = (struct Materia*)malloc(capacidadMaterias * sizeof(struct Materia));
    estudiante->numMaterias = 0;
    estudiante->capacidadMaterias = capacidadMaterias;
}


void liberarEstudiante(struct Estudiante* estudiante) {
    free(estudiante->materias);
}


void agregarMateria(struct Estudiante* estudiante, const char* nombre, float calificacion) {
    if (estudiante->numMaterias < estudiante->capacidadMaterias) {
        snprintf(estudiante->materias[estudiante->numMaterias].nombre, sizeof(estudiante->materias[0].nombre), "%s", nombre);
        estudiante->materias[estudiante->numMaterias].calificacion = calificacion;
        estudiante->numMaterias++;
    }
}


void eliminarMateria(struct Estudiante* estudiante, const char* nombre) {
    for (int i = 0; i < estudiante->numMaterias; i++) {
        if (strcmp(estudiante->materias[i].nombre, nombre) == 0) {

            for (int j = i; j < estudiante->numMaterias - 1; j++) {
                estudiante->materias[j] = estudiante->materias[j + 1];
            }
            estudiante->numMaterias--;
            break;
        }
    }
}

// Función para mostrar las materias del estudiante
void mostrarMaterias(const struct Estudiante* estudiante) {
    printf("Materias Inscritas:\n");
    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("- %s (Calificacion: %.2f)\n", estudiante->materias[i].nombre, estudiante->materias[i].calificacion);
    }
}

int main() {
    struct Estudiante estudiante1;
    inicializarEstudiante(&estudiante1, "Javier", 18, 9.1, 9);

    agregarMateria(&estudiante1, "Matematicas", 9.6);
    agregarMateria(&estudiante1, "Historia", 8.5);

    mostrarMaterias(&estudiante1);

    eliminarMateria(&estudiante1, "Historia");

    mostrarMaterias(&estudiante1);

    liberarEstudiante(&estudiante1);

    return 0;
}
