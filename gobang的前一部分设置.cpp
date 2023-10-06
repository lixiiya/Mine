//数组和循环判断
# include <stdio.h>
#define max_row 20   //行数 
#define max_col 20  //列数 
#define white 1
#define black 1

//讨论落子情况
#define white_win 1
#define black_win 2
#define draw 3
#define next 0

//设计菜单
int main()
{
	printf("WELCOME TO PLAY THE GOBANG!\n");
	printf("1.开始游戏\n");
	printf("2.结束游戏\n");
	printf("请选择\n");
	int choice = 2;
	scanf("&d", &choice);
	return choice;

}
//设计棋盘
#include <stdio.h>

