#ifndef TEST_HPP
#define TEST_HPP

#include "gtest/gtest.h"
#include "class.hpp"
#include "BaseFactory.hpp"

TEST(Test, Test0){ // 3 + 1
    char *input[2]; 
    input[1] = new char[2];
    strcpy(input[1], "3");
    BaseFactory* A = new BaseFactory(2, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),3); 
}

TEST(Test, Test1){ // 3 + 1
    char *input[4]; 
    input[1] = new char[2];
    strcpy(input[1], "3");
    input[2] = new char[2];
    strcpy(input[2], "+");
    input[3] = new char[2];
    strcpy(input[3], "1"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),4); 
}

TEST(Test, Test2){ // 8 - 3
    char *input[4]; 
    input[1] = new char[2];
    strcpy(input[1], "8");
    input[2] = new char[2];
    strcpy(input[2], "-");
    input[3] = new char[2];
    strcpy(input[3], "3"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),5); 
}

TEST(Test, Test3){ // 5 * 6
    char *input[4]; 
    input[1] = new char[2];
    strcpy(input[1], "5");
    input[2] = new char[2];
    strcpy(input[2], "*");
    input[3] = new char[2];
    strcpy(input[3], "6"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),30); 
}
TEST(Test, Test4){ // 8 / 2
    char *input[4]; 
    input[1] = new char[2];
    strcpy(input[1], "8");
    input[2] = new char[2];
    strcpy(input[2], "/");
    input[3] = new char[2];
    strcpy(input[3], "2"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),4); 
}

TEST(Test, Test5){ // 2 ** 3
    char *input[4]; 
    input[1] = new char[2];
    strcpy(input[1], "2");
    input[2] = new char[3];
    strcpy(input[2], "**");
    input[3] = new char[2];
    strcpy(input[3], "3"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),8); 
}

TEST(Test, Test6){ // 3 + 2 * 6
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
    EXPECT_EQ(B->evaluate(),30);  
}

TEST(Test, Test7){ // 4 / 2 ** 2
    int len = 6;
    int max = 3;
    char *input[len]; 
    input[1] = new char[max];
    strcpy(input[1], "4");
    input[2] = new char[max];
    strcpy(input[2], "/");
    input[3] = new char[max];
    strcpy(input[3], "2"); 
    input[4] = new char[max];
    strcpy(input[4], "**");
    input[5] = new char[max];
    strcpy(input[5], "2"); 
    BaseFactory* A = new BaseFactory(len, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),4);   
}

TEST(Test, Test8){ // 12 / 2 ** 2 - 10
    int len = 8;
    int max = 3;
    char *input[len]; 
    input[1] = new char[max];
    strcpy(input[1], "12");
    input[2] = new char[max];
    strcpy(input[2], "/");
    input[3] = new char[max];
    strcpy(input[3], "2"); 
    input[4] = new char[max];
    strcpy(input[4], "**");
    input[5] = new char[max];
    strcpy(input[5], "2"); 
    input[6] = new char[max];
    strcpy(input[6], "-");
    input[7] = new char[max];
    strcpy(input[7], "10"); 
    BaseFactory* A = new BaseFactory(len, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),26);    
}

TEST(Test, Test9){ // 20 + 45
    char *input[4]; 
    input[1] = new char[3];
    strcpy(input[1], "20");
    input[2] = new char[3];
    strcpy(input[2], "+");
    input[3] = new char[3];
    strcpy(input[3], "45"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),65);  
}

TEST(Test, Test10){ // 20 / 10
    char *input[4]; 
    input[1] = new char[3];
    strcpy(input[1], "20");
    input[2] = new char[3];
    strcpy(input[2], "/");
    input[3] = new char[3];
    strcpy(input[3], "10"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),2);  
}

TEST(Test, Test11){ // 0 / 10
    char *input[4]; 
    input[1] = new char[3];
    strcpy(input[1], "0");
    input[2] = new char[3];
    strcpy(input[2], "/");
    input[3] = new char[3];
    strcpy(input[3], "10"); 
    BaseFactory* A = new BaseFactory(4, input); 
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),0);   
}
TEST(Test, Test12){ // 13 + 10
    char *input[4];
    input[1] = new char[3];
    strcpy(input[1], "13");
    input[2] = new char[3];
    strcpy(input[2], "+");
    input[3] = new char[3];
    strcpy(input[3], "10");
    BaseFactory* A = new BaseFactory(4, input);
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),23);
}

TEST(Test, Test13){ // 20 / 10
    char *input[4];
    input[1] = new char[3];
    strcpy(input[1], "20");
    input[2] = new char[3];
    strcpy(input[2], "/");
    input[3] = new char[3];
    strcpy(input[3], "10");
    BaseFactory* A = new BaseFactory(4, input);
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),2);   
}

TEST(Test, Test14){ // 20 / 10
    char *input[4];
    input[1] = new char[3];
    strcpy(input[1], "-5");
    input[2] = new char[3];
    strcpy(input[2], "*");
    input[3] = new char[3];
    strcpy(input[3], "2");
    BaseFactory* A = new BaseFactory(4, input);
    Base* B = A->getRoot();
    EXPECT_EQ(B->evaluate(),-10);   
}
#endif
