#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int tile = 1;
/*
strategy: if k > 0, divide the 2k*2k chess-board into 
4 smaller chess-board of size (2k-1)*(2k-1)
*/ 
int cb[1100][1100];
void chB(int br,int bc,int er,int ec,int size);
int main(){
	int k;
	int j;
	int ex,ey;
//	cout << "输入棋盘大小，k,棋盘大小将为2k(k次方)*2k" << endl;
	cin >> k;
	int size;
	size = pow(2,k);
//	cout << "输入特殊格x，y坐标" << endl; 
	cin >> ex >> ey;
	chB(0,0,ex-1,ey-1,size);
	for(int i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			cout << cb[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}
void chB(int ar,int ac, int fr,int fc,int size){
	if(size == 1) return;
	int til = tile++;
	int s = size / 2;
	 
	//cover the left-upper
	if(fr < ar+s && fc < ac+s){
		chB(ar,ac,fr,fc,s);
	} else{
		cb[ar+s-1][ac+s-1] = til;
		chB(ar,ac,ar+s-1,ac+s-1,s);
	}
	
	//cover the right-upper
	if(fr < ar+s && fc >= ac+s){
		chB(ar,ac+s,fr,fc,s); //特殊格位置不变 
	}else{
		cb[ar+s-1][ac+s] = til; //找一个特殊格，特殊格靠近中心点处 
		chB(ar,ac+s,ar+s-1,ac+s,s); 
	}
	
	//cover the left-lower
	if(fr >= ar+s && fc < ac+s){
		chB(ar+s,ac,fr,fc,s);
	}else{
		cb[ar+s][ac+s-1]=til;
		chB(ar+s,ac,ar+s,ac+s-1,s);
	}
	//cover the right-lower
	if(fr >= ar+s && fc >= ac+s){
		chB(ar+s,ac+s,fr,fc,s);
	}else{
		cb[ar+s][ac+s]=til;
		chB(ar+s,ac+s,ar+s,ac+s,s);
	}	
}
