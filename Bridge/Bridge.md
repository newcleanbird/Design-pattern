# Bridge 桥模式
桥接模式（Bridge Pattern）是一种结构型设计模式，旨在将抽象与实现分离开来，使它们可以独立变化。

## 动机（Motivation）
+ 由于某些类型的固有的实现逻辑，使得它们具有两个变化的维度，乃至多个纬度的变化。
+ 如何应对这种“多维度的变化”？如何利用面向对象技术来使得类型可以轻松地沿着两个乃至多个方向变化，而不引入额外的复杂度？

## 模式定义
将抽象部分(业务功能)与实现部分(平台实现)分离，使它们都可以独立地变化。
——《设计模式》GoF

## 要点总结
+ Bridge模式使用“对象间的组合关系”解耦了抽象和实现之间固有的绑定关系，使得抽象和实现可以沿着各自的维度来变化。所谓抽象和实现沿着各自纬度的变化，即“子类化”它们。
+ Bridge模式有时候类似于多继承方案，但是多继承方案往往违背单一职责原则（即一个类只有一个变化的原因），复用性比较差。Bridge模式是比多继承方案更好的解决方法。
+ Bridge模式的应用一般在“两个非常强的变化维度”，有时一个类也有多于两个的变化维度，这时可以使用Bridge的扩展模式。

## 优点
+ 分离抽象和实现：允许抽象和实现可以独立变化，提高了系统的灵活性。
+ 扩展性增强：更容易对抽象和实现层次进行扩展，而不会影响到另一层。
+ 符合开闭原则：易于通过继承或组合的方式扩展功能，而不需要修改现有的代码。
+ 减少子类的生成：减少了子类数量，降低了系统管理和维护的复杂度。

## 深入理解：
### 角色定义：
包括抽象化(Abstraction)角色、具体抽象化(RefinedAbstraction)角色、实现化(Implementor)角色以及关联关系。
+ Abstraction（抽象化角色）：定义抽象接口，维护一个对Implementor对象的引用。
+ RefinedAbstraction（具体抽象化角色）：是Abstraction的一个子类，对Abstraction接口进行一些补充。
+ Implementor（实现化角色）：定义实现化角色的接口，任何Abstraction角色可以调用。
+ ConcreteImplementor（具体实现化角色）：Implementor接口的具体实现。
+ 关联关系：则描述了如何将抽象部分和实现部分结合在一起。

## 适用情况：
+ 多个维度的分类：当存在多个类似维度的分类时，可以使用桥接模式来分离这些维度，使得它们可以独立变化。
+ 复杂的继承关系：在有多层级继承关系的情况下，如果既要保持继承结构又要支持多维度变化，桥接模式是一个合适的选择。
+ 平台间移植的需求：当需要将某些功能在不同的平台上实现，且每个平台有各自的实现方式时，使用桥接模式可以很好地隔离这些差异。

## 注意事项
+ 不要过度使用：仅当类的继承层次较多或者存在多个独立变化的维度时，才考虑使用桥接模式。避免在不需要的情况下使用该模式，以免增加系统的复杂性。
+ 封装变化因素：尽可能将变化的因素封装在最小的逻辑单元中，这样可以限制风险的扩散，使得系统更加稳定。
+ 遵循设计原则：桥接模式遵循了里氏替换原则、依赖倒置原则，并最终实现了开闭原则。这意味着它对修改关闭，对扩展开放，这有助于保持系统的灵活性和可维护性。
+ 理解两个独立变化的维度：正确识别出系统中两个独立变化的维度是桥接模式的关键。这要求开发者有较高的抽象能力，以确保抽象化和实现化能够正确地分离。
+ 组合而非继承：在桥接模式中，抽象化部分与实现化部分之间的继承关系被取消，改用组合关系。这样做可以减少类之间的耦合，提高系统的可扩展性。

## 应用场景
1. 图形界面库：图形界面库通常有多种外观（如按钮、菜单等）和多种平台实现（Windows、Mac、Linux等）。桥接模式可以使抽象外观接口独立于各个平台的具体实现，方便在不同平台上复用相同的外观设计。

2. 日志系统：日志系统可能需要支持不同的日志级别（如Debug、Info、Error等）和不同的输出目的地（如控制台、文件、数据库等）。桥接模式可以将日志级别抽象出来，同时将输出目的地作为一个独立的维度，使得日志系统可以在不修改原有代码的基础上轻易更换日志级别或输出目的地。

3. 数据库驱动：数据库驱动程序可能需要支持不同的数据库（MySQL、Oracle、SQL Server等）和不同的操作（查询、插入、删除、更新等）。桥接模式可以将数据库操作抽象成统一的接口，而具体的数据库操作由不同的实现类负责，这样就能灵活地替换或升级数据库驱动。

4. 图像处理库：图像处理库可能需要支持多种图像格式（JPEG、PNG、GIF等）和多种处理操作（缩放、旋转、裁剪等）。桥接模式可以将图像处理操作抽象化，并与各种图像格式的读写实现解耦，便于添加新的格式支持或处理功能。

5. 网络通信框架：在网络通信框架中，抽象接口可以定义诸如发送消息、接收消息等功能，而具体实现可以包括TCP、UDP、WebSocket等多种协议。这样，上层应用只需关注消息的发送和接收逻辑，而无需关心底层通信协议的具体实现。

6. 多语言本地化：在国际化应用中，可以将界面的逻辑（如按钮、标签、提示信息等）与具体语言环境（如英文、中文、法文等）分离，通过桥接模式使得在切换不同语言环境时，仅需替换具体的本地化实现即可。

7. 硬件驱动程序：对于硬件设备（如打印机、扫描仪等），抽象接口可以定义一系列设备操作，而具体实现可以针对不同的厂商和型号。这样，即使更换了硬件设备，只要新设备遵循同一接口规范，应用也能无缝对接。

8. 支付系统：支付系统可能需要对接多种支付渠道（如支付宝、微信支付、银行卡支付等），并且每种支付渠道的操作流程各不相同。桥接模式可以将支付操作抽象化，而将具体支付渠道的处理逻辑放在各自的实现类中。

## 示例
```cpp
#include <iostream>

// 实现化角色接口
class Implementor {
public:
    virtual ~Implementor() {}
    virtual void operationImpl() = 0; // 定义操作接口
};

// 具体实现化角色A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorA 的 operationImpl()" << std::endl;
    }
};

// 具体实现化角色B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorB 的 operationImpl()" << std::endl;
    }
};

// 抽象化角色
class Abstraction {
protected:
    Implementor* _implementor;

public:
    Abstraction(Implementor* impl) : _implementor(impl) {}
    virtual ~Abstraction() { delete _implementor; }
    virtual void operation() = 0; // 定义抽象操作
};

// 具体抽象化角色
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void operation() override {
        std::cout << "RefinedAbstraction 调用 operation..." << std::endl;
        _implementor->operationImpl(); // 委托实现化角色执行操作
    }
};

int main() {
    Abstraction* absA = new RefinedAbstraction(new ConcreteImplementorA());
    absA->operation();

    Abstraction* absB = new RefinedAbstraction(new ConcreteImplementorB());
    absB->operation();

    delete absA;
    delete absB;

    return 0;
}
```
在这个例子中，Abstraction是抽象化角色，RefinedAbstraction是具体抽象化角色，Implementor是实现化角色接口，ConcreteImplementorA和ConcreteImplementorB是具体实现化角色。通过改变构造Abstraction时传入的Implementor的不同实现，我们可以轻松切换不同的行为方式。

1. 抽象化角色(Abstraction)：定义了抽象的操作operation()，但不提供具体实现。它通过维持一个指向Implementor的指针来间接使用其实现。
```cpp
class Abstraction {
protected:
    Implementor* _implementor;

public:
    // 构造函数接收一个Implementor对象的指针
    Abstraction(Implementor* impl) : _implementor(impl) {}
    virtual ~Abstraction() { delete _implementor; }

    // 定义抽象操作
    virtual void operation() = 0;
};
```
2. 具体抽象化角色(RefinedAbstraction)：继承自Abstraction，在operation()中调用了_implementor的operationImpl()方法，这样就把具体实现细节交给了实现化角色。\
```cpp
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    // 实现抽象操作，调用Implementor的实现
    void operation() override {
        std::cout << "RefinedAbstraction 调用 operation..." << std::endl;
        _implementor->operationImpl();
    }
};
```
3. 实现化角色(Implementor)：定义了所有实现类共有的接口operationImpl()，它是抽象化角色依赖的具体操作。
```cpp
class Implementor {
public:
    virtual ~Implementor() {}
    // 实现化角色的接口
    virtual void operationImpl() = 0;
};

```
4. 具体实现化角色(ConcreteImplementorA/B)：分别提供了operationImpl()的不同实现。
```cpp
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorA 的 operationImpl()" << std::endl;
    }
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() override {
        std::cout << "ConcreteImplementorB 的 operationImpl()" << std::endl;
    }
};
```

## 对比桥接模式 和 装饰者模式
桥接模式和装饰者模式都是结构型设计模式，但它们各自解决了不同的问题。桥接模式主要解决的是抽象和实现的耦合问题，而装饰者模式解决的是如何不通过继承就动态地扩展对象功能的问题。

### 目的不同
桥接模式的目的是将抽象与实现分离，以便它们可以独立变化。它主要用于处理当一个类存在两个或多个独立变化的维度时的情况。
装饰者模式的目的是在不改变对象接口的前提下，动态地给对象添加新的功能。它主要用于扩展功能，而不是分离抽象和实现。

### 结构不同
在桥接模式中，通常有两方使用抽象类或接口，一方持有另一方的引用。这有助于分离抽象和实现，使得它们可以独立变化。
装饰者模式中，装饰者和被装饰者通常实现相同的接口或继承自相同的基类。装饰者在其基类的基础上添加额外的功能。

### 使用场景不同：
桥接模式适用于当你想避免类爆炸问题，即想要独立地扩展抽象和实现时。它有助于管理复杂的继承关系。
装饰者模式适用于当你想在运行时动态地为对象添加新功能，而不想影响其他对象或使用继承的方式。
