template<typename T>
class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T& current() = 0;
};



template<typename T>
class MyCollection{
    
public:
    
    Iterator<T> GetIterator(){
        //...
    }
    
};

template<typename T>
class CollectionIterator : public Iterator<T>{
    MyCollection<T> mc;
public:
    
    CollectionIterator(const MyCollection<T> & c): mc(c){ }
    
    void first() override {
        
    }
    void next() override {
        
    }
    bool isDone() const override{
        
    }
    T& current() override{
        
    }
};

void MyAlgorithm()
{
    MyCollection<int> mc;
    
    Iterator<int> iter= mc.GetIterator();
    
    for (iter.first(); !iter.isDone(); iter.next()){
        cout << iter.current() << endl;
    }
    
}
/*
虚函数调用，性能调用开销比较大

模板：编译时多态
虚函数：运行时多态
*/






