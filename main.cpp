// Ejercicio 3: Sobrecarga de operadores (+, -, *, == y <<) con la clase Fraccion
#include <iostream>
#include "Fraccion.h"

int main() {
    std::cout << "=== 3. Sobrecarga de operadores ===" << std::endl;

    Fraccion f1(1, 2);
    Fraccion f2(1, 3);
    Fraccion f3(2, 4); // se guarda simplificada como 1/2
    Fraccion f4(1, 4);
    Fraccion f5(2, 3);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << std::endl;
    std::cout << f1 << " + " << f4 << " = " << (f1 + f4) << std::endl;

    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << std::endl;
    std::cout << f4 << " - " << f1 << " = " << (f4 - f1) << std::endl;

    std::cout << f1 << " * " << f5 << " = " << (f1 * f5) << std::endl;
    std::cout << f5 << " * " << f5 << " = " << (f5 * f5) << std::endl;

    std::cout << "1/2 == 2/4 ? " << (f1 == f3 ? "Si, son equivalentes" : "No") << std::endl;
    std::cout << f1 << " == " << f2 << " ? " << (f1 == f2 ? "Si, son equivalentes" : "No") << std::endl;

    return 0;
}
