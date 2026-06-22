#include "Profesor.h"

Profesor::Profesor() : nombreCompleto(""), codigoProfesor("") {}

Profesor::Profesor(std::string nombre, std::string codigo)
    : nombreCompleto(nombre), codigoProfesor(codigo) {}

void Profesor::setNombreCompleto(std::string nombre) {
    nombreCompleto = nombre;
}

void Profesor::setCodigoProfesor(std::string codigo) {
    codigoProfesor = codigo;
}

std::string Profesor::getNombreCompleto() const {
    return nombreCompleto;
}

std::string Profesor::getCodigoProfesor() const {
    return codigoProfesor;
}

std::string Profesor::serializar() const {
    return nombreCompleto + "|" + codigoProfesor;
}

Profesor Profesor::deserializar(const std::string& linea) {
    size_t pos = linea.find("|");
    std::string nombre = linea.substr(0, pos);
    std::string cod = linea.substr(pos + 1);
    return Profesor(nombre, cod);
}
