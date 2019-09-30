#include "ExpressionTree.h"

struct Suma : public ArbolExpresion {
    Suma(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}
    int operator()() const {
        return (*left)() + (*right)();
    }
};

struct Resta : public ArbolExpresion {
    Resta(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}
    int operator()() const {
        return (*left)() - (*right)();
    }
};

struct Multiplicacion : public ArbolExpresion {
    Multiplicacion(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}
    int operator()() const {
        return (*left)() * (*right)();
    }
};

struct Division : public ArbolExpresion {
    Division(Expresion* const left, Expresion* const right) : ArbolExpresion(left, right) {}
    int operator()() const {
        return (*left)() / (*right)();
    }
};