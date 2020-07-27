#include <iostream>//标准头文件 
#include <windows.h>//系统头文件 
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

bool check(char c)
{//检测某个按键是否按下
	if(!KEY_DOWN(c)) return 0;
	else return 1;
}


int main()
{
	int time;//间隔时间
	bool key;//bool布尔类型变量，0（fales）或1（true） ，key为要点击的是左键（0）或右键（1）
	bool run;//是否开启
	
	//输入时间 
	cout << "请输入间隔时间（小于10）：";
	while (1)
	{
		cin >> time;
		if (time < 10)//间隔时间，最小为10，防止电脑卡死 
		{
			cout << "时间需要小于10哦，清重新输入...";
			system ("cls");//cmd指令 
		}
		else break;
	}
	
	//输入左键或右键
	cout << "请输入连点的是左键还是右键（左键是0，右键是1）";
	cin >> key;
	
	//开始连点
	while (1)
	{
		if (check ('N')) run = 1;//注意单引号里一定是大写，n开启 
		if (check ('M')) run = 0;//注意单引号里一定是大写，m关闭 
		if (check ('R')) return 0;//注意单引号里一定是大写，r退出程序 
		if (run)
		{
			if (!key) mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);//左键，mouse_event函数——鼠标点击
			else mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0); //右键 
			Sleep (time);//等待 
		}
	} 
}
