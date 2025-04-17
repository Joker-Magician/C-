#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<chrono>

std::chrono::milliseconds interval_time = std::chrono::milliseconds(1);

int main()
{
	while (1)
	{
		// 检测鼠标右键是否被按下
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		{
			std::cout << "检测到鼠标右键点击，退出循环。" << std::endl;
			break; // 退出循环
		}

		// 模拟鼠标左键点击
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		
		// 等待指定的时间间隔
		Sleep(interval_time.count());
	}


	return 0;
}