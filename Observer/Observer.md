# Observer 观察者模式
观察者模式是一种行为型设计模式，它定义了对象之间的一对多依赖关系，主要优点是实现对象间的解耦、支持广播通信、实时性高以及使用方便灵活等。

观察者模式通过定义对象之间的依赖关系，使得每当一个对象状态发生改变时，所有依赖于它的对象都会得到通知并被自动更新。这种模式广泛应用于实现事件处理系统、MVC框架的模型和视图同步以及任何需要多个对象间存在一对多关系的场景。

## “组件协作”模式:
现代软件专业分工之后的第一个结果是“框架与应用程序的划分”，“组件协作”模式通过晚期绑定，来实现框架与应用程序之间的松耦合，是二者之间协作时常用的模式。
典型模式
    • Template Method
    • Strategy
    • Observer / Event
    
## 动机（Motivation）
+ 在软件构建过程中，我们需要为某些对象建立一种“通知依赖关系” ——一个对象（目标对象）的状态发生改变，所有的依赖对
象（观察者对象）都将得到通知。如果这样的依赖关系过于紧密，将使软件不能很好地抵御变化。
+ 使用面向对象技术，可以将这种依赖关系弱化，并形成一种稳定的依赖关系。从而实现软件体系结构的松耦合。

## 模式定义
定义对象间的一种一对多（变化）的依赖关系，以便当一个对象(Subject)的状态发生改变时，所有依赖于它的对象都得到通知并自动更新。
——《 设计模式》 GoF


## 要点总结
+ 使用面向对象的抽象，Observer模式使得我们可以独立地改变目标与观察者，从而使二者之间的依赖关系达致松耦合。
+ 目标发送通知时，无需指定观察者，通知（可以携带通知信息作为参数）会自动传播。
+ 观察者自己决定是否需要订阅通知，目标对象对此一无所知。
+ Observer模式是基于事件的UI框架中非常常用的设计模式，也是MVC模式的一个重要组成部分。

## 优点
解耦：被观察者和观察者之间是松耦合的，这意味着你可以独立地改变和复用它们，而不会相互影响。
实时性：当被观察者的状态发生变化时，观察者可以立即得到通知并作出相应的处理。
灵活性：观察者模式提供了更灵活的协作机制，新的观察者可以很容易地加入到系统中来。
动态交互：它允许在不知晓对方身份的情况下，实现对象间的动态交互。

## 深入理解
1. 角色划分：明确识别出观察者（Observer）和被观察者（Subject）两种角色。
2. 状态变更通知：当被观察者对象的状态发生改变时，需要有一种机制让所有依赖于它（即观察者）得到通知并自动更新。
3. 推拉模型：根据信息的传递方式，观察者模式可以分为推模型和拉模型。在推模型中，被观察者将信息推送给观察者；而在拉模型中，观察者主动从被观察者那里获取信息。

## 观察者和被观察者
观察者（Observer）和被观察者（Subject）是观察者模式中的两个主要角色，它们之间存在一对多的依赖关系。当被观察者对象的状态发生改变时，所有依赖于它的观察者对象都会得到通知并自动更新。这种模式使得对象可以动态地建立协作关系，而不需要直接的引用，从而实现了对象之间的解耦。具体如下：

1. 被观察者（Subject）：在观察者模式中，被观察者是那个可能会发生变化的对象，它维护着一个观察者列表，并在自身状态发生变化时负责通知这些观察者。被观察者可以是任何能够发送状态变化通知的对象，比如上文提到的水壶。被观察者通常包含添加观察者、移除观察者和通知观察者的接口。

2. 观察者（Observer）：观察者则是那些需要响应被观察者状态变化的对象的抽象。在实际的状态变化通知过程中，观察者通常会实现某个特定接口（如update方法），以便在接收到通知时执行相应的动作。观察者可以是任何对被观察者状态变化感兴趣的对象，它们之间不必相互了解，只需要知道被观察者即可。



## 适用场景
1. 数据同步更新：当一个对象的数据或状态更新需要其他对象同步更新时，如MVC框架中的模型与视图的同步。
2. 事件多级触发：在系统内存在事件多级触发的情况，例如用户界面操作触发一连串后端服务响应。
3. 消息中间件：在分布式系统中，用于组件之间的消息发布与订阅，如消息队列处理机制。
4. 跨系统通信：适用于跨系统的消息交换场景，比如不同服务之间的状态通知与数据同步。


## 例子
```cpp
#include <bits/stdc++.h>

// 观察者模式

class Observer; // 向前声明观察者

// 抽象被观察者
class Subject {
public:
    Subject() : m_nState(0) {}

    virtual ~Subject() = default;

    virtual void Attach(const std::shared_ptr<Observer> pObserver) = 0;     // 添加观察者

    virtual void Detach(const std::shared_ptr<Observer> pObserver) = 0;     // 删除观察者

    virtual void Notify() = 0;  // 通知观察者，使用观察者指针调用观察者的相应接口(update)

    virtual int GetState() { return m_nState; } // 获得状态

    void SetState(int state) {  // 设置状态(改变状态)
        std::cout << "Subject updated !" << std::endl;
        m_nState = state;
    }

protected:
    std::list<std::shared_ptr<Observer>> m_pObserver_list;  // 观察者指针列表
    int m_nState;   // 状态/信息
};

// 抽象观察者
class Observer {
public:
    virtual ~Observer() = default;

    Observer(const std::shared_ptr<Subject> pSubject, const std::string& name = "unknown")
        : m_pSubject(pSubject), m_strName(name) {}

    virtual void Update() = 0;  // 响应被观察者状态变化,在接收到通知时执行相应的动作

    virtual const std::string& name() { return m_strName; }

protected:
    std::shared_ptr<Subject> m_pSubject;    // 被观察者指针，用于获取被观察者的状态/信息
    std::string m_strName;
};

// 具体被观察者
class ConcreteSubject : public Subject {
public:
    void Attach(const std::shared_ptr<Observer> pObserver) override {
        auto iter = std::find(m_pObserver_list.begin(), m_pObserver_list.end(), pObserver);
        if (iter == m_pObserver_list.end()) {
            std::cout << "Attach observer" << pObserver->name() << std::endl;
            //m_pObserver_list.emplace_back(pObserver);
            m_pObserver_list.push_back(pObserver);
        }
    }

    void Detach(const std::shared_ptr<Observer> pObserver) override {
        std::cout << "Detach observer" << pObserver->name() << std::endl;
        m_pObserver_list.remove(pObserver);
    }

    // 循环通知所有观察者
    void Notify() override {
        for (auto it = m_pObserver_list.begin(); it != m_pObserver_list.end(); it++)
        {
            (*it)->Update();
        }
    }
};


//具体观察者1
class Observer1 : public Observer {
public:
    Observer1(const std::shared_ptr<Subject> pSubject, const std::string& name = "unknown")
        : Observer(pSubject, name) {}

    void Update() override {
        std::cout << "Observer1_" << m_strName << " get the update. New state is: " << m_pSubject->GetState() << std::endl;
    }
};

//具体观察者2
class Observer2 : public Observer {
public:
    Observer2(const std::shared_ptr<Subject> pSubject, const std::string& name = "unknown")
        : Observer(pSubject, name) {}

    void Update() override {
        std::cout << "Observer2_" << m_strName << " get the update.New state is: "
            << m_pSubject->GetState() << std::endl;
    }
};


int main() {
    // 创建被观察者
    std::shared_ptr<Subject> pSubject = std::make_shared<ConcreteSubject>();

    // 创建观察者
    std::shared_ptr<Observer> pObserver1_1 = std::make_shared<Observer1>(pSubject, "1");
    std::shared_ptr<Observer> pObserver1_2 = std::make_shared<Observer1>(pSubject, "2");
    std::shared_ptr<Observer> pObserver1_3 = std::make_shared<Observer1>(pSubject, "3");

    std::shared_ptr<Observer> pObserver2_4 = std::make_shared<Observer2>(pSubject, "4");
    std::shared_ptr<Observer> pObserver2_5 = std::make_shared<Observer2>(pSubject, "5");
    std::shared_ptr<Observer> pObserver2_6 = std::make_shared<Observer2>(pSubject, "6");

    // 注册观察者
    pSubject->Attach(pObserver1_1);
    pSubject->Attach(pObserver1_2);
    pSubject->Attach(pObserver1_3);
    pSubject->Attach(pObserver2_4);
    pSubject->Attach(pObserver2_5);
    pSubject->Attach(pObserver2_6);

    pSubject->SetState(2);// 改变状态
    pSubject->Notify(); // 通知所有观察者

    std::cout << std::string(50, '-') << std::endl; 

    // 注销观察者
    pSubject->Detach(pObserver1_1);
    pSubject->Detach(pObserver1_2);

    pSubject->SetState(3);
    pSubject->Notify();

    return 0;
}

//运行结果如下：
//Attach observer1
//Attach observer2
//Attach observer3
//Attach observer4
//Attach observer5
//Attach observer6
//Subject updated !
//Observer1_1 get the update.New state is: 2
//Observer1_2 get the update.New state is: 2
//Observer1_3 get the update.New state is: 2
//Observer2_4 get the update.New state is: 2
//Observer2_5 get the update.New state is: 2
//Observer2_6 get the update.New state is: 2
//--------------------------------------------------
//Detach observer1
//Detach observer2
//Subject updated !
//Observer1_3 get the update.New state is: 3
//Observer2_4 get the update.New state is: 3
//Observer2_5 get the update.New state is: 3
//Observer2_6 get the update.New state is: 3
```