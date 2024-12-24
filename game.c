#include "wzq.h"
//游戏模式
void wanning(void)
{
    int choice;
    printf("\n挑战模式开始:");
    initRecordBorard();
    innerLayoutToDisplayArray(0,0);
    DEPTH=8;
    printf("\n制作者的怜悯:");
    printf("\n1:神之一手");
    printf("\n2:过河拆桥");
    printf("\n3:狡兔三窟");
    printf("\n4:小推车");
    printf("\n5:开心消消乐");
    printf("\n6:情势反转");
    printf("\n请选择你的祝福:");
    scanf("%d",&choice);
    getchar();
    if(choice==1)
    {
        printf("\n获得祝福:神之一手");
        getchar();
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
            if (count==100)
            {
                break;
            }
            p2_white_move();

            buff1(count);

            if(judge_win(WHITE))
            {
                printf("白棋胜利!\n");
                return ;
            }
        }
        printf("平局！\n");
        return ;
    }
    else if(choice==2)
    {
        printf("\n获得祝福:过河拆桥");
        getchar();
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
            if (count==120)
            {
                break;
            }
            p2_white_move();
            if(judge_win(WHITE))
            {
                printf("白棋胜利!\n");
                return ;
            }
            buff2(count);
        }
        printf("旗鼓相当的对手！\n");
        return ;
    }
    else if(choice==3)
    {
        printf("\n获得祝福:狡兔三窟");
        getchar();
        for (int i = 0;; i++)
        {
            int count=i+1;
            buff3(count);
            getchar();
            printf("\n第%d回合\n",count);
            printf("\n轮到电脑黑棋下棋…\n");
            e_black_move(count);
            if(judge_win(BLACK))
            {
                printf("黑棋胜利!\n");
                printf("菜，就多练。\n");
                return ;
            }
            if (count==111)
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
        printf("旗鼓相当的对手！\n");
        return ;
    }
    else if(choice==4)
    {
        printf("\n获得祝福:小推车");
        getchar();
        int remain[1]={1};
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
            if (count==115)
            {
                break;
            }
            p2_white_move();
            if(judge_win(WHITE))
            {
                printf("白棋胜利!\n");
                return ;
            }
            buff4(remain);
        }
        printf("旗鼓相当的对手！\n");
        return ;
    }
    else if(choice==5)
    {
        printf("\n获得祝福:开心消消乐");
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
            buff5(choose->x,choose->y,BLACK);
            if (count==128)
            {
                break;
            }
            p2_white_move();
            if(judge_win(WHITE))
            {
                printf("白棋胜利!\n");
                return ;
            }
            buff5(coord.x,coord.y,WHITE);
        }
        printf("旗鼓相当的对手！\n");
        return ;
    }
    else if(choice==6)
    {
        printf("\n获得祝福:情势反转");
        getchar();
        for (int i = 0;; i++)
        {
            int count=i+1;
            printf("\n第%d回合\n",count);
            buff6(count);
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
        printf("旗鼓相当的对手！\n");
        return ;
    }
    else
    {
        printf("输入错误，请重新输入\n");
        wanning();
    }
}

