#include<bits/stdc++.h>
using namespace std;

int main(){
	int f[600],n,len;
	memset(f,0,sizeof(f));
	len = 1;
	cin >> n;
	f[1] = 2;
	while(n>=1){
		for(int i = len; i > 0; i--){
			f[i] = f[i] * 2;
			if(f[i] >= 10){
				f[i+1]++;
				f[i] -= 10;
			}
		}
		if(f[len+1]>0) len++;
		n--;
	}	
	f[1] -= 2;
	for(int i = len; i > 0; i--){
		cout << f[i];
	}
	return 0;
}
