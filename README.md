# Ejercicio 3: Clase Fraccion
Representa fracciones siempre simplificadas y con el signo en el numerador.
Permite sumar, restar, multiplicar, comparar e imprimir fracciones con la sintaxis normal de C++.

**Archivos:** `Fraccion.h/.cpp` (clase con `operator+`, `operator-`, `operator*`, `operator==` y `operator<<`) · `main.cpp` (pruebas de cada operador)

- **Compilar:** `g++ -std=c++17 -Wall *.cpp -o programa.exe`
- **Ejecutar:** `./programa.exe`

```
1/2 + 1/3 = 5/6
1/4 - 1/2 = -1/4
1/2 * 2/3 = 1/3
1/2 == 2/4 ? Si, son equivalentes
```

**Concepto de POO:** sobrecarga de operadores, encapsulamiento (invariante de fraccion simplificada) y funciones `friend`.
