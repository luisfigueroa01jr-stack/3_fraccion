#ifndef FRACCION_H
#define FRACCION_H

#include <ostream>

class Fraccion {
private:
    int numerador;
    int denominador;

    // Deja la fraccion en su minima expresion y con el signo en el numerador
    void simplificar();
    static long long mcd(long long a, long long b);

public:
    Fraccion(int numerador = 0, int denominador = 1);

    int getNumerador() const;
    int getDenominador() const;

    // Sobrecarga de operadores
    Fraccion operator+(const Fraccion& otra) const;
    Fraccion operator-(const Fraccion& otra) const;
    Fraccion operator*(const Fraccion& otra) const;
    bool operator==(const Fraccion& otra) const;

    // Permite imprimir con std::cout << fraccion
    friend std::ostream& operator<<(std::ostream& os, const Fraccion& f);
};

#endif
