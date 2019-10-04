#ifndef ARBOL_OPERACIONES_EXPRESSIONTREE_H
#define ARBOL_OPERACIONES_EXPRESSIONTREE_H

// Clase base de todas las expresiones
class Expresion {
public:
    virtual double operator()() const = 0;
    virtual ~Expresion() = default;
};

// Clase que almacena un numero entero
class Numero : public Expresion {
public:
    int valor;
    explicit Numero(const int valor = 0) : valor(valor) {}

    // El operator () retorna el valor del objeto Numero que se ha creado
    double operator()() const override {
        return valor;
    }
};

// Clase que almacena el arbol
class ArbolExpresion : public Expresion {
public:
    Expresion* left;
    Expresion* right;

    // Nodos left y right inicializados en nullptr
    explicit ArbolExpresion(Expresion* const left = nullptr, Expresion* const right = nullptr) : left(left), right(right) {}
};

#endif //ARBOL_OPERACIONES_EXPRESSIONTREE_H