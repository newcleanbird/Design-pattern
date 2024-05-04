#include<string>
#include<map>

// 字体
class Font {
private:

    //unique object key
    std::string key;
    
    //object state
    //....
    
public:
    Font(const std::string& key){
        //...
    }
};


class FontFactory{
private:
    std::map<std::string,Font* > fontPool;  // 字体池
    
public:
    Font* GetFont(const std::string& key){
        std::map<std::string, Font*>::iterator item=fontPool.find(key);
        
        if(item != fontPool.end()){
            return fontPool[key];
        }
        else{
            Font* font = new Font(key);
            fontPool[key]= font;
            return font;
        }
    }
    
    void clear(){
        //...
    }
};