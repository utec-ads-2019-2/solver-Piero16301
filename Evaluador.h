#ifndef ARBOL_OPERACIONES_EVALUADOR_H
#define ARBOL_OPERACIONES_EVALUADOR_H

#include <iostream>
#include <map>

#include "ExpressionTree.h"
#include "Operations.h"

// Mapa donde se va a almacenar los valores de las variables. Comienza vacio
std::map <char, int> variables;

// Clase encargada de analizar y parsear la expresion original
class Evaluador {

private:
    // Metodo encargado de parsear los numeros y crear y retornar un objeto tipo Numero heredado de Expresion
    static Expresion* evaluarNumero(const char* &s) {
        auto* numero = new Numero(0);
        while (*s && std::isdigit(*s)) {
            numero->valor = numero->valor * 10 + *s++ - '0';
        }
        return numero;
    };

    // Metodo encargado de buscar si el valor de la variable ingresada se encuentra en el mapa
    static Expresion* evaluarVariable(const char* &s) {
        auto* numero = new Numero(0);
        while (*s && std::isalpha(*s)) {
            if (variables.find(*s) != variables.end()) {
                // Ingresa si la variable se encuentra en el mapa
                numero->valor = variables[*s];
            } else {
                // Ingresa si la variable no se encuentra en el mapa
                int valorVariable;
                // Pide que el usuario ingrese el valor de la variable
                std::cout << "Ingrese el valor de la variable " << *s << ": ";
                std::cin >> valorVariable;
                // Se añade la variable al mapa
                variables[*s] = valorVariable;
                // Se asigna el nuevo valor de la variable al atributo valor del objeto tipo Numero
                numero->valor = variables[*s];
            }
            s++;
        }
        return numero;
    }

    // Evalua los posibles casos de imput, ya sea (), numero o variable
    Expresion* evaluarOperadores(const char* &s) {
        if (*s == 0) {
            // Ingresa si la expresion esta vacia
            throw std::invalid_argument("Expresion vacia");
        }
        else if (*s == '(') {
            // Ingresa si la expresion contiene un parentesis, se pasa al siguiente caracter (s++=
            s++;
            // Se evalua si hay sumandos dentro del parentesis
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