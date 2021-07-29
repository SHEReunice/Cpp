#include<bits/stdc++.h>
using namespace std;

int w,h,beginx,beginy,ans;
char floors[21][21];

void dfs(int x, int y);

int main(){
	while(cin >> w >> h){
		if(w == 0 && h == 0){
			break;
		}
		ans = 1;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> floors[i][j];
				if(floors[i][j] == '@'){
					beginx = i;
					beginy = j;
				}
			}
		}
		dfs(beginx,beginy);
		cout << ans << endl;
	}
	return 0;
}

void dfs(int x, int y){
	floors[x][y] = '#';
	int X[4] = {0,0,-1,1};
	int Y[4] = {-1,1, 0, 0};
	for(int i = 0; i < 4; i++){
		int newx = x + X[i];
		int newy = y + Y[i];
		if(newx >= 0 && newx < h && newy >= 0 && newy < w && floors[newx][newy]== '.'){
			ans++;
			dfs(newx,newy);
		}
	}
}
