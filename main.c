#include "wzq.h"

void drawMenu(void)
{
	printf("*****************************\n");
	printf("******* Hello Wuziqi ********\n");
	printf("******* 制作者:David Zhao *****\n");
	printf("******* 游戏说明：***********\n");
	printf("******* 落子请输入坐标 ******\n");
	printf("******* 例如12h或h12 ********\n");
	printf("******* q退出,r悔棋 *******\n");
	printf("*****************************\n");
	printf("******* 请选择游戏模式 ******\n");
	printf("*       1.人-人对战         *\n");
	printf("*       2.人-机对战         *\n");
	printf("*       3.退出              *\n");
	printf("*****************************\n");
	printf("请选择：");
}

int main()
{
	drawMenu();
	while (1) 
	{
		scanf("%d", &mode);
		switch (mode) 
		{
			case 1:
				pvp();
				break;
			case 2:
				pve();
				break;
			case 3:
				exit(0);
				break;
			case 428:
				eve();
				break;
			case 114514:
				wanning();
				break;
			default:
				printf("输入错误，请重新选择\n");
			break;
		}
		printf("本轮游戏结束，继续选择游戏模式：");
	}
	return 0;
}
