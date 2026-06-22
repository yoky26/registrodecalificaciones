#include "Calificacion.h"
#include <string>
#include <vector>

Calificacion::Calificacion() : nota(0.0f) {}

Calificacion::Calificacion(Estudiante est, Profesor prof, Materia mat, float nota)
    : estudiante(est), profesor(prof), materia(mat), nota(nota) {}

void Calificacion::setEstudiante(Estudiante est) {
    estudiante = est;
}

void Calificacion::setProfesor(Profesor prof) {
    profesor = prof;
}

void Calificacion::setMateria(Materia mat) {
    materia = mat;
}

void Calificacion::setNota(float nota) {
    this->nota = nota;
}

Estudiante Calificacion::getEstudiante() const {
    return estudiante;
}

Profesor Calificacion::getProfesor() const {
    return profesor;
}

Materia Calificacion::getMateria() const {
    return materia;
}

float Calificacion::getNota() const {
    return nota;
}

std::string Calificacion::serializar() const {
    return estudiante.getMatricula() + "|" +
           profesor.getCodigoProfesor() + "|" +
           materia.getCodigoMateria() + "|" +
           std::to_string(nota);
}

Calificacion Calificacion::deserializar(const std::string& linea, const std::vector<Estudiante>& listaEst, const std::vector<Profesor>& listaProf, const std::vector<Materia>& listaMat) {
    size_t pos1 = linea.find("|");
    size_t pos2 = linea.find("|", pos1 + 1);
    size_t pos3 = linea.find("|", pos2 + 1);

    std::string matEst = linea.substr(0, pos1);
    std::string codProf = linea.substr(pos1 + 1, pos2 - pos1 - 1);
    std::string codMat = linea.substr(pos2 + 1, pos3 - pos2 - 1);
    float nota = std::stof(linea.substr(pos3 + 1));

    Estudiante e;
    for (const auto& obj : listaEst)
        if (obj.getMatricula() == matEst) { e = obj; break; }

    Profesor p;
    for (const auto& obj : listaProf)
        if (obj.getCodigoProfesor() == codProf) { p = obj; break; }

    Materia m;
    for (const auto& obj : listaMat)
        if (obj.getCodigoMateria() == codMat) { m = obj; break; }

    return Calificacion(e, p, m, nota);
}
