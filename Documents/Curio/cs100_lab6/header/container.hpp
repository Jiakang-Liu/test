//container.h
#ifndef CONTAINER_HPP
#define CONTAINER_HPP
#include <vector>
#include <list>
#include "class.hpp"

class Sort;

class Container {
protected:
    Sort* sort_function;
    
public:
    Container();
    Container(Sort* function);
    
    void set_sort_function(Sort* sort_function);
    virtual void add_element(Base* element) = 0;
    virtual void print() = 0;
    virtual void sort() = 0;
    virtual void swap(int i, int j) = 0;
    virtual Base* at(int i) = 0;
    virtual int size() = 0;
};

class VectorContainer: public Container {
private:
    std::vector <Base*> data;
public:
    VectorContainer();
    VectorContainer(Sort* function);
    virtual void add_element(Base* element);
    virtual void print();
    virtual void sort();
    virtual void swap(int i, int j);
    virtual Base* at(int i);
    virtual int size();
    
};

class ListContainer: public Container {
private:
    std::list<Base*> mylist;
public:
    ListContainer();
    ListContainer(Sort* function);
    virtual void add_element(Base* element);
    virtual void print();
    virtual void sort();
    virtual void swap(int i, int j);
    virtual Base* at(int i);
    virtual int size();
    
};


#endif
