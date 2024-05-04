# Abstract Factory 抽象工厂模式 / 家族工厂模式
C++抽象工厂模式是一种创建型设计模式，其核心思想是提供一个接口用于创建一系列相关或相互依赖的对象，而无需指定它们的具体类。这个模式通过将系统中的一组产品对象家族统一到一起，使得客户端可以只依赖于抽象接口编程，而不必关心具体产品的创建细节。抽象工厂模式不仅能够管理产品的创建，还能处理产品族内部的关联关系，增加了系统的灵活性和可扩展性。

## 动机(motivation)
+ 在软件系统中，经常面临着“一系列相互依赖的对象工作”；同时，由于需求的变化，往往存在更多系列对象的创建工作。
+ 如何应对这种变化？如何绕过常规的对象创建方法(new)，提供一种“封装机制”来避免客户程序和这种“多系列具体对象创建工作”的紧耦合。

## 模式定义
提供一个接口，让该接口负责创建一系列”相关或者相互依赖的对象“，无需指定它们具体的类。
——《设计模式》GoF

## 要点总结
+ 如果没有应对”多系列对象创建“的需求变化，则没有必要使用Abstract Factory模式，这时候使用简单的工厂即可。
+ ”系列对象“指的是在某一个特定系列的对象之间有相互依赖、或作用的关系。不同系列的对象之间不能相互依赖。
+ Abstract Factory模式主要在于应用”新系列“的需求变动。其缺点在与难以应对”新对象“的需求变动。

## 主要参与者角色
1. 抽象工厂（Abstract Factory）：声明创建一系列产品对象的接口，但并不负责具体产品的创建。
2. 具体工厂（Concrete Factory）：实现抽象工厂接口，负责创建具体的产品对象。
3. 抽象产品（Abstract Product）：定义产品对象的接口，所有具体产品必须实现。
4. 具体产品（Concrete Product）：具体产品类，实现抽象产品接口，由具体工厂创建。

## 优点
1. 隔离具体类的耦合：客户端仅与抽象接口交互，减少了对具体类的依赖，易于更换产品系列。
2. 易于扩展：新增产品线或产品种类时，只需要增加新的具体工厂和产品类，不影响已有的代码结构。
3. 提供一致性接口：确保一系列相关产品的创建操作具有一致性，便于维护和理解。
4. 促进松耦合：通过抽象接口编程，促进模块间的松耦合，提高系统的灵活性。

## 注意事项
1. 过度设计风险：对于简单的系统，引入抽象工厂可能会导致不必要的复杂度。
2. 难以支持新种类：如果需要添加一个新的产品，但不属于任何现有的产品族，则可能需要修改抽象工厂接口。
3. 配置管理：随着具体工厂和产品的增多，管理这些类的实例化和选择可能会变得复杂。
4. 性能考量：由于使用了多层抽象，可能会有轻微的性能损失。

## 适用情况
1. 当系统需要独立于如何创建、组合和表示它的组成部分时。
2. 一个系统要独立于其产品的创建、组合和表示时，以便可以使用不同的产品系列。
3. 当要强调一系列相关产品的整体约束时，即产品族的概念很重要。
4. 需要在运行时决定具体产品的类型时，但这些产品属于同一产品族。

## 深入理解抽象工厂方法
抽象工厂模式不仅是面向对象编程原则的综合应用，也是设计模式中高内聚、低耦合原则的典范，它通过提供一个高层次的抽象，使得系统能够更好地适应变化，满足复杂多变的需求。
### 面向对象特性体现
1. 封装：抽象工厂模式通过接口或抽象类来定义产品的创建过程，隐藏了具体产品的创建细节，从而实现了生产过程的封装。这使得客户端无需了解产品的具体实现，降低了模块间的耦合度。

2. 继承：具体工厂类继承自抽象工厂接口或抽象类，通过继承实现了接口的多态性，使得具体工厂能够根据需要创建不同的产品族。同时，具体产品类也会继承自抽象产品接口或基类，确保了产品之间的兼容性和互换性。

3. 多态：客户端通过抽象接口引用具体工厂和产品，这意味着在运行时可以根据具体需求动态地创建和使用不同类型的对象，而无需修改客户端代码。这是多态性的直接体现，也是抽象工厂模式灵活性的来源。

### 独特设计思路
1. 产品族概念：抽象工厂模式独特之处在于它关注的不是单一产品，而是一系列相关或相互依赖的产品族。这种设计允许系统按产品族来组织和创建对象，非常适合那些需要处理多个产品系列的场景。

2. 分离接口与实现：通过定义抽象接口来规范产品和工厂的行为，将接口定义与具体实现分离，使得系统设计更加灵活，易于扩展和维护。

3. 配置灵活性：抽象工厂模式通过配置不同的具体工厂，可以在运行时动态改变产品族的选择，为系统配置提供了极大的灵活性。

### 设计模式特点体现
1. 开放封闭原则：抽象工厂模式允许在不修改现有代码的情况下，通过添加新的具体工厂和产品类来扩展系统功能，体现了对扩展开放，对修改封闭的原则。

2. 里氏替换原则：具体工厂和产品类作为抽象工厂和抽象产品的子类，应当能够替换父类而不影响系统的正确性，确保了设计的稳定性。

3. 依赖倒置原则：客户端依赖于抽象接口而不是具体类，使得抽象工厂模式鼓励依赖于抽象，而非具体实现，这是良好设计的重要标志。

4. 单一职责原则：每个工厂专注于创建一个产品族内的对象，避免了职责扩散，使得代码更加清晰，易于管理和维护。

## 例子
下面是一个C++中实现抽象工厂模式的标准示例。在这个例子中，我们将创建一个界面库，其中包含两种主题（LightTheme和DarkTheme）以及两种按钮（TextButton和ImageButton）。抽象工厂负责生产这些界面元素。

```cpp
#include <iostream>

/*首先，定义抽象产品接口*/

// 抽象产品：主题接口
class Theme {
public:
    virtual ~Theme() {}
    virtual void apply() const = 0;
};

// 抽象产品：按钮接口
class Button {
public:
    virtual ~Button() {}
    virtual void display() const = 0;
};

/*然后，定义具体产品*/

// 具体产品：浅色主题
class LightTheme : public Theme {
public:
    void apply() const override {
        std::cout << "Applying Light Theme" << std::endl;
    }
};

// 具体产品：深色主题
class DarkTheme : public Theme {
public:
    void apply() const override {
        std::cout << "Applying Dark Theme" << std::endl;
    }
};

// 具体产品：文本按钮
class TextButton : public Button {
public:
    void display() const override {
        std::cout << "Displaying Text Button" << std::endl;
    }
};

// 具体产品：图像按钮
class ImageButton : public Button {
public:
    void display() const override {
        std::cout << "Displaying Image Button" << std::endl;
    }
};

/*接下来，定义抽象工厂接口和具体工厂*/

// 抽象工厂
class GUIFactory {
public:
    virtual ~GUIFactory() {}
    virtual std::unique_ptr<Theme> createTheme() const = 0;
    virtual std::unique_ptr<Button> createButton() const = 0;
};

// 具体工厂：浅色主题工厂
class LightThemeFactory : public GUIFactory {
public:
    std::unique_ptr<Theme> createTheme() const override {
        return std::make_unique<LightTheme>();
    }
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<TextButton>();
    }
};

// 具体工厂：深色主题工厂
class DarkThemeFactory : public GUIFactory {
public:
    std::unique_ptr<Theme> createTheme() const override {
        return std::make_unique<DarkTheme>();
    }
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<ImageButton>();
    }
};

/*最后，客户端代码使用抽象工厂来创建界面元素*/

int main() {
    std::unique_ptr<GUIFactory> lightFactory = std::make_unique<LightThemeFactory>();
    std::unique_ptr<GUIFactory> darkFactory = std::make_unique<DarkThemeFactory>();

    // 使用工厂创建界面元素并展示
    auto lightTheme = lightFactory->createTheme();
    lightTheme->apply();
    auto lightButton = lightFactory->createButton();
    lightButton->display();

    auto darkTheme = darkFactory->createTheme();
    darkTheme->apply();
    auto darkButton = darkFactory->createButton();
    darkButton->display();

    return 0;
}
```
这个例子展示了如何使用抽象工厂模式来创建一系列相关的对象，而无需知道具体的类。如果要添加新的主题或按钮类型，只需增加新的具体产品类和对应的工厂类，既不会影响现有的代码，也符合开闭原则。