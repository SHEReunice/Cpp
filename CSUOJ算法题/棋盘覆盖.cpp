#include<stdio.h>

#include<stdlib.h>

int tile=1;

//ȫ�ֱ��� ���Ʊ��  

int board[100][100]={0};

//��ʼ��ֵȫΪ0 ����ʼ������

   // Lr : �������Ͻǵ��кţ�Lc�������Ͻǵ��к�

 // Rr : ���ⷽ�����Ͻǵ��кţ�Rc���ⷽ�����Ͻǵ��к�

  void chessBoard ( int Lr, int Lc, int Rr, int Rc, int size )

{
    if ( size==1 )

{
    return;

}

    int t=tile++;//L�͹��Ʊ��

int s=size/2;

//��ʼֵΪtitle���ָ�����Ϊ4�ȷ�

  //�������Ͻ�������  

    if ( Rr<Lr+s && Rc<Lc+s )//���ⷽ�������������  

    {
        chessBoard ( Lr, Lc, Rr, Rc, s );

    }

    else//���ⷽ�������������  

{
//�ñ��Ϊt�Ĺ��Ƹ������½�  

    board[Lr+s-1][Lc+s-1]=t;

    //�������෽��  

        chessBoard ( Lr, Lc, Lr+s-1, Lc+s-1, s );

    }

    //�������Ͻ�������

if ( Rr<Lr+s && Rc>=Lc+s )

//���ⷽ�������������  

    {
        chessBoard ( Lr, Lc+s, Rr, Rc, s );

    }

    else//���ⷽ�������������  

    {
        board[Lr+s-1][Lc+s]=t;

        chessBoard ( Lr, Lc+s, Lr+s-1, Lc+s, s );

    }

    //�������½�������  

if ( Rr>=Lr+s && Rc<Lc+s )

//���ⷽ�������������  

    {
        chessBoard ( Lr+s, Lc, Rr, Rc, s );

    }

    else//���ⷽ�������������  

    {
        board[Lr+s][Lc+s-1]=t;

        chessBoard ( Lr+s, Lc, Lr+s, Lc+s-1, s );

    }

    //�������½�������  

if ( Rr>=Lr+s && Rc>=Lc+s )

//���ⷽ�������������  

    {
        chessBoard ( Lr+s, Lc+s, Rr, Rc, s );

    }

Else

//���ⷽ�������������  

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

    printf("���������̵Ĺ��:");

    scanf("%d",&size);// �������̵Ĵ�С 

    printf("���������ⷽ����к����к�:");

    scanf("%d %d",&x,&y); //�������ⷽ������� 

    chessBoard ( 0,0,x,y,size );

    for ( i=0; i<size; i++ )

    {
        for ( j=0; j<size; j++ )

        {
            printf("%d\t",board[i][j]);  //��ӡ���Ǻ������

        }

        printf("\n");

    }

}

