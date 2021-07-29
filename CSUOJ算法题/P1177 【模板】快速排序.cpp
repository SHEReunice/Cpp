#include<iostream>
#include <algorithm>
using namespace std;
int n;
long long digits[1000001];
void quicksort(int left, int right); 
int main(){
	cin >> n;
	for(int i = 0; i< n; i++){
		cin >> digits[i];
	}
	quicksort(0,n-1);
	for(int i = 0; i < n; i++){
		cout << digits[i] << " ";
	}
	return 0;
} 
void quicksort(int left, int right){
	int i = left, j = right;
	int mid = (left+right)/2;
	while(i <= j){
		while(digits[i] <= digits[mid]) i++;
		while(digits[j] >= digits[mid]) j--;
		if(i <= j){
			swap(digits[i], digits[j]);
			i++;
			j--;
		}
	}
	if(left < j) quicksort( left, j);
	if(i < right) quicksort(i, right);	
}
