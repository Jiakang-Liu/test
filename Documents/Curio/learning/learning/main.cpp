//
//  main.cpp
//  learning
//int argc, const char * argv[]
//  Created by Jiakang Liu on 5/16/20.
//  Copyright © 2020 Jiakang Liu. All rights reserved.
//

#include <iostream>
#include "class.hpp"
#include "BaseFactory.hpp"
using namespace std;
int main(int argc, char * argv[]) {
    Base* result;
    string x = argv[1];
    BaseFactory expression;
    argv++;
    result = expression.factory(argv, argc-1);
    if(result == nullptr){
        cout<<"invaild"<<endl;
    }
    else{
        cout << result -> stringify() << " = " << result -> evaluate()<<endl;
    }
    return 0;
    return 0;
}
