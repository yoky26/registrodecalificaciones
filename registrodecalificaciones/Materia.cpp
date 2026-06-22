#include "Materia.h"

Materia::Materia() : nombreMateria(""), codigoMateria(""), creditos(0) {}

Materia::Materia(std::string nombre, std::string codigo, int creditos)
    : nombreMateria(nombre), codigoMateria(codigo), creditos(creditos) {}

void Materia::setNombreMateria(std::string nombre) {
    nombreMateria = nombre;
}

void Materia::setCodigoMateria(std::string codigo) {
    codigoMateria = codigo;
}

void Materia::setCreditos(int creditos) {
    this->creditos = creditos;
}

std::string Materia::getNombreMateria() const {
    return nombreMateria;
}

std::string Materia::getCodigoMateria() const {
    return codigoMateria;
}

int Materia::getCreditos() const {
    return creditos;
}

std::string Materia::serializar() const {
    return nombreMateria + "|" + codigoMateria + "|" + std::to_string(creditos);
}

Materia Materia::deserializar(const std::string& linea) {
    size_t pos1 = linea.find("|");
    size_t pos2 = linea.find("|", pos1 + 1);

    std::string nombre = linea.substr(0, pos1);
    std::string cod = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    int cred = std::stoi(linea.substr(pos2 + 1));

    return Materia(nombre, cod, cred);
}
