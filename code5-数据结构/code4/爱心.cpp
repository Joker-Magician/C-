#define _CRT_SECURE_NO_WARNINGS
#include<easyx.h>//Í¼ÐÎ¿â
#include<stdio.h>
#include<time.h>
#include<math.h>

struct Point {
	double x, y;
	COLORREF color;
};

COLORREF colors[7] = { RGB(255,32,83),RGB(252,22,25),RGB(255,0,0),
					RGB(255,0,0),RGB(255,2,2),RGB(255,0,8),
					RGB(255,5,5)
};

const int xScreen = 1200;
const int yScreen = 800;

const double PI = 3.1415926;
const double e = 2.71828;
const double average_distance = 0.1;
const int quantity = 1000;
const int circles = 210;
const int frames = 20;
Point origin_points[quantity];
Point points[circles * quantity];
IMAGE images[frames];

double srceen_x(double x)
{
	x += xScreen / 2;
	return x;
}

double srceen_y(double y)
{
	y = -y + yScreen / 2;
	return y;
}

int createRandom(int x1, int x2)
{
	if ((x2 > x1)) {
		return rand() % (x2 - x1 + 1) + x1;
	}
	return x1;
}

void create_data() {
	int index = 0;
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	for (double radin = 0.1; radin <= 2 * PI; radin += 0.001) {
		x2 = 16 * pow(sin(radin), 3);
		y2 = 13 * cos(radin) - 5 * cos(2 * radin) - 2 * cos(3 * radin) - cos(4 * radin);

		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		if (distance > average_distance) {
			x1 = x2;
			y1 = y2;
			origin_points[index].x = x2;
			origin_points[index++].y = y2;
		}

	}

	index = 0;
	for (double size = 0.1, light = 1.5; size <= 20; size += 0.1) {
		double p = 1 / (1 + pow(e, 8 - size / 2));

		for (int i = 0; i < quantity; ++i) {
			if (p > createRandom(0, 100) / 100.0)
			{
				points[index].color = colors[createRandom(0, 6)];
				points[index].x = size * origin_points[i].x + createRandom(-2, 2);
				points[index++].y = size * origin_points[i].y + createRandom(-2, 2);
			}
		}

	}

	int points_size = index;

	for (int f = 0; f < frames; ++f) {
		images[f] = IMAGE(xScreen, yScreen);
		SetWorkingImage(&images[f]);
		//Ìø¶¯
		for (index = 0; index < points_size; ++index) {

			double x = points[index].x, y = points[index].y;
			double dis = sqrt(pow(x, 2) + pow(y, 2));
			double dis_in = -0.00009 * dis * dis + 0.35714 * dis + 5;

			double x_dis = dis_in * x / dis / frames;
			double y_dis = dis_in * y / dis / frames;

			points[index].x += x_dis;
			points[index].y += y_dis;


			setfillcolor(points[index].color);
			solidcircle((int)srceen_x(points[index].x), (int)srceen_y(points[index].y), 1);
		}
	}
}


int main()
{
	srand((unsigned int)time(NULL));
	//´´½¨´°¿Ú
	initgraph(xScreen, yScreen);
	//¿ªÆôË«»º³å»æÍ¼£¬·ÀÖ¹ÉÁË¸
	BeginBatchDraw();
	//°®ÐÄÁ£×ÓµÄ´´½¨
	create_data();

	SetWorkingImage(NULL);

	int f = 0;
	bool extend = true, shrink = false;
	//Ö÷Ñ­»·
	while (true) {
		//äÖÈ¾°®ÐÄÁ£×Ó
		putimage(0, 0, &images[f]);
		//Ë¢ÐÂ´°¿Ú
		FlushBatchDraw();

		//ÇåÆÁ
		cleardevice();

		if (extend) f == 19 ? (shrink = true, extend = false) : ++f;
		else  f == 0 ? (shrink = false, extend = true) : --f;

		Sleep(20);
	}
	//¹Ø±ÕË«»º³å»æÍ¼
	EndBatchDraw();

	//¹Ø±Õ´°¿Ú
	closegraph();

	return 0;
}
