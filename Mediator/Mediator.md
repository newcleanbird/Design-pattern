# Mediator 中介者模式
也称协调者模式，调停者模式
C++中介者模式（Mediator Pattern）是一种行为设计模式，它通过定义一个中介类来封装一组对象之间的交互，从而使得这些对象不必直接引用彼此。中介者模式降低了系统的耦合度，使得各个对象可以独立地改变它们之间的交互，而不需要修改对象自身，提高了系统的可维护性和灵活性。

## 动机(Motivation)
+ 多个对象相互关联的情况，对象之间常常会维持一种复杂的引用关系，如果遇到一些需求的更改，这种直接的引用关系将面临不断的变化。
+ 在这种情况下，可以使用一种”中介对象“来管理对象间的关联关系，避免相互交互的对象之间的紧耦合引用关系，从而更好地抵御变化。

## 模式定义
用一个中介对象来封装(封装变化)一系列的对象交互。中介者使各对象不需要显式的相互引用(编译时依赖->运行时依赖)，
从而使其耦合松散(管理变化)，并且可以独立地改变它们之间的交互。
——《设计模式》GoF

## 要点总结
+ 将多个对象间发杂的关联关系解耦
+ Facade模式是解耦系统间(单向)的对象关联关系；Mediator模式是解耦系统内各个对象之间(双向)的关联关系。

## 深入理解中介者模式
### 基本概念
1. 中介者（Mediator）: 提供一个统一的接口，用于各个具体同事对象之间的通信。中介者不关心具体的同事对象，只负责协调它们之间的交互。

2. 同事（Colleague）: 知道中介者并且与其通信的类。每个同事都有一份对中介者的引用，用于在需要与其他同事通信时通知中介者。

### 优点
1. 降低耦合性: 同事类之间不直接互相引用，而是通过中介者进行通信，减少了对象间的直接依赖，使得系统更易于修改和扩展。

2. 简化对象间的关系: 中介者封装了复杂交互逻辑，使得各个同事对象可以专注于自己的职责，而不必了解系统的全局结构。

3. 集中控制交互: 通过集中管理对象间的交互，可以更容易地控制系统的复杂性，尤其是在交互模式复杂多变的场景下。

4. 提高可重用性和灵活性: 中介者模式使得同事对象可以独立于彼此变化，可以单独复用或修改任何一个同事，而不会影响到其他对象。

### 注意事项
1. 中介者可能变得复杂: 当系统中的同事数量增多，或者同事之间的交互逻辑复杂时，中介者类可能会变得庞大且难以维护。

2. 过度集中: 如果过度集中控制在中介者中，可能会导致中介者成为系统的瓶颈，影响系统的扩展性和灵活性。

3. 设计决策: 需要权衡何时使用中介者模式，避免在简单交互场景中过度设计，引入不必要的复杂度。

### 深入理解
中介者模式体现了面向对象设计中的“单一职责原则”和“迪米特法则”。它通过将交互逻辑集中化，使得各个同事对象保持简单的职责，同时减少了对象之间的直接联系，符合迪米特法则的“最少知识原则”。

### 适用情况
1. 复杂交互系统: 当多个对象之间存在复杂的相互作用，直接耦合会导致系统难以理解和维护时，中介者模式可以有效分离和管理这些交互。

2. 解耦合需求: 当需要频繁更改对象之间的交互方式，而又不想影响到对象本身的结构时，中介者模式提供了一种灵活的解耦方案。

3. 系统重构: 在重构既有系统，尤其是那些因为对象间过度耦合而难以维护的系统时，中介者模式可以帮助理清对象间的依赖关系，简化设计。

4. 用户界面设计: 在图形用户界面设计中，中介者模式常用于管理多个UI组件之间的交互，如对话框、按钮、列表等，保持界面逻辑清晰。

总之，中介者模式是处理复杂交互关系的强大工具，它通过引入一个中心协调者来降低系统的耦合度，但设计时需要谨慎考虑其适用场景，避免过度设计带来的复杂性。

### 面向对象特性的体现
1. 封装：中介者模式通过将对象间的交互逻辑封装在一个中介者对象中，实现了交互细节的隐藏，使得各个同事对象不需要知道彼此的具体实现细节，只与中介者交互。这是面向对象封装原则的直接体现，有助于提高模块的独立性和可维护性。

2. 多态：在实现中介者模式时，通常会定义一个抽象的中介者接口和具体的中介者类，以及抽象的同事接口和具体同事类。这种设计允许在运行时根据具体需要动态替换不同的中介者或同事，体现了面向对象的多态性，增加了系统的灵活性和可扩展性。

3. 抽象与接口：中介者模式强调通过接口而非实现进行编程，每个同事只知道中介者的接口而不关心其实现，这遵循了面向对象设计中的“针对接口编程，而不是针对实现编程”的原则，促进了松耦合的设计。

### 独特设计思路和哲学
1. 集中控制与分散实现：中介者模式体现了“集中控制，分散实现”的设计理念。它通过一个中心点（中介者）集中管理多个对象间的交互逻辑，而各个同事对象则专注于自身的业务逻辑实现，这样的设计既保证了交互的一致性，又保持了系统的灵活性和可扩展性。

2. 解耦与协作：中介者模式的核心价值在于解耦。它通过将对象间的直接依赖转变为对中介者的依赖，大大降低了系统的耦合度，使得同事对象可以独立变化，同时又通过中介者保证了它们之间的协作。

### 设计模式特点
1. 行为模式：中介者模式属于行为设计模式，主要关注对象间责任的分配和通信方式，通过定义一个中介者来封装多个对象间的交互，使对象间的耦合度降低，提高系统的可维护性和灵活性。

2. 松耦合：中介者模式通过引入中介者作为通信的中间人，实现了同事间的松耦合，使得系统中的对象可以独立发展和演化，减少修改一处影响多处的问题。

3. 关注点分离：该模式强制分离了对象的交互逻辑和业务逻辑，使得每个对象可以专注于自己的核心职责，符合“单一职责原则”，提升了代码的可读性和可维护性。

### 总结
中介者模式在面向对象设计中扮演着“协调者”角色，它不仅仅是一种技术上的解决方案，更是一种设计哲学的实践，强调了如何通过合理的职责分配和通信模式设计来提高系统的灵活性和可维护性。在面对对象间复杂交互设计挑战时，中介者模式提供了一种清晰、可控的解决方案，体现了面向对象设计的精髓。

## 例子
以下是一个C++中实现中介者模式的简单例子，我们将模拟一个聊天室场景，其中用户（User）通过聊天室（ChatRoom，充当中介者）发送和接收消息，而不是直接与其他用户通信。
```cpp
// 抽象类定义
// 首先，定义用户（User）和中介者（Mediator）的抽象接口。

#include <iostream>
#include <vector>

// 抽象中介者类
class Mediator {
public:
    virtual ~Mediator() {}
    virtual void sendMessage(const std::string& message, User* user) = 0;
};

// 抽象用户类
class User {
protected:
    Mediator* mediator;
    std::string name;
public:
    User(Mediator* mediator, const std::string& name) : mediator(mediator), name(name) {}
    virtual ~User() {}
    virtual void receiveMessage(const std::string& message) = 0;
    void sendMessage(const std::string& message) {
        mediator->sendMessage(message, this);
    }
};

// 具体实现
// 接着，实现聊天室（ConcreteMediator）和用户（ConcreteUser）的类。

class ConcreteMediator : public Mediator {
private:
    std::vector<User*> users;
public:
    void addUser(User* user) {
        users.push_back(user);
    }
    void sendMessage(const std::string& message, User* user) override {
        for (User* u : users) {
            if (u != user) {
                u->receiveMessage(message);
            }
        }
    }
};

class ConcreteUser : public User {
public:
    ConcreteUser(Mediator* mediator, const std::string& name) : User(mediator, name) {}
    void receiveMessage(const std::string& message) override {
        std::cout << name << " received message: " << message << std::endl;
    }
};

// 客户端代码
// 最后，客户端代码创建聊天室和用户，并通过聊天室发送消息。

int main() {
    ConcreteMediator chatRoom;
    ConcreteUser alice(&chatRoom, "Alice");
    ConcreteUser bob(&chatRoom, "Bob");

    chatRoom.addUser(&alice);
    chatRoom.addUser(&bob);

    alice.sendMessage("Hello, Bob!");
    bob.sendMessage("Hi Alice!");

    return 0;
}
```
在这个例子中，ConcreteMediator作为中介者，负责接收来自用户的请求并转发给其他用户，而ConcreteUser类的实例（代表聊天室中的用户）仅需与中介者交互，无需直接与其他用户通信。这样，当添加新的用户或者改变消息传递逻辑时，只需修改中介者类，而用户类保持不变，展示了中介者模式的解耦优势。
