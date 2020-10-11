#include <iostream>//标准头文件 
#include <windows.h>//系统头文件 
using namespace std;

//鼠标按键判断 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
// 左  ：KEY_DOWN(MOUSE_MOVED)
// 右  ：KEY_DOWN(MOUSE_EVENT)
//滚轮 ：KEY_DOWN(MOUSE_WHEELED)

bool check(char c)
{//检测某个按键是否按下
	if(!KEY_DOWN(c))return 0;
	else return 1;
}

int main()
{
	int time;//间隔时间
	int run = 0;
	
	//输入时间 
	while (1)
	{
		cout << "Input interval time (more than 10, in MS):";
		cin >> time;
		if (time < 10)//间隔时间，最小为10，防止电脑卡死 
		{
			cout << "The time needs to be less than 10, please input again...";
			Sleep (500);
			system ("cls");//cmd指令 
		}
		else break;
	}
	
	//开始连点
	while (1)
	{
		if (KEY_DOWN(MOUSE_MOVED) && run)
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
		if (check('G')) run = !run;
		
		Sleep (time);//等待
	} 
}
