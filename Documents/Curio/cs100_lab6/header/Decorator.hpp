//decorator.h

#ifndef DECORATOR_HPP
#define DECORATOR_HPP
#include "class.hpp"
#include <cmath>
#include <string>

using namespace std;

class Decorator : public Base {
    protected:
        Base* key;
    public:
        Decorator(Base* key) : key(key) { };
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

class Ceil : public Decorator {
    public:
        Ceil(Base* key) : Decorator(key) { };
        virtual double evaluate() {return ceil(key->evaluate());};
        virtual std::string stringify(){return to_string(ceil(key->evaluate()));};
};

class Floor : public Decorator {
public:
    Floor(Base* key) : Decorator(key) { };
    virtual double evaluate() {return floor(key->evaluate());};
    virtual std::string stringify() {return to_string(floor(key->evaluate()));};
};

class AbsValue : public Decorator {
public:
    AbsValue(Base* key) : Decorator(key) { };
    virtual double evaluate() {return abs(key->evaluate());};
    virtual std::string stringify() {return to_string(abs(key->evaluate()));};
};

class Trunc : public Decorator {
public:
    Trunc(Base* key) : Decorator(key) { };
    virtual double evaluate() {return key->evaluate();};
    virtual std::string stringify() {return to_string(key->evaluate());};
};

class Paren : public Decorator {
public:
    Paren(Base* key) : Decorator(key) { };
    virtual double evaluate() {return key->evaluate();};
    virtual std::string stringify() {return "(" + key->stringify() + ")";};
};
#endif
