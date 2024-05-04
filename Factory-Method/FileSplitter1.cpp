// 分割器
class ISplitter{
public: 
    virtual void split()=0;

    virtual ~ISplitter(){}
};

// 二进制分割器
class BinarySplitter : public ISplitter{
    
};

// 文本文件分割器
class TxtSplitter: public ISplitter{
    
};

// 图片分割器
class PictureSplitter: public ISplitter{
    
};

// 视频分割器
class VideoSplitter: public ISplitter{
    
};

 