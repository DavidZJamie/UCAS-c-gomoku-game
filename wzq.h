#ifndef _MY_HEAD_H
#define _MY_HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//棋盘棋子规格
#define SIZE 15
#define CHARSIZE 3
//决定在打印棋盘时是否先清屏
#define CLEAR 0

#define NONE 0//空子
#define BLACK 1//黑子
#define WHITE 2//白子
#define A_0 -20000000//alpha
#define B_0  20000000//beta

//用于选择模式
int mode;
//搜索深度
extern int DEPTH;

//用于记录输入的坐标
struct coord
{
	int x;//记录行
	int y;//记录列
} coord;
struct coord trans(char *input);
struct coord seatrecording();

//记录连子信息
typedef struct LinkChess
{
	int Long_ban;//长连禁手
	int Fine_5;//连五
	int Live_4;//活四
	int Rush_4;//冲四
	int Live_3;//活三
	int Rush_3;//冲三
	int Live_2;//活二
	int Rush_2;//冲二
}Link,*Lineptr;
//记录棋子连子，分数
typedef struct ScoreBoard
{
	Link status[3];//status[0]记录总连子，status[1]记录黑棋连子，status[2]记录白棋连子   
	int score[3];//score[0]记录总分，score[1]记录黑棋分数，score[2]记录白棋分数
}ScoreBoard;
ScoreBoard BoardForAssess[SIZE][SIZE];

//用于记录可落子的坐标位置
typedef struct SEAT
{
	int x;
	int y;
}seat, *seatptr;
extern seatptr choose;
//α-β剪枝法中记录节点位置和分数
typedef struct POINT
{
	seat point;
	int score;
}point,*pointptr;

extern char arrayForEmptyBoard[SIZE][SIZE*CHARSIZE+1];
extern char arrayForDisplayBoard[SIZE][SIZE*CHARSIZE+1];
extern char play1Pic[];//黑棋子;
extern char play1CurrentPic[]; 
extern char play2Pic[];//白棋子;
extern char play2CurrentPic[];
extern int arrayForInnerBoardLayout[SIZE][SIZE];

void initRecordBorard(void);
void innerLayoutToDisplayArray(int x,int y);
void displayBoard(void);
void Clear_BoardForAssess(int x, int y, int colormark);
void Search(int x,int y,int color,int O[],int O_[],int O_O[],int O_O_[],int O_O_O[]);

int judge_win(int color);
void check_link(int x, int y, int color);   
int check_if_can_put(int x,int y,int distance,int direction,int color);
int check_ban(int x, int y, int color);
int print_ban(int x,int y);
void assess_value(int x, int y);
int assess_board(int color);
int choice(int color, seatptr choose, int depth, int a, int b);
int available_points(pointptr free_points, int color,int situation[], seat killer[]);
void myqsort(pointptr s, int left, int right);
void swap(pointptr s, int i, int j);

void pvp();
void pve();
void eve();
void p1_black_move();
void p2_white_move(); 
void e_black_move(int count);
void e_white_move(int count);
void put_black(int x, int y);
void put_white(int x, int y);
void wanning();

void buff1(int count);
void buff2(int count);
void buff3(int count);
void buff4(int remain[]);
void buff5(int x,int y,int color);
void buff6(int count);

#endif