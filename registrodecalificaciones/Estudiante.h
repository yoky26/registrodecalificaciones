#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombreCompleto;
    std::string matricula;
    std::string sesion;

public:
    Estudiante();
    Estudiante(std::string nombre, std::string matricula, std::string sesion);

    void setNombreCompleto(std::string nombre);
    void setMatricula(std::string matricula);
    void setSesion(std::string sesion);

    std::string getNombreCompleto() const;
    std::string getMatricula() const;
    std::string getSesion() const;

    std::string serializar() const;
    static Estudiante deserializar(const std::string& linea);
};

#endif
