# Visitor 访问者模式
访问者模式（Visitor Pattern）在C++中是一种行为设计模式，它使你能够在不修改对象结构中的元素的情况下定义作用于这些元素的新操作。访问者模式通过将操作的算法与对象结构分离，为对象结构中的每个元素提供一个访问接口，从而达到解耦的目的。下面是访问者模式的详细说明，包括其优点、注意事项以及适用情况。

## 动机(Motivation)
+ 由于需求的变化，某些类层次结构中常常需要增加新的行为(方法)，如果直接在基类中做这样的更改，
将会给子类带来很繁重的变更负担，甚至破坏原有设计。
+ 如何在不更改类层次结构的前提下，在运行时根据需要透明地为类层次结构上的各个类动态添加新的操作，从而避免上面的问题？

## 模式定义
表示一个作用与某对象结构中的各元素的操作。使得可以在不改变(稳定)各元素的类的前提下定义(扩展)
作用于这些元素的新操作(变化)。
——《设计模式》GoF

## 要点总结
+ Visitor模式通过所谓的双重分发来实现在不更改(编译时)Element类层次结构的前提下，在运行时
透明地为类层次结构上的各个类动态添加新的操作(支持变化)。
+ 所谓双重分发Visitor模式中间包括了两个多态分发：第一个为accept方法的多态辨析；第二个为visitElement方法的多态辨析。
+ Visitor模式的最大缺点在于扩展类层次结构(添加新的Element子类)，会导致Visitor类的改变，
因此Visitor模式适用于“Element类层次结构稳定，而其中的操作却经常面临频繁改动”。


## 访问者模式详解
### 访问者模式的核心组成
1. Visitor（访问者接口）: 定义了一个访问元素的接口，声明了对每个元素类的访问操作。
2. ConcreteVisitor（具体访问者类）: 实现Visitor接口中的操作，为每个具体元素类提供具体的访问操作实现。
3. Element（元素接口）: 定义了一个接受访问者的方法，通常是一个accept()方法。
4. ConcreteElement（具体元素类）: 实现Element接口，提供accept()方法的具体实现，用于接收访问者并调用访问者相应的方法。
5. ObjectStructure（对象结构）: 负责管理元素集合，可以提供高层接口供访问者遍历元素。

### 优点
1. 扩展性好: 可以在不修改元素类的前提下，通过添加新的访问者类来增加新的操作。
2. 分离操作和数据结构: 将数据结构和操作分离，使得两者可以独立变化。
3. 集中相关操作: 将相关的操作集中在一个访问者类中，使得代码更易于阅读和维护。

### 注意事项
1. 违反了开闭原则: 添加新的元素类时，需要修改所有的访问者类，这违反了开闭原则。
2. 结构变化困难: 如果元素类的结构频繁变化，维护访问者模式的代码会变得复杂。
3. 类膨胀: 随着元素类和操作的增加，访问者类的数量也会迅速增长，可能导致类膨胀问题。

### 深入理解
访问者模式通过双分派机制实现了动态绑定，即在运行时既根据访问者类型又根据元素类型决定调用哪个方法。这使得访问者模式非常适合于处理具有复杂操作逻辑的系统，特别是当这些操作逻辑与对象结构相独立时。访问者模式强调了“单一职责原则”，将数据结构的维护与数据的操作分离，使得两者可以独立演化。

### 适用情况
1. 对象结构稳定，操作易变: 当对象结构相对稳定，但需要经常定义新的操作时，访问者模式非常有用。
2. 操作独立于对象结构: 当操作逻辑与对象结构解耦，且操作逻辑较为复杂时，使用访问者模式可以提高代码的组织性和可读性。
3. 数据结构复杂: 对于树形或图形结构的数据，访问者模式可以提供一种优雅的方式来遍历和处理这些结构中的元素。

### 面向对象特性的体现
1. 多态性：访问者模式通过定义抽象的访问者接口和元素接口，以及它们各自的实现类，利用多态性使得访问者能够以统一的方式处理不同的元素类型，同时也允许元素对不同的访问者做出响应。这种动态绑定机制是访问者模式实现的核心。

2. 封装性：访问者将操作的实现细节封装在访问者类中，元素类不需要了解这些操作的具体实现，同样，访问者也不需要了解元素的内部结构，只是通过元素提供的接口进行访问，这增强了系统的封装性。

3. 继承性：通过继承，可以很容易地扩展新的访问者或元素类，继承父类的接口和行为，从而符合开闭原则，即对扩展开放，对修改关闭。

### 独特设计思路与哲学
1. 双重分派：访问者模式的一个独特之处在于它使用了双重分派机制。第一次分派发生在元素的accept方法中，根据访问者类型决定调用哪个visit方法；第二次分派发生在访问者的visit方法中，根据元素的实际类型执行特定操作。这样的设计允许访问者模式在运行时动态地决定执行哪种操作。

2. 分离关注点：访问者模式将数据结构（对象集合）的遍历逻辑与对这些数据的操作逻辑分开，使得这两者可以独立地演化。这体现了单一职责原则，每个类专注于自身的责任，使得系统更易于维护和扩展。

### 设计模式特点体现
开闭原则：通过定义抽象接口和实现类，访问者模式允许在不修改原有代码的情况下，通过添加新的访问者或元素类来扩展功能，满足了对扩展开放、对修改关闭的要求。

单一职责原则：访问者模式将数据结构的遍历和数据的操作分离，每个类都有明确的职责，符合单一职责原则。

迪米特法则：访问者只通过元素的公共接口来访问和操作元素，减少了类之间的耦合，体现了最少知识原则。

## 例子
BuyBasket（购物车）添加、删除（关联）Product（产品），并由accept函数传递Visitor参数供Product被动访问（实际是在Product里调用Visitor的visit函数，并传递this指针来判断具体的某个产品（重载））。
```cpp
#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

//抽象访问者Visitor（访问者类）
class Apple;
class Book;
class Visitor {
public:
	void setName(string name) {
		this->name = name;
	}

	virtual void visit(Apple* apple) = 0;
	virtual void visit(Book* book) = 0;
protected:
	string name;
};

//具体访问者类Customer（顾客类） 
class Customer : public Visitor {
public:
	void visit(Apple* apple) {
		cout << "顾客" << name << "选苹果。" << endl;
	}

	void visit(Book* book) {
		cout << "顾客" << name << "买书。" << endl;
	}
};

//具体访问者类Saler（收银员类） 
class Saler : public Visitor {
public:
	void visit(Apple* apple) {
		cout << "收银员" << name << "给苹果过秤，然后计算价格。" << endl;
	}

	void visit(Book* book) {
		cout << "收银员" << name << "直接计算书的价格。" << endl;
	}
};

//抽象元素类Product（商品类）
class Product {
public:
	virtual void accept(Visitor* visitor) = 0;
};

//具体元素类Apple（苹果类） 
class Apple : public Product {
public:
	void accept(Visitor* visitor) {
		visitor->visit(this);
	}
};

//具体元素类Book（书籍类） 
class Book : public Product {
public:
	void accept(Visitor* visitor) {
		visitor->visit(this);
	}
};

//对象结构BuyBasket（购物车类）
class BuyBasket {
public:
	void accept(Visitor* visitor) {
		for (auto i : list) {
			i->accept(visitor);
		}
	}

	void addProduct(Product* product) {
		list.push_back(product);
	}

	void removeProduct(Product* product) {
		list.remove(product);
	}
private:
	list<Product*> list;
};


//客户端测试 
int main(void)
{
	//创建商品 
	Book b1, b2;
	Apple a1;

	//创建购物车 
	BuyBasket basket;

	//购物车添加商品 
	basket.addProduct(&b1);
	basket.addProduct(&b2);
	basket.addProduct(&a1);

	//创建顾客 
	Customer customer;
	customer.setName("张三");

	//访问操作 
	basket.accept(&customer);

	//购物车移除商品 
	basket.removeProduct(&b2);

	cout << "-----------------" << endl;

	//创建收银员 
	Saler saler;
	saler.setName("李四");

	//访问操作 
	basket.accept(&saler);

	return 0;
}
```