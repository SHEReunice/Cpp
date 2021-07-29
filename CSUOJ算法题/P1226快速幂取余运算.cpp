#include<iostream>
using namespace std;
int main(){
	long long b,p,k,i,a,c;
	cin >> b >> p >> k;
	a=b;
	c= p;
	long long s=1;
	while(p>0){
		if(p%2 == 1){
			s = s * b % k;
		}
		b = b * b % k;
		p = p / 2;
	}
	cout<<a<<"^"<<c<<" "<<"mod"<<" "<<k<<"="<<s%k;
} 


