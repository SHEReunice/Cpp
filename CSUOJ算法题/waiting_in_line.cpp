#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;
struct Cus{
	int proTi;
	int sTi;
	int enTi;
};
int n,m,k,q;
Cus cus[1005];
queue<Cus> wins[25];

int main(){ 
	cin >> n >> m >> k >> q;
	for(int  i = 1; i <= k; i++){
		cin >> cus[i].proTi;
	}
	int oTi = 60*8;
	int cTi = 60 * 17;
	for(int i = 1; i <= k; i++){
		if ( i <= n*m){
			int win1 = (i-1)%n+1;
			if(i <= n){
				cus[i].sTi = oTi;
				cus[i].enTi = oTi + cus[i].proTi;
			}else{
				Cus lastOne = wins[win1].back();
				cus[i].sTi = lastOne.enTi;
				cus[i].enTi = cus[i].sTi+cus[i].proTi; 
			}
			wins[win1].push(cus[i]);
		}else{
			int win2 = 1;
			for(int j = 2; j <= n; j++){
				if(wins[j].front().enTi < wins[win2].front().enTi){
					win2 = j;
				}
			}
			wins[win2].pop();
		Cus lastOne = wins[win2].back();
		cus[i].sTi = lastOne.enTi;
		cus[i].enTi =  cus[i].sTi + cus[i].proTi;
		wins[win2].push(cus[i]);
		}
		
	} 
	int index;
	while(q>0){
		q--;
		cin >> index;
		if(cus[index].sTi >= cTi){
			cout << "Sorry" << endl; 
		}else{
			cout << setw(2) << setfill('0') << cus[index].enTi / 60;
			cout << ":";
			cout << setw(2) << setfill('0') << cus[index].enTi%60;
			cout << endl;
		}
	}
}

