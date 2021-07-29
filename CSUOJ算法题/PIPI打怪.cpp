#include<iostream>
#include<algorithm>
using namespace std;
long long blood[100005];
int main(){
	int n;
	while(cin>>n){
		for(int i = 0; i < n; i++){
			cin >> blood[i];
		}
		sort(blood,blood+n);
		long long bullet = 0, power = 0, flag = 0;
		for(int i = 0; i < n; i++){
			if(blood[i] <= power) continue;
			if(flag==1){
				power += 2;
				flag = 1;	
			} 
			if(blood[i] <= power){  //有怪物被增加的两点伤害kill了，那就有新的两点伤害 
				flag = 1;
				continue;
			}
			flag = 1;
			long long resblood = blood[i] - power;
			long long addbullet = resblood%2==0 ? resblood/2 : resblood/2 + 1;
			power += addbullet * 2;
			bullet += addbullet;
		}
		cout<<bullet<<endl;
	}
	return 0;
} 
