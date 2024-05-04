# Proxy 代理模式
代理模式（Proxy Pattern）是一种结构型设计模式，它的核心思想是在客户端和目标对象之间插入一个代理对象，这个代理对象作为目标对象的替代品，控制对目标对象的访问，从而实现额外的功能，比如访问控制、延迟初始化、统计调用次数等，而不需要修改目标对象的代码。

## 动机(Motivation)
+ 在面向对象系统中，有些对象由于某种原因(比如对象创建的开销很大，或者某些操作需要安全控制，或者需要进程外的访问等)，
直接访问会给使用者、或者系统结构带来很多麻烦。
+ 如何在不失去透明操作对象的同事来管理/控制这些对象特有的复杂性？增加一层间接层是软件开发中常见的解决方式。

## 模式定义
为其他对象提供一种代理以控制(隔离，使用接口)对这对象的访问。
——《设计模式》GoF

## 要点总结
+ Proxy并不一定要求保持接口完整的一致性，只要能够实现间接控制，有时候损及一些透明性是可以接受的。

## 深入
### 实现要点
1. 目标接口（Subject）：定义了目标对象和代理对象的共同接口，使得它们可以互换使用。
2. 目标对象（RealSubject）：真正执行业务逻辑的对象，实现了目标接口。
3. 代理对象（Proxy）：持有一个目标对象的引用，并实现了目标接口。代理对象在调用目标对象的方法前后，可以添加额外的处理逻辑。

### 优点
1. 增加灵活性：通过代理对象可以在不修改目标对象的前提下，增加额外功能，比如日志记录、权限校验、缓存等。
2. 控制访问：代理可以控制对目标对象的访问，例如限制访问次数、时间等。
3. 延迟初始化：虚拟代理可以延迟创建目标对象，直到真正需要时才创建，节省资源。
4. 提高安全性：保护代理可以为敏感操作提供安全检查，增强系统安全性。
5. 远程代理：用于处理不同地址空间的对象交互，隐藏网络通信细节。

### 注意事项
1. 避免过度设计：虽然代理模式可以提供很多便利，但不必要的代理会增加系统的复杂度和运行开销。
2. 清晰的职责界定：确保代理和目标对象的职责明确，避免职责混淆。
3. 性能考量：特别是对于频繁调用的操作，代理模式可能引入额外的性能开销，需要评估其影响。
4. 正确选择代理类型：根据具体需求选择合适的代理类型，如虚拟代理、远程代理或保护代理等。

### 适用情况
1. 需要对访问进行控制：当需要对对象的访问进行权限验证或计数时。
2. 延迟初始化：对象创建成本较高，希望在真正需要时才创建。
3. 远程服务调用：隐藏网络通信细节，简化客户端与远程服务的交互。
4. 增强功能：不改变原有对象的基础上，添加日志、监控、缓存等附加功能。
5. 保护资源：对敏感资源或操作进行保护，确保安全访问。

### 面向对象特性的体现
1. 封装：代理模式利用封装的概念，隐藏了目标对象的实现细节，通过代理类来控制对目标对象的访问。这样，客户端不需要知道目标对象的具体实现，只需与代理交互，这增加了系统的灵活性和可维护性。

2. 多态：代理模式通过继承或接口实现，可以利用多态特性，使得代理类和真实目标类可以被相同类型的引用来调用。这意味着客户端代码可以对代理和真实对象使用相同的接口，而无需关心具体类型，增强了代码的通用性和可扩展性。

3. 继承与接口：代理模式通常通过继承目标接口或持有目标对象的引用实现，体现了面向对象中的继承关系和关联关系，这使得代理能够在不修改目标类的基础上，添加额外的行为或责任。

### 内涵独特的设计思路
1. 代理模式的设计核心在于“代理”，即在客户端与目标对象之间插入一个中间层，这个中间层可以扮演多种角色，比如提供安全检查、延迟加载、访问控制、日志记录等，而这些功能的添加不会影响到目标对象的纯净性。

2. 灵活性与扩展性：代理模式允许在不修改目标对象的情况下，动态添加或改变目标对象的功能，这对于应对需求变化、增强系统灵活性非常有用。例如，通过引入不同类型的代理（如虚拟代理、远程代理、保护代理），可以轻松应对各种复杂场景。

3. 设计哲学：遵循“开放封闭原则”（Open/Closed Principle），即对扩展开放，对修改封闭。代理模式通过新增代理类来扩展系统功能，而不是修改现有目标类，保证了系统的稳定性和可维护性。

### 设计模式特点
1. 结构型模式：代理模式属于设计模式中的结构型模式，它关注的是如何将类或对象组合在一起形成更大的结构，以达到新的功能或更好的结构。

2. 解耦与控制：代理模式通过引入代理对象，有效地解耦了客户端与目标对象的直接依赖，为系统提供了控制点，使得可以在不改变目标对象的情况下，控制对目标对象的访问，增加了系统的可控制性和灵活性。

3. 策略性：代理模式在实现上提供了策略上的灵活性，可以根据具体需求选择不同类型的代理来应对不同的场景，如使用虚拟代理来实现懒加载，远程代理处理远程服务调用等。

## 例子
下面是一个C++标准代理模式的例子，展示了如何使用代理模式来实现图像的延迟加载。这个例子中，Image是目标接口，RealImage是实际加载图像的目标对象，而ImageProxy则是代理类，用于在真正需要时才加载图像，从而提高效率和节省资源。
```cpp
#include <iostream>
#include <memory>

// 目标接口：图像接口
class Image {
public:
    virtual ~Image() {}
    virtual void display() const = 0;
};

// 实际对象：真实图像类，负责从磁盘加载图像
class RealImage : public Image {
private:
    std::string filename;
public:
    RealImage(const std::string& filename) : filename(filename) {
        loadImageFromFile();
    }

    void display() const override {
        std::cout << "Displaying " << filename << std::endl;
    }

private:
    void loadImageFromFile() {
        std::cout << "Loading image from disk: " << filename << std::endl;
    }
};

// 代理对象：图像代理类，用于延迟加载图像
class ImageProxy : public Image {
private:
    std::shared_ptr<Image> realImage;
    std::string filename;
public:
    ImageProxy(const std::string& filename) : filename(filename) {}

    ~ImageProxy() {}

    void display() const override {
        if (!realImage) {
            realImage = std::make_shared<RealImage>(filename);
        }
        realImage->display();
    }
};

int main() {
    // 客户端代码仅与代理交互，不知道也不关心图像是否立即加载
    ImageProxy proxy("very_large_image.jpg");
    proxy.display();  // 第一次调用时，图像被加载
    proxy.display();  // 第二次调用时，图像已经加载，直接显示
    return 0;
}
```
在这个例子中，ImageProxy作为代理，只有在第一次调用display()方法时，才创建并加载真实的RealImage对象。之后的调用，由于realImage已经被实例化，所以直接显示图像，避免了重复加载，实现了延迟加载的目的。这个过程对客户端透明，客户端只需要与代理交互，降低了系统的耦合度，提高了性能。

### 深入理解例子
在上述示例中，代理层（ImageProxy）的核心作用在于延迟加载和减少不必要的资源消耗。让我们更细致地分析一下这个例子，以便理解代理层的重要性：

#### 没有代理层的情况
如果直接使用RealImage对象，每次创建对象时都会立即加载图像文件，这可能涉及到磁盘I/O操作，对于大型图像文件来说，这可能是耗时且资源密集的操作。考虑以下情况没有使用代理：
```cpp
int main() {
    RealImage realImage1("big_image1.jpg");
    realImage1.display(); // 加载并显示图像1
    RealImage realImage2("big_image2.jpg"); // 另一个图像，同样立即加载
    realImage2.display(); // 显示图像2
    return 0;
}
```
在这个场景中，即使我们只是想查看图像是否正确加载（通过display()方法），每个RealImage对象在构造时就已经完成了图像的加载。如果有多个这样的对象，且并非所有对象最终都会被展示（例如，用户可能中途取消操作），那么就浪费了资源和时间。

#### 使用代理层的好处
现在，让我们回到使用ImageProxy的场景：

1. 延迟加载: ImageProxy在构造时并不立即加载图像，而是等到display()方法被调用时才创建RealImage对象并加载图像。这意味着，如果某个图像最终没有被显示（比如用户操作改变），则不会发生不必要的加载操作。

2. 资源优化: 对于频繁创建和销毁的图像展示需求，或者在内存有限的环境下，代理模式能够显著减少内存占用。只有在真正需要时，才会占用资源加载图像。

3. 提升用户体验: 在某些应用场景下，用户可能不需要等待所有图像加载完毕就可以开始浏览部分内容。代理模式允许程序更快地响应用户操作，逐步加载内容，而不是阻塞等待所有资源准备就绪。

因此，虽然从代码层面看，代理层似乎只是简单地“多加了一层”，但它在实际应用中扮演着关键的角色，特别是在性能优化、资源管理以及提供更好的用户体验等方面。去除代理层可能简化了代码结构，但可能会导致效率低下、资源浪费和用户体验的下降。