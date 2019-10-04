#ifndef ARBOL_OPERACIONES_OPERATIONS_H
#define ARBOL_OPERACIONES_OPERATIONS_H

#include <cmath>
#include "ExpressionTree.h"

// Estructura para realizar la suma
struct Suma : public ArbolExpresion {
    // Constructor recibe como parametros el left y right y construye una expresion del arbol con nodos left y right
    Suma(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    // El operator () retorna el valor double de la suma de las ramas left y right
    double operator()() const override {
        return (*left)() + (*right)();
    }
};

// Estructura para realizar la resta
struct Resta : public ArbolExpresion {
    // Constructor recibe como parametros el left y right y construye una expresion del arbol con nodos left y right
    Resta(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    // El operator () retorna el valor double de la resta de las ramas left y right
    double operator()() const override {
        return (*left)() - (*right)();
    }
};

// Estructura para realizar la multiplicacion
struct Multiplicacion : public ArbolExpresion {
    // Constructor recibe como parametros el left y right y construye una expresion del arbol con nodos left y right
    Multiplicacion(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    // El operator () retorna el valor double de la multiplicacion de las ramas left y right
    double operator()() const override {
        return (*left)() * (*right)();
    }
};

// Estructura para realizar la division
struct Division : public ArbolExpresion {
    // Constructor recibe como parametros el left y right y construye una expresion del arbol con nodos left y right
    Division(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    // El operator () retorna el valor double de la division de las ramas left y right
    double operator()() const override {
        return (*left)() / (*right)();
    }
};

// Estructura para realizar la potencia
struct Potencia : public ArbolExpresion {
    // Constructor recibe como parametros el left y right y construye una expresion del arbol con nodos left y right
    Potencia(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    // El operator () retorna el valor double de la potencia de las ramas left y right
    double operator()() const override {
        return pow((*left)(), (*right)());
    }
};

#endif //ARBOL_OPERACIONES_OPERATIONS_H