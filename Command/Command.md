# Command 命令模式
命令模式（Command Pattern）是一种行为设计模式，它将请求封装成对象，以便参数化对象、延迟执行、记录请求日志、支持可撤销操作等。在C++中，命令模式通过定义一个命令接口，以及实现这个接口的具体命令类来实现。每个具体命令类封装了一个请求，包括接收者（Receiver）的信息和需要执行的操作。

## 动机(Motivation)
+ ”行为请求者“与”行为实现者“通常呈现一种”紧耦合“。但在某些场合——比如需要对行为进行”记录、撤销、事务“等处理，这种无法抵御变化的紧耦合是不合适的。
+ 在这种情况下，如何将”行为请求者“与”行为实现者“解耦？将一组行为抽象为对象，可以实现二者之间的松耦合。

## 模式定义
将一个请求(行为)封装成一个对象，从而使你可用不同的请求对客户进行参数化；对请求排队或记录请求日志，以及支持可撤销的操作。
——《设计模式》GoF

## 要点总结
+ Command模式的根本目的在于将”行为请求者“与”行为实现者“解耦，在面向对象语言中，常见的实现手段是”将行为抽象为对象“。
+ 与C++中的函数对象类似，C++函数对象以函数签名来定义行为接口规范，更灵活性能更高。

## C++命令模式详解
### 核心组成部分：
1. Command接口：定义执行操作的接口，通常有一个execute()方法。
2. Concrete Command类：实现Command接口，包含对Receiver的引用，并实现具体的execute()方法。
3. Receiver类：真正执行操作的类，包含与执行命令相关的业务逻辑。
4. Invoker类：请求的发起者，持有Command对象的引用，调用execute()方法来执行命令。Invoker不关心具体的命令是如何被执行的。

### 优点：
1. 解耦：命令模式将请求的发送者和接收者解耦，使得两者不直接依赖，有利于系统的维护和扩展。
2. 扩展性：容易添加新的命令，只需要实现Command接口即可。
3. 灵活性：支持命令的参数化，可以方便地改变命令的执行方式，比如队列执行、日志记录、撤销/重做等。
4. 可控制性：可以集中控制命令的执行，比如批量处理、事务管理等。

### 注意事项：
1. 类爆炸问题：如果命令类型过多，可能会导致大量的具体命令类，增加了系统的复杂度。
2. 性能考量：频繁创建和销毁命令对象可能影响性能，特别是在命令对象较重或执行频率高的场景下。
3. 设计复杂度：对于复杂的命令模式实现，如支持撤销操作，设计和维护的难度会增加。
4. 职责清晰：确保每个命令类的职责单一，避免命令类变得过于庞大和复杂。

### 深入理解：
命令模式不仅是一种简单的请求封装方式，更是面向对象设计原则的体现，如单一职责原则、开放封闭原则和里氏替换原则等。它通过引入命令对象这一中介，实现了调用者和接收者之间的松耦合，使得系统设计更加灵活和可扩展。此外，命令模式还支持命令的存储和复用，这对于需要实现宏命令、事务处理、回滚机制等功能的系统尤为重要。

### 适用情况：
1. 需要支持撤销/重做操作的场景：例如文本编辑器、图形编辑软件等。
2. 需要将请求排队或记录日志：如任务调度系统、订单处理系统。
3. 需要对请求进行参数化处理：使得相同的接收者可以执行不同的操作，或不同的接收者执行相同的操作。
4. 需要支持命令的动态组合：比如游戏中的技能组合，通过组合不同的命令对象实现复杂的技能效果。

### 面向对象特性的体现
1. 封装：命令模式的核心在于将发出请求的动作（命令）和执行动作的逻辑封装到命令对象中。这种封装不仅隐藏了具体操作的实现细节，还允许客户端代码和请求的处理逻辑相互独立，降低了系统的耦合度。

2. 多态：通过定义抽象命令接口或抽象基类，以及具体命令类继承并实现该接口，命令模式利用多态性使得调用者能够以统一的方式处理不同类型的命令，而无需知道具体的实现细节。这样，新命令的添加不会影响到现有的客户端代码。

3. 继承：在命令模式中，具体命令类通常会继承自一个抽象命令类或实现一个命令接口，这不仅促进了代码的复用，也使得系统结构更加清晰，易于理解。

### 独特设计思路与哲学
1. 分离关注点：命令模式通过将请求的发起与请求的执行分离，体现了“单一职责原则”。这种分离使得系统的设计更加模块化，易于维护和扩展。

2. 灵活性与可扩展性：由于命令对象是独立的实体，可以轻松添加、修改或移除命令，而不影响到系统其它部分，为系统的动态配置和行为变化提供了可能。

3. 支持复杂操作组合：命令模式天然支持命令的组合，可以通过组合命令来实现宏命令或事务处理，进一步增强系统的功能和灵活性。

4. 易于控制与追踪：命令对象可以存储在队列中，支持延迟执行、撤销操作等功能，使得系统操作易于控制和追踪，提升了系统的可控性和健壮性。

体现的设计模式特点
行为模式：作为行为设计模式，命令模式关注的是对象之间的交互，以及如何在运行时动态改变对象的行为，而非对象的创建。

松耦合：通过引入命令对象作为中介，实现了请求发送者和接收者的解耦，提高了系统的灵活性和可维护性。

可撤销操作：命令模式易于实现撤销操作，因为每个命令都是一个独立的实体，可以通过记录命令历史来支持回退操作。

代码复用：通过继承和多态，命令模式鼓励代码复用，减少重复代码，使得系统更加整洁和高效。


## 示例
将创建一个简单的遥控器控制系统，该系统可以控制电灯的开关。在这个例子中，命令模式将用于封装电灯的开关操作，使得遥控器可以控制这些操作，同时支持动态添加新的命令。
```cpp
#include<iostream>

// Receiver类 知道如何实施与执行一个与请求相关的操作，任何类都可能作为一个接收者
class Light {
public:
    void turnOn() const {
        std::cout << "Light is on" << std::endl;
    }
    void turnOff() const {
        std::cout << "Light is off" << std::endl;
    }
};
// Command类，用来声明执行操作的接口
class Command {
protected:
    Light* light;
public:
    virtual ~Command() {}
    virtual void execute() const = 0;
    Command(Light* light) : light(light){}
};

// ConcreteCommand类 将一个接收者对象绑定于一个动作 调用接收者相应的操作 以实现Execute
class LightOnCommand : public Command {
public:
    LightOnCommand(Light* light) : Command(light) {}
    void execute() const override {
        light->turnOn();
    }
};

class LightOffCommand : public Command {
private:
    Light* light;
public:
    LightOffCommand(Light* light) : Command(light) {}
    void execute() const override {
        light->turnOff();
    }
};

//Invoker类，要求该命令执行这个请求
class RemoteControl {
private:
    Command* slot;
public:
    void setCommand(Command* command) {
        this->slot = command;
    }
    void buttonPressed() const {
        if (slot != nullptr) {
            slot->execute();
        }
    }
};

int main() {
    Light livingRoomLight;
    Command* livingRoomLightOn = new LightOnCommand(&livingRoomLight);
    Command* livingRoomLightOff = new LightOffCommand(&livingRoomLight);

    RemoteControl remoteControl;

    // 设置打开电灯的命令
    remoteControl.setCommand(livingRoomLightOn);
    // 按下遥控器按钮
    remoteControl.buttonPressed();  // 输出: Light is on

    // 设置关闭电灯的命令
    remoteControl.setCommand(livingRoomLightOff);
    // 再次按下遥控器按钮
    remoteControl.buttonPressed();  // 输出: Light is off

    delete livingRoomLightOn;
    delete livingRoomLightOff;

    return 0;
}
```

