#include "wzq.h"
//神之一手
void buff1(int count)
{
    if (count%4==0)
    {
        printf("\n神之一手:");
        srand((unsigned)time(NULL));
        do
        {
            coord.x=rand()%SIZE;
            coord.y=rand()%SIZE;
        }while(arrayForInnerBoardLayout[coord.x][coord.y]!=NONE);
        put_white(coord.x,coord.y);
        getchar();
    }
    return ;
}
//过河拆桥
void buff2(int count)
{
    if (count%6==0)
    {     
        srand((unsigned)time(NULL));       
        do
        {
            coord.x=rand()%SIZE;
            coord.y=rand()%SIZE;
        }while(arrayForInnerBoardLayout[coord.x][coord.y]!=BLACK);
        printf("\n过河拆桥:拆除黑子%c%d\n",coord.y+'A',15-coord.x);
        arrayForInnerBoardLayout[coord.x][coord.y]=NONE;
        innerLayoutToDisplayArray(coord.x,coord.y);   
        displayBoard();
        }
        return ;
}
//狡兔三窟
void buff3(int count)
{
    if (count==1)
    {
        printf("\n狡兔三窟:\n");
        for (int j = 0; j < 3; j++)
        {
            srand((unsigned)time(NULL));
            do
            {
                coord.x=rand()%SIZE;
                coord.y=rand()%SIZE;
            }while(arrayForInnerBoardLayout[coord.x][coord.y]!=NONE);
            arrayForInnerBoardLayout[coord.x][coord.y]=WHITE;
            innerLayoutToDisplayArray(coord.x,coord.y);
        }
        displayBoard();
    }
    return ;
}
//小推车
void buff4(int remain[])
{
    if (remain[0])
    {
        printf("\n是否发动小推车(限定技):");
        char Buff=getchar();
        if(Buff>='A'&&Buff<='O')
        {
            printf("\n小推车来喽:\n");
            remain[0]--;
            for (int j = 0; j < SIZE; j++)
            {
                arrayForInnerBoardLayout[j][Buff-'A']=NONE;
                innerLayoutToDisplayArray(j,Buff-'A');
            }
            getchar();
            displayBoard();
        }
        else if (Buff>='a'&&Buff<='o')
        {
            printf("\n小推车来喽:\n");
            remain[0]--;
            for (int j = 0; j < SIZE; j++)
            {
                arrayForInnerBoardLayout[j][Buff-'a']=NONE;
                innerLayoutToDisplayArray(j,Buff-'a');
            }
            getchar();
            displayBoard();
        }
    }
    return ;
}

//开心消消乐
void buff5(int x,int y,int color)
{
    int samex,samey;
    samex=samey=0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arrayForInnerBoardLayout[i][y]==color)
        {
            samex++;
        }
        if (arrayForInnerBoardLayout[x][i]==color)
        {
            samey++;
        }
    }
    if (samex>=5)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arrayForInnerBoardLayout[j][y]=NONE;
            innerLayoutToDisplayArray(j,y);
        }
    }
    if (samey>=5)
    {
        for (int j = 0; j < SIZE; j++)
        {
            arrayForInnerBoardLayout[x][j]=NONE;
            innerLayoutToDisplayArray(x,j);
        }
    }
    if (samex>=5||samey>=5)
    {
        printf("\n开心消消乐:\n");
        displayBoard();
    }
    return ;
}
//变节
void buff6(int count)
{
    static int random[4];
    if (count==1)
    {
        srand((unsigned)time(NULL));
        for (int j = 0; j < 4; j++)
        {
            random[j]=rand()%29+2;
        }
    }
    if (count==random[0]||count==random[1]||count==random[2]||count==random[3])
    {
        printf("\n情势反转:\n");
        int i,j;
        for(i=0;i<SIZE;i++)
        {
            for(j=0;j<SIZE;j++)
            {
                if(arrayForInnerBoardLayout[i][j]==BLACK)
                {
                    arrayForInnerBoardLayout[i][j]=WHITE;
                    innerLayoutToDisplayArray(i,j);
                }
                else if (arrayForInnerBoardLayout[i][j]==WHITE)
                {
                    arrayForInnerBoardLayout[i][j]=BLACK;
                    innerLayoutToDisplayArray(i,j);
                }
                
            }
        }
        displayBoard();
        getchar();
    }
    return ;
}
