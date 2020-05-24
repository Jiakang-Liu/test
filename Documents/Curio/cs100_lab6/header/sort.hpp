//sort.h
#ifndef SORT_HPP
#define SORT_HPP

class Container;

class Sort {
public:
    Sort() {};
    virtual void sort(Container* container) = 0;
};

class BubbleSort : public Sort {
public:
    BubbleSort();
    virtual void sort(Container* container);
};

class SelectionSort : public Sort {
public:
    SelectionSort();
    virtual void sort(Container* container);
    
};



#endif
