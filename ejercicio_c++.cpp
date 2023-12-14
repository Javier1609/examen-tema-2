#include <iostream>
#include <string>
#include <vector>


struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado; // "asistió", "falta", "tardanza"
};


struct Materia {
    std::string nombre;
    float calificacion;
};


struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    std::vector<Materia> materias;
    std::vector<Asistencia> asistencias;


    void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {
        asistencias.push_back({fecha, materia, estado});
    }


    void mostrarInformacion() const {
        std::cout << "Informacion del Estudiante:" << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
        std::cout << "Edad: " << edad << std::endl;
        std::cout << "Promedio: " << promedio << std::endl;

        std::cout << "\nMaterias Inscritas:" << std::endl;
        for (const auto& materia : materias) {
            std::cout << "- " << materia.nombre << " (Calificacion: " << materia.calificacion << ")" << std::endl;
        }

        std::cout << "\nAsistencias Registradas:" << std::endl;
        for (const auto& asistencia : asistencias) {
            std::cout << "- Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << std::endl;
        }
    }
};

int main() {
    Estudiante estudiante1 = {"Juan", 20, 8.5};


    estudiante1.materias.push_back({"Matematicas", 9.0});
    estudiante1.materias.push_back({"Historia", 8.0});


    estudiante1.registrarAsistencia("2023-01-01", "Matematicas", "asistio");
    estudiante1.registrarAsistencia("2023-01-02", "Historia", "falta");


    estudiante1.mostrarInformacion();

    return 0;
}
