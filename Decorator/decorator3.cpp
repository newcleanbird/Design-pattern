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

// 由于两个子类有相同的成员Stream*，所以这个成员要往上提。但如果直接给Stream类增加成员，会使得其他子类继承Stream*但并不需要Stream*，因此考虑改为创建一个中间类增加Stream*。
class DecoratorStream : public Stream{
protected:
    Stream* stream;//...
    
    DecoratorStream(Stream * stm):stream(stm){
    
    }
    
};

class CryptoStream: public DecoratorStream {
public:
    CryptoStream(Stream* stm):DecoratorStream(stm){
    
    }
    
    virtual char Read(int number){
        //额外的加密操作...
        stream->Read(number);//读文件流
    }
    virtual void Seek(int position){
        //额外的加密操作...
        stream::Seek(position);//定位文件流
        //额外的加密操作...
    }
    virtual void Write(byte data){
        //额外的加密操作...
        stream::Write(data);//写文件流
        //额外的加密操作...
    }
};


class BufferedStream : public DecoratorStream{
    
    Stream* stream;//...
    
public:
    BufferedStream(Stream* stm):DecoratorStream(stm){
        
    }
    //...
};




void Process(){

    //运行时装配
    FileStream* s1=new FileStream();
    
    CryptoStream* s2=new CryptoStream(s1);
    
    BufferedStream* s3=new BufferedStream(s1);
    
    BufferedStream* s4=new BufferedStream(s2);
}

/*
总的数量：
    修饰前：1+n+n*m/2
    修饰后：1+n+1+m 
*/