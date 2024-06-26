# Composite 组合模式
组合模式（Composite Pattern）是一种结构设计模式，它让我们能够以一致的方式处理单个对象和对象组合。在C++中，组合模式通常通过定义一个类层次结构来实现，其中基础接口既适用于叶子对象（无法再分解的基本单元）也适用于组合对象（可以包含叶子对象或其他组合对象的容器）。

## 动机(Motivation)
+ 客户代码过多地依赖于对象容器复杂的内部实现结构，对象容器内部实现结构(而非抽象结构)的变化
引起客户代码的频繁变化，带来了代码的维护性、扩展性等弊端。
+ 如何将”客户代码与复杂的对象容器结构“解耦？让对象容器自己来实现自身的复杂结构，从而使得客户代码就像处理简单对象一样来处理复杂的对象容器？

## 模式定义
将对象组合成树形结构以表示”部分-整体“的层次结构。Composite使得用户对单个对象和组合对象的使用具有一致性(稳定)。
——《设计模式》GoF

## 要点总结
+ Composite模式采用树性结构来实现普遍存在的对象容器，从而将”一对多“的关系转化为”一对一“的关系，使得客户代码可以一致地(复用)处理对象和对象容器，
无需关心处理的是单个的对象，还是组合的对象容器。
+ 客户代码与纯粹的抽象接口——而非对象容器的内部实现结构——发生依赖，从而更能”应对变化“。
+ Composite模式在具体实现中，可以让父对象中的子对象反向追溯；如果父对象有频繁的遍历需求，可使用缓存技术来改善效率。


## C++组合模式详解
### 关键组成部分：
1. Component（组件）: 定义了所有对象共有的接口，无论它们是组合对象还是叶子对象。这使得客户端可以用统一的方式处理它们。

2. Leaf（叶子）: 实现Component接口，表示组合中的叶节点对象，没有子节点，通常包含一些实际的业务逻辑。

3. Composite（组合）: 同样实现Component接口，但可以包含子组件（叶子或其它组合）。它提供了管理子组件的接口，比如添加、删除子组件以及迭代子组件。

### 优点：
1. 简化客户端代码: 通过将对象组合和单个对象统一抽象，客户端无需关心操作的是单个对象还是组合，简化了客户端代码。
2. 结构透明: 通过递归组合，可以构建复杂的树状结构，而不需要了解这个结构的细节，便于管理层次化的数据结构。
3. 易于扩展: 可以轻易地在组合中添加新的叶子或组合对象，而不需要修改现有类的代码。

### 注意事项：
1. 设计平衡: 在决定将哪些方法放在Component接口还是Composite类中时需要权衡。如果将管理子组件的方法（如add, remove）放在Component中，可以提高透明度但可能违反单一职责原则。

2. 性能考量: 如果组合结构庞大，递归遍历或操作可能会引起性能问题，需要考虑缓存机制或优化算法。

3. 类型安全: C++中使用多态时，要确保正确的向下转型，避免运行时错误。

### 深入理解：
组合模式体现了面向对象设计中的“面向接口编程”原则，通过抽象化将不同类型的对象统一处理。它还体现了“开闭原则”，即对扩展开放（容易添加新的组件类型），对修改关闭（不改动现有组件接口）。

### 适用情况：
1. 文件系统: 文件夹（组合）可以包含文件（叶子）和子文件夹（组合），统一处理文件和文件夹的操作。
2. 图形界面元素: 如菜单项（叶子）和菜单（组合），可以递归构建菜单层次。
3. 组织结构: 员工（叶子）和部门（组合，可以包含员工和子部门）的管理。
4. 游戏对象: 场景中的对象，如树木（叶子）和森林（组合，包含多个树木或子森林）。
综上所述，组合模式在处理具有层次结构的数据或对象集合时非常有用，特别是在需要以统一方式操作这些结构中的所有元素时。它强调了设计的灵活性和可扩展性，但也要求设计者在透明性与安全性之间找到恰当的平衡。

### 面向对象特性的体现
1. 封装性: 组合模式通过定义清晰的接口（Component），将对象的内部结构和实现细节隐藏起来，仅暴露出必要的操作。无论是叶子对象还是组合对象，都遵循相同的接口规范，这加强了系统的封装性。

2. 继承与多态: 通过继承机制，叶子对象和组合对象都可以视为Component的子类，实现了接口的多态性。这意味着客户端可以对Component的引用进行操作，而无需关心它是指向叶子还是组合，提高了代码的通用性和灵活性。

3. 抽象与具体分离: Component接口定义了所有对象共有的行为，而具体的叶子和组合类则专注于实现这些行为。这种分离使得设计更易于理解和维护，同时也便于未来扩展。

### 独特设计思路
1. 递归组合: 组合模式的精髓在于它允许递归地构造对象结构，即组合对象可以包含叶子或更多组合对象。这种设计使得构建复杂的层次结构变得简单直接，同时也易于管理。

2. 一致的接口处理: 不论处理的是单个对象还是对象组合，都通过相同的接口进行操作。这种一致性简化了客户端代码，降低了错误率，提高了代码的可读性和可维护性。

### 设计哲学
1. 分而治之: 组合模式体现了将复杂问题分解为更小、更易管理的部分的哲学。通过将对象组织成树状结构，可以逐步构建复杂系统，每一步都保持清晰和可控制。

2. 组合优于继承: 通过组合对象而不是过度依赖继承关系来构建复杂结构，可以更灵活地调整和重用代码。这符合面向对象设计中的一种重要原则，即组合比继承更具弹性。

### 设计模式特点
1. 结构型模式: 组合模式属于结构型设计模式，它关注类和对象的组合，通过提供简单的方式来组合低级对象形成更复杂结构，从而实现新功能。

2. 透明性与安全性的权衡: 为了实现客户端对单个对象和组合对象的透明操作，有时需要在接口设计上做出权衡，可能会牺牲一定的安全性（如直接暴露管理子对象的方法）。

3. 开闭原则: 组合模式鼓励对组件的扩展开放，对修改封闭。新增加的组件类型（无论是叶子还是组合）都应当能够无缝融入现有的结构，而无需修改现有的组件接口和实现。

## 例子
以下是一个C++标准的组合模式示例，通过构建一个文件系统目录树结构来展示组合模式的特点。这个例子很好地体现了如何以一致的方式处理单个文件（叶子对象）和文件夹（组合对象）。
```cpp
#include <iostream>
#include <vector>
#include <string>

// 组件基类，定义了所有对象共有的接口
class FileSystemItem {
public:
    virtual ~FileSystemItem() {}
    virtual void displayInfo(int depth) const = 0;
};

// 叶子对象：文件
class File : public FileSystemItem {
public:
    File(const std::string& name) : name_(name) {}
    void displayInfo(int depth) const override {
        for (int i = 0; i < depth; ++i) std::cout << "\t";
        std::cout << "- " << name_ << " (File)" << std::endl;
    }

private:
    std::string name_;
};

// 组合对象：文件夹，包含子组件
class Folder : public FileSystemItem {
public:
    Folder(const std::string& name) : name_(name) {}

    void add(FileSystemItem* item) {
        children_.emplace_back(item);
    }

    void displayInfo(int depth) const override {
        for (int i = 0; i < depth; ++i) std::cout << "\t";
        std::cout << "- " << name_ << " (Folder)" << std::endl;

        for (const auto& child : children_) {
            child->displayInfo(depth + 1);
        }
    }

private:
    std::string name_;
    std::vector<FileSystemItem*> children_;
};

int main() {
    // 构建一个简单的文件系统目录结构
    Folder root("root");
    Folder documents("Documents");
    File file1("example.txt");
    File file2("notes.txt");

    // 添加文件和文件夹
    documents.add(&file1);
    documents.add(&file2);
    root.add(&documents);

    // 显示目录结构
    root.displayInfo(0);

    return 0;
}
```
### 解释
这个例子中：

``FileSystemItem`` 是抽象基类，定义了所有文件系统项目应具备的共同接口，即 displayInfo 方法，用于显示项目信息。
``File`` 类继承自 FileSystemItem，代表文件，是组合模式中的叶子对象。它实现了 displayInfo 方法来显示文件名。
``Folder`` 类同样继承自 FileSystemItem，代表文件夹，是组合模式中的组合对象。它不仅实现了 displayInfo 方法来显示文件夹名，还可以添加（add 方法）和管理子项目（文件或文件夹）。Folder 通过一个 children_ 向量来存储其子组件。
``main`` 函数中，我们创建了一个简单的文件系统结构，包括一个根目录、一个名为“Documents”的子文件夹，以及两个文件“example.txt”和“notes.txt”。通过调用 displayInfo 方法，以递归方式显示整个目录结构，展示了组合模式如何以一致的方式处理单个文件和包含文件及子文件夹的文件夹。
