#ifndef ARBOL_OPERACIONES_EXPRESSIONTREE_H
#define ARBOL_OPERACIONES_EXPRESSIONTREE_H

class Expresion {
public:
    virtual int operator()() const = 0;
    virtual ~Expresion() = default;
};

class Numero : public Expresion {
    int valor;
    Numero(const int valor = 0) : valor(valor) {}
    int operator()() const {
        return valor;
    }
};

class ArbolExpresion : public Expresion {
public:
    Expresion* left;
    Expresion* right;

    ArbolExpresion(Expresion* const left = 0, Expresion* const right = 0) : left(left), right(right) {}
};

#endif //ARBOL_OPERACIONES_EXPRESSIONTREE_H