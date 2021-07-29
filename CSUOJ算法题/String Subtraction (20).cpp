#include<bits/stdc++.h>
#include<cstring>
#define  MAX 10005
using namespace std;

int main(){
	int characters[128] = {0};
	string str1,str2;
	getline(cin, str1);
	getline(cin, str2);
	for(int i = 0; i < str2.length(); i++){
		characters[str2[i]]++;
	}
	for(int i = 0; i < str1.length(); i++){
		if(characters[str1[i]] == 0){
			cout<<str1[i];
		}
	}
	return 0;
}
