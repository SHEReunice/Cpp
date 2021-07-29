#include<iostream>
using namespace std;
int main(){
	long long n, left = 0, right = 0, a = 1, now = 1, count = 0;
	cin >> n;
	while(n/a){
		left = n / a / 10;
		right = n % a;
		now = n / a % 10;
		if(now == 0){
			count += left * a;
		}
		else if(now == 1){
			count += left * a + right +  1;   
		}
		else{
				count += (left + 1) * a;
		}
		a *= 10;		
	}
	cout << count;
	return 0;
}
