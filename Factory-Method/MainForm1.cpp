
class MainForm : public Form
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;

public:
	void Button1_Click(){

		ISplitter * splitter = new BinarySplitter();// 依赖具体类
        // 两边都要变成接口

        splitter->split();

	}
};
 