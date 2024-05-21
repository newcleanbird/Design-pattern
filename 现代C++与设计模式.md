# 现代C++设计模式
c++常用的设计模式包括单例模式、工厂模式、抽象工厂模式、适配器模式、装饰者模式、代理模式、外观模式、桥接模式、组合模式、享元模式、观察者模式和命令模式等。使用设计模式的好处：提高代码的可读性和可维护性；将常见的设计问题隔离程序的业务逻辑；重用已有的实现；消除重复代码；消除手动调整代码以达到正确逻辑的所有痛苦。

## 十一种C++常用的设计模式
+ [Factory-Method 工厂方法模式](Factory-Method/Factory-Method.md) / [Abstract Factory 抽象工厂模式](Abstract-Factory/Abstract-Factory.md)
+ [Singleton 单例模式](Singleton/Singleton.md)
+ [Adapter 适配器模式](Adapter/Adapter.md)
+ [Façade 外观模式](Facade/Facade.md)
+ [Proxy 代理模式](Proxy/Proxy.md)
+ [Bridge 桥接模式](Bridge/Bridge.md)
+ [Template Method 模板方法](Template-Method/Template-Method.md)
+ [Template Method 模板方法](Template-Method/Template-Method.md)
+ [Strategy 策略模式](Strategy/Strategy.md)
+ [Observer/Event 观察者模式](Observer/Observer.md)
+ [Chain-of-Resposibility 责任链模式](Chain-of-Resposibility/Chain-of-Resposibility.md)

## 李志忠老师认为的现代不常用的设计模式
在C++的现代实践中，某些设计模式可能因为语言特性的进步、编程范式的转变或是更高效的设计模式的出现而变得较少使用或逐渐淡出。
+ [Bridge 桥接模式](Bridge/Bridge.md)
+ [Mediator 中介者模式](Mediator/Mediator.md)
+ [Memento 备忘录模式](Memento/Memento.md)
+ [Iterator 迭代器模式](Iterator/Iterator.md)
+ [Chain-of-Resposibility 责任链模式](Chain-of-Resposibility/Chain-of-Resposibility.md)
+ [Command 命令模式](Command/Command.md)
+ [Visitor 访问者模式](Visitor/Visitor.md)
+ [Interpreter 解析器模式](Interpreter/Interpreter.md)

### 过时的 Singleton 实现:
虽然单例模式本身仍然常见，但早期基于静态成员或全局变量的实现方式因线程安全问题和测试困难而逐渐被基于局部静态变量或更现代并发控制机制的实现所取代。

### 简单工厂模式:
简单工厂模式由于其违反了开放封闭原则（即增加新产品需要修改工厂类），在大型项目或需要高度可扩展的系统中可能较少使用，转而使用工厂方法模式或抽象工厂模式。

### 门面模式 (Facade) 的过度使用:
当过度使用时，可能会隐藏系统的真实复杂性，使得维护和理解底层架构变得困难。现代设计更倾向于适度封装和模块化，直接使用更细粒度的接口而非单一的门面。

### 命令模式的直接应用:
随着反应式编程和函数式编程风格的流行，命令模式直接用于实现请求-响应链路的场景减少，但在某些领域如Undo/Redo系统、GUI框架中仍有应用。

### 享元模式 (Flyweight):
在现代硬件资源丰富和内存管理优化的环境下，直接使用享元模式来节省内存的情况减少，但在处理大量相似对象时，其核心思想仍可能间接应用于资源池等设计中。

## 现代C++应用设计模式的变化
1. 内存管理的现代化
- 智能指针：C++11引入了智能指针（std::unique_ptr, std::shared_ptr），极大地简化了资源管理，降低了内存泄漏的风险。在实现如工厂模式、单例模式等需要动态分配对象的设计模式时，智能指针提供了自动化的资源生命周期管理。
- 移动语义：通过右值引用和移动构造函数，C++11允许高效地转移资源所有权而不是复制，这对于需要高效复制或转移大量数据的设计模式（如原型模式）非常有用。

2. 语言特性的增强
- Lambda表达式：C++11引入的Lambda表达式使得在设计模式中传递行为（如策略模式、观察者模式）变得更加方便和直接，提高了代码的可读性和灵活性。
- 类型推断：auto关键字简化了类型声明，特别是在复杂的模板或迭代器使用中，使得代码更简洁，降低了类型错误的可能性。
- 模板和泛型编程改进：C++14、C++17对模板元编程的支持增强，C++20引入的概念（Concepts）提高了泛型代码的清晰度和错误信息的准确性，使得泛化设计模式（如模板方法模式）的实现更加严格和易懂。

3. 并发与并行编程支持
- C++11引入了线程库，C++17和C++20进一步加强了并发支持，使得并发设计模式（如生产者-消费者模式）的实现更加标准化和安全，减少了手动同步的复杂性。

4. 模块化编程
- C++20的模块系统旨在替换传统的头文件，提供更好的封装性，减少编译时间和依赖管理复杂性。这对于大型项目中设计模式的组织和维护是一个重大改进。

5. 性能和安全性提升
- 新的编译器优化技术和语言特性（如constexpr）允许更多的计算在编译时完成，提高了运行时性能。
更强的类型安全和边界检查（如C++20的std::span）减少了缓冲区溢出和其他安全漏洞。

6. 编程实践的演变
- 随着现代C++编码规范的推广，如使用RAII（Resource Acquisition Is Initialization）原则，设计模式的实现更注重资源管理的安全性和代码的清晰度。
函数式编程和反应式编程风格的融合，也影响了某些设计模式的实现方式，比如使用函数对象和lambda表达式来替代传统的类结构。
