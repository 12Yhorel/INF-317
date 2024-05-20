#include <iostream>
#include <string>
#include "calculadora.h"

int main() {
    std::string exp;

    std::cout << "Ingrese una expresion postfija: ";
    std::getline(std::cin, exp);

    int resultado = evaluarPostfija(exp);
    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}
