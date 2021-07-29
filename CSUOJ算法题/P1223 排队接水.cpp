#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
	int n;
	double sum = 0.0;
	cin >> n;
	int wait[n],copy[n]={0}; 
	for(int i = 0; i < n; i++){
		cin >> wait[i];
	}
	memcpy(copy,wait,sizeof(wait));
	int record[n]={0};
	sort(copy,copy+n);
	for(int i = 0; i < n; i++){
		for(int j = 0;j < n; j++){
			if(copy[i] == wait[j]){
				if(i != 0){
				copy[i] += copy[i-1];
				sum += copy[i-1];
				}
				
				wait[j] = 0;
				record[i] = j+1;
				break;
			}
		}
	}
	cout<<fixed<<setprecision(2);
	for(int i = 0;i < n; i++){
		cout << record[i] << " " ;
	}
	cout<<endl;
	sum /= n;
	cout<<sum;
	return 0;	
}

//第一个人不排队，后面每个人排队的时间都要累加，比如说第三个的排队时间=第一个的时间+第二个人的打水时间，
//所以每个人的等待时间都需要前面的排队时间加上前一个人的打水时间 
