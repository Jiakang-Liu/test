#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <iomanip>
#include <string>
#include <time.h>
#include "class.hpp"
#include "container.hpp"
#include "sort.hpp"
#include "container.cpp"
#include "sort.cpp"
#include "Decorator.hpp"
#include "BaseFactory.hpp"

using namespace std;

void test1(){
    int len = 6;
    int max = 2;
    char *input[len]; 
    input[1] = new char[max];
    strcpy(input[1], "3");
    input[2] = new char[max];
    strcpy(input[2], "+");
    input[3] = new char[max];
    strcpy(input[3], "2"); 
    input[4] = new char[max];
    strcpy(input[4], "*");
    input[5] = new char[max];
    strcpy(input[5], "6"); 
    BaseFactory* A = new BaseFactory(len, input); 
    Base* B = A->getRoot();
    cout << "B = " << B->stringify() << " = " << B->evaluate() << endl;
}

void test2(){
    int len = 8;
    int max = 2;
    char *input[len]; 
    input[1] = new char[max];
    strcpy(input[1], "4");
    input[2] = new char[max];
    strcpy(input[2], "*");
    input[3] = new char[max];
    strcpy(input[3], "2"); 
    input[4] = new char[max];
    strcpy(input[4], "+");
    input[5] = new char[max];
    strcpy(input[5], "1"); 
    input[6] = new char[max];
    strcpy(input[6], "**");
    input[7] = new char[max];
    strcpy(input[7], "2"); 
    BaseFactory* A = new BaseFactory(len, input); 
    Base* B = A->getRoot();
    cout << "B = " << B->stringify() << " = " << B->evaluate() << endl;
}

void test3(){
    int len = 10;
    int max = 3;
    char *input[len]; 
    input[1] = new char[max];
    strcpy(input[1], "1");
    input[2] = new char[max];
    strcpy(input[2], "+");
    input[3] = new char[max];
    strcpy(input[3], "2"); 
    input[4] = new char[max];
    strcpy(input[4], "-");
    input[5] = new char[max];
    strcpy(input[5], "3"); 
    input[6] = new char[max];
    strcpy(input[6], "*");
    input[7] = new char[max];
    strcpy(input[7], "4"); 
    input[8] = new char[max];
    strcpy(input[8], "/");
    input[9] = new char[max];
    strcpy(input[9], "5"); 
    BaseFactory* A = new BaseFactory(len, input); 
    Base* B = A->getRoot();
    cout << "B = " << B->stringify() << " = " << B->evaluate() << endl;
}

void test4(){
    int len = 10;
    int max = 3;
    char *input[len]; 
    input[1] = new char[max];
    strcpy(input[1], "15");
    input[2] = new char[max];
    strcpy(input[2], "**");
    input[3] = new char[max];
    strcpy(input[3], "3"); 
    input[4] = new char[max];
    strcpy(input[4], "-");
    input[5] = new char[max];
    strcpy(input[5], "15"); 
    input[6] = new char[max];
    strcpy(input[6], "**");
    input[7] = new char[max];
    strcpy(input[7], "1"); 
    input[8] = new char[max];
    strcpy(input[8], "+");
    input[9] = new char[max];
    strcpy(input[9], "2"); 
    BaseFactory* A = new BaseFactory(len, input); 
    Base* B = A->getRoot();
    cout << "B = " << B->stringify() << " = " << B->evaluate() << endl;
}

void inputTest(int argc, char *argv[]){
    BaseFactory* A = new BaseFactory(argc, argv); 
    Base* B = A->getRoot();
    if(B == nullptr){
        cout << "Invalid enter" << endl;
    } else {
        cout << "B = " << B->stringify() << " = " << B->evaluate() << endl;
    }
}

int main(int argc, char *argv[]){
//    test1();
//    test2();
//    test3();
//    test4();
    inputTest(argc, argv);
    return 0;
}
