# Memento(备忘录) 备忘录模式
备忘录模式（Memento Pattern）是一种行为设计模式，用于在不破坏封装性的前提下，捕获并存储一个对象的内部状态，以便在未来需要时恢复到该状态。此模式特别适用于需要实现撤销操作或保存/恢复状态的场景，如文本编辑器的撤销功能、游戏存档、交易事务的回滚等。

主要是实现信息隐藏。
如今已经很少使用备忘录模式，目前采用序列化、编码方式。

## 动机(Motivation)
+ 某些对象的状态转换过程中，可能由于某中需要，要求程序能够回溯到对象之前处于某个点的状态。
如果使用一些公开接口来让其他对象得到对象的状态，便会暴露对象的细节实现。
+ 如何实现对象状态的良好保存与恢复？但同时又不会因此而破坏对象本身的封装性、

## 模式定义
在不破坏封装性的前提下，捕获一个对象的内部状态，并在该对象之外保存这个状态。这样以后就可以将该对象恢复到原先保存的状态。
——《设计模式》GoF

## 要点总结
+ 备忘录存储原发器(Originator)对象的内部状态，在需要时恢复原发器状态。
+ 有些过时。


## C++备忘录模式详解
### 关键参与者
1. Originator（发起人）: 负责创建一个备忘录（Memento）对象，用来存储其当前状态；同时，提供方法来恢复到备忘录所保存的状态。

2. Memento（备忘录）: 一个简单的数据结构，用于存储Originator对象的内部状态。为了保护Originator的封装性，Memento通常被设计为不可直接访问其内部状态的外部类，除了Originator本身（通过友元类或特定的访问方法）。

3. Caretaker（管理者/看管者）: 负责保存和提供备忘录对象，但不关心备忘录的内容。Caretaker可以管理多个备忘录，但它不会也不应该直接读取备忘录的数据，仅作为存储容器。

### 优点
1. 状态恢复: 提供了一种简单的方式来恢复对象到先前的状态，支持撤销操作。
2. 封装性: 通过限制对备忘录数据的访问，保持了Originator的内部状态的封装。
3. 灵活性和扩展性: 可以轻松添加新的备忘录类型或改变备忘录的存储策略，而不影响到其他部分。

### 注意事项
1. 内存消耗: 如果备忘录保存大量状态或者频繁创建，可能会导致较高的内存消耗。
2. 状态管理: 必须谨慎管理备忘录的生命周期，避免无用的备忘录占用资源。
3. 设计复杂度: 在某些情况下，如果状态逻辑过于复杂，备忘录模式的设计和实现也会随之复杂化。

### 深入理解
备忘录模式体现了面向对象设计中一个重要原则：关注点分离。它将状态的保存和恢复逻辑从业务逻辑中解耦，使得状态的管理更加灵活且易于维护。此外，备忘录模式通过限制状态的访问权限，强化了封装原则，保证了对象内部状态的私密性。

### 适用情况
1. 撤销/重做功能: 如文本编辑器、绘图软件中的撤销操作。
2. 游戏存档: 记录玩家进度，以便随时加载。
3. 事务管理: 支持事务的回滚操作，确保数据一致性。
4. 配置管理: 保存和恢复应用程序的配置状态。
总之，备忘录模式是一种强大的工具，它允许我们在不破坏对象封装的前提下，灵活地管理对象的状态历史，对于需要实现状态恢复功能的场景尤其有效。然而，设计和使用时需要权衡状态保存的成本和复杂度，确保其带来的好处超过潜在的资源消耗和实现难度。

### 面向对象特性的体现
1. 封装性: 备忘录模式通过Memento对象封装了Originator的内部状态，这对外界是不可见的。只有Originator类自身能够访问这些状态，这是通过C++中的访问控制（public, private, protected）来实现的，从而确保了对象状态的安全性和封装性。

2. 抽象与接口: Memento作为一个抽象概念，代表了保存的状态，但具体实现细节对客户端（Caretaker）隐藏。这体现了面向对象设计中的抽象与接口隔离原则，使得系统各部分之间的依赖关系减少，提高了模块间的独立性。

3. 多态性: 虽然备忘录模式直接的多态表现不如策略模式或工厂模式那样明显，但设计中仍可能利用接口或抽象类来定义Memento，使得不同的状态类型可以通过相同的接口来处理，这体现了面向对象的多态性。

### 内涵独特设计思路
1. 状态隔离与时间旅行: 备忘录模式通过创建状态的快照，实际上是在时间轴上为对象的状态创建了“检查点”。这种设计允许对象“时间旅行”，回到之前的任何检查点，这是一种非常直观且强大的状态管理方式。

2. 职责分离: 该模式清晰地划分了三个角色的职责：Originator负责创建和恢复状态；Memento负责存储状态；Caretaker负责管理状态的集合，但不关心状态的具体内容。这种职责划分符合单一职责原则，使系统设计更为清晰和可维护。

### 设计模式的特点体现
1. 复用性: 备忘录模式提供了一种通用的状态保存和恢复框架，可以应用于多种需要状态管理的场景，如撤销/重做机制、游戏存档系统等，增强了代码的复用性。

2. 灵活性与扩展性: 由于Memento对象是独立于Originator和Caretaker设计的，引入新类型的备忘录或修改状态存储方式对整个系统的影响较小，便于系统的扩展和维护。

3. 设计哲学: 备忘录模式展示了面向对象设计中的一个重要哲学——关注点分离。它将状态的管理从业务逻辑中分离出来，使得状态的保存和恢复成为一种可插拔的服务，有助于保持代码的整洁和高效。

综上所述，C++备忘录模式不仅是一种技术实践，更是面向对象设计原则的深刻应用，它通过巧妙的角色设计和状态管理机制，展示了如何在复杂的系统中维持高内聚低耦合的设计目标，体现了设计模式在提升软件质量和可维护性方面的重要价值。

## 例子
### 包含的类和接口
1. Editor (Originator): 负责创建和恢复备忘录，即文本编辑器本身。
2. Memento (Memento): 存储编辑器的状态，即文本内容。
3. Caretaker (History): 负责管理备忘录的历史记录，可以回滚到之前的状态。

### 示例代码
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// 备忘录类，存储编辑器的状态
class Memento {
public:
    explicit Memento(const std::string& state) : state_(state) {}

    std::string getState() const { return state_; }

private:
    std::string state_; // 文本状态
};

// 起源类：编辑器
class Editor {
public:
    void type(const std::string& text) {
        text_ += text;
        saveToHistory();
        printCurrentText();
    }

    void undo() {
        if (!history_.empty()) {
            auto lastState = history_.back();
            history_.pop_back();
            restoreFrom(lastState);
        }
        else {
            std::cout << "Nothing to undo." << std::endl;
        }
    }

private:
    std::string text_;  // 当前文本
    std::vector<std::shared_ptr<Memento>> history_; // 备忘录历史

    // 保存当前的编辑器状态到历史记录
    void saveToHistory() {
        history_.push_back(std::make_shared<Memento>(text_));
    }

    // 从备忘录中恢复状态
    void restoreFrom(const std::shared_ptr<Memento>& memento) {
        text_ = memento->getState();
    }

    // 打印当前状态
    void printCurrentText() {
        std::cout << "Current Text: " << text_ << std::endl;
    }
};

int main() {
    Editor editor;
    editor.type("Hello, ");
    editor.type("World!");
    editor.undo();
    std::cout << "执行回滚操作" << std::endl;
    editor.undo();
    std::cout << "执行回滚操作" << std::endl;

    editor.type("china!");

    return 0;
}
```

### 解释
- Editor 类（起源）包含了文本状态和操作文本的方法（type 和 undo）。每次输入新文本后，它都会创建一个新的备忘录并保存到历史记录中。
- Memento 类（备忘录）只包含编辑器的状态信息，即当前的文本内容，没有暴露任何修改状态的方法，以保持封装性。
- Editor 类内部管理了一个 history_ 向量来存储备忘录对象，使用 saveToHistory 方法保存状态，使用 undo 方法恢复上一步的状态。
- 在 main 函数中，我们创建了一个 Editor 实例并进行了几次操作，展示了如何输入文本以及撤销操作。