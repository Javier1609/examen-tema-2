#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;

class FechaInvalidaException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Formato de fecha incorrecto.";
    }
};


class MateriaNoRegistradaException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Materia no registrada.";
    }
};


struct Asistencia {
    std::string fecha;
    std::string materia;
    std::string estado;
};


struct Materia {
    std::string nombre;
    float calificacion;
};


struct Estudiante {
    std::string nombre;
    int edad;
    float promedio;
    vector<Materia> materias;
    vector<Asistencia> asistencias;


    void registrarAsistencia(const std::string& fecha, const std::string& materia, const std::string& estado) {

        if (fecha.size() != 10 || fecha[4] != '-' || fecha[7] != '-') {
            throw FechaInvalidaException();
        }


        if (std::find_if(materias.begin(), materias.end(),
                         [&](const Materia& mat) { return mat.nombre == materia; }) == materias.end()) {
            throw MateriaNoRegistradaException();
        }


        asistencias.push_back({fecha, materia, estado});
    }


    void mostrarInformacion() const {
        cout << "Informacion del Estudiante:" << std::endl;
        cout << "Nombre: " << nombre << std::endl;
       cout << "Edad: " << edad << std::endl;
       cout << "Promedio: " << promedio << std::endl;

        cout << "\nMaterias Inscritas:" << std::endl;
        for (const auto& materia : materias) {
            std::cout << "- " << materia.nombre << " (Calificacion: " << materia.calificacion << ")" << std::endl;
        }

       cout << "\nAsistencias Registradas:" << std::endl;
        for (const auto& asistencia : asistencias) {
            cout << "- Fecha: " << asistencia.fecha << ", Materia: " << asistencia.materia << ", Estado: " << asistencia.estado << std::endl;
        }
    }
};

int main() {
    try {
        Estudiante estudiante1 = {"Javier", 18, 9.1};


        estudiante1.materias.push_back({"Matematicas", 9.0});
        estudiante1.materias.push_back({"Historia", 8.0});


        estudiante1.registrarAsistencia("2023-01-01", "Matematicas", "asistio");


        estudiante1.registrarAsistencia("2023-01-02", "Geografia", "asistio");


        estudiante1.mostrarInformacion();
    } catch (const std::exception& e) {
        std::cerr << "Excepcion: " << e.what() << std::endl;
    }

    return 0;
}
