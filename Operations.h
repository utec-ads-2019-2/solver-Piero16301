#ifndef ARBOL_OPERACIONES_OPERATIONS_H
#define ARBOL_OPERACIONES_OPERATIONS_H

#include <cmath>
#include "ExpressionTree.h"

struct Suma : public ArbolExpresion {
    Suma(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    double operator()() const override {
        return (*left)() + (*right)();
    }
};

struct Resta : public ArbolExpresion {
    Resta(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    double operator()() const override {
        return (*left)() - (*right)();
    }
};

struct Multiplicacion : public ArbolExpresion {
    Multiplicacion(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    double operator()() const override {
        return (*left)() * (*right)();
    }
};

struct Division : public ArbolExpresion {
    Division(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    double operator()() const override {
        return (*left)() / (*right)();
    }
};

struct Potencia : public ArbolExpresion {
    Potencia(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}

    double operator()() const override {
        return pow((*left)(), (*right)());
    }
};

#endif //ARBOL_OPERACIONES_OPERATIONS_H