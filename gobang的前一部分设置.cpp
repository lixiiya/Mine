//�����ѭ���ж�
# include <stdio.h>
#define max_row 20   //���� 
#define max_col 20  //���� 
#define white 1
#define black 1

//�����������
#define white_win 1
#define black_win 2
#define draw 3
#define next 0

//��Ʋ˵�
int main()
{
	printf("WELCOME TO PLAY THE GOBANG!\n");
	printf("1.��ʼ��Ϸ\n");
	printf("2.������Ϸ\n");
	printf("��ѡ��\n");
	int choice = 2;
	scanf("&d", &choice);
	return choice;

}
//�������
#include <stdio.h>

