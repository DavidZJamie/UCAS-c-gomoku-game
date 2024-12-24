#include "wzq.h"

//在棋盘上找到所有可能的落子点
int available_points(pointptr free_points, int color,int situation[], seat killer[])
{
    seatptr Saved;  //存储已搜索过的点
    Saved=(seatptr)malloc(sizeof(seat)*225);
    int Saved_num=0;
    int num=0;
    int x,y;
    for(x=0;x<SIZE;x++)
    {
        for(y=0;y<SIZE;y++)
        {
            //确定当前格子周围的四个方向（上、下、左、右）的边界
            if(arrayForInnerBoardLayout[x][y]!=NONE)
            {
                int up=x;
                int down=x;
                int left=y;
                int right=y;
                if(x>0)
                {
                    up=x-1;
                }
                if (x<SIZE-1)
                {
                    down=x+1;
                }
                if(y>0)
                {
                    left=y-1;
                }
                if (y<SIZE-1)
                {
                    right=y+1;
                }
                int i,j;
                for(i=up;i<=down;i++)
                {
                    for(j=left;j<=right;j++)
                    {
                        if(arrayForInnerBoardLayout[i][j]==NONE)
                        {
                            int if_saved=0;
                            for(int k=0;k<Saved_num;k++)
                            {
                                if(i==Saved[k].x&&j==Saved[k].y)
                                {
                                    if_saved=1;
                                    break;
                                }
                            }
                            if(if_saved)//说明该点已经判断过了，直接到下一个点去
                            {  
                                continue;
                            }
                            else
                            {
                                Saved[Saved_num].x=i;
                                Saved[Saved_num].y=j;
                                Saved_num++;
                            }
                            check_link(i,j,BLACK);
                            check_link(i,j,WHITE);
                            if (color==WHITE)//己方白棋
                            {
                                if(BoardForAssess[i][j].status[WHITE].Fine_5)//存入己方杀手
                                {   
                                    situation[1]=1;
                                    killer[1].x=i;
                                    killer[1].y=j;
                                    num++;
                                    return num;
                                }
                                if (BoardForAssess[i][j].status[BLACK].Fine_5)//存入对方杀手
                                {
                                    if (check_ban(i,j,BLACK))
                                    {
                                        situation[0]=1;
                                        killer[0].x=i;
                                        killer[0].y=j;
                                    }
                                }
                                assess_value(i,j);
                                free_points[num].point.x=i;
                                free_points[num].point.y=j;
                                free_points[num].score=BoardForAssess[i][j].score[0];
                                num++;
                            }
                            else//己方黑棋
                            {
                                if (check_ban(i,j,BLACK))
                                {
                                    if(BoardForAssess[i][j].status[BLACK].Fine_5)//存入己方杀手
                                    {   
                                        situation[1]=1;
                                        killer[1].x=i;
                                        killer[1].y=j;
                                        num++;
                                        return num;
                                    }
                                    if (BoardForAssess[i][j].status[WHITE].Fine_5)//存入对方杀手
                                    {
                                        situation[0]=1;
                                        killer[0].x=i;
                                        killer[0].y=j;
                                    }
                                    assess_value(i,j);
                                    free_points[num].point.x=i;
                                    free_points[num].point.y=j;
                                    free_points[num].score=BoardForAssess[i][j].score[0];
                                    num++;
                                }
                                
                            }
                        }
                    }
                }
            }
        }
    }
    return num;
}

/*//在棋盘上找到所有可能的落子点
int available_points(pointptr free_points, int color,int situation[], seat killer[])
{
    int i,j;
    int num=0;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(arrayForInnerBoardLayout[i][j]==NONE)
            {
                check_link(i,j,BLACK);
                check_link(i,j,WHITE);
                if (color==WHITE)//己方白棋
                {
                    if(BoardForAssess[i][j].status[WHITE].Fine_5)//存入己方杀手
                    {   
                        situation[1]=1;
                        killer[1].x=i;
                        killer[1].y=j;
                        num++;
                        return num;
                    }
                    if (BoardForAssess[i][j].status[BLACK].Fine_5)//存入对方杀手
                    {
                        if (check_ban(i,j,BLACK))
                        {
                            situation[0]=1;
                            killer[0].x=i;
                            killer[0].y=j;
                        }
                    }
                    assess_value(i,j);
                    free_points[num].point.x=i;
                    free_points[num].point.y=j;
                    free_points[num].score=BoardForAssess[i][j].score[0];
                    num++;
                }
                else//己方黑棋
                {
                    if (check_ban(i,j,BLACK))
                    {
                        if(BoardForAssess[i][j].status[BLACK].Fine_5)//存入己方杀手
                        {   
                            situation[1]=1;
                            killer[1].x=i;
                            killer[1].y=j;
                            num++;
                            return num;
                        }
                        if (BoardForAssess[i][j].status[WHITE].Fine_5)//存入对方杀手
                        {
                            situation[0]=1;
                            killer[0].x=i;
                            killer[0].y=j;
                        }
                    }
                    assess_value(i,j);
                    free_points[num].point.x=i;
                    free_points[num].point.y=j;
                    free_points[num].score=BoardForAssess[i][j].score[0];
                    num++;
                }
            }
        }
    }
    return num;
}
*/
//搜索深度,限定偶数
int DEPTH;
//落子评估和剪枝法选出最好的点
int choice(int color, seatptr choose, int depth, int alpha, int beta)
{
    int WIDTH=SIZE;//限定选点宽度
    int Op_turn=depth%2;//奇数层为对方落子，偶数层为己方落子
    int situation[2]={0};//记录是否可以杀死比赛，[1]表示己方
    seat killer[2];//记录杀棋手，[1]表示己方
    pointptr free_points;//记录所有可落点
    free_points=(pointptr)malloc(sizeof(point)*225);
    //遍历棋盘找到所有可落点，记录到free_points中
    int num=available_points(free_points,color,situation,killer);
    if(DEPTH>=8)
    {
        switch(depth)
        {
            case 10:
                WIDTH=10;
                break;
            case 9:
                WIDTH=9;
                break;
            case 8:
                WIDTH=10;
                break;
            case 7:
                WIDTH=9;
                break;
            case 6:
                WIDTH=8;
                break;
            case 5:
                WIDTH=7;
                break;
            case 4:
            	WIDTH=6;
            	break;
            case 3:
                WIDTH=6;
                break;
            case 2:
                WIDTH=6;
                break;
            case 1:
                WIDTH=6;
                break;
            case 0:
                WIDTH=15;
                break;
        }
    }
    if(depth==0)//底层，递归终止条件
    {
        if(situation[0])//对方有杀手，只能堵，返回堵的价值（极小值）
        {
            arrayForInnerBoardLayout[killer[0].x][killer[0].y]=color;//落子，算分，擦除
            int onlychoice=assess_board(color);
            arrayForInnerBoardLayout[killer[0].x][killer[0].y]=NONE; 
            return onlychoice;
        }
        if(situation[1])//己方有杀手，对方不会落上一步，返回极大值
        { 
            return 400000;
        }
        else//无杀手,用棋盘分数评估选择，取极大值 
        {
            int Board_value,inf;
            inf=-400000;
            for(int i=0;i<num;i++)
            {
                arrayForInnerBoardLayout[free_points[i].point.x][free_points[i].point.y]=color;//落子，算分，擦除
                Board_value=assess_board(color);
                arrayForInnerBoardLayout[free_points[i].point.x][free_points[i].point.y]=NONE;
                inf=(Board_value>inf)?Board_value:inf;
            }
            return inf;
        }
    }
    if(situation[1])//己方有杀手 
    {
        if(!Op_turn)//我能杀，对方不会落上一步，返回极大值
        {
            if(depth==DEPTH)//没有对方的上一步，我直接杀死比赛
            {
                choose->x=killer[1].x;
                choose->y=killer[1].y;
            }
            return 400000;
        }
        if(Op_turn)//我落子后对方这一步能杀，我上一步落子不对，返回极小值
        {
            return -400000;
        }
    }

    //根据选点宽度筛选出更好的点  
    WIDTH=(num<WIDTH)?num:WIDTH;
    pointptr betterpoints;    
    betterpoints=(pointptr)malloc(sizeof(point)*WIDTH);
    int *back;//记录每个子节点的回推价值
    back=(int *)malloc(sizeof(int)*WIDTH);

    //按分数高低排排序选出最优的WIDTH个选点
    myqsort(free_points,0,num-1);
    for(int i=0;i<WIDTH;i++)
    {
        betterpoints[i].point=free_points[i].point;
        betterpoints[i].score=free_points[i].score;
    }
    int next_color=BLACK;//为了给对方落子
    if (color==BLACK)
    {
        next_color=WHITE;
    } 
    
    int width=WIDTH;
    for(int i=0;i<width;i++)//对每个选择进行极大极小值搜索和剪枝
    {
        arrayForInnerBoardLayout[betterpoints[i].point.x][betterpoints[i].point.y]=color;//落子
        back[i]=choice(next_color,choose,depth-1,alpha,beta);//给对方落子，到下一层，得回推值，下面改变alpha和bata
        if(Op_turn)//对方落子，回推值取小
        {
            beta=(back[i]<beta)?back[i]:beta;//改上界
            if(alpha>=beta)//不用再搜索，剪枝
            {    
            	arrayForInnerBoardLayout[betterpoints[i].point.x][betterpoints[i].point.y]=NONE;//擦除
                return beta;
            }
        }
        if(!Op_turn)//己方落子,回推值取大
        {
            if(depth==DEPTH&&back[i]>alpha)//回到顶层给出选择
            {   
                choose->x=betterpoints[i].point.x;
                choose->y=betterpoints[i].point.y;      
            }
            alpha=(back[i]>alpha)?back[i]:alpha;//改下界
            if(alpha>=beta)//不用再搜索，剪枝
            {    
            	arrayForInnerBoardLayout[betterpoints[i].point.x][betterpoints[i].point.y]=NONE;//擦除
                return alpha;
            }
        }
        arrayForInnerBoardLayout[betterpoints[i].point.x][betterpoints[i].point.y]=NONE;//擦除
    }
    if(Op_turn)
    {
        return beta;
    }
    if(!Op_turn)
    {
        return alpha;
    }
    
}

void myqsort(pointptr s, int left, int right)
{
    int i,last;
    if(left>=right)
    {
        return ;
    }
    swap(s, left, (left+right)/2);
    last=left;
    for ( i = left+1; i <=right; i++)
    {
        if (s[i].score>s[left].score)
        {
            swap(s, ++last,i);
        }
        
    }
        swap(s, left,last);
        myqsort(s,left,last-1);
        myqsort(s,last+1,right);
}

void swap(pointptr s, int i, int j)
{
    int temp;
    temp=s[i].score;
    s[i].score=s[j].score;
    s[j].score=temp;
    temp=s[i].point.x;
    s[i].point.x=s[j].point.x;
    s[j].point.x=temp;
    temp=s[i].point.y;
    s[i].point.y=s[j].point.y;
    s[j].point.y=temp;
}