#include <iostream>

#include "ExpressionTree.h"
#include "Evaluador.h"

double resolverExpresion(const char* const expresionOriginal) {
    Evaluador evaluador;
    const Expresion* const expresion = evaluador.evaluar(expresionOriginal);
    return (*expresion)();
}

int main() {
    std::string expresion;
    std::cin >> expresion;
    const char* expresionOriginal = expresion.c_str();
    double a = resolverExpresion(expresionOriginal);
    std::cout << "Resultado: " << a << std::endl;
    return 0;
}