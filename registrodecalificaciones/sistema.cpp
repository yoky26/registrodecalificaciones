#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <limits>

Sistema::Sistema() {
    cargarDatos();
}

void Sistema::cargarDatos() {
    std::ifstream fe("estudiantes.txt");
    if (fe.is_open()) {
        std::string linea;
        while (std::getline(fe, linea))
            if (!linea.empty()) listaEstudiantes.push_back(Estudiante::deserializar(linea));
        fe.close();
    }

    std::ifstream fp("profesores.txt");
    if (fp.is_open()) {
        std::string linea;
        while (std::getline(fp, linea))
            if (!linea.empty()) listaProfesores.push_back(Profesor::deserializar(linea));
        fp.close();
    }

    std::ifstream fm("materias.txt");
    if (fm.is_open()) {
        std::string linea;
        while (std::getline(fm, linea))
            if (!linea.empty()) listaMaterias.push_back(Materia::deserializar(linea));
        fm.close();
    }

    std::ifstream fc("calificaciones.txt");
    if (fc.is_open()) {
        std::string linea;
        while (std::getline(fc, linea))
            if (!linea.empty()) listaCalificaciones.push_back(Calificacion::deserializar(linea, listaEstudiantes, listaProfesores, listaMaterias));
        fc.close();
    }
}

void Sistema::guardarDatos() const {
    std::ofstream fe("estudiantes.txt");
    for (const auto& e : listaEstudiantes) fe << e.serializar() << "\n";
    fe.close();

    std::ofstream fp("profesores.txt");
    for (const auto& p : listaProfesores) fp << p.serializar() << "\n";
    fp.close();

    std::ofstream fm("materias.txt");
    for (const auto& m : listaMaterias) fm << m.serializar() << "\n";
    fm.close();

    std::ofstream fc("calificaciones.txt");
    for (const auto& c : listaCalificaciones) fc << c.serializar() << "\n";
    fc.close();
}

std::string Sistema::leerTexto(const std::string& msj) const {
    std::string txt;
    do {
        std::cout << msj;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, txt);
        if (txt.empty()) std::cout << "No puede estar vacío.\n";
    } while (txt.empty());
    return txt;
}

std::string Sistema::leerMatricula() const {
    std::string mat;
    do {
        std::cout << "Matrícula (ej: 2024-0001): ";
        std::cin >> mat;
        if (mat.size() != 9 || mat[4] != '-')
            std::cout << "Formato incorrecto.\n";
    } while (mat.size() != 9 || mat[4] != '-');
    return mat;
}

std::string Sistema::leerCodigoProfesor() const {
    std::string cod;
    do {
        std::cout << "Código profesor (3 letras + 3 números): ";
        std::cin >> cod;
        if (cod.size() != 6 || !std::isalpha(cod[0]) || !std::isalpha(cod[1]) || !std::isalpha(cod[2]))
            std::cout << "Formato incorrecto.\n";
    } while (cod.size() != 6 || !std::isalpha(cod[0]) || !std::isalpha(cod[1]) || !std::isalpha(cod[2]));
    return cod;
}

std::string Sistema::leerCodigoMateria() const {
    std::string cod;
    do {
        std::cout << "Código materia (ej: MAT101): ";
        std::cin >> cod;
        if (cod.size() != 6)
            std::cout << "Formato incorrecto.\n";
    } while (cod.size() != 6);
    return cod;
}

std::string Sistema::leerSesion() const {
    std::string ses;
    do {
        std::cout << "Sesión (ej: 4-1): ";
        std::cin >> ses;
        if (ses.empty()) std::cout << "No puede estar vacía.\n";
    } while (ses.empty());
    return ses;
}

float Sistema::leerNota() const {
    float n;
    do {
        std::cout << "Nota (0 - 100): ";
        std::cin >> n;
        if (std::cin.fail() || n < 0 || n > 100) {
            std::cout << "Nota inválida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    } while (true);
    return n;
}

int Sistema::leerOpcion(int min, int max) const {
    int op;
    do {
        std::cout << "\nOpción: ";
        std::cin >> op;
        if (std::cin.fail() || op < min || op > max) {
            std::cout << "Opción no válida.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else break;
    } while (true);
    return op;
}

void Sistema::mostrarEstudiantes() const {
    if (listaEstudiantes.empty()) { std::cout << "Sin registros.\n"; return; }
    std::cout << "\n" << std::setw(25) << std::left << "Nombre" << std::setw(15) << "Matrícula" << std::setw(10) << "Sesión\n";
    std::cout << std::string(50, '-') << "\n";
    for (const auto& e : listaEstudiantes)
        std::cout << std::setw(25) << e.getNombreCompleto() << std::setw(15) << e.getMatricula() << std::setw(10) << e.getSesion() << "\n";
}

void Sistema::mostrarProfesores() const {
    if (listaProfesores.empty()) { std::cout << "Sin registros.\n"; return; }
    std::cout << "\n" << std::setw(25) << std::left << "Nombre" << std::setw(15) << "Código\n";
    std::cout << std::string(40, '-') << "\n";
    for (const auto& p : listaProfesores)
        std::cout << std::setw(25) << p.getNombreCompleto() << std::setw(15) << p.getCodigoProfesor() << "\n";
}

void Sistema::mostrarMaterias() const {
    if (listaMaterias.empty()) { std::cout << "Sin registros.\n"; return; }
    std::cout << "\n" << std::setw(25) << std::left << "Materia" << std::setw(15) << "Código" << std::setw(10) << "Créditos\n";
    std::cout << std::string(50, '-') << "\n";
    for (const auto& m : listaMaterias)
        std::cout << std::setw(25) << m.getNombreMateria() << std::setw(15) << m.getCodigoMateria() << std::setw(10) << m.getCreditos() << "\n";
}

void Sistema::mostrarCalificaciones() const {
    if (listaCalificaciones.empty()) { std::cout << "Sin registros.\n"; return; }
    std::cout << "\n" << std::setw(20) << std::left << "Estudiante" << std::setw(20) << "Profesor" << std::setw(20) << "Materia" << std::setw(10) << "Nota\n";
    std::cout << std::string(70, '-') << "\n";
    for (const auto& c : listaCalificaciones)
        std::cout << std::setw(20) << c.getEstudiante().getNombreCompleto()
                  << std::setw(20) << c.getProfesor().getNombreCompleto()
                  << std::setw(20) << c.getMateria().getNombreMateria()
                  << std::setw(10) << std::fixed << std::setprecision(2) << c.getNota() << "\n";
}

void Sistema::ejecutar() {
    int op;
    do {
        std::cout << "\n===== SISTEMA DE REGISTRO DE CALIFICACIONES =====\n";
        std::cout << "1. Registrar estudiante\n";
        std::cout << "2. Registrar profesor\n";
        std::cout << "3. Registrar materia\n";
        std::cout << "4. Registrar calificación\n";
        std::cout << "5. Ver estudiantes\n";
        std::cout << "6. Ver profesores\n";
        std::cout << "7. Ver materias\n";
        std::cout << "8. Ver calificaciones\n";
        std::cout << "9. Salir\n";

        op = leerOpcion(1,9);

        if (op == 1) {
            std::string n = leerTexto("Nombre completo: ");
            std::string m = leerMatricula();
            std::string s = leerSesion();
            listaEstudiantes.emplace_back(n, m, s);
            std::cout << "Estudiante registrado.\n";
        }
        else if (op == 2) {
            std::string n = leerTexto("Nombre completo: ");
            std::string c = leerCodigoProfesor();
            listaProfesores.emplace_back(n, c);
            std::cout << "Profesor registrado.\n";
        }
        else if (op == 3) {
            std::string n = leerTexto("Nombre materia: ");
            std::string c = leerCodigoMateria();
            int cr;
            do {
                std::cout << "Créditos: ";
                std::cin >> cr;
                if (std::cin.fail() || cr <= 0) {
                    std::cout << "Valor inválido.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                } else break;
            } while(true);
            listaMaterias.emplace_back(n, c, cr);
            std::cout << "Materia registrada.\n";
        }
        else if (op == 4) {
            if (listaEstudiantes.empty() || listaProfesores.empty() || listaMaterias.empty()) {
                std::cout << "Faltan datos para registrar.\n";
                continue;
            }
            std::cout << "\n--- Estudiantes ---\n";
            for (size_t i=0; i<listaEstudiantes.size(); i++)
                std::cout << i+1 << ". " << listaEstudiantes[i].getNombreCompleto() << "\n";
            int eSel; std::cin >> eSel;

            std::cout << "\n--- Profesores ---\n";
            for (size_t i=0; i<listaProfesores.size(); i++)
                std::cout << i+1 << ". " << listaProfesores[i].getNombreCompleto() << "\n";
            int pSel; std::cin >> pSel;

            std::cout << "\n--- Materias ---\n";
            for (size_t i=0; i<listaMaterias.size(); i++)
                std::cout << i+1 << ". " << listaMaterias[i].getNombreMateria() << "\n";
            int mSel; std::cin >> mSel;

            float nota = leerNota();
            listaCalificaciones.emplace_back(listaEstudiantes[eSel-1], listaProfesores[pSel-1], listaMaterias[mSel-1], nota);
            std::cout << "Calificación registrada.\n";
        }
        else if (op == 5) mostrarEstudiantes();
        else if (op == 6) mostrarProfesores();
        else if (op == 7) mostrarMaterias();
        else if (op == 8) mostrarCalificaciones();

    } while (op != 9);

    guardarDatos();
    std::cout << "Datos guardados. Programa finalizado.\n";
}
