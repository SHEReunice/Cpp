#include<iostream>
#include <math.h>
using namespace std;
int main(){
	int a,i=0;
	long long sum=0;
	while(cin>>a){ //���� control+z���� 
		sum += a;
		i++;
	}
	int x = pow(2,i-1);
	sum *= x;
	cout<<sum;
} 
