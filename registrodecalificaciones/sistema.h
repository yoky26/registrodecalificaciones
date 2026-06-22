#ifndef SISTEMA_H
#define SISTEMA_H

#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Calificacion.h"
#include <vector>
#include <string>

class Sistema {
private:
    std::vector<Estudiante> listaEstudiantes;
    std::vector<Profesor> listaProfesores;
    std::vector<Materia> listaMaterias;
    std::vector<Calificacion> listaCalificaciones;

    void cargarDatos();
    void guardarDatos() const;

    std::string leerTexto(const std::string& msj) const;
    std::string leerMatricula() const;
    std::string leerCodigoProfesor() const;
    std::string leerCodigoMateria() const;
    std::string leerSesion() const;
    float leerNota() const;
    int leerOpcion(int min, int max) const;

    void mostrarEstudiantes() const;
    void mostrarProfesores() const;
    void mostrarMaterias() const;
    void mostrarCalificaciones() const;

public:
    Sistema();
    void ejecutar();
};

#endif
