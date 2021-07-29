#include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define MAX 2600
#define INF 9999999999
long long dis[MAX][MAX];
long long path[MAX];
int previous[MAX];
int visited[MAX];
void initialize(int n);
void shortest(int n,int s, int t);

int main(){
	int n,m,s,t;
	cin >> n >> m >> s >> t;
	initialize(n);
	int x,y;
	long long w;
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> w;
		if(w < dis[x][y]){
			dis[x][y] = w;
			dis[y][x] = w;
		}
	}
	shortest(n,s,t);
	return 0;
}

void initialize(int n){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}
}

void shortest(int n,int s, int t){
	for(int i = 1; i <= n; i++){
		path[i] = dis[s][i];
		previous[i] = s;
	}
	visited[s] = 1;
	for(int i = 2; i <= n; i++){
		long long min = INF;
		int u;
		for(int j = 1; j <= n; j++){
			if(!visited[j] && path[j] < min){
				min = path[j];
				u = j;
			}
		}
		visited[u] = 1;
		for(int k = 1; k <= n;k++){
			if(!visited[k] && path[u] + dis[u][k] < path[k]){
				path[k] = path[u] + dis[u][k];
				previous[k] = u;
			}
		}
	}
	cout << path[t] << endl;
} 
