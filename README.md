# Design-pattern
设计模式(C++)，方便快速了解设计模式并反复学习。

## 什么是设计模式
“每一个模式描述了一个在我们周围不断重复发生的问题，以及该问题的解决方案的核心。这样，你就能一次又一次地使用该方案而不必做重复劳动”。
——Christopher Alexander

### 如何解决复杂性？
+ 分解
  + 人们面对复杂性有一个常见的做法：即分而治之，将大问题分解为多个小问题，将复杂问题分解为多个简单问题。
+ 抽象
  + 更高层次来讲，人们处理复杂性有一个通用的技术，即抽象。由于不能掌握全部的复杂对象，我们选择忽视它的非本质细节，而去处理泛化和理想化了的对象模型。
  
### 底层思维 和 抽象思维
底层思维：向下，如何把握机器底层从微观理解对象构造
• 语言构造
• 编译转换
• 内存模型
• 运行时机制

抽象思维：向上，如何将我们的周围世界抽象为程序代码
• 面向对象
• 组件封装
• 设计模式
• 架构模式

### 深入理解面向对象
向下：深入理解三大面向对象机制
•封装，隐藏内部实现
•继承，复用现有代码
•多态，改写对象行为
向上：深刻把握面向对象机制所带来的抽象意义，理解如何使用
这些机制来表达现实世界，掌握什么是“好的面向对象设计”

## 面向对象设计原则
1. 依赖倒置原则（DIP）
  + 高层模块(稳定)不应该依赖于低层模块(变化)，二者都应该依赖于抽象(稳定) 。
  + 抽象(稳定)不应该依赖于实现细节(变化) ，实现细节应该依赖于抽象(稳定)。
2. 开放封闭原则（OCP）
  + 对扩展开放，对更改封闭。
  + 类模块应该是可扩展的，但是不可修改。
3. 单一职责原则（SRP）
  + 一个类应该仅有一个引起它变化的原因。
  + 变化的方向隐含着类的责任。
4. Liskov 里氏替换原则（LSP）
  + 子类必须能够替换它们的基类(IS-A)。
  + 继承表达类型抽象。
5. 接口隔离原则（ISP）
  + 不应该强迫客户程序依赖它们不用的方法。
  + 接口应该小而完备。
6. 合成复用原则
  + 优先使用对象组合，而不是继承关系来实现代码的复用。
  + 类继承通常为“白箱复用”，对象组合通常为“黑箱复用” 。
  + 继承在某种程度上破坏了封装性，子类父类耦合度高。
  + 而对象组合则只要求被组合的对象具有良好定义的接口，耦合度低。
7. 封装变化点
  + 使用封装来创建对象之间的分界层，让设计者可以在分界层的一侧进行修改，而不会对另一侧产生不良的影响，从而实现层次间的松耦合。
8. 针对接口编程，而不是针对实现编程
  + 不将变量类型声明为某个特定的具体类，而是声明为某个接口。
  + 客户程序无需获知对象的具体类型，只需要知道对象所具有的接口。
  + 减少系统中各部分的依赖关系，从而实现“高内聚、松耦合”的类型设计方案。

###  单一职责原则[SINGLE RESPONSIBILITY PRINCIPLE]
- 一个方法尽可能做一件事情，一般来说不应该让一个方法承担多个职责。

单一职责原则的英文名称是Single Responsibility Principle，简称是SRP。单一职责原则的定义是：应该有且仅有一个原因引起类的变更。

SRP的原话解释是：There should never be more than one reason for a class to change.

- 单一职责原则提出了一个编写程序的标准，用“职责”或“变化原因”来衡量接口或设计是否优良，但是“职责”跟“变化原因”都是不好度量的，要“因地制宜”。

- 单一职责适用于接口、类，同时也适用于方法，也就是说，一个方法尽可能做一件事情，一般来说不应该让一个方法承担多个职责。

### 里氏替换原则[LISKOV SUBSTITUTION PRINCIPLE]
- 子类应该能替换掉它的父类。

- 里氏替换原则为良好的继承定义了一个规范，一句简单的定义包含了4层含义。
1. 子类必须完全实现父类的方法
2. 子类可以有自己的个性。
3. 覆盖或实现父类的方法时输入参数可以被放大。
4. 覆写或实现父类的方法时输出结果可以被缩小。

- 即如果父类的一个方法的返回值是一个类型T，子类的相同方法（重载或覆写）的返回值为S，那么里氏替换原则就要求S必须小于等于T，也就是说，要么S和T是同一个类型，要么S是T的子类。

- 好像挺难理解的，查找了一些资料。著名技术作家Robert Martin在1996年为《C++ Reporter》写了一篇题为《The The Liskov Substitution Principle》的文章，专门介绍LSP。在Martin的文章中，他给了LSP一个解释：Functions that use pointers or references to base classes must be able to use objects of derived classes without knowing it. 意思是：“使用指向基类的指针或引用的函数，必须能够在不知道具体派生类对象类型的情况下使用它们。”在2002年，Martin在他出版的《Agile Software Development Principles Patterns and Practices》一书中，又进一步简化为：Subtypes must be substitutable for their base types。子类必须能替换掉它们的父类。这样理解起来就比较顺利了。

### 依赖倒置原则[DEPENDENCE INVERSION PRINCIPLE]
- 细节依赖抽象，低层依赖高层。 

- 依赖倒置原则的原始定义是：High level modules should not depend upon low level modules.Both should depend upon abstractions.Abstractions should not depend upon details.Details should depend upon abstractions.

-  高层模块不应该依赖低层模块，二者都应该依赖其抽象；抽象不应该依赖细节；细节应该依赖抽象。即针对接口编程，不要针对实现编程。

包含了三层含义：
1. 高层模块不应该依赖低层模块，两者都应该依赖其抽象;
2. 抽象不应该依赖细节；
3. 细节应该依赖抽象。

- 这一原则在Java语言中的表现就是：
1. 模块间的依赖通过抽象发生，实现类之间不发生直接的依赖关系，其依赖关系是通过接口或抽象类产生的；
2. 接口或抽象类不依赖于实现类；
3. 实现类依赖接口或抽象类。

- 一般抽象是不变的，而具体是易变的。每个较高层次都为它所需要的服务声明一个抽象接口，较低的层次实现这些抽象接口，每个高层类都通过该抽象接口使用下一层的服务，接口属于高层,低层要实现高层的接口,因此现在是低层依赖于高层。是依赖关系倒置和接口所有权的倒置。在周围环境发生变化的时候，如果设计可以做到不怎么发生改变，那这样的设计就是好的。

### 接口隔离原则[INTERFACE SEGREGATION PRINCIPLE]
- 应该尽量建立单一接口，不要建立臃肿的接口，尽量细化接口，接口中的方法尽量少。

- 接口隔离原则的原始定义是：Clients should not be forced to depend upon interfaces that they don’t use.客户端不应该依赖它不需要的接口。

- The dependency of one class to another one should depend on the smallest possible interface.类间的依赖关系应该建立在最小的接口上。

- 这两个定义概括起来就是，应该尽量建立单一接口，不要建立臃肿的接口，接口应该尽量细化。

接口分离的手段主要有以下两种：
1. 委托分离，通过增加一个新的类型来委托客户的请求，隔离客户和接口的直接依赖，但会增加系统开销。
2. 多重继承分离，通过接口多继承来实现客户需求。

### 迪米特法则(最少知识原则)[LOW OF DEMETER]
- 低耦合，高内聚.不要和陌生人说话。
- 一个类应该对自己需要耦合或调用的类知道得最少。

- 迪米特法则（Law of Demeter）又叫最少知道原则（Least Knowledge Principle），1987年秋天由美国Northeastern University的Ian Holland提出，被UML的创始者之一Booch等普及。后来，因为在经典著作《 The Pragmatic Programmer》中提出而广为人知。

**迪米特法则还有一个英文解释是：Only talk to your immediate friends。**

一个对象应该对其他对象有最少的了解。通俗地讲，一个类应该对自己需要耦合或调用的类知道得最少。一个类公开的public属性或方法越多，修改时涉及的面也就越大，变更引起的风险扩散也就越大。在设计时需要反复衡量，是否可以减少public方法和属性，是否可以修改为private、package-private、protected等访问权限，是否可以加上final关键字等。迪米特法则要求类尽量不要对外公布太多的public方法和非静态的public变量，尽量内敛，多使用private、package-private、protected等访问权限。

### 开闭原则[OPEN CLOSE PRINCIPLE]

- 开闭原则要求尽量通过扩展软件实体的行为来实现变化，而不是通过修改已有的代码来完成变化。

**开闭原则的定义：**
Software entities like classes,modules and functios should be open for extemsion but closed for modifications.
- 一个软件实体如类、模块和函数应该对扩展开放，对修改关闭。
- 一个软件产品只要在生命期内，都会发生变化，既然变化是一个既定的事实，我们应该在设计时尽量适应这些变化，以提高项目的稳定性和灵活性。开闭原则要求尽量通过扩展软件实体的行为来实现变化，而不是通过修改已有的代码来完成变化。如何做到开闭原则：抽象、封装。

### 组合/聚合复用原则[Composition/Aggregation Reuse Principle(CARP)]
- 尽量使用组合和聚合少使用继承的关系来达到复用的原则。

## 从意图和用途可以被分类为三大主要类别
### 创建型模式 (Creational Patterns)
在软件工程中，创建型模式是处理对象创建的设计模式，试图根据实际情况使用合适的方式创建对象。基本的对象创建方式可能会导致设计上的问题，或增加设计的复杂度。创建型模式通过以某种方式控制对象的创建来解决问题。创建型模式由两个主导思想构成。一是将系统使用的具体类封装起来，二是隐藏这些具体类的实例创建和结合的方式。创建型模式又分为对象创建型模式和类创建型模式。对象创建型模式处理对象的创建，类创建型模式处理类的创建。详细地说，对象创建型模式把对象创建的一部分推迟到另一个对象中，而类创建型模式将它对象的创建推迟到子类中。

+ [Simple-Factroy 简单工厂模式](Simple-Factroy/Simple-Factroy.md) / [Factory-Method 工厂方法模式](Factory-Method/Factory-Method.md)
让子类来决定要创建哪个对象。

+ [Abstract Factory 抽象工厂模式](Abstract-Factory/Abstract-Factory.md)
创建多个产品族中的产品对象。

+ [Singleton 单例模式](Singleton/Singleton.md)
确保某一个类只有一个实例，并且提供一个全局访问点。

+ [Builder 建造者模式](Builder/Builder.md)
用来创建复杂的复合对象。

+ [Prototype 原型模式](Prototype/Prototype.md)
通过复制原型来创建新对象。

### 结构型模式 (Structural Patterns):
结构型模式涉及到如何组合类和对象以获得更大的结构。结构型模式采用继承机制来组合接口或实现。结构型对象模式不是对接口和实现进行组合，而是描述了如何对一些对象进行组合，从而实现新功能的一些方法。因为可以在运行时刻改变对象组合关系，所以对象组合方式具有更大的灵活性。

+ [Adapter 适配器模式](Adapter/Adapter.md)
将原来不兼容的两个类融合在一起。

+ [Bridge 桥接模式](Bridge/Bridge.md)
将两个能够独立变化的部分分离开来。

+ [Composite 组合模式](Composite/Composite.md)
将整体与局部（树形结构）进行递归组合，让客户端能够以一种的方式对其进行处理。

+ [Decorator 装饰器模式](Decorator/Decorator.md)
为对象添加新功能。

+ [Façade 外观模式](Facade/Facade.md)
对外提供一个统一的接口用来访问子系统。

+ [Flyweight 享元模式](Flyweight/Flyweight.md)
使用对象池来减少重复对象的创建。

+ [Proxy 代理模式](Proxy/Proxy.md)
控制客户端对对象的访问。

### 行为型模式 (Behavioral Patterns):
行为型模式主要是用于描述类或者对象是怎样交互和怎样分配职责的。它涉及到算法和对象间的职责分配，不仅描述对象或者类的模式，还描述了他们之间的通信方式，它将你的注意力从控制流转移到了对象间的关系上来。``行为型类模式``采用继承机制在类间分派行为，而``行为型对象模式``使用对象复合而不是继承。
+ [Chain-of-Resposibility 责任链模式](Chain-of-Resposibility/Chain-of-Resposibility.md)
将事件沿着链去处理。

+ [Command 命令模式](Command/Command.md)
将请求封装成命令，并记录下来，能够撤销与重做。

+ [Interpreter 解析器模式](Interpreter/Interpreter.md)
定义语法，并对其进行解释。

+ [Iterator 迭代器模式](Iterator/Iterator.md)
提供一种方法顺序访问一个聚合对象中的各个元素。

+ [Mediator 中介者模式](Mediator/Mediator.md)
将网状结构转变为星型结构，所有行为都通过中介。

+ [Memento 备忘录模式](Memento/Memento.md)
保存对象的状态，在需要时进行恢复。

+ [Observer/Event 观察者模式](Observer/Observer.md)
状态发生改变时通知观察者，一对多的关系。

+ [State 状态模式](State/State.md)
根据不同的状态做出不同的行为。

+ [Strategy 策略模式](Strategy/Strategy.md)
封装不同的算法，算法之间能互相替换。

+ [Template Method 模板方法](Template-Method/Template-Method.md)
定义一套流程模板，根据需要实现模板中的操作。

+ [Visitor 访问者模式](Visitor/Visitor.md)
基于稳定数据结构，定义新的操作行为。

## 从封装变化角度对模式分类
### “组件协作”模式：
现代软件专业分工之后的第一个结果是“框架与应用程序的划分”，“组件协作”模式通过晚期绑定，来实现框架与应用程序之间的松耦合，是二者之间协作时常用的模式。
+ [Template Method 模板方法](Template-Method/Template-Method.md)
+ [Strategy 策略模式](Strategy/Strategy.md)
+ [Observer/Event 观察者模式](Observer/Observer.md)

### “单一职责”模式：
在软件组件的设计中，如果责任划分的不清晰，使用继承得到的结果往往是随着需求的变化，子类急剧膨胀，同时充斥着重复代码，这时候的关键是划清责任。
+ [Decorator 装饰模式](Decorator/Decorator.md)
+ [Bridge 桥接模式](Bridge/Bridge.md)

### “对象创建”模式
通过"对象创建"模式绕开new，来避免对象创建(new)过程中所导致的紧耦合(依赖具体类)，从而支持对象创建的稳定，它是接口抽象之后的第一步工作。
+ [Simple-Factroy 简单工厂模式](Simple-Factroy/Simple-Factroy.md)
+ [Factory-Method 工厂方法模式](Factory-Method/Factory-Method.md)
+ [Abstract Factory 抽象工厂模式](Abstract-Factory/Abstract-Factory.md)
+ [Prototype 原型模式](Prototype/Prototype.md)
+ [Builder 建造者模式](Builder/Builder.md)

### “对象性能”模式
面向对象很好的解决了"抽象"的问题，但不可避免的要付出一定的代价。对于通常情况来讲，面向对象的成本大都可以忽略不计。但是某些情况，面型对象所带来的成本必须谨慎处理。
+ [Singleton 单例模式](Singleton/Singleton.md)
+ [Flyweight 享元模式](Flyweight/Flyweight.md)

### “接口隔离模式”
在组件构建过程中，某些接口之间直接的依赖常常会带来很多问题、甚至根本无法实现，采用添加一层间接(稳定)接口，来隔离本来相互紧密关联的接口是一种常见的解决方案。
+ [Façade 门面模式](Facade/Facade.md)
+ [Proxy 代理模式](Proxy/Proxy.md)
+ [Adapter 适配器模式](Adapter/Adapter.md)
+ [Mediator 中介者模式](Mediator/Mediator.md)

### “状态变化”模式
在组件构建过程中，某些对象的状态经常面临变化，如何对这些变化进行有效的管理？同时又维持高层模块的稳定？“状态变化”模式为这一问题提供了一种解决方案。
+ [State 状态模式](State/State.md)
+ [Memento 备忘录模式](Memento/Memento.md)

### “数据结构”模式
常常有一些组件在内部具有特定的数据结构，如果让客户程序依赖这些特定的数据结构，将极大的破坏组件的复用。这时候将这些特定数据结构封装在内部，在外界提供统一的接口，来实现与特定数据结构无关的访问，是一种行之有效的解决方案。
+ [Composite 组合模式](Composite/Composite.md)
+ [Iterator 迭代器模式](Iterator/Iterator.md)
+ [Chain-of-Resposibility 责任链模式](Chain-of-Resposibility/Chain-of-Resposibility.md)

### “行为变化”模式
在组件的构建过程中，组件行为的变化经常导致组件本身剧烈的变化。“行为变化”模式将组件的行为和组件本身进行解耦，从而支持组件行为的变化，实现两者之间的松耦合。
+ [Command 命令模式](Command/Command.md)
+ [Visitor 访问者模式](Visitor/Visitor.md)

### “领域规则”模式
在特定领域中，某些变化虽然频繁，但可以抽象为某种规则。这时候，结合特定领域，将问题抽象为语法规则，从而给出在该领域下的一般性解决方案。
+ [Interpreter 解析器模式](Interpreter/Interpreter.md)

## 重构获得模式 Refactoring to Pattern
面向对象设计模式是“好的面向对象设计”，所谓“好的面向对象设计”指是那些可以满足 “应对变化，提高复用”的设计 。

现代软件设计的特征是“需求的频繁变化”。设计模式的要点是“寻找变化点，然后在变化点处应用设计模式，从而来更好地应对需求的变化”.“什么时候、什么地点应用设计模式”比“理解设计模式结构本身”更为重要。

设计模式的应用不宜先入为主，一上来就使用设计模式是对设计模式的最大误用。没有一步到位的设计模式。敏捷软件开发实践提倡的“Refactoring to Patterns”是目前普遍公认的最好的使用设计模式的方法。

## 重构关键技法
静态 -> 动态
早绑定 -> 晚绑定
继承 -> 组合
编译时依赖 -> 运行时依赖
紧耦合 -> 松耦合