#include "Fraccion.h"
#include <stdexcept>

Fraccion::Fraccion(int numerador, int denominador)
    : numerador(numerador), denominador(denominador) {
    if (denominador == 0) {
        throw std::invalid_argument("El denominador no puede ser 0");
    }
    simplificar();
}

long long Fraccion::mcd(long long a, long long b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Fraccion::simplificar() {
    if (denominador < 0) {
        numerador = -numerador;
        denominador = -denominador;
    }
    long long divisor = mcd(numerador, denominador);
    if (divisor != 0) {
        numerador /= divisor;
        denominador /= divisor;
    }
}

int Fraccion::getNumerador() const { return numerador; }
int Fraccion::getDenominador() const { return denominador; }

// a/b + c/d = (a*d + c*b) / (b*d)
// Se calcula en long long y se simplifica antes de volver a int para evitar desbordamiento
Fraccion Fraccion::operator+(const Fraccion& otra) const {
    long long num = static_cast<long long>(numerador) * otra.denominador
                  + static_cast<long long>(otra.numerador) * denominador;
    long long den = static_cast<long long>(denominador) * otra.denominador;
    long long divisor = mcd(num, den);
    return Fraccion(static_cast<int>(num / divisor), static_cast<int>(den / divisor));
}

// a/b - c/d = (a*d - c*b) / (b*d)
Fraccion Fraccion::operator-(const Fraccion& otra) const {
    long long num = static_cast<long long>(numerador) * otra.denominador
                  - static_cast<long long>(otra.numerador) * denominador;
    long long den = static_cast<long long>(denominador) * otra.denominador;
    long long divisor = mcd(num, den);
    return Fraccion(static_cast<int>(num / divisor), static_cast<int>(den / divisor));
}

// a/b * c/d = (a*c) / (b*d)
Fraccion Fraccion::operator*(const Fraccion& otra) const {
    long long num = static_cast<long long>(numerador) * otra.numerador;
    long long den = static_cast<long long>(denominador) * otra.denominador;
    long long divisor = mcd(num, den);
    return Fraccion(static_cast<int>(num / divisor), static_cast<int>(den / divisor));
}

// a/b == c/d  si  a*d == c*b   (equivalentes, ej. 1/2 == 2/4)
bool Fraccion::operator==(const Fraccion& otra) const {
    return static_cast<long long>(numerador) * otra.denominador
        == static_cast<long long>(otra.numerador) * denominador;
}

std::ostream& operator<<(std::ostream& os, const Fraccion& f) {
    os << f.numerador << "/" << f.denominador;
    return os;
}
