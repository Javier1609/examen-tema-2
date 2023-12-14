#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Asistencia {
    char fecha[20];
    char materia[50];
    char estado[20];
};


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
    struct Asistencia* asistencias;
    int numAsistencias;
    int capacidadAsistencias;
};


void inicializarEstudiante(struct Estudiante* estudiante, const char* nombre, int edad, float promedio, int capacidadMaterias, int capacidadAsistencias) {
    snprintf(estudiante->nombre, sizeof(estudiante->nombre), "%s", nombre);
    estudiante->edad = edad;
    estudiante->promedio = promedio;
    estudiante->materias = (struct Materia*)malloc(capacidadMaterias * sizeof(struct Materia));
    estudiante->numMaterias = 0;
    estudiante->capacidadMaterias = capacidadMaterias;
    estudiante->asistencias = (struct Asistencia*)malloc(capacidadAsistencias * sizeof(struct Asistencia));
    estudiante->numAsistencias = 0;
    estudiante->capacidadAsistencias = capacidadAsistencias;
}


void liberarEstudiante(struct Estudiante* estudiante) {
    free(estudiante->materias);
    free(estudiante->asistencias);
}


void agregarMateria(struct Estudiante* estudiante, const char* nombre, float calificacion) {
    if (estudiante->numMaterias < estudiante->capacidadMaterias) {
        snprintf(estudiante->materias[estudiante->numMaterias].nombre, sizeof(estudiante->materias[0].nombre), "%s", nombre);
        estudiante->materias[estudiante->numMaterias].calificacion = calificacion;
        estudiante->numMaterias++;
    }
}


void registrarAsistencia(struct Estudiante* estudiante, const char* fecha, const char* materia, const char* estado) {
    if (estudiante->numAsistencias < estudiante->capacidadAsistencias) {
        snprintf(estudiante->asistencias[estudiante->numAsistencias].fecha, sizeof(estudiante->asistencias[0].fecha), "%s", fecha);
        snprintf(estudiante->asistencias[estudiante->numAsistencias].materia, sizeof(estudiante->asistencias[0].materia), "%s", materia);
        snprintf(estudiante->asistencias[estudiante->numAsistencias].estado, sizeof(estudiante->asistencias[0].estado), "%s", estado);
        estudiante->numAsistencias++;
    }
}


void mostrarInformacion(const struct Estudiante* estudiante) {
    printf("Información del Estudiante:\n");
    printf("Nombre: %s\n", estudiante->nombre);
    printf("Edad: %d\n", estudiante->edad);
    printf("Promedio: %.2f\n", estudiante->promedio);

    printf("\nMaterias Inscritas:\n");
    for (int i = 0; i < estudiante->numMaterias; i++) {
        printf("- %s (Calificacion: %.2f)\n", estudiante->materias[i].nombre, estudiante->materias[i].calificacion);
    }

    printf("\nAsistencias Registradas:\n");
    for (int i = 0; i < estudiante->numAsistencias; i++) {
        printf("- Fecha: %s, Materia: %s, Estado: %s\n", estudiante->asistencias[i].fecha, estudiante->asistencias[i].materia, estudiante->asistencias[i].estado);
    }
}

int main() {
    struct Estudiante estudiante1;
    inicializarEstudiante(&estudiante1, "Javier", 18, 8.5, 10, 10);


    agregarMateria(&estudiante1, "Matematicas", 9.0);
    agregarMateria(&estudiante1, "Historia", 8.0);


    registrarAsistencia(&estudiante1, "2023-01-01", "Matematicas", "asistio");
    registrarAsistencia(&estudiante1, "2023-01-02", "Historia", "falta");


    mostrarInformacion(&estudiante1);


    liberarEstudiante(&estudiante1);

    return 0;
}
