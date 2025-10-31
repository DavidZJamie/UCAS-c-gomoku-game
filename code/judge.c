#include"wzq.h"

//判断输赢，向上开始，顺时针遍历棋盘，看有没有五连
int judge_win(int color)
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            if(arrayForInnerBoardLayout[i][j]==color)
            {
                if(j+4<SIZE&&arrayForInnerBoardLayout[i][j+1]==color&&arrayForInnerBoardLayout[i][j+2]==color&&arrayForInnerBoardLayout[i][j+3]==color&&arrayForInnerBoardLayout[i][j+4]==color)
                {
                    return 1;
                }
                if(j+4<SIZE&&i+4<SIZE&&arrayForInnerBoardLayout[i+1][j+1]==color&&arrayForInnerBoardLayout[i+2][j+2]==color&&arrayForInnerBoardLayout[i+3][j+3]==color&&arrayForInnerBoardLayout[i+4][j+4]==color)
                {
                    return 1;
                }
                if(i+4<SIZE&&arrayForInnerBoardLayout[i+1][j]==color&&arrayForInnerBoardLayout[i+2][j]==color&&arrayForInnerBoardLayout[i+3][j]==color&&arrayForInnerBoardLayout[i+4][j]==color)
                {
                    return 1;
                }
                if(j-4>=0&&i+4<SIZE&&arrayForInnerBoardLayout[i+1][j-1]==color&&arrayForInnerBoardLayout[i+2][j-2]==color&&arrayForInnerBoardLayout[i+3][j-3]==color&&arrayForInnerBoardLayout[i+4][j-4]==color)
                {
                    return 1;
                }
            }   
        }
   }
   return 0;
}

//打印禁手信息
int print_ban(int x,int y)
{
    if(BoardForAssess[x][y].status[BLACK].Long_ban==1)
    {
        printf("长连禁手!\n");
        return 1;
    }
    //四三不是禁手
    if(BoardForAssess[x][y].status[BLACK].Live_3==1&&(BoardForAssess[x][y].status[BLACK].Live_4+BoardForAssess[x][y].status[BLACK].Rush_4)==1)
    {
        return 0;
    }
    if(BoardForAssess[x][y].status[BLACK].Live_3>=2)
    {
        printf("三三禁手!\n");
        return 1;
    }
    if((BoardForAssess[x][y].status[BLACK].Live_4+BoardForAssess[x][y].status[BLACK].Rush_4)>=2)
    {
        printf("四四禁手!\n");
        return 1;
    }
    return 0;
}

//用于判断传入点的禁手，返回0为禁手
int check_ban(int x, int y, int color)
{ 
    int O[8]={0};
    int O_[8]={0};
    int O_O[8]={0};
    int O_O_[8]={0};
    int O_O_O[8]={0};
    Search(x, y, color,O, O_, O_O,O_O_, O_O_O);
    //和check_link基本相同，但只检查三四五                 
    int Live_4=0;
    int Rush_4=0;
    int Live_3=0;
    int i;
    //统计的是一行或列的信息，只有四个方向
    for(i=0;i<4;i++)
    {
        if(O[i]+O[i+4]==4||(O[i]==4 && O[i+4]==4))//五连
        {  
            return 1;
        }
        if(O[i]+O[i+4]>=5)//长连禁手
        {
            return 0;
        }
        //OOOO
        else if(O[i]+O[i+4]==3)
        {
            if(O_[i]>0&&O_[i+4]>0&&check_if_can_put(x,y,O[i],i,color)&&check_if_can_put(x,y,O[i+4],i+4,color))
            {    
                Live_4+=1;
            }
            else if((O_[i]>0 && check_if_can_put(x,y,O[i],i,color))||(O_[i+4]>0 && check_if_can_put(x,y,O[i+4],i+4,color)))
            {       
                Rush_4+=1;
            }
        }
        //OOO
        else if(O[i]+O[i+4]==2)
        {
            if(O_[i]==1&&O_O[i]==1&&O_[i+4]==1&&O_O[i+4]==1&&check_if_can_put(x,y,O[i],i,color)&&check_if_can_put(x,y,O[i+4],i+4,color))
            {
                Live_4+=1;
            }
            else if((O_[i]==1&&O_O[i]==1&&check_if_can_put(x,y,O[i],i,color))||(O_[i+4]==1&&O_O[i+4]==1&&check_if_can_put(x,y,O[i+4],i+4,color)))
            {
                Rush_4+=1;
            }
            else
            {
                int passup[2]={0};
                int passdown[2]={0};
                if (O_[i]>2)
                {
                    passup[0]++;
                }
                else if (O_[i]==2&&O_O[i]==0)
                {
                    passup[0]++;
                }
                if (O_[i+4]>2)
                {
                    passdown[0]++;
                }
                else if (O_[i+4]==2&&O_O[i+4]==0)
                {
                    passdown[0]++;
                }
                if (O_[i+4]>1)
                {
                    passup[1]++;
                }
                else if (O_[i+4]==1&&O_O[i+4]==0)
                {
                    passup[1]++;
                }
                if (O_[i]>1)
                {
                    passdown[1]++;
                }
                else if (O_[i]==1&&O_O[i]==0)
                {
                    passdown[1]++;
                }

                if(passup[0]&&passup[1]&&check_if_can_put(x,y,O[i],i,color))
                {
                    Live_3+=1;
                }
                else if (passdown[0]&& passdown[1]&&check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    Live_3+=1;
                }
            }
        }
        //OO
        else if(O[i]+O[i+4]==1)
        {
            if(O_[i]==1&&O_O[i]==2&&O_[i+4]==1&&O_O[i+4]==2&&check_if_can_put(x,y,O[i],i,color)&&check_if_can_put(x,y,O[i+4],i+4,color))
            {
                Live_4+=1;
            }
            else if((O_[i]==1&&O_O[i]==2&&check_if_can_put(x,y,O[i],i,color))||(O_[i+4]==1&&O_O[i+4]==2&&check_if_can_put(x,y,O[i+4],i+4,color)))
            {
                Rush_4+=1;
            }
            else
            {
                int passup[3]={0};
                int passdown[3]={0};
                if (O_[i]==1&&O_O[i]==1)
                {
                    passup[0]++;
                }
                if (O_[i+4]==1&&O_O[i+4]==1)
                {
                    passdown[0]++;
                }
                if (O_O_[i]>1)
                {
                    passup[1]++;
                }
                else if (O_O_[i]==1&&O_O_O[i]==0)
                {
                    passup[1]++;
                }
                if (O_O_[i+4]>1)
                {
                    passdown[1]++;
                }
                else if (O_O_[i+4]==1&&O_O_O[i+4]==0)
                {
                    passdown[1]++;
                }
                if (O_[i+4]>1)
                {
                    passup[2]++;
                }
                else if (O_[i+4]==1 && O_O[i+4]==0)
                {
                    passup[2]++;
                }
                if (O_[i]>1)
                {
                    passdown[2]++;
                }
                else if (O_[i]==1 && O_O[i]==0)
                {
                    passdown[2]++;
                }

                if(passup[0]&&passup[1]&&passup[2]&&check_if_can_put(x,y,O[i],i,color))
                {
                    Live_3+=1;
                }
                else if (passdown[0]&& passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    Live_3+=1;
                }
            }
        }
        //O
        else if(O[i]+O[i+4]==0)
        {
            int pass=0;
            if(O_[i]==1&&O_O[i]==3&&check_if_can_put(x,y,O[i],i,color))
            {
                Rush_4+=1;
                pass++;
            }
            if(O_[i+4]==1 && O_O[i+4]==3&&check_if_can_put(x,y,O[i+4],i+4,color))
            {

                Rush_4+=1;
                pass++;
            }
            if(pass==0)
            {      
                int passup[3]={0};
                int passdown[3]={0};
                if (O_[i]==1 && O_O[i]==2)
                {
                    passup[0]++;
                }
                if (O_[i+4]==1 && O_O[i+4]==2)
                {
                    passdown[0]++;
                }
                if (O_O_[i]>1)
                {
                    passup[1]++;
                }
                else if (O_O_[i]==1 && O_O_O[i]==0)
                {
                    passup[1]++;
                }
                if (O_O_[i+4]>1||(O_O_[i+4]==1 && O_O_O[i+4]==0))
                {
                    passdown[1]++;
                }
                if (O_[i+4]>1)
                {
                    passup[2]++;
                }
                else if (O_[i+4]==1 && O_O[i+4]==0)
                {
                    passup[2]++;
                }
                if (O_[i]>1||(O_[i]==1 && O_O[i]==0))
                {
                    passdown[2]++;
                }
                
                if( (passup[0]&&passup[1]&&passup[2]&&check_if_can_put(x,y,O[i],i,color)) )
                {
                    Live_3+=1;
                }
                else if ((passdown[0]&& passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color)) )
                {
                    Live_3+=1;
                }
                
            }
        }
    }
    if((Live_3+Live_4+Rush_4>=2)&&(!(Live_3==1&&(Live_4+Rush_4)==1)))//禁手
    {             
        return 0;
    }
    else
    {
        return 1;
    }
} 

//和check_ban递归判断前面的棋子落下后，原来的空位是否禁手，该递归能终止
//Same传入的是O[]也就是空位和落子之间连子的数量,direction传入的是方向
int check_if_can_put(int x,int y,int Same,int direction,int color)
{   
    int none_x,none_y;
    if(color==WHITE)
    {         
        return 1;
    }
    int gap=Same+1;
    //把送来的信息转化为坐标信息
    if (direction==0)
    {
        none_x=x-gap;
        none_y=y;
    }
    else if (direction==1)
    {
        none_x=x-gap;
        none_y=y+gap; 
    }
    else if (direction==2)
    {
        none_x=x;
        none_y=y+gap;
    }
    else if (direction==3)
    {
        none_x=x+gap;
        none_y=y+gap;
    }
    else if (direction==4)
    {
        none_x=x+gap;
        none_y=y;
    }
    else if (direction==5)
    {
        none_x=x+gap;
        none_y=y-gap;  
    }
    else if (direction==6)
    {
        none_x=x;
        none_y=y-gap;
    }
    else if (direction==7)
    {
        none_x=x-gap;
        none_y=y-gap;
    }
    int if_assessed =0;//评估过的点不能擦
    if(arrayForInnerBoardLayout[x][y]!=NONE)
    {
    	if_assessed=1;
    }
    arrayForInnerBoardLayout[x][y]=color;//落子
    int if_can_put=check_ban(none_x,none_y,color);//检查送来的点是否禁手，0表示禁手
    if(!if_assessed)
    {         
    	arrayForInnerBoardLayout[x][y]=NONE;//擦除,有子就不擦
    }
    if(if_can_put)
    {
    	return 1;//可落子
    }
    else
    {
        return 0;
    }
}
