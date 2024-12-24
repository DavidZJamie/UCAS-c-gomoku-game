#include "wzq.h"
//人机对战
void pve(void)
{
    initRecordBorard();
    innerLayoutToDisplayArray(0,0);
    displayBoard();
    int depth;
    printf("\n设置搜索深度,限定偶数(六层很慢):");
    scanf("%d",&depth);
    getchar();
    if (depth%2!=0||depth<=0)
    {
        printf("输入错误，请重新输入\n");
        pve();
    }
    DEPTH=depth;
    int choice;
    printf("\n人机对战开始,请选择先后手(输入1:选择黑棋先手,输入2:选择白棋后手):");
    scanf("%d",&choice);
    getchar();
    if(choice==1)
    {
        for (int i = 0;; i++)
        {
            int count=i+1;
            printf("\n第%d回合\n\n",count);
            p1_black_move();
            if(judge_win(BLACK))
            {
                printf("黑棋胜利!\n");
                return ;
            }
            if (count==113)
            {
                break;
            }
            printf("\n轮到电脑白棋下棋…\n");
            e_white_move(count);
            if(judge_win(WHITE))
            {
                printf("白棋胜利!\n");
                printf("菜，就多练。\n");
                return ;
            }
        }
        printf("平局！\n");
        return ;
    }
    else if(choice==2)
    {
        for (int i = 0;; i++)
        {
            int count=i+1;
            printf("\n第%d回合\n",count);
            printf("\n轮到电脑黑棋下棋…\n");
            e_black_move(count);
            if(judge_win(BLACK))
            {
                printf("黑棋胜利!\n");
                printf("菜，就多练。\n");
                return ;
            }
            if (count==113)
            {
                break;
            }
            p2_white_move();
            if(judge_win(WHITE))
            {
                printf("白棋胜利!\n");
                return ;
            }
        }
        printf("平局！\n");
        return ;
    }
    else
    {
        printf("输入错误，请重新输入\n");
        pve();
    }
}

seatptr choose;
//电脑下黑棋
void e_black_move(int count)
{
    choose=(seatptr)malloc(sizeof(seat));
    if(count==1)
    {
        put_black(7,7);
        return;
    }
#if 1 
    if(count==2)
    {
        //白棋第二步下右下或左下 
        if(arrayForInnerBoardLayout[8][8]==WHITE || arrayForInnerBoardLayout[8][6]==WHITE)
        {
            put_black(6,7);
            return;
        }
        //白棋第二步下右上或左上 
        if(arrayForInnerBoardLayout[6][6]==WHITE || arrayForInnerBoardLayout[6][8]==WHITE)
        {
            put_black(8,7);
            return;
        }
        //白棋第二步下下面或左边
        if(arrayForInnerBoardLayout[8][7]==WHITE || arrayForInnerBoardLayout[7][6]==WHITE)
        {
            put_black(8,6);
            return;
        }
        //白棋第二步下上面或右边
        if(arrayForInnerBoardLayout[6][7]==WHITE || arrayForInnerBoardLayout[7][8]==WHITE)
        {
            put_black(6,8);
            return;
        }
    }
    if(count==3)
    {
        //第二步白棋下右下 
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[8][7]==WHITE)
        {
            put_black(8,6);
            return;
        }
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE)
        {
            put_black(6,8);
            return;
        }
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[7][9]==WHITE)
        {
            put_black(7,6);
            return;
        }
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[8][6]==WHITE)
        {
            put_black(8,7);
            return;
        }
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[9][7]==WHITE)
        {
            put_black(7,9);
            return;
        }
        //第二步白棋下左下 
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[8][7]==WHITE)
        {
            put_black(8,8);
            return;
        }
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE)
        {
            put_black(6,6); 
            return;
        }
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[7][5]==WHITE)
        {
            put_black(7,8);
            return;
        }
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[8][8]==WHITE)
        {
            put_black(8,7);
            return;
        }
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[9][7]==WHITE)
        {
            put_black(7,5);
            return;
        }
        //第二步白棋下右上 
        if(arrayForInnerBoardLayout[6][8]==WHITE&&arrayForInnerBoardLayout[9][7]==WHITE)
        {
            put_black(8,8);
            return;
        }
        if(arrayForInnerBoardLayout[6][8]==WHITE&&arrayForInnerBoardLayout[6][7]==WHITE)
        {
            put_black(6,6);
            return;
        }
        if(arrayForInnerBoardLayout[6][8]==WHITE&&arrayForInnerBoardLayout[7][9]==WHITE)
        {
            put_black(7,6);
            return;
        }
        if(arrayForInnerBoardLayout[6][8]==WHITE&&arrayForInnerBoardLayout[6][6]==WHITE)
        {
            put_black(6,7);
            return;
        }
        if(arrayForInnerBoardLayout[6][8]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE)
        {
            put_black(7,9);
            return;
        }
        //第二步白棋下左上 
        if(arrayForInnerBoardLayout[6][6]==WHITE&&arrayForInnerBoardLayout[6][7]==WHITE)
        {
            put_black(6,8);
            return;
        }
        if(arrayForInnerBoardLayout[6][6]==WHITE&&arrayForInnerBoardLayout[9][7]==WHITE)
        {
            put_black(8,6); 
            return;
        }
        if(arrayForInnerBoardLayout[6][6]==WHITE&&arrayForInnerBoardLayout[7][5]==WHITE)
        {
            put_black(7,8); 
            return;
        }
        if(arrayForInnerBoardLayout[6][6]==WHITE&&arrayForInnerBoardLayout[6][8]==WHITE)
        {
            put_black(6,7); 
            return;
        }
        if(arrayForInnerBoardLayout[6][6]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE)
        {
            put_black(7,5); 
            return;
        }

        //第二步白棋下下面
        if(arrayForInnerBoardLayout[8][7]==WHITE&& (arrayForInnerBoardLayout[9][5]==WHITE || arrayForInnerBoardLayout[9][6]==WHITE))
        {
            put_black(6,8);
            return;
        }
        if(arrayForInnerBoardLayout[8][7]==WHITE&&arrayForInnerBoardLayout[6][8]==WHITE)
        {
            put_black(9,6); 
            return;
        }
        if(arrayForInnerBoardLayout[8][7]==WHITE&&arrayForInnerBoardLayout[7][8]==WHITE)
        {
            put_black(9,5); 
            return;
        }
        if(arrayForInnerBoardLayout[8][7]==WHITE&&arrayForInnerBoardLayout[7][6]==WHITE)
        {
            put_black(6,5); 
            return;
        }
        //第二步白棋下左面
        if(arrayForInnerBoardLayout[7][6]==WHITE&& (arrayForInnerBoardLayout[9][5]==WHITE || arrayForInnerBoardLayout[8][5]==WHITE))
        {
            put_black(6,8);
            return;
        }
        if(arrayForInnerBoardLayout[7][6]==WHITE&&arrayForInnerBoardLayout[6][8]==WHITE)
        {
            put_black(8,5); 
            return;
        }
        if(arrayForInnerBoardLayout[7][6]==WHITE&&arrayForInnerBoardLayout[6][7]==WHITE)
        {
            put_black(9,5); 
            return;
        }
        if(arrayForInnerBoardLayout[7][6]==WHITE&&arrayForInnerBoardLayout[8][7]==WHITE)
        {
            put_black(6,5); 
            return;
        }
        //第二步白棋下上面
        if(arrayForInnerBoardLayout[6][7]==WHITE&& (arrayForInnerBoardLayout[5][8]==WHITE || arrayForInnerBoardLayout[5][9]==WHITE))
        {
            put_black(8,6);
            return;
        }
        if(arrayForInnerBoardLayout[6][7]==WHITE&&arrayForInnerBoardLayout[8][6]==WHITE)
        {
            put_black(5,8); 
            return;
        }
        if(arrayForInnerBoardLayout[6][7]==WHITE&&arrayForInnerBoardLayout[7][6]==WHITE)
        {
            put_black(5,9); 
            return;
        }
        if(arrayForInnerBoardLayout[6][7]==WHITE&&arrayForInnerBoardLayout[7][8]==WHITE)
        {
            put_black(5,6); 
            return;
        }
        //第二步白棋下右面
        if(arrayForInnerBoardLayout[7][8]==WHITE&& (arrayForInnerBoardLayout[5][9]==WHITE || arrayForInnerBoardLayout[6][9]==WHITE))
        {
            put_black(8,6);
            return;
        }
        if(arrayForInnerBoardLayout[7][8]==WHITE&&arrayForInnerBoardLayout[8][7]==WHITE)
        {
            put_black(5,9); 
            return;
        }
        if(arrayForInnerBoardLayout[7][8]==WHITE&&arrayForInnerBoardLayout[8][6]==WHITE)
        {
            put_black(6,9); 
            return;
        }
        if(arrayForInnerBoardLayout[7][8]==WHITE&&arrayForInnerBoardLayout[6][7]==WHITE)
        {
            put_black(5,6); 
            return;
        }
    }
    if(count==4)
    {
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE&&arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[6][8]==BLACK)
        {
            put_black(8,9);
            return;
        }
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE&&arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[6][6]==BLACK)
        {
            put_black(8,5);
            return;
        }
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE&&arrayForInnerBoardLayout[5][9]==WHITE)
        {
            put_black(5,8);
            return;
        }
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE&&arrayForInnerBoardLayout[5][5]==WHITE)
        {
            put_black(5,6);
            return;
        }
    }
    if(count==5)
    {
        if(arrayForInnerBoardLayout[8][8]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE&&arrayForInnerBoardLayout[5][9]==WHITE&&arrayForInnerBoardLayout[7][6]==WHITE)
        {
            put_black(6,9);
            return;
        }
        if(arrayForInnerBoardLayout[8][6]==WHITE&&arrayForInnerBoardLayout[5][7]==WHITE&&arrayForInnerBoardLayout[5][5]==WHITE&&arrayForInnerBoardLayout[7][8]==WHITE)
        {
            put_black(6,5);
            return;
        }
    }
#endif

    int value=choice(BLACK, choose, DEPTH, A_0, B_0);
    printf("\n黑棋落子位置为:%c%d\n",choose->y+'A',15-choose->x);
    arrayForInnerBoardLayout[choose->x][choose->y]=BLACK;
    innerLayoutToDisplayArray(choose->x,choose->y); 
    displayBoard();
}
void put_black(int x, int y)
{
    choose->x=x;
    choose->y=y;
    arrayForInnerBoardLayout[x][y]=BLACK;
    innerLayoutToDisplayArray(x,y);
    printf("\n黑棋落子位置为:%c%d\n",y+'A',15-x);
    displayBoard();
    return; 
}
//电脑下白棋
void e_white_move(int count)
{
    if(count==1)
    {
        if(arrayForInnerBoardLayout[7][7]==BLACK)
        {
            put_white(8,8);
            return;
        }
    }
#if 1
    if(count==2)
    {
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[6][7]==BLACK)
        {
            put_white(5,7);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[7][6]==BLACK)
        {
            put_white(7,5);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[7][8]==BLACK)
        {
            put_white(7,9);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[8][7]==BLACK)
        {
            put_white(9,7);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[6][8]==BLACK)
        {
            put_white(8,6);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[8][6]==BLACK)
        {
            put_white(6,8);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[6][6]==BLACK)
        {
            put_white(8,7);
            return;
        }
    }
    if(count==3)
    {
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[6][7]==BLACK && arrayForInnerBoardLayout[6][8]==BLACK)
        {
            put_white(8,6);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[6][7]==BLACK && arrayForInnerBoardLayout[7][6]==BLACK)
        {
            put_white(7,5);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[6][6]==BLACK && arrayForInnerBoardLayout[8][6]==BLACK)
        {
            put_white(6,8);
            return;
        }
        if(arrayForInnerBoardLayout[7][7]==BLACK && arrayForInnerBoardLayout[7][6]==BLACK && arrayForInnerBoardLayout[8][6]==BLACK)
        {
            put_white(6,8);
            return;
        }
    }
#endif

    choose=(seatptr)malloc(sizeof(seat));
    int value=choice(WHITE, choose, DEPTH,  A_0, B_0);
    printf("\n白棋落子位置为:%c%d\n",choose->y+'A',15-choose->x);
    arrayForInnerBoardLayout[choose->x][choose->y]=WHITE;
    innerLayoutToDisplayArray(choose->x,choose->y); 
    displayBoard();
}
void put_white(int x, int y)
{
    arrayForInnerBoardLayout[x][y]=WHITE;
    innerLayoutToDisplayArray(x,y);
    printf("\n白棋落子位置为:%c%d\n",y+'A',15-x);
    displayBoard();
    return;
}
