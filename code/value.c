#include "wzq.h"

//评估传入的点的价值
void assess_value(int x, int y)
{
    //按价值高低排
    int Fine_5=114514;
    int Live_4=8888;
    int Live_3=2000;
    int Rush_4=1200;
    int Live_2=200;
    int Rush_3=120;
    int Rush_2=40;
    //黑子分数
    BoardForAssess[x][y].score[BLACK]=BoardForAssess[x][y].status[BLACK].Fine_5*Fine_5+\
        BoardForAssess[x][y].status[BLACK].Live_4*Live_4+BoardForAssess[x][y].status[BLACK].Rush_4*Rush_4+\
        BoardForAssess[x][y].status[BLACK].Live_3*Live_3+BoardForAssess[x][y].status[BLACK].Rush_3*Rush_3+\
        BoardForAssess[x][y].status[BLACK].Live_2*Live_2+BoardForAssess[x][y].status[BLACK].Rush_2*Rush_2;
    //白子分数
    BoardForAssess[x][y].score[WHITE]=BoardForAssess[x][y].status[WHITE].Fine_5*Fine_5+\
        BoardForAssess[x][y].status[WHITE].Live_4*Live_4+BoardForAssess[x][y].status[WHITE].Rush_4*Rush_4+\
        BoardForAssess[x][y].status[WHITE].Live_3*Live_3+BoardForAssess[x][y].status[WHITE].Rush_3*Rush_3+\
        BoardForAssess[x][y].status[WHITE].Live_2*Live_2+BoardForAssess[x][y].status[WHITE].Rush_2*Rush_2;
    //黑白子总分
    BoardForAssess[x][y].score[0]=BoardForAssess[x][y].score[BLACK]+BoardForAssess[x][y].score[WHITE];
}

//从己方的视角评估整个棋盘上的价值
int assess_board(int color)
{
    //按价值高低排
    int Op_Live_4=B_0; 
    int Op_Rush_4=2000000;
    int My_Live_4=200000;
    int Op_Live_3=150000;
    int My_Live_3=2400;
    int My_Rush_4=2000;
    int Op_Rush_3=800;
    int My_Rush_3=600;
    int Op_Live_2=400;
    int My_Live_2=300;
    int Op_Rush_2=100;
    int My_Rush_2=40;
    int Fine_5[3]={0};
    int Live_4[3]={0};
    int Rush_4[3]={0};
    int Live_3[3]={0};
    int Rush_3[3]={0};
    int Live_2[3]={0};
    int Rush_2[3]={0};
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            int colour=arrayForInnerBoardLayout[i][j];
            check_link(i,j,colour);
            Live_4[colour]+=BoardForAssess[i][j].status[colour].Live_4;
            Rush_4[colour]+=BoardForAssess[i][j].status[colour].Rush_4;
            Live_3[colour]+=BoardForAssess[i][j].status[colour].Live_3;
            Rush_3[colour]+=BoardForAssess[i][j].status[colour].Rush_3;
            Live_2[colour]+=BoardForAssess[i][j].status[colour].Live_2;
            Rush_2[colour]+=BoardForAssess[i][j].status[colour].Rush_2;
        }
    }
    int Board_value;
    if(color==BLACK)
    {
        Board_value=Live_4[BLACK]*My_Live_4/4+Rush_4[BLACK]*My_Rush_4/4+Live_3[BLACK]*My_Live_3/3+Rush_3[BLACK]*My_Rush_3/3+Live_2[BLACK]*My_Live_2/2+Rush_2[BLACK]*My_Rush_2/2\
            -Live_4[WHITE]*Op_Rush_4/4-Rush_4[WHITE]*Op_Rush_4/4-Live_3[WHITE]*Op_Live_3/3-Rush_3[WHITE]*Op_Rush_3/3-Live_2[WHITE]*Op_Live_2/2-Rush_2[WHITE]*Op_Rush_2/2;
    }
    else
    {
        Board_value=Live_4[WHITE]*My_Live_4/4+Rush_4[WHITE]*My_Rush_4/4+Live_3[WHITE]*My_Live_3/3+Rush_3[WHITE]*My_Rush_3/3+Live_2[WHITE]*My_Live_2/2+Rush_2[WHITE]*My_Rush_2/2\
            -Live_4[BLACK]*Op_Rush_4/4-Rush_4[BLACK]*Op_Rush_4/4-Live_3[BLACK]*Op_Live_3/3-Rush_3[BLACK]*Op_Rush_3/3-Live_2[BLACK]*Op_Live_2/2-Rush_2[BLACK]*Op_Rush_2/2;
    }
    return Board_value;
}