#ifndef ARBOL_OPERACIONES_EXPRESSIONTREE_H
#define ARBOL_OPERACIONES_EXPRESSIONTREE_H

class Expresion {
public:
    virtual double operator()() const = 0;
    virtual ~Expresion() = default;
};

class Numero : public Expresion {
public:
    int valor;
    explicit Numero(const int valor = 0) : valor(valor) {}

    double operator()() const override {
        return valor;
    }
};

class ArbolExpresion : public Expresion {
public:
    Expresion* left;
    Expresion* right;

    explicit ArbolExpresion(Expresion* const left = nullptr, Expresion* const right = nullptr) : left(left), right(right) {}
};

#endif //ARBOL_OPERACIONES_EXPRESSIONTREE_H