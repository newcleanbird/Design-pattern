#include<string>

class Memento   // 备忘录
{
    std::string state;
    //..
public:
    Memento(const std::string & s) : state(s) {}
    std::string getState() const { return state; }
    void setState(const std::string & s) { state = s; }
};



class Originator    // 源发器
{
    std::string state;
    //....
public:
    Originator() {}
    Memento createMomento() {
        Memento m(state);   // 拍照
        return m;
    }
    void setMomento(const Memento & m) {
        state = m.getState();
    }
};



int main()
{
    Originator orginator;
    
    // 捕获对象状态，存储到备忘录
    Memento mem = orginator.createMomento();
    
    // ... 改变orginator状态
    
    // 从备忘录中恢复
    orginator.setMomento(mem);

}