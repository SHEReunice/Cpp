#include<bits/stdc++.h>
#include<cstring>
using namespace std;
bool cmp(double a, double b);
int main(){
	int N,D;
	cin >> N >> D;
	double obtain = 0.0;
	double amount[N]={0},sum[N]={0},price[N]={0},count[N]={0};
	for(int i = 0; i < N; i++){
		cin >> amount[i];
	}
	for(int i = 0; i < N; i++){
		cin >> sum[i];
		price[i] = sum[i] / amount[i];
	}
	sort(price, price+N,cmp);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(sum[j]/amount[j] == price[i])
			count[i] = amount[j];  //��Ϊ���յ��������Ժ��Ǹ�˳��ͺ� ԭ���±��������ܼ�˳��һ���� 
		}
	}
	cout<<fixed<<setprecision(2); //����С���������С�������λ
	for(int i = 0; i < N; i++){
		if(count[i] <= D){
			obtain += price[i] * count[i];
		}else{
			obtain += price[i] * D;
			break;
		}
		D -= count[i];
	}
	cout<<obtain;
	
}
bool cmp(double a, double b){
	return a>b;
}
