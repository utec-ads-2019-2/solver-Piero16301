#ifndef ARBOL_OPERACIONES_EVALUADOR_H
#define ARBOL_OPERACIONES_EVALUADOR_H

#include <iostream>
#include <map>

#include "ExpressionTree.h"
#include "Operations.h"

std::map <char, int> variables;

class Evaluador {
private:

    static Expresion* evaluarNumero(const char* &s) {
        auto* numero = new Numero(0);
        while (*s && std::isdigit(*s)) {
            numero->valor = numero->valor * 10 + *s++ - '0';
        }
        return numero;
    };

    static Expresion* evaluarVariable(const char* &s) {
        auto* numero = new Numero(0);
        while (*s && std::isalpha(*s)) {
            if (variables.find(*s) != variables.end()) {
                numero->valor = variables[*s];
            } else {
                int valorVariable;
                std::cout << "Ingrese el valor de la variable " << *s << ": ";
                std::cin >> valorVariable;
                variables[*s] = valorVariable;
                numero->valor = variables[*s];
            }
            s++;
        }
        return numero;
    }

    Expresion* evaluarOperadores(const char* &s) {
        if (*s == 0) {
            throw std::invalid_argument("Expresion vacia");
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
        else if (std::isalpha(*s)) {
            Expresion* expresion = evaluarVariable(s);
            return expresion;
        }
        throw std::invalid_argument("Caracter no valido");
    };

    Expresion* evaluarSumandos(const char* &s) {
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
        Expresion* left = evaluarExponente(s);
        while (*s) {
            if (*s == '*') {
                s++;
                Expresion* right = evaluarExponente(s);
                left = new Multiplicacion(left, right);
                continue;
            }
            else if (*s == '/') {
                s++;
                Expresion* right = evaluarExponente(s);
                left = new Division(left, right);
                continue;
            }
            return left;
        }
        return left;
    };

    Expresion* evaluarExponente(const char* &s) {
        Expresion* left = evaluarOperadores(s);
        while (*s) {
            if (*s == '^') {
                s++;
                Expresion* right = evaluarOperadores(s);
                left = new Potencia(left, right);
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