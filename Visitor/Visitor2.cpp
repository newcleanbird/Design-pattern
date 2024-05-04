#include <iostream>
using namespace std;

class Visitor;


class Element
{
public:
    virtual void Func1() = 0;
    
    virtual void Func2(int data)=0; // 需求变更时，增加方法
    virtual void Func3(int data)=0; // 增加方法
    //...
    
    virtual ~Element(){}
};

class ElementA : public Element
{
public:
    void Func1() override{
        //...
    }
    
    void Func2(int data) override{
        //...
    }
    
};

class ElementB : public Element
{
public:
    void Func1() override{
        //***
    }
    
    void Func2(int data) override {
        //***
    }
    
};

/*
在开发结束后，已经部署上线。此时有了新的需求，在原有的基础上增加方法并在子类重写的代价很大。并且违背了开闭原则。

考虑如何在不改变原代码的情况下，实现扩展式添加新的需求，动态添加新的操作。
*/




