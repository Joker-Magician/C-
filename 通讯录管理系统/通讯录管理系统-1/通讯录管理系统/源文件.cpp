#define _CRT_SECURE_NO_WARNINGS
#include"list.h"

void drawMenu()
{
	cleardevice();

	//����
	settextcolor(0x4299E1);
	settextstyle(36, 0, "΢���ź�");
	drawCenteredText(0, 20, x_graph, "ͨѶ¼����ϵͳ");

	//�˵�
	settextcolor(BLACK);
	settextstyle(20, 0, "����");
	int y = start_y;
	outtextxy(start_x, y, "1. �����ϵ��");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./add_contact.png");
	outtextxy(start_x, y, "2. ������������ϵ��");	y += item_height + spacing;  outimage(start_x - 25, y - 35, "./get_contact.png");
	outtextxy(start_x, y, "3. ������ϵ��");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./insert_contact.png");
	outtextxy(start_x, y, "4. ɾ����ϵ��");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./delete_contact.png");
	outtextxy(start_x, y, "5  ��ʾ������ϵ��");		y += item_height + spacing;  outimage(start_x - 25, y - 35, "./show_contacts.png");
	outtextxy(start_x, y, "6. ���绰������ϵ��");	y += item_height + spacing;  outimage(start_x - 25, y - 35, "./search_phone.png");
	outtextxy(start_x, y, "7. ������ϵ�˵绰");		y += item_height + spacing;  outimage(start_x - 25, y - 35, "./update_phone.png");
	outtextxy(start_x, y, "8. ����������");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./sort_name.png");
	outtextxy(start_x, y, "9. ���绰����");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./sort_phone.png");
	outtextxy(start_x, y, "0. �˳�ϵͳ");			y += item_height + spacing;  outimage(start_x - 25, y - 35, "./exit.png");

	//��ʾ��Ϣ
	settextcolor(0x4299E1);
	settextstyle(16, 0, "����");
	outtextxy(20, 450, "************************************************************************************************");
	settextstyle(25, 0, "����");
	outtextxy(20, 470, "���ڿ���̨����������:");
}//���ַ�����Ϊ���ֽ��ַ���ʹ�� 

void drawCenteredText(int x, int y, int width, const char* text)
{
	int textWidth = textwidth(text);
	outtextxy(x + (width - textWidth) / 2, y, text);
}

void outimage(const int x, const int y, const char* postion)
{
	IMAGE img;
	loadimage(&img, postion, 20, 20);
	putimage(x, y, &img);
}

void handleInput(List* pList)
{
	char choice = _getch();//��ȡһ���ַ��Ҳ�������ʾ����Ļ��
	char name[50], phone[20], newPhone[20];
	int position;

	fflush(stdin);
	//getchar();// ����������еĻ��з�
	switch (choice) {
	case '1':
		cleardevice();
		displayMessage("�����ϵ��");
		outtextxy(50, 100, "����������:");
		Sleep(1000);
		safeFgets(name, sizeof(name));// ȥ�����з�
		outtextxy(50, 150, "������绰:");
		Sleep(1000);
		safeFgets(phone, sizeof(phone));
		add(pList, name, phone);
		break;
	case '2':
		cleardevice();
		displayMessage("������ϵ��");
		outtextxy(50, 100, "����������: ");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		get(pList, name);
		break;
	case '3':
		cleardevice();
		displayMessage("������ϵ��");
		outtextxy(50, 100, "���������λ�ã�");
		Sleep(1000);
		scanf("%d", &position);
		//getchar();
		//fflush(stdin);
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		outtextxy(50, 150, "����������: ");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		outtextxy(50, 200, "������绰: ");
		Sleep(1000);
		safeFgets(phone, sizeof(phone));
		insert(pList, position, name, phone);
		break;
	case '4':
		cleardevice();
		displayMessage("ɾ����ϵ��");
		outtextxy(50, 100, "������������");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		del(pList, name);
		break;
	case '5':
		cleardevice();
		displayMessage("������ϵ��");
		show(pList);
		Sleep(5000);
		break;
	case '6':
		cleardevice();
		displayMessage("���绰������ϵ��");
		outtextxy(50, 100, "������绰��");
		Sleep(1000);
		safeFgets(phone, sizeof(phone));
		searchByPhone(pList, phone);
		break;
	case '7':
		cleardevice();
		displayMessage("������ϵ�˵绰");
		outtextxy(50, 100, "������������");
		Sleep(1000);
		safeFgets(name, sizeof(name));
		outtextxy(50, 150, "�������µĵ绰��");
		Sleep(1000);
		safeFgets(newPhone, sizeof(newPhone));
		update(pList, name, newPhone);
		break;
	case '8':
		cleardevice();
		displayMessage("����������");
		sortByName(pList);
		break;
	case '9':
		cleardevice();
		displayMessage("���绰����");
		sortByPhone(pList);
		break;
	case '0':
		saveToFile(pList, "��ϵ��.txt");
		freeList(pList);
		closegraph();
		exit(0);
	default:
		outtextxy(50, 550, "��Чѡ��������.\n");
		Sleep(1000);
	}
}

void safeFgets(char* str, int size)
{
	if (fgets(str, size, stdin)) {
		str[strcspn(str, "\n")] = 0;
	}
}

void displayMessage(const char* message)
{
	cleardevice();
	settextcolor(0x4299E1);
	settextstyle(20, 0, "����");
	outtextxy(50, 50, message);
	Sleep(1000);
}