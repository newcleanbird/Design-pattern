# Singleton 单例模式

单例模式是一种创建型设计模式，它保证一个类在整个应用程序中仅有一个实例，并提供一个全局访问点来获取这个实例。单例模式常用于那些需要控制资源访问、协调操作或提供全局服务的场景。在C++中，实现单例模式可以通过多种方式，但关键在于确保类的实例化过程受控且唯一。

## 动机(Motivation)

+ 在软件系统中，经常有这样一些特殊的类，必须保证它们在系统中只存在一个实例，才能确保它们的逻辑正确性、以及良好的效率。
+ 如何绕过常规的构造器，提供一种机制来保证一个类只有一个实例？
+ 这应该是类设计者的责任，而不是使用者的责任。

## 模式定义

保证一个类仅有一个实例，并提供一个该实例的全局访问点。
——《设计模式》GoF

## 要点总结

+ Singleton模式中的实例构造器可以设置为protected以允许子类派生。
+ Singleton模式一般不要支持拷贝构造函数和Clone接口，因为这有可能导致多个对象实例，与Singleton模式的初中违背。
+ 如何实现多线程环境下安全的Singleton？注意对双检查锁的正确实现。

## 详解

### 基本实现方式

1. 懒汉式（Lazy Initialization）：在首次请求实例时才创建单例对象。需注意线程安全问题。
2. 饿汉式（Eager Initialization）：在类加载时就立即创建单例对象，保证线程安全，但可能会造成资源浪费。
3. 双重检查锁定（Double-Checked Locking）：结合懒汉式和性能优化，减少锁的开销，同时保证线程安全。
4. 局部静态变量（C++11之后推荐）：利用局部静态变量的特性，实现线程安全且高效的单例初始化。

```cpp
class Singleton {
private:
    Singleton() {} // 私有构造函数
    Singleton(const Singleton&) = delete; // 禁止拷贝构造
    Singleton& operator=(const Singleton&) = delete; // 禁止赋值操作

public:
    static Singleton& getInstance() {
        static Singleton instance; // 局部静态变量，线程安全且懒惰初始化
        return instance;
    }

    // 其他公共接口函数...
};
```

### 优点

1. 控制资源访问：对于那些需要控制共享资源访问的场景，如数据库连接池、日志文件等，单例模式提供了一个全局访问点。
2. 简化配置：单例对象可以作为配置的中心点，使得配置的修改对整个应用的影响集中且可控。
3. 全局唯一性：保证某些操作的唯一性，比如序列号生成器、线程池管理器等。

### 缺点

1. 一般没有接口，扩展困难。原因：接口对单例模式没有任何意义；要求“自行实例化”，并提供单一实例，接口或抽象类不可能被实例化。（当然，单例模式可以实现接口、被继承，但需要根据系统开发环境判断）
2. 单例模式对测试是不利的。如果单例模式没完成，是不能进行测试的。
3. 单例模式与单一职责原则有冲突。原因：一个类应该只实现一个逻辑，而不关心它是否是单例，是不是要单例取决于环境；单例模式把“要单例”和业务逻辑融合在一个类。

### 注意事项

1. 线程安全：确保单例的创建是线程安全的，特别是在多线程环境下。
2. 测试困难：由于单例的全局状态，它可能会使单元测试变得复杂，因为测试之间会共享状态。
3. 滥用风险：过度使用单例可能会导致过度耦合，降低代码的可测试性和可维护性。
4. 扩展性：单例模式可能限制了对象的扩展性，特别是在需要多个实例或不同配置的场景下。
5. 类中其他方法，尽量是static。

### 如何深入理解

1. 模式对比：将单例模式与其他创建型模式（如工厂模式、构建器模式）进行对比，理解它们之间的应用场景和优缺点。
2. 设计原则：思考单例模式如何体现设计模式的原则，如单一职责原则、开闭原则等。
3. 源码分析：研究开源库或框架中的单例实现，理解它们如何处理线程安全、初始化时机等问题。
4. 实践与反思：在实际项目中尝试应用单例模式，并反思其带来的好处与潜在问题。

### 适用情况

1. 资源共享：需要控制对共享资源（如数据库、硬件设备）的访问时。
2. 全局服务：提供如日志记录、配置管理等全局服务的场景。
3. 控制行为：需要控制某个行为或操作在应用程序中只发生一次时，如初始化操作。
4. 要求生成唯一序列化的环境.
5. 项目需要的一个共享访问点或共享的数据点.
6. 创建一个对象需要消耗资源过多的情况。如：要访问IO和 数据库等资源。
7. 需要定义大量的静态常量和静态方法（如工具类）的环境。可以采用单例模式或者直接声明static的方式。

### 面向对象特性的体现

1. 封装: 单例模式通过将实例化的细节隐藏在类内部，确保了对象创建过程对外界的不可见性，这是封装原则的直接体现。外部用户无需知道单例是如何被创建的，只需通过一个公共接口获取实例即可。

2. 抽象: 单例模式强调的是“全局唯一实例”的概念，而非具体的实现细节。这鼓励我们关注于接口（即获取单例的方法）而非实现，体现了抽象思维。

3. 继承与多态（非直接相关，但在设计上可考虑）: 虽然单例模式本身不直接依赖于继承或多态，但在复杂的系统设计中，单例类可以通过继承自一个抽象基类来实现多态性，从而允许在不同的上下文中复用单例模式的逻辑，同时也保持了设计的灵活性。

### 独特设计思路

1. 全局唯一性: 单例模式的核心在于确保一个类在任何时刻、任何位置都只有一个实例存在。这种设计思路直接应对了需要全局控制资源或行为的需求，如配置管理、日志记录等场景。

2. 延迟初始化: “懒汉”式的单例实现体现了延迟初始化的思想，即直到真正需要时才创建实例，这样可以节省资源，尤其是在对象创建成本较高或不总是需要的情况下。

3. 控制访问: 通过私有构造函数、拷贝构造函数及赋值运算符的禁用，单例模式严格控制了对象的创建和复制，确保了全局唯一性的实现。

### 设计模式的特点体现

1. 可重用性: 单例模式提供了一种通用的解决方案来处理需要全局访问点的问题，可以在不同的项目或系统中重复使用这一模式。

2. 灵活性与扩展性: 虽然单例模式有时因全局状态而受到批评，但通过设计良好的接口和遵循开放封闭原则，单例类可以被灵活替换或扩展，以适应变化的需求。

3. 设计哲学: 单例模式体现了设计模式的“模式而非巧合”原则，即通过一种经过验证的、标准化的方式来解决常见问题，而非每次遇到问题时都从零开始设计。

## 单例模式的实现

### 懒汉式

#### 懒汉式SingletonLazy(线程非安全版)

特点：延迟创建对象实例(延迟加载，懒汉么，很懒，它只在要用到实例时才加载实例)，避免了不必要的资源消耗，但是在多线程环境中线程不安全，需要加锁保证线程安全。

适用情况: 单例对象的创建和初始化过程比较耗时，而且在程序运行过程中可能并不总是需要使用该对象，对资源敏感时也不叫使用，如果线程安全没什么要求，也可以用。

```cpp
#include<iostream>

using namespace std;

class Singleton {
public:
    // 获取单实例对象
    static Singleton* getInstance() 
    {
        if (instance == nullptr) 
        {
            instance = new Singleton();
        }
        return instance;
    }
private:
    static Singleton* instance;
    Singleton() {} // 私有构造函数
};

// 类定义外部初始化静态成员
Singleton* Singleton::instance = nullptr;

// 使用单例
int main() {
    // 获取单例对象
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // 检查是否为同一个实例
    if(s1 == s2) {
        std::cout << "s1 和 s2 是同一个实例" << std::endl;
    } else {
        std::cout << "s1 和 s2 不是同一个实例" << std::endl;
    }

    return 0;
}
```

+ 注意：当前实现方案，没有释放instance指针。

#### 懒汉式(单锁版 线程安全版本，但锁的代价过高)

增加锁，改进以支持多线程， 确保线程安全，但锁的代价过高。
**注意**：在高并发的场景下，不适用。

```cpp
//线程安全版本，但锁的代价过高
Singleton* Singleton::getInstance() {
    Lock lock;  // 全局加锁，函数结束析构自动释放锁
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;// 对于都是读操作的高并发情形，锁的代价过高
}
```

#### 懒汉式（线程安全，双重检查锁定）SingletonLazyDCLP

双重检查锁定(DCLP)在懒汉式基础上增加线程安全性，减少锁的开销：

注意：

```cpp
//双检查锁(非常经典)，但由于内存读写reorder不安全
class SingletonLazyDCLP {
private:
    static SingletonLazyDCLP* instance;
    SingletonLazyDCLP() {} // 私有构造函数
public:
    static SingletonLazyDCLP* getInstance() {
        if (instance == nullptr) {
            std::lock_guard<std::mutex> lock(mutex); // 加锁
            if (instance == nullptr) { // 第二次检查
                instance = new SingletonLazyDCLP();
            }
        }
        return instance;
    }
private:
    static std::mutex mutex;
};

// 类定义外部初始化静态成员
SingletonLazyDCLP* SingletonLazyDCLP::instance = nullptr;
std::mutex SingletonLazyDCLP::mutex;
```

##### 双检锁（Double-Checked Locking）失效问题

双检锁（Double-Checked Locking）在某些情况下可能不是线程安全的，尤其是在特定的编译器和硬件平台上。这是由于编译器和处理器的优化行为可能导致双检锁失效，从而导致多个线程同时创建实例。

具体来说，双检锁的问题源于指令重排序（instruction reordering）和多核处理器的内存可见性（memory visibility）。编译器和处理器为了提高执行效率，可能会对代码中的指令进行重排序，而不考虑程序员的意图。这种重排序可能会导致在检查 instance 是否为 nullptr 之后，但在实际创建实例之前，另一个线程就已经读取到了一个尚未完全初始化的实例。

使用new时：
    1. 先分配内存
    2. 调用构造器，对分配的内存进行初始化
    3. 将得到的指针给`instance`

在指令级别有可能会被`reorder`
顺序可能会被改变，编译器出于优化的原因。

因此改进方案是:

+ 使用std::atomic：自C++11起，推荐使用std::atomic来管理共享资源，如将单例实例指针声明为std::atomic<Singleton*>。std::atomic不仅提供了内存顺序的控制，还能确保对它的读写操作是原子的，有效避免了指令重排序问题。

+ 内存屏障：在适当的位置插入内存屏障（如通过std::atomic_thread_fence）来禁止特定的指令重排序，确保对象的初始化对所有线程都是可见的。

+ C++11及以上版本的内存模型：利用C++11及以后版本的内存模型提供的原子操作和内存顺序语义来编写线程安全的代码，避免了早期C++版本中内存模型不明确导致的问题。

#### 懒汉式(C++11) atomic实现，解决双检锁

懒汉式 C++ 11版本之后的跨平台实现 (volatile)

```cpp
std::atomic<Singleton*> Singleton::m_instance;  // 原子对象
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
    Singleton* tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire);//获取内存fence // 内存屏障,reorder的保护
    if (tmp == nullptr) {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr) {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release);//释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}
```

#### 使用 C++11 std::call_once 实现的懒汉单例

使用 C++11 std::call_once 实现的懒汉单例，C++11 线程安全。

```cpp
#include <iostream>
#include <memory>
#include <mutex>

class Singleton {
public:
    static std::shared_ptr<Singleton> getSingleton();

    void print() {
        std::cout << "Hello World." << std::endl;
    }

    ~Singleton() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

private:
    Singleton() {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
};

static std::shared_ptr<Singleton> singleton = nullptr;
static std::once_flag singletonFlag;

std::shared_ptr<Singleton> Singleton::getSingleton() {
    std::call_once(singletonFlag, [&] {
        singleton = std::shared_ptr<Singleton>(new Singleton());
    });
    return singleton;
}
```

#### 静态局部变量的懒汉单例（推荐）

这种方式在 C++11 下是线程安全的。这种单例实现方式称为 [Meyer’s Singleton](https://laristra.github.io/flecsi/src/developer-guide/patterns/meyers_singleton.html) 。

```cpp
///  内部静态变量的懒汉实现  //

class Single
{

public:
    // 获取单实例对象
    static Single& GetInstance();
 
    // 打印实例地址
    void Print();

private:
    // 禁止外部构造
    Single();

    // 禁止外部析构
    ~Single();

    // 禁止外部拷贝构造
    Single(const Single &single) = delete;

    // 禁止外部赋值操作
    const Single &operator=(const Single &single) = delete;
};

Single& Single::GetInstance()
{
    /**
     * 局部静态特性的方式实现单实例。
     * 静态局部变量只在当前函数内有效，其他函数无法访问。
     * 静态局部变量只在第一次被调用的时候初始化，也存储在静态存储区，生命周期从第一次被初始化起至程序结束止。
     */
    static Single single;
    return single;
}

void Single::Print()
{
    std::cout << "我的实例内存地址是:" << this << std::endl;
}

Single::Single()
{
    std::cout << "构造函数" << std::endl;
}

Single::~Single()
{
    std::cout << "析构函数" << std::endl;
}
```

#### 懒汉式存在释放指针的问题

大多数时候，这样的实现都不会出现问题。有经验的读者可能会问，instance指向的空间什么时候释放呢？更严重的问题是，该实例的析构函数什么时候执行？
如果在类的析构行为中有必须的操作，比如关闭文件，释放外部资源，那么上面的代码无法实现这个要求。我们需要一种方法，正常的删除该实例。
可以在程序结束时调用GetInstance()，并对返回的指针掉用delete操作。这样做可以实现功能，但不仅很丑陋，而且容易出错。因为这样的附加代码很容易被忘记，而且也很难保证在delete之后，没有代码再调用GetInstance函数。

##### 使用内嵌类

一个妥善的方法是让这个类自己知道在合适的时候把自己删除，或者说把删除自己的操作挂在操作系统中的某个合适的点上，使其在恰当的时候被自动执行。
我们知道，程序在结束的时候，系统会自动析构所有的全局变量。事实上，系统也会析构所有的类的静态成员变量，就像这些静态成员也是全局变量一样。利用这个特征，我们可以在单例类中定义一个这样的静态成员变量，而它的唯一工作就是在析构函数中删除单例类的实例。如下面的代码中的Garbo类（Garbo意为垃圾工人）：

```cpp
class Singleton  
{  
private:  
    Singleton()  
    {  
    }  
    static Singleton *instance;  
    class Garbo   //它的唯一工作就是在析构函数中删除Singleton的实例，也常声明为 Del
    {  
    public:  
        ~CGarbo()  
        {  
            if(Singleton::instance)  
                delete Singleton::instance;  
        }  
    };  
    static CGarbo Garbo;  //定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数  
public:  
    static Singleton * getInstance()  
    {  
        if(instance == NULL)  //判断是否第一次调用  
            instance = new Singleton();  
        return instance;  
    }  
};  

// 类定义外部初始化静态成员
Singleton* Singleton::instance = nullptr;
```

进一步的讨论：

但是添加一个类的静态对象，总是让人不太满意，所以考虑采用静态变量(饿汉式)的实现方式。

##### 使用智能指针

```cpp
#include <mutex>
#include <memory>

class SingletonLazy {
public:
    static SingletonLazy& getInstance() {
        std::call_once(initInstanceFlag, &SingletonLazy::initSingleton);
        return *instance.get();
    }

    // 删除拷贝构造函数和赋值运算符以防止拷贝
    SingletonLazy(const SingletonLazy&) = delete;
    SingletonLazy& operator=(const SingletonLazy&) = delete;

    ~SingletonLazy() {
        // 可以在这里放置清理资源的代码，但智能指针会自动管理内存
    }

private:
    SingletonLazy() {} // 私有构造函数

    static void initSingleton() {
        instance.reset(new SingletonLazy());
    }

    static std::once_flag initInstanceFlag;
    static std::unique_ptr<SingletonLazy> instance;
};

// 类外初始化静态成员
std::once_flag SingletonLazy::initInstanceFlag;
std::unique_ptr<SingletonLazy> SingletonLazy::instance = nullptr;

// 使用示例
int main() {
    SingletonLazy& singleton = SingletonLazy::getInstance();
    // 使用singleton...
    return 0;
}
```

#### 懒汉式最佳实现(静态局部变量+智能指针)

使用C++11，结合静态局部变量和智能指针（如std::unique_ptr）来实现懒汉式单例模式，可以在确保线程安全的同时，有效地管理资源的生命周期。

1. 静态局部变量：在C++11及以后版本中，静态局部变量的初始化是线程安全的，这意味着无需手动添加锁机制就能保证单例实例在多线程环境下的唯一性和初始化的正确顺序。这种方式简洁高效，避免了不必要的同步开销。

2. 智能指针（如std::unique_ptr或std::shared_ptr）：使用智能指针来管理单例实例的生命周期，可以确保资源的自动回收，即使是在复杂的程序环境中也能避免内存泄漏的问题。这对于保证程序的健壮性和减少手动资源管理错误非常关键。

```cpp
#include <memory>

class SingletonLazy {
public:
    static SingletonLazy& getInstance() {
        static std::unique_ptr<SingletonLazy> instance = std::make_unique<SingletonLazy>();
        return *instance;
    }

    // 禁止拷贝和赋值
    SingletonLazy(const SingletonLazy&) = delete;
    SingletonLazy& operator=(const SingletonLazy&) = delete;

private:
    SingletonLazy() {} // 私有构造函数，防止外部直接实例化
    ~SingletonLazy() {} // 析构函数，智能指针会自动调用
};

// 使用示例
int main() {
    SingletonLazy& singleton = SingletonLazy::getInstance();
    // 使用singleton...
    return 0;
}
```

在这个实现中，利用了C++11标准中静态局部变量的线程安全初始化特性。getInstance方法内定义了一个静态的std::unique_ptr成员instance，它会在首次调用时构造单例对象，并由智能指针自动管理其生命周期，确保了单例对象在不再需要时能够被正确销毁并释放资源。

由于C++11标准保证了静态局部变量的初始化是线程安全的，并且只执行一次，所以这种方法自然地避免了多线程环境下的竞争条件，同时也无需显式地使用锁或其他同步机制，代码更简洁且高效。

### 饿汉式

特点：实现简单，线程安全，但可能造成内存浪费
适用情况: 单例对象在程序运行过程中频繁被调用

饿汉式是最简单的一种单例模式实现方式，它在程序启动时(类加载时)就创建了单例对象，要用时直接返回即可，因此也被称为“急切创建”方式。这种方式的优点是实现简单且线程安全，因为这种方式在单例对象被使用之前就已经创建好了，因为所以线程都只能访问一个已存在的对象，无论线程怎么调度都不会有多个对象出现。因为对象是一个静态变量（不是指针），会在程序结束时自动调用它的析构函数，所以不用考虑内存泄露问题，但会提前占用资源。
饿汉式单例模式的实现方式一般是将单例模式定义为静态成员变量，并在类定义中就初始化它，这样单例对象就会在类装载的时候进行创建，在整个程序结束时按序销毁。

```cpp
#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {} // 私有构造函数，防止外部直接实例化
    static Singleton instance; // 声明静态实例变量

public:
    static Singleton& GetInstance() {
        return instance; // 返回静态实例的引用
    }
};

// 初始化静态成员变量instance
Singleton Singleton::instance;

int main() {
    Singleton& singleton1 = Singleton::GetInstance();
    Singleton& singleton2 = Singleton::GetInstance();

    // 检验是否为同一实例
    if (&singleton1 == &singleton2) {
        cout << "singleton1 和 singleton2 是同一个实例" << endl;
    } else {
        cout << "singleton1 和 singleton2 不是同一个实例" << endl;
    }

    return 0;
}
```

声明一个局部的静态变量，而静态变量在全局范围内只有一份数据，所以无论调用多少此GetInstance，返回的都是那一个实例。

但这个实现存在问题，`Singleton singleton = Singleton :: GetInstance()`，这么做就出现了一个类拷贝的问题，这就违背了单例的特性。产生这个问题原因在于：因为在这里没有实现拷贝构造函数，编译器会为类生成一个默认的拷贝构造函数，来支持类的拷贝。

+ 实际上这一行不会引起类的拷贝构造或赋值运算符调用。这里使用的是`直接初始化`语法，而且因为 GetInstance() 方法返回的是一个对静态实例 instance 的引用，所以 singleton 直接被初始化为那个已经存在的实例的引用，而非通过拷贝构造或赋值操作创建新对象。
+ 等价于``Singleton& singleton = Singleton::GetInstance();``

但以下几种情况仍可能导致拷贝构造或赋值的发生：

+ 值传递或返回：如果在某个函数中，将Singleton类型的对象按值传递（作为参数或返回值），而不是引用或指针，这将会触发拷贝构造。

+ 容器存储：如果尝试将Singleton对象放入标准库容器（如`std::vector<Singleton>、std::list<Singleton>`等）中，容器在添加元素时会尝试复制对象。

+ 初始化列表：在类的初始化列表中直接用Singleton::GetInstance()初始化一个Singleton类型的成员变量，如果成员变量不是引用或指针类型，理论上会触发拷贝构造，但实际上现代编译器通常能优化避免这种情况（即直接构造或直接初始化）。

+ 显式拷贝或赋值：在代码中直接编写显式的拷贝或赋值语句，如 Singleton another = someSingleton; 或 another = Singleton::GetInstance();，这显然会触发拷贝构造或赋值操作。

+ 序列化/反序列化：如果涉及到对象的序列化和反序列化过程，可能需要特别注意，不当的实现可能会尝试复制对象。

#### 禁用拷贝构造函数和赋值运算符版

```cpp
class Singleton {
public:
    // 获取单例对象的静态方法
    static Singleton& getInstance() {
        return instance; // 直接返回已初始化的静态实例
    }

    // 删除拷贝构造函数和赋值运算符，防止拷贝
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

private:
    // 私有构造函数，防止外部直接创建实例
    Singleton() {}

    // 静态私有成员变量，保存唯一实例
    static Singleton instance;
};

// 在类外初始化静态成员变量
Singleton Singleton::instance;

// 使用示例
int main() {
    Singleton& singleton1 = Singleton::getInstance();
    Singleton& singleton2 = Singleton::getInstance();

    // 检查是否为同一实例
    if (&singleton1 == &singleton2) {
        std::cout << "singleton1 和 singleton2 是同一个实例" << std::endl;
    } else {
        std::cout << "singleton1 和 singleton2 不是同一个实例" << std::endl;
    }

    return 0;
}
```

#### 指针版

```cpp
#include <iostream>

class SingletonEager {
private:
    SingletonEager() {} // 私有构造函数
    SingletonEager(const SingletonEager&) = delete; // 禁用拷贝构造
    SingletonEager& operator=(const SingletonEager&) = delete; // 禁用赋值运算符
    static SingletonEager instance;
public:
    static SingletonEager* getInstance() {
        return &instance;
    }
};

// 静态实例在编译期创建，线程安全
SingletonEager SingletonEager::instance;

int main() {
    // 测试单例模式
    SingletonEager* singleton1 = SingletonEager::getInstance();
    SingletonEager* singleton2 = SingletonEager::getInstance();

    // 验证两个指针是否指向同一地址，即验证是否为同一个实例
    if (singleton1 == singleton2) {
        std::cout << "singleton1 和 singleton2 是同一个实例" << std::endl;
    } else {
        std::cout << "singleton1 和 singleton2 不是同一个实例" << std::endl;
    }

    return 0;
}
```

### 单例模式什么时候用指针什么时候用变量？

在单例模式中，使用指针还是直接使用变量（对象实例）主要取决于如何管理资源以及如何确保线程安全。

1. 使用指针：
   + 资源管理：当单例对象需要动态分配时，通常会使用智能指针（如std::unique_ptr或std::shared_ptr）来管理内存。这样可以确保单例对象在不再需要时能够自动释放，避免内存泄漏。
   + 线程安全：在实现多线程安全的单例模式时，特别是在懒汉式实现中，可能最初会通过一个指针来延迟实例化，直到第一次请求时才创建单例对象。这时，指针初始为nullptr，并在需要时分配并初始化单例对象。
   + 灵活性：指针（尤其是智能指针）提供了更多的灵活性，例如通过继承来改变单例的类型。

2. 使用变量（对象实例）：
   + 静态局部变量：在C++中，懒汉式单例也可以通过静态局部变量来实现，这是因为C++11标准保证了静态局部变量的线程安全初始化。这种方式直接在内存中保留单例实例，无需额外的指针间接访问。
   + 简单性：如果确定单例对象在程序生命周期内始终存在，且大小固定，直接在类中定义一个静态变量（非指针）可以简化代码，减少资源管理和释放的复杂度。

### 懒汉式局部静态变量和饿汉式区别

1. 实例化时机：
   + 饿汉式：在类加载阶段就完成了单例对象的实例化。这意味着，不管后续是否真的需要这个单例，对象都会被创建出来。饿汉式的特点是急切地初始化，因此得名“饿汉”。
   + 懒汉式（局部静态变量实现）：单例对象的实例化被推迟到了第一次实际需要使用该实例时。也就是说，只有当调用获取单例的方法时，实例才会被创建。这种方式称为“懒加载”或“延迟初始化”，因此被称为“懒汉”。

2. 资源占用：
   + 饿汉式：由于在类加载时就创建了实例，因此会立即占用所需资源。对于资源消耗大的单例来说，这可能导致不必要的开销，尤其是在该单例可能根本不被使用的情况下
   + 懒汉式：由于实例化的延迟，只有在真正需要时才占用资源，这在一定程度上节省了系统资源，特别是对于那些不经常使用或者资源消耗大的单例。

3. 线程安全与复杂度：
   + 饿汉式：由于实例化发生在类加载时，而类加载是线程安全的，因此饿汉式天生是线程安全的，无需额外的同步措施。
   + 懒汉式：由于实例化发生在运行时，可能在多线程环境下引发竞态条件。使用局部静态变量实现的懒汉式（C++11及以上版本）利用了静态局部变量的线程安全初始化特性，因此天然避免了多线程问题，但如果是传统的懒汉式实现，则需要额外的同步机制（如互斥锁）来保证线程安全，这会增加实现的复杂度。

4. 性能：
   + 饿汉式：由于实例在一开始就创建，因此第一次访问时无需等待实例化，响应速度快。但在不需要该单例的情况下，可能会有轻微的启动时间增加。
   + 懒汉式：首次访问时需要实例化，可能会有轻微的延迟，但随后的访问与饿汉式一样快。对于大多数应用而言，这种延迟微乎其微，几乎可以忽略不计。

### 总结

**懒汉式（线程不安全版）**是最基础的实现，但在多线程环境下不可靠。
**饿汉式**解决了线程安全问题，但牺牲了部分资源效率，适用于资源占用不大或确定性高的场景。
**双重检查锁定**在懒汉式基础上增加了线程安全，是多线程环境下常用的懒汉式实现方式。
**局部静态变量**是C++11引入后推荐的实现方式，因为它既保证了线程安全，又利用了局部静态变量的延迟初始化特性，实现简单且高效。
