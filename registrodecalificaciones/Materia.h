#ifndef MATERIA_H
#define MATERIA_H

#include <string>

class Materia {
private:
    std::string nombreMateria;
    std::string codigoMateria;
    int creditos;

public:
    Materia();
    Materia(std::string nombre, std::string codigo, int creditos);

    void setNombreMateria(std::string nombre);
    void setCodigoMateria(std::string codigo);
    void setCreditos(int creditos);

    std::string getNombreMateria() const;
    std::string getCodigoMateria() const;
    int getCreditos() const;

    std::string serializar() const;
    static Materia deserializar(const std::string& linea);
};

#endif
