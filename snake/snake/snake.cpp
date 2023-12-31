﻿#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>
HWND hwnd = NULL;
#define MAX 100

void initSnake();//初始化蛇

void drawSnake();//绘制蛇

void snakeMove();//蛇的移动

void keyDown();//蛇的方向

void foodxy();//蛇的食物

void inifood();//食物绘制

void eatfood();//判断蛇是否吃掉食物

int snakedie();//判断蛇是否吃挂掉

void again();//按空格可以对游戏进行暂停、开始

typedef struct pointXY
{
	int x;
	int y;
}MYPOINT;//存储蛇的坐标的结构体

struct snake//蛇的基本属性
{
	int num;//蛇的总节数
	MYPOINT xy[MAX];//存储蛇的坐标的结构体数组
	char postion;

}snake;

struct food
{
	MYPOINT fdxy;
	int flag = 0;
	int eatgrade = 0;
}food;//食物的基本属性

enum movPostion
{
	right = 72,
	left = 75,
	down = 77,
	up = 80
};//方向枚举

int main()
{
	hwnd = initgraph(640, 480);
	setbkcolor(WHITE);
	srand((unsigned int)time(NULL));//随机数种子，后面随机产生蛇的食物要用到
	initSnake();
	while (1)
	{
		cleardevice();
		if (food.flag == 0)
		{
			foodxy();
		}
		inifood();
		drawSnake();
		if (snakedie())
		{
			break;
		}
		eatfood();   //吃食物增长
		snakeMove();
		Sleep(100);
		while (_kbhit())//这里是按上下左右键控制蛇的移动
		{
			//again();
			keyDown();
		}
	}
	closegraph();
	return 0;
}
//初始化蛇
void initSnake() {

	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;

	snake.num = 3;
	snake.postion = right;
	food.flag = 0;

}

void drawSnake()
{
	for (int i = 0; i < snake.num; i++)
	{
		setlinecolor(BLUE);
		setfillcolor(YELLOW);
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}
}//绘制蛇

void snakeMove()//蛇的移动
{

	for (int i = snake.num - 1; i > 0; i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}

	switch (snake.postion)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	case up:
		snake.xy[0].y -= 10;
		break;
	default:
		break;
	}
}

void keyDown()
{
	char ch = 0;
	ch = _getch();
	switch (ch)
	{
	case 72:
		if (snake.postion != down)
			snake.postion = up;
		break;
	case 75:
		if (snake.postion != right)
			snake.postion = left;
		break;
	case 77:
		if (snake.postion != left)
			snake.postion = right;
		break;
	case 80:
		if (snake.postion != up)
			snake.postion = down;
		break;
	default:
		break;
	}//蛇的方向控制
}

void foodxy()
{
	food.fdxy.x = rand() % 65 * 10;
	food.fdxy.y = rand() % 48 * 10;
	food.flag = 1;

	for (int i = 0; i > snake.num; i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 65 * 10;
			food.fdxy.y = rand() % 48 * 10;
		}
	}//食物坐标获取


}

void inifood()
{
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);

}//绘制食物

void eatfood()
{

	if (snake.xy[0].x == food.fdxy.x && snake.xy[0].y == food.fdxy.y)
	{
		snake.num++;
		food.eatgrade += 10;
		food.flag = 0;

	}

}//吃食物的判断

int  snakedie()
{

	char grade[100] = { 0 };
	sprintf_s(grade, "%d", food.eatgrade);
	setbkmode(0);
	settextcolor(LIGHTBLUE);
	outtextxy(570, 20, "分数：");
	outtextxy(610, 20, grade);

	if (snake.xy[0].x > 640 || snake.xy[0].x < 0 || snake.xy[0].y > 480 || snake.xy[0].y < 0)
	{
		outtextxy(240, 320, "撞墙了");
		MessageBox(hwnd, "游戏结束！", "提示！", 0);
		return 1;
	}
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(240, 320, "你咬死了自己，游戏结束！");
			MessageBox(hwnd, "游戏结束！", "提示！", 0);
			return 1;
		}
	}
	return 0;
}

void again()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}