#include<stdio.h>

#include<stdlib.h>

int tile=1;

//全局变量 骨牌编号  

int board[100][100]={0};

//初始赋值全为0 ，初始化棋盘

   // Lr : 棋盘左上角的行号，Lc棋盘左上角的列号

 // Rr : 特殊方格左上角的行号，Rc特殊方格左上角的列号

  void chessBoard ( int Lr, int Lc, int Rr, int Rc, int size )

{
    if ( size==1 )

{
    return;

}

    int t=tile++;//L型骨牌编号

int s=size/2;

//初始值为title；分割棋盘为4等份

  //覆盖左上角子棋盘  

    if ( Rr<Lr+s && Rc<Lc+s )//特殊方格在这个棋盘中  

    {
        chessBoard ( Lr, Lc, Rr, Rc, s );

    }

    else//特殊方格不在这个棋盘中  

{
//用编号为t的骨牌覆盖右下角  

    board[Lr+s-1][Lc+s-1]=t;

    //覆盖其余方格  

        chessBoard ( Lr, Lc, Lr+s-1, Lc+s-1, s );

    }

    //覆盖右上角子棋盘

if ( Rr<Lr+s && Rc>=Lc+s )

//特殊方格在这个棋盘中  

    {
        chessBoard ( Lr, Lc+s, Rr, Rc, s );

    }

    else//特殊方格不在这个棋盘中  

    {
        board[Lr+s-1][Lc+s]=t;

        chessBoard ( Lr, Lc+s, Lr+s-1, Lc+s, s );

    }

    //覆盖左下角子棋盘  

if ( Rr>=Lr+s && Rc<Lc+s )

//特殊方格在这个棋盘中  

    {
        chessBoard ( Lr+s, Lc, Rr, Rc, s );

    }

    else//特殊方格不在这个棋盘中  

    {
        board[Lr+s][Lc+s-1]=t;

        chessBoard ( Lr+s, Lc, Lr+s, Lc+s-1, s );

    }

    //覆盖右下角子棋盘  

if ( Rr>=Lr+s && Rc>=Lc+s )

//特殊方格在这个棋盘中  

    {
        chessBoard ( Lr+s, Lc+s, Rr, Rc, s );

    }

Else

//特殊方格不在这个棋盘中  

    {
        board[Lr+s][Lc+s]=t;

        chessBoard ( Lr+s, Lc+s, Lr+s, Lc+s, s );

    }

}

int main()

{
    int size;

    int i,j;

    int x,y;

    printf("请输入棋盘的规格:");

    scanf("%d",&size);// 输入棋盘的大小 

    printf("请输入特殊方格的行号与列号:");

    scanf("%d %d",&x,&y); //输入特殊方格的坐标 

    chessBoard ( 0,0,x,y,size );

    for ( i=0; i<size; i++ )

    {
        for ( j=0; j<size; j++ )

        {
            printf("%d\t",board[i][j]);  //打印覆盖后的棋盘

        }

        printf("\n");

    }

}

