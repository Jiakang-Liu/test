//class.h
#ifndef CLASS_HPP
#define CLASS_HPP

#include <iostream>
#include <string>
#include "iterator.hpp"
#include "visitor.hpp"

//Base class
class Base {
public:
    /* Constructors */
    Base() { };
    
    /* Pure Virtual Functions */
    virtual double evaluate() = 0;
    virtual std::string stringify() = 0;
    
    virtual Iterator* create_iterator() = 0;
    virtual void accept(CountVisitor* visitor) = 0;
    virtual Base* get_left() = 0;
    virtual Base* get_right() = 0;
};

// Op class
// This class represents the operands in an expression, 
// and can be any double value. It's string representation 
// should be a string version of its double value.
class Op : public Base {
public:
    Op() {};
    
    Op(double value) : Base() {
        num = value;
    }
    
    ~ Op () {};
    
    double evaluate() {
        return num;
    }
    std::string stringify() {
        std::string str = std::to_string(num);
        return str;
    }
    void accept(CountVisitor* visitor){
        visitor->visit_op();
    }
    Iterator* create_iterator(){
        return new NullIterator(this);
    }
    Base* get_left(){
        return nullptr;
    }
    Base* get_right(){
        return nullptr;
    }
private:
    double num;
};

// Random class
// This class is exactly the same as the Op class, 
// but rather than being able to set its value its 
// value is set during construction by the the equation rand() % 100
class Rand : public Base {
public:
    Rand() : Base() {
        srand (0);
        num = rand() % 100;
    }
    ~ Rand () {};
    
    double  evaluate() {
        double new_num;
        new_num = static_cast<double>(num);
        return new_num;
    }
    void accept(CountVisitor* visitor){visitor->visit_rand();}
    std::string stringify() {
        std::string str = std::to_string(num);
        return str;
    }
    Iterator* create_iterator(){
        return new NullIterator(this);
    }
private:
    int num;
};

// Mult class
// This class represents the multiplication operation. 
// It's string representation should be "*" along with 
// its operands (which might be operands or another operator).
class Mult: public Base {
public:
    Base* result;
    Base* left;
    Base* right;
    
    Mult() {};
    ~ Mult() {};
    Mult (Base* new_num1,Base* new_num2){
        left = new_num1;
        right = new_num2;
        result = new Op(evaluate());
    };
    
    double evaluate(){
        return left -> evaluate() * right -> evaluate();
    }
    
    std::string stringify() {
        std::string str1 = left -> stringify();
        std::string str2 = right -> stringify();
        std::string str3  = " * ";
        std::string str = str1 + str3;
        str = str + str2;
        return str;
    }
    
    void accept(CountVisitor* visitor){
        visitor->visit_mult();
    }
    Iterator* create_iterator(){
        return new BinaryIterator(this);
    }
    Base* get_left() {
        return this->left;
    }
    Base* get_right() {
        return this->right;
    }
    
};

// Add class
// This class represents the add operaiton. It's 
// string representation should be "+" along with 
// its operands (which might be operands or another operator).
class Add: public Base {
public:
    Base* result;
    Base* left;
    Base* right;
    
    Add() {};
    ~Add() {};
    Add (Base* new_num1, Base* new_num2){
        left = new_num1;
        right = new_num2;
        result = new Op(evaluate());
    };
    
    double  evaluate(){
        return left -> evaluate() + right -> evaluate();
    }
    
    std::string stringify() {
        std::string str1 = left -> stringify();
        std::string str2 = right -> stringify();
        std::string str3 = " + ";
        std::string str = str1 + str3;
        str+=str2;
        return str;
    }
    void accept(CountVisitor* visitor){
        visitor->visit_add();
    }
    Iterator* create_iterator(){
        return new BinaryIterator(this);
    }
    
    Base* get_left() {
        return this->left;
    }
    Base* get_right() {
        return this->right;
    }
    
};

// Sub class
// This class represents the subtraction operation. 
// It's string representation should be "-" along with 
// its operands (which might be operands or another operator).
class Sub: public Base {
public:
    Base* result;
    Base* left;
    Base* right;
    
    Sub() {};
    ~Sub() {};
    Sub (Base* new_num1, Base* new_num2){
        left = new_num1;
        right = new_num2;
        result = new Op(evaluate());
    };
    
    double evaluate(){
        return left -> evaluate() - right -> evaluate();
    }
    
    std::string stringify() {
        std::string str1 = left -> stringify();
        std::string str2 = right -> stringify();
        std::string str3 = " - ";
        std::string str = str1 + str3;
        str+=str2;
        return str;
    }
    Iterator* create_iterator(){
        return new BinaryIterator(this);
    }
    
    Base* get_left() {
        return this->left;
    }
    Base* get_right() {
        return this->right;
    }
    void accept(CountVisitor* visitor){visitor->visit_sub();}
};

// Div class
// This class represents the division operation. 
// It's string representation should be "/" along 
// with its operands (which might be operands or another operator).
class Div: public Base {
public:
    Base* result;
    Base* left;
    Base* right;
    
    Div() {};
    ~ Div() {};
    Div (Base* new_num1, Base* new_num2) {
        left = new_num1;
        right = new_num2;
        result = new Op(evaluate());
    };
    
    double evaluate() {
        return left -> evaluate() / right -> evaluate();
    }
    
    std:: string stringify() {
        std::string str1 = left -> stringify();
        std::string str3 = right -> stringify();
        std::string str2 = " / ";
        std::string str = str1 + str2;
        str = str + str3;
        return str;
    }
    Iterator* create_iterator(){
        return new BinaryIterator(this);
    }
    void accept(CountVisitor* visitor){
        visitor->visit_div();
    }
    
    Base* get_left() {
        return this->left;
    }
    Base* get_right() {
        return this->right;
    }
    
};

// Pow class
// This class represents the power or exponentiation 
// operation. It's string representation should be "**" 
// along with its operands (which might be operands or another operator).
class Pow : public Base{
public:
    Base* result;
    Base* left;
    Base* right;
    
    Pow(){};
    ~Pow(){};
    Pow(Base* new_num, Base* new_pow){
        left = new_num;
        right = new_pow;
        result = new Op(evaluate());
    };
    
    double evaluate(){
        double Result = left -> evaluate();
        if (right -> evaluate() == 0){
            Result = 1.0;
        }
        else{
            for(unsigned int i=1; i< right -> evaluate(); ++i){
                Result*= left -> evaluate();
            }
        }
        return Result;
    }
    
    std::string stringify(){
        std::string str1 = left -> stringify();
        std::string str2 = right -> stringify();
        std::string str3 = " ** ";
        std::string str = str1 + str3;
        str+=str2;
        return str;
    }
    Iterator* create_iterator(){
        return new BinaryIterator(this);
    }
    void accept(CountVisitor* visitor){visitor->visit_pow();}
    
    Base* get_left() {
        return this->left;
    }
    Base* get_right() {
        return this->right;
    }
    
};

#endif
