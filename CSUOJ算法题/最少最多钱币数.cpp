#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,S,T;
	cin>>T;
	while(T--){
		cin >> n >> S;
		int money[n];
		for(int i = 0; i < n; i++){
			cin >> money[i];
		}
		sort(money, money+n);
		int least[S+1],most[S+1];
		for(int i = 1; i <= S; ++i){
		least[i] = 10001;
		most[i] = -1; 
		}
		least[0] = 0;
		memset(most, 0 ,sizeof(most)); 
		for(int i  = 1; i <= S; i++){
			for(int j = 0; j < n; j++){
				if(i < money[j]){
					break;
				}
				if(least[i-money[j]] != 10001){ //要判断能不能凑出正好的钱数 
					least[i] = min(least[i - money[j]] + 1,  least[i]);
					most[i] = max(most[i - money[j]] + 1, most[i]);
				}
			}
		}
		if(least[S] != 10001){
			cout << least[S] << " " << most[S];
		}else{
			cout << 0 << " " << 0;
		}
			
		
		cout << endl;
	}
} 
