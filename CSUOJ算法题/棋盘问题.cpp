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
			col[i] = 1; //����һ�е�i�з�һ�����ӣ������е���һ�оͲ��ܷ��� 
			num++; //��һ�����ӷ���ȥ��
			dfs(row+1);
			num--;  //���ż�����
			col[i] = 0; 
		}
	}
	dfs(row+1);
}
