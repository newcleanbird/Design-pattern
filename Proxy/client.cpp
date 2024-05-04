class ISubject{
public:
    virtual void process();
};


class RealSubject: public ISubject{
public:
    virtual void process(){
        //....
    }
};

class ClientApp{
    
    ISubject* subject;
    
public:
    
    ClientApp(){
        subject = new RealSubject();    // 性能、分布式等原因，拿不到这个对象或性能差
    }
    
    void DoTask(){
        //...
        subject->process();
        
        //....
    }
};