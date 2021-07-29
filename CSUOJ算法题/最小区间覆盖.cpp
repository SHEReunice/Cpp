#include <iostream>
using namespace std;

int main(){
	int n,l,r;
	while((cin >> n >> l >> r)){
	

	int pathL[n];
	int pathR[n];
	for(int i =0; i < n; i++){
		cin >> pathL[i] >> pathR[i];
	}
	
	int num = 0;
	for(;;){
		int s = -1;
		int max = 1;
		if(l == r){
			int flag = 0;
			for(int i = 0; i < n; i++){
				if(pathL[i] <= l && pathR[i] >= r){
					flag = 1;
					break;
				}
			}
			if(flag == 1){
				num++;
			}else{
				num = -1;
			}
			break;
		}
		for(int i = 0; i < n; i++){
			if(pathL[i] <= l && pathR[i] >= r){
				if(max <= pathR[i] - l){
					max = pathR[i] - l;
					s = i;
				}
			}
		}
		if(s == -1){
			num = -1;
			break;
		}else{
			l += max;
			num++;
			if(l >= r){
				break;
			}
		}
	}
	cout << num<<endl;
}
} 
