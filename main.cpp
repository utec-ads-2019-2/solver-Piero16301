#include <iostream>

#include "ExpressionTree.h"
#include "Evaluador.h"

double resolverExpresion(const char* const expresionOriginal) {
    Evaluador evaluador;
    const Expresion* const expresion = evaluador.evaluar(expresionOriginal);
    assert("Revisar resultado" && expresion);
    return (*expresion)();
}

int main() {
    double a = resolverExpresion("3*(4/2)+5^2/5");
    std::cout << "Resultado: " << a << std::endl;
    return 0;
}