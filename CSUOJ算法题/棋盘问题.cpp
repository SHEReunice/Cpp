#include<bits/stdc++.h>
using namespace std;

void dfs(int row);

char  c[11][11];
int col[11];
int n,k,num;
long long sum;

int main(){
	while(cin >> n >> k){
		num = 0;
		sum = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> c[i][j];
			}
		}
		dfs(0);
		cout << sum << endl;
	}
}

void dfs(int row){
	if(num == k){
		sum++;
		return;
	}
	if(row >= n){
		return;
	}
	for(int i = 0; i < n; i++){
		if(col[i] == 0 && c[row][i]=='#'){
			col[i] = 1; //在这一行第i列放一个棋子，后面行的这一列就不能放了 
			num++; //有一个棋子放下去了
			dfs(row+1);
			num--;  //倒着减回来
			col[i] = 0; 
		}
	}
	dfs(row+1);
}
