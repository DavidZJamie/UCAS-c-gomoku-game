#include"wzq.h"
//棋盘使用的是UTF8编码，每一个中文字符占用3个字节。

//空棋盘模板 
char arrayForEmptyBoard[SIZE][SIZE*CHARSIZE+1]= 
{
        "┏┯┯┯┯┯┯┯┯┯┯┯┯┯┓",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┠┼┼┼┼┼┼┼┼┼┼┼┼┼┨",
        "┗┷┷┷┷┷┷┷┷┷┷┷┷┷┛"
};
//此数组存储用于显示的棋盘 
char arrayForDisplayBoard[SIZE][SIZE*CHARSIZE+1];

char play1Pic[]="●";//黑棋子;
char play1CurrentPic[]="▲"; 

char play2Pic[]="◎";//白棋子;
char play2CurrentPic[]="△";

//此数组用于记录当前的棋盘的格局 
int arrayForInnerBoardLayout[SIZE][SIZE];


//初始化一个空棋盘格局 
void initRecordBorard(void)
{
    //通过双重循环，将arrayForInnerBoardLayout清0
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            arrayForInnerBoardLayout[i][j]=0;  
        }
    }
}

//将arrayForInnerBoardLayout中记录的棋子位置，转化到arrayForDisplayBoard中
void innerLayoutToDisplayArray(int x, int y)
{
    //第一步：将arrayForEmptyBoard中记录的空棋盘，复制到arrayForDisplayBoard中
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE*CHARSIZE+1;j++)
        {
            arrayForDisplayBoard[i][j]=arrayForEmptyBoard[i][j];
        }
    }

    //第二步：扫描arrayForInnerBoardLayout，当遇到非0的元素，将●或者◎复制到arrayForDisplayBoard的相应位置上
    //注意：arrayForDisplayBoard所记录的字符是中文字符，每个字符占3个字节。●和◎也是中文字符，每个也占3个字节。
    for (int i = 0; i <SIZE; i++)
    {
            for (int j = 0; j <SIZE; j++)
            {
                switch (arrayForInnerBoardLayout[i][j])
                {
                    case NONE:
                        arrayForDisplayBoard[i][j*CHARSIZE] = arrayForEmptyBoard[i][j*CHARSIZE];
                        arrayForDisplayBoard[i][j*CHARSIZE+1] = arrayForEmptyBoard[i][j*CHARSIZE+1];
                        arrayForDisplayBoard[i][j*CHARSIZE+2] = arrayForEmptyBoard[i][j*CHARSIZE+2];
                        break;
                    case BLACK:
                        if(i==x&&j==y)
                        {
                            arrayForDisplayBoard[i][j*CHARSIZE] = play1CurrentPic[0];
                            arrayForDisplayBoard[i][j*CHARSIZE+1] = play1CurrentPic[1];
                            arrayForDisplayBoard[i][j*CHARSIZE+2] = play1CurrentPic[2];
                        }
                        else
                        {
                            arrayForDisplayBoard[i][j*CHARSIZE] = play1Pic[0];
                            arrayForDisplayBoard[i][j*CHARSIZE+1] = play1Pic[1];
                            arrayForDisplayBoard[i][j*CHARSIZE+2] = play1Pic[2];
                        }
                        break;
                    case WHITE:
                        if(i==x&&j==y)
                        {
                            arrayForDisplayBoard[i][j*CHARSIZE] = play2CurrentPic[0];
                            arrayForDisplayBoard[i][j*CHARSIZE+1] = play2CurrentPic[1];
                            arrayForDisplayBoard[i][j*CHARSIZE+2] = play2CurrentPic[2];
                        }
                        else
                        {
                            arrayForDisplayBoard[i][j*CHARSIZE] = play2Pic[0];
                            arrayForDisplayBoard[i][j*CHARSIZE+1] = play2Pic[1];
                            arrayForDisplayBoard[i][j*CHARSIZE+2] = play2Pic[2];
                        }
                        break;
                    default:
                        break;
                }
            }          
        } 
}


//显示棋盘格局 
void displayBoard(void)
{
    int i;
    //第一步：清屏
    #if CLEAR
    system("clear");
    #endif
    //第二步：将arrayForDisplayBoard输出到屏幕上
    for(i=0;i<SIZE;i++)
    {
        printf("%3d %s\n",SIZE-i,arrayForDisplayBoard[i]);
    }
    //第三步：输出最下面的一行字母A B .... 
    printf("    ");
    for(i=0;i<SIZE;i++)
    {
        printf("%2c",'A'+i);
    }
    printf("\n");
}