//
//  Header.h
//  learning
//
//  Created by Jiakang Liu on 5/16/20.
//  Copyright © 2020 Jiakang Liu. All rights reserved.
//

#ifndef BaseFactory_hpp
#define BaseFactory_hpp
#include "class.hpp"
#include "Decorator.hpp"
class BaseFactory{
public:
    BaseFactory(){}
    Base* factory(char** input, int length){
        string in,next;
        int prev_opt=0;
        Base* result = nullptr;
        in = input[0];
        if (length == 0 || !isdigit(in[0])){
            return nullptr;
        }
        result = new Op(stod(in));
        for (unsigned int i = 1; i< length; ++i){
            in = input[i];next =input[i+1];
            if(in == "+" && isdigit(next[0])){
                result = new Add(result, new Op(stod(next)));
                cout<<result->stringify()<<endl;
                prev_opt = 1;
                i++;
            }
            else if(in == "-" && isdigit(next[0])){
                result = new Sub(result, new Op(stod(next)));
                prev_opt = 1;
                i++;
            }
            else if(in == "*" && isdigit(next[0])){
                if(prev_opt == 1){
                    result = new Mult(new Paren(result), new Op(stod(next)));
                }
                else{
                    result = new Mult(result, new Op(stod(next)));
                }
                prev_opt = 0;
                i++;
            }
            else if(in == "/" && isdigit(next[0])){
                if(prev_opt == 1){
                    result = new Div(new Paren(result), new Op(stod(next)));
                }
                else{
                    result = new Div(result, new Op(stod(next)));
                }
                prev_opt = 0;
                i++;
            }
            else if(in == "^" && isdigit(next[0])){
                if(i!=1){
                    result = new Pow(new Paren(result), new Op(stod(next)));
                }
                else{
                    result =new Paren( new Pow(result, new Op(stod(next))));
                }
                i++;
            }
            else{
                return nullptr;
            }
        }
        return result;
    }
};

#endif /* BaseFactory.hpp */
