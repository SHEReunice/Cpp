#include<iostream>
using namespace std;

int main(){
	int n,temp;
	while(cin >> n){
		int bucket[1001]= {0};
		int time = 0;
		while(n--){
		cin >> temp;
		time =  bucket[temp]==1 ? time : time+1;
		bucket[temp] = 1;	
		
		}
		cout<<time<<endl;
		for(int i = 0; i < 1001; i++){
			if(bucket[i]){
				cout << i << " ";
			}
		}
		cout<<endl;	
	}
	return 0;
} 
