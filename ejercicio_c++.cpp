#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Materia {
    std::string nombre;
    float calificacion;
};


struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
};


void agregarMateria(Estudiante& estudiante, const std::string& nombre, float calificacion) {
    estudiante.materias.push_back({nombre, calificacion});
}


void eliminarMateria(Estudiante& estudiante, const string& nombre) {
    estudiante.materias.erase(
            std::remove_if(estudiante.materias.begin(), estudiante.materias.end(),
                           [nombre](const Materia& materia) { return materia.nombre == nombre; }),
            estudiante.materias.end());
}


void mostrarMaterias(const Estudiante& estudiante) {
    cout << "Materias Inscritas:" << std::endl;
    for (const auto& materia : estudiante.materias) {
        std::cout << "- " << materia.nombre << " (Calificacion: " << materia.calificacion << ")" << std::endl;
    }
}

int main() {
    Estudiante estudiante1 = {"Juan", 20, 8.5};


    agregarMateria(estudiante1, "Matematicas", 9.0);
    agregarMateria(estudiante1, "Historia", 8.0);


    mostrarMaterias(estudiante1);


    eliminarMateria(estudiante1, "Historia");


    mostrarMaterias(estudiante1);

    return 0;
}
