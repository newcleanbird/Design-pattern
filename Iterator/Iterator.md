# Iterator 迭代器模式
迭代器模式（Iterator Pattern）是一种行为设计模式，它提供了一种方法来顺序访问集合对象中的元素，而无需知道集合的底层实现。在C++中，迭代器模式被广泛应用于STL（标准模板库）中，如std::vector、std::list等容器的迭代器。

## 动机(Motivation)
+ 集合对象内部结构常常变化异常。但对于这些集合对象，我们希望不暴露其内部结构的同时，可以让外部客户代码透明地访问其中包含的元素；
同时这种”透明遍历“也为”同一种算法在多种集合对象上进行操作“提供了可能。
+ 使用面向对象技术将这种遍历机制抽象为”迭代器对象“为”应对变化中的集合对象“提供了一种优雅的方式。

## 模式定义
提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露(稳定)该对象的内部表示。
——《设计模式》GoF

不暴露：隔离变化
目前在C++已经过时了，STL迭代器很好的诠释了迭代器。
迭代器模式是用面向对象的方式定义。

## 要点总结
+ 迭代抽象：访问一个聚合对象的内容而无需暴露它的内部表示。
+ 迭代多态：为遍历不同的集合对象提供一个统一的接口，从而支持同样的算法在不同的集合结构上进行操作。
+ 对C++来说是过时的，现在迭代器用模板，面向对象的方式性能低

## C++迭代器模式详解
### 关键组成部分：
1. Iterator（迭代器接口）: 定义了遍历集合元素所需的方法，如next()（移动到下一个元素）、hasNext()（检查是否有下一个元素）和current()（返回当前元素）。

2. Concrete Iterator（具体迭代器）: 实现迭代器接口，维护当前遍历的位置，知道如何遍历特定集合的元素。

3. Aggregate（集合接口）: 提供创建迭代器的方法，如createIterator()。

4. Concrete Aggregate（具体集合）: 实现集合接口，创建并返回与其关联的迭代器实例。

### 优点：
1. 封装: 迭代器模式将集合的遍历逻辑与集合的具体实现分离，使得集合的内部结构对客户端透明，易于修改集合的实现而不影响客户端代码。

2. 灵活性和可扩展性: 新增集合类型或迭代器行为时，只需实现相应的迭代器接口，不会影响现有代码。

3. 简化集合操作: 通过统一的迭代器接口，客户端可以以相同的方式遍历不同的集合，简化了集合的遍历逻辑。

### 注意事项：
1. 迭代器失效: 在动态改变集合大小的操作（如在迭代过程中删除元素）可能导致某些迭代器失效。C++中，如std::vector的push_back可能导致重新分配内存，从而使现有迭代器失效。

2. 性能考量: 迭代器可能引入额外的间接访问开销，尤其是在频繁迭代大量数据时。

3. 正确使用迭代器范围: 确保迭代器始终在有效范围内使用，避免越界错误。

### 深入理解：
迭代器模式是C++STL的重要组成部分，它不仅体现了面向对象设计的原则（如封装和多态），而且是泛型编程的一个典型应用。通过泛型迭代器，C++能够编写出高度通用的算法，这些算法可以在任何提供适当迭代器接口的容器上工作，大大增强了代码的复用性和灵活性。

### 适用情况：
1. 集合遍历: 当需要遍历集合中的每个元素，但又不想暴露集合的内部结构时，迭代器模式是理想的选择。

2. 多种遍历策略: 需要提供多种遍历集合的方式时，可以通过实现不同的迭代器来实现。

3. 算法与数据结构解耦: 在设计库或框架时，希望算法独立于特定的数据结构，迭代器模式可以帮助实现这一目标。

综上，迭代器模式是处理集合遍历时的一个强大工具，它通过抽象化迭代逻辑，提高了代码的可维护性和灵活性。然而，在使用时要注意迭代器的有效性管理和性能优化，确保其高效且安全地服务于程序的需要。

### 面向对象特性的体现
1. 封装: 迭代器模式通过迭代器接口封装了集合的遍历逻辑，使得客户端代码无需了解集合的具体实现细节。这种封装保证了数据的安全性和代码的模块化。

2. 多态: 迭代器模式利用多态性，使得不同类型的集合可以提供各自的迭代器实现，而客户端代码只需要通过迭代器接口就能操作所有类型的集合。这提高了代码的通用性和可复用性。

3. 抽象: 通过定义抽象迭代器接口，迭代器模式提供了一个统一的遍历集合的抽象视图。这使得设计更加灵活，可以轻松地添加新的集合类型或迭代逻辑，而不会影响现有代码。

### 独特设计思路
1. 分离关注点: 迭代器模式将集合的遍历行为与集合本身分离，使得集合的设计可以专注于数据的存储和管理，而遍历逻辑则由迭代器负责。这样，集合和遍历逻辑可以独立演化，降低耦合。

2. 迭代器作为行为: 这一模式将遍历视为对象的行为，而非集合的直接属性。迭代器是具有状态的对象，知道如何一步步访问集合的元素，这体现了行为对象设计的思维。

### 设计哲学
1. 开闭原则: 迭代器模式鼓励对扩展开放，对修改关闭。当需要支持新的集合类型或遍历方式时，只需添加新的迭代器类，而无需修改现有集合或迭代器接口，这符合软件工程中的重要原则。

2. 迭代器的泛型编程: 在C++中，迭代器模式与泛型编程紧密结合，通过模板提供了一种编写与容器类型无关的算法方法。这使得算法可以复用，提高了代码的效率和可维护性。

### 设计模式特点
1. 行为模式: 迭代器模式属于行为设计模式，它关注对象之间的责任分配，通过定义一组算法，使对象能够在不修改自身的情况下定义新的行为。

2. 迭代器的透明性: 优秀的迭代器设计应使用户感觉像是直接操作集合本身一样自然，即所谓的“透明迭代”。这意味着用户不必关心是直接访问元素还是通过迭代器访问。

3. 可定制性: 迭代器模式允许为不同的集合类型定制不同的遍历策略，如正序遍历、逆序遍历或根据某种条件过滤的遍历，增加了设计的灵活性。

## 例子
下面是一个C++标准迭代器模式的简化示例，该示例模拟了一个简单的集合（Container）和一个迭代器（Iterator），用于遍历集合内的元素。这个例子虽然简化，但很好地体现了迭代器模式的基本特点和运作机制。
```cpp
#include <iostream>
#include <vector>

// 抽象迭代器接口
class Iterator {
public:
    virtual ~Iterator() {}
    virtual bool hasNext() const = 0;
    virtual int next() = 0;
};

// 具体迭代器，用于遍历Container
class ConcreteIterator : public Iterator {
public:
    ConcreteIterator(std::vector<int>& items) : items_(items), index_(0) {}

    bool hasNext() const override {
        return index_ < items_.size();
    }

    int next() override {
        if (hasNext()) {
            return items_[index_++];
        }
        throw std::out_of_range("No more elements.");
    }

private:
    std::vector<int>& items_;
    size_t index_;
};

// 抽象集合接口
class Container {
public:
    virtual ~Container() {}
    virtual Iterator* createIterator() const = 0;
    virtual void addItem(int item) = 0;
    virtual void removeItem(int item) = 0;
};

// 具体集合
class ConcreteContainer : public Container {
public:
    Iterator* createIterator() const override {
        return new ConcreteIterator(items_);
    }

    void addItem(int item) override {
        items_.push_back(item);
    }

    void removeItem(int item) override {
        items_.erase(std::remove(items_.begin(), items_.end(), item), items_.end());
    }

private:
    std::vector<int> items_;
};

int main() {
    ConcreteContainer container;
    container.addItem(1);
    container.addItem(2);
    container.addItem(3);

    Iterator* it = container.createIterator();
    while (it->hasNext()) {
        std::cout << it->next() << std::endl;
    }
    delete it; // 注意释放迭代器资源

    return 0;
}
```
### 解释
1. 抽象迭代器 (Iterator) 定义了遍历元素所需的接口，如 hasNext() 和 next()。
2. 具体迭代器 (ConcreteIterator) 实现了 Iterator 接口，与具体的集合类型（这里是一个 std::vector<int>）交互，提供遍历逻辑。
3. 抽象集合 (Container) 定义了获取迭代器、添加和移除元素的方法。
4. 具体集合 (ConcreteContainer) 实现了 Container 接口，并使用 std::vector 存储元素。

通过这个例子，我们可以看到迭代器模式如何在不暴露集合内部结构的情况下，提供了遍历集合元素的能力，同时保持了良好的封装性。客户端代码（在 main 函数中）可以使用统一的接口遍历不同类型的集合，只要这些集合提供了遵循迭代器模式的迭代器。这正是迭代器模式的核心价值所在。