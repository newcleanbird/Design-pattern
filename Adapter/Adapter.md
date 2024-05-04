# Adapter 适配器
C++适配器模式（Adapter Pattern）是一种结构型设计模式，它允许将不兼容的接口转换为客户所需的接口，从而使原本无法协同工作的类能够一起工作。适配器模式主要用于解决两个已有类之间接口不匹配的问题，它通过创建一个新的适配器类来包装原有的接口，使得新接口能够符合客户的期待。

## 动机(Motivation)
+ 由于应用环境的变化，常常需要将”一些现存的对象“放在新的环境中应用，但是新环境要求的接口是这些现存对象所不满足。
+ 如何应对这些”迁移的变化“？

## 模式定义
将一个类的接口转换成客户希望的另一个接口。Adapter模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
——《设计模式》GoF

## 要点总结
+ 在遗留代码复用、类库迁移等方面有用

## 深入理解
### 适配器模式的组成部分：
1. 目标接口（Target Interface）：这是客户代码期望的接口，适配器类将转换后的接口呈现给客户。
2. 适配者（Adaptee）：拥有特定接口的现有类，但不符合客户的需求。
3. 适配器（Adapter）：将适配者的接口转换为客户所期待的目标接口的类。适配器可以是类适配器（通过多重继承实现）或对象适配器（通过组合实现）。

### 优点：
1. 兼容性增强：可以让旧的或外部组件与现有系统无缝集成，无需修改原有代码。
2. 灵活性高：通过适配器模式，可以动态地调整和配置系统行为，增加新功能而不改变系统结构。
3. 遵循开闭原则：可以在不修改原有类的基础上，通过增加适配器类来实现新的功能，符合软件设计的开放封闭原则。
4. 易于测试：适配器模式可以用来为难以测试的类提供测试接口，便于单元测试。

### 注意事项：
1. 设计复杂度：过多的适配器可能会增加系统的复杂度，尤其是在接口繁多的情况下。
2. 性能开销：适配器模式可能会引入额外的间接调用，影响性能，尤其是在性能敏感的应用中需权衡使用。
3. 适配器的选择：类适配器通过继承实现，可能导致类继承层次过深；对象适配器通过组合实现，更加灵活但可能需要更多代码来转发调用。
4. 接口设计：适配器接口应该简洁明了，尽量减少不必要的方法，以免增加适配器的实现负担。

### 深入理解：
适配器模式不仅仅是接口转换那么简单，它体现了设计模式中的一个重要思想：解耦。通过适配器，我们可以在不修改原有代码的基础上，实现新老接口的兼容，或是让不同来源的组件协同工作，这大大增强了系统的灵活性和可扩展性。适配器模式鼓励我们面向接口编程，而非具体实现，有助于构建松耦合的系统。

### 适用情况：
1. 系统升级或整合：在升级系统时，新旧模块间接口不兼容，需要适配器来桥接。
2. 第三方库集成：需要使用外部库，但库的接口与当前系统不一致。
3. 遗留系统改造：对旧系统进行重构成本高，可通过适配器模式逐步迁移。
4. API标准化：统一不同服务或模块的接口，使其符合统一的标准或规范。

### 面向对象特性的体现
1. 多态性：适配器模式利用多态机制，使得适配器类可以像目标接口那样被使用，即使它内部可能调用了一个完全不同的接口。这种抽象和接口的统一，让客户端代码可以以统一的方式与不同类型的对象交互。

2. 封装：适配器模式通过封装不兼容的接口，隐藏了适配者类的复杂性，使得客户端无需了解适配者类的实现细节。这种封装不仅简化了客户端代码，也使得系统更容易维护和扩展。

3. 继承与组合：适配器的实现有两种常见方式：类适配器（使用继承）和对象适配器（使用组合）。类适配器通过继承来实现目标接口，而对象适配器通过组合的方式包含一个适配者对象的实例，体现了面向对象中的继承和组合两种基本关系。

### 独特设计思路和哲学
1. 解耦：适配器模式的核心思想是解耦。它将接口的转换逻辑集中在一个地方处理，而不是散落在整个应用程序中。这样，当接口发生变化时，只需修改适配器，无需改动其他部分，降低了系统的耦合度。

2. 重用性：通过适配器，现有的类可以不经修改就融入新的系统中，提高了代码的重用性。适配器模式鼓励复用而不是重新发明轮子，符合软件工程的经济原则。

3. 开放/封闭原则：适配器模式通过添加新的适配器类来适应变化，而不是修改现有的适配器或目标接口，这遵循了“对扩展开放，对修改关闭”的设计原则。

### 设计模式特点
1. 结构型模式：适配器模式属于结构型设计模式，因为它关注如何组织类和对象的结构，以提供更灵活、更有效的设计。

2. 灵活性：适配器模式增加了系统的灵活性，使得系统能够更容易地应对接口变化，适应新的需求或环境。

3. 非侵入性：适配器模式的实现尽量不对原有的适配者类进行修改，保持了适配者类的独立性，体现了设计模式的非侵入性特点。

## 例子
以下是一个C++标准的适配器模式示例，这个例子中我们将模拟一个场景，其中有一个音频播放器只能播放MP3Player接口的音乐文件，但我们有一个AudioFile类库，它包含一个只支持WAVFile接口的音频文件。为了使播放器能够播放WAVFile格式的音频，我们需要创建一个适配器来适配这两个不兼容的接口。
```cpp
// 接口定义
// 首先，定义两个接口：MP3Player（播放器期望的接口）和WAVFile（现有音频文件的接口）。

class MP3Player {
public:
    virtual void play() = 0;
    virtual ~MP3Player() {}
};

class WAVFile {
public:
    virtual void playWAV() = 0;
    virtual ~WAVFile() {}
};

// 实现类
// 然后，实现MP3Player接口的类和WAVFile接口的类。

// 目标接口（Target Interface）
class ConcreteMP3Player : public MP3Player {
public:
    void play() override {
        std::cout << "Playing MP3 file." << std::endl;
    }
};

// 适配者（Adaptee）
class ConcreteWAVFile : public WAVFile {
public:
    void playWAV() override {
        std::cout << "Playing WAV file." << std::endl;
    }
};

// 适配器类
// 接下来，创建适配器类WAVToMP3Adapter，让它同时实现MP3Player接口，并在内部持有WAVFile的实例，从而将playWAV方法转换为play方法。

class WAVToMP3Adapter : public MP3Player {
private:
    WAVFile* wavFile;
public:
    WAVToMP3Adapter(WAVFile* file) : wavFile(file) {}

    void play() override {
        wavFile->playWAV(); // 调用WAVFile的playWAV方法
    }
};

// 客户端代码
// 最后，客户端代码通过适配器来播放WAVFile格式的音频。

int main() {
    ConcreteWAVFile wavFile;
    WAVToMP3Adapter adapter(&wavFile);

    // 使用适配器播放WAV文件
    adapter.play();

    return 0;
}
```
在这个例子中，WAVToMP3Adapter就是适配器，它使得ConcreteWAVFile（原本不能被MP3Player直接使用的类）能够通过适配后，满足MP3Player的接口要求，从而达到兼容播放的目的。这就是适配器模式的基本应用，它使得原本不兼容的接口能够协同工作，增强了系统的灵活性和可重用性。