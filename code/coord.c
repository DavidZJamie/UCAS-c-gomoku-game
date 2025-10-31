#include "wzq.h"

char input[4];
//将输入的字母数字转化为坐标
struct coord trans(char *input)
{
    if (input[0]>='A' && input[0]<='O')
    {
        coord.y=input[0]-'A';
        if (input[1]>='0' && input[1]<='9' && input[2]>='0' && input[2]<='9')
        {
            coord.x=15-(10*(input[1]-'0')+(input[2]-'0'));
        }
        else if(input[1]>='0' && input[1]<='9' && (input[2]=='\n' || input[2]<='\0'))
        {
            coord.x=15-(input[1]-'0');
        }
    }
    else if(input[0]>='1' && input[0]<='9')
    {
        if(input[2]!='\0' && input[2]!='\n')
        {   
            if(input[2]>='A' && input[2]<='O')
            {
                coord.x=15-(10*(input[0]-'0')+(input[1]-'0'));
                coord.y=input[2]-'A';
            }
            else
            {
                coord.x=15-(10*(input[0]-'0')+(input[1]-'0'));
                coord.y=input[2]-'a';
            }  
        }
        else
        {
            if(input[1]>='A' && input[1]<='O')
            {
                coord.x=15-(input[0]-'0');
                coord.y=input[1]-'A';
            }
            else
            {
                coord.x=15-(input[0]-'0');
                coord.y=input[1]-'a';
            }            
        }
    }
    else if(input[0]>='a' && input[0]<='o')
    {
            coord.y=input[0]-'a';
        if (input[2]!='\0' && input[2]!='\n')
        {
            coord.x=15-(10*(input[1]-'0') +(input[2]-'0'));
        }
        else
            coord.x=15-(input[1]-'0');
    }
    else
    {
        printf("不在棋盘有效范围内，请重新输入：");
        return seatrecording();
    }
    return coord;
}

int mygetline(char *s)
{
    int c,i;
    i=0;
    while((c=getchar())!= EOF && c!='\n')
    {
        s[i++]=c;
    }
    if(c=='\n')
    {
        s[i++]=c;
    }
    s[i]='\0';
    return i;
}

//记录坐标，判断退出和坐标范围
struct coord seatrecording()
{
    mygetline(input);
    if ((input[0]=='q'||input[0]=='Q')&& input[1]=='\n')//q键退出
        exit(0);
    else
    {
        coord=trans(input);
        if(coord.x>=15 || coord.y>=15 || coord.x<0 || coord.y<0)
        {
            printf("不在棋盘有效范围内，请重新输入：");
            return seatrecording();
        }
        else if(arrayForInnerBoardLayout[coord.x][coord.y]!=0)
        {
            printf("该处已有棋子，请重新输入：");
            return seatrecording();
        }
        return coord;
    }         
}