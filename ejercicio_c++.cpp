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
    vector<Materia> materias;
}

void agregarMateria(Estudiante& estudiante, const std::string& nombre, float calificacion) {
    estudiante.materias.push_back({nombre, calificacion});
}

void eliminarMateria(Estudiante& estudiante, const std::string& nombre) {
    estudiante.materias.erase(
            std::remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                           [nombre](const Materia& materia) { return materia.nombre == nombre; }),
            estudiante.materias.end());
}

void mostrarMaterias(const Estudiante& estudiante) {
    std::cout << "Materias Inscritas:" << std::endl;
    for (const auto& materia : estudiante.materias) {
        std::cout << "- " << materia.nombre << " (Calificación: " << materia.calificacion << ")" << std::endl;
    }
}


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