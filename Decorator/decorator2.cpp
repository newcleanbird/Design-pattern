//业务操作
class Stream{

public:
    virtual char Read(int number)=0;
    virtual void Seek(int position)=0;
    virtual void Write(char data)=0;
    
    virtual ~Stream(){}
};

//主体类
class FileStream: public Stream{
public:
    virtual char Read(int number){
        //读文件流
    }
    virtual void Seek(int position){
        //定位文件流
    }
    virtual void Write(char data){
        //写文件流
    }

};

class NetworkStream :public Stream{
public:
    virtual char Read(int number){
        //读网络流
    }
    virtual void Seek(int position){
        //定位网络流
    }
    virtual void Write(char data){
        //写网络流
    }
    
};

class MemoryStream :public Stream{
public:
    virtual char Read(int number){
        //读内存流
    }
    virtual void Seek(int position){
        //定位内存流
    }
    virtual void Write(char data){
        //写内存流
    }
    
};

//扩展操作

// 三个子类变为一个子类，用组合代替继承
class CryptoStream : public Stream {
    
    Stream* stream;//new FileStream/NetworkStream/MemoryStream 运行时多态

public:
    CryptoStream(Stream* stm) : stream(stm){  // 构造器
    
    }
    
    virtual char Read(int number){
       
        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作...
        stream->Seek(position);//定位文件流
        //额外的加密操作...
    }
    virtual void Write(char data){
        //额外的加密操作...
        stream->Write(data);//写文件流
        //额外的加密操作...
    }
};



class BufferedStream : public Stream{
    
    Stream* stream;//...
    
public:
    BufferedStream(Stream* stm):stream(stm){
        
    }
    //缓存方法...
}; 





void Process(){

    // 运行时装配
    FileStream* s1=new FileStream();   // 创建一个文件流s1
    CryptoStream* s2=new CryptoStream(s1);  // 创建一个s1的加密流
    
    BufferedStream* s3=new BufferedStream(s1);  // 创建一个s1的缓冲流
    
    BufferedStream* s4=new BufferedStream(s2);  // 创建一个s2的缓冲流，即既有加密又有缓存的文件流s1
    
    

}


/*
组合优于继承：将所有的继承改为指针。
重构原则：当一个变量的声明类型都是某个类型的子类，就应该将类似声明为某个类型(基类)。即利用运行时多态
    编译时复用，运行时多态。
多次装饰：为了装饰多个方法，可以对已装饰A的对象再次装饰B，达到同时装饰A和B的目的。
*/