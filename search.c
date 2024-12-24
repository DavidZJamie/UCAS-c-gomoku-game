#include "wzq.h"
//向上开始，顺时针八个方向搜索棋子相对位置信息
//0-7表示8个方向，向上为开始，顺时针方向遍历
//用数组形象的表示棋子排布信息，O表示相同棋子，_表示空位，O_数组记录的是名字末尾的类型的数量
void Search(int x,int y,int color,int O[],int O_[],int O_O[],int O_O_[],int O_O_O[])
{
    //注意横纵坐标和棋盘上的行列是相反的
    //上
    int heng=y;
    int zong=x-1;
    while (zong>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    { 
        O[0]++;
        zong--;
    }
    while (zong>=0&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {   
        O_[0]++;
        zong--;
    }
    while (zong>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {      
        O_O[0]++;
        zong--;
    }
    while (zong>=0&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {                
        O_O_[0]++;
        zong--;
    }
    while (zong>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[0]++;
        zong--;
    }

    //右上
    heng=y+1;
    zong=x-1;
    while (zong>=0&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[1]++;
        zong--;
        heng++;
    }
    while (zong>=0&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {
        O_[1]++;
        zong--;
        heng++;
    }
    while (zong>=0&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {    
        O_O[1]++;
        zong--;
        heng++;
    }
    while (zong>=0&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {        
        O_O_[1]++;
        zong--;
        heng++;
    }
    while (zong>=0&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[1]++;
        zong--;
        heng++;
    }

    //右
    heng=y+1;
    zong=x;
    while (heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[2]++;
        heng++;
    }
    while (heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {
        O_[2]++;
        heng++;
    }
    while (heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {        
        O_O[2]++;
        heng++;
    }
    while (heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {                
        O_O_[2]++;
        heng++;
    }
    while (heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[2]++;
        heng++;
    }    

    //右下
    heng=y+1;
    zong=x+1;
    while (zong<SIZE&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[3]++;
        heng++;
        zong++;
    }
    while (zong<SIZE&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    { 
        O_[3]++;
        heng++;
        zong++;
    }
    while (zong<SIZE&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O[3]++;
        heng++;
        zong++;
    }
    while (zong<SIZE&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {        
        O_O_[3]++;
        heng++;
        zong++;
    }
    while (zong<SIZE&&heng<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[3]++;
        heng++;
        zong++;
    }

    //下
    heng=y;
    zong=x+1;
    while (zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[4]++;
        zong++;
    }
    while (zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {
        O_[4]++;
        zong++;
    }
    while (zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {                
        O_O[4]++;
        zong++;
    }
    while (zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {                
        O_O_[4]++;
        zong++;
    }
    while (zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[4]++;
        zong++;
    }

    //左下
    heng=y-1;
    zong=x+1;
    while (heng>=0&&zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[5]++;
        zong++;
        heng--;
    }
    while (heng>=0&&zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {
        O_[5]++;
        zong++;
        heng--;
    }
    while (heng>=0&&zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O[5]++;
        zong++;
        heng--;
    }
    while (heng>=0&&zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {
                    
        O_O_[5]++;
        zong++;
        heng--;
    }
    while (heng>=0&&zong<SIZE&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[5]++;
        zong++;
        heng--;
    }

    //左
    heng=y-1;
    zong=x;
    while (heng>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[6]++;
        heng--;
    }
    while (heng>=0&&arrayForInnerBoardLayout[zong][heng]==NONE)
    { 
        O_[6]++;
        heng--;
    }
    while (heng>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {        
        O_O[6]++;
        heng--;
    }
    while (heng>=0&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {            
        O_O_[6]++;
        heng--;
    }
    while (heng>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[6]++;
        heng--;
    }

    //左上
    heng=y-1;
    zong=x-1;
    while (heng>=0&&zong>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O[7]++;
        heng--;
        zong--;
    }
    while (heng>=0&&zong>=0&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {
        O_[7]++;
        heng--;
        zong--;
    }
    while (heng>=0&&zong>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    { 
        O_O[7]++;
        heng--;
        zong--;
    }
    while (heng>=0&&zong>=0&&arrayForInnerBoardLayout[zong][heng]==NONE)
    {          
        O_O_[7]++;
        heng--;
        zong--;
    }
    while (heng>=0&&zong>=0&&arrayForInnerBoardLayout[zong][heng]==color)
    {
        O_O_O[7]++;
        heng--;
        zong--;
    }
}