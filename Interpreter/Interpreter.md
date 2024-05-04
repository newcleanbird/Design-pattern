# Interpreter 解析器
解析器模式（Parser Pattern），也常被称为解释器模式（Interpreter Pattern），是行为设计模式之一，用于定义一个语言的文法，并创建一个解释器来解释该语言中的句子。这个模式通常用于处理具有明确文法规则的自定义语言或者格式，比如查询语言、数学表达式、配置文件解析等。下面我将详细讲解C++中的解析器模式，包括其优点、注意事项及适用场景，并分享我的深入理解。

## 动机(Motivation)
+ 如果某一特定领域的问题比较复杂，类似的结构不断重复出现，如果使用普通的编程方式来实现将面临非常频繁的变化。
+ 在这种情况下，将特定领域的问题表达为某种语法规则下的句子，然后构建一个解释器来解释这样的句子，从而达到解决问题的目的。

## 模式定义
给定一个语言，定义它的文法的一种表示，并定义一种解释器，这个解释器使用该表示来解释语言中的句子。
——《设计模式》GoF


## 要点总结
+ Interpreter模式的应用场合是Interpreter模式应用中的难点，只有满足“业务规则频繁变化，且类似的结构不断重复出现，
并且容易抽象为语法规则的问题”才适合使用Interpreter模式。
+ 使用Interpreter模式来表示文法规则，从而可以使用面向对象技巧来方便地“扩展”文法。
+ Interpreter模式适合简单的文法表示，对于复杂的文法表示需要求助语法分析器标准工具。

## 详解解析器模式
### C++解析器模式的实现
1. 抽象表达式（AbstractExpression）: 定义解释器的接口，声明解释操作。
2. 终结符表达式（TerminalExpression）: 实现抽象表达式的子类，代表文法中的终结符（如数字、标识符）。
3. 非终结符表达式（NonterminalExpression）: 实现抽象表达式的子类，代表文法中的非终结符（如加、减、乘、除运算符），通常包含对其他表达式的引用。
4. 环境类（Context）: 包含解释器可能需要的全局信息或状态。
5. 客户端（Client）: 构建一个具体的表达式（如通过组合终结符和非终结符表达式），并调用解释器的解释方法。

### 优点
1. 扩展性良好：当需要添加新的语法规则时，仅需增加新的解释器类，不需要修改现有的解释器代码。
2. 清晰的文法规则：将复杂的文法规则编码为类结构，使得文法更容易理解和维护。
3. 模块化：将解析逻辑封装在独立的类中，提高了代码的模块化和可重用性。

### 注意事项
1. 性能考量：对于复杂或大规模的输入，解释器模式可能导致大量的类实例，进而影响性能和内存消耗。
2. 类膨胀：随着文法规则的增多，可能需要创建大量的类，导致类膨胀。
3. 适用范围有限：解析器模式最适合处理小规模、定义良好的语言，对于大型或复杂语言，可能更适合使用编译器生成技术或现成的解析库。

### 深入理解
解析器模式的价值在于它能够将复杂的文法规则转换为易于理解和管理的对象结构。通过定义一系列遵循特定文法的类，解析器模式使得对这些规则的解释和处理变得更加直接和灵活。然而，这种模式的使用需要权衡其带来的结构清晰度与可能的性能开销，特别是在处理非常基础或高度优化的场景下，可能有更高效的替代方案。

### 适用情况
1. 领域特定语言（DSL）的解析：当需要解析自定义的查询语言、脚本语言或其他小型语言时。
2. 配置文件解析：处理配置文件中的特定格式和规则。
3. 公式计算：如数学表达式、逻辑表达式的解析与计算。
4. 查询解析：数据库查询语言、搜索条件解析等。
总之，解析器模式在处理具有明确定义语法的小型语言时非常有用，它通过将文法规则映射到对象结构，使得语法的解析和执行逻辑更加清晰和易于扩展。然而，在面对复杂的语言或性能敏感的场景时，应考虑其他更高效的技术或工具。


### 面向对象特性在解析器模式中的体现
1. 继承与多态：解析器模式的核心在于定义了一个抽象表达式基类（AbstractExpression），并通过继承这一基类创建终结符表达式和非终结符表达式类。终结符表达式直接解释文法中的基本元素（如数字和变量），而非终结符表达式通过组合其他表达式来解释更复杂的结构（如运算符）。多态允许这些不同类型的表达式被统一处理，即客户端可以通过基类指针或引用来调用所有表达式的解释方法，而无需知道它们的具体类型。

2. 封装：每种表达式类都封装了特定的解释逻辑，隐藏了内部实现细节。这样，当需要改变或扩展解释规则时，只需修改相应的类，而不影响到其它部分，符合“开放封闭原则”。

3. 组合：解析器模式经常使用组合模式来构建复杂的表达式树，即非终结符表达式内部可以包含对其他表达式的引用。这种组合方式允许以递归的方式构造和解析复杂的语言结构，同时保持了代码的整洁和模块化。

### 设计模式的特点与哲学
1. 分离关注点：解析器模式将语言的定义与语言的解释过程分离。定义（文法规则）体现在类结构上，而解释（执行）体现在类的方法实现中。这种分离使得文法的变更不会直接影响到解释逻辑，反之亦然。

2. 灵活性与可扩展性：通过新增表达式类，可以轻松地扩展语言的文法规则，而不需要修改现有的解释器框架，体现了“针对接口编程，不针对实现编程”的设计原则，增强了系统的灵活性和可维护性。

3. 设计哲学：解析器模式体现了设计模式中的“单一职责原则”和“里氏替换原则”。每个表达式类负责解释一种特定的文法规则，且在不改变原有类行为的基础上，子类可以替换父类出现在父类能够出现的任何地方。

## 例子
```cpp
#include <iostream>
#include <map>
#include <stack>
 
class AbsExpression
{
public:
    bool isVarType = false;
public:
    void   setExpressionType(bool bFlag){isVarType= bFlag;};
    virtual int interpreter(std::map<char,int>var)=0;
    virtual ~AbsExpression(){};
};
 
//变量表达式
class ValExpression:public AbsExpression
{
private:
    char m_key;
public:
    ValExpression(const char&key)
    {
        std::cout << "ValExpression " << std::endl;
        this->m_key = key;
        setExpressionType(true);
    }
 
    int interpreter(std::map<char, int> var) override
    {
        return var[m_key];
    }
    ~ValExpression()
    {
     std::cout << "~ValExpression " << std::endl;
    }
};
 
//符号表达式
class SymbolExpression:public AbsExpression
{
protected:
    AbsExpression* m_left;
    AbsExpression* m_right;
 
public:
    SymbolExpression(AbsExpression* left,AbsExpression* right):
        m_left(left),m_right(right)
    {
    }
    ~SymbolExpression()
    {
        //left对象是直接取的栈容器的上一个top,故可以显式清理。
        //right的new对象不会直接push进栈容器，而是做了符号实例对象的成员变量。故需要对其进行对象释放
        if(m_right != nullptr)
        {
            delete m_right;
            m_right = nullptr;
        }
        std::cout << "~SymbolExpression" << std::endl;
    }
};
 
//加法运算符
class AddExpression:public SymbolExpression
{
public:
    AddExpression(AbsExpression* left,AbsExpression* right):
        SymbolExpression(left,right){
        std::cout << "AddExpression " << std::endl;
    }
 
    int interpreter(std::map<char,int>var)
    {
        return m_left->interpreter(var) + m_right->interpreter(var);
    }
};
//减法运算符
class SubExpression:public SymbolExpression
{
public:
    SubExpression(AbsExpression* left,AbsExpression* right):
        SymbolExpression(left,right){
        std::cout << "SubExpression " << std::endl;
    }
 
    int interpreter(std::map<char,int>var)
    {
        return m_left->interpreter(var) - m_right->interpreter(var);
    }
};
 
std::stack<AbsExpression*> analyse(std::string strLanguage){
    std::stack<AbsExpression*>stackExp;
    AbsExpression* left = nullptr;
    AbsExpression* right = nullptr;
 
    for(size_t i = 0; i < strLanguage.length();i++)
    {
        switch (strLanguage[i]) {
        case '+':
        {
            left = stackExp.top();
            right = new ValExpression(strLanguage[++i]);
            stackExp.push(new AddExpression(left,right));
        }break;
        case '-':
        {   left = stackExp.top();
            right = new ValExpression(strLanguage[++i]);
            stackExp.push(new SubExpression(left,right));
 
        }break;
        default:
            stackExp.push(new ValExpression(strLanguage[i]));
 
        }
    }
    return stackExp;
};
 
void release( std::stack<AbsExpression*> exp)
{
    while (exp.size() > 0) {
       AbsExpression* it =  exp.top();
       delete it;
       it = nullptr;
       exp.pop();
    }
    std::cout << "clear exp finshed " << std::endl;
}
class Client
{
public:
    void doWork()
    {
        std::string str = "a+b+c-d";
        std::map<char,int>mapVar;
        mapVar.insert(std::make_pair('a',1));
        mapVar.insert(std::make_pair('b',2));
        mapVar.insert(std::make_pair('c',3));
        mapVar.insert(std::make_pair('d',4));
        std::stack<AbsExpression*> exp = analyse(str);
        int ret = exp.top()->interpreter(mapVar);
 
        std::cout << "ret is " << ret << std::endl;
        release(exp);
    }
};
 
int main()
{
    Client obj;
    obj.doWork();
    return 0;
}
```