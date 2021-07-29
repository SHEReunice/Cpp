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
		while(ans!=0&&bns!=0)//恢复最长公共序列，相当于从一串字符串中找到A、B两串中共有的字符，这里从A串中还原最长公共字符串
		{
			if(lcs[ans][bns]!=lcs[ans-1][bns])//lcs[i][j]来自于lcs[i][j-1]或者lcs[i-1][j-1],不管来自哪个，Ax肯定包含在最长公共字符串中
			 {
			 	 dp[++num]=a[ans];//记录最长公共串
			 	 ans--;//继续判断A串中前一个字符
			 	 bns--;//不管By来自与哪个表达式，By已经被判断过了，现在应该继续B的前一个字符
			 }
			 else if(lcs[ans][bns]==lcs[ans][bns-1])//如果来自lcs[i][j-1]，那么说明By不包含在最长公共字符串中，继续遍历B的前一个字符
			       bns--;
			else ans--;//说明Ax不包含在最长公共字符串中，继续遍历A的前一个字符
			  
			  
		}
		for(int i=lcs[l1][l2];i>0;i--)
		 cout<<dp[i];//输出最长子序列
		 cout << endl;
		 cout << lcs[l1][l2];
}

