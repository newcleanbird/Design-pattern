
//抽象类
class ISplitter{
public:
    virtual void split()=0;
    virtual ISplitter* clone()=0; //通过克隆自己来创建对象
    
    virtual ~ISplitter(){}

};

/*
将工厂模式的工厂基类和业务基类合二为一
*/

