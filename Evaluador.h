#ifndef ARBOL_OPERACIONES_EVALUADOR_H
#define ARBOL_OPERACIONES_EVALUADOR_H

#include <cassert>
#include <stdexcept>
#include <iostream>
#include <list>

#include "ExpressionTree.h"
#include "Operations.h"

class Evaluador {
private:

    static Expresion* evaluarNumero(const char* &s) {
        assert("Evaluar digito" && s && std::isdigit(*s));
        auto* numero = new Numero(0);
        while (*s && std::isdigit(*s)) {
            numero->valor = numero->valor * 10 + *s++ - '0';
        }
        return numero;
    };

    Expresion* evaluarOperadores(const char* &s) {
        assert("Evaluar parentesis" && s);
        if (*s == 0) {
            throw std::invalid_argument("No existe la expresion");
        }
        else if (*s == '(') {
            s++;
            Expresion* expresion = evaluarSumandos(s);
            if (*s == ')') {
                s++;
                return expresion;
            }
            throw std::runtime_error("Parentesis no balanceados");
        }
        else if (std::isdigit(*s)) {
            Expresion* expresion = evaluarNumero(s);
            return expresion;
        }
        throw std::invalid_argument("Caracter no valido");
    };

    Expresion* evaluarSumandos(const char* &s) {
        assert("Evaluar sumandos" && s);
        Expresion* left = evaluarFactores(s);
        while (*s) {
            if (*s == '+') {
                s++;
                Expresion* right = evaluarFactores(s);
                left = new Suma(left, right);
                continue;
            }
            else if (*s == '-') {
                s++;
                Expresion* right = evaluarFactores(s);
                left = new Resta(left, right);
                continue;
            }
            return left;
        }
        return left;
    };

    Expresion* evaluarFactores(const char* &s) {
        assert("Evaluar factores" && s);
        Expresion* left = evaluarOperadores(s);
        while (*s) {
            if (*s == '*') {
                s++;
                Expresion* right = evaluarOperadores(s);
                left = new Multiplicacion(left, right);
                continue;
            }
            else if (*s == '/') {
                s++;
                Expresion* right = evaluarOperadores(s);
                left = new Division(left, right);
                continue;
            }
            return left;
        }
        return left;
    };

public:
    const Expresion* evaluar(const char* s) {
        return evaluarSumandos(s);
    };
};

#endif //ARBOL_OPERACIONES_EVALUADOR_H