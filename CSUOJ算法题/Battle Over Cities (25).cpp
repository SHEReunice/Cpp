#include<bits/stdc++.h>
using namespace std;
int city;
int  v[1005][1005];
bool visit[1005];
void dfs(int n);
int main(){
	int M,K,a,b;
	cin >> city >> M >> K;
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		v[a][b] = v[b][a] = 1;
	}
	for(int i = 0; i < K; i++){
		int num = 0;
		memset(visit, false, sizeof(visit));
		cin >> a;
		visit[a] = true;
		for(int j = 1; j <= city; j++){
			if(visit[j] == false){
				dfs(j);
				num++;
			}
		}
		cout << num - 1 << endl;
	}
}

void dfs(int n){
	visit[n] = true;
	for(int i = 1; i <= city; i++){
		if(!visit[i] && v[n][i] == 1){
			dfs(i);
		}
	}
}

