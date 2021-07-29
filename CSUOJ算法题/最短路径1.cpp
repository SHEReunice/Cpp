#include<stdio.h>
#include<string.h>
 
#define N 3000
#define INF 0x3f3f3f3f
int e[N][N];
int dist[N];  ///��ʼ�㵽������i�ľ���
int visited[N];
int pre[N];  ///pre[i]=j,��j-->i
int n, m; ///������������
int s, t; ///��㣬�յ�
 
///��ʼ���ڽӾ���
void init_e() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = INF;
	}
}
 
void Dijkstra() {
	//memset(visited,0,sizeof(visited);
	///��ʼ��dist��pre,��ʼ�㵽������i�ľ���
	for (int i = 1; i <= n; i++) {
		dist[i] = e[s][i];
		pre[i] = s; ///s-->i
	}
	visited[s] = 1;
	for (int i = 2; i <= n; i++) {
		int min = INF, u;
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && dist[i] < min) {
				min = dist[i];
				u = i;
			}
		}
		visited[u] = 1;
		///����u���ڽӶ��㣬����dist
		for (int i = 1; i <= n; i++) {
			if (!visited[i] && dist[u] + e[u][i] < dist[i]) {
				dist[i] = dist[u] + e[u][i];
				pre[i] = u;
			}
		}
	}
	printf("%d\n", dist[t]);
 
}
 
///������·�����ݹ�
void search(int x){
	if(x==s){
		printf("%d",x );
		return;
	}
	search(pre[x]);
	printf("-->%d",x);
}
 
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	init_e();
	int a, b, w;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &a, &b, &w);
		///�ڽӾ���ֻ�ܴ�����������һ��·�����������Ŀ�е�ע������
		///ֻ�������������С������·
		if (w < e[a][b]) {  
			e[a][b] = w;
			e[b][a] = w; ///����ͼ
		}
	}
	Dijkstra();
	search(t);  ///����Ϊ�յ�
	return 0;
}
