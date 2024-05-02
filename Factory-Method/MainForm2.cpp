class MainForm : public Form
{
    SplitterFactory*  factory;//工厂

public:
    
    MainForm(SplitterFactory*  factory){
        this->factory=factory;
    }
    
	void Button1_Click(){
		ISplitter* splitter = factory->CreateSplitter(); //多态new

        splitter->split();

	}
};

/*
依赖具体类的关系不会消失，只会转移。
将变化赶到一个局部的地方，将依赖的位置转移到合适的位置。
*/


