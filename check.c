#include "wzq.h"

//检查传入点的连子信息
void check_link(int x, int y, int color)
{
    //统计棋子位置信息，转化为连子信息。
    int O[8]={0};
    int O_[8]={0};
    int O_O[8]={0};
    int O_O_[8]={0};
    int O_O_O[8]={0};
    Search(x, y, color,O, O_, O_O, O_O_, O_O_O);

    //1表示黑棋，2表示白棋,在Board中的数组中，1对应黑，2对应白,因此color即为颜色对应的编号
    //BoardForAssess存储的是上次的信息,需要将信息清零
    Clear_BoardForAssess(x,y,color);
    //统计的是一行或列的信息，只有四个方向
    for(int i=0;i<4;i++)
    {
        
        if(O[i]+O[i+4]==4||(O[i]==4 && O[i+4]==4))//连五不是禁手
        {   
            BoardForAssess[x][y].status[color].Fine_5=1;
            return;
        }
        if(O[i]+O[i+4]>=5&&color==BLACK)//长连禁手
        {    
            BoardForAssess[x][y].status[color].Long_ban=1;
            return;
        }
        if(O[i]+O[i+4]>=5&&color==WHITE)//白棋长连不禁，直接win
        {    
            BoardForAssess[x][y].status[color].Fine_5=1;
            return;
        }

        //连四OOOO
        else if(O[i]+O[i+4]==3)
        {
            //_OOOO_活四
            if(O_[i]>0&&O_[i+4]>0&&check_if_can_put(x,y,O[i],i,color)&&check_if_can_put(x,y,O[i+4],i+4,color))
            {    
                BoardForAssess[x][y].status[color].Live_4+=1;
            }
            //|OOOO_,_OOOO|，冲四
            else if((O_[i]>0 && check_if_can_put(x,y,O[i],i,color))||(O_[i+4]>0 && check_if_can_put(x,y,O[i+4],i+4,color)))
            {       
                BoardForAssess[x][y].status[color].Rush_4+=1;
            }
        }

        //连三OOO
        else if(O[i]+O[i+4]==2)
        {
            //O_OOO_O活四
            if(O_[i]==1&&O_O[i]==1&&O_[i+4]==1&&O_O[i+4]==1&&check_if_can_put(x,y,O[i],i,color)&&check_if_can_put(x,y,O[i+4],i+4,color))
            {
                BoardForAssess[x][y].status[color].Live_4+=1;
            }
            //OOO_O冲四
            else if((O_[i]==1&&O_O[i]==1&&check_if_can_put(x,y,O[i],i,color))||(O_[i+4]==1&&O_O[i+4]==1&&check_if_can_put(x,y,O[i+4],i+4,color)))
            {
                BoardForAssess[x][y].status[color].Rush_4+=1;
            }
            else//检查活三，下一步在第一个空位上能否形成活四，__OOO___,__OOO__|,_OOO___
            {
                int passup[3]={0};
                int passdown[3]={0};
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
                if (O_[i]==1&&O_O[i]==0)
                {
                    passup[2]++;
                }
                if (O_[i+4]==1&&O_O[i+4]==0)
                {
                    passdown[2]++;
                }
                //两边可落
                if(passup[0]&&passup[1]&&check_if_can_put(x,y,O[i],i,color))
                {
                    BoardForAssess[x][y].status[color].Live_3+=1;
                }
                else if (passdown[0]&&passdown[1]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Live_3+=1;
                }
                //只要一边可落
                else if(passup[1]&&passup[2]&& check_if_can_put(x,y,O[i],i,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                else if (passup[0]&& !passup[1]&& check_if_can_put(x,y,O[i],i,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                else if (passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                else if (passdown[0]&& !passdown[1]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                
            }
        }
        //连二OO
        else if(O[i]+O[i+4]==1)
        {
            //OO_OO_OO为活四
            if(O_[i]==1&&O_O[i]==2&&O_[i+4]==1&&O_O[i+4]==2&&check_if_can_put(x,y,O[i],i,color)&&check_if_can_put(x,y,O[i+4],i+4,color))
            {
                BoardForAssess[x][y].status[color].Live_4+=1;
            }
            //_OO_OO,OO_OO_为冲四
            else if((O_[i]==1&&O_O[i]==2&&check_if_can_put(x,y,O[i],i,color))||(O_[i+4]==1&&O_O[i+4]==2&&check_if_can_put(x,y,O[i+4],i+4,color)))
            {
                BoardForAssess[x][y].status[color].Rush_4+=1;
            }
            else//活三冲三
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
                
                //两边可落
                if((passup[0]&&passup[1]&&passup[2]&&check_if_can_put(x,y,O[i],i,color)))
                {
                    BoardForAssess[x][y].status[color].Live_3+=1;
                }
                else if (passdown[0]&& passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Live_3+=1;
                }
                //只要一边可落
                else if(passup[0]&& passup[1]&&check_if_can_put(x,y,O[i],i,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                else if (passup[0]&& passup[2]&&check_if_can_put(x,y,O[i],i,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                
                else if (passdown[0] && passdown[1]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                else if (passdown[0] && passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                }
                
                
            }
            //活二冲二
            int passup[3]={0};
            int passdown[3]={0};
            if (O_[i]>2 )
            {
                passup[0]++;
            }
            else if (O_[i]==2 && O_O[i]==0)
            {
                passup[0]++;
            }
            if (O_[i+4]>2 || (O_[i+4]==2 && O_O[i+4]==0))
            {
                passdown[0]++;
            }
            if (O_[i]>3)
            {
                passup[1]++;
            }
            else if (O_[i]==3 && O_O[i]==0)
            {
                passup[1]++;
            }
            if (O_[i+4]>3 || (O_[i+4]==3 && O_O[i+4]==0))
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
            if (O_[i]>1 || (O_[i]==1 && O_O[i]==0))
            {
                passdown[2]++;
            }
            //两边可落    
            if(passup[0]&&passup[1]&&passup[2]&&check_if_can_put(x,y,O[i],i,color)&& check_if_can_put(x,y,O[i]+1,i,color))
            {
                BoardForAssess[x][y].status[color].Live_2+=1;
            }
            else if (passdown[0]&& passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color)&&check_if_can_put(x,y,O[i+4]+1,i+4,color))
            {
                BoardForAssess[x][y].status[color].Live_2+=1;
            }
            
            else if(passup[0] && (passup[1]||passup[2]) && check_if_can_put(x,y,O[i],i,color)&& check_if_can_put(x,y,O[i]+1,i,color))
            {
                BoardForAssess[x][y].status[color].Rush_2+=1;
            }
            else if (passdown[0] && (passdown[1] || passdown[2]) && check_if_can_put(x,y,O[i+4],i+4,color)&& check_if_can_put(x,y,O[i+4]+1,i+4,color))
            {
                BoardForAssess[x][y].status[color].Rush_2+=1;
            }
            
        }
        //一子O
        else if(O[i]+O[i+4]==0)
        {
            //活四冲四判断，_O_OOO的_无禁手为活四
            int pass=0;
            if(O_[i]==1&&O_O[i]==3&&check_if_can_put(x,y,O[i],i,color))
            {
                BoardForAssess[x][y].status[color].Rush_4+=1;
                pass++;
            }
            if(O_[i+4]==1&&O_O[i+4]==3&&check_if_can_put(x,y,O[i+4],i+4,color))
            {

                BoardForAssess[x][y].status[color].Rush_4+=1;
                pass++;
            }
            if(pass==0)
            {    
                //活三冲三
                //__O_OO__,_OO_O__且中间_无禁手为活三
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
                //两边可落
                if(passup[0]&&passup[1]&&passup[2]&&check_if_can_put(x,y,O[i],i,color))
                {
                    BoardForAssess[x][y].status[color].Live_3+=1;
                    pass++;
                }
                else if (passdown[0]&& passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Live_3+=1;
                    pass++;
                }
        
                else if(passup[0]&& (passup[1]||passup[2]) && check_if_can_put(x,y,O[i],i,color) )
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                    pass++;
                }
                else if (passdown[0]&& (passdown[1]||passdown[2])&& check_if_can_put(x,y,O[i+4],i+4,color))
                {
                    BoardForAssess[x][y].status[color].Rush_3+=1;
                    pass++;
                }
                
            }
            //活二冲二
            if(pass==0)
            {
                int passup[3]={0};
                int passdown[3]={0};
                if (O_[i]==1 && O_O[i]==1 && O_O_[i]>=1)
                {
                    passup[0]++;
                }
                if (O_[i+4]==1 && O_O[i+4]==1 && O_O_[i+4]>=1)
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
                if (O_O_[i+4]>1 || (O_O_[i+4]==1 && O_O_O[i+4]==0))
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
                if (O_[i]>1 || (O_[i]==1 && O_O[i]==0))
                {
                    passdown[2]++;
                }
                //两边可落
                if(passup[0]&&passup[1]&&passup[2]&&check_if_can_put(x,y,O[i],i,color)&& check_if_can_put(x,y,O[i]+2,i,color))
                {
                    BoardForAssess[x][y].status[color].Live_2+=1;
                    pass++;
                }
                else if (passdown[0]&& passdown[1]&&passdown[2]&& check_if_can_put(x,y,O[i+4],i+4,color)&& check_if_can_put(x,y,O[i+4]+2,i+4,color))
                {
                    BoardForAssess[x][y].status[color].Live_2+=1;
                    pass++;
                }
                //只要一边可落
                else if(passup[0]&& (passup[1]||passup[2]) && check_if_can_put(x,y,O[i],i,color)&& check_if_can_put(x,y,O[i]+2,i,color))
                {
                    BoardForAssess[x][y].status[color].Rush_2+=1;
                    pass++;
                }
                else if (passdown[0]&& (passdown[1]||passdown[2])&& check_if_can_put(x,y,O[i+4],i+4,color)&&check_if_can_put(x,y,O[i+4]+2,i+4,color))
                {
                    BoardForAssess[x][y].status[color].Rush_2+=1;
                    pass++;
                }
                
            }
        }
    }
}

void Clear_BoardForAssess(int x, int y, int color)
{
    BoardForAssess[x][y].status[color].Long_ban=0;
    BoardForAssess[x][y].status[color].Fine_5=0;
    BoardForAssess[x][y].status[color].Live_4=0;
    BoardForAssess[x][y].status[color].Rush_4=0;
    BoardForAssess[x][y].status[color].Live_3=0;
    BoardForAssess[x][y].status[color].Rush_3=0;
    BoardForAssess[x][y].status[color].Live_2=0;
    BoardForAssess[x][y].status[color].Rush_2=0;
    BoardForAssess[x][y].score[color]=0;
}