#include <iostream>
#include <string>
using namespace std;

struct Materia {
    string nombre;
    float calificacion;
};


struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;
    cout << "Edad: " << estudiante.edad << endl;
    cout << "Promedio: " << estudiante.promedio << endl;
}

int main () {
    Estudiante estudiante1;


    estudiante1.nombre = "Javier";
    estudiante1.edad = 18;
    estudiante1.promedio = 9.34;

    mostrarEstudiante(estudiante1);
    }