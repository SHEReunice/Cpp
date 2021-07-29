#include<bits/stdc++.h>
#include<cstring>
#define MAX 105
using namespace std;
int num[MAX][MAX];
int dp[MAX][MAX];
void maxPath(int n);

int main(){
	int n;
	while(cin >> n){
		memset(num, 0, sizeof(num));
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				cin >> num[i][j];
			}
		}
		maxPath(n);
		cout << dp[0][0] << endl;
	}
}

void maxPath(int n){
	for(int i = 0; i < n; i++){
		dp[n-1][i] = num[n-1][i];
	}
	for(int i = n-1; i >= 0; --i){
		for(int j = 0; j <= i; j++){
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + num[i][j];
		}
	}
}
