#ifndef PROFESOR_H
#define PROFESOR_H

#include <string>

class Profesor {
private:
    std::string nombreCompleto;
    std::string codigoProfesor;

public:
    Profesor();
    Profesor(std::string nombre, std::string codigo);

    void setNombreCompleto(std::string nombre);
    void setCodigoProfesor(std::string codigo);

    std::string getNombreCompleto() const;
    std::string getCodigoProfesor() const;

    std::string serializar() const;
    static Profesor deserializar(const std::string& linea);
};

#endif
