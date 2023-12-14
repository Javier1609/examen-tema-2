#include <iostream>
#include <string>
using namespace std;



struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

void mostrarEstudiante(const Estudiante& estudiante) {
    cout << "Nombre: " << estudiante.nombre << endl;

}