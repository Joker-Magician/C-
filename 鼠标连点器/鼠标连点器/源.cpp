#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<chrono>

std::chrono::milliseconds interval_time = std::chrono::milliseconds(1);

int main()
{
	while (1)
	{
		// �������Ҽ��Ƿ񱻰���
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		{
			std::cout << "��⵽����Ҽ�������˳�ѭ����" << std::endl;
			break; // �˳�ѭ��
		}

		// ģ�����������
		mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		
		// �ȴ�ָ����ʱ����
		Sleep(interval_time.count());
	}


	return 0;
}