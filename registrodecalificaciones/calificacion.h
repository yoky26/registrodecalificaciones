#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include <string>
#include <vector>

class Calificacion {
private:
    Estudiante estudiante;
    Profesor profesor;
    Materia materia;
    float nota;

public:
    Calificacion();
    Calificacion(Estudiante est, Profesor prof, Materia mat, float nota);

    void setEstudiante(Estudiante est);
    void setProfesor(Profesor prof);
    void setMateria(Materia mat);
    void setNota(float nota);

    Estudiante getEstudiante() const;
    Profesor getProfesor() const;
    Materia getMateria() const;
    float getNota() const;

    std::string serializar() const;
    static Calificacion deserializar(const std::string& linea,
                                    const std::vector<Estudiante>& listaEst,
                                    const std::vector<Profesor>& listaProf,
                                    const std::vector<Materia>& listaMat);
};

#endif
