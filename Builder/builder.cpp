// 对象的表示
class House{
    //....
};

// 对象的构建
class HouseBuilder {
public:
    House* GetResult(){
        return pHouse;
    }
    virtual ~HouseBuilder(){}
protected:
     
    House* pHouse;
	virtual void BuildPart1()=0;
    virtual void BuildPart2()=0;
    virtual void BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
	
};

class StoneHouse: public House{
    
};

class StoneHouseBuilder: public HouseBuilder{
protected:
    
    virtual void BuildPart1() override{
        //pHouse->Part1 = ...;
    }
    virtual void BuildPart2() override{
        
    }
    virtual void BuildPart3() override{
        
    }
    virtual void BuildPart4() override{
        
    }
    virtual void BuildPart5() override{
        
    }
    
};

// 稳定
class HouseDirector{
    
public:
    HouseBuilder* pHouseBuilder;
    
    HouseDirector(HouseBuilder* pHouseBuilder){
        this->pHouseBuilder=pHouseBuilder;
    }
    
    House* Construct(){
        
        pHouseBuilder->BuildPart1();
        
        for (int i = 0; i < 4; i++){
            pHouseBuilder->BuildPart2();
        }
        
        bool flag=pHouseBuilder->BuildPart3();
        
        if(flag){
            pHouseBuilder->BuildPart4();
        }
        
        pHouseBuilder->BuildPart5();
        
        return pHouseBuilder->GetResult();
    }
};

int main()
{

}

/*
C++ 构造函数中不能引入虚函数！！！
C++构造函数中调用虚函数时 静态绑定
子类的构造函数是先调用父类的构造函数，如果允许动态绑定，就会导致子类的构造函数还未完成，就调用子类的成员函数。违背了伦理原则，对象还没被构造就被调用成员函数。
*/




