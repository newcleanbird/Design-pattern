# State 状态模式
C++状态模式是一种行为设计模式，它允许对象在内部状态改变时改变其行为。这种模式通过将状态相关的行为封装在独立的类中，使得对象能够在运行时根据当前状态动态切换其行为，而不需要修改对象的代码。状态模式使得状态转换逻辑更加清晰，易于管理和扩展。

## 动机(Motivation)
+ 对象状态如果改变，其行为也会随之而发生变化，比如文档处于只读状态，其支持的行为和读写状态支持的行为就可能完全不同。
+ 如何在运行时根据对象的状态来透明地改变对象的行为？


## 模式定义
允许一个对象在其内部状态改变时改变它的行为。从而使对象看起来似乎修改了其行为。
——《设计模式》GoF

## 要点总结
+ State模式将所有与一个特定状态相关的行为都放入一个State的子对象中，在对象状态切换时，切换相应的对象；
但同时维持State的接口，这样实现了具体操作与状态转换之间的解耦。
+ 转换是原子性的
+ 与Strategy模式类似

## 深入理解状态模式
### 基本概念
1. Context（上下文）: 保存当前状态并定义一个接口以处理状态相关的操作。上下文并不直接处理请求，而是委托给当前状态对象。

2. State（状态接口）: 定义所有具体状态类共有的操作接口，使得上下文可以与任何状态对象交互。

3. Concrete State（具体状态）: 实现状态接口，每一个具体状态类对应上下文中的一种具体状态，负责实现与该状态相关的操作。

### 优点
1. 封装状态转换逻辑: 将状态转换的逻辑封装在状态类中，使得状态转换逻辑集中，易于理解和维护。

2. 易于扩展新状态: 添加新的状态只需定义一个新的状态类，修改上下文对新状态的引用即可，符合开闭原则。

3. 消除多分支判断: 通过状态对象来处理状态相关的逻辑，可以减少上下文中复杂的条件判断语句，使代码更加清晰。

4. 提高可读性和可维护性: 状态模式使得状态逻辑与上下文逻辑分离，每个状态类负责单一职责，便于阅读和维护。

### 注意事项
1. 状态类数量: 如果状态过多，会导致类的数量激增，增加设计的复杂度和维护成本。

2. 状态转换复杂性: 在状态转换逻辑复杂的情况下，状态类之间的关系可能变得难以管理，需要仔细设计状态转换规则。

3. 性能考量: 状态模式通过对象引用来实现状态切换，频繁的状态转换可能会有性能开销，特别是在性能敏感的应用中需要权衡。

### 深入理解
状态模式是面向对象设计中对“单一职责原则”和“开放封闭原则”的一种具体应用。它通过状态类的多态性，实现了行为的动态变化，体现了面向对象的灵活性和可扩展性。状态模式的精髓在于状态转换逻辑的集中管理，使得状态间的转换变得有序且易于控制。

### 适用情况
1. 状态转换频繁: 当一个对象的行为依赖于其状态，并且状态之间转换频繁时，状态模式可以有效管理这些状态和转换。

2. 复杂状态逻辑: 如果一个对象的行为逻辑基于多种条件分支，且这些条件分支难以管理或容易出错，状态模式可以通过状态类来简化逻辑。

3. 避免条件语句膨胀: 当大量的if-else或switch-case语句开始充斥代码，状态模式可以用来替代这些逻辑，提高代码的可读性和可维护性。

4. 状态影响行为: 对象的行为不仅依赖于其自身的数据，还依赖于其当前状态，且状态对行为的影响是动态变化的。

总的来说，状态模式在处理状态驱动的行为变化时非常有效，特别是在需要清晰地表示和管理这些状态及其转换的应用场景中。通过应用这一模式，可以显著提升代码的结构清晰度和可维护性。

### 面向对象特性的体现
1. 封装: 状态模式将状态相关的行为封装在独立的状态类中，隐藏了状态转换的具体实现细节。这样做，使得状态转换逻辑对外部环境透明，仅暴露必要的接口来触发状态变化。这不仅保护了内部数据，也使得状态转换逻辑易于修改和扩展。

2. 继承: 状态接口定义了一个通用的操作集合，所有具体状态类都继承自这个接口，实现这些操作。这种层次化的类结构利用了面向对象的继承机制，确保了所有状态对象都能响应相同的接口调用，同时也允许每个状态根据自身特点定制行为。

3. 多态: 上下文对象通过持有状态接口的引用，可以在运行时动态地切换到任何具体状态的实例，体现了多态性。这意味着，上下文无需知道当前状态的类型，就可以调用状态对象的方法，执行与当前状态相符的行为，大大提高了代码的灵活性和可扩展性。


### 独特设计思路和设计哲学
1. 行为与状态分离: 状态模式将状态和行为绑定在状态对象中，而将状态转换逻辑从上下文中分离出来，这体现了“单一职责原则”。每个状态类专注于处理与自己相关的行为，上下文则专注于维护状态和调用状态对象的方法。

2. 动态策略选择: 状态模式利用多态实现了策略模式中的动态策略选择思想，不同状态代表不同的策略。状态的切换意味着在运行时选择了不同的行为策略，这为程序提供了高度的动态性和可配置性。

3. 状态机抽象: 状态模式是面向对象实现状态机的一种方式，它将状态机的概念映射为类和对象，使得状态机的构建和维护更加直观和易于理解。每个状态转换可以视为一个对象到另一个对象的跳转，状态机的复杂性通过对象关系和交互来管理。

### 设计模式特点
1. 行为设计模式: 状态模式属于行为设计模式类别，专注于定义对象间的行为和职责分配，特别是如何在运行时改变对象的行为。

2. 开闭原则: 新状态的添加只需要增加新的具体状态类，而无需修改现有的状态类或上下文类，体现了对扩展开放、对修改关闭的原则。

3. 松耦合: 上下文和状态对象之间的关系是松耦合的，上下文不知道具体状态类的细节，仅通过抽象状态接口与状态交互。这有利于降低模块间的依赖，提高系统的可测试性和可维护性。

C++状态模式不仅是解决状态管理的有效手段，更是一种面向对象设计哲学的实践，它通过封装、继承和多态等机制，实现了行为的动态变化，体现了设计模式的诸多优点，如高内聚低耦合、易于扩展和维护等。

## 举例
以下是一个C++中实现状态模式的标准例子，我们将模拟一个简单的自动贩卖机系统，其中贩卖机可以根据不同的状态（比如正常工作、缺货、维修中等）表现出不同的行为（如接受硬币、分配商品、拒绝服务等）。
```cpp
#include <iostream>
#include <memory> // 引入智能指针的支持

// 售货机状态接口
class VendingMachineState {
public:
    virtual ~VendingMachineState() = default; // 添加虚析构函数，确保通过基类指针删除子类对象时能正确析构
    virtual void insertCoin() = 0;
    virtual void pressButton() = 0;
    virtual void dispenseItem() = 0;
    virtual void returnCoin() = 0;
};

// 具体状态类：无硬币
class NoCoinState : public VendingMachineState {
public:
    void insertCoin() override {
        std::cout << "Coin inserted." << std::endl;
    }
    void pressButton() override {
        std::cout << "Please insert a coin." << std::endl;
    }
    void dispenseItem() override {
        std::cout << "Please insert a coin." << std::endl;
    }
    void returnCoin() override {
        std::cout << "No coin to return." << std::endl;
    }
};

// 具体状态类：有硬币
class HasCoinState : public VendingMachineState {
public:
    void insertCoin() override {
        std::cout << "Coin already inserted." << std::endl;
    }
    void pressButton() override {
        std::cout << "Item dispensed." << std::endl;
    }
    void dispenseItem() override {
        std::cout << "Please press the button." << std::endl;
    }
    void returnCoin() override {
        std::cout << "Coin returned." << std::endl;
    }
};

// 上下文类：自动售货机
class VendingMachine {
private:
    std::unique_ptr<VendingMachineState> state; // 使用unique_ptr管理状态对象的生命周期

public:
    VendingMachine() : state(std::make_unique<NoCoinState>()) {} // 默认无硬币状态，使用make_unique初始化

    // 使用unique_ptr的转移语义设置新状态，避免显式delete
    void setState(std::unique_ptr<VendingMachineState> newState) {
        state = std::move(newState);
    }

    // 各个操作委托给当前状态对象处理
    void insertCoin() { state->insertCoin(); }
    void pressButton() { state->pressButton(); }
    void dispenseItem() { state->dispenseItem(); }
    void returnCoin() { state->returnCoin(); }

    // 智能指针会在VendingMachine销毁时自动释放状态对象资源
};

int main() {
    VendingMachine vendingMachine;

    vendingMachine.insertCoin();   // 输出: Coin inserted.
    vendingMachine.pressButton();  // 输出: Please insert a coin.

    // 动态创建并设置新状态，利用智能指针管理生命周期
    vendingMachine.setState(std::make_unique<HasCoinState>());

    vendingMachine.pressButton();  // 输出: Item dispensed.
    vendingMachine.returnCoin();   // 输出: Coin returned.

    return 0;
}
```
