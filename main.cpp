#include <iostream>

#include "ExpressionTree.h"
#include "Evaluador.h"

// Funcion para resolver la expresion. Recibe el char* y retorna el resultado double
double resolverExpresion(const char* const expresionOriginal) {
    Evaluador evaluador;
    const Expresion* const expresion = evaluador.evaluar(expresionOriginal);
    return (*expresion)();
}

int main() {
    // Se ingresa la expresion como string
    std::string expresion;
    std::cin >> expresion;
    // Se convierte el imput de string a char*
    const char* expresionOriginal = expresion.c_str();
    // Se evalua el imput y retorna un resultado double
    double a = resolverExpresion(expresionOriginal);
    // Se imprime el resultado
    std::cout << "Resultado: " << a << std::endl;
    return 0;
}