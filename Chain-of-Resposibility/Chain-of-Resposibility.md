# Chain of Resposibility 职责链模式
职责链模式（Chain of Responsibility Pattern）是一种行为设计模式，它允许将请求沿着处理者链条传递，直到找到一个能够处理该请求的处理者。在C++中，这种模式通常通过定义一系列具有相似接口的类来实现，这些类可以相互链接，形成一个请求处理链。

## 动机(Motivation)
+ 一个请求可能被多个对象处理，但是每个请求在运行时只能有一个接收者，如果显式指定，将必不可少地带来请求发送者与接收者的紧耦合。
+ 如何使请求的发送者不需要指定具体的接收者？让请求的接收者自己在运行时决定来处理请求，从而使两者解耦。

## 模式定义
使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链，并沿着这条链传递请求，直到有一个对象处理它为止。
——《设计模式》GoF

## 要点总结
+ 应用于”一个请求可能有多个接受者，但是最后真正的接受者只有一个“，这时候请求发送者与接受者有可能出现”变化脆弱“的症状，职责链解耦。
+ 有些过时。

## C++职责链模式详解
### 关键组成部分
1. Handler（处理器接口）: 定义了处理请求的接口，一般包括处理请求的方法（如handleRequest）和设置下一个处理器的方法（如setNext）。

2. Concrete Handler（具体处理器）: 实现处理器接口，负责处理或传递请求。具体处理器可以决定是否处理请求，如果不能处理，则将其传递给链中的下一个处理器。

3. Client（客户端）: 创建处理器链，并向链中的第一个处理器提交请求。客户端不需要知道请求最终由哪个处理器处理。

### 优点
1. 解耦: 通过将请求的发送者和接收者解耦，职责链模式使得两者都不需要知道对方的细节，增加了系统的灵活性和可扩展性。

2. 灵活性和可扩展性: 可以在运行时动态地添加或修改处理器，而不需要修改客户端代码。

3. 简化对象间的交互: 请求的传递和处理过程对客户端透明，简化了对象之间的交互逻辑。

### 注意事项
1. 避免过长的责任链: 过多的处理器会导致链路过长，增加处理请求的复杂度和时间成本，也使得调试和维护变得更加困难。

2. 明确终止条件: 必须确保链中的某个处理器能处理请求，或者设定一个默认处理器来处理未被其他处理器处理的请求，避免请求在链中无限循环。

3. 处理器间的依赖关系: 尽管职责链模式减少了对象之间的直接依赖，但在设计时仍需注意处理器间的逻辑顺序和依赖关系，避免造成不必要的复杂度。

### 深入理解
职责链模式强调了职责的分配与传递，体现了面向对象设计中的“单一职责原则”，即每个处理器只负责处理自己能处理的请求，不知道也不关心请求的后续处理者。此外，它也是“开放封闭原则”的一种实践，允许在不修改现有类的基础上添加新的处理器类，以应对新的请求类型。

### 适用于以下情况
1. 多个对象可以处理同一请求: 当存在多个对象都能处理某一请求，但具体由哪个对象处理取决于运行时条件时，职责链模式尤为有用。

2. 动态决定处理者: 如果处理请求的对象需要在运行时动态指定，而不是在编译时固定，职责链模式提供了一种灵活的解决方案。

3. 简化对象间的直接通信: 当直接指定请求的处理者会使系统过于复杂或难以维护时，通过职责链模式可以减少对象间的直接耦合。

4. 处理流程灵活多变: 对于那些处理流程可能经常变化的系统，职责链模式允许通过添加、修改或重新排列处理器来快速适应变化。

### 面向对象特性的体现
1. 封装: 职责链模式通过抽象处理器接口封装了请求处理的逻辑，使得请求的发送者和具体处理者之间不需要直接交互，从而降低了系统的耦合度。

2. 多态: 利用C++的多态性，具体处理器类可以重写抽象处理器类的请求处理方法，这使得在运行时可以根据具体情况动态决定由哪个处理器处理请求，增强了系统的灵活性。

3. 继承与组合: 通过继承实现处理器的层次结构，而组合则是构建责任链的关键，每个处理器持有对其下一个处理器的引用，形成了一个链式结构。这体现了继承和组合两种构造复杂对象的手段。

### 独特设计思路
1. 责任委派: 核心思想在于将请求的处理责任从发送端转移到一系列的处理对象中，每个对象都有机会处理请求，但也有权拒绝处理并将责任传递给链中的下一个对象。这种委派机制允许请求在多个对象间流动，直到被恰当处理。

2. 动态配置: 责任链可以在运行时动态构建，这意味着可以根据不同的业务需求或运行时环境调整处理链的结构，增加了系统的可配置性和适应性。

### 设计哲学
1. 关注点分离: 通过将请求的发送和处理分开，职责链模式强化了单一职责原则，让每个对象专注于自己的功能，而不需要了解请求的完整处理流程。

2. 开放封闭原则: 系统设计为对扩展开放，对修改封闭。新加入的处理器或更改处理逻辑只需添加新的具体处理器类或修改已有类，而不需要改动客户端代码或基础架构。

### 设计模式特点
1. 行为模式: 作为一种行为模式，职责链关注的是对象之间的动态交互，如何分配和组织责任，以实现特定的行为或结果。

2. 可替换性: 在链中，相同接口的不同具体处理器可以互换，这不仅提高了代码的复用性，也为系统提供了多样化的处理策略选择。

3. 松耦合: 通过接口而非具体类进行编程，使得责任链的各个部分高度解耦，易于维护和扩展。

## 例子
以一个简单的日志记录系统为例，展示如何根据不同日志级别（如DEBUG, INFO, WARNING, ERROR）将日志记录任务分配给不同的处理器。
```cpp
#include <iostream>
#include <string>

enum class LogLevel { DEBUG, INFO, WARNING, ERROR };    // 枚举日志级别

// 抽象处理器类
class LogHandler {
public:
    LogHandler(LogHandler* next = nullptr) : nextHandler(next) {}
    virtual ~LogHandler() = default;

    virtual void logMessage(LogLevel level, const std::string& message) = 0;

protected:
    LogHandler* nextHandler;
};

// 具体处理器类
class DebugLogHandler : public LogHandler {
public:
    DebugLogHandler(LogHandler* next = nullptr) : LogHandler(next) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level == LogLevel::DEBUG) {
            std::cout << "DEBUG: " << message << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->logMessage(level, message);
        }
    }
};

class InfoLogHandler : public LogHandler {
public:
    InfoLogHandler(LogHandler* next = nullptr) : LogHandler(next) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level == LogLevel::INFO) {
            std::cout << "INFO: " << message << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->logMessage(level, message);
        }
    }
};

class WarningLogHandler : public LogHandler {
public:
    WarningLogHandler(LogHandler* next = nullptr) : LogHandler(next) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level == LogLevel::WARNING) {
            std::cout << "WARNING: " << message << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->logMessage(level, message);
        }
    }
};

class ErrorLogHandler : public LogHandler {
public:
    ErrorLogHandler(LogHandler* next = nullptr) : LogHandler(next) {}

    void logMessage(LogLevel level, const std::string& message) override {
        if (level == LogLevel::ERROR) {
            std::cout << "ERROR: " << message << std::endl;
        } else if (nextHandler != nullptr) {
            nextHandler->logMessage(level, message);
        }
    }
};

int main() {
    // 构建职责链
    LogHandler* logger = new ErrorLogHandler(new WarningLogHandler(new InfoLogHandler(new DebugLogHandler(nullptr))));

    // 记录不同级别的日志
    logger->logMessage(LogLevel::DEBUG, "This is a debug message");
    logger->logMessage(LogLevel::INFO, "This is an info message");
    logger->logMessage(LogLevel::WARNING, "This is a warning message");
    logger->logMessage(LogLevel::ERROR, "This is an error message");

    // 清理内存
    delete logger;

    return 0;
}
```
在这个例子中，每个日志处理器类（DebugLogHandler, InfoLogHandler, WarningLogHandler, ErrorLogHandler）都实现了LogHandler接口，并且只有当接收到对应级别的日志时才会处理该日志，否则将日志传递给链中的下一个处理器。通过这样的设计，我们实现了日志处理的解耦和灵活配置。