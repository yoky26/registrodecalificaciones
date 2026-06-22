#include "Estudiante.h"

Estudiante::Estudiante() : nombreCompleto(""), matricula(""), sesion("") {}

Estudiante::Estudiante(std::string nombre, std::string matricula, std::string sesion)
    : nombreCompleto(nombre), matricula(matricula), sesion(sesion) {}

void Estudiante::setNombreCompleto(std::string nombre) {
    nombreCompleto = nombre;
}

void Estudiante::setMatricula(std::string matricula) {
    this->matricula = matricula;
}

void Estudiante::setSesion(std::string sesion) {
    this->sesion = sesion;
}

std::string Estudiante::getNombreCompleto() const {
    return nombreCompleto;
}

std::string Estudiante::getMatricula() const {
    return matricula;
}

std::string Estudiante::getSesion() const {
    return sesion;
}

std::string Estudiante::serializar() const {
    return nombreCompleto + "|" + matricula + "|" + sesion;
}

Estudiante Estudiante::deserializar(const std::string& linea) {
    size_t pos1 = linea.find("|");
    size_t pos2 = linea.find("|", pos1 + 1);

    std::string nombre = linea.substr(0, pos1);
    std::string mat = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    std::string ses = linea.substr(pos2 + 1);

    return Estudiante(nombre, mat, ses);
}
