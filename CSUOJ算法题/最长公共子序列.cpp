#include<iostream>
#include<algorithm>
#include<string.h>
char a[1001],b[1001];
int lcs[1001][1001];
char dp[1001];
using namespace std;
main()
{
	gets(a+1);
	gets(b+1);
	int l1=strlen(a+1);
	int l2=strlen(b+1);
	for(int i=0;i<=l1;i++)
	   for(int j=0;j<=l2;j++)
	   { if(i==0||j==0) lcs[i][j]=0;
	     else if(a[i]==b[j]) lcs[i][j]=lcs[i-1][j-1]+1;
	   	 else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);	   
		}
		int ans=l1,bns=l2,num=0;
		while(ans!=0&&bns!=0)//�ָ���������У��൱�ڴ�һ���ַ������ҵ�A��B�����й��е��ַ��������A���л�ԭ������ַ���
		{
			if(lcs[ans][bns]!=lcs[ans-1][bns])//lcs[i][j]������lcs[i][j-1]����lcs[i-1][j-1],���������ĸ���Ax�϶�������������ַ�����
			 {
			 	 dp[++num]=a[ans];//��¼�������
			 	 ans--;//�����ж�A����ǰһ���ַ�
			 	 bns--;//����By�������ĸ����ʽ��By�Ѿ����жϹ��ˣ�����Ӧ�ü���B��ǰһ���ַ�
			 }
			 else if(lcs[ans][bns]==lcs[ans][bns-1])//�������lcs[i][j-1]����ô˵��By��������������ַ����У���������B��ǰһ���ַ�
			       bns--;
			else ans--;//˵��Ax��������������ַ����У���������A��ǰһ���ַ�
			  
			  
		}
		for(int i=lcs[l1][l2];i>0;i--)
		 cout<<dp[i];//����������
		 cout << endl;
		 cout << lcs[l1][l2];
}

