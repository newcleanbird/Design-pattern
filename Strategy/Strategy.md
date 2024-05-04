# Strategy 策略模式
策略模式是一种行为型设计模式，它的核心目的是定义一系列算法，并将每个算法封装起来，使它们可以互换使用。

在C++中，策略模式允许在运行时选择所需的算法行为。通过使用策略模式，可以定义一系列算法，并将每个算法封装起来，使它们可以互换使用。这种模式主要利用虚函数和继承来实现，其中定义一个接口来代表可互换的算法，并让子类实现这个接口的具体算法。

## 动机（Motivation）
+ 在软件构建过程中，某些对象使用的算法可能多种多样，经常改变，如果将这些算法都编码到对象中，将会使对象变得异常复杂；而且有时候支持不使用的算法也是一个性能负担。
+ 如何在运行时根据需要透明地更改对象的算法？将算法与对象本身解耦，从而避免上述问题？

## 模式定义
定义一系列算法，把它们一个个封装起来，并且使它们可互相替换（变化）。该模式使得算法可独立于使用它的客户程序(稳定)而变化（扩展，子类化）。
——《设计模式》 GoF

## 要点总结
+ Strategy及其子类为组件提供了一系列可重用的算法，从而可以使得类型在运行时方便地根据需要在各个算法之间进行切换。
+ Strategy模式提供了用条件判断语句以外的另一种选择，消除条件判断语句，就是在解耦合。含有许多条件判断语句的代码通常都需要Strategy模式。
+ 如果Strategy对象没有实例变量，那么各个上下文可以共享同一个Strategy对象，从而节省对象开销。


## 适用场景
适用场景包括但不限于需要使用不同算法或策略来完成相同任务的情况，以及希望在运行时根据不同情况切换算法或策略的场景。例如，在一个排序应用中，可能需要根据数据的特性（如大小、分布等）来选择不同的排序算法（快速排序、归并排序等），这时就可以使用策略模式来动态地选择最适合的排序算法。

经典标志：``替换if-else``

## 深度理解策略模式
+ 理解策略模式的结构：策略模式通常涉及三个角色——上下文（Context）、策略（Strategy）接口和具体策略（ConcreteStrategy）。上下文用来维护对策略对象的引用，并负责调用策略对象的方法；策略接口定义了所有支持的算法的公共接口；具体策略实现了策略接口的具体算法。

+ 理解策略模式的优点：策略模式提供了一种优雅的方式来封装一系列可互换的算法，使得算法可以独立于使用它们的客户端进行变化。这样可以提高系统的灵活性和可扩展性。

+ 学习策略模式的实现：在C++中，可以通过使用虚函数和继承来实现策略模式。定义一个包含虚函数的基类作为策略接口，然后通过继承该基类并实现具体的算法来创建具体策略类。上下文类则包含一个或多个策略接口的指针或引用，并在需要时调用相应的策略方法。

+ 实践策略模式的应用：通过实际编写代码来实践策略模式，可以更好地理解其工作原理和应用场景。尝试创建一个包含多种算法的问题，并使用策略模式来解决它，这将有助于加深对策略模式的理解。

## 例子
### 1.计算不同国家的税
适用情况：
```cpp
enum TaxBase {
	CN_Tax,
	US_Tax,
	DE_Tax,
	FR_Tax       //更改
};

class SalesOrder{
    TaxBase tax;
public:
    double CalculateTax(){
        //...
        
        if (tax == CN_Tax){
            //CN***********
        }
        else if (tax == US_Tax){
            //US***********
        }
        else if (tax == DE_Tax){
            //DE***********
        }
		else if (tax == FR_Tax){  //更改
			//...
		}

        //....
     }
    
};
```
分析：SalesOrder类CalculateTax方法中，需要逐个判断tax类型，然后依次进行处理。这种实现在扩展和修改时需要对原有代码进行修改，容易引发bug，扩展性不好。因此是很适合使用策略模式的形式。

使用策略模式：
```cpp
// 税基类
class TaxStrategy{
public:
    virtual double Calculate(const Context& context)=0;
    virtual ~TaxStrategy(){}
};


class CNTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //中国税算法
    }
};

class USTax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //美国税算法
    }
};

class DETax : public TaxStrategy{
public:
    virtual double Calculate(const Context& context){
        //德国税算法
    }
};

//扩展
//当需要新增税时，继承基类并设计具体的算法
class FRTax : public TaxStrategy{
public:
	virtual double Calculate(const Context& context){
		//.........
	}
};


class SalesOrder{
private:
    TaxStrategy* strategy;

public:
    // 工厂模式
    SalesOrder(StrategyFactory* strategyFactory){
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder(){
        delete this->strategy;
    }

    public double CalculateTax(){
        //...
        Context context();
        
        double val = 
            strategy->Calculate(context); //多态调用
        //...
    } 
};
```
分析：将需要判断的类型抽象为一个抽象类，定义抽象方法供子类实现。每种类型扩展时，继承抽象父类并改写方法，实现不同的策略。
在使用时，类似多态，定义一个抽象父类指针，指向需要的子类对象，然后调用同名方法。
此策略使用时可以搭配工厂模式。

### 2.不同客户策略
```cpp
//示例1
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//高层策略接口
class Strategy
{
public:
    virtual double CalcPrice(double  goodsPrice){return 0;}
};

//具体策略
//普通客户策略
class NormalCustomerStrategy : public Strategy
{
public:
    double CalcPrice(double  goodsPrice) override
    {
        //普通客户没有折扣
        std::cout<<"普通客户没有折扣"<<std::endl;
        return goodsPrice;
    }
};

//老客户策略
class OldCustomerStrategy : public Strategy
{
public:
    double CalcPrice(double  goodsPrice) override
    {
        //老客户 统一折扣5%
        std::cout<<"老客户折扣5%"<<std::endl;
        return goodsPrice * (1 - 0.05);
    }
};

//大客户策略
class LargeCustomerStrategy : public Strategy
{
    double CalcPrice(double  goodsPrice) override
    {
        //大客户 统一折扣10%
        std::cout<<"大客户折扣10%"<<std::endl;
        return goodsPrice * (1 - 0.1);
    }
};


//策略上下文
class Price
{
public:
    Price(Strategy* strategy) : pStrategy(strategy){}
    double Quote(double goodsPrice)
    {
        if(pStrategy != nullptr)
        {
            return pStrategy->CalcPrice(goodsPrice);
        }
        return 0;
    }
private:
    std::unique_ptr<Strategy> pStrategy {nullptr};
};

int main()
{
    {
        Price price(new NormalCustomerStrategy);
        double goodsPrice = price.Quote(100);
        std::cout<<"普通客户最终价:"<<goodsPrice<<std::endl;
    }

    {
        Price price(new OldCustomerStrategy);
        double goodsPrice = price.Quote(100);
        std::cout<<"老客户最终价:"<<goodsPrice<<std::endl;
    }

    {
        Price price(new LargeCustomerStrategy);
        double goodsPrice = price.Quote(100);
        std::cout<<"大客户最终价:"<<goodsPrice<<std::endl;
    }

    return 0;
}
```