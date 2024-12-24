#include "wzq.h"
//人人对战
void pvp(void)
{
    initRecordBorard();//初始化棋盘
    innerLayoutToDisplayArray(0,0);
    displayBoard();
    getchar(); 
    printf("\n人人对战开始\n");
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

//人类下黑棋
void p1_black_move()
{
    printf("\n轮到黑方下棋,请输入坐标:");
    coord=seatrecording();
    arrayForInnerBoardLayout[coord.x][coord.y]=BLACK;    
    innerLayoutToDisplayArray(coord.x,coord.y);   
    displayBoard();
    //检查禁手
    check_link(coord.x,coord.y,BLACK);
    if(print_ban(coord.x,coord.y))
    {
        printf("黑棋禁手!白棋胜利!\n");
        getchar();
        getchar();
    }
    //判断是否悔棋
    printf("若悔棋请输入r:");
    char Regret=getchar();
    if(Regret=='R' || Regret=='r')
    {
        arrayForInnerBoardLayout[coord.x][coord.y]=NONE;
        getchar();
        p1_black_move();
    }
}
//人类下白棋
void p2_white_move()
{
    printf("\n轮到白方下棋,请输入坐标:");
    coord=seatrecording();
    arrayForInnerBoardLayout[coord.x][coord.y]=WHITE;      
    innerLayoutToDisplayArray(coord.x,coord.y); 
    displayBoard();
    //判断是否悔棋
    printf("若悔棋请输入r:");
    char Regret=getchar();
    if(Regret=='R' || Regret=='r')
    {
        arrayForInnerBoardLayout[coord.x][coord.y]=NONE;
        getchar();
        p2_white_move();
    }
}

void eve(void)
{
    getchar();
    getchar();
    getchar();
    printf("你干嘛\n");
    getchar();
    getchar();
    getchar();
    printf("别按了\n");
    getchar();
    getchar();
    getchar();
    printf("啥都没有\n");
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    getchar();
    printf("真没办法\n");
    printf("彩蛋，启动！\n");
    initRecordBorard();
    innerLayoutToDisplayArray(0,0);
    int depth_black,depth_white;
    printf("\n为黑棋设置搜索深度:");
    scanf("%d",&depth_black);
    getchar();
    if (depth_black%2!=0||depth_black<=0)
    {
        printf("输入错误，请重新输入\n");
        eve();
    }
    printf("为白棋设置搜索深度:");
    scanf("%d",&depth_white);
    getchar();
    if (depth_white%2!=0||depth_white<=0)
    {
        printf("输入错误，请重新输入\n");
        eve();
    }
    printf("\n内战开始");
    getchar();
    for (int i = 0;; i++)
    {
        int count=i+1;
        printf("\n第%d回合\n",count);
        printf("\n轮到电脑黑棋下棋…\n");
        DEPTH=depth_black;
        e_black_move(count);
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
        DEPTH=depth_white;
        e_white_move(count);
        if(judge_win(WHITE))
        {
            printf("白棋胜利!\n");
            return ;
        }
    }
    printf("平局！\n");
    return ;
}
