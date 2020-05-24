#ifndef BASEFACTORY_HPP
#define BASEFACTORY_HPP

#include "class.hpp"
#include "Decorator.hpp"

class BaseFactory{
private:
    Base* root;

public:
    BaseFactory(){ root = nullptr;};
    BaseFactory(int length, char** input){
        root = factory(length, input);
    }

    Base* factory(int length, char** input){
        if (length <= 1 || strlen(input[1]) == 0){
            return nullptr;
        } 
        else if (strlen(input[1]) == 1 && !isdigit(input[1][0])){
            return nullptr;
        }

        Base* result = new Op(atoi(input[1]));
        bool prev_opt = false;

        for (int i = 2; i < length && i+1 < length; i += 2){
            if(strlen(input[i]) > 1){
                if(!isdigit(input[i][0]) && !isdigit(input[i][1]))
                    return nullptr;
            }
            if(!isdigit(input[i][0]) && !isdigit(input[i+1][0]))
                return nullptr;
            if(input[i][0] == '+') {                                                  //Add
                result = new Add(result, new Op(atoi(input[i+1])));
                prev_opt = true;
            } else if(input[i][0] == '-') {                                           //Sub
                result = new Sub(result, new Op(atoi(input[i+1])));
                prev_opt = true;
            } else if(input[i][0] == '*') {
                if(input[i][1] != '\0' && input[i][1] == '*') {                       //pow
                    if(i!=1){
                        result = new Pow(new Paren(result), new Op(atoi(input[i+1])));
                    }
                    else{
                        result =new Paren( new Pow(result, new Op(atoi(input[i+1]))));
                    }
                } else {                                                              //mult
                    if(prev_opt) {
                        result = new Mult(new Paren(result), new Op(atoi(input[i+1])));
                    }
                    else{
                        result = new Mult(result, new Op(atoi(input[i+1])));
                    }
                    prev_opt = false;
                }
            } else if(input[i][0] == '/') {                                           //Div
                if(prev_opt) {
                    result = new Div(new Paren(result), new Op(atoi(input[i+1])));
                } else {
                    result = new Div(result, new Op(atoi(input[i+1])));
                }
                prev_opt = false;
            } else {
                return nullptr;
            }
        }
        return result;
    }

    Base* getRoot(){
        return root;
    }
};

#endif /* BaseFactory.hpp */
